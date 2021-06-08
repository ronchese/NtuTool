#!/bin/sh

if [ ! -s "${ROOTSYS}" ]; then
echo "ROOTSYS undefined: source ..../root/bin/thisroot.[sh|csh]"
exit
fi

if [ ! -s "${NTU_TOOL_DIR}" ]; then
echo "NTU_TOOL_DIR undefined: source ..../NtuTool/uty/envset.[sh|csh]"
exit
fi

rm -f simpleLegacyWrite
c++ -Wall `root-config --cflags`                     \
    -I ${NTU_TOOL_DIR}/include                       \
    -o simpleLegacyWrite                             \
    ${NTU_TOOL_DIR}/Common/test/simpleLegacyWrite.cc \
    `root-config --libs`

rm -f simpleNtupleWrite
c++ -Wall `root-config --cflags`                     \
    -I ${NTU_TOOL_DIR}/include                       \
    -o simpleNtupleWrite                             \
    ${NTU_TOOL_DIR}/Common/test/simpleNtupleWrite.cc \
    -L${NTU_TOOL_DIR}/lib -lNtupleTool               \
    `root-config --libs`

rm -f simpleLegacyRead
c++ -Wall `root-config --cflags`                    \
    -I ${NTU_TOOL_DIR}/include                      \
    -o simpleLegacyRead                             \
    ${NTU_TOOL_DIR}/Common/test/simpleLegacyRead.cc \
    `root-config --libs`

rm -f simpleNtupleRead
c++ -Wall `root-config --cflags`                    \
    -I ${NTU_TOOL_DIR}/include                      \
    -o simpleNtupleRead                             \
    ${NTU_TOOL_DIR}/Common/test/simpleNtupleRead.cc \
    -L${NTU_TOOL_DIR}/lib -lNtupleTool              \
    `root-config --libs` -lGpad

rm -f simpleNtupleFilter
c++ -Wall `root-config --cflags`                      \
    -I ${NTU_TOOL_DIR}/include                        \
    -o simpleNtupleFilter                             \
    ${NTU_TOOL_DIR}/Common/test/simpleNtupleFilter.cc \
    -L${NTU_TOOL_DIR}/lib -lNtupleTool                \
    `root-config --libs`

