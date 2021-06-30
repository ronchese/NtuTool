#!/bin/sh

cd `dirname $0`/..
export INSTALLDIR=`/bin/pwd`

rm -f uty/envset.sh
sed s#INSTALLDIR#${INSTALLDIR}# uty/envsetTemplate.sh  > uty/envset.sh
rm -f uty/envset.csh
sed s#INSTALLDIR#${INSTALLDIR}# uty/envsetTemplate.csh > uty/envset.csh

. uty/envset.sh

cd ${NTU_TOOL_DIR}/Common/src
rm -f treeAnalyze.cc
ln -s ../bin/treeAnalyze.cc

cd ${NTU_TOOL_DIR}

rm -rf include lib
mkdir include
mkdir lib

cd include
eval `ls -1 ../*/interface/*h ../*/interface/*hpp | awk '{print "ln -s "$0";"}'`
ln -s ${NTU_TOOL_DIR} ${NTU_TOOL_DIR}/include/NtuTool

