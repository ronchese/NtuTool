#ifndef NtuTool_Common_DataResetVector_h
#define NtuTool_Common_DataResetVector_h
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
  DataResetVector( resetMode m = null );

  /** Destructor
   */
  ~DataResetVector() override;

  /** Operations
   */
  /// reset data
  void clearDatum( void* p, void* a ) override;

};

#include "NtuTool/Common/interface/DataResetVector.hpp"

#endif // NtuTool_Common_DataResetVector_h


