#ifndef DataHandlerManager_h
#define DataHandlerManager_h

#include <map>
#include <string>

class DataHandler;
class DataHandlerMap;

class DataHandlerManager {

 public:

  DataHandlerManager();
  virtual ~DataHandlerManager();

  DataHandler* setHandler( const void* descPtr,
                           const std::string* branchData );
  DataHandler* getHandler( const void* descPtr );
  DataHandler* getHandler( const std::string& dataName );

  /// get concrete object
  DataHandler* getInstance( const std::string* branchData );

 private:

  DataHandlerManager( const DataHandlerManager& t );
  DataHandlerManager& operator=( const DataHandlerManager& t );

  typedef std::map< const void*, DataHandler* > data_map;
  typedef data_map::const_iterator data_iterator;

  data_map dataMap;

  virtual DataHandlerMap* handlerMap() = 0;

};


#endif
