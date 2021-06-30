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
#include "NtuTool/Common/interface/TreeTypeHandler.h"

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

static const TreeTypeHandler< std::string          > tth____x(
                      new DataResetString( DataReset::native_write ) );


// === template specializations for std::vector<...> ===



// === template specialization for std::vector<int> ===

static const TreeTypeHandler< std::vector<int      > > tth_v__i(
                      new DataResetVector<int      >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned int> ===

static const TreeTypeHandler< std::vector<unsigned
                                          int      > > tth_v_ui(
                      new DataResetVector<unsigned
                                          int      >( DataReset::stl_read ) );


// === template specialization for std::vector<short> ===

static const TreeTypeHandler< std::vector<short    > > tth_v__s(
                      new DataResetVector<short    >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned short> ===

static const TreeTypeHandler< std::vector<unsigned
                                          short    > > tth_v_us(
                      new DataResetVector<unsigned
                                          short    >( DataReset::stl_read ) );


// === template specialization for std::vector<bool> ===

static const TreeTypeHandler< std::vector<bool     > > tth_v__a(
                      new DataResetVector<bool     >( DataReset::stl_read ) );


// === template specialization for std::vector<char> ===

static const TreeTypeHandler< std::vector<char     > > tth_v__b(
                      new DataResetVector<char     >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned char> ===

static const TreeTypeHandler< std::vector<unsigned
                                          char     > > tth_v_ub(
                      new DataResetVector<unsigned
                                          char     >( DataReset::stl_read ) );



// === template specialization for std::vector<long long> ===

static const TreeTypeHandler< std::vector<long long> > tth_v__l(
                      new DataResetVector<long long>( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned long long> ===

static const TreeTypeHandler< std::vector<unsigned
                                          long long> > tth_v_ul(
                      new DataResetVector<unsigned
                                          long long>( DataReset::stl_read ) );


// === template specialization for std::vector<float> ===

static const TreeTypeHandler< std::vector<float    > > tth_v__f(
                      new DataResetVector<float    >( DataReset::stl_read ) );


// === template specialization for std::vector<double> ===

static const TreeTypeHandler< std::vector<double   > > tth_v__d(
                      new DataResetVector<double   >( DataReset::stl_read ) );



// === template specialization for std::vector<std::string> ===

static const TreeTypeHandler< std::vector<std::string> > tth_v__x(
                      new DataResetVector<std::string>( DataReset::stl_read ) );


// === template specializations for std::vector< std::vector<...> > ===


// === template specialization for std::vector< std::vector<int      > > ===

static const TreeTypeHandler< std::vector
                            < std::vector<int      > > > tth_w__i( nullptr );


// === template specialization for std::vector< std::vector<unsigned
//                                                          int      > > ===

static const TreeTypeHandler< std::vector
                            < std::vector<unsigned
                                          int      > > > tth_w_ui( nullptr );


// === template specialization for std::vector< std::vector<short    > > ===

static const TreeTypeHandler< std::vector
                            < std::vector<short    > > > tth_w__s( nullptr );


// === template specialization for std::vector< std::vector<unsigned
//                                                          short    > > ===

static const TreeTypeHandler< std::vector
                            < std::vector<unsigned
                                          short    > > > tth_w_us( nullptr );


// === template specialization for std::vector< std::vector<char     > > ===

static const TreeTypeHandler< std::vector
                            < std::vector<char     > > > tth_w__b( nullptr );


// === template specialization for std::vector< std::vector<unsigned
//                                                          char     > > ===

static const TreeTypeHandler< std::vector
                            < std::vector<unsigned
                                          char     > > > tth_w_ub( nullptr );



// === template specialization for std::vector< std::vector<bool     > > ===

static const TreeTypeHandler< std::vector
                            < std::vector<bool     > > > tth_w__a( nullptr );


// === template specialization for std::vector< std::vector<long long> > ===

static const TreeTypeHandler< std::vector
                            < std::vector<long long> > > tth_w__l( nullptr );


// === template specialization for std::vector< std::vector<unsigned
//                                                          long long> > ===

static const TreeTypeHandler< std::vector
                            < std::vector<unsigned
                                          long long> > > tth_w_ul( nullptr );


// === template specialization for std::vector< std::vector<float    > > ===

static const TreeTypeHandler< std::vector
                            < std::vector<float    > > > tth_w__f( nullptr );


// === template specialization for std::vector< std::vector<double   > > ===

static const TreeTypeHandler< std::vector
                            < std::vector<double   > > > tth_w__d( nullptr );



