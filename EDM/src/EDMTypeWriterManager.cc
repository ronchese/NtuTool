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
#include "NtuTool/EDM/interface/EDMTypeWriterManager.h"

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
EDMTypeWriterManager::EDMTypeWriterManager() {
}

//--------------
// Destructor --
//--------------
EDMTypeWriterManager::~EDMTypeWriterManager() {
}

//--------------
// Operations --
//--------------
DataHandlerMap* EDMTypeWriterManager::handlerMap() {
  return hm();
}


void EDMTypeWriterManager::registerHandler( const std::string& code,
                                            DataHandler* handler ) {
  hm()->insert( code, handler );
}


DataHandlerMap* EDMTypeWriterManager::hm() {
  static DataHandlerMap* etwMap = new DataHandlerMap;
  return etwMap;
}

