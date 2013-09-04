#include "NtuTool/Common/interface/TreeWriter.h"
#include "NtuTool/Common/interface/DataHandler.h"
#include "NtuTool/Common/interface/TreeTypeManager.h"

#include "TTree.h"
#include "TFile.h"
#include "TDirectory.h"


TreeWriter::TreeWriter() {
  handlerManager = new TreeTypeManager;
}


TreeWriter::~TreeWriter() {
}


void TreeWriter::initWrite( TFile* file ) {

  TDirectory* currentDir = gDirectory;
  if ( file != 0 ) {
    file->cd();
    std::string fullName = treeName;
    int dirNameLength;
    while ( ( dirNameLength = fullName.find( "/" ) ) >= 0 ) {
      std::string nextName = fullName.substr( 0, dirNameLength ).c_str();
      const char* n = nextName.c_str();
      if ( gDirectory->Get( n ) == 0 ) gDirectory->mkdir( n );
      gDirectory->cd( n );
      fullName = fullName.substr( ++dirNameLength, fullName.length() );
    }
    const char* name = fullName.c_str();
    treeDir = gDirectory;
    currentTree = new TTree( name, name );
  }
  else {
    currentTree = 0;
  }
  currentDir->cd();

  branch_iterator iter = treeBegin();
  branch_iterator iend = treeEnd();
  while ( iter != iend ) {
    branch_desc* bDesc = *iter++;
    DataHandler* handler = handlerManager->setHandler( bDesc,
                                                       bDesc->branchData );
    bDesc->dataHandler = handler;
    TBranch* b = 0;
    void** dataPtr = 0;
    if ( bDesc->splitLevel < 0 ) handler->setAuxPtr( bDesc->dataPtr,
                                                     handlerManager );
    if ( bDesc->ppRef ) dataPtr =  reinterpret_cast<void**>( bDesc->dataPtr );
    else                dataPtr = &bDesc->dataPtr;
    if ( file != 0 ) {
      if ( bDesc->splitLevel < 0 )
           b = currentTree->Branch( bDesc->branchName->c_str(),
                                    bDesc->dataPtr,
                                    bDesc->branchData->c_str() );
      else b = handler->branch( currentTree, bDesc->branchName, dataPtr,
                                bDesc->bufferSize, bDesc->splitLevel );
      if ( bDesc->branchPtr != 0 ) *bDesc->branchPtr = b;
    }
  }

  return;

}


void TreeWriter::fill() {
  if ( currentTree == 0 ) return;
  TDirectory* currentDir = gDirectory;
  treeDir->cd();
  currentTree->Fill();
  currentDir->cd();
  return;
}


void TreeWriter::close() {
  if ( currentTree == 0 ) return;
  TDirectory* currentDir = gDirectory;
  treeDir->cd();
  currentTree->Write();
  currentDir->cd();
  return;
}

