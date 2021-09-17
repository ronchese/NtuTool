#ifndef NtuTool_Common_DataResetString_h
#define NtuTool_Common_DataResetString_h
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
#include "NtuTool/Common/interface/TypeReset.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------


//---------------
// C++ Headers --
//---------------
#include <string>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class DataResetString: public TypeReset<std::string> {

 public:

  /** Constructor
   */
  DataResetString( resetMode m = null );

  /** Destructor
   */
  ~DataResetString() override;

};

#endif // NtuTool_Common_DataResetString_h


