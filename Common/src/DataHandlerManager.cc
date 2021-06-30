#include <iostream>

#include "NtuTool/Common/interface/DataHandlerManager.h"
#include "NtuTool/Common/interface/DataHandler.h"
#include "NtuTool/Common/interface/DataHandlerMap.h"
#include "NtuTool/Common/interface/BranchInterfaceData.h"

DataHandlerManager::DataHandlerManager() {
}


DataHandlerManager::~DataHandlerManager() {
}


DataHandler* DataHandlerManager::setHandler(
             const BranchInterfaceData::branch_desc* descPtr ) {

  data_iterator iter;
  if ( ( iter = dataMap.find( descPtr ) ) != dataMap.end() )
    return iter->second;
  DataHandler* dataHandler = getInstance( descPtr->branchData );
  dataMap.insert( std::make_pair( descPtr, dataHandler ) );
  nameMap.insert( std::make_pair( dataHandler->getName(), dataHandler ) );
  return dataHandler;

}


DataHandler* DataHandlerManager::getHandler( const BranchInterfaceData::branch_desc* descPtr ) {

  data_iterator iter;
  if ( ( iter = dataMap.find( descPtr ) ) == dataMap.end() ) return nullptr;
  return iter->second;

}


DataHandler* DataHandlerManager::getHandler( const std::string& dataName ) {

  const auto iter = nameMap.find( dataName );
  if ( iter != nameMap.end() ) return iter->second;
  return nullptr;

}


DataHandler* DataHandlerManager::getInstance( const std::string* branchData ) {
  int bdt = branchData->find( "/" );
  int edt = branchData->find( ":" );
  if ( edt < 0 ) edt = branchData->length();
  std::string name = branchData->substr( 0, bdt++ );
  std::string code = branchData->substr( bdt, edt );
  if ( handlerMap() == nullptr ) return nullptr;
  DataHandler* handler = handlerMap()->find( code );
  if ( handler == nullptr ) {
    std::cout << "type not found: " << code << std::endl;
    return nullptr;
  }
  return handler->getInstance( name, code );
}

