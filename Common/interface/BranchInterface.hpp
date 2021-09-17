#include <iostream>
#include <sstream>

#include "NtuTool/Common/interface/TreeTypeNames.h"

template <class T>
BranchInterface* BranchInterface::setBranch( const char* branchName,
                                             T* dataPtr,
                                             int bufferSize,
                                             int splitLevel,
                                             TBranch** branchPtr ) {

  if ( branchPtr == nullptr ) branchPtr = new TBranch*;
  std::string
  dataName  = branchName;
  dataName += "/";
  dataName += TreeTypeNames::typeCode( dataPtr );
  branch_desc* bDesc = newBranch( branchName, dataPtr, dataName.c_str() );
  bDesc->bufferSize = bufferSize;
  bDesc->splitLevel = splitLevel;
  bDesc->branchPtr  = branchPtr;
  return biShadow;

}


template <class T>
BranchInterface* BranchInterface::setBranch( const char* branchName,
                                             T** dataPtr,
                                             int bufferSize,
                                             int splitLevel,
                                             TBranch** branchPtr ) {
  if ( branchPtr == nullptr ) branchPtr = new TBranch*;
  std::string
  dataName  = branchName;
  dataName += "/";
  dataName += TreeTypeNames::typeCode( *dataPtr );
  branch_desc* bDesc = newBranch( branchName, dataPtr, dataName.c_str() );
  bDesc->bufferSize = bufferSize;
  bDesc->splitLevel = splitLevel;
  bDesc->branchPtr  = branchPtr;
  bDesc->ppRef      = true;
  return biShadow;
}

template <class T>
BranchInterface* BranchInterface::setInfo( int type, const T& i ) {
  branch_desc* bDesc = branchList().back();
  std::map<int,const void*>& m = bDesc->addInfo;
  std::map<int,const void*>::const_iterator iter = m.find( type );
  if ( iter == m.end() ) m[type] = new T( i );
  return biShadow;
}

