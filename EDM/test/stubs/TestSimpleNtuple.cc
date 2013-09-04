#include "FWCore/Framework/interface/MakerMacros.h"

#include "NtuTool/EDM/test/stubs/TestSimpleNtuple.h"

#include "TFile.h"

#include <iostream>

TestSimpleNtuple::TestSimpleNtuple( const edm::ParameterSet& cfg ) {
  // open output ROOT file
  file = new TFile( "ntuple_base.root", "CREATE" );
  // use local function "initWrite" (defined in the tool)
  // to define the tree structure
  initWrite( file );
}

TestSimpleNtuple::~TestSimpleNtuple() {
}

void TestSimpleNtuple::beginJob() {
  std::cout << "TestSimpleNtuple::beginJob" << std::endl;
  return;
}

void TestSimpleNtuple::analyze( const edm::Event &evt,
                                const edm::EventSetup& es ) {
  std::cout << "event "
            << evt.id().run() << " / "
            << evt.id().event() << std::endl;
  // function provided by the tool to automatically reset all variables
  autoReset();
  // set variables
  setData( evt.id().run() );
  // function provided by the tool to actually fill the tree
  fill();
  return;
}

void TestSimpleNtuple::endJob() {
  std::cout << "TestSimpleNtuple::endJob" << std::endl;
  // function provided by the tool to close the tree
  close();
  // close the file
  file->Close();
  return;
}

void TestSimpleNtuple::setData( unsigned int iRun ) {

  i_run = iRun;
  i_vec.push_back( iRun );
  i_vec.push_back( iRun % 100 );
  f_vpt->push_back( 1000000 + iRun );
  f_vpt->push_back( 1000000 + iRun % 100 );

  i_arr[n_arr++] = iRun;
  i_arr[n_arr++] = iRun % 100;
  if ( ( iRun % 100 ) > 60 ) i_arr[n_arr++] = iRun % 10000;

  return;

}

DEFINE_FWK_MODULE( TestSimpleNtuple );
