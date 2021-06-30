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
#include "NtuTool/Common/interface/DataConvert.h"
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
int    NANOTypeWriter<int      >::cSize( const void* p ) {
  return ( convType == copyVector ? *iPtr( auxPtr ) : -1 );
}
template <>
void   NANOTypeWriter<int      >::addC( const void* p, void* t,
                                        const std::string& name,
                                        const std::string& doc ) {
  this->addC<int>( p, t, name, doc, NANOTableWrapper::Int );
  return;
}
static NANOTypeWriter<int      > tw____i( DataReset::native_write );


// === template specialization for unsigned int ===

template <>
int    NANOTypeWriter<unsigned
                      int      >::cSize( const void* p ) {
  return ( convType == copyVector ? *iPtr( auxPtr ) : -1 );
}
template <>
void   NANOTypeWriter<unsigned
                      int      >::addC( const void* p, void* t,
                                        const std::string& name,
                                        const std::string& doc ) {
  this->addC<int>( p, t, name, doc, NANOTableWrapper::Int );
  return;
}
static NANOTypeWriter<unsigned
                      int      > tw___ui( DataReset::native_write );


// === template specialization for short ===

template <>
int    NANOTypeWriter<short    >::cSize( const void* p ) {
  return ( convType == copyVector ? *iPtr( auxPtr ) : -1 );
}
template <>
void   NANOTypeWriter<short    >::addC( const void* p, void* t,
                                        const std::string& name,
                                        const std::string& doc ) {
  this->addC<int>( p, t, name, doc, NANOTableWrapper::Int );
  return;
}
static NANOTypeWriter<short    > tw____s( DataReset::native_write );


// === template specialization for unsigned short ===

template <>
int    NANOTypeWriter<unsigned
                      short    >::cSize( const void* p ) {
  return ( convType == copyVector ? *iPtr( auxPtr ) : -1 );
}
template <>
void   NANOTypeWriter<unsigned
                      short    >::addC( const void* p, void* t,
                                        const std::string& name,
                                        const std::string& doc ) {
  this->addC<int>( p, t, name, doc, NANOTableWrapper::Int );
  return;
}
static NANOTypeWriter<unsigned
                      short    > tw___us( DataReset::native_write );


// === template specialization for char ===

template <>
int    NANOTypeWriter<char     >::cSize( const void* p ) {
  return ( convType == copyVector ? *iPtr( auxPtr ) : -1 );
}
template <>
void   NANOTypeWriter<char     >::addC( const void* p, void* t,
                                        const std::string& name,
                                        const std::string& doc ) {
  this->addC<unsigned char>( p, t, name, doc, NANOTableWrapper::UInt8 );
  return;
}
static NANOTypeWriter<char     > tw____b( DataReset::native_write );


// === template specialization for unsigned char ===

template <>
int    NANOTypeWriter<unsigned
                      char     >::cSize( const void* p ) {
  return ( convType == copyVector ? *iPtr( auxPtr ) : -1 );
}
template <>
void   NANOTypeWriter<unsigned
                      char     >::addC( const void* p, void* t,
                                        const std::string& name,
                                        const std::string& doc ) {
  this->addC<unsigned char>( p, t, name, doc, NANOTableWrapper::UInt8 );
  return;
}
static NANOTypeWriter<unsigned
                      char     > tw___ub( DataReset::native_write );


// === template specialization for bool ===

template <>
int    NANOTypeWriter<bool     >::cSize( const void* p ) {
  return ( convType == copyVector ? *iPtr( auxPtr ) : -1 );
}
template <>
void   NANOTypeWriter<bool     >::addC( const void* p, void* t,
                                        const std::string& name,
                                        const std::string& doc ) {
  this->addC<bool>( p, t, name, doc, NANOTableWrapper::Bool );
  return;
}
static NANOTypeWriter<unsigned
                      char     > tw____o( DataReset::native_write );


// === template specialization for long long ===

template <>
int    NANOTypeWriter<long long>::cSize( const void* p ) {
  return ( convType == copyVector ? *iPtr( auxPtr ) : -1 );
}
template <>
void   NANOTypeWriter<long long>::addC( const void* p, void* t,
                                        const std::string& name,
                                        const std::string& doc ) {
  this->addC<int>( p, t, name, doc, NANOTableWrapper::Int );
  return;
}
static NANOTypeWriter<long long> tw____l( DataReset::native_write );


// === template specialization for unsigned long long ===

template <>
int    NANOTypeWriter<unsigned
                      long long>::cSize( const void* p ) {
  return ( convType == copyVector ? *iPtr( auxPtr ) : -1 );
}
template <>
void   NANOTypeWriter<unsigned
                      long long>::addC( const void* p, void* t,
                                        const std::string& name,
                                        const std::string& doc ) {
  this->addC<int>( p, t, name, doc, NANOTableWrapper::Int );
  return;
}
static NANOTypeWriter<unsigned
                      long long> tw___ul( DataReset::native_write );


// === template specialization for float ===

template <>
int    NANOTypeWriter<float    >::cSize( const void* p ) {
  return ( convType == copyVector ? *iPtr( auxPtr ) : -1 );
}
template <>
void   NANOTypeWriter<float    >::addC( const void* p, void* t,
                                        const std::string& name,
                                        const std::string& doc ) {
  this->addC<float>( p, t, name, doc, NANOTableWrapper::Float );
  return;
}
static NANOTypeWriter<float    > tw____f( DataReset::native_write );


// === template specialization for double ===

template <>
int    NANOTypeWriter<double   >::cSize( const void* p ) {
  return ( convType == copyVector ? *iPtr( auxPtr ) : -1 );
}
template <>
void   NANOTypeWriter<double   >::addC( const void* p, void* t,
                                        const std::string& name,
                                        const std::string& doc ) {
  this->addC<float>( p, t, name, doc, NANOTableWrapper::Float );
  return;
}
static NANOTypeWriter<double   > tw____d( DataReset::native_write );

