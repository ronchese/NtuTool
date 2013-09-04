#!/bin/csh
cd ${NTU_TOOL_DIR}
eval `scramv1 list CMSSW | awk '($1 == "CMSSW") {print "uty/compile_CMSSW.csh "$2";"}'`
