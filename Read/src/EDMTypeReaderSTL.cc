/*
 *  See header file for a description of this class.
 *
 *  $Date: 2010-12-09 11:49:02 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "NtuTool/Read/interface/EDMTypeReader.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Read/interface/EDMTypeReaderManager.h"
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/TypeReset.h"
#include "NtuTool/Common/interface/DataResetString.h"
#include "NtuTool/Common/interface/DataResetVector.h"

//---------------
// C++ Headers --
//---------------


//-------------------
// Initializations --
//-------------------


//--------------
// Operations --
//--------------

// === template specialization for std::string === 

template <>
EDMTypeReader<std::string>::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetString( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader<std::string> tr____x;


// === template specialization for std::vector<int> === 

template <>
EDMTypeReader< std::vector<int> >::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
  dataReset = new DataResetVector<int>( DataReset::read );
}
static EDMTypeReader< std::vector<int      > > tr_v__i;


// === template specialization for std::vector<unsigned int> === 

template <>
EDMTypeReader< std::vector<unsigned int> >::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<unsigned int>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader< std::vector<unsigned
                                  int      > > tr_v_ui;


// === template specialization for std::vector<short> === 

template <>
EDMTypeReader< std::vector<short> >::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<short>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader< std::vector<short    > > tr_v__s;


// === template specialization for std::vector<unsigned short> === 

template <>
EDMTypeReader< std::vector<unsigned short> >::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<unsigned short>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader< std::vector<unsigned
                                  short    > > tr_v_us;


// === template specialization for std::vector<char> === 

template <>
EDMTypeReader< std::vector<char> >::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<char>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader< std::vector<char     > > tr_v__b;


// === template specialization for std::vector<unsigned char> === 

template <>
EDMTypeReader< std::vector<unsigned char> >::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<unsigned char>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader< std::vector<unsigned
                                  char     > > tr_v_ub;


// === template specialization for std::vector<bool> === 

template <>
EDMTypeReader< std::vector<bool> >::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<bool>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader< std::vector<bool     > > tr_v__a;


// === template specialization for std::vector<long long> === 

template <>
EDMTypeReader< std::vector<long long> >::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<long long>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader< std::vector<long long> > tr_v__l;


// === template specialization for std::vector<unsigned long long> === 

template <>
EDMTypeReader< std::vector<unsigned long long> >::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<unsigned long long>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader< std::vector<unsigned
                                  long long> > tr_v_ul;


// === template specialization for std::vector<float> === 

template <>
EDMTypeReader< std::vector<float> >::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<float>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader< std::vector<float    > > tr_v__f;


// === template specialization for std::vector<double> === 

template <>
EDMTypeReader< std::vector<double> >::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<double>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader< std::vector<double   > > tr_v__d;


// === template specialization for std::vector<std::string> === 

template <>
EDMTypeReader< std::vector<std::string> >::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<std::string>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader< std::vector<std::string> > tr_v__x;


