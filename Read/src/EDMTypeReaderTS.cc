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

static EDMTypeReader<int               > tr____i( DataReset::stl_read );


// === template specialization for unsigned int === 

static EDMTypeReader<unsigned int      > tr___ui( DataReset::stl_read );


// === template specialization for short === 

static EDMTypeReader<short             > tr____s( DataReset::stl_read );


// === template specialization for unsigned short === 

static EDMTypeReader<unsigned short    > tr___us( DataReset::stl_read );


// === template specialization for char === 

static EDMTypeReader<char              > tr____b( DataReset::stl_read );


// === template specialization for unsigned char  === 

static EDMTypeReader<unsigned char     > tr___ub( DataReset::stl_read );


// === template specialization for bool  === 

static EDMTypeReader<bool              > tr____a( DataReset::stl_read );


// === template specialization for long long === 

static EDMTypeReader<long long         > tr____l( DataReset::stl_read );


// === template specialization for unsigned long long === 

static EDMTypeReader<unsigned long long> tr___ul( DataReset::stl_read );


// === template specialization for float === 

static EDMTypeReader<float             > tr____f( DataReset::stl_read );


// === template specialization for double === 

static EDMTypeReader<double            > tr____d( DataReset::stl_read );

