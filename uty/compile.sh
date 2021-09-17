#!/bin/sh

cd `dirname $0`
cd ..
export NTU_TOOL_DIR=`/bin/pwd`

if [ "___"`which root-config | awk -F/ '($NF=="root-config"){print $0}'`"___" = "______" ]; then
  echo "ROOT environment not set: issue the command:"
  echo "source ..../root/bin/thisroot.[sh|csh]"
  exit
fi

rm -f ${NTU_TOOL_DIR}/lib/libNtupleTool.so
c++ -I ${NTU_TOOL_DIR}/include `root-config --cflags` -fPIC \
    --shared -o ${NTU_TOOL_DIR}/lib/libNtupleTool.so \
    Common/src/*.cc  Read/src/*.cc
