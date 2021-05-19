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
#include "NtuTool/Read/interface/NANOStringReader.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Read/interface/NANOTypeReaderManager.h"
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
NANOStringReader::NANOStringReader():
 NANOTypeReader<unsigned char>( false ) {
  this->dataType = TreeTypeNames::typeName( dummyPtr );
  this->dataReset = new TypeReset<char>( DataReset::native_write );
  C__String* p = nullptr;
  NANOTypeReaderManager::registerHandler( TreeTypeNames::typeCode( p ),
                                          this );
}


NANOStringReader::NANOStringReader( const std::string& name,
                                    const std::string& code,
                                    const std::string& type ):
 DataHandler( name, code, type ),
 NANOTypeReader<unsigned char>( nullptr, nullptr ) {
}

//--------------
// Destructor --
//--------------
NANOStringReader::~NANOStringReader() {
}

//--------------
// Operations --
//--------------
DataHandler* NANOStringReader::getInstance( const std::string& name,
                                           const std::string& code ) {
  NANOStringReader* handler = new NANOStringReader( name, code, dataType );
  handler->dataReset = dataReset;
  return handler;
}

// static object

static const NANOStringReader tnr____c;
