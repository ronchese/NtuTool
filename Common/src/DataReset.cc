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
#include "NtuTool/Common/interface/DataReset.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------


//---------------
// C++ Headers --
//---------------


//-------------------
// Initializations --
//-------------------


//----------------
// Constructors --
//----------------
DataReset::DataReset( resetMode m ):
  mode( m ) {
}

//--------------
// Destructor --
//--------------
DataReset::~DataReset() {
}

//--------------
// Operations --
//--------------
void DataReset::clearDatum( void* p, void* a ) {
  return;
}


void DataReset::clearArray( void* p, void* a ) {
  return;
}

