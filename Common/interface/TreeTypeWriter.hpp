/*
 *  See header file for a description of this class.
 *
 *  $Date: 2011/03/01 18:06:55 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
//#include "NtuTool/Common/interface/TreeTypeWriter.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Common/interface/DataHandlerManager.h"
#include "NtuTool/Common/interface/DataConvert.h"
#include "TTree.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>
#include <sstream>
#include <string>

//-------------------
// Initializations --
//-------------------


//----------------
// Constructors --
//----------------
template <class T>
TreeTypeWriter<T>::TreeTypeWriter() {
}


template <class T>
TreeTypeWriter<T>::TreeTypeWriter( const std::string& name,
                                   const std::string& code,
                                   const std::string& type ):
 DataHandler( name, code, type ) {
}


template <class T>
TreeTypeWriter<T>::TreeTypeWriter( bool dum ) {
}

//--------------
// Destructor --
//--------------
template <class T>
TreeTypeWriter<T>::~TreeTypeWriter() {
}

//--------------
// Operations --
//--------------
template <class T>
DataHandler* TreeTypeWriter<T>::getInstance( const std::string& name,
                                             const std::string& code ) {
  TreeTypeWriter<T>* handler = new TreeTypeWriter<T>( name, code, dataType );
  handler->dataReset = dataReset;
  return handler;
}


template <class T>
TBranch* TreeTypeWriter<T>::branch( TTree* tree,
                                    const std::string* name, void** p,
                                    int bufferSize, int splitLevel ) {
  return tree->Branch( name->c_str(), reinterpret_cast<T**>( p ),
                       bufferSize, splitLevel );
}


template <class T>
void* TreeTypeWriter<T>::setAuxPtr( void* p, DataHandlerManager* hm ) {
  if ( convType == copyVector ) {
    bool fixedSize = DataConvert::fixedValue( dataSize );
    if ( fixedSize ) {
      if ( auxPtr == 0 ) auxPtr = new int;
      std::stringstream ssize;
      ssize.str( dataSize );
      ssize >> *reinterpret_cast<int*>( auxPtr );
    }
    else {
      DataHandler* handler = hm->getHandler( dataSize );
      auxPtr = handler->auxiliaryPtr();
    }
  }
  else {
    auxPtr = p;
  }
  return auxPtr;
}
