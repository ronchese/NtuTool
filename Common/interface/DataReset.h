#ifndef DataReset_H
#define DataReset_H
/** \class DataReset
 *
 *  Description: 
 *    Base class to reset data with different types
 *
 *  $Date: 2010-12-01 11:42:45 $
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


//---------------
// C++ Headers --
//---------------


//              ---------------------
//              -- Class Interface --
//              ---------------------

class DataReset {

 public:

  enum resetMode{ null, native_write, stl_read };

  /** Constructor
   */
  DataReset( resetMode m = null );

  /** Destructor
   */
  virtual ~DataReset();

  /** Operations
   */
  /// reset data
  virtual void clearDatum( void* p, void* a );
  virtual void clearArray( void* p, void* a );

 protected:

  resetMode mode;

};


#endif // DataReset_H

