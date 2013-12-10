#!/bin/sh
cd `dirname $0`
cd ..
export NTU_TOOL_DIR=`/bin/pwd`
#cd ${NTU_TOOL_DIR}
eval `scramv1 list CMSSW | awk '($1 == "CMSSW") {print "uty/compile_CMSSW.sh "$2";"}'`
