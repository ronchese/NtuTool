#!/bin/sh

if [ ! -s "${ROOTSYS}" ]; then
echo "ROOTSYS undefined: source ..../root/bin/thisroot.[sh|csh]"
exit
fi

if [ ! -s "${NTU_TOOL_DIR}" ]; then
echo "NTU_TOOL_DIR undefined: source ..../NtuTool/uty/envset.[sh|csh]"
exit
fi

rm -f ${NTU_TOOL_DIR}/Common/test/simpleLegacyWrite
c++ -Wall `root-config --cflags`                     \
    -I ${NTU_TOOL_DIR}/include                       \
    -o ${NTU_TOOL_DIR}/Common/test/simpleLegacyWrite \
    ${NTU_TOOL_DIR}/Common/test/simpleLegacyWrite.cc \
    `root-config --libs`

rm -f ${NTU_TOOL_DIR}/Common/test/simpleNtupleWrite
c++ -Wall `root-config --cflags`                     \
    -I ${NTU_TOOL_DIR}/include                       \
    -o ${NTU_TOOL_DIR}/Common/test/simpleNtupleWrite \
    ${NTU_TOOL_DIR}/Common/test/simpleNtupleWrite.cc \
    -L${NTU_TOOL_DIR}/lib -lNtupleTool               \
    `root-config --libs`

rm -f ${NTU_TOOL_DIR}/Common/test/simpleLegacyRead
c++ -Wall `root-config --cflags`                    \
    -I ${NTU_TOOL_DIR}/include                      \
    -o ${NTU_TOOL_DIR}/Common/test/simpleLegacyRead \
    ${NTU_TOOL_DIR}/Common/test/simpleLegacyRead.cc \
    `root-config --libs`

rm -f ${NTU_TOOL_DIR}/Common/test/simpleNtupleRead
c++ -Wall `root-config --cflags`                    \
    -I ${NTU_TOOL_DIR}/include                      \
    -o ${NTU_TOOL_DIR}/Common/test/simpleNtupleRead \
    ${NTU_TOOL_DIR}/Common/test/simpleNtupleRead.cc \
    -L${NTU_TOOL_DIR}/lib -lNtupleTool              \
    `root-config --libs` -lGpad

rm -f ${NTU_TOOL_DIR}/Common/test/simpleNtupleFilter
c++ -Wall `root-config --cflags`                      \
    -I ${NTU_TOOL_DIR}/include                        \
    -o ${NTU_TOOL_DIR}/Common/test/simpleNtupleFilter \
    ${NTU_TOOL_DIR}/Common/test/simpleNtupleFilter.cc \
    -L${NTU_TOOL_DIR}/lib -lNtupleTool                \
    `root-config --libs`

