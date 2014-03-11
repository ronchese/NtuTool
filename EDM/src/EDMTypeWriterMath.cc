#include "NtuTool/EDM/interface/EDMTypeWriter.h"
#include "NtuTool/EDM/interface/EDMTypeWriterManager.h"
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/Math.h"

// === template specialization for math::XYZVector === 

template <>
EDMTypeWriter<math::XYZVector>::EDMTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  EDMTypeWriterManager::registerHandler( "XYZVector", this );
}
static EDMTypeWriter<math::XYZVector> tw_mxyz;

/*
template <>
void EDMTypeWriter<math::XYZVector>::reset( void* p ) {
  math::XYZVector* q = reinterpret_cast<math::XYZVector*>( p );
  if ( convType != copyVector ) {
    q->SetCoordinates( 0, 0, 0 );
    return;
  }
  else {
    int size = *reinterpret_cast<int*>( auxPtr );
    math::XYZVector* r = q + size;
    while ( r-- > q ) r->SetCoordinates( 0, 0, 0 );
  }
}
*/

/*
template <>
EDMDataHandler* EDMTypeWriter< std::vector<int> >::getInstance( 
                const std::string& name,
                const std::string& code ) {
  return new EDMTypeWriter< std::vector<int> >( name, code, "int" );
}
*/


