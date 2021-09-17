/*
 *  See header file for a description of this class.
 *
 *  $Date: 2010-11-05 16:31:20 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "NtuTool/Read/interface/EDMXYZVectorReader.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Read/interface/EDMTypeReaderManager.h"
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "TTree.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>
#include <sstream>

//-------------------
// Initializations --
//-------------------
static EDMXYZVectorReader tr_mxyz;

//----------------
// Constructors --
//----------------
EDMXYZVectorReader::EDMXYZVectorReader():
 EDMTypeReader<math::XYZVector>( false ) {
  dataType = TreeTypeNames::typeName( dummyPtr );
  EDMTypeReaderManager::registerHandler( TreeTypeNames::typeCode( dummyPtr ),
                                         this );
}


EDMXYZVectorReader::EDMXYZVectorReader( const std::string& name,
                                        const std::string& code,
                                        const std::string& type ):
  EDMTypeReader<math::XYZVector>( name, code, type ) {
}


//--------------
// Destructor --
//--------------
EDMXYZVectorReader::~EDMXYZVectorReader() {
}

//--------------
// Operations --
//--------------
DataHandler* EDMXYZVectorReader::getInstance( const std::string& name,
                                              const std::string& code ) {
  EDMXYZVectorReader* handler = new EDMXYZVectorReader( name, code, dataType );
  handler->dataReset = dataReset;
  return handler;
}


void EDMXYZVectorReader::setMemberPtr( TTree* tree,
                                       const std::string& branchName,
                                       void* dataPtr ) {
  double* pX = static_cast<double*>( dataPtr );
  double* pY = pX + 1;
  double* pZ = pY + 1;
  std::string bN = branchName + ".fCoordinates.";
  std::string bX = bN + "fX";
  std::string bY = bN + "fY";
  std::string bZ = bN + "fZ";
  tree->SetBranchAddress( bX.c_str(), pX );
  tree->SetBranchAddress( bY.c_str(), pY );
  tree->SetBranchAddress( bZ.c_str(), pZ );
  return;
}

