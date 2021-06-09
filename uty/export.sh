#!/bin/sh

cd `dirname $0`/..
export NTU_ROOT_DIR=`/bin/pwd`
cd ${NTU_ROOT_DIR}

rm -f export.tgz
tar -czf export.tgz                \
         VERSION                   \
         Common/interface          \
         Common/src                \
         Common/bin/treeAnalyze.cc \
         Common/test/*.h           \
         Common/test/*.cc          \
         Common/test/*.xml         \
         Common/test/*.sh          \
         Read/interface            \
         Read/src                  \
         Read/test/*.cc            \
         Read/test/*.xml           \
         Read/test/*.sh            \
         uty/install.sh            \
         uty/envset*h              \
         uty/compile.sh            \
         uty/go_compileNtuTool.sh  \
         uty/compile_CMSSW.sh

export NTU_TOOL_TMP=NtuTool_`head -1 ${NTU_ROOT_DIR}/VERSION | sed s/"\."/_/g`
mkdir ${NTU_TOOL_TMP}

mv export.tgz ${NTU_TOOL_TMP}
cd ${NTU_TOOL_TMP}
tar -xzf export.tgz
rm -f export.tgz

cd ${NTU_ROOT_DIR}
rm -f ${NTU_TOOL_TMP}.tgz
tar -czf ${NTU_TOOL_TMP}.tgz ${NTU_TOOL_TMP}
rm -rf ${NTU_TOOL_TMP}
rm -f ../${NTU_TOOL_TMP}.tgz
mv ${NTU_TOOL_TMP}.tgz ..

cd ..
echo `/bin/pwd`/${NTU_TOOL_TMP}.tgz

