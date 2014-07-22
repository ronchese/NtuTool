#include <iostream>
#include <math.h>

#include "NtuTool/Read/test/stubs/SimpleEDMAnalyzer.h"
#include "NtuTool/Common/interface/Math.h"


static SimpleEDMAnalyzer ta;


SimpleEDMAnalyzer::SimpleEDMAnalyzer() {
  std::cout << "new SimpleEDMAnalyzer" << std::endl;
// additional info
// set according to .py used when writing
  setProcessName( "PIPPO" );
  setProducerName( "simpleEDMWriter" );
}


SimpleEDMAnalyzer::~SimpleEDMAnalyzer() {
}


void SimpleEDMAnalyzer::beginJob() {
  std::cout << "SimpleEDMAnalyzer::beginJob" << std::endl;
  return;
}


void SimpleEDMAnalyzer::book() {

  // putting "autoSavedObject" in front of the histo creation 
  // it's automatically marked for saving on file

  autoSavedObject =
  hist = new TH1F( "hist", "hist", 10, -2.5, 2.5 );

  autoSavedObject =
  gDirectory->mkdir( "subd" );
  autoSavedObject =
  hisd = new TH1F( "hisd", "hisd", 25, -50.0, 50.0 );

  autoSavedObject =
  gDirectory->GetDirectory( ".." );
  autoSavedObject =
  hisc = new TH1F( "hisc", "hisc",  7, -0.5, 6.5 );

  return;

}


void SimpleEDMAnalyzer::beginFile() {
  std::cout << "open file " << currentFile << std::endl;
  return;
}


void SimpleEDMAnalyzer::reset() {
  // automatic reset
  autoReset();
  return;
}

/*
// function to get current entry from ntuple, to be overridden if
// a "preliminary analysis" is to be performed over part of events
void GenericSimpleAnalyzer::getEntry( int ientry ) {
  // read all events by default
  currentTree->GetEntry( ientry );
}
*/

bool SimpleEDMAnalyzer::analyze( int entry, int event_file, int event_tot ) {

  std::cout << " +++++++++++++++++++++++++++ " << std::endl;
  std::cout << currentFile << std::endl;

  std::cout << "run: "
            <<  i_run << std::endl;

  int isize = i_vec.size();
  std::cout << "vec size " << isize << std::endl;
  int ipos = 0;
  std::vector<int>::const_iterator i_iter = i_vec.begin();
  std::vector<int>::const_iterator i_iend = i_vec.end();
  while ( i_iter != i_iend ) std::cout << ipos++ << " -> "
                                       << *i_iter++ << std::endl;

  int fsize = f_vpt->size();
  std::cout << "vpt size " << fsize << std::endl;
  int fpos = 0;
  std::vector<float>::const_iterator f_iter = f_vpt->begin();
  std::vector<float>::const_iterator f_iend = f_vpt->end();
  while ( f_iter != f_iend ) std::cout << fpos++ << " -> "
                                       << *f_iter++ << std::endl;

  std::cout << "array length " << n_arr << std::endl;
  int j = 0;
  while ( j < n_arr ) std::cout << i_arr[j++] << " ";
  std::cout << std::endl;

  int n;
  int i;

  n = i_vec.size();
  for ( i = 0; i < n; ++i ) hist->Fill( i_vec[i] );
  n = f_vpt->size();
  for ( i = 0; i < n; ++i ) hisd->Fill( f_vpt->at( i ) );
  n = n_arr;
  for ( i = 0; i < n; ++i ) hisc->Fill( i_arr[i] );

  std::cout << " --------------------------- " << std::endl;

  return true;

}


void SimpleEDMAnalyzer::endFile() {
  std::cout << "close file " << currentFile << std::endl;
  return;
}


void SimpleEDMAnalyzer::endJob() {
  std::cout << "SimpleEDMAnalyzer::endJob" << std::endl;
  return;
}


void SimpleEDMAnalyzer::plot() {
  hist->Draw();
  return;
}


// "save" function not needed for auto-saved histos,
// see book() function
//void SimpleEDMAnalyzer::save() {
//  std::cout << "save histos" << std::endl;
//  hist->Write();
//  return;
//}

