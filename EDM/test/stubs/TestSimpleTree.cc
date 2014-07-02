#include "NtuTool/EDM/test/stubs/TestSimpleTree.h"

#include "FWCore/Framework/interface/MakerMacros.h"

#include "TFile.h"
#include "TTree.h"

#include <iostream>

TestSimpleTree::TestSimpleTree( const edm::ParameterSet& ps ) {

  // open output ROOT file
  file = new TFile( "simple_tree.root", "CREATE" );

  // create tree
  tree = new TTree( "simpleNtuple", "simpleNtuple" );

  n_max =             // max array length
  n_arr = 10;         // array length set at maximum to allow reset
  i_arr = new int[n_max];         // array  creation
  f_vpt = new std::vector<float>; // vector creation (in the heap)

  // define branches

  tree->Branch(  "iRun", & i_run,       "iRun/I" );
  tree->Branch(  "nArr", & n_arr,       "nArr/I" );
  tree->Branch(  "iArr",   i_arr, "iArr[nArr]/I" );
  tree->Branch(  "iVec", & i_vec,       1000, 99 );
  tree->Branch(  "fVpt", & f_vpt,       1000, 99 );

}

TestSimpleTree::~TestSimpleTree() {
}

void TestSimpleTree::beginJob() {
  std::cout << "TestSimpleTree::beginJob" << std::endl;
  return;
}

void TestSimpleTree::analyze( const edm::Event& ev,
                              const edm::EventSetup& es ) {

  std::cout << "event "
            << ev.id().run() << " / "
            << ev.id().event() << std::endl;

  // reset variables
  i_vec.clear();
  f_vpt->clear();
  int* iptr = i_arr + n_arr;
  while ( iptr-- > i_arr ) *iptr = 0;
  n_arr = 0;

  // set variables
  setData( ev.id().run() );

  //
  file->cd();
  // actually fill the tree
  tree->Fill();

  return;

}

void TestSimpleTree::endJob() {
  std::cout << "TestSimpleTree::endJob" << std::endl;
  file->cd();
  // write the tree to file
  tree->Write();
  // close the file
  file->Close();
  return;
}

void TestSimpleTree::setData( unsigned int iRun ) {

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

#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_FWK_MODULE( TestSimpleTree );
