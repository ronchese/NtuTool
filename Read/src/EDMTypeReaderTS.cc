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

// === template specialization for int === 

template <>
EDMTypeReader<int>::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<int>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader<int      > tr____i;


// === template specialization for unsigned int === 

template <>
EDMTypeReader<unsigned int>::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<unsigned int>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader<unsigned
                     int      > tr___ui;


// === template specialization for short === 

template <>
EDMTypeReader<short>::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<short>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader<short    > tr____s;


// === template specialization for unsigned short === 

template <>
EDMTypeReader<unsigned short>::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<unsigned short>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader<unsigned
                     short    > tr___us;


// === template specialization for char === 

template <>
EDMTypeReader<char>::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<char>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader<char     > tr____b;


// === template specialization for unsigned char  === 

template <>
EDMTypeReader<unsigned char>::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<unsigned char>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader<unsigned
                     char     > tr___ub;


// === template specialization for bool  === 

template <>
EDMTypeReader<bool>::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<bool>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader<bool     > tr____a;


// === template specialization for long long === 

template <>
EDMTypeReader<long long>::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<long long>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader<long long> tr____l;


// === template specialization for unsigned long long === 

template <>
EDMTypeReader<unsigned long long>::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<unsigned long long>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader<unsigned
                     long long> tr___ul;


// === template specialization for float === 

template <>
EDMTypeReader<float>::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<int>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader<float    > tr____f;


// === template specialization for double === 

template <>
EDMTypeReader<double>::EDMTypeReader() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<long long>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader<double   > tr____d;

