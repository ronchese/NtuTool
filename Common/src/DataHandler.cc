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
#include <iostream>
#include <sstream>

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
 auxPtr( 0 ),
 dataReset( 0 ) {
}


DataHandler::DataHandler( const std::string& name,
                          const std::string& code,
                          const std::string& type ):
 dataName( name ),
 dataCode( code ),
 dataType( type ),
 dataSize( ""   ),
 convType( null ),
 auxPtr( 0 ),
 dataReset( 0 ) {
  int bds = dataName.find( "[" );
  if ( bds < 0 ) return;
  convType = copyVector;
  int eds = dataName.find( "]" );
  dataSize = dataName.substr( bds + 1, eds - bds - 1 );
  dataName = dataName.substr( 0, bds );
}


DataHandler::DataHandler( bool dum ) {
}

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
  return 0;
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
  return 0;
}


void DataHandler::produces( edm::EDProducer* p ) {
  return;
}


void DataHandler::put( edm::Event& e, const void* p ) {
  return;
}


std::string DataHandler::getBranchName( const std::string& processName,
                                        const std::string& producerName ) {
  std::string
  name( dataType );
  if ( convType == copyVector ) name += "s";
  name += "_";
  name += producerName;
  name += "_";
  name += dataName;
  name += "_";
  name += processName;
  name += ".obj";
  return name;
}


void DataHandler::process( void* p ) {
  return;
}


void DataHandler::reset( void* p ) {
  if ( dataReset == 0 ) return;
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


void* DataHandler::setAuxPtr( void* p, DataHandlerManager* hm ) {
  return auxPtr = p;
}


void DataHandler::setMemberPtr( TTree* tree,
                                const std::string& branchName,
                                void* dataPtr ) {
  return;
}

