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
#include "NtuTool/Read/interface/EDMTypeReader.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Read/interface/EDMTypeReaderManager.h"
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

// === template specialization for std::string ===

static const EDMTypeReader< std::string            > ter____x(
                    new DataResetString           ( DataReset::stl_read ) );


// === template specialization for std::vector<int> ===

static const EDMTypeReader< std::vector<int      > > ter_v__i(
                    new DataResetVector<int      >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned int> ===

static const EDMTypeReader< std::vector<unsigned
                                        int      > > ter_v_ui(
                    new DataResetVector<unsigned
                                        int      >( DataReset::stl_read ) );


// === template specialization for std::vector<short> ===

static const EDMTypeReader< std::vector<short    > > ter_v__s(
                    new DataResetVector<short    >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned short> ===

static const EDMTypeReader< std::vector<unsigned
                                        short    > > ter_v_us(
                    new DataResetVector<unsigned
                                        short    >( DataReset::stl_read ) );


// === template specialization for std::vector<char> ===

static const EDMTypeReader< std::vector<char     > > ter_v__b(
                    new DataResetVector<char     >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned char> ===

static const EDMTypeReader< std::vector<unsigned
                                        char     > > ter_v_ub(
                    new DataResetVector<unsigned
                                        char     >( DataReset::stl_read ) );


// === template specialization for std::vector<bool> ===

static const EDMTypeReader< std::vector<bool     > > ter_v__a(
                    new DataResetVector<bool     >( DataReset::stl_read ) );


// === template specialization for std::vector<long long> ===

static const EDMTypeReader< std::vector<long long> > ter_v__l(
                    new DataResetVector<long long>( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned long long> ===

static const EDMTypeReader< std::vector<unsigned
                                        long long> > ter_v_ul(
                    new DataResetVector<unsigned
                                        long long>( DataReset::stl_read ) );


// === template specialization for std::vector<float> ===

static const EDMTypeReader< std::vector<float    > > ter_v__f(
                    new DataResetVector<float    >( DataReset::stl_read ) );


// === template specialization for std::vector<double> ===

static const EDMTypeReader< std::vector<double   > > ter_v__d(
                    new DataResetVector<double   >( DataReset::stl_read ) );


// === template specialization for std::vector<std::string> ===

static const EDMTypeReader< std::vector<std::string> > ter_v__x(
                    new DataResetVector<std::string>( DataReset::stl_read ) );


