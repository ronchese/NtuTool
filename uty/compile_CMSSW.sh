#!/bin/sh

cd `dirname $0`
cd ..
export NTU_TOOL_DIR=`/bin/pwd`

if   [ $# = "0" ]; then
  echo "CMSSW version missing: use"
  echo "compile_CMSSW.sh CMSSW_X_Y_Z [slcN_ARCH_gccPQR]"
exit
elif [ $# = "1" ]; then
  export CMSSW_VERSION=$1
  if [ "___"`printenv | awk -F= '($1=="SCRAM_ARCH"){print $0}'`"___" = "______" ]; then
    echo "SCRAM_ARCH not defined: please set it with setenv/export or use"
    echo "compile_CMSSW.sh CMSSW_X_Y_Z slcN_ARCH_gccPQR"
    exit
  fi
else
  export PAR_SUBSTR1=`echo $1 | awk '{print substr($0,1,5)}'`
  export PAR_SUBSTR2=`echo $2 | awk '{print substr($0,1,5)}'`
  if   [ ${PAR_SUBSTR1} = "CMSSW" ]; then
    export CMSSW_VERSION=$1
    export SCRAM_ARCH=$2
  elif [ ${PAR_SUBSTR2} = "CMSSW" ]; then
    export CMSSW_VERSION=$2
    export SCRAM_ARCH=$1
  fi
fi

export INSTDIR=`scramv1 list CMSSW | awk -v VERSION=${CMSSW_VERSION} 'BEGIN{FOUND="FALSE"} ($1 == "CMSSW" && $2 == VERSION && FOUND == "FALSE") {FOUND="TRUE"} ($1 == "-->" && FOUND == "TRUE") {print $2; FOUND="FALSE"}'`

if [ ! -s "${INSTDIR}" ]; then
  echo ${CMSSW_VERSION}": version not found for arch "${SCRAM_ARCH}
  exit
fi

unset ROOTSYS

cd ${INSTDIR}
eval `scramv1 runtime -sh`

if [ ! -s "${ROOTSYS}" ]; then
  echo ${CMSSW_VERSION}": "
  echo ${ROOTSYS}" not found"
  exit
fi

cd ${NTU_TOOL_DIR}

echo "build lib for "${SCRAM_ARCH}" "${CMSSW_VERSION}

export LIBDIR=${NTU_TOOL_DIR}"/lib/"${SCRAM_ARCH}
if [ ! -d ${LIBDIR} ]; then
  mkdir ${LIBDIR}
fi

export VERSION=`echo ${CMSSW_VERSION} | awk '{print substr($0,7,length($0)-6)}'`

rm -f ${LIBDIR}/libNtupleTool_${VERSION}.so
c++ -I ${NTU_TOOL_DIR}/include `root-config --cflags` -fPIC \
    --shared -o ${LIBDIR}/libNtupleTool_${VERSION}.so \
    Common/src/*.cc  Read/src/*.cc


