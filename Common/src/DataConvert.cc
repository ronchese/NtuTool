/** \class DataConvert
 *
 *  Description: 
 *
 *
 *  $Date: 2010-11-11 11:17:56 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// This Class' Header --
//----------------------
#include "NtuTool/Common/interface/DataConvert.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------


//---------------
// C++ Headers --
//---------------
#include <vector>
#include <string>

//              ---------------------
//              -- Class Interface --
//              ---------------------

/** Constructor
 */
DataConvert::DataConvert() {
}

/** Destructor
 */
DataConvert::~DataConvert() {
}

/** Operations
 */
/// copy std::string to C string
void DataConvert::copyString( const std::string* s, char* c ) {
  const char* p = s->c_str();
  while ( ( *c++ = *p++ ) );
  return;
}

/// recognize fixed or variable
bool DataConvert::fixedValue( const std::string& x ) {
  const char* p = x.c_str();
  while ( *p ) {
    if ( *p < '0' ) return false;
    if ( *p > '9' ) return false;
    p++;
  }
  return true;
}
