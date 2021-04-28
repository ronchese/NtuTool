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
#include "NtuTool/Common/interface/TreeTypeNames.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>

//-------------------
// Initializations --
//-------------------


//----------------
// Constructors --
//----------------
template <class T>
DataResetVector<T>::DataResetVector( resetMode m ):
  DataReset( m ) {
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

