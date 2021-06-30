/*
 *  See header file for a description of this class.
 *
 *  $Date: 2010-11-05 16:31:20 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
//#include "NtuTool/EDM/interface/EDMTypeWriter.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Common/interface/DataHandlerManager.h"
#include "NtuTool/Common/interface/DataConvert.h"
#include "NtuTool/EDM/interface/EDProducerWrapper.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>
#include <string>

//-------------------
// Initializations --
//-------------------


//----------------
// Constructors --
//----------------
template <class T>
EDMTypeWriter<T>::EDMTypeWriter( const std::string& name,
                                 const std::string& code,
                                 const std::string& type ):
 DataHandler( name, code, type ) {
}


//--------------
// Destructor --
//--------------
template <class T>
EDMTypeWriter<T>::~EDMTypeWriter() {
}

//--------------
// Operations --
//--------------
template <class T>
DataHandler* EDMTypeWriter<T>::getInstance( const std::string& name,
                                            const std::string& code ) {
  EDMTypeWriter<T>* handler = new EDMTypeWriter<T>( name, code,
                                                    this->dataType );
  handler->dataReset = this->dataReset;
  return handler;
}


template <class T>
void EDMTypeWriter<T>::produces( EDProducerWrapper* p ) {
  if ( this->convType != DataHandler::copyVector )
       p->produces<             T  >( this->dataName ).
                      setBranchAlias( this->dataName );
  else p->produces< std::vector<T> >( this->dataName ).
                      setBranchAlias( this->dataName );
  return;
}


template <class T>
void EDMTypeWriter<T>::put( edm::Event& e, const void* p ) {
  if ( this->convType == DataHandler::ppReference ) {
    e.put( typePtr( this->dPtr( this->auxPtr ) ), this->dataName );
    return;
  }
  if ( this->convType != DataHandler::copyVector ) {
    e.put( typePtr( new T( *this->cPtr( p ) ) ), this->dataName );
  }
  else {
    std::vector<T>* vp = new std::vector<T>;
    DataConvert::copyVector( this->cPtr( p ), vp, *this->iPtr( this->auxPtr ) );
    e.put( vectPtr( vp ), this->dataName );
  }
  return;
}


template <class T>
void EDMTypeWriter<T>::buildPtr( void* p ) {
  this->auxPtr = *this->pPtr( p ) = new T;
  this->convType = DataHandler::ppReference;
  return;
}


template <class T>
void EDMTypeWriter<T>::clearPtr( void* p ) {
  this->auxPtr = *this->pPtr( p ) = nullptr;
  return;
}

