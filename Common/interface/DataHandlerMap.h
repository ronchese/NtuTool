#ifndef NtuTool_Common_DataHandlerMap_h
#define NtuTool_Common_DataHandlerMap_h
/** \class DataHandlerMap
 *
 *  Description: 
 *
 *
 *  $Date: 2010-11-30 12:19:52 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------


//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
class DataHandler;

//---------------
// C++ Headers --
//---------------
#include <string>
#include <map>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class DataHandlerMap {

 public:

  /** Constructor
   */
  DataHandlerMap();

  /** Destructor
   */
  virtual ~DataHandlerMap();

  /** Operations
   */
  /// insert new handler
  void insert( const std::string& code,
               DataHandler* handler );
  DataHandler* find( const std::string& code );

 private:

  typedef std::map<std::string,DataHandler*> handler_map;
  typedef handler_map::const_iterator handler_iterator;
  handler_map* handlerMap;

};


#endif // NtuTool_Common_DataHandlerMap_h


