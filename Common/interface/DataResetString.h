#ifndef DataResetString_H
#define DataResetString_H
/** \class DataResetString
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

class DataResetString: public DataReset {

 public:

  /** Constructor
   */
  DataResetString( dataType t = null );

  /** Destructor
   */
  virtual ~DataResetString();

  /** Operations
   */
  /// reset data
  virtual void clearDatum( void* p, void* a );
  virtual void clearArray( void* p, void* a );

 protected:

  dataType type;

};


#endif // DataResetString_H

