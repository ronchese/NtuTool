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
  return hm();
}


void TreeTypeManager::registerHandler( const std::string& code,
                                       DataHandler* handler ) {
  hm()->insert( code, handler );
}


DataHandlerMap* TreeTypeManager::hm() {
  static DataHandlerMap* stmMap = new DataHandlerMap;
  return stmMap;
}

