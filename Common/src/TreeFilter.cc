#include "NtuTool/Common/interface/TreeFilter.h"
#include "NtuTool/Common/interface/DataHandler.h"
#include "NtuTool/Common/interface/TreeTypeManager.h"

#include "TTree.h"
#include "TFile.h"
#include "TDirectory.h"

#include <string>
#include <vector>

TreeFilter::TreeFilter() {
  fhManager = new TreeTypeManager;
}


TreeFilter::~TreeFilter() {
}


void TreeFilter::dropBranch( const std::string& name ) {
  if ( name.find( "*" ) == std::string::npos ) {
    skimDrop.insert( name );
  }
  else {
    std::vector<std::string> sl;
    sl.reserve( 100 );
    std::size_t p = 0;
    std::size_t n = 0;
    while ( ( n = name.find( "*", p ) ) != std::string::npos ) {
      sl.push_back( name.substr( p, n - p ) );
      p = n + 1;
    }
    sl.push_back( name.substr( p ) );
    bool bb = sl.front().length();
    bool eb = sl.back ().length();
    branch_iterator iter = treeBegin();
    branch_iterator iend = treeEnd();
    while ( iter != iend ) {
      branch_desc* bDesc = *iter++;
      const std::string& bn = *bDesc->branchName;
      n = p = 0;
      bool match = true;
      int i;
      int l = sl.size();
      for ( i = 0; i < l; ++i ) {
        const std::string& dn = sl[i];
        if ( dn.length() == 0 ) continue;
        if ( ( n = bn.find( dn, p ) ) == std::string::npos ) {
          match = false;
          break;
        }
        if ( bb && ( i ==   0       )
                && ( n != 0 ) ) {
          match = false;
          break;
        }
        if ( eb && ( i == ( l - 1 ) )
                && ( n != ( bn.length() - dn.length() ) ) ) {
          match = false;
          break;
        }
        p = n + dn.length();
      }
      if ( match ) skimDrop.insert( bn );
    }
  }
  return;
}


void TreeFilter::initWSkim( TFile* file ) {

  if ( file != 0 ) {
    TDirectory* currentDir = gDirectory;
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
    currentDir->cd();
  }
  else {
    filterTree = 0;
    return;
  }

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

  return;

}


void TreeFilter::fillSkim() {
  if ( filterTree == 0 ) return;
  TDirectory* currentDir = gDirectory;
  treeDir->cd();
  filterTree->Fill();
  currentDir->cd();
  return;
}


void TreeFilter::closeSkim() {
  if ( filterTree == 0 ) return;
  TDirectory* currentDir = gDirectory;
  treeDir->cd();
  filterTree->Write();
  currentDir->cd();
  return;
}

