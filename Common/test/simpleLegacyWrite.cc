#include "NtuTool/Common/test/LegacyTree.h"
#include "NtuTool/Common/test/SimpleFill.h"

#include "TFile.h"
#include "TTree.h"

#include <iostream>

using namespace std;

// This class do some assembling of parts from other classes.
// Usually values can be assigned to ntuple data directly in this class;
// here these operations are encapsulated in a different class (SimpleFill)
// to allow its reusage in different contexts, i.e. the example that uses
// NtuTool (simpleNtupleWrite.cc).
class SimpleLegacyWriter: public LegacyTree,
                          public SimpleFill {
 public:
  void setAndFill( int n, TTree* tree ) {
    resetNtupleContent();      // reset ntuple content  (in LegacyTree )
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
  writer.setBranchesWrite( tree );

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

