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

static EDMTypeReader< std::string                     > tr____x(
              new DataResetString                    ( DataReset::stl_read ) );


// === template specialization for std::vector<int> === 

static EDMTypeReader< std::vector<int               > > tr_v__i(
              new DataResetVector<int               >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned int> === 

static EDMTypeReader< std::vector<unsigned int      > > tr_v_ui(
              new DataResetVector<unsigned int      >( DataReset::stl_read ) );


// === template specialization for std::vector<short> === 

static EDMTypeReader< std::vector<short             > > tr_v__s(
              new DataResetVector<short             >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned short> === 

static EDMTypeReader< std::vector<unsigned short    > > tr_v_us(
              new DataResetVector<unsigned short    >( DataReset::stl_read ) );


// === template specialization for std::vector<char> === 

static EDMTypeReader< std::vector<char              > > tr_v__b(
              new DataResetVector<char              >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned char> === 

static EDMTypeReader< std::vector<unsigned
                                  char              > > tr_v_ub(
              new DataResetVector<unsigned char     >( DataReset::stl_read ) );


// === template specialization for std::vector<bool> === 

static EDMTypeReader< std::vector<bool              > > tr_v__a(
              new DataResetVector<bool              >( DataReset::stl_read ) );


// === template specialization for std::vector<long long> === 

static EDMTypeReader< std::vector<long long         > > tr_v__l(
              new DataResetVector<long long         >( DataReset::stl_read ) );


// === template specialization for std::vector<unsigned long long> === 

static EDMTypeReader< std::vector<unsigned long long> > tr_v_ul(
              new DataResetVector<unsigned long long>( DataReset::stl_read ) );


// === template specialization for std::vector<float> === 

static EDMTypeReader< std::vector<float             > > tr_v__f(
              new DataResetVector<float             >( DataReset::stl_read ) );


// === template specialization for std::vector<double> === 

static EDMTypeReader< std::vector<double            > > tr_v__d(
              new DataResetVector<double            >( DataReset::stl_read ) );


// === template specialization for std::vector<std::string> === 

static EDMTypeReader< std::vector<std::string       > > tr_v__x(
              new DataResetVector<std::string       >( DataReset::stl_read ) );


