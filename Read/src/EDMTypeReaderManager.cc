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
#include "NtuTool/Read/interface/EDMTypeReader.h"
#include "NtuTool/Common/interface/DataHandlerMap.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>

//-------------------
// Initializations --
//-------------------
DataHandlerMap* EDMTypeReaderManager::etrMap = 0;

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
  if ( etrMap == 0 ) etrMap = new DataHandlerMap;
  return etrMap;
}


void EDMTypeReaderManager::registerHandler( const std::string& code,
                                            DataHandler* handler ) {
  if ( etrMap == 0 ) etrMap = new DataHandlerMap;
  etrMap->insert( code, handler );
}

