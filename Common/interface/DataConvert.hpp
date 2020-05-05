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

/// copy std::vector to C array
template<class T>
int  DataConvert::copyVector( const std::vector<T>* v, T* p ) {
  typedef typename std::vector<T>::const_iterator vIter;
  vIter iter = v->begin();
  vIter iend = v->end();
  while ( iter != iend ) *p++ = *iter++;
  return v->size();
}

/// copy C array to std::vector
template<class T>
void DataConvert::copyVector( const T* p, std::vector<T>* v, int n ) {
  v->reserve( n );
  while ( n-- ) v->push_back( *p++ );
  return;
}


