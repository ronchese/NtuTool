#!/bin/sh

export VERSION=$1
export INSTDIR=`scramv1 list CMSSW | awk -v VERSION=${VERSION} 'BEGIN{FOUND="FALSE"} ($1 == "CMSSW" && $2 == VERSION && FOUND == "FALSE") {FOUND="TRUE"} ($1 == "-->" && FOUND == "TRUE") {print $2; FOUND="FALSE"}'`

if [ ! -s "${INSTDIR}" ]; then
echo "${VERSION}: version not found"
exit
fi

unset ROOTSYS

cd ${INSTDIR}
eval `scramv1 runtime -sh`

if [ ! -s "${ROOTSYS}" ]; then
echo "${VERSION}: "
echo "${ROOTSYS} not found"
exit
fi

cd `dirname $0`
cd ..
export NTU_TOOL_DIR=`/bin/pwd`
#cd ${NTU_TOOL_DIR}

echo "build lib for "${SCRAM_ARCH}" "${VERSION}

export LIBDIR=${NTU_TOOL_DIR}/lib/${SCRAM_ARCH}
if [ ! -d ${LIBDIR} ]; then
mkdir ${LIBDIR}
fi

rm -f ${LIBDIR}/libNtupleTool_${VERSION}.so
c++ -I ${NTU_TOOL_DIR}/include `root-config --cflags` -fPIC \
    --shared -o ${LIBDIR}/libNtupleTool_${VERSION}.so \
    Common/src/*.cc  Read/src/*.cc


