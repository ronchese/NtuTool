/*
 *  See header file for a description of this class.
 *
 *  $Date: 2020-05-05 10:21:04 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "NtuTool/EDM/interface/NANOTypeWriterManager.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Common/interface/DataHandlerMap.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>

//-------------------
// Initializations --
//-------------------


//----------------
// Constructors --
//----------------
NANOTypeWriterManager::NANOTypeWriterManager() {
}

//--------------
// Destructor --
//--------------
NANOTypeWriterManager::~NANOTypeWriterManager() {
}

//--------------
// Operations --
//--------------
DataHandlerMap* NANOTypeWriterManager::handlerMap() {
  return hm();
}


void NANOTypeWriterManager::registerHandler( const std::string& code,
                                             DataHandler* handler ) {
  hm()->insert( code, handler );
}


DataHandlerMap* NANOTypeWriterManager::hm() {
  static DataHandlerMap* ntwMap = new DataHandlerMap;
  return ntwMap;
}

