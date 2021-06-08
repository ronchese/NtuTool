#!/bin/sh

if [ ! -s "${ROOTSYS}" ]; then
echo "ROOTSYS undefined: source ..../root/bin/thisroot.[sh|csh]"
exit
fi

if [ ! -s "${NTU_TOOL_DIR}" ]; then
echo "NTU_TOOL_DIR undefined: source ..../NtuTool/uty/envset.[sh|csh]"
exit
fi

export NTU_EXA_PATH=${NTU_TOOL_DIR}/Read/test

export EXAMPLE_NAME=simpleNtuEDMRead
rm -f ${NTU_EXA_PATH}/${EXAMPLE_NAME}
c++ -Wall `root-config --cflags`       \
    -I ${NTU_TOOL_DIR}/include         \
    -o ${NTU_EXA_PATH}/${EXAMPLE_NAME} \
    ${NTU_EXA_PATH}/${EXAMPLE_NAME}.cc \
    -L${NTU_TOOL_DIR}/lib -lNtupleTool \
    `root-config --libs`

export EXAMPLE_NAME=simpleNtuNANORead
rm -f ${NTU_EXA_PATH}/${EXAMPLE_NAME}
c++ -Wall `root-config --cflags`       \
    -I ${NTU_TOOL_DIR}/include         \
    -o ${NTU_EXA_PATH}/${EXAMPLE_NAME} \
    ${NTU_EXA_PATH}/${EXAMPLE_NAME}.cc \
    -L${NTU_TOOL_DIR}/lib -lNtupleTool \
    `root-config --libs`
