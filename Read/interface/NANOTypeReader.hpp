/*
 *  See header file for a description of this class.
 *
 *  $Date: 2020/07/23 18:09:03 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
//#include "NtuTool/Read/interface/NANOTypeReader.h"

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
NANOTypeReader<T>::NANOTypeReader( const std::string& name,
                                 const std::string& code,
                                 const std::string& type ):
 DataHandler( name, code, type ) {
}

//--------------
// Destructor --
//--------------
template <class T>
NANOTypeReader<T>::~NANOTypeReader() {
}

//--------------
// Operations --
//--------------
template <class T>
DataHandler* NANOTypeReader<T>::getInstance( const std::string& name,
                                             const std::string& code ) {
  NANOTypeReader<T>* handler = new NANOTypeReader<T>( name, code,
                                                      this->dataType );
  handler->dataReset = this->dataReset;
  handler->nConv = this->nConv;
  return handler;
}


template <class T>
void NANOTypeReader<T>::process( void* p ) {
  AdditionalInfo* aInfo =
                  static_cast<AdditionalInfo*>( this->additionalInfo() );
  int nTrans = ( this->auxPtr != p ? *this->iPtr( this->auxPtr ) : 1 );
  if ( nTrans < 0 ) return;
  if ( aInfo->arrayPtr == nullptr ) return;
  this->translate( aInfo->arrayPtr, this->dPtr( p ), nTrans );
  return;
}


template <class T>
void* NANOTypeReader<T>::setAddInfo( void* p ) {
  AdditionalInfo* aInfo = static_cast<AdditionalInfo*>( p );
  aInfo->arrayPtr = tmpArray( aInfo->maxSize );
  return DataHandler::setAddInfo( p );
}


template <class T>
void NANOTypeReader<T>::translate( void* sPtr, void* dPtr, int n ) {
  if ( nConv != nullptr ) (*nConv)( sPtr, dPtr, n );
  return;
}

