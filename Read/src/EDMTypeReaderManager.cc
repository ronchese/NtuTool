/*
 *  See header file for a description of this class.
 *
 *  $Date: 2010-11-08 13:01:04 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "NtuTool/Read/interface/EDMTypeReaderManager.h"

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
EDMTypeReaderManager::EDMTypeReaderManager() {
}

//--------------
// Destructor --
//--------------
EDMTypeReaderManager::~EDMTypeReaderManager() {
}

//--------------
// Operations --
//--------------
DataHandlerMap* EDMTypeReaderManager::handlerMap() {
  return hm();
}


void EDMTypeReaderManager::registerHandler( const std::string& code,
                                            DataHandler* handler ) {
  hm()->insert( code, handler );
}


DataHandlerMap* EDMTypeReaderManager::hm() {
  static DataHandlerMap* etrMap = new DataHandlerMap;
  return etrMap;
}

