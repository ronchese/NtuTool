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

static TreeTypeHandler<std::string> tw____x( new DataResetString( DataReset::native_write ) );


// === template specializations for std::vector<...> ===



// === template specialization for std::vector<int> === 

static TreeTypeHandler< std::vector<int      > > tw_v__i( new DataResetVector<int>( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned int> === 

static TreeTypeHandler< std::vector<unsigned
                                   int      > > tw_v_ui( new DataResetVector<unsigned int>( DataReset::stl_read ) );


// === template specialization for std::vector<short> === 

static TreeTypeHandler< std::vector<short    > > tw_v__s( new DataResetVector<short>( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned short> === 

static TreeTypeHandler< std::vector<unsigned
                                   short    > > tw_v_us( new DataResetVector<unsigned short>( DataReset::stl_read ) );


// === template specialization for std::vector<bool> === 

static TreeTypeHandler< std::vector<bool     > > tw_v__a( new DataResetVector<bool>( DataReset::stl_read ) );


// === template specialization for std::vector<char> === 

static TreeTypeHandler< std::vector<char     > > tw_v__b( new DataResetVector<char>( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned char> === 

static TreeTypeHandler< std::vector<unsigned
                                   char     > > tw_v_ub( new DataResetVector<unsigned char>( DataReset::stl_read ) );



// === template specialization for std::vector<long long> === 

static TreeTypeHandler< std::vector<long long> > tw_v__l( new DataResetVector<long long>( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned long long> === 

static TreeTypeHandler< std::vector<unsigned
                                   long long> > tw_v_ul( new DataResetVector<unsigned long long>( DataReset::stl_read ) );


// === template specialization for std::vector<float> === 

static TreeTypeHandler< std::vector<float    > > tw_v__f( new DataResetVector<float>( DataReset::stl_read ) );


// === template specialization for std::vector<double> === 

static TreeTypeHandler< std::vector<double   > > tw_v__d( new DataResetVector<float>( DataReset::stl_read ) );



// === template specialization for std::vector<std::string> === 

static TreeTypeHandler< std::vector<std::string> > tw_v__x( new DataResetVector<std::string>( DataReset::stl_read ) );


// === template specializations for std::vector< std::vector<...> > ===


// === template specialization for std::vector< std::vector<int> > === 

static TreeTypeHandler< std::vector< std::vector<int       > > > tw_w__i( nullptr );


// === template specialization for std::vector< std::vector<unsigned
//                                                          int> > === 

static TreeTypeHandler< std::vector< std::vector< unsigned
                                                 int      > > > tw_w_ui( nullptr );


// === template specialization for std::vector< std::vector<short> > === 

static TreeTypeHandler< std::vector< std::vector<short     > > > tw_w__s( nullptr );


// === template specialization for std::vector< std::vector<unsigned
//                                                          short> === 

static TreeTypeHandler< std::vector< std::vector<unsigned
                                                short     > > > tw_w_us( nullptr );


// === template specialization for std::vector< std::vector<char> > > === 

static TreeTypeHandler< std::vector< std::vector<char      > > > tw_w__b( nullptr );


// === template specialization for std::vector< std::vector<unsigned
//                                                          char> === 

static TreeTypeHandler< std::vector< std::vector<unsigned
                                                char      > > > tw_w_ub( nullptr );



// === template specialization for std::vector< std::vector<bool> > === 

static TreeTypeHandler< std::vector< std::vector<bool      > > > tw_w__a( nullptr );


// === template specialization for std::vector< std::vector<long long> > === 

static TreeTypeHandler< std::vector< std::vector<long long > > > tw_w__l( nullptr );


// === template specialization for std::vector< std::vector<unsigned
//                                                          long long> === 

static TreeTypeHandler< std::vector< std::vector<unsigned
                                                long long > > > tw_w_ul( nullptr );


// === template specialization for std::vector< std::vector<float> > === 

static TreeTypeHandler< std::vector< std::vector<float     > > > tw_w__f( nullptr );


// === template specialization for std::vector< std::vector<double> > === 

static TreeTypeHandler< std::vector< std::vector<double    > > > tw_w__d( nullptr );



