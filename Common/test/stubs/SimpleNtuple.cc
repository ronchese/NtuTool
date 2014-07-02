#include <iostream>

#include "NtuTool/Common/test/stubs/SimpleNtuple.h"

SimpleNtuple::SimpleNtuple() {

  // "treeName" must be assigned the name chosen by the user for the tree,
  // specifying the full path:
  // the TTree object and all the subfolders are created by the tool
  treeName = "ntuFolder/simpleNtuple";

  n_max =             // max array length
  n_arr = 10;         // array length set at maximum to allow auto reset
  i_arr = new int[n_max];         // array  creation
  f_vpt = new std::vector<float>; // vector creation (in the heap)

  // define branches
  // use local function "setBranch" (defined in the tool)
  // in place of ROOT "Branch" & "SetBranchAddress"

  setBranch(  "iRun", & i_run,       "iRun/I", &b_i_run );
  setBranch(  "nArr", & n_arr,       "nArr/I", &b_n_arr );
  setBranch(  "iArr",   i_arr, "iArr[nArr]/I", &b_i_arr );
  setBranch(  "iVec", & i_vec,       1000, 99, &b_i_vec ); // access by pointer
  setBranch(  "fVpt", & f_vpt,       1000, 99, &b_f_vpt ); // access by pointer
                                                           //        to pointer

}


SimpleNtuple::~SimpleNtuple() {
}


