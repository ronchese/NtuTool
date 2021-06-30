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
#include "NtuTool/EDM/interface/NANOTypeWriter.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/EDM/interface/NANOTypeWriterManager.h"
#include "NtuTool/EDM/interface/NANOTableWrapper.h"
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
int    NANOTypeWriter<std::string>::cSize( const void* p ) {
  return this->cPtr( p )->size();
}
template <>
void   NANOTypeWriter<std::string>::addC( const void* p, void* t,
       const std::string& name, const std::string& doc ) {
  NANOTableHandler::addC<const char*, unsigned char>(
                    cPtr( p )->c_str(), cSize( p ), t, name, doc,
                    NANOTableWrapper::UInt8 );
  return;
}
static NANOTypeWriter<std::string> tw____x(
       new DataResetString( DataReset::native_write ) );


// === template specialization for std::vector<int> ===

template <>
int    NANOTypeWriter  < std::vector<int      > >::cSize( const void* p ) {
  return this->cPtr( p )->size();
}
template <>
void   NANOTypeWriter  < std::vector<int      > >::addC( const void* p, void* t,
       const std::string& name, const std::string& doc ) {
  NANOTableWrapper::addColumn       <int      >( tPtr( t ),
                    name, *cPtr( p ), doc,
                    NANOTableWrapper::Int, -1 );
  return;
}
static NANOTypeWriter  < std::vector<int      > > tw_v__i(
                 new DataResetVector<int      >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned int> ===

template <>
int    NANOTypeWriter  < std::vector<unsigned
                                     int      > >::cSize( const void* p ) {
  return this->cPtr( p )->size();
}
template <>
void   NANOTypeWriter  < std::vector<unsigned
                                     int      > >::addC( const void* p, void* t,
       const std::string& name, const std::string& doc ) {
  NANOTableHandler::addC<std::vector<unsigned
                                     int      >, int>(
                    *cPtr( p ), cSize( p ), t, name, doc,
                    NANOTableWrapper::Int );
  return;
}
static NANOTypeWriter  < std::vector<unsigned
                                     int      > > tw_v_ui(
                 new DataResetVector<unsigned
                                     int      >( DataReset::stl_read ) );


// === template specialization for std::vector<short> ===

template <>
int    NANOTypeWriter  < std::vector<short    > >::cSize( const void* p ) {
  return this->cPtr( p )->size();
}
template <>
void   NANOTypeWriter  < std::vector<short    > >::addC( const void* p, void* t,
       const std::string& name, const std::string& doc ) {
  NANOTableHandler::addC<std::vector<short    >, int>(
                    *cPtr( p ), cSize( p ), t, name, doc,
                    NANOTableWrapper::Int );
  return;
}
static NANOTypeWriter  < std::vector<short    > > tw_v__s(
                 new DataResetVector<short    >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned short> ===

template <>
int    NANOTypeWriter  < std::vector<unsigned
                                     short    > >::cSize( const void* p ) {
  return this->cPtr( p )->size();
}
template <>
void   NANOTypeWriter  < std::vector<unsigned
                                     short    > >::addC( const void* p, void* t,
       const std::string& name, const std::string& doc ) {
  NANOTableHandler::addC<std::vector<unsigned
                                     short    >, int>(
                    *cPtr( p ), cSize( p ), t, name, doc,
                    NANOTableWrapper::Int );
  return;
}
static NANOTypeWriter  < std::vector<unsigned
                                     short    > > tw_v_us(
                 new DataResetVector<unsigned
                                     short    >( DataReset::stl_read ) );


// === template specialization for std::vector<bool> ===

template <>
int    NANOTypeWriter  < std::vector<bool     > >::cSize( const void* p ) {
  return this->cPtr( p )->size();
}
template <>
void   NANOTypeWriter  < std::vector<bool     > >::addC( const void* p, void* t,
       const std::string& name, const std::string& doc ) {
  NANOTableWrapper::addColumn       <bool     >( tPtr( t ),
                    name, *cPtr( p ), doc,
                    NANOTableWrapper::Bool, -1 );
  return;
}
static NANOTypeWriter  < std::vector<bool     > > tw_v__a(
                 new DataResetVector<bool     >( DataReset::stl_read ) );


// === template specialization for std::vector<char> ===

template <>
int    NANOTypeWriter  < std::vector<char     > >::cSize( const void* p ) {
  return this->cPtr( p )->size();
}
template <>
void   NANOTypeWriter  < std::vector<char     > >::addC( const void* p, void* t,
       const std::string& name, const std::string& doc ) {
  NANOTableHandler::addC<std::vector<char     >, unsigned char>(
                    *cPtr( p ), cSize( p ), t, name, doc,
                    NANOTableWrapper::UInt8 );
  return;
}
static NANOTypeWriter  < std::vector<char     > > tw_v__b(
                 new DataResetVector<char     >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned char> ===

template <>
int    NANOTypeWriter  < std::vector<unsigned
                                     char     > >::cSize( const void* p ) {
  return this->cPtr( p )->size();
}
template <>
void   NANOTypeWriter  < std::vector<unsigned
                                     char     > >::addC( const void* p, void* t,
       const std::string& name, const std::string& doc ) {
  NANOTableWrapper::addColumn       <unsigned
                                     char     >( tPtr( t ),
                    name, *cPtr( p ), doc,
                    NANOTableWrapper::UInt8, -1 );
  return;
}
static NANOTypeWriter  < std::vector<unsigned
                                     char     > > tw_v_ub(
                 new DataResetVector<unsigned
                                     char     >( DataReset::stl_read ) );



// === template specialization for std::vector<long long> ===

template <>
int    NANOTypeWriter  < std::vector<long long> >::cSize( const void* p ) {
  return this->cPtr( p )->size();
}
template <>
void   NANOTypeWriter  < std::vector<long long> >::addC( const void* p, void* t,
       const std::string& name, const std::string& doc ) {
  NANOTableHandler::addC<std::vector<long long>, int>(
                    *cPtr( p ), cSize( p ), t, name, doc,
                    NANOTableWrapper::Int );
  return;
}
static NANOTypeWriter  < std::vector<long long> > tw_v__l(
                 new DataResetVector<long long>( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned long long> ===

template <>
int    NANOTypeWriter  < std::vector<unsigned
                                     long long> >::cSize( const void* p ) {
  return this->cPtr( p )->size();
}
template <>
void   NANOTypeWriter  < std::vector<unsigned
                                     long long> >::addC( const void* p, void* t,
       const std::string& name, const std::string& doc ) {
  NANOTableHandler::addC<std::vector<unsigned
                                     long long>, int>(
                    *cPtr( p ), cSize( p ), t, name, doc,
                    NANOTableWrapper::Int );
  return;
}
static NANOTypeWriter  < std::vector<unsigned
                                     long long> > tw_v_ul(
                 new DataResetVector<unsigned
                                     long long>( DataReset::stl_read ) );


// === template specialization for std::vector<float> ===

template <>
int    NANOTypeWriter  < std::vector<float    > >::cSize( const void* p ) {
  return this->cPtr( p )->size();
}
template <>
void   NANOTypeWriter  < std::vector<float    > >::addC( const void* p, void* t,
       const std::string& name, const std::string& doc ) {
  NANOTableWrapper::addColumn       <float    >( tPtr( t ),
                    name, *cPtr( p ), doc,
                    NANOTableWrapper::Float, -1 );
  return;
}
static NANOTypeWriter  < std::vector<float    > > tw_v__f(
                 new DataResetVector<float    >( DataReset::stl_read ) );


// === template specialization for std::vector<double> ===

template <>
int    NANOTypeWriter  < std::vector<double   > >::cSize( const void* p ) {
  return this->cPtr( p )->size();
}
template <>
void   NANOTypeWriter  < std::vector<double   > >::addC( const void* p, void* t,
       const std::string& name, const std::string& doc ) {
  NANOTableHandler::addC<std::vector<double   >, float>(
                    *cPtr( p ), cSize( p ), t, name, doc,
                    NANOTableWrapper::Float );
  return;
}
static NANOTypeWriter  < std::vector<double   > > tw_v__d(
                 new DataResetVector<double   >( DataReset::stl_read ) );


// === template specialization for std::vector<std::string> ===

template <>
int    NANOTypeWriter< std::vector<std::string> >::cSize( const void* p ) {
  return this->cPtr( p )->size();
}
template <>
void   NANOTypeWriter< std::vector<std::string> >::addC( const void* p, void* t,
       const std::string& name, const std::string& doc ) {
}
static NANOTypeWriter< std::vector<std::string> > tw_v__x(
               new DataResetVector<std::string>( DataReset::stl_read ) );

