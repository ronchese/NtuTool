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
EDMTypeWriter<T>::EDMTypeWriter() {
}


template <class T>
EDMTypeWriter<T>::EDMTypeWriter( const std::string& name,
                                 const std::string& code,
                                 const std::string& type ):
 DataHandler( name, code, type ) {
}


template <class T>
EDMTypeWriter<T>::EDMTypeWriter( bool dum ) {
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
  EDMTypeWriter<T>* handler = new EDMTypeWriter<T>( name, code, dataType );
  handler->dataReset = dataReset;
  return handler;
}


template <class T>
void EDMTypeWriter<T>::produces( edm::EDProducer* p ) {
  if ( convType != copyVector )
       p->produces<             T  >( dataName ).setBranchAlias( dataName );
  else p->produces< std::vector<T> >( dataName ).setBranchAlias( dataName );
  return;
}


template <class T>
void EDMTypeWriter<T>::put( edm::Event& e, const void* p ) {
  if ( convType == ppReference ) {
    e.put( typePtr( reinterpret_cast<T*>( auxPtr ) ), dataName );
    return;
  }
  if ( convType != copyVector ) {
    e.put( typePtr( new T( *reinterpret_cast<const T*>( p ) ) ), dataName );
  }
  else {
    std::vector<T>* vp = new std::vector<T>;
    DataConvert::copyVector( reinterpret_cast<const T*>( p ),
                             vp, *reinterpret_cast<int*>( auxPtr ) );
    e.put( vectPtr( vp ), dataName );
  }
  return;
}


template <class T>
void EDMTypeWriter<T>::buildPtr( void* p ) {
  auxPtr = *reinterpret_cast<T**>( p ) = new T;
  convType = ppReference;
  return;
}


template <class T>
void EDMTypeWriter<T>::clearPtr( void* p ) {
  auxPtr = *reinterpret_cast<T**>( p ) = 0;
  return;
}


template <class T>
void* EDMTypeWriter<T>::setAuxPtr( void* p, DataHandlerManager* hm ) {
  if ( convType == copyVector ) {
    bool fixedSize = DataConvert::fixedValue( dataSize );
    if ( fixedSize ) {
      auxPtr = new int;
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

