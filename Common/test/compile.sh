#!/bin/sh

if [ "___"`which root-config | awk -F/ '($NF=="root-config"){print $0}'`"___" = "______" ]; then
  echo "ROOT environment not set: issue the command:"
  echo "source ..../root/bin/thisroot.[sh|csh]"
  exit
fi

if [ "___"`printenv | awk -F= '($1=="NTU_TOOL_DIR"){print $0}'`"___" = "______" ]; then
  echo "NTU_TOOL_DIR undefined: source ..../NtuTool/uty/envset.[sh|csh]"
  exit
fi

export NTU_EXA_PATH=${NTU_TOOL_DIR}/Common/test

export EXAMPLE_NAME=simpleLegacyWrite
rm -f ${NTU_EXA_PATH}/${EXAMPLE_NAME}
c++ -Wall `root-config --cflags`       \
    -I ${NTU_TOOL_DIR}/include         \
    -o ${NTU_EXA_PATH}/${EXAMPLE_NAME} \
    ${NTU_EXA_PATH}/${EXAMPLE_NAME}.cc \
    -L${NTU_TOOL_DIR}/lib -lNtupleTool \
    `root-config --libs`

export EXAMPLE_NAME=simpleNtupleWrite
rm -f ${NTU_EXA_PATH}/${EXAMPLE_NAME}
c++ -Wall `root-config --cflags`       \
    -I ${NTU_TOOL_DIR}/include         \
    -o ${NTU_EXA_PATH}/${EXAMPLE_NAME} \
    ${NTU_EXA_PATH}/${EXAMPLE_NAME}.cc \
    -L${NTU_TOOL_DIR}/lib -lNtupleTool \
    `root-config --libs`

export EXAMPLE_NAME=simpleLegacyRead
rm -f ${NTU_EXA_PATH}/${EXAMPLE_NAME}
c++ -Wall `root-config --cflags`       \
    -I ${NTU_TOOL_DIR}/include         \
    -o ${NTU_EXA_PATH}/${EXAMPLE_NAME} \
    ${NTU_EXA_PATH}/${EXAMPLE_NAME}.cc \
    -L${NTU_TOOL_DIR}/lib -lNtupleTool \
    `root-config --libs`

export EXAMPLE_NAME=simpleNtupleRead
rm -f ${NTU_EXA_PATH}/${EXAMPLE_NAME}
c++ -Wall `root-config --cflags`       \
    -I ${NTU_TOOL_DIR}/include         \
    -o ${NTU_EXA_PATH}/${EXAMPLE_NAME} \
    ${NTU_EXA_PATH}/${EXAMPLE_NAME}.cc \
    -L${NTU_TOOL_DIR}/lib -lNtupleTool \
    `root-config --libs` -lGpad

export EXAMPLE_NAME=simpleNtupleFilter
rm -f ${NTU_EXA_PATH}/${EXAMPLE_NAME}
c++ -Wall `root-config --cflags`       \
    -I ${NTU_TOOL_DIR}/include         \
    -o ${NTU_EXA_PATH}/${EXAMPLE_NAME} \
    ${NTU_EXA_PATH}/${EXAMPLE_NAME}.cc \
    -L${NTU_TOOL_DIR}/lib -lNtupleTool \
    `root-config --libs`

