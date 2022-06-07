#include <iostream>
#include <fstream>
#include <string>

#include "NtuTool/Common/interface/UserParametersManager.h"

UserParametersManager::UserParametersManager() {
}


UserParametersManager::~UserParametersManager() {
}


void UserParametersManager::setConfiguration( const std::string& file ) {
  std::ifstream cfg( file.c_str() );
  int length;
  int lenMax = 1000;
  char* line = new char[lenMax];
  char* lptr;
  while ( cfg.getline( line, lenMax ) ) {
    lptr = line;
    while ( *lptr == ' ' ) ++lptr;
    if    ( *lptr == '#' ) continue;
    std::string key( lptr );
    length = key.find( " " );
    if ( length < 0 ) {
      std::cout << "invalid configuration input: " << line << std::endl;
      continue;
    }
    key = key.substr( 0, length );
    lptr += length;
    while ( *lptr == ' ' ) ++lptr;
    std::string val( lptr );
    length = val.find( " " );
    if ( length >= 0 )
    val = val.substr( 0, length );
    setUserParameter( key, val );
  }
  delete[] line;
  return;
}


void UserParametersManager::setUserParameter( const std::string& key,
                                    const std::string& val ) {
  std::map<std::string,std::string>::iterator
                                     iter = userParameters.find( key );
  std::map<std::string,std::string>::iterator
                                     iend = userParameters.end();
  if ( iter != iend ) iter->second = val;
  else                userParameters.insert( make_pair( key, val ) );
  return;
}


void UserParametersManager::setUserParameter( const std::string& key,
                                    const        bool& val ) {
  setUserParameter( key, val ? "t" : "f" );
  return;
}


const std::string& UserParametersManager::getUserParameter( const std::string& key ) {
  static std::string dum( "" );
  std::map<std::string,std::string>::iterator
                                     iter = userParameters.find( key );
  std::map<std::string,std::string>::iterator
                                     iend = userParameters.end();
  if ( iter != iend ) return iter->second;
  return dum;
}


void UserParametersManager::getUserParameter( const std::string& key, bool& val ) {
  const char* flag = getUserParameter( key ).c_str();
  val = (   ( *flag == 't' ) || ( *flag == 'T' ) ||
          ( ( *flag >= '1' ) && ( *flag <= '9' ) ) );
  return;
}


void UserParametersManager::dumpAll( std::ostream& os ) {
  std::map<std::string,std::string>::const_iterator
                                           iter = userParameters.begin();
  std::map<std::string,std::string>::const_iterator
                                           iend = userParameters.end();
  while ( iter != iend ) {
    const std::pair<std::string,std::string>& entry = *iter++;
    os << entry.first << " " << entry.second << std::endl;
  }
  return;
}

