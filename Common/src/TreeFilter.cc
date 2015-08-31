#include "NtuTool/Common/interface/TreeFilter.h"
#include "NtuTool/Common/interface/DataHandler.h"
#include "NtuTool/Common/interface/TreeTypeManager.h"

#include "TTree.h"
#include "TFile.h"
#include "TDirectory.h"


TreeFilter::TreeFilter() {
  fhManager = new TreeTypeManager;
}


TreeFilter::~TreeFilter() {
}


void TreeFilter::dropBranch( const std::string& name ) {
  skimDrop.insert( name );
  return;
}


void TreeFilter::initWrite( TFile* file ) {

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
    filterTree = new TTree( name, name );
  }
  else {
    filterTree = 0;
  }
  currentDir->cd();

  branch_iterator iter = treeBegin();
  branch_iterator iend = treeEnd();
  while ( iter != iend ) {
    branch_desc* bDesc = *iter++;
//    const std::string& bName = bDesc->branchName;
//    std::map<std::string,bool>::const_iterator iter =
//                                skimMap.find( bDesc->branchName );
//    if ( ( iter != skimMap.end ) && ( iter->second ) ) continue;
    if ( skimDrop.find( *bDesc->branchName ) != skimDrop.end() ) continue;
    DataHandler* handler = fhManager->setHandler( bDesc,
                                                  bDesc->branchData );
//    bDesc->dataHandler = handler;
//    TBranch* b = 0;
    void** dataPtr = 0;
    if ( bDesc->splitLevel < 0 ) handler->setAuxPtr( bDesc->dataPtr,
                                                     fhManager );
    if ( bDesc->ppRef ) dataPtr =  reinterpret_cast<void**>( bDesc->dataPtr );
    else                dataPtr = &bDesc->dataPtr;
    if ( file != 0 ) {
      if ( bDesc->splitLevel < 0 )
           filterTree->Branch( bDesc->branchName->c_str(),
                                    bDesc->dataPtr,
                                    bDesc->branchData->c_str() );
      else handler->branch( filterTree, bDesc->branchName, dataPtr,
                                bDesc->bufferSize, bDesc->splitLevel );
//      if ( bDesc->splitLevel < 0 )
//           b = currentTree->Branch( bDesc->branchName->c_str(),
//                                    bDesc->dataPtr,
//                                    bDesc->branchData->c_str() );
//      else b = handler->branch( currentTree, bDesc->branchName, dataPtr,
//                                bDesc->bufferSize, bDesc->splitLevel );
//      if ( bDesc->branchPtr != 0 ) *bDesc->branchPtr = b;
    }
  }

  return;

}


void TreeFilter::fill() {
  if ( filterTree == 0 ) return;
  TDirectory* currentDir = gDirectory;
  treeDir->cd();
  filterTree->Fill();
  currentDir->cd();
  return;
}


void TreeFilter::close() {
  if ( filterTree == 0 ) return;
  TDirectory* currentDir = gDirectory;
  treeDir->cd();
  filterTree->Write();
  currentDir->cd();
  return;
}

