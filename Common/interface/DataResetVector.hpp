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
//#include "NtuTool/Common/interface/DataResetVector.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------


//---------------
// C++ Headers --
//---------------
#include <vector>

//-------------------
// Initializations --
//-------------------


//----------------
// Constructors --
//----------------
template <class T>
DataResetVector<T>::DataResetVector( dataType t ):
  type( t ) {
}

//--------------
// Destructor --
//--------------
template <class T>
DataResetVector<T>::~DataResetVector() {
}

//--------------
// Operations --
//--------------
template <class T>
void DataResetVector<T>::clearDatum( void* p, void* a ) {
  static_cast< std::vector<T>* >( p )->clear();
  return;
}

