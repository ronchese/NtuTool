#ifndef NANOTypeWriterManager_H
#define NANOTypeWriterManager_H
/** \class NANOTypeWriterManager
 *
 *  Description: 
 *
 *
 *  $Date: 2020/05/05 10:19:32 $
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

class NANOTypeWriterManager: public DataHandlerManager {

 public:

  /** Constructor
   */
  NANOTypeWriterManager();

  /** Destructor
   */
  ~NANOTypeWriterManager() override;

  /** Operations
   */
  /// register new type
  static void registerHandler( const std::string& code,
                               DataHandler* handler );

 private:

  DataHandlerMap* handlerMap() override;
  static  DataHandlerMap* hm();

};


#endif // NANOTypeWriterManager_H






