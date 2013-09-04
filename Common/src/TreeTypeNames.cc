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
#include "NtuTool/Common/interface/Math.h"

//---------------
// C++ Headers --
//---------------
#include <vector>
#include <string>

//-------------------
// Initializations --
//-------------------


//----------------
// Constructors --
//----------------
TreeTypeNames::TreeTypeNames() {
}

//--------------
// Destructor --
//--------------
TreeTypeNames::~TreeTypeNames() {
}

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
  return "A";
}
template <>
std::string TreeTypeNames::typeName( bool*  dataPtr ) {
  return "bool";
}


template <>
std::string TreeTypeNames::typeCode( bool**  dataPtr ) {
  return "A";
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


// === template specializations for std::vector<...> ===


// === template specialization for std::vector<int> ===

template <>
std::string TreeTypeNames::typeCode( std::vector<int>*  dataPtr ) {
  return "vI";
}
template <>
std::string TreeTypeNames::typeName( std::vector<int>*  dataPtr ) {
  return "ints";
}


template <>
std::string TreeTypeNames::typeCode( std::vector<int>** dataPtr ) {
  return "pvI";
}
template <>
std::string TreeTypeNames::typeName( std::vector<int>** dataPtr ) {
  return "ints";
}


// === template specialization for std::vector<unsigned int> ===

template <>
std::string TreeTypeNames::typeCode( std::vector<unsigned int>*  dataPtr ) {
  return "vi";
}
template <>
std::string TreeTypeNames::typeName( std::vector<unsigned int>*  dataPtr ) {
  return "uints";
}


template <>
std::string TreeTypeNames::typeCode( std::vector<unsigned int>** dataPtr ) {
  return "pvi";
}
template <>
std::string TreeTypeNames::typeName( std::vector<unsigned int>** dataPtr ) {
  return "uints";
}


// === template specialization for std::vector<short> ===

template <>
std::string TreeTypeNames::typeCode( std::vector<short>*  dataPtr ) {
  return "vS";
}
template <>
std::string TreeTypeNames::typeName( std::vector<short>*  dataPtr ) {
  return "shorts";
}


template <>
std::string TreeTypeNames::typeCode( std::vector<short>** dataPtr ) {
  return "pvS";
}
template <>
std::string TreeTypeNames::typeName( std::vector<short>** dataPtr ) {
  return "shorts";
}


// === template specialization for std::vector<unsigned short> ===

template <>
std::string TreeTypeNames::typeCode( std::vector<unsigned short>*  dataPtr ) {
  return "vs";
}
template <>
std::string TreeTypeNames::typeName( std::vector<unsigned short>*  dataPtr ) {
  return "ushorts";
}


template <>
std::string TreeTypeNames::typeCode( std::vector<unsigned short>** dataPtr ) {
  return "pvs";
}
template <>
std::string TreeTypeNames::typeName( std::vector<unsigned short>** dataPtr ) {
  return "ushorts";
}


// === template specialization for std::vector<bool> ===

template <>
std::string TreeTypeNames::typeCode( std::vector<bool>*  dataPtr ) {
  return "vA";
}
template <>
std::string TreeTypeNames::typeName( std::vector<bool>*  dataPtr ) {
  return "bools";
}


template <>
std::string TreeTypeNames::typeCode( std::vector<bool>** dataPtr ) {
  return "pvA";
}
template <>
std::string TreeTypeNames::typeName( std::vector<bool>** dataPtr ) {
  return "bools";
}


// === template specialization for std::vector<char> ===

template <>
std::string TreeTypeNames::typeCode( std::vector<char>*  dataPtr ) {
  return "vB";
}
template <>
std::string TreeTypeNames::typeName( std::vector<char>*  dataPtr ) {
  return "chars";
}


template <>
std::string TreeTypeNames::typeCode( std::vector<char>** dataPtr ) {
  return "pvB";
}
template <>
std::string TreeTypeNames::typeName( std::vector<char>** dataPtr ) {
  return "chars";
}


// === template specialization for std::vector<unsigned char> ===

template <>
std::string TreeTypeNames::typeCode( std::vector<unsigned char>*  dataPtr ) {
  return "vb";
}
template <>
std::string TreeTypeNames::typeName( std::vector<unsigned char>*  dataPtr ) {
  return "uchars";
}


template <>
std::string TreeTypeNames::typeCode( std::vector<unsigned char>** dataPtr ) {
  return "pvb";
}
template <>
std::string TreeTypeNames::typeName( std::vector<unsigned char>** dataPtr ) {
  return "uchars";
}


// === template specialization for std::vector<long long> ===

template <>
std::string TreeTypeNames::typeCode( std::vector<long long>*  dataPtr ) {
  return "vL";
}
template <>
std::string TreeTypeNames::typeName( std::vector<long long>*  dataPtr ) {
  return "llongs";
}


template <>
std::string TreeTypeNames::typeCode( std::vector<long long>** dataPtr ) {
  return "pvL";
}
template <>
std::string TreeTypeNames::typeName( std::vector<long long>** dataPtr ) {
  return "llongs";
}


// === template specialization for std::vector<unsigned long long> ===

template <>
std::string TreeTypeNames::typeCode( std::vector<unsigned long long>*  dataPtr ) {
  return "vl";
}
template <>
std::string TreeTypeNames::typeName( std::vector<unsigned long long>*  dataPtr ) {
  return "ullongs";
}


template <>
std::string TreeTypeNames::typeCode( std::vector<unsigned long long>** dataPtr ) {
  return "pvl";
}
template <>
std::string TreeTypeNames::typeName( std::vector<unsigned long long>** dataPtr ) {
  return "ullongs";
}


// === template specialization for std::vector<float> ===

template <>
std::string TreeTypeNames::typeCode( std::vector<float>*  dataPtr ) {
  return "vF";
}
template <>
std::string TreeTypeNames::typeName( std::vector<float>*  dataPtr ) {
  return "floats";
}


template <>
std::string TreeTypeNames::typeCode( std::vector<float>** dataPtr ) {
  return "pvF";
}
template <>
std::string TreeTypeNames::typeName( std::vector<float>** dataPtr ) {
  return "floats";
}


// === template specialization for std::vector<double> ===

template <>
std::string TreeTypeNames::typeCode( std::vector<double>*  dataPtr ) {
  return "vD";
}
template <>
std::string TreeTypeNames::typeName( std::vector<double>*  dataPtr ) {
  return "doubles";
}


template <>
std::string TreeTypeNames::typeCode( std::vector<double>** dataPtr ) {
  return "pvD";
}
template <>
std::string TreeTypeNames::typeName( std::vector<double>** dataPtr ) {
  return "doubles";
}


// === template specializations for std::vector< std::vector<...> > ===


// === template specialization for std::vector< std::vector<int> > ===

template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<int> >*  dataPtr ) {
  return "vvI";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<int> >*  dataPtr ) {
  return "intss";
}


