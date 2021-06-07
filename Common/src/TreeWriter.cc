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
  if ( file != nullptr ) {
    file->cd();
    std::string fullName = treeName;
    int dirNameLength;
    while ( ( dirNameLength = fullName.find( "/" ) ) >= 0 ) {
      std::string nextName = fullName.substr( 0, dirNameLength ).c_str();
      const char* n = nextName.c_str();
      if ( gDirectory->Get( n ) == nullptr ) gDirectory->mkdir( n );
      gDirectory->cd( n );
      fullName = fullName.substr( ++dirNameLength, fullName.length() );
    }
    const char* name = fullName.c_str();
    treeDir = gDirectory;
    currentTree() = new TTree( name, name );
  }
  else {
    currentTree() = nullptr;
  }
  currentDir->cd();

  branch_iterator iter = treeBegin();
  branch_iterator iend = treeEnd();
  while ( iter != iend ) {
    branch_desc* bDesc = *iter++;
    DataHandler* handler = handlerManager->setHandler( bDesc );
    bDesc->dataHandler = handler;
    TBranch* b = nullptr;
    void** dataPtr = nullptr;
    if ( bDesc->splitLevel < 0 ) handler->setAuxPtr( bDesc->dataPtr,
                                                     handlerManager );
    if ( bDesc->ppRef ) dataPtr =  pPtr( bDesc->dataPtr );
    else                dataPtr = &bDesc->dataPtr;
    if ( file == nullptr ) continue;
//    if ( file != nullptr ) {
      if ( bDesc->splitLevel < 0 ) {
        if ( bDesc->bufferSize < 0 )
           b = currentTree()->Branch( bDesc->branchName->c_str(),
                                      bDesc->dataPtr,
                                      bDesc->branchData->c_str() );
        else
           b = currentTree()->Branch( bDesc->branchName->c_str(),
                                      bDesc->dataPtr,
                                      bDesc->branchData->c_str(),
                                      bDesc->bufferSize );
      }
      else b = handler->branch( currentTree(), bDesc->branchName, dataPtr,
                                bDesc->bufferSize, bDesc->splitLevel );
      if ( bDesc->branchPtr != nullptr ) *bDesc->branchPtr = b;
//    }
  }

  return;

}


void TreeWriter::fill() {
  if ( currentTree() == nullptr ) return;
  TDirectory* currentDir = gDirectory;
  treeDir->cd();
  currentTree()->Fill();
  currentDir->cd();
  return;
}


void TreeWriter::close() {
  if ( currentTree() == nullptr ) return;
  TDirectory* currentDir = gDirectory;
  treeDir->cd();
  currentTree()->Write();
  currentDir->cd();
  return;
}

