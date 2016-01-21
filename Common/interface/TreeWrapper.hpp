#include <iostream>
#include <sstream>

#include "NtuTool/Common/interface/TreeTypeNames.h"

template<class T>
void TreeWrapper::setUserParameter( const std::string& key, const T& val ) {
  std::stringstream sstr;
  sstr.str( "" );
  sstr << val;
  setUserParameter( key, sstr.str() );
  return;
}


template<class T>
void TreeWrapper::getUserParameter( const std::string& key, T& val ) {
  std::stringstream sstr;
  sstr.str( getUserParameter( key ) );
  sstr >> val;
  return;
}


template<class T>
T    TreeWrapper::getUserParameter( const std::string& key ) {
  T val;
  getUserParameter( key, val );
  return val;
}


template <class T>
void TreeWrapper::setBranch( const char* branchName,
                             T* dataPtr,
                             int bufferSize,
                             int splitLevel ) {

  std::string
  dataName  = branchName;
  dataName += "/";
  dataName += TreeTypeNames::typeCode( dataPtr );
  branch_desc* bDesc = newBranch( branchName, dataPtr, dataName.c_str() );
  bDesc->bufferSize = bufferSize;
  bDesc->splitLevel = splitLevel;
  bDesc->branchPtr  = 0;
  return;

}


template <class T>
void TreeWrapper::setBranch( const char* branchName,
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
  return;

}


template <class T>
void TreeWrapper::setBranch( const char* branchName,
                             T** dataPtr,
                             int bufferSize,
                             int splitLevel ) {

  std::string
  dataName  = branchName;
  dataName += "/";
  dataName += TreeTypeNames::typeCode( *dataPtr );
  branch_desc* bDesc = newBranch( branchName, dataPtr, dataName.c_str() );
  bDesc->bufferSize = bufferSize;
  bDesc->splitLevel = splitLevel;
  bDesc->branchPtr  = 0;
  bDesc->ppRef      = true;
  return;

}


template <class T>
void TreeWrapper::setBranch( const char* branchName,
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
  return;

}

