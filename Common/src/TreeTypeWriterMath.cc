#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/TreeTypeWriter.h"
#include "NtuTool/Common/interface/TreeTypeManager.h"
#include "NtuTool/Common/interface/Math.h"

// === template specialization for math::XYZVector === 

template <>
TreeTypeWriter<math::XYZVector>::TreeTypeWriter() {
  dataType = TreeTypeNames::typeName( dummyPtr );
  TreeTypeManager::registerHandler( "XYZVector", this );
}
static TreeTypeWriter<math::XYZVector> tw_mxyz;

