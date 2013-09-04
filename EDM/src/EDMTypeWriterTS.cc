#include <iostream>
#include "NtuTool/EDM/interface/EDMTypeWriter.h"
#include "NtuTool/EDM/interface/EDMStringWriter.h"
#include "NtuTool/EDM/interface/EDMTypeWriterManager.h"
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/TypeReset.h"
#include "NtuTool/Common/interface/DataResetString.h"
#include "NtuTool/Common/interface/DataResetVector.h"


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

