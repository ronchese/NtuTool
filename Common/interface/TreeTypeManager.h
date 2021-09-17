#ifndef NtuTool_Common_TreeTypeManager_h
#define NtuTool_Common_TreeTypeManager_h
/** \class TreeTypeManager
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


//---------------
// C++ Headers --
//---------------
#include <map>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class TreeTypeManager: public DataHandlerManager {

 public:

  /** Constructor
   */
  TreeTypeManager();

  /** Destructor
   */
  virtual ~TreeTypeManager();

  /** Operations
   */
  /// register new type
  static void registerHandler( const std::string& code,
                               DataHandler* handler );

 private:

  virtual DataHandlerMap* handlerMap();
  static  DataHandlerMap* hm();

};


#endif // NtuTool_Common_TreeTypeManager_h







