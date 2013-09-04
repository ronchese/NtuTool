#ifndef DataResetVector_H
#define DataResetVector_H
/** \class DataResetVector
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
#include <vector>

//              ---------------------
//              -- Class Interface --
//              ---------------------

template <class T>
class DataResetVector: public DataReset {

 public:

  /** Constructor
   */
  DataResetVector( dataType t = null );

  /** Destructor
   */
  virtual ~DataResetVector();

  /** Operations
   */
  /// reset data
  virtual void clearDatum( void* p, void* a );

 protected:

  dataType type;

};

#include "NtuTool/Common/interface/DataResetVector.icc"

#endif // DataResetVector_H

