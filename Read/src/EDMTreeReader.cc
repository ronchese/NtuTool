#include <iostream>

#include "NtuTool/Read/interface/EDMTreeReader.h"
#include "NtuTool/Read/interface/EDMTypeReaderManager.h"
#include "NtuTool/Common/interface/DataHandlerManager.h"
#include "NtuTool/Common/interface/DataHandler.h"
#include "NtuTool/Common/interface/DataConvert.h"

#include "TFile.h"
#include "TChain.h"


EDMTreeReader::EDMTreeReader() {
  treeName = "Events";
  handlerManager = new EDMTypeReaderManager;
}


EDMTreeReader::~EDMTreeReader() {
}


void EDMTreeReader::setProcessName( const std::string& name ) {
  processName = name;
  return;
}


void EDMTreeReader::setProducerName( const std::string& name ) {
  producerName = name;
  return;
}


void EDMTreeReader::initRead( TTree* tree ) {

  currentTree() = tree;
  currentTree()->SetMakeClass(1);

  branch_iterator iter = treeBegin();
  branch_iterator iend = treeEnd();
  while ( iter != iend ) {
    branch_desc* bDesc = *iter++;
    DataHandler* handler = handlerManager->setHandler( bDesc );
    bDesc->dataHandler = handler;
    void* dataPtr = ( bDesc->ppRef ? *pPtr( bDesc->dataPtr ) :
                                     handler->setAuxPtr( bDesc->dataPtr,
                                                         handlerManager ) );
    std::string branchName = handler->getType();
    if ( handler->getConv() == DataHandler::copyVector ) branchName += "s";
    branchName += "_";
    branchName += producerName;
    branchName += "_";
    branchName += handler->getName();
    branchName += "_";
    branchName += processName;
    branchName += ".obj";
    if ( bDesc->branchPtr == nullptr ) bDesc->branchPtr = new TBranch*;
    currentTree()->SetBranchAddress( branchName.c_str(), dataPtr,
                                     bDesc->branchPtr );
  }

  fillBranchMap();

  return;

}

