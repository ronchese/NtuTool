#ifndef TreeTypeNames_H
#define TreeTypeNames_H
/** \class TreeTypeNames
 *
 *  Description: 
 *    Class to assign names to types
 *
 *  $Date: 2010-12-09 11:49:02 $
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
class C__String;

//---------------
// C++ Headers --
//---------------
#include <string>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class TreeTypeNames {

 public:

  /** Constructor
   */
  TreeTypeNames();

  /** Destructor
   */
  virtual ~TreeTypeNames();

  /** Operations
   */
  /// Type codes used by ROOT
  template <class T> static
  std::string typeCode( T*  dataPtr );
  template <class T> static
  std::string typeCode( T** dataPtr );

  /// Type names
  template <class T> static
  std::string typeName( T*  dataPtr );
  template <class T> static
  std::string typeName( T** dataPtr );

 private:


};


#endif // TreeTypeNames_H

