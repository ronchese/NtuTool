/*
 *  See header file for a description of this class.
 *
 *  $Date: 2010-12-01 11:42:45 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
//#include "NtuTool/Common/interface/TypeReset.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------


//---------------
// C++ Headers --
//---------------
#include <vector>
#include <iostream>

//-------------------
// Initializations --
//-------------------


//----------------
// Constructors --
//----------------
template<class T>
TypeReset<T>::TypeReset( dataType t ):
  type( t ) {
}

//--------------
// Destructor --
//--------------
template<class T>
TypeReset<T>::~TypeReset() {
}

//--------------
// Operations --
//--------------
template<class T>
void TypeReset<T>::clearDatum( void* p, void* a ) {
  T* q = reinterpret_cast<T*>( p );
  *q = 0;
  return;
}


template<class T>
void TypeReset<T>::clearArray( void* p, void* a ) {
  T* q = reinterpret_cast<T*>( p );
  int size = 1;
  switch ( type ) {
  default:
  case null:
    size = 1;
    break;
  case write:
    size = *reinterpret_cast<int*>( a );
    break;
  case read:
    size = reinterpret_cast< std::vector<T>* >( a )->size();
    break;
  }
  T* r = q + size;
  while ( r-- > q ) *r = 0;
  return;
}

