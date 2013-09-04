#!/bin/csh

cd ${NTU_TOOL_DIR}

rm -f lib/libNtupleTool.so
c++ -I ${NTU_TOOL_DIR}/include `root-config --cflags` -fPIC \
    --shared -o $NTU_TOOL_DIR/lib/libNtupleTool.so \
    Common/src/*.cc  Read/src/*.cc
