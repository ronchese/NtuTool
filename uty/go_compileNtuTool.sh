#!/bin/sh
cd `dirname $0`
cd ..

export NTU_TOOL_DIR=`/bin/pwd`

if   [ $# = "0" ]; then
  if [ "___"`printenv | awk -F= '($1=="SCRAM_ARCH"){print $0}'`"___" = "______" ]; then
    echo "SCRAM_ARCH not defined: please set it with setenv/export or use"
    echo "go_compileNtuTool.sh slcN_ARCH_gccPQR"
    exit
  fi
elif [ $# = "1" ]; then
  export SCRAM_ARCH=$1
fi

eval `scramv1 list CMSSW | awk '($1 == "CMSSW") {print "uty/compile_CMSSW.sh "$2";"}'`