template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<int> >** dataPtr ) {
  return "pvvI";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<int> >** dataPtr ) {
  return "intss";
}


// === template specialization for std::vector< std::vector<unsigned int> > ===

template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<unsigned int> >*  dataPtr ) {
  return "vvi";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<unsigned int> >*  dataPtr ) {
  return "uintss";
}


template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<unsigned int> >** dataPtr ) {
  return "pvvi";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<unsigned int> >** dataPtr ) {
  return "uintss";
}


// === template specialization for std::vector< std::vector<short> > ===

template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<short> >*  dataPtr ) {
  return "vvS";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<short> >*  dataPtr ) {
  return "shortss";
}


template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<short> >** dataPtr ) {
  return "pvvS";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<short> >** dataPtr ) {
  return "shortss";
}


// === template specialization for std::vector< std::vector<unsigned short> ===

template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<unsigned short> >*  dataPtr ) {
  return "vvs";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<unsigned short> >*  dataPtr ) {
  return "ushortss";
}


template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<unsigned short> >** dataPtr ) {
  return "pvvs";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<unsigned short> >** dataPtr ) {
  return "ushortss";
}


// === template specialization for std::vector< std::vector<bool> > ===

template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<bool> >*  dataPtr ) {
  return "vvA";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<bool> >*  dataPtr ) {
  return "boolss";
}


