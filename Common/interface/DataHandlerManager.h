#ifndef NtuTool_Common_DataHandlerManager_h
#define NtuTool_Common_DataHandlerManager_h

#include "NtuTool/Common/interface/BranchInterfaceData.h"

#include <map>
#include <string>

class DataHandler;
class DataHandlerMap;

class DataHandlerManager {

 public:

  DataHandlerManager();
  virtual ~DataHandlerManager();

  DataHandler* setHandler( const BranchInterfaceData::branch_desc* descPtr );
  DataHandler* getHandler( const BranchInterfaceData::branch_desc* descPtr );
  DataHandler* getHandler( const std::string& dataName );

  /// get concrete object
  DataHandler* getInstance( const std::string* branchData );

 private:

  DataHandlerManager           ( const DataHandlerManager& t ) = delete;
  DataHandlerManager& operator=( const DataHandlerManager& t ) = delete;

  typedef std::map< const void*, DataHandler* > data_map;
  typedef data_map::const_iterator data_iterator;

  data_map dataMap;
  std::map< std::string, DataHandler* > nameMap;

  virtual DataHandlerMap* handlerMap() = 0;

};


#endif // NtuTool_Common_DataHandlerManager_h
