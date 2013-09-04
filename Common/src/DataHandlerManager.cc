#include <iostream>

#include "NtuTool/Common/interface/DataHandlerManager.h"
#include "NtuTool/Common/interface/DataHandler.h"
#include "NtuTool/Common/interface/DataHandlerMap.h"


DataHandlerManager::DataHandlerManager() {
}


DataHandlerManager::~DataHandlerManager() {
}


DataHandler* DataHandlerManager::setHandler( const void* descPtr,
                                             const std::string* branchData ) {

  data_iterator iter;
  if ( ( iter = dataMap.find( descPtr ) ) != dataMap.end() )
    return iter->second;
  DataHandler* dataHandler = getInstance( branchData );
  dataMap.insert( std::make_pair( descPtr, dataHandler ) );
  return dataHandler;

}


DataHandler* DataHandlerManager::getHandler( const void* descPtr ) {

  data_iterator iter;
  if ( ( iter = dataMap.find( descPtr ) ) == dataMap.end() ) return 0;
  return iter->second;

}


DataHandler* DataHandlerManager::getHandler( const std::string& dataName ) {

  data_iterator iter = dataMap.begin();
  data_iterator iend = dataMap.end();
  while ( iter != iend ) {
    const std::pair<const void*,DataHandler*>& entry = *iter++;
    DataHandler* handler = entry.second;
    if ( handler->getName() == dataName ) return handler;
  }
  return 0;

}


DataHandler* DataHandlerManager::getInstance( const std::string* branchData ) {
  int bdt = branchData->find( "/" );
  int edt = branchData->find( ":" );
  if ( edt < 0 ) edt = branchData->length();
  std::string name = branchData->substr( 0, bdt++ );
  std::string code = branchData->substr( bdt, edt );
  if ( handlerMap() == 0 ) return 0;
  DataHandler* handler = handlerMap()->find( code );
  if ( handler == 0 ) {
    std::cout << "type not found" << std::endl;
    return 0;
  }
  return handler->getInstance( name, code );
}

