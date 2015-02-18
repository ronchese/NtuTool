#ifndef TypeReset_H
#define TypeReset_H
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

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------


//---------------
// C++ Headers --
//---------------


//              ---------------------
//              -- Class Interface --
//              ---------------------

template<class T>
class TypeReset: public DataReset {

 public:

  /** Constructor
   */
  TypeReset( dataType t = null );

  /** Destructor
   */
  virtual ~TypeReset();

  /** Operations
   */
  /// reset data
  virtual void clearDatum( void* p, void* a );
  virtual void clearArray( void* p, void* a );

 protected:

  dataType type;

};

#include "NtuTool/Common/interface/TypeReset.hpp"

#endif // TypeReset_H

