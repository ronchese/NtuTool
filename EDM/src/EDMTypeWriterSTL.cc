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
#include "NtuTool/EDM/interface/EDMTypeWriter.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/EDM/interface/EDMStringWriter.h"
#include "NtuTool/EDM/interface/EDMTypeWriterManager.h"
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/TypeReset.h"
#include "NtuTool/Common/interface/DataResetString.h"
#include "NtuTool/Common/interface/DataResetVector.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>

//--------------
// Operations --
//--------------

// === template specialization for std::string === 

template <>
EDMTypeWriter<std::string>::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetString( DataReset::write );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter<std::string> tw____x;


// === template specialization for std::vector<int> === 

template <>
EDMTypeWriter< std::vector<int> >::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<int>( DataReset::read );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter< std::vector<int      > > tw_v__i;


// === template specialization for std::vector<unsigned int> === 

template <>
EDMTypeWriter< std::vector<unsigned int> >::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<unsigned int>( DataReset::read );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter< std::vector<unsigned
                                  int      > > tw_v_ui;


// === template specialization for std::vector<short> === 

template <>
EDMTypeWriter< std::vector<short> >::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<short>( DataReset::read );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter< std::vector<short    > > tw_v__s;


// === template specialization for std::vector<unsigned short> === 

template <>
EDMTypeWriter< std::vector<unsigned short> >::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<unsigned short>( DataReset::read );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter< std::vector<unsigned
                                  short    > > tw_v_us;


// === template specialization for std::vector<bool> === 

template <>
EDMTypeWriter< std::vector<bool> >::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<bool>( DataReset::read );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter< std::vector<bool     > > tw_v__a;


// === template specialization for std::vector<char> === 

template <>
EDMTypeWriter< std::vector<char> >::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<char>( DataReset::read );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter< std::vector<char     > > tw_v__b;


// === template specialization for std::vector<unsigned char> === 

template <>
EDMTypeWriter< std::vector<unsigned char> >::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<unsigned char>( DataReset::read );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter< std::vector<unsigned
                                  char     > > tw_v_ub;



// === template specialization for std::vector<long long> === 

template <>
EDMTypeWriter< std::vector<long long> >::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<long long>( DataReset::read );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter< std::vector<long long> > tw_v__l;


// === template specialization for std::vector<unsigned long long> === 

template <>
EDMTypeWriter< std::vector<unsigned long long> >::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<unsigned long long>( DataReset::read );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter< std::vector<unsigned
                                  long long> > tw_v_ul;


// === template specialization for std::vector<float> === 

template <>
EDMTypeWriter< std::vector<float> >::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<float>( DataReset::read );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter< std::vector<float    > > tw_v__f;


// === template specialization for std::vector<double> === 

template <>
EDMTypeWriter< std::vector<double> >::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<double>( DataReset::read );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter< std::vector<double   > > tw_v__d;


// === template specialization for std::vector<std::string> === 

template <>
EDMTypeWriter< std::vector<std::string> >::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<std::string>( DataReset::read );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter< std::vector<std::string> > tw_v__x;

