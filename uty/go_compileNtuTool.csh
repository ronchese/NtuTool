#!/bin/csh
cd `dirname $0`
cd ..
setenv NTU_TOOL_DIR `/bin/pwd`
#cd ${NTU_TOOL_DIR}
eval `scramv1 list CMSSW | awk '($1 == "CMSSW") {print "uty/compile_CMSSW.csh "$2";"}'`
