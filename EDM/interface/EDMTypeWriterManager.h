#ifndef EDMTypeWriterManager_H
#define EDMTypeWriterManager_H
/** \class EDMTypeWriterManager
 *
 *  Description: 
 *
 *
 *  $Date: 2011/03/01 18:09:32 $
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

class EDMTypeWriterManager: public DataHandlerManager {

 public:

  /** Constructor
   */
  EDMTypeWriterManager();

  /** Destructor
   */
  virtual ~EDMTypeWriterManager();

  /** Operations
   */
  /// register new type
  static void registerHandler( const std::string& code,
                               DataHandler* handler );

 private:

  virtual DataHandlerMap* handlerMap();
  static  DataHandlerMap* hm();

};


#endif // EDMTypeWriterManager_H






