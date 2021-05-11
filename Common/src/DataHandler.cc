/*
 *  See header file for a description of this class.
 *
 *  $Date: 2011/03/01 18:08:37 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "NtuTool/Common/interface/DataHandler.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Common/interface/DataHandlerManager.h"
#include "NtuTool/Common/interface/DataReset.h"
#include "NtuTool/Common/interface/DataConvert.h"

//---------------
// C++ Headers --
//---------------


//-------------------
// Initializations --
//-------------------


//----------------
// Constructors --
//----------------
DataHandler::DataHandler():
 dataName( "" ),
 dataCode( "" ),
 dataType( "" ),
 dataSize( "" ),
 convType( null ),
 auxPtr( nullptr ),
 addInfo( nullptr ),
 dataReset( nullptr ) {
}


DataHandler::DataHandler( const std::string& name,
                          const std::string& code,
                          const std::string& type ):
 dataName( name ),
 dataCode( code ),
 dataType( type ),
 dataSize( ""   ),
 convType( null ),
 auxPtr( nullptr ),
 addInfo( nullptr ),
 dataReset( nullptr ) {
  int bds = dataName.find( "[" );
  if ( bds < 0 ) return;
  convType = copyVector;
  int eds = dataName.find( "]" );
  dataSize = dataName.substr( bds + 1, eds - bds - 1 );
  dataName = dataName.substr( 0, bds );
}


//DataHandler::DataHandler( bool dum ) {
//}

//--------------
// Destructor --
//--------------
DataHandler::~DataHandler() {
}

//--------------
// Operations --
//--------------
DataHandler* DataHandler::getInstance( const std::string& name,
                                       const std::string& code ) {
  return nullptr;
}


const std::string& DataHandler::getName() {
  return dataName;
}


const std::string& DataHandler::getCode() {
  return dataCode;
}


const std::string& DataHandler::getType() {
  return dataType;
}


const std::string& DataHandler::getSize() {
  return dataSize;
}


DataHandler::conversionType DataHandler::getConv() {
  return convType;
}


TBranch* DataHandler::branch( TTree* tree, const std::string* name, void** p,
                              int bufferSize, int splitLevel ) {
  return nullptr;
}


void DataHandler::process( void* p ) {
  return;
}


void DataHandler::reset( void* p ) {
  if ( dataReset == nullptr ) return;
  if ( convType != copyVector ) dataReset->clearDatum( p, auxPtr );
  else                          dataReset->clearArray( p, auxPtr );
  return;
}


void DataHandler::buildPtr( void* p ) {
  return;
}


void DataHandler::clearPtr( void* p ) {
  return;
}


void* DataHandler::auxiliaryPtr() {
  return auxPtr;
}


void* DataHandler::additionalInfo() {
  return addInfo;
}


void* DataHandler::setAuxPtr( void* p, DataHandlerManager* hm ) {
  return auxPtr = p;
}


void* DataHandler::setAddInfo( void* p ) {
  return addInfo = p;
}


void DataHandler::setMemberPtr( TTree* tree,
                                const std::string& branchName,
                                void* dataPtr ) {
  return;
}

