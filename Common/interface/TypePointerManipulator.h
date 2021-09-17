#ifndef NtuTool_Common_TypePointerManipulator_h
#define NtuTool_Common_TypePointerManipulator_h
/** \class TypePointerManipulator
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
#include "NtuTool/Common/interface/BranchInterface.h"

//---------------
// C++ Headers --
//---------------
#include <vector>

//              ---------------------
//              -- Class Interface --
//              ---------------------

template <class Type>
class TypePointerManipulator {

 public:

  typedef Type data_type;

  /** Constructor
   */
  TypePointerManipulator() {}

  /** Destructor
   */
  virtual ~TypePointerManipulator() {}

  static             Type * dPtr(       void* p ) {
    return static_cast<            Type *>( p );
  } 
  static const       Type * cPtr( const void* p ) {
    return static_cast<const       Type *>( p );
  }
  static std::vector<Type>* vPtr(       void* p ) {
    return static_cast<std::vector<Type>*>( p );
  } 
  static              int * iPtr(       void* p ) {
    return BranchInterface::iPtr( p );
  } 
  static     unsigned int * uPtr(       void* p ) {
    return BranchInterface::uPtr( p );
  } 
  static             void** pPtr(       void* p ) {
    return BranchInterface::pPtr( p );
  } 

 private:

  TypePointerManipulator           ( const TypePointerManipulator& e ) = delete;
  TypePointerManipulator& operator=( const TypePointerManipulator& e ) = delete;

};

#endif // NtuTool_Common_TypePointerManipulator_h




