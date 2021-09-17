#ifndef NtuTool_Common_TypeHandler_h
#define NtuTool_Common_TypeHandler_h
/** \class TypeHandler
 *
 *  Description: 
 *    Base class to select type-specific calls to EDProducer and Event
 *    functions
 *
 *  $Date: 2010-11-05 16:31:20 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "NtuTool/Common/interface/DataHandler.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/TreeTypeManager.h"
#include "NtuTool/Common/interface/TypeReset.h"
#include "NtuTool/Common/interface/TypePointerManipulator.h"
#include "NtuTool/Common/interface/BranchInterface.h"
#include "NtuTool/Common/interface/DataConvert.h"

//---------------
// C++ Headers --
//---------------
#include <string>
#include <iostream>

//              ---------------------
//              -- Class Interface --
//              ---------------------

template <class Type, class Manager>
class TypeHandler: public virtual DataHandler,
                   public TypePointerManipulator<Type> {

 public:

  /** Constructor
   */
  TypeHandler() {}
  TypeHandler( DataReset::resetMode mode ) {
    registerHandler( new TypeReset<Type>( mode ) );
  }
  TypeHandler( DataReset* dr ) {
    registerHandler( dr );
  }

  /** Destructor
   */
  ~TypeHandler() override {}

 protected:

  Type* dummyPtr;
  void* setAuxPtr( void* p, DataHandlerManager* hm ) override {
    return ( this->auxPtr = ( this->convType == DataHandler::copyVector ?
                              this->arraySize( hm ) : p ) );
  }
  int* arraySize( DataHandlerManager* hm ) {
    if ( this->convType != DataHandler::copyVector ) return nullptr;
    bool fixedSize = DataConvert::fixedValue( this->dataSize );
    int* ptr = nullptr;
    if ( fixedSize ) {
      ptr = new int;
      std::stringstream ssize;
      ssize.str( this->dataSize );
      ssize >> *ptr;
    }
    else {
      DataHandler* handler = hm->getHandler( this->dataSize );
      ptr = this->iPtr( handler->auxiliaryPtr() );
    }
    return ptr;
  }

 private:

  void registerHandler( DataReset* dr ) {
    dataType = TreeTypeNames::typeName( dummyPtr );
    dataReset = dr;
    Manager::registerHandler( TreeTypeNames::typeCode( dummyPtr ), this );
    return;
  }

 private:

  TypeHandler           ( const TypeHandler& e ) = delete;
  TypeHandler& operator=( const TypeHandler& e ) = delete;

};

//#include "NtuTool/Common/interface/TypeHandler.hpp"

#endif // NtuTool_Common_TypeHandler_h




