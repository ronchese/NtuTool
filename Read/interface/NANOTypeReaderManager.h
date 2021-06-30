#ifndef NtuTool_Read_NANOTypeReaderManager_h
#define NtuTool_Read_NANOTypeReaderManager_h
/** \class NANOTypeReaderManager
 *
 *  Description: 
 *
 *
 *  $Date: 2020-07-23 13:01:04 $
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

class NANOTypeReaderManager: public DataHandlerManager {

 public:

  /** Constructor
   */
  NANOTypeReaderManager();

  /** Destructor
   */
  ~NANOTypeReaderManager() override;

  /** Operations
   */
  /// register new type
  static void registerHandler( const std::string& code,
                               DataHandler* handler );

 private:

  DataHandlerMap* handlerMap() override;
  static  DataHandlerMap* hm();

};


#endif // NtuTool_Read_NANOTypeReaderManager_h







