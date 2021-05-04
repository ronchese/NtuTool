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
//#include "NtuTool/EDM/interface/NANOTypeWriter.h"


//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/EDM/interface/NANOTypeWriterManager.h"
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/TypeReset.h"
#include "NtuTool/Common/interface/DataResetString.h"
#include "NtuTool/Common/interface/DataResetVector.h"


// -----------------------------------------------------
//---------------
// C++ Headers --
//---------------
#include <iostream>

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Common/interface/DataHandlerManager.h"
#include "NtuTool/Common/interface/DataConvert.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/NanoAOD/interface/FlatTable.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>
#include <string>
#include <vector>

//-------------------
// Initializations --
//-------------------


//----------------
// Constructors --
//----------------
template <class T>
NANOTypeWriter<T>::NANOTypeWriter( const std::string& name,
                                   const std::string& code,
                                   const std::string& type ):
 DataHandler( name, code, type ) {
}

//--------------
// Destructor --
//--------------
template <class T>
NANOTypeWriter<T>::~NANOTypeWriter() {
}

//--------------
// Operations --
//--------------
template <class T>
DataHandler* NANOTypeWriter<T>::getInstance( const std::string& name,
                                             const std::string& code ) {
  NANOTypeWriter<T>* handler = new NANOTypeWriter<T>( name, code,
                                                      this->dataType );
  handler->dataReset = this->dataReset;
  return handler;
}


template <class T>
void NANOTypeWriter<T>::produces( edm::EDProducer* p,
                                  const std::string& tableName ) {
  p->produces<nanoaod::FlatTable>( tableName );
  return;
}


template <class T>
void* NANOTypeWriter<T>::put( edm::Event& e,
                              const BranchInterfaceData::branch_desc* b,
                              void* t ) {
  void* p = ( this->convType == DataHandler::ppReference ? this->auxPtr : b->dataPtr );
  nanoaod::FlatTable* table;
  int s = cSize( p );
  bool keep = true;
  if ( s < 0 ) {
    const BranchInterfaceData::branch_desc* n = b->nextBranch;
    if ( n != nullptr ) {
      void* q =  ( n->ppRef ? n->dataHandler->auxiliaryPtr() : n->dataPtr );
      n->dataHandler->print();
      s = dynamic_cast<NANOHandler*>( n->dataHandler )->cSize( q );
      keep = ( s < 0 );
    }
  }
  if ( t == nullptr ) {
    bool single = ( s < 0 );
    table = new nanoaod::FlatTable( single ? 1 : s,
                BranchInterfaceData::getInfo( b,
                NANOHandler::nanoTableName, *b->branchName ),
                single, false );
    table->setDoc( BranchInterfaceData::getInfo( b,
                   NANOHandler::nanoBranchDoc, *b->branchName ) );
  }
  else {
    table = static_cast<nanoaod::FlatTable*>( t );
  }
  if ( keep ) addC( p, table, *b->branchName,
                    BranchInterfaceData::getInfo( b,
                    NANOHandler::nanoBranchDoc, *b->branchName ) );
  return table;
}


template <class T>
void NANOTypeWriter<T>::buildPtr( void* p ) {
  this->convType = DataHandler::ppReference;
  return;
}


template <class T>
void NANOTypeWriter<T>::clearPtr( void* p ) {
  return;
}


template <class T>
template <class I>
void NANOTypeWriter<T>::addC( const void* p, void* t,
                              const std::string& name,
                              const std::string& doc,
                              nanoaod::FlatTable::ColumnType type ) {
  std::vector<I> vp;
  if ( this->convType == DataHandler::copyVector )
    DataConvert::copyVector(  this->cPtr( p ), &vp,
			     *this->iPtr( this->auxPtr ) );
  else vp.push_back( *this->cPtr( p ) );
  tPtr( t )->template addColumn<I>(
                      name, vp, doc, type, -1 );
  return;
}

