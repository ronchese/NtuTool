#include <iostream>

#include "NtuTool/EDM/interface/EDMTreeWriter.h"
#include "NtuTool/EDM/interface/EDMTypeWriterManager.h"
#include "NtuTool/EDM/interface/EDMDataHandler.h"
#include "NtuTool/Common/interface/DataHandlerManager.h"
#include "NtuTool/Common/interface/DataHandler.h"


bool EDMTreeWriter::select = true;


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


void EDMTreeWriter::beginRun( const edm::Run& r, const edm::EventSetup& es ) {
  return;
}


void EDMTreeWriter::endRun( const edm::Run& r, const edm::EventSetup& es ) {
  return;
}


void EDMTreeWriter::initWrite() {

  branch_iterator iter = treeBegin();
  branch_iterator iend = treeEnd();
  while ( iter != iend ) {
    branch_desc* bDesc = *iter++;
    DataHandler* handler = handlerManager->setHandler( bDesc );
    bDesc->dataHandler = handler;
    handler->setAuxPtr( bDesc->dataPtr, handlerManager );
    if ( bDesc->ppRef ) *pPtr( bDesc->dataPtr ) = nullptr;
    EDMDataHandler* edmHandler = dynamic_cast<EDMDataHandler*>( handler );
    edmHMap[handler] = edmHandler;
    edmHandler->produces( this );
  }

  return;

}


void EDMTreeWriter::produce( edm::Event& ev, const edm::EventSetup& es ) {
  reset();
  // "build" must be done before "fill" because pointer-to-pointer data
  // are updated with new dynamic addresses at each event and directly
  // used to build smart pointers, in place of copying to smart pointers
  // when writing to the event
  build();
  if ( ( select = fill( ev, es ) ) ) put( ev );
  return;
}


bool EDMTreeWriter::fill( const edm::Event& ev, const edm::EventSetup& es ) {
// default analysis - dummy
  return true;
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
    edmHMap[handler]->put( ev, bDesc->dataPtr );
    if ( bDesc->ppRef ) handler->clearPtr( bDesc->dataPtr );
  }
  return;
}


