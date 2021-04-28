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
template <class T>
TypeReset<T>::TypeReset( resetMode m ):
  DataReset( m ) {
}

//--------------
// Destructor --
//--------------
template <class T>
TypeReset<T>::~TypeReset() {
}

//--------------
// Operations --
//--------------
template <class T>
void TypeReset<T>::clearDatum( void* p, void* a ) {
  clearType( this->dPtr( p ) );
  return;
}


template <class T>
void TypeReset<T>::clearArray( void* p, void* a ) {
  T* q = this->dPtr( p );
  int size = 1;
  switch ( mode ) {
  default:
  case null:
    size = 1;
    break;
  case native_write: // native variable OR write ntuple
    size = *this->iPtr( a );
    break;
  case stl_read:     // stl vector AND read ntuple
    size = this->vPtr( a )->size();
    this->vPtr( a )->clear();
    break;
  }
  T* r = q + size;
  while ( r-- > q ) clearType( r );
  return;
}


template <class T>
void TypeReset<T>::clearType( T* p ) {
  *p = 0;
}

