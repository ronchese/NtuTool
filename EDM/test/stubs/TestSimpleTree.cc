#include "NtuTool/EDM/test/stubs/TestSimpleTree.h"

#include "FWCore/Framework/interface/MakerMacros.h"

#include "TFile.h"
#include "TTree.h"

#include <iostream>

TestSimpleTree::TestSimpleTree( const edm::ParameterSet& cfg ) {

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
  tree->Branch(  "iVec", & i_vec,       1000, 99 );
  tree->Branch(  "fVpt", & f_vpt,       1000, 99 );
  tree->Branch(  "nArr", & n_arr,       "nArr/I" );
  tree->Branch(  "iArr",   i_arr, "iArr[nArr]/I" );

}

TestSimpleTree::~TestSimpleTree() {
}

void TestSimpleTree::beginJob() {
  std::cout << "TestSimpleTree::beginJob" << std::endl;
  return;
}

void TestSimpleTree::analyze( const edm::Event &evt,
                              const edm::EventSetup& es ) {

  std::cout << "event "
            << evt.id().run() << " / "
            << evt.id().event() << std::endl;

  // reset variables
  i_vec.clear();
  f_vpt->clear();
  int* iptr = i_arr + n_arr;
  while ( iptr-- > i_arr ) *iptr = 0;
  n_arr = 0;

  // set variables
  setData( evt.id().run() );

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
  i_vec.push_back( iRun );
  i_vec.push_back( iRun % 100 );
  f_vpt->push_back( 1000000 + iRun );
  f_vpt->push_back( 1000000 + iRun % 100 );

  i_arr[n_arr++] = iRun;
  i_arr[n_arr++] = iRun % 100;
  if ( ( iRun % 100 ) > 60 ) i_arr[n_arr++] = iRun % 10000;

  return;

}

#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_FWK_MODULE( TestSimpleTree );
