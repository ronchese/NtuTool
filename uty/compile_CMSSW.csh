#!/bin/csh

setenv VERSION $1
setenv INSTDIR `scramv1 list CMSSW | awk -v VERSION=${VERSION} 'BEGIN{FOUND="FALSE"} ($1 == "CMSSW" && $2 == VERSION && FOUND == "FALSE") {FOUND="TRUE"} ($1 == "-->" && FOUND == "TRUE") {print $2; FOUND="FALSE"}'`

if ( ! -s "${INSTDIR}" ) then
echo "${VERSION}: not found"
exit
endif

unsetenv ROOTSYS

cd ${INSTDIR}
eval `scramv1 runtime -csh`

if ( ! -s "${ROOTSYS}" ) then
echo "${VERSION}: "
echo "${ROOTSYS} not found"
exit
endif

cd ${NTU_TOOL_DIR}

echo "build lib for "${SCRAM_ARCH}" "${VERSION}

setenv LIBDIR ${NTU_TOOL_DIR}/lib/${SCRAM_ARCH}
if ( ! -d ${LIBDIR} ) then
mkdir ${LIBDIR}
endif

rm -f ${LIBDIR}/libNtupleTool_${VERSION}.so
c++ -I ${NTU_TOOL_DIR}/include `root-config --cflags` -fPIC \
    --shared -o ${LIBDIR}/libNtupleTool_${VERSION}.so \
    Common/src/*.cc  Read/src/*.cc


