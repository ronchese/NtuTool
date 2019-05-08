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
#include "NtuTool/Common/interface/TreeTypeNames.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------


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
std::string TreeTypeNames::typeCode( int*  dataPtr ) {
  return "I";
}
template <>
std::string TreeTypeNames::typeName( int*  dataPtr ) {
  return "int";
}


// === template specialization for unsigned int ===

template <>
std::string TreeTypeNames::typeCode( unsigned int*  dataPtr ) {
  return "i";
}
template <>
std::string TreeTypeNames::typeName( unsigned int*  dataPtr ) {
  return "uint";
}


// === template specialization for short ===

template <>
std::string TreeTypeNames::typeCode( short*  dataPtr ) {
  return "S";
}
template <>
std::string TreeTypeNames::typeName( short*  dataPtr ) {
  return "short";
}


// === template specialization for unsigned short  ===

template <>
std::string TreeTypeNames::typeCode( unsigned short*  dataPtr ) {
  return "s";
}
template <>
std::string TreeTypeNames::typeName( unsigned short*  dataPtr ) {
  return "ushort";
}


// === template specialization for bool ===

template <>
std::string TreeTypeNames::typeCode( bool*  dataPtr ) {
  return "O";
}
template <>
std::string TreeTypeNames::typeName( bool*  dataPtr ) {
  return "bool";
}


template <>
std::string TreeTypeNames::typeCode( bool**  dataPtr ) {
  return "O";
}
template <>
std::string TreeTypeNames::typeName( bool**  dataPtr ) {
  return "bool";
}


// === template specialization for char ===

template <>
std::string TreeTypeNames::typeCode( char*  dataPtr ) {
  return "B";
}
template <>
std::string TreeTypeNames::typeName( char*  dataPtr ) {
  return "char";
}


// === template specialization for unsigned char ===

template <>
std::string TreeTypeNames::typeCode( unsigned char*  dataPtr ) {
  return "b";
}
template <>
std::string TreeTypeNames::typeName( unsigned char*  dataPtr ) {
  return "uchar";
}


// === template specialization for long long ===

template <>
std::string TreeTypeNames::typeCode( long long*  dataPtr ) {
  return "L";
}
template <>
std::string TreeTypeNames::typeName( long long*  dataPtr ) {
  return "llong";
}


// === template specialization for unsigned long long ===

template <>
std::string TreeTypeNames::typeCode( unsigned long long*  dataPtr ) {
  return "l";
}
template <>
std::string TreeTypeNames::typeName( unsigned long long*  dataPtr ) {
  return "ullong";
}


// === template specialization for float ===

template <>
std::string TreeTypeNames::typeCode( float*  dataPtr ) {
  return "F";
}
template <>
std::string TreeTypeNames::typeName( float*  dataPtr ) {
  return "float";
}


// === template specialization for double ===

template <>
std::string TreeTypeNames::typeCode( double*  dataPtr ) {
  return "D";
}
template <>
std::string TreeTypeNames::typeName( double*  dataPtr ) {
  return "double";
}


// === template specialization for C__String ===

template <>
std::string TreeTypeNames::typeCode( C__String*  dataPtr ) {
  return "C";
}
template <>
std::string TreeTypeNames::typeName( C__String*  dataPtr ) {
  return "String";
}

