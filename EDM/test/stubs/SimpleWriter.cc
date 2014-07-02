#include "FWCore/Framework/interface/MakerMacros.h"

#include "NtuTool/EDM/test/stubs/SimpleWriter.h"

#include "TFile.h"

#include <iostream>

SimpleWriter::SimpleWriter( const edm::ParameterSet& ps ) {
  // open output ROOT file
  file = new TFile( "ntuple_base.root", "CREATE" );
  // use local function "initWrite" (defined in the tool)
  // to define the tree structure
  initWrite( file );
}

SimpleWriter::~SimpleWriter() {
}

void SimpleWriter::beginJob() {
  std::cout << "SimpleWriter::beginJob" << std::endl;
  return;
}

void SimpleWriter::analyze( const edm::Event& ev,
                            const edm::EventSetup& es ) {
  std::cout << "event "
            << ev.id().run() << " / "
            << ev.id().event() << std::endl;
  // function provided by the tool to automatically reset all variables
  autoReset();
  // set variables
  setData( ev.id().run() );
  // function provided by the tool to actually fill the tree
  fill();
  return;
}

void SimpleWriter::endJob() {
  std::cout << "SimpleWriter::endJob" << std::endl;
  // function provided by the tool to close the tree
  close();
  // close the file
  file->Close();
  return;
}

void SimpleWriter::setData( unsigned int iRun ) {

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

DEFINE_FWK_MODULE( SimpleWriter );
