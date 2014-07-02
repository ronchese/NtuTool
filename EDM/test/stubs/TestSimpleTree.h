#ifndef TestBaseNtuple_h
#define TestBaseNtuple_h

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

class TFile;
class TTree;
class TBranch;

class TestSimpleTree: public edm::EDAnalyzer {

 public:

  explicit TestSimpleTree( const edm::ParameterSet& ps );
  virtual ~TestSimpleTree();

  virtual void beginJob();
  virtual void analyze( const edm::Event& ev, const edm::EventSetup& es );
  virtual void endJob();

 private:

  TFile* file;
  TTree* tree;

  // Declaration of leaf types

  int i_run;                    // a number

  int  n_max;
  int  n_arr;
  int* i_arr;                   // an array with "n_arr" elements

  std::vector<int>    i_vec;    // a vector (in the stack)
  std::vector<float>* f_vpt;    // a vector (in the heap)

  // List of branches

  TBranch* b_i_run;
  TBranch* b_n_arr;
  TBranch* b_i_arr;
  TBranch* b_i_vec;
  TBranch* b_f_vpt;

  // function (by the user) to encapsulate operations to set variables
  void setData( unsigned int iRun );

};

#endif
