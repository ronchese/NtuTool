#include "NtuTool/Read/interface/EDMTypeReader.h"
#include "NtuTool/Read/interface/EDMTypeReaderManager.h"
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/TypeReset.h"
#include "NtuTool/Common/interface/DataResetString.h"
#include "NtuTool/Common/interface/DataResetVector.h"

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
  dataReset = new TypeReset<int>( DataReset::read );
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
  dataReset = new TypeReset<short>( DataReset::read );
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
  dataReset = new TypeReset<char>( DataReset::read );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static EDMTypeReader<unsigned
                     char     > tr___ub;


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
  dataReset = new TypeReset<long long>( DataReset::read );
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


