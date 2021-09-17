#ifndef NtuTool_Common_LegacyTree_h
#define NtuTool_Common_LegacyTree_h

#include "TFile.h"
#include "TTree.h"

#include "NtuTool/Common/test/SimpleData.h"

// This example code does NOT use NtuTool functionalities, it's just a 
// reference to show how code handling ntuples changes using NtuTool:
// see "SimpleNtuple.h" for a comparison.

// This class encapsulate the calls to "Branch" (when writing ntuples)
// and SetBranchAddress (when reading ntuples).
// This is done to allow reusage in different contexts, i.e. in the
// standalone programs "simpleLegacyWrite.cc" and "simpleLegacyRead.cc" and
// in the edm module "SimpleLegacyModule" (in NtuTool/EDM/test); normally
// the code contained in this could stay directly in the classes inheriting
// from it.
// Different calls are used when writing/reading ntuples, those calls can 
// be unified using the NtuTool classes (see "SimpleNtuple" class).
// A function is also included to reset the ntuple content; that operation
// can be done automatically when using the NtuTool classes
// (see "SimpleNtuple" class).
// Data are encapsulated in another class ("SimpleData") to allow reusage
// in a different context too, i.e. in examples using NtuTool (SimpleNtuple.h),
// normally data could stay inside this class.

class LegacyTree: public virtual SimpleData {

 public:
  LegacyTree() {
    n_arr = n_max; // array length set at maximum to reset all elements
                   // at zero at the first call to "resetNtupleContent()"
  }
  ~LegacyTree() override {
  }

  // Create branches when writing ntuple
  void setBranchesWrite( TTree* tree ) {
    // define branches
    b_i_run = tree->Branch( "iRun", &i_run, "iRun/i"       ); // a number
    b_i_evt = tree->Branch( "iEvt", &i_evt, "iEvt/i"       ); // a number
    b_n_arr = tree->Branch( "nArr", &n_arr, "nArr/i"       ); // an array
    b_i_arr = tree->Branch( "iArr",  i_arr, "iArr[nArr]/I" ); // with its size
    b_i_vec = tree->Branch( "iVec", &i_vec, 1000, 99 ); // a vector (in stack)
                                  // i_vec is a std::vector  :
                                  // address by pointer
    b_f_vpt = tree->Branch( "fVpt", &f_vpt, 1000, 99 ); // a vector (in heap)
                                  // f_vpt is a std::vector* :
                                  // address by pointer to pointer
    b_i_ran = tree->Branch( "iRan", &i_ran, "iRan/I"       );
    b_s_ran = tree->Branch( "sRan", &s_ran, "sRan/S"       );
    b_f_ran = tree->Branch( "fRan", &f_ran, "fRan/F"       );
    b_d_ran = tree->Branch( "dRan", &d_ran, "dRan/D"       );
    return;
  }

  // Create branches when reading ntuple
  void setBranchesRead( TTree* tree ) {
    // define branches
    tree->SetBranchAddress( "iRun", &i_run, &b_i_run );
    tree->SetBranchAddress( "iEvt", &i_evt, &b_i_evt );
    tree->SetBranchAddress( "nArr", &n_arr, &b_n_arr );
    tree->SetBranchAddress( "iArr",  i_arr, &b_i_arr );
    // "i_vec" is a std::vector, not a pointer, and a pointer to pointer
    // is needed: a pointer is then declared and the pointer to it is taken.
    // A static pointer is used to keep it in memory after this function
    // is done.
    static std::vector<int>* i_vpt = &i_vec;
    tree->SetBranchAddress( "iVec", &i_vpt, &b_i_vec );
    tree->SetBranchAddress( "fVpt", &f_vpt, &b_f_vpt );
    tree->SetBranchAddress( "iRan", &i_ran, &b_i_ran );
    tree->SetBranchAddress( "sRan", &s_ran, &b_s_ran );
    tree->SetBranchAddress( "fRan", &f_ran, &b_f_ran );
    tree->SetBranchAddress( "dRan", &d_ran, &b_d_ran );
    return;
  }

  // Reset all data at zero and clear vectors, should it be required for
  // any reason. This can be done
  void resetNtupleContent() {
     // reset ntuple content
    int* iptr = i_arr + n_arr;
    while ( iptr-- > i_arr ) *iptr = 0;
    n_arr = 0;
    i_vec.clear();
    f_vpt->clear();
    // set variables
 }

 private:

  LegacyTree           ( const LegacyTree& x ) = delete;
  LegacyTree& operator=( const LegacyTree& x ) = delete;

};

#endif // NtuTool_Common_LegacyTree_h

