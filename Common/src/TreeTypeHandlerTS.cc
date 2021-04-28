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

static TreeTypeHandler<int      > tw____i( DataReset::native_write );


// === template specialization for unsigned int === 

static TreeTypeHandler<unsigned
                      int      > tw___ui( DataReset::native_write );


// === template specialization for short === 

static TreeTypeHandler<short    > tw____s( DataReset::native_write );


// === template specialization for unsigned short === 

static TreeTypeHandler<unsigned
                      short    > tw___us( DataReset::native_write );


// === template specialization for char & C/C++ string === 

template <>
TreeTypeHandler<char>::TreeTypeHandler( DataReset::resetMode mode ):
                      TypeHandler<char,TreeTypeManager>( mode ) {
  C__String* p = nullptr;
  TreeTypeManager::registerHandler( TreeTypeNames::typeCode( p ),
                                    this );
}
static TreeTypeHandler<char     > tw____b( DataReset::native_write );


// === template specialization for unsigned char  === 

static TreeTypeHandler<unsigned
                     char     > tw___ub( DataReset::native_write );


// === template specialization for bool === 

static TreeTypeHandler<bool> tw____a( DataReset::native_write );


// === template specialization for long long === 

static TreeTypeHandler<long long> tw____l( DataReset::native_write );


// === template specialization for unsigned long long === 

static TreeTypeHandler<unsigned
                     long long> tw___ul( DataReset::native_write );


// === template specialization for float === 

static TreeTypeHandler<float    > tw____f( DataReset::native_write );


// === template specialization for double === 

static TreeTypeHandler<double   > tw____d( DataReset::native_write );

