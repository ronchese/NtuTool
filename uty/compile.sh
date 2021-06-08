#!/bin/sh

cd `dirname $0`
cd ..
export NTU_TOOL_DIR=`/bin/pwd`

rm -f ${NTU_TOOL_DIR}/lib/libNtupleTool.so
c++ -I ${NTU_TOOL_DIR}/include `root-config --cflags` -fPIC \
    --shared -o ${NTU_TOOL_DIR}/lib/libNtupleTool.so \
    Common/src/*.cc  Read/src/*.cc
