/*
 *  See header file for a description of this class.
 *
 *  $Date: 2010-11-30 12:19:52 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "NtuTool/Common/interface/DataHandlerMap.h"

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
DataHandlerMap::DataHandlerMap() {
  handlerMap = new handler_map;
}

//--------------
// Destructor --
//--------------
DataHandlerMap::~DataHandlerMap() {
}

//--------------
// Operations --
//--------------
void DataHandlerMap::insert( const std::string& code,
                             DataHandler* handler ) {
  handler_iterator iter = handlerMap->find( code );
  handler_iterator iend = handlerMap->end();
  if ( iter == iend ) handlerMap->insert( std::make_pair( code, handler ) );
}


DataHandler* DataHandlerMap::find( const std::string& code ) {
  if ( handlerMap == nullptr ) return nullptr;
  handler_iterator iter = handlerMap->find( code );
  handler_iterator iend = handlerMap->end();
  if ( iter == iend ) return nullptr;
  return iter->second;
}

