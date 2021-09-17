/*
 *  See header file for a description of this class.
 *
 *  $Date: 2020-07-23 11:49:02 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "NtuTool/Read/interface/NANOTypeReader.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Read/interface/NANOTypeReaderManager.h"
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/TypeReset.h"
#include "NtuTool/Common/interface/DataResetString.h"
#include "NtuTool/Common/interface/DataResetVector.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>

//-------------------
// Initializations --
//-------------------


//--------------
// Operations --
//--------------

// === template specialization for std::string === 

template <>
int          NANOTypeReader<std::string>::cSize( const void* p ) {
  return 1;
}
template <>
void*        NANOTypeReader<std::string>::tmpArray( int n ) {
  return new unsigned char[n];
}
static const NANOTypeReader<std::string> tnr____x(
              new DataResetString( DataReset::stl_read ),
              new NANOHandler::ConvertToString );


// === template specialization for std::vector<int> === 

template <>
int          NANOTypeReader< std::vector<int      > >::cSize( const void* p ) {
  return 1;
}
template <>
void*        NANOTypeReader< std::vector<int      > >::tmpArray( int n ) {
  return new int[n];
}
static const NANOTypeReader< std::vector<int      > > tnr_v__i(
                     new DataResetVector<int      >( DataReset::stl_read ),
                     new NANOHandler::ConvertToVector<int,int> );


// === template specialization for std::vector<unsigned int> === 

template <>
int          NANOTypeReader< std::vector<unsigned
                                         int      > >::cSize( const void* p ) {
  return 1;
}
template <>
void*        NANOTypeReader< std::vector<unsigned
                                         int      > >::tmpArray( int n ) {
  return new int[n];
}
static const NANOTypeReader< std::vector<unsigned
                                         int      > > tnr_v_ui(
                     new DataResetVector<unsigned
                                         int      >( DataReset::stl_read ),
                     new NANOHandler::ConvertToVector<int,unsigned int> );


// === template specialization for std::vector<short> === 

template <>
int          NANOTypeReader< std::vector<short    > >::cSize( const void* p ) {
  return 1;
}
template <>
void*        NANOTypeReader< std::vector<short    > >::tmpArray( int n ) {
  return new int[n];
}
static const NANOTypeReader< std::vector<short    > > tnr_v__s(
                     new DataResetVector<short    >( DataReset::stl_read ),
                     new NANOHandler::ConvertToVector<int,short> );


// === template specialization for std::vector<unsigned short> === 

template <>
int          NANOTypeReader< std::vector<unsigned
                                         short    > >::cSize( const void* p ) {
  return 1;
}
template <>
void*        NANOTypeReader< std::vector<unsigned
                                         short    > >::tmpArray( int n ) {
  return new int[n];
}
static const NANOTypeReader< std::vector<unsigned
                                         short    > > tnr_v_us(
                     new DataResetVector<unsigned
                                         short    >( DataReset::stl_read ),
                     new NANOHandler::ConvertToVector<int,unsigned short> );


// === template specialization for std::vector<char> === 

template <>
int          NANOTypeReader< std::vector<char     > >::cSize( const void* p ) {
  return 1;
}
template <>
void*        NANOTypeReader< std::vector<char     > >::tmpArray( int n ) {
  return new unsigned char[n];
}
static const NANOTypeReader< std::vector<char     > > tnr_v__b(
                     new DataResetVector<char     >( DataReset::stl_read ),
                     new NANOHandler::ConvertToVector<unsigned char,char> );


// === template specialization for std::vector<unsigned char> === 

template <>
int          NANOTypeReader<  std::vector<unsigned
                                          char    > >::cSize( const void* p ) {
  return 1;
}
template <>
void*        NANOTypeReader< std::vector<unsigned
                                         char     > >::tmpArray( int n ) {
  return new unsigned char[n];
}
static const NANOTypeReader< std::vector<unsigned
                                         char     > > tnr_v_ub(
                     new DataResetVector<unsigned
                                         char     >( DataReset::stl_read ),
                     new NANOHandler::ConvertToVector<unsigned char,unsigned char> );


// === template specialization for std::vector<bool> === 

template <>
int         NANOTypeReader<  std::vector<bool     > >::cSize( const void* p ) {
  return 1;
}
template <>
void*        NANOTypeReader< std::vector<bool     > >::tmpArray( int n ) {
  return new bool[n];
}
static const NANOTypeReader< std::vector<bool     > > tnr_v__a(
                     new DataResetVector<bool     >( DataReset::stl_read ),
                     new NANOHandler::ConvertToVector<bool,bool> );


// === template specialization for std::vector<long long> === 

template <>
int          NANOTypeReader< std::vector<long long> >::cSize( const void* p ) {
  return 1;
}
template <>
void*        NANOTypeReader< std::vector<long long> >::tmpArray( int n ) {
  return new int[n];
}
static const NANOTypeReader< std::vector<long long> > tnr_v__l(
                     new DataResetVector<long long>( DataReset::stl_read ),
                     new NANOHandler::ConvertToVector<int,long long> );


// === template specialization for std::vector<unsigned long long> === 

template <>
int          NANOTypeReader< std::vector<unsigned
                                         long long> >::cSize( const void* p ) {
  return 1;
}
template <>
void*        NANOTypeReader< std::vector<unsigned
                                         long long> >::tmpArray( int n ) {
  return new int[n];
}
static const NANOTypeReader< std::vector<unsigned
                                         long long> > tnr_v_ul(
                     new DataResetVector<unsigned
                                         long long>( DataReset::stl_read ),
                     new NANOHandler::ConvertToVector<int,unsigned long long> );


// === template specialization for std::vector<float> === 

template <>
int          NANOTypeReader< std::vector<float    > >::cSize( const void* p ) {
  return 1;
}
template <>
void*        NANOTypeReader< std::vector<float    > >::tmpArray( int n ) {
  return new float[n];
}
static const NANOTypeReader< std::vector<float    > > tnr_v__f(
                     new DataResetVector<float    >( DataReset::stl_read ),
                     new NANOHandler::ConvertToVector<float,float> );


// === template specialization for std::vector<double> === 

template <>
int          NANOTypeReader< std::vector<double   > >::cSize( const void* p ) {
  return 1;
}
template <>
void*        NANOTypeReader< std::vector<double   > >::tmpArray( int n ) {
  return new float[n];
}
static const NANOTypeReader< std::vector<double   > > tnr_v__d(
                     new DataResetVector<double   >( DataReset::stl_read ),
                     new NANOHandler::ConvertToVector<float,double> );

/*
// === template specialization for std::vector<std::string> === 

template <>
int          NANOTypeReader< std::vector<std::string> >::cSize( const void* p ) {
  return 1;
}
template <>
void*        NANOTypeReader< std::vector<std::string> >::tmpArray( int n ) {
  return nullptr;
}
static const NANOTypeReader< std::vector<std::string> > tnr_v__x(
                     new DataResetVector<std::string>( DataReset::stl_read ),
                     nullptr );
*/

