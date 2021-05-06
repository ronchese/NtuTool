#!/bin/sh

export DIR=`dirname $0`
export TOP=`dirname ${DIR}`

eval `find ${TOP} | grep -i NANO | grep -v removeNANO | awk '{print "rm "$0" ;"}'`

cat << END_OF_INPUT > ${TOP}/Read/interface/NANOHandler.h
#ifndef NANOHandler_H
#define NANOHandler_H
class NANOHandler {
 public:
  static const int nanoTableName;
  static const int nanoTableSize;
  static const int nanoBranchDoc;
};
#endif // NANOHandler_H
END_OF_INPUT

cat << END_OF_INPUT > ${TOP}/Read/src/NANOHandler.cc
#include "NtuTool/Read/interface/NANOHandler.h"
#include "NtuTool/Common/interface/BranchInterfaceData.h"

const int NANOHandler::nanoTableName = BranchInterfaceData::infoId(
                      "NANOTableName" );
const int NANOHandler::nanoTableSize = BranchInterfaceData::infoId(
                      "NANOTableSize" );
const int NANOHandler::nanoBranchDoc = BranchInterfaceData::infoId(
                      "NANOBranchDoc" );
END_OF_INPUT
