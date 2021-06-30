#include <iostream>
#include <sstream>

#include "NtuTool/Common/interface/TreeTypeNames.h"

template <class T>
void TreeWrapper::setUserParameter( const std::string& key, const T& val ) {
  std::stringstream sstr;
  sstr.str( "" );
  sstr << val;
  setUserParameter( key, sstr.str() );
  return;
}


template <class T>
void TreeWrapper::getUserParameter( const std::string& key, T& val ) {
  std::stringstream sstr;
  sstr.str( getUserParameter( key ) );
  sstr >> val;
  return;
}


template <class T>
T    TreeWrapper::getUserParameter( const std::string& key ) {
  T val;
  getUserParameter( key, val );
  return val;
}

