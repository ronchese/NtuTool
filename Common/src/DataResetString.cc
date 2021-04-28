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
#include <iostream>

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
DataResetString::DataResetString( resetMode m ):
  TypeReset<std::string>( m ) {
}

//--------------
// Destructor --
//--------------
DataResetString::~DataResetString() {
}

//--------------
// Operations --
//--------------
template<>
void TypeReset<std::string>::clearType( std::string* p ) {
  *p = "";
}

