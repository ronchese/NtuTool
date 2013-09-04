#include "NtuTool/EDM/test/stubs/TestSimpleEDMNtuple.h"

#include "FWCore/Framework/interface/MakerMacros.h"

#include <iostream>

TestSimpleEDMNtuple::TestSimpleEDMNtuple( const edm::ParameterSet& cfg ) {
  // opening ROOT file is no more necessary
  //
  // use local function "initWrite" (defined in the tool)
  // to define the tree structure
  initWrite();
}

TestSimpleEDMNtuple::~TestSimpleEDMNtuple() {
}

void TestSimpleEDMNtuple::beginJob() {
  std::cout << "TestSimpleEDMNtuple::beginJob" << std::endl;
  return;
}

void TestSimpleEDMNtuple::fill( edm::Event &evt, const edm::EventSetup& es ) {
  std::cout << "event "
            << evt.id().run() << " / "
            << evt.id().event() << std::endl;
  // all variables are automatically reset by the tool
  // without need of any action from the user
  //
  // the creation of all auto_ptrs is automatically performed by the tool
  //
  // the function (by the user) to encapsulate operations to set variables
  // is exactly the same
  setData( evt.id().run() );
  // the calls to "evt.put(...)" are automatically performed by the tool
  return;
}

void TestSimpleEDMNtuple::endJob() {
  std::cout << "TestSimpleEDMNtuple::endJob" << std::endl;
  // no operation is required at the end of the job
  return;
}

void TestSimpleEDMNtuple::setData( unsigned int iRun ) {

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

DEFINE_FWK_MODULE( TestSimpleEDMNtuple );
