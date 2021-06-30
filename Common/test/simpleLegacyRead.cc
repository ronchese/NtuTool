#include "NtuTool/Common/test/LegacyTree.h"
#include "NtuTool/Common/test/SimpleAnalyze.h"

#include "TFile.h"
#include "TTree.h"

#include <string>
#include <iostream>

using namespace std;

// This example code does NOT use NtuTool functionalities, it's just a 
// reference to show how code handling ntuples changes using NtuTool:
// see "simpleNtupleRead.cc" for a comparison.

// This class do some assembling of parts from other classes.
// Usually histograms can be declared and created directly in this class,
// as well as doing the analysis; here these operations are encapsulated
// in another class (SimpleAnalyze) to allow its reusage in a different
// context, i.e. the example that uses NtuTool (simpleNtupleRead.cc).
class SimpleLegacyReader: public LegacyTree,
                          public SimpleAnalyze {

 public:

  // Histograms creation
  void book() {
    TObject* dum = nullptr; // dummy pointer to fake an "autoSavedObject"
    createHisto( dum );     // create histograms (in SimpleAnalyze)
  }

  // Data analysis
  void analyze( TTree* tree, int i ) {
    resetNtupleContent();   // reset ntuple content, not strictly necessary
                            //                   (in LegacyTree   )
    tree->GetEntry( i );    // get an entry from ntuple file
    fillHisto();            // analyze data and
                            // fill histograms   (in SimpleAnalyze)
    return;
  }

  // Histogram saving
  void save( const std::string& name ) {
    // open output ROOT file
    cout << "open output TFile" << endl;
    TFile* hist = new TFile( name.c_str(), "CREATE" );
    // save histograms in output file
    hCount->Write();
    hContA->Write();
    hContI->Write();
    hContF->Write();
    hRandI->Write();
    hRandS->Write();
    hRandF->Write();
    hRandD->Write();
    // close output TFile
    cout << "close output TFile" << endl;
    delete hist;
    return;
  }

};

int main() {

  // create a reader object
  cout << "create reader" << endl;
  SimpleLegacyReader reader;

  // open input ROOT file
  cout << "open input TFile" << endl;
  TFile* file = new TFile( "simple_tree.root" );

  // create tree
  cout << "create tree" << endl;
  TTree* tree = dynamic_cast<TTree*>( file->Get( "simpleNtuple" ) );

  // create branches
  cout << "create branches" << endl;
  reader.setBranchesRead( tree );

  // create histograms
  reader.book();

  // event loop
  cout << "event loop" << endl;
  int n = tree->GetEntries();
  int i;
  for ( i = 0; i < n; ++i ) reader.analyze( tree, i );

  // save histograms
  cout << "save histograms" << endl;
  reader.save( "hist.root" );

  // close input TFile
  cout << "close input TFile" << endl;
  delete file;

  return 0;

}

