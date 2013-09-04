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
#include "NtuTool/EDM/interface/EDMStringWriter.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/EDM/interface/EDMTypeWriterManager.h"
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/TypeReset.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>

//-------------------
// Initializations --
//-------------------
static EDMStringWriter tw____c;

//----------------
// Constructors --
//----------------
EDMStringWriter::EDMStringWriter():
 EDMTypeWriter<std::string>( false ) {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<char>( DataReset::write );
  C__String* p = 0;
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( p ),
                                         this );
}


EDMStringWriter::EDMStringWriter( const std::string& name,
                                  const std::string& code,
                                const std::string& type ):
 EDMTypeWriter<std::string>( name, code, type ) {
  DataHandler::dataReset = 0;
}


EDMStringWriter::EDMStringWriter( bool dum ) {
}

//--------------
// Destructor --
//--------------
EDMStringWriter::~EDMStringWriter() {
}

//--------------
// Operations --
//--------------
DataHandler* EDMStringWriter::getInstance( const std::string& name,
                                           const std::string& code ) {
  EDMStringWriter* handler = new EDMStringWriter( name, code, dataType );
  handler->dataReset = dataReset;
  return handler;
}


void EDMStringWriter::put( edm::Event& e, const void* p ) {
  std::auto_ptr<std::string> ap( new std::string( 
                                 reinterpret_cast<char*>(
                                       const_cast<void*>( p ) ) ) );
  e.put( ap, dataName );
  return;
}

