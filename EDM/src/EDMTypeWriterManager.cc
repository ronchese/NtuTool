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
#include "NtuTool/EDM/interface/EDMTypeWriter.h"
#include "NtuTool/Common/interface/DataHandlerMap.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>

//-------------------
// Initializations --
//-------------------
DataHandlerMap* EDMTypeWriterManager::etwMap = 0;

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
  if ( etwMap == 0 ) etwMap = new DataHandlerMap;
  return etwMap;
}


void EDMTypeWriterManager::registerHandler( const std::string& code,
                                            DataHandler* handler ) {
  if ( etwMap == 0 ) etwMap = new DataHandlerMap;
  etwMap->insert( code,handler );
}

