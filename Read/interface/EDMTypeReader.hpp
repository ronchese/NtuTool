/*
 *  See header file for a description of this class.
 *
 *  $Date: 2011/03/01 18:09:03 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
//#include "NtuTool/Read/interface/EDMTypeReader.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Common/interface/DataHandler.h"
#include "NtuTool/Common/interface/DataConvert.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>
#include <sstream>

//-------------------
// Initializations --
//-------------------


//----------------
// Constructors --
//----------------
template <class T>
EDMTypeReader<T>::EDMTypeReader( const std::string& name,
                                 const std::string& code,
                                 const std::string& type ):
 DataHandler( name, code, type ) {
}

//--------------
// Destructor --
//--------------
template <class T>
EDMTypeReader<T>::~EDMTypeReader() {
}

//--------------
// Operations --
//--------------
template <class T>
DataHandler* EDMTypeReader<T>::getInstance( const std::string& name,
                                            const std::string& code ) {
  EDMTypeReader<T>* handler = new EDMTypeReader<T>( name, code,
                                                    this->dataType );
  handler->dataReset = this->dataReset;
  return handler;
}


template <class T>
void EDMTypeReader<T>::process( void* p ) {
  if ( this->convType == DataHandler::copyVector )
       DataConvert::copyVector( this->vPtr( this->auxPtr ), this->dPtr( p ) );
  return;
}


template <class T>
void* EDMTypeReader<T>::setAuxPtr( void* p, DataHandlerManager* hm ) {
  if ( this->auxPtr == nullptr ) this->auxPtr =
                               ( this->convType == DataHandler::copyVector ?
                                 new std::vector<T>( *this->arraySize( hm ) ) :
                                 p );
  return this->auxPtr;
}

