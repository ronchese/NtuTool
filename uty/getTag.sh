#!/bin/sh
export VERSION_FILE=`find ${CMSSW_BASE}/src | grep NtuTool | grep VERSION`
echo "V"`head -1 ${VERSION_FILE} | sed s/"\."/-/g`
