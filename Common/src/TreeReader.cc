#include <iostream>

#include "NtuTool/Common/interface/TreeReader.h"
#include "NtuTool/Common/interface/DataHandler.h"
#include "NtuTool/Common/interface/TreeTypeManager.h"

#include "TFile.h"
#include "TChain.h"


TreeReader::TreeReader() {
  handlerManager = new TreeTypeManager;
  TreeReader*& readerInstance = instance();
  if ( readerInstance == nullptr ) readerInstance = this;
}


TreeReader::~TreeReader() {
}


TreeReader* TreeReader::getInstance() {
  return instance();
}


TChain* TreeReader::initRead( const std::string& file ) {

  currentFile = file;

  TChain* c = new TChain( treeName.c_str() );
  c->Add( file.c_str() );
  initRead( c );
  return c;

}


int TreeReader::loop( int evtmax, int evskip, int accmax, bool anaexe ) {

  // get number of events
  int evtnum = static_cast<int>( currentTree()->GetEntries() );

  // last required event
  if (   evtmax >  0       ) evtmax += evskip;
  if ( ( evtmax == 0     ) ||
       ( evtmax > evtnum ) ) evtmax  = evtnum;

  if ( !anaexe ) return evtnum;
  if (   accmax == 0       ) accmax  = evtnum + acceptedEvts;

  beginFile();
  int analyzedFile = 0;
  // loop over all events
  int ientry;
  for ( ientry = evskip; ientry < evtmax; ientry++ ) {
    if ( acceptedEvts >= accmax ) break;
    reset();
    // read tree
    readEvts++;
    if ( !getEntry( ientry ) ) continue;
    // preliminary data process
    process( ientry );
    // perform user analysis
    if ( analyze( ientry, analyzedFile++, analyzedEvts++ ) )
                                          acceptedEvts++;
  }
  endFile();

  return evtnum;

}


void TreeReader::initRead( TTree* tree ) {

  currentTree() = tree;
  currentTree()->SetMakeClass(1);

  branch_iterator iter = treeBegin();
  branch_iterator iend = treeEnd();
  while ( iter != iend ) {
    branch_desc* bDesc = *iter++;
    DataHandler* handler = handlerManager->setHandler( bDesc );
    bDesc->dataHandler = handler;
    void* dataPtr = nullptr;
    if ( ( bDesc->ppRef ) ||
         ( bDesc->splitLevel < 0 ) ) dataPtr =  bDesc->dataPtr;
    else                             dataPtr = &bDesc->dataPtr;
    if ( bDesc->splitLevel < 0 ) handler->setAuxPtr( bDesc->dataPtr,
                                                     handlerManager );
    currentTree()->SetBranchAddress( bDesc->branchName->c_str(), dataPtr,
                                     bDesc->branchPtr );
  }

  fillBranchMap();
  return;

}


bool TreeReader::getEntry( int ientry ) {
// default preliminary process - read all event
  currentTree()->GetEntry( ientry );
  return true;
}


TreeReader*& TreeReader::instance() {
  static TreeReader* readerInstance = nullptr;
  return readerInstance;
}

