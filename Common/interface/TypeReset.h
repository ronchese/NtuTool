#ifndef NtuTool_Common_TypeReset_h
#define NtuTool_Common_TypeReset_h
/** \class TypeReset
 *
 *  Description: 
 *    Class to reset data of 1byte size
 *
 *  $Date: 2010-12-01 11:42:45 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "NtuTool/Common/interface/DataReset.h"
#include "NtuTool/Common/interface/TypePointerManipulator.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------


//---------------
// C++ Headers --
//---------------


//              ---------------------
//              -- Class Interface --
//              ---------------------

template <class T>
class TypeReset: public DataReset,
                 public TypePointerManipulator<T> {

 public:

  /** Constructor
   */
  TypeReset( resetMode m = null );

  /** Destructor
   */
  ~TypeReset() override;

  /** Operations
   */
  /// reset data
  void clearDatum( void* p, void* a ) override;
  void clearArray( void* p, void* a ) override;

 protected:

  virtual void clearType( T* p );
//  dataType type;

 private:

  TypeReset           ( const TypeReset& e ) = delete;
  TypeReset& operator=( const TypeReset& e ) = delete;

};

#include "NtuTool/Common/interface/TypeReset.hpp"

#endif // NtuTool_Common_TypeReset_h


