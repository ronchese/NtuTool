#ifndef NtuTool_Read_EDMTypeReaderManager_h
#define NtuTool_Read_EDMTypeReaderManager_h
/** \class EDMTypeReaderManager
 *
 *  Description: 
 *
 *
 *  $Date: 2010-11-08 13:01:04 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "NtuTool/Common/interface/DataHandlerManager.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
class DataHandlerMap;

//---------------
// C++ Headers --
//---------------
#include <map>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class EDMTypeReaderManager: public DataHandlerManager {

 public:

  /** Constructor
   */
  EDMTypeReaderManager();

  /** Destructor
   */
  ~EDMTypeReaderManager() override;

  /** Operations
   */
  /// register new type
  static void registerHandler( const std::string& code,
                               DataHandler* handler );

 private:

  DataHandlerMap* handlerMap() override;
  static  DataHandlerMap* hm();

};


#endif // NtuTool_Read_EDMTypeReaderManager_h







