#include <iostream>

#include "NtuTool/EDM/interface/NANOTreeWriter.h"
#include "NtuTool/EDM/interface/NANOTypeWriterManager.h"
#include "NtuTool/EDM/interface/NANOTableHandler.h"
#include "NtuTool/Read/interface/NANOHandler.h"
#include "NtuTool/Common/interface/DataHandlerManager.h"
#include "NtuTool/Common/interface/DataHandler.h"
#include "NtuTool/Common/interface/BranchInterface.h"

#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/NanoAOD/interface/FlatTable.h"

#include <string>
#include <iostream>

bool NANOTreeWriter::select = true;


NANOTreeWriter::NANOTreeWriter() {
  handlerManager = new NANOTypeWriterManager;
}


NANOTreeWriter::~NANOTreeWriter() {
}


void NANOTreeWriter::beginJob() {
  return;
}


void NANOTreeWriter::endJob() {
  return;
}


void NANOTreeWriter::beginRun( const edm::Run& r, const edm::EventSetup& es ) {
  return;
}


void NANOTreeWriter::endRun( const edm::Run& r, const edm::EventSetup& es ) {
  return;
}


void NANOTreeWriter::initWrite() {

  branch_iterator iter = treeBegin();
  branch_iterator iend = treeEnd();
  while ( iter != iend ) {
    branch_desc* bDesc = *iter++;
    DataHandler* handler = handlerManager->setHandler( bDesc );
    bDesc->dataHandler = handler;
    void* p = bDesc->dataPtr;
    handler->setAuxPtr( bDesc->ppRef ? *BranchInterface::pPtr( p ) : p,
			handlerManager );
    NANOTableHandler* nanoHandler = dynamic_cast<NANOTableHandler*>( handler );
    nanoHMap[handler] = nanoHandler;
    if ( bDesc->firstBranch == nullptr ) nanoHandler->produces( this,
                BranchInterfaceData::getInfo( bDesc,
                NANOHandler::nanoTableName, *bDesc->branchName ) );
  }

  return;

}


void NANOTreeWriter::produce( edm::Event& ev, const edm::EventSetup& es ) {
  reset();
  select = fill( ev, es );
  put( ev );
  return;
}


bool NANOTreeWriter::fill( const edm::Event& ev, const edm::EventSetup& es ) {
// default analysis - dummy
  return true;
}


void NANOTreeWriter::put( edm::Event& ev ) {
  void* table = nullptr;
  branch_iterator iter = treeBegin();
  branch_iterator iend = treeEnd();
  std::string tName;
  while ( iter != iend ) {
    const branch_desc* bDesc = *iter++;
    DataHandler* handler = bDesc->dataHandler;
    if ( bDesc->firstBranch == nullptr ) {
      table = nullptr;
      tName = BranchInterfaceData::getInfo( bDesc,
              NANOHandler::nanoTableName, *bDesc->branchName );
    }
    table = nanoHMap[handler]->put( ev, bDesc, table );
    if ( bDesc->nextBranch == nullptr ) {
      std::unique_ptr<nanoaod::FlatTable> u(
                      static_cast<nanoaod::FlatTable*>( table ) );
      ev.put( std::move( u ), tName );
    }
  }
  return;
}


