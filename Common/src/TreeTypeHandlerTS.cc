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
#include "NtuTool/Common/interface/DataResetVector.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>

//--------------
// Operations --
//--------------

// === template specialization for int ===

static const TreeTypeHandler<int      > tth____i( DataReset::native_write );


// === template specialization for unsigned int ===

static const TreeTypeHandler<unsigned
                             int      > tth___ui( DataReset::native_write );


// === template specialization for short ===

static const TreeTypeHandler<short    > tth____s( DataReset::native_write );


// === template specialization for unsigned short ===

static const TreeTypeHandler<unsigned
                             short    > tth___us( DataReset::native_write );


// === template specialization for char & C/C++ string ===

template <>
TreeTypeHandler<char>::TreeTypeHandler( DataReset::resetMode mode ):
                           TypeHandler<char,TreeTypeManager>( mode ) {
  C__String* p = nullptr;
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( p ), this );
}
static const TreeTypeHandler<char     > tth____b( DataReset::native_write );


// === template specialization for unsigned char ===

static const TreeTypeHandler<unsigned
                             char     > tth___ub( DataReset::native_write );


// === template specialization for bool ===

static const TreeTypeHandler<bool     > tth____a( DataReset::native_write );


// === template specialization for long long ===

static const TreeTypeHandler<long long> tth____l( DataReset::native_write );


// === template specialization for unsigned long long ===

static const TreeTypeHandler<unsigned
                             long long> tth___ul( DataReset::native_write );


// === template specialization for float ===

static const TreeTypeHandler<float    > tth____f( DataReset::native_write );


// === template specialization for double ===

static const TreeTypeHandler<double   > tth____d( DataReset::native_write );

