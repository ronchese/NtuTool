#include <iostream>
#include <sstream>

template <class T>
void UserParametersManager::setUserParameter( const std::string& key,
                                              const           T& val ) {
  std::stringstream sstr;
  sstr.str( "" );
  sstr << val;
  setUserParameter( key, sstr.str() );
  return;
}


template <class T>
void UserParametersManager::getUserParameter( const std::string& key,
                                                              T& val ) const {
  std::stringstream sstr;
  sstr.str( getUserParameter( key ) );
  sstr >> val;
  return;
}


template <class T>
T    UserParametersManager::getUserParameter( const std::string& key ) const {
  T val;
  getUserParameter( key, val );
  return val;
}

