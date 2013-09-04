#include <iostream>
#include <math.h>

#include "NtuTool/Read/test/stubs/EDMSimpleAnalyzer.h"
#include "NtuTool/Common/interface/Math.h"


static EDMSimpleAnalyzer ta;


EDMSimpleAnalyzer::EDMSimpleAnalyzer() {
  std::cout << "new EDMSimpleAnalyzer" << std::endl;
// additional info
// set according to .py used when writing
  treeName = "Events";
  setProcessName( "PIPPO" );
  setProducerName( "testSimpleEDMNtuple" );
}


EDMSimpleAnalyzer::~EDMSimpleAnalyzer() {
}


void EDMSimpleAnalyzer::beginJob() {
  std::cout << "EDMSimpleAnalyzer::beginJob" << std::endl;
  return;
}


void EDMSimpleAnalyzer::book() {
  // putting "autoSavedObject" in front of the histo creation 
  // it's automatically marked for saving on file
  autoSavedObject =
  hist = new TH1F( "hist", "hist", 10, -2.5, 2.5 );
  return;
}


void EDMSimpleAnalyzer::reset() {
  autoReset();
  return;
}


void EDMSimpleAnalyzer::beginFile() {
  std::cout << "open file " << currentFile << std::endl;
  return;
}


bool EDMSimpleAnalyzer::analyze( int entry, int event_file, int event_tot ) {

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

  hist->Fill( ( ( i_run % 10 ) / 2.0 ) - 2.5 );

  std::cout << " --------------------------- " << std::endl;

  return true;

}


void EDMSimpleAnalyzer::endFile() {
  std::cout << "close file " << currentFile << std::endl;
  return;
}


void EDMSimpleAnalyzer::endJob() {
  std::cout << "EDMSimpleAnalyzer::endJob" << std::endl;
  return;
}


void EDMSimpleAnalyzer::plot() {
  hist->Draw();
  return;
}


// "save" function not needed for auto-saved histos,
// see book() function
//void EDMSimpleAnalyzer::save() {
//  std::cout << "save histos" << std::endl;
//  hist->Write();
//  return;
//}

