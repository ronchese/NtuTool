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


//--------------
// Operations --
//--------------

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





