/*
 *  See header file for a description of this class.
 *
 *  $Date: 2020-07-23 13:01:04 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "NtuTool/Read/interface/NANOTypeReaderManager.h"

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
NANOTypeReaderManager::NANOTypeReaderManager() {
}

//--------------
// Destructor --
//--------------
NANOTypeReaderManager::~NANOTypeReaderManager() {
}

//--------------
// Operations --
//--------------
DataHandlerMap* NANOTypeReaderManager::handlerMap() {
  return hm();
}


void NANOTypeReaderManager::registerHandler( const std::string& code,
                                             DataHandler* handler ) {
  hm()->insert( code, handler );
}


DataHandlerMap* NANOTypeReaderManager::hm() {
  static DataHandlerMap* etrMap = new DataHandlerMap;
  return etrMap;
}

