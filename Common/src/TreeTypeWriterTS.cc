#include <iostream>
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/TreeTypeWriter.h"
#include "NtuTool/Common/interface/TreeTypeManager.h"
#include "NtuTool/Common/interface/TypeReset.h"
#include "NtuTool/Common/interface/DataResetString.h"
#include "NtuTool/Common/interface/DataResetVector.h"


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


// === template specialization for std::string === 

template <>
TreeTypeWriter<std::string>::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetString( DataReset::write );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter<std::string> tw____x;


// === template specializations for std::vector<...> ===


// === template specialization for std::vector<int> === 

template <>
TreeTypeWriter< std::vector<int> >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<int>( DataReset::read );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static TreeTypeWriter< std::vector<int      > > tw_v__i;


// === template specialization for std::vector<unsigned int> === 

template <>
TreeTypeWriter< std::vector<unsigned int> >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<unsigned int>( DataReset::read );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector<unsigned
                                   int      > > tw_v_ui;


// === template specialization for std::vector<short> === 

template <>
TreeTypeWriter< std::vector<short> >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<short>( DataReset::read );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector<short    > > tw_v__s;


// === template specialization for std::vector<unsigned short> === 

template <>
TreeTypeWriter< std::vector<unsigned short> >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<unsigned short>( DataReset::read );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector<unsigned
                                   short    > > tw_v_us;


// === template specialization for std::vector<char> === 

template <>
TreeTypeWriter< std::vector<char> >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<char>( DataReset::read );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector<char     > > tw_v__b;


// === template specialization for std::vector<bool> === 

template <>
TreeTypeWriter< std::vector<bool> >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<bool>( DataReset::read );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector<bool     > > tw_v__a;


// === template specialization for std::vector<unsigned char> === 

template <>
TreeTypeWriter< std::vector<unsigned char> >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<unsigned char>( DataReset::read );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector<unsigned
                                   char     > > tw_v_ub;



// === template specialization for std::vector<long long> === 

template <>
TreeTypeWriter< std::vector<long long> >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<long long>( DataReset::read );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector<long long> > tw_v__l;


// === template specialization for std::vector<unsigned long long> === 

template <>
TreeTypeWriter< std::vector<unsigned long long> >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<unsigned long long>( DataReset::read );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector<unsigned
                                   long long> > tw_v_ul;


// === template specialization for std::vector<float> === 

template <>
TreeTypeWriter< std::vector<float> >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<float>( DataReset::read );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector<float    > > tw_v__f;


// === template specialization for std::vector<double> === 

template <>
TreeTypeWriter< std::vector<double> >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<double>( DataReset::read );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector<double   > > tw_v__d;



// === template specialization for std::vector<std::string> === 

template <>
TreeTypeWriter< std::vector<std::string> >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<std::string>( DataReset::read );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector<std::string> > tw_v__x;


// === template specializations for std::vector< std::vector<...> > ===


// === template specialization for std::vector< std::vector<int> > === 

template <>
TreeTypeWriter< std::vector< std::vector<int> > >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = 0;
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}
static TreeTypeWriter< std::vector< std::vector<int       > > > tw_w__i;


// === template specialization for std::vector< std::vector<unsigned
//                                                          int> > === 

template <>
TreeTypeWriter< std::vector< std::vector<unsigned
                                         int> > >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = 0;
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector< std::vector< unsigned
                                                 int      > > > tw_w_ui;


// === template specialization for std::vector< std::vector<short> > === 

template <>
TreeTypeWriter< std::vector< std::vector<short> > >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = 0;
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector< std::vector<short     > > > tw_w__s;


// === template specialization for std::vector< std::vector<unsigned
//                                                          short> === 

template <>
TreeTypeWriter< std::vector< std::vector<unsigned
                                         short> > >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = 0;
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector< std::vector<unsigned
                                                short     > > > tw_w_us;


// === template specialization for std::vector< std::vector<char> > > === 

template <>
TreeTypeWriter< std::vector< std::vector<char> > >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = 0;
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector< std::vector<char      > > > tw_w__b;


// === template specialization for std::vector< std::vector<unsigned
//                                                          char> === 

template <>
TreeTypeWriter< std::vector< std::vector<unsigned
                                         char> > >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = 0;
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector< std::vector<unsigned
                                                char      > > > tw_w_ub;



// === template specialization for std::vector< std::vector<bool> > === 

template <>
TreeTypeWriter< std::vector< std::vector<bool> > >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = 0;
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector< std::vector<bool      > > > tw_w__a;


// === template specialization for std::vector< std::vector<long long> > === 

template <>
TreeTypeWriter< std::vector< std::vector<long long> > >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = 0;
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector< std::vector<long long > > > tw_w__l;


// === template specialization for std::vector< std::vector<unsigned
//                                                          long long> === 

template <>
TreeTypeWriter< std::vector< std::vector<unsigned
                                         long long> > >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = 0;
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector< std::vector<unsigned
                                                long long > > > tw_w_ul;


// === template specialization for std::vector< std::vector<float> > === 

template <>
TreeTypeWriter< std::vector< std::vector<float> > >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = 0;
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector< std::vector<float     > > > tw_w__f;


// === template specialization for std::vector< std::vector<double> > === 

template <>
TreeTypeWriter< std::vector< std::vector<double> > >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = 0;
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector< std::vector<double    > > > tw_w__d;



