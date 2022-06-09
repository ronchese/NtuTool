#!/bin/sh

cd `dirname $0`/..
export NTU_ROOT_DIR=`/bin/pwd`
cd ${NTU_ROOT_DIR}

rm -rf ${NTU_ROOT_DIR}/Read
rm -f ${NTU_ROOT_DIR}/uty/go_compile*
grep -v Read ${NTU_ROOT_DIR}/uty/export.sh | grep -v go_compile | grep -v slim | awk '{printf($0); if((NF>1)&&(substr($2,1,13)=="NTU_TOOL_TMP="))printf("_slim"); print""}' > ${NTU_ROOT_DIR}/uty/export.tmp
rm -f ${NTU_ROOT_DIR}/uty/export.sh
mv ${NTU_ROOT_DIR}/uty/export.tmp ${NTU_ROOT_DIR}/uty/export.sh
rm -f ${NTU_ROOT_DIR}/uty/exportSlim.sh
chmod +x ${NTU_ROOT_DIR}/uty/export.sh
mv ${NTU_ROOT_DIR}/uty/compileSlim.sh ${NTU_ROOT_DIR}/uty/compile.sav
rm -f ${NTU_ROOT_DIR}/uty/compile*sh
mv ${NTU_ROOT_DIR}/uty/compile.sav uty/compile.sh


