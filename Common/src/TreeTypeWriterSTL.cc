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


// === template specialization for std::vector<bool> === 

template <>
TreeTypeWriter< std::vector<bool> >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<bool>( DataReset::read );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector<bool     > > tw_v__a;


// === template specialization for std::vector<char> === 

template <>
TreeTypeWriter< std::vector<char> >::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  dataReset = new DataResetVector<char>( DataReset::read );
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                    this );
}
static TreeTypeWriter< std::vector<char     > > tw_v__b;


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



