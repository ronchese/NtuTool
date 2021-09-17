#include <iostream>
#include <fstream>
#include <string>

#include "NtuTool/Common/interface/BranchInterface.h"
#include "NtuTool/Common/interface/DataHandler.h"

#include "TFile.h"
#include "TTree.h"
#include "TApplication.h"
#include "TRint.h"
#include "TROOT.h"
#include "TList.h"


BranchInterface::BranchInterface() {
  biData = new BranchInterfaceData;
  biShadow = new BranchInterface( this );
}


BranchInterface::BranchInterface( BranchInterface* bi ) {
  biData = bi->biData;
  biShadow = this;
}


BranchInterface::~BranchInterface() {
  if ( biShadow != this ) {
    delete biData;
    delete biShadow;
  }
}


BranchInterface* BranchInterface::setBranch( const char* branchName,
                                             void* dataPtr,
                                             const char* branchData,
                                             TBranch** branchPtr ) {
  if ( branchPtr == nullptr ) branchPtr = new TBranch*;
  newBranch( branchName, dataPtr, branchData )->branchPtr  = branchPtr;
  return biShadow;
}


BranchInterface* BranchInterface::setBranch( const char* branchName,
                                             void* dataPtr,
                                             int bufferSize,
                                             const char* branchData,
                                             TBranch** branchPtr ) {
  if ( branchPtr == nullptr ) branchPtr = new TBranch*;
  branch_desc* bDesc =
  newBranch( branchName, dataPtr, branchData );
  bDesc->bufferSize = bufferSize;
  bDesc->branchPtr  = branchPtr;
  return biShadow;
}


BranchInterface* BranchInterface::setInfo( int type, const char* s ) {
  branch_desc* bDesc = branchList().back();
  if ( s != nullptr ) bDesc->addInfo[type] = new std::string( s );
  return biShadow;
}


void BranchInterface::fillBranchMap() {
  auto& bMap = biData->bMap;
  bMap.clear();
  for ( const auto& bDesc : biData->bList ) bMap[bDesc->branchPtr] = bDesc;
  return;
}


void BranchInterface::process( int ientry ) {
// default preliminary process - dummy
  return;
}


void BranchInterface::process( TBranch** b, int ientry ) {
// default preliminary process - dummy
  return;
}


void BranchInterface::process( const branch_desc* b, int ientry ) {
  b->dataHandler->process( b->ppRef ? *( this->pPtr( b->dataPtr ) ) :
                                                     b->dataPtr     );
}


BranchInterface::branch_iterator BranchInterface::treeBegin() {
  return branchList().begin();
}


BranchInterface::branch_iterator BranchInterface::treeEnd() {
  return branchList().end();
}


BranchInterface::branch_rev_iter BranchInterface::treeRBegin() {
  return branchList().rbegin();
}


BranchInterface::branch_rev_iter BranchInterface::treeREnd() {
  return branchList().rend();
}


BranchInterface::branch_desc* BranchInterface::newBranch(
                                               const char* branchName,
                                               void* dataPtr,
                                               const char* branchData ) {
  branch_desc* bDesc = new branch_desc;
  bDesc->branchName  = new std::string( branchName ); 
  bDesc->dataPtr     = dataPtr;
  bDesc->branchData  = new std::string( branchData );
  bDesc->branchPtr   = nullptr;
  bDesc->bufferSize  =
  bDesc->splitLevel  = -999;
  bDesc->ppRef       = false;
  bDesc->dataHandler = nullptr;
  if ( biShadow == this ) {
    bDesc->firstBranch = biData->lastBranch;
    biData->bList.back()->nextBranch = bDesc;
  }
  else {
    bDesc->firstBranch = nullptr;
    biData->lastBranch = bDesc;
  }
  bDesc->nextBranch = nullptr;
  biData->bList.push_back( bDesc );
  return bDesc;
}

