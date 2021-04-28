#include <iostream>

#include "NtuTool/Read/interface/EDMTreeReader.h"
#include "NtuTool/Read/interface/EDMTypeReaderManager.h"
#include "NtuTool/Common/interface/DataHandlerManager.h"
#include "NtuTool/Common/interface/DataHandler.h"
#include "NtuTool/Common/interface/DataConvert.h"

#include "TFile.h"
#include "TChain.h"


EDMTreeReader::EDMTreeReader() {
  handlerManager = new EDMTypeReaderManager;
}


EDMTreeReader::~EDMTreeReader() {
}


TChain* EDMTreeReader::initRead( const std::string& file ) {

  std::cout << "EDMTreeReader: " << file << std::endl;
  currentFile = file;

  TChain* c = new TChain( "Events" );
  c->Add( file.c_str() );
  initRead( c );
  return c;

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
    std::string branchName( handler->getBranchName( processName,
                                                    producerName ) );
    if ( bDesc->branchPtr == nullptr ) bDesc->branchPtr = new TBranch*;
    currentTree()->SetBranchAddress( branchName.c_str(), dataPtr,
                                     bDesc->branchPtr );
  }

  fillBranchMap();

  return;

}


void EDMTreeReader::process( int ientry ) {

  branch_iterator iter = treeBegin();
  branch_iterator iend = treeEnd();
  while ( iter != iend ) {
    const branch_desc* bDesc = *iter++;
    bDesc->dataHandler->process( bDesc->dataPtr );
  }

  return;

}


void EDMTreeReader::process( TBranch* b, int ientry ) {

  const std::map<TBranch*,branch_desc*>& bMap = branchMap();
  std::map<TBranch*,branch_desc*>::const_iterator iter = bMap.find( b );
  std::map<TBranch*,branch_desc*>::const_iterator iend = bMap.end();
  if ( iter != iend ) {
    const branch_desc* bDesc = iter->second;
    bDesc->dataHandler->process( bDesc->dataPtr );
  }

  return;

}

