#!/bin/sh

export DCOM=`find /bin /usr/bin | grep dirname | head -1`
export DIR=`${DCOM} $0`
export TOP=`${DCOM} ${DIR}`

eval `find ${TOP} | grep '_810$' | awk -F_ '{printf("cp "$0" "$1); for(i=2;i<NF;++i) printf("_"$i); print ";"}'`

