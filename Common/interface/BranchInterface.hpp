#include <iostream>
#include <sstream>

#include "NtuTool/Common/interface/TreeTypeNames.h"

template <class T>
BranchInterface* BranchInterface::setBranch( const char* branchName,
                                             T* dataPtr,
                                             int bufferSize,
                                             int splitLevel,
                                             TBranch** branchPtr ) {

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
  const void*& ptr = bDesc->addInfo[type];
  if ( ptr == nullptr ) ptr = new T( i );
  return biShadow;
}

