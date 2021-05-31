#include "NtuTool/Common/test/SimpleAnalyze.h"

#include "TFile.h"
#include "TTree.h"

#include <string>
#include <iostream>

using namespace std;

// This class is just to have direct access to data structure members
class SimpleLegacyReader: public SimpleAnalyze {
 public:
  // Data link to ntuple branches
  void setBranches( TTree* tree ) {
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
//    n_arr = n_max; // array length set at maximum to reset all elements
//                   // at zero at the first call to "setAndFill(...)"
    return;
  }
  // Histograms creation
  void book() {
    TObject* dum = nullptr; // dummy pointer to fake an "autoSavedObject"
    createHisto( dum );     // create histograms (in SimpleAnalyze)
  }
  // Data analysis
  void analyze( TTree* tree, int i ) {
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
  reader.setBranches( tree );

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

