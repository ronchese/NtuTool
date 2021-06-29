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
#include "NtuTool/EDM/interface/EDMTypeWriterManager.h"
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/TypeReset.h"
#include "NtuTool/Common/interface/DataResetVector.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>

//--------------
// Operations --
//--------------

// === template specialization for int ===

static EDMTypeWriter<int      > tw____i( DataReset::native_write );


// === template specialization for unsigned int ===

static EDMTypeWriter<unsigned
                     int      > tw___ui( DataReset::native_write );


// === template specialization for short ===

static EDMTypeWriter<short    > tw____s( DataReset::native_write );


// === template specialization for unsigned short ===

static EDMTypeWriter<unsigned
                     short    > tw___us( DataReset::native_write );


// === template specialization for char ===

static EDMTypeWriter<char     > tw____b( DataReset::native_write );


// === template specialization for unsigned char ===

static EDMTypeWriter<unsigned
                     char     > tw___ub( DataReset::native_write );


// === template specialization for long long ===

static EDMTypeWriter<long long> tw____l( DataReset::native_write );


// === template specialization for unsigned long long ===

static EDMTypeWriter<unsigned
                     long long> tw___ul( DataReset::native_write );


// === template specialization for float ===

static EDMTypeWriter<float    > tw____f( DataReset::native_write );


// === template specialization for double ===

static EDMTypeWriter<double   > tw____d( DataReset::native_write );

