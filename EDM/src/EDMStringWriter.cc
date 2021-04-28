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
  dataReset = new TypeReset<char>( DataReset::native_write );
  C__String* p = nullptr;
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( p ),
                                         this );
}


EDMStringWriter::EDMStringWriter( const std::string& name,
                                  const std::string& code,
                                  const std::string& type ):
 DataHandler( name, code, type ),
 EDMTypeWriter( nullptr ) {
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
  std::cout << "EDMStringWriter::put " << dataName << std::endl;
  e.put( typePtr( new std::string( static_cast<const char*>( p ) ) ),
         dataName );
  return;
}

