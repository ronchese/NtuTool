#ifndef NtuTool_Common_SimpleData_h
#define NtuTool_Common_SimpleData_h

#include "TBranch.h"

#include <vector>

// A simple data structure, to contain random numbers

class SimpleData {

 public:

  SimpleData() {
    n_max = 10;                     // max array length
    i_arr = new int[n_max];         // array  creation
    f_vpt = new std::vector<float>; // vector creation (in the heap)
  }
  virtual ~SimpleData() {
    delete[] i_arr;
    delete f_vpt;
  }

 protected:

  // Data declarations

  unsigned int i_run;        // a number
  unsigned int i_evt;        // a number

  unsigned int n_max;
  unsigned int n_arr;
  int* i_arr;                // an array with "n_arr" (up to "n_max") elements

  std::vector<int>    i_vec; // a vector (in the stack)
  std::vector<float>* f_vpt; // a vector (in the heap)

  int    i_ran;
  short  s_ran;
  float  f_ran;
  double d_ran;

  // List of branches

  TBranch* b_i_run;
  TBranch* b_i_evt;
  TBranch* b_n_arr;
  TBranch* b_i_arr;
  TBranch* b_i_vec;
  TBranch* b_f_vpt;

  TBranch* b_i_ran;
  TBranch* b_s_ran;
  TBranch* b_f_ran;
  TBranch* b_d_ran;

 private:

  SimpleData           ( const SimpleData& x ) = delete;
  SimpleData& operator=( const SimpleData& x ) = delete;

};

#endif // NtuTool_Common_SimpleData_h

