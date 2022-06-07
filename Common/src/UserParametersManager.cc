#include <iostream>
#include <fstream>
#include <string>

#include "NtuTool/Common/interface/UserParametersManager.h"

using namespace std;

UserParametersManager::UserParametersManager() {
}


UserParametersManager::~UserParametersManager() {
}


void UserParametersManager::setConfiguration( const string& file ) {
  ifstream cfg( file.c_str() );
  int length;
  int lenMax = 1000;
  char* line = new char[lenMax];
  char* lptr;
  while ( cfg.getline( line, lenMax ) ) {
    lptr = line;
    while ( *lptr == ' ' ) ++lptr;
    if    ( *lptr == '#' ) continue;
    string key( lptr );
    length = key.find( " " );
    if ( length < 0 ) {
      cout << "invalid configuration input: " << line << endl;
      continue;
    }
    key = key.substr( 0, length );
    lptr += length;
    while ( *lptr == ' ' ) ++lptr;
    string val( lptr );
    length = val.find( " " );
    if ( length >= 0 )
    val = val.substr( 0, length );
    setUserParameter( key, val );
  }
  delete[] line;
  return;
}


void UserParametersManager::setUserParameter( const string& key,
                                              const string& val ) {
  map<string,string>::iterator iter = userParameters.find( key );
  map<string,string>::iterator iend = userParameters.end();
  if ( iter != iend ) iter->second = val;
  else                userParameters.insert( make_pair( key, val ) );
  return;
}


void UserParametersManager::setUserParameter( const string& key,
                                              const   bool& val ) {
  setUserParameter( key, val ? "t" : "f" );
  return;
}


const string& UserParametersManager::getUserParameter( const string& key )
                                                       const {
  static string dum( "" );
  map<string,string>::const_iterator iter = userParameters.find( key );
  map<string,string>::const_iterator iend = userParameters.end();
  if ( iter != iend ) return iter->second;
  return dum;
}


void UserParametersManager::getUserParameter( const string& key,
                                                      bool& val ) const {
  const char* flag = getUserParameter( key ).c_str();
  val = (   ( *flag == 't' ) || ( *flag == 'T' ) ||
          ( ( *flag >= '1' ) && ( *flag <= '9' ) ) );
  return;
}


void UserParametersManager::dumpAll( ostream& os ) const {
  std::map<string,string>::const_iterator iter = userParameters.begin();
  std::map<string,string>::const_iterator iend = userParameters.end();
  while ( iter != iend ) {
    const map<string,string>::value_type& entry = *iter++;
    os << entry.first << " " << entry.second << std::endl;
  }
  return;
}

