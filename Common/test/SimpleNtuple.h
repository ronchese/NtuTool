#ifndef NtuTool_Common_SimpleNtuple_h
#define NtuTool_Common_SimpleNtuple_h

#include "NtuTool/Common/test/SimpleData.h"
#include "NtuTool/Common/interface/TreeWrapper.h"

// This example code actually uses NtuTool functionalities:
// see "LegacyTree.h" for a comparison.

// The class with the tree definition must inherit from "TreeWrapper", doing
// that it's possible define the ntuple structure just once (see "setup()"
// function) and use that both when writing the ntuple and/or analyzing it.
// Data are encapsulated in another class ("SimpleData") to allow reusage
// in a different context, i.e. in examples using NtuTool (LegacyTree.h),
// normally data could stay inside this class.

class SimpleNtuple: public virtual SimpleData,
                    public virtual TreeWrapper {

 public:

  SimpleNtuple() {
  }
  ~SimpleNtuple() override {
  }

  void setup( bool setName = true ) {
    if ( setName ) {
      // "treeName" must be assigned the name chosen by the user for the tree,
      // specifying the full path: the TTree object and all the subfolders
      // are created automatically.
      // The bool flag is used for contexts where the tree name is fixed
      // and cannot be modified by the user.
//      treeName = "ntuFolder/simpleNtuple";
      treeName = "simpleNtuple";
    }
    // Associate variables to branches, the same calls can be used 
    // when writing and reading ntuples in place of different calls 
    // to "Branch" (when writing) or "SetBranchAddress" (when reading).
    setBranch( "iRun", &i_run, "iRun/i"      , &b_i_run ); // a number
    setBranch( "iEvt", &i_evt, "iEvt/i"      , &b_i_evt ); // a number
    setBranch( "nArr", &n_arr, "nArr/i"      , &b_n_arr ); // an array
    setBranch( "iArr",  i_arr, "iArr[nArr]/I", &b_i_arr ); // with its size
    setBranch( "iVec", &i_vec, 1000, 99, &b_i_vec ); // a vector (in stack)
                     // i_vec is a std::vector  : address by pointer
    setBranch( "fVpt", &f_vpt, 1000, 99, &b_f_vpt ); // a vector (in heap)
                     // f_vpt is a std::vector* : address by pointer to pointer
    n_arr = n_max; // array length set at maximum to reset all elements
                   // at zero at the first call to "reset()"
    setBranch( "iRan", &i_ran, "iRan/I"      , &b_i_ran );
    setBranch( "sRan", &s_ran, "sRan/S"      , &b_s_ran );
    setBranch( "fRan", &f_ran, "fRan/F"      , &b_f_ran );
    setBranch( "dRan", &d_ran, "dRan/D"      , &b_d_ran );
    return;
  }

  void reset() override {
    autoReset(); // defined in TreeWrapper: it automatically
    return;      // reset to zero all numbers and clears all std::vectors
  }

 private:

  SimpleNtuple           ( const SimpleNtuple& x ) = delete;
  SimpleNtuple& operator=( const SimpleNtuple& x ) = delete;

};

#endif // NtuTool_Common_SimpleNtuple_h

