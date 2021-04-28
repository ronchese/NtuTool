#include "NtuTool/EDM/interface/EDMTypeWriter.h"
#include "NtuTool/EDM/interface/EDMTypeWriterManager.h"
#include "NtuTool/Common/interface/TreeTypeNames.h"
#include "NtuTool/Common/interface/Math.h"

// === template specialization for math::XYZVector === 

static EDMTypeWriter<math::XYZVector> tw_mxyz( nullptr );


