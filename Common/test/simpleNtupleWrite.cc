#include "NtuTool/Common/test/SimpleNtuple.h"
#include "NtuTool/Common/test/SimpleFill.h"
#include "NtuTool/Common/interface/TreeWriter.h"

#include "TFile.h"
#include "TTree.h"

#include <iostream>

using namespace std;

// This example code actually uses NtuTool functionalities:
// see "simpleLegacyWrite.cc" for a comparison.

// This class is just to assemble parts from other classes.
// Usually values can be assigned to ntuple data directly in this class;
// here these operations are encapsulated in another class (SimpleFill)
// to allow its reusage in a different context, i.e. the example that does not
// use NtuTool (simpleLegacyWrite.cc).
// The important point here is inheriting from both "SimpleNtuple", with the
// ntuple definition from the user, and "TreeWriter", from the library taking
// care of the actual calls to "TTree::Branch".
class SimpleNtupleWriter: public SimpleNtuple, // ntuple definition,
                          public SimpleFill,   // assign values to data,
                          public TreeWriter {  // create branches and
                                               //   write ntuple to file

 public:

  void setBranches( TFile* file ) {
    // Branches are created using the calls in the function "setup()"
    // and "initWrite()", in place of calling specific Branch
    // functions as in "simpleLegacyWrite.cc".
    setup();                   // define ntuple structure (in SimpleNtuple)
    initWrite( file );         // create tree branches    (in TreeWriter  )
    return;
  }

  void setAndFill( int n ) {
    reset();                   // reset ntuple content    (in SimpleNtuple)
    setData( ( n / 1000 ) + 1, // assign values to data   (in SimpleFill  )
             ( n % 1000 ) + 1 );
    fill();                    // write ntuple to file    (in TreeWriter  )
  }

};

int main() {

  // create a writer object
  cout << "create writer" << endl;
  SimpleNtupleWriter writer;

  // open output ROOT file
  cout << "open TFile" << endl;
  TFile* file = new TFile( "simple_ntuple.root", "CREATE" );

  // create tree and branches
  cout << "create tree and branches" << endl;
  writer.setBranches( file );

  // event loop
  cout << "event loop" << endl;
  int n = 10000;
  int i;
  for ( i = 0; i < n; ++i ) writer.setAndFill( i );

  // save TTree
  cout << "save ntuple" << endl;
  writer.close(); // save ntuple (in TreeWriter)

  // close TFile
  cout << "close TFile" << endl;
  delete file;

  return 0;

}

