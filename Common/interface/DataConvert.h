#ifndef DataConvert_H
#define DataConvert_H
/** \class DataConvert
 *
 *  Description: 
 *
 *
 *  $Date: 2010-11-11 11:17:56 $
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
#include <vector>
#include <string>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class DataConvert {

 public:

  /** Constructor
   */
  DataConvert();

  /** Destructor
   */
  virtual ~DataConvert();

  /** Operations
   */
  /// copy std::string to C string
  static void copyString( const std::string* s, char* c );

  /// copy std::vector to C array
  template<class T>
    static int  copyVector( const std::vector<T>* v, T* p );

  /// copy C array to std::vector
  template<class T>
    static void copyVector( const T* p, std::vector<T>* v, int n );

  /// recognize fixed or variable
  static bool fixedValue( const std::string& x );

 private:


};

#include "NtuTool/Common/interface/DataConvert.icc"

#endif // DataConvert_H

