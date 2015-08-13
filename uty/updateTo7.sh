#!/bin/sh

export DIR=`dirname $0`
export TOP=`dirname ${DIR}`

eval `find ${TOP} | grep BuildFile | grep 'xml$' | awk -v DIR=${DIR} '{print DIR"/cleanupBuildFile.sh "$0" ;"}'`
