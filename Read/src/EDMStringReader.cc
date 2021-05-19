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
#include "NtuTool/Read/interface/EDMStringReader.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Read/interface/EDMTypeReaderManager.h"
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/TypeReset.h"

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
EDMStringReader::EDMStringReader():
 EDMTypeReader<std::string>( false ) {
  std::string* p = nullptr;
  this->dataType = TreeTypeNames::typeName( p );
  this->dataReset = new TypeReset<char>( DataReset::stl_read );
  EDMTypeReaderManager::registerHandler( "C", this );
}


EDMStringReader::EDMStringReader( const std::string& name,
                                  const std::string& code,
                                  const std::string& type ):
 DataHandler( name, code, type ),
 EDMTypeReader<std::string>( nullptr ) {
}

//--------------
// Destructor --
//--------------
EDMStringReader::~EDMStringReader() {
}

//--------------
// Operations --
//--------------
DataHandler* EDMStringReader::getInstance( const std::string& name,
                                           const std::string& code ) {
  EDMStringReader* handler = new EDMStringReader( name, code, dataType );
  handler->dataReset = dataReset;
  return handler;
}


void EDMStringReader::process( void* p ) {
  DataConvert::copyString( cPtr( auxPtr ), static_cast<char*>( p ) );
  return;
}


void* EDMStringReader::setAuxPtr( void* p, DataHandlerManager* hm ) {
  return auxPtr = new std::string;
}

// static object

static const EDMStringReader ter____c;
