#ifndef NtuTool_EDM_EDMDataHandler_h
#define NtuTool_EDM_EDMDataHandler_h
/** \class EDMDataHandler
 *
 *  Description: 
 *    Base class to select type-specific calls to EDProducer and Event
 *    functions
 *
 *  $Date: 2021/04/15 16:06:55 $
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
#include "NtuTool/Common/interface/DataHandler.h"
namespace edm {
  class Event;
}
class EDProducerWrapper;

//---------------
// C++ Headers --
//---------------
#include <string>
#include <iostream>
//              ---------------------
//              -- Class Interface --
//              ---------------------

class EDMDataHandler {

 public:

  /** Constructor
   */
  EDMDataHandler() {}

  /** Destructor
   */
  virtual ~EDMDataHandler() {}

  /** Operations
   */
  /// EDProducer function
  virtual void produces( EDProducerWrapper* p ) = 0;

  /// Event function
  virtual void  put( edm::Event& e, const void* p ) = 0;
  virtual void* put( edm::Event& e,
                     const BranchInterfaceData::branch_desc* b, void* t ) {
    put( e, b->dataPtr );
    return nullptr;
  }

 private:

  EDMDataHandler           ( const EDMDataHandler& e ) = delete;
  EDMDataHandler& operator=( const EDMDataHandler& e ) = delete;

};


#endif // NtuTool_EDM_EDMDataHandler_h


