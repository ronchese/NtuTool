#ifndef SimpleNtuple_H
#define SimpleNtuple_H

#include "NtuTool/Common/interface/TreeWrapper.h"
#include <string>
#include <vector>

// The class with the tree definition must inherit from "TreeWrapper"

class SimpleNtuple: public virtual TreeWrapper {

 public:

  SimpleNtuple();
  virtual ~SimpleNtuple();

 protected:

  // Declaration of leaf types

  int i_run;                    // a number
  std::vector<int>    i_vec;    // a vector (in the stack)
  std::vector<float>* f_vpt;    // a vector (in the heap)

  int  n_max;
  int  n_arr;
  int* i_arr;                   // an array with "n_arr" elements

  // List of branches

  TBranch* b_i_run;
  TBranch* b_i_vec;
  TBranch* b_f_vpt;
  TBranch* b_n_arr;
  TBranch* b_i_arr;

 private:

  SimpleNtuple( const SimpleNtuple& td );
  SimpleNtuple& operator=( const SimpleNtuple& td );

};

#endif

