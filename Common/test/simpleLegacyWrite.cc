#include "NtuTool/Common/test/SimpleFill.h"

#include "TFile.h"
#include "TTree.h"

#include <iostream>

using namespace std;

// This class is just to have direct access to data structure members
class SimpleLegacyWriter: public SimpleFill {
 public:
  void setBranches( TTree* tree ) {
    // define branches
    b_i_run = tree->Branch( "iRun", &i_run,       "iRun/i" ); // a number
    b_i_evt = tree->Branch( "iEvt", &i_evt,       "iEvt/i" ); // a number
    b_n_arr = tree->Branch( "nArr", &n_arr,       "nArr/i" ); // an array
    b_i_arr = tree->Branch( "iArr",  i_arr, "iArr[nArr]/I" ); // with its size
    b_i_vec = tree->Branch( "iVec", &i_vec, 1000, 99 ); // a vector (in stack)
                                  // i_vec is a std::vector  :
                                  // address by pointer
    b_f_vpt = tree->Branch( "fVpt", &f_vpt, 1000, 99 ); // a vector (in heap)
                                  // f_vpt is a std::vector* :
                                  // address by pointer to pointer
    n_arr = n_max; // array length set at maximum to reset all elements
                   // at zero at the first call to "setAndFill(...)"
    return;
  }
  void setAndFill( int n, TTree* tree ) {
    // reset ntuple content
    int* iptr = i_arr + n_arr;
    while ( iptr-- > i_arr ) *iptr = 0;
    n_arr = 0;
    i_vec.clear();
    f_vpt->clear();
    // set variables
    setData( ( n / 1000 ) + 1, // assign values to data (in SimpleFill )
             ( n % 1000 ) + 1 );
    // actually fill the tree
    tree->Fill();
    return;
  }
};

int main() {

  // create a writer object
  cout << "create writer" << endl;
  SimpleLegacyWriter writer;

  // open output ROOT file
  cout << "open TFile" << endl;
  TFile* file = new TFile( "simple_tree.root", "CREATE" );

  // create tree
  cout << "create tree" << endl;
  TTree* tree = new TTree( "simpleNtuple", "simpleNtuple" );

  // create branches
  cout << "create branches" << endl;
  writer.setBranches( tree );

  // event loop
  cout << "event loop" << endl;
  int n = 10000;
  int i;
  for ( i = 0; i < n; ++i ) writer.setAndFill( i, tree );

  // save TTree
  cout << "save ntuple" << endl;
  tree->Write();

  // close TFile
  cout << "close TFile" << endl;
  delete file;

  return 0;

}

