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
#include "NtuTool/EDM/interface/NANOStringWriter.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/EDM/interface/NANOTypeWriterManager.h"
#include "NtuTool/EDM/interface/NANOTableWrapper.h"
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/DataResetString.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>

//-------------------
// Initializations --
//-------------------
static NANOStringWriter tw____c;

//----------------
// Constructors --
//----------------
NANOStringWriter::NANOStringWriter():
 NANOTypeWriter<unsigned char>( false ) {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<unsigned char>( DataReset::native_write );
  C__String* p = nullptr;
  NANOTypeWriterManager::registerHandler( TreeTypeNames::typeCode( p ),
                                          this );
}


NANOStringWriter::NANOStringWriter( const std::string& name,
                                    const std::string& code,
                                    const std::string& type ):
 DataHandler( name, code, type ),
 NANOTypeWriter( nullptr ) {
}

//--------------
// Destructor --
//--------------
NANOStringWriter::~NANOStringWriter() {
}

//--------------
// Operations --
//--------------
DataHandler* NANOStringWriter::getInstance( const std::string& name,
                                            const std::string& code ) {
  NANOStringWriter* handler = new NANOStringWriter( name, code, dataType );
  handler->dataReset = dataReset;
  return handler;
}


int NANOStringWriter::cSize( const void* p ) {
  const unsigned char* q = cPtr( p );
  int n = 1;
  while ( *q++ ) ++n;
  return n;
}


void NANOStringWriter::addC( const void* p, void* t,
                             const std::string& name, const std::string& doc ) {
  std::vector<unsigned char> vp;
  DataConvert::copyVector( static_cast<const unsigned char*>( p ), &vp, cSize( p ) );
  NANOTableWrapper::addColumn<unsigned char>( tPtr( t ),
                    name, vp, doc, NANOTableWrapper::UInt8, -1 );
  return;
}

