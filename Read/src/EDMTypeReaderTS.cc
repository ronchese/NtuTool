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

// === template specialization for int ===

static const EDMTypeReader<int      > ter____i( DataReset::stl_read );


// === template specialization for unsigned int ===

static const EDMTypeReader<unsigned
                           int      > ter___ui( DataReset::stl_read );


// === template specialization for short ===

static const EDMTypeReader<short    > ter____s( DataReset::stl_read );


// === template specialization for unsigned short ===

static const EDMTypeReader<unsigned
                           short    > ter___us( DataReset::stl_read );


// === template specialization for char ===

static const EDMTypeReader<char     > ter____b( DataReset::stl_read );


// === template specialization for unsigned char ===

static const EDMTypeReader<unsigned
                           char     > ter___ub( DataReset::stl_read );


// === template specialization for bool ===

static const EDMTypeReader<bool     > ter____a( DataReset::stl_read );


// === template specialization for long long ===

static const EDMTypeReader<long long> ter____l( DataReset::stl_read );


// === template specialization for unsigned long long ===

static const EDMTypeReader<unsigned
                           long long> ter___ul( DataReset::stl_read );


// === template specialization for float ===

static const EDMTypeReader<float    > ter____f( DataReset::stl_read );


// === template specialization for double ===

static const EDMTypeReader<double   > ter____d( DataReset::stl_read );