template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<bool> >** dataPtr ) {
  return "pvvA";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<bool> >** dataPtr ) {
  return "boolss";
}


// === template specialization for std::vector< std::vector<char> > ===

template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<char> >*  dataPtr ) {
  return "vvB";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<char> >*  dataPtr ) {
  return "charss";
}


template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<char> >** dataPtr ) {
  return "pvvB";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<char> >** dataPtr ) {
  return "charss";
}


// === template specialization for std::vector< std::vector<unsigned char> > ===

template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<unsigned char> >*  dataPtr ) {
  return "vvb";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<unsigned char> >*  dataPtr ) {
  return "ucharss";
}


template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<unsigned char> >** dataPtr ) {
  return "pvvb";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<unsigned char> >** dataPtr ) {
  return "ucharss";
}


// === template specialization for std::vector< std::vector<long long> > ===

template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<long long> >*  dataPtr ) {
  return "vvL";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<long long> >*  dataPtr ) {
  return "llongss";
}


template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<long long> >** dataPtr ) {
  return "pvvL";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<long long> >** dataPtr ) {
  return "llongss";
}


// === template specialization for std::vector< std::vector<unsigned long long> > ===

template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<unsigned long long> >*  dataPtr ) {
  return "vvl";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<unsigned long long> >*  dataPtr ) {
  return "ullongss";
}


template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<unsigned long long> >** dataPtr ) {
  return "pvvl";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<unsigned long long> >** dataPtr ) {
  return "ullongss";
}


// === template specialization for std::vector< std::vector<float> > ===

template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<float> >*  dataPtr ) {
  return "vvF";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<float> >*  dataPtr ) {
  return "floatss";
}


template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<float> >** dataPtr ) {
  return "pvvF";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<float> >** dataPtr ) {
  return "floatss";
}


// === template specialization for std::vector< std::vector<double> > ===

template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<double> >*  dataPtr ) {
  return "vvD";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<double> >*  dataPtr ) {
  return "doubless";
}


template <>
std::string TreeTypeNames::typeCode( std::vector< std::vector<double> >** dataPtr ) {
  return "pvvD";
}
template <>
std::string TreeTypeNames::typeName( std::vector< std::vector<double> >** dataPtr ) {
  return "doubless";
}

// ===============================================


// === template specialization for std::string ===

template <>
std::string TreeTypeNames::typeCode( std::string*  dataPtr ) {
  return "X";
}
template <>
std::string TreeTypeNames::typeName( std::string*  dataPtr ) {
  return "String";
}


template <>
std::string TreeTypeNames::typeCode( std::string** dataPtr ) {
  return "X";
}
template <>
std::string TreeTypeNames::typeName( std::string** dataPtr ) {
  return "String";
}


// === template specialization for std::vector<std::string> ===

template <>
std::string TreeTypeNames::typeCode( std::vector<std::string>*  dataPtr ) {
  return "vX";
}
template <>
std::string TreeTypeNames::typeName( std::vector<std::string>*  dataPtr ) {
  return "strings";
}


template <>
std::string TreeTypeNames::typeCode( std::vector<std::string>** dataPtr ) {
  return "vX";
}
template <>
std::string TreeTypeNames::typeName( std::vector<std::string>** dataPtr ) {
  return "strings";
}


// === template specialization for math::XYZVector ===

template <>
std::string TreeTypeNames::typeCode( math::XYZVector*  dataPtr ) {
  return "XYZVector";
}
template <>
std::string TreeTypeNames::typeName( math::XYZVector*  dataPtr ) {
  return "doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3D";
}


template <>
std::string TreeTypeNames::typeCode( math::XYZVector** dataPtr ) {
  return "";
}
template <>
std::string TreeTypeNames::typeName( math::XYZVector** dataPtr ) {
  return "doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3D";
}





