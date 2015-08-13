#!/bin/sh

export FILE=$1
export FTMP=/tmp/`basename ${FILE}``date +%s`

awk '(index($0,"rootcintex")==0){print $0}' ${FILE} > ${FTMP}
cp ${FTMP} ${FILE}
rm ${FTMP}
