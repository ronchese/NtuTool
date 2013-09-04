#include <iostream>

#include "NtuTool/EDM/interface/EDMTreeWriter.h"
#include "NtuTool/EDM/interface/EDMTypeWriterManager.h"
#include "NtuTool/Common/interface/DataHandlerManager.h"
#include "NtuTool/Common/interface/DataHandler.h"

#include <string>

EDMTreeWriter::EDMTreeWriter() {
  handlerManager = new EDMTypeWriterManager;
}


EDMTreeWriter::~EDMTreeWriter() {
}


void EDMTreeWriter::beginJob() {
  return;
}


void EDMTreeWriter::endJob() {
  return;
}


void EDMTreeWriter::beginRun( edm::Run& r, edm::EventSetup const & es ) {
  return;
}


void EDMTreeWriter::endRun( edm::Run& r, edm::EventSetup const & es ) {
  return;
}


void EDMTreeWriter::initWrite() {

  branch_iterator iter = treeBegin();
  branch_iterator iend = treeEnd();
  while ( iter != iend ) {
    branch_desc* bDesc = *iter++;
    DataHandler* handler = handlerManager->setHandler( bDesc,
                                                       bDesc->branchData );
    bDesc->dataHandler = handler;
    handler->setAuxPtr( bDesc->dataPtr, handlerManager );
    if ( bDesc->ppRef ) *reinterpret_cast<void**>( bDesc->dataPtr ) = 0;
    handler->produces( this );
  }

  return;

}


void EDMTreeWriter::produce( edm::Event& ev, const edm::EventSetup& es ) {
  autoReset();
  build();
  fill( ev, es );
  put( ev );
  return;
}


void EDMTreeWriter::fill( edm::Event& ev, const edm::EventSetup& es ) {
// default analysis - dummy
  return;
}


void EDMTreeWriter::build() {
  branch_iterator iter = treeBegin();
  branch_iterator iend = treeEnd();
  while ( iter != iend ) {
    branch_desc* bDesc = *iter++;
    DataHandler* handler = bDesc->dataHandler;
    if ( bDesc->ppRef ) handler->buildPtr( bDesc->dataPtr );
  }
  return;
}


void EDMTreeWriter::put( edm::Event& ev ) {
  branch_iterator iter = treeBegin();
  branch_iterator iend = treeEnd();
  while ( iter != iend ) {
    const branch_desc* bDesc = *iter++;
    DataHandler* handler = bDesc->dataHandler;
    handler->put( ev, bDesc->dataPtr );
    if ( bDesc->ppRef ) handler->clearPtr( bDesc->dataPtr );
  }
  return;
}


