/*
 *  See header file for a description of this class.
 *
 *  $Date: 2010-12-01 11:42:45 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "NtuTool/Common/interface/DataResetString.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include <string>

//---------------
// C++ Headers --
//---------------
#include <vector>

//-------------------
// Initializations --
//-------------------


//----------------
// Constructors --
//----------------
DataResetString::DataResetString( dataType t ):
  type( t ) {
}

//--------------
// Destructor --
//--------------
DataResetString::~DataResetString() {
}

//--------------
// Operations --
//--------------
void DataResetString::clearDatum( void* p, void* a ) {
  std::string* q = static_cast<std::string*>( p );
  *q = "";
  return;
}


void DataResetString::clearArray( void* p, void* a ) {
  std::string* q = static_cast<std::string*>( p );
  int size = 1;
  switch ( type ) {
  default:
  case null:
    size = 1;
    break;
  case write:
    size = *static_cast<int*>( a );
    break;
  case read:
    size = static_cast< std::vector<std::string>* >( a )->size();
    break;
  }
  std::string* r = q + size;
  while ( r-- > q ) *r = "";
  return;
}

