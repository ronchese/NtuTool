#ifndef NtuTool_Common_DataConvert_h
#define NtuTool_Common_DataConvert_h
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
#include <iostream>

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
  template <class S, class D>
  static int  copyVector( const std::vector<S>* v, D* p );

  /// copy C array to std::vector
  template <class S, class D>
  static void copyVector( const S* p, std::vector<D>* v, int n );

  /// copy C array to std::vector
  template <class T>
  static void copyVectorFromVoid( const void* p, std::vector<T>* v, int n ) {
    return copyVector( static_cast<const T*>( p ), v, n );
  }

  /// recognize fixed or variable
  static bool fixedValue( const std::string& x );

 private:


};

#include "NtuTool/Common/interface/DataConvert.hpp"

#endif // NtuTool_Common_DataConvert_h


