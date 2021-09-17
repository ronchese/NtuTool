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
#include "NtuTool/EDM/interface/EDMTypeWriter.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/EDM/interface/EDMStringWriter.h"
#include "NtuTool/EDM/interface/EDMTypeWriterManager.h"
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

static EDMTypeWriter<std::string> tw____x(
              new DataResetString( DataReset::native_write ) );


// === template specialization for std::vector<int> ===

static EDMTypeWriter< std::vector<int      > > tw_v__i(
              new DataResetVector<int      >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned int> ===

static EDMTypeWriter< std::vector<unsigned 
                                  int      > > tw_v_ui(
              new DataResetVector<unsigned
                                  int      >( DataReset::stl_read ) );


// === template specialization for std::vector<short> ===

static EDMTypeWriter< std::vector<short    > > tw_v__s(
              new DataResetVector<short    >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned short> ===

static EDMTypeWriter< std::vector<unsigned 
                                  short    > > tw_v_us(
              new DataResetVector<unsigned
                                  short    >( DataReset::stl_read ) );


// === template specialization for std::vector<bool> ===

static EDMTypeWriter< std::vector<bool     > > tw_v__a(
              new DataResetVector       <bool     >( DataReset::stl_read ) );


// === template specialization for std::vector<char> ===

static EDMTypeWriter< std::vector<char     > > tw_v__b(
              new DataResetVector<char     >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned char> ===

static EDMTypeWriter< std::vector<unsigned 
                                  char     > > tw_v_ub(
       new DataResetVector       <unsigned
                                  char     >( DataReset::stl_read ) );



// === template specialization for std::vector<long long> ===

static EDMTypeWriter< std::vector<long long> > tw_v__l(
              new DataResetVector<long long>( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned long long> ===

static EDMTypeWriter< std::vector<unsigned 
                                  long long> > tw_v_ul(
              new DataResetVector<unsigned
                                  long long>( DataReset::stl_read ) );


// === template specialization for std::vector<float> ===

static EDMTypeWriter< std::vector<float    > > tw_v__f(
              new DataResetVector<float    >( DataReset::stl_read ) );


// === template specialization for std::vector<double> ===

static EDMTypeWriter< std::vector<double   > > tw_v__d(
              new DataResetVector<double   >( DataReset::stl_read ) );


// === template specialization for std::vector<std::string> ===

static EDMTypeWriter< std::vector<std::string> > tw_v__x(
              new DataResetVector<std::string>( DataReset::stl_read ) );

