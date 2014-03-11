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
#include "NtuTool/Common/interface/TreeTypeWriter.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/TreeTypeManager.h"
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
TreeTypeWriter<int>::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<int>( DataReset::write );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter<int      > tw____i;


// === template specialization for unsigned int === 

template <>
TreeTypeWriter<unsigned int>::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<unsigned int>( DataReset::write );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter<unsigned
                      int      > tw___ui;


// === template specialization for short === 

template <>
TreeTypeWriter<short>::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<short>( DataReset::write );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter<short    > tw____s;


// === template specialization for unsigned short === 

template <>
TreeTypeWriter<unsigned short>::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<unsigned short>( DataReset::write );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter<unsigned
                      short    > tw___us;


// === template specialization for char & C/C++ string === 

template <>
TreeTypeWriter<char>::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<char>( DataReset::write );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
  C__String* p = 0;
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( p ),
                                    this );
}
static TreeTypeWriter<char     > tw____b;


// === template specialization for unsigned char  === 

template <>
TreeTypeWriter<unsigned char>::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<unsigned char>( DataReset::write );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter<unsigned
                     char     > tw___ub;


// === template specialization for bool === 

template <>
TreeTypeWriter<bool>::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<bool>( DataReset::write );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter<bool> tw____a;


// === template specialization for long long === 

template <>
TreeTypeWriter<long long>::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<long long>( DataReset::write );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter<long long> tw____l;


// === template specialization for unsigned long long === 

template <>
TreeTypeWriter<unsigned long long>::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<unsigned long long>( DataReset::write );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter<unsigned
                     long long> tw___ul;


// === template specialization for float === 

template <>
TreeTypeWriter<float>::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<float>( DataReset::write );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter<float    > tw____f;


// === template specialization for double === 

template <>
TreeTypeWriter<double>::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new TypeReset<double>( DataReset::write );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter<double   > tw____d;

