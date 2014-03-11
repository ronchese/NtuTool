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

// === template specialization for int === 

template <>
EDMTypeWriter<int>::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<int>( DataReset::write );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter<int      > tw____i;


// === template specialization for unsigned int === 

template <>
EDMTypeWriter<unsigned int>::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<int>( DataReset::write );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter<unsigned
                     int      > tw___ui;


// === template specialization for short === 

template <>
EDMTypeWriter<short>::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<short>( DataReset::write );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter<short    > tw____s;


// === template specialization for unsigned short === 

template <>
EDMTypeWriter<unsigned short>::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<short>( DataReset::write );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter<unsigned
                     short    > tw___us;


// === template specialization for char === 

template <>
EDMTypeWriter<char>::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<char>( DataReset::write );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter<char     > tw____b;


// === template specialization for unsigned char  === 

template <>
EDMTypeWriter<unsigned char>::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<char>( DataReset::write );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter<unsigned
                     char     > tw___ub;


// === template specialization for long long === 

template <>
EDMTypeWriter<long long>::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<long long>( DataReset::write );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter<long long> tw____l;


// === template specialization for unsigned long long === 

template <>
EDMTypeWriter<unsigned long long>::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<long long>( DataReset::write );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter<unsigned
                     long long> tw___ul;


// === template specialization for float === 

template <>
EDMTypeWriter<float>::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<float>( DataReset::write );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter<float    > tw____f;


// === template specialization for double === 

template <>
EDMTypeWriter<double>::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<double>( DataReset::write );
  EDMTypeWriterManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeWriter<double   > tw____d;

