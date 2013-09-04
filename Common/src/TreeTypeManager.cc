/*
 *  See header file for a description of this class.
 *
 *  $Date: 2011/03/01 18:08:37 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "NtuTool/Common/interface/TreeTypeManager.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Common/interface/DataHandlerMap.h"
#include "NtuTool/Common/interface/Math.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>

//-------------------
// Initializations --
//-------------------
DataHandlerMap* TreeTypeManager::stmMap = 0;

//----------------
// Constructors --
//----------------
TreeTypeManager::TreeTypeManager() {
}

//--------------
// Destructor --
//--------------
TreeTypeManager::~TreeTypeManager() {
}

//--------------
// Operations --
//--------------
DataHandlerMap* TreeTypeManager::handlerMap() {
  if ( stmMap == 0 ) stmMap = new DataHandlerMap;
  return stmMap;
}


void TreeTypeManager::registerHandler( const std::string& code,
                                       DataHandler* handler ) {
  if ( stmMap == 0 ) stmMap = new DataHandlerMap;
  stmMap->insert( code, handler );
}

