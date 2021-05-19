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


//-------------------
// Initializations --
//-------------------


//--------------
// Operations --
//--------------

// === template specialization for int === 

//template <>
template <>
int          NANOTypeReader<int      >::cSize( const void* p ) {
  return ( convType == copyVector ? 1 : -1 );
}
template <>
void*        NANOTypeReader<int      >::tmpArray( int n ) { return nullptr; }
static const NANOTypeReader<int      > tnr____i( DataReset::native_write,
       nullptr );


// === template specialization for unsigned int === 

template <>
int          NANOTypeReader<unsigned
                      int      >::cSize( const void* p ) {
  return ( convType == copyVector ? 1 : -1 );
}
template <>
void*        NANOTypeReader<unsigned
		      int      >::tmpArray( int n ) { return new int[n]; }
static const NANOTypeReader<unsigned
		      int      > tnr___ui( DataReset::native_write,
       new NANOHandler::ConvertToArray<int,unsigned int> );


// === template specialization for short === 

template <>
int          NANOTypeReader<short    >::cSize( const void* p ) {
  return ( convType == copyVector ? 1 : -1 );
}
template <>
void*        NANOTypeReader<short    >::tmpArray( int n ) { return new int[n]; }
static const NANOTypeReader<short    > tnr____s( DataReset::native_write,
       new NANOHandler::ConvertToArray<int,short> );


// === template specialization for unsigned short === 

template <>
int          NANOTypeReader<unsigned
                            short    >::cSize( const void* p ) {
  return ( convType == copyVector ? 1 : -1 );
}
template <>
void*        NANOTypeReader<unsigned
                            short>::tmpArray( int n ) { return new int[n]; }
static const NANOTypeReader<unsigned
                            short    > tnr___us( DataReset::native_write,
             new NANOHandler::ConvertToArray<int,unsigned short> );


// === template specialization for char === 

template <>
int          NANOTypeReader<char     >::cSize( const void* p ) {
  return ( convType == copyVector ? 1 : -1 );
}
template <>
void*        NANOTypeReader<char     >::tmpArray( int n ) { return new char[n]; }
static const NANOTypeReader<char     > tnr____b( DataReset::native_write,
       new NANOHandler::ConvertToArray<unsigned char,char> );


// === template specialization for unsigned char  === 

template <>
int          NANOTypeReader<unsigned
                            char>::cSize( const void* p ) {
  return ( convType == copyVector ? 1 : -1 );
}
template <>
void*        NANOTypeReader<unsigned
                            char>::tmpArray( int n ) { return nullptr; }
static const NANOTypeReader<unsigned
                            char     > tnr___ub( DataReset::native_write,
       nullptr );


// === template specialization for bool  === 

template <>
int          NANOTypeReader<bool     >::cSize( const void* p ) {
  return ( convType == copyVector ? 1 : -1 );
}
template <>
void*        NANOTypeReader<bool     >::tmpArray( int n ) { return new bool[n]; }
static const NANOTypeReader<bool     > tnr____a( DataReset::native_write,
       nullptr );


// === template specialization for long long === 

template <>
int          NANOTypeReader<long long>::cSize( const void* p ) {
  return ( convType == copyVector ? 1 : -1 );
}
template <>
void*        NANOTypeReader<long long>::tmpArray( int n ) { return new int[n]; }
static const NANOTypeReader<long long> tnr____l( DataReset::native_write,
             new NANOHandler::ConvertToArray<int,long long> );


// === template specialization for unsigned long long === 

template <>
int          NANOTypeReader<unsigned
                            long long>::cSize( const void* p ) {
  return ( convType == copyVector ? 1 : -1 );
}
template <>
void*        NANOTypeReader<unsigned
                            long long>::tmpArray( int n ) { return new int[n]; }
static const NANOTypeReader<unsigned
                            long long> tnr___ul( DataReset::native_write,
             new NANOHandler::ConvertToArray<int,unsigned long long> );


// === template specialization for float === 

template <>
int          NANOTypeReader<float    >::cSize( const void* p ) {
  return ( convType == copyVector ? 1 : -1 );
}
template <>
void*        NANOTypeReader<float    >::tmpArray( int n ) { return nullptr; }
static const NANOTypeReader<float    > tnr____f( DataReset::native_write,
       nullptr );


// === template specialization for double === 

template <>
int          NANOTypeReader<double   >::cSize( const void* p ) {
  return ( convType == copyVector ? 1 : -1 );
}
template <>
void*        NANOTypeReader<double   >::tmpArray( int n ) { return new float[n]; }
static const NANOTypeReader<double   > tnr____d( DataReset::native_write,
             new NANOHandler::ConvertToArray<float,double> );

