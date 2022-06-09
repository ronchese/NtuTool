#!/bin/sh

cd `dirname $0`
export NTU_TOOL_TGZ=`export.sh`
export NTU_VERSNAME=`echo ${NTU_TOOL_TGZ} | awk -F/ '{print $NF}' | awk -F. '{print $1}'`
cd ..
export NTU_ROOT_DIR=`/bin/pwd`
cd ${NTU_ROOT_DIR}

export NTU_TEMP_DIR=/tmp/NTU_TEMP_DIR_`date +%s`

mkdir ${NTU_TEMP_DIR}
cd ${NTU_TEMP_DIR}
tar -xzf ${NTU_TOOL_TGZ}
${NTU_VERSNAME}/uty/slim.sh
rm -f ${NTU_VERSNAME}/uty/slim.sh

export NTU_VERSSLIM=${NTU_VERSNAME}_slim
mv ${NTU_VERSNAME} ${NTU_VERSSLIM}
export NTU_SLIM_TGZ=`echo ${NTU_TOOL_TGZ} | sed s/${NTU_VERSNAME}/${NTU_VERSSLIM}/`
tar -czf ${NTU_SLIM_TGZ} ${NTU_VERSSLIM}

cd ${NTU_ROOT_DIR}
rm -rf ${NTU_TEMP_DIR}

echo ${NTU_SLIM_TGZ}
