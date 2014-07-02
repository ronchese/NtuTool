#include "NtuTool/EDM/test/stubs/SimpleEDMWriter.h"

#include "FWCore/Framework/interface/MakerMacros.h"

#include <iostream>

SimpleEDMWriter::SimpleEDMWriter( const edm::ParameterSet& ps ) {
  // opening ROOT file is no more necessary
  //
  // use local function "initWrite" (defined in the tool)
  // to define the tree structure
  initWrite();
}

SimpleEDMWriter::~SimpleEDMWriter() {
}

void SimpleEDMWriter::beginJob() {
  std::cout << "SimpleEDMWriter::beginJob" << std::endl;
  return;
}

bool SimpleEDMWriter::fill( const edm::Event& ev,
                            const edm::EventSetup& es ) {
  std::cout << "event "
            << ev.id().run() << " / "
            << ev.id().event() << std::endl;
  // all variables are automatically reset by the tool
  // without need of any action from the user
  //
  // the creation of all auto_ptrs is automatically performed by the tool
  //
  // the function (by the user) to encapsulate operations to set variables
  // is exactly the same
  setData( ev.id().run() );
  // the calls to "evt.put(...)" are automatically performed by the tool
  return true;
}

void SimpleEDMWriter::endJob() {
  std::cout << "SimpleEDMWriter::endJob" << std::endl;
  // no operation is required at the end of the job
  return;
}

void SimpleEDMWriter::setData( unsigned int iRun ) {

  i_run = iRun;

  int n = 4 + lround( random() * 4.0 / RAND_MAX );

  while ( n-- ) {
    int i = 15 + lround( random() * 10.0 / RAND_MAX );
    i_vec.push_back( i );
    float x = 6.0 - ( 8.0 * sqrt( -log( 1.0 - ( random() * 1.0 /
                                                RAND_MAX ) ) ) *
                            cos( 2.0 * M_PI * ( random() * 1.0 /
                                                RAND_MAX ) ) );
    f_vpt->push_back( x );
    i_arr[n_arr++] = i % 7;
  }

  return;

}

DEFINE_FWK_MODULE( SimpleEDMWriter );
