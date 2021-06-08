#include "NtuTool/Common/test/SimpleNtuple.h"
#include "NtuTool/Common/test/SimpleAnalyze.h"
#include "NtuTool/Common/interface/TreeReader.h"
#include "NtuTool/Common/interface/TreeFilter.h"
#include "NtuTool/Common/interface/TreeStandardAnalyzer.h"

#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"

#include <iostream>

using namespace std;

// This example code actually uses NtuTool functionalities to skim the ntuple.

// This class do some assembling of parts from other classes.
// Usually histograms can be declared and created directly in this class,
// as well as doing the analysis; here these operations are encapsulated
// in another class (SimpleAnalyze) to allow its reusage in a different
// context, i.e. the example that does not use NtuTool (simpleLegacyRead.cc).
// The important point here is inheriting from both "SimpleNtuple", with the
// ntuple definition from the user, and "TreeReader", from the library taking
// care of the actual calls to "TTree::SetBranchAddress".
class SimpleNtupleFilter: public SimpleNtuple,  // ntuple definition,
                          public SimpleAnalyze, // analyze data and fill histos
                          public TreeFilter,    // create a skim ntuple
                          public TreeReader {   // create branches and
                                                //   read ntuple from file

 public:

  // The following code is almost identical to the one in
  // NtuTool/Common/test/simpleNtupleRead.cc, look there for comments.
  // Any difference is well marked to be easily spotted.

  SimpleNtupleFilter() {
    setUserParameter<int>( "iCut", 18 );
    // === SPECIFIC INSTRUCTIONS ===
    // additional info to set default name and mode for skimmed ntuple,
    // can be overridden at runtime in the command line
    setUserParameter( "filterName", "simple_filter.root" );
    setUserParameter( "filterMode", "CREATE" );
  }

  // Operations to be done at the execution begin
  void beginJob() override {
    setup();
    iCut = getUserParameter<int>( "iCut" );
    // === SPECIFIC INSTRUCTIONS ===
    // open file for skimmed ntuple
    TDirectory* currentDir = gDirectory;
    filterFile = new TFile( getUserParameter( "filterName" ).c_str(),
                            getUserParameter( "filterMode" ).c_str() );
    // === SPECIFIC INSTRUCTIONS ===
    // setup skimmed ntuple dropping a branch
    dropBranch( "fVpt" );
    initWSkim( filterFile );
    // === SPECIFIC INSTRUCTIONS ===
    // restore ROOT environment
    currentDir->cd();
    return;
  }

  // Histograms creation
  void book() override {
    createHisto( autoSavedObject );
    return;
  }

  // An optional preliminary processing can be implemented to read only part
  // of the data and looking at that choose if read the full event or skip it;
  // see simpleNtupleRead.cc for an example.

  // Data analysis
  bool analyze( int entry, int event_file, int event_tot ) override {
    fillHisto();
    // === SPECIFIC INSTRUCTIONS ===
    // skim events
    bool select = vCut( iCut ); // select events with at least one element
                                // in "i_arr" larger than "iCut"
    if ( select ) fillSkim();
    return select;
  }

  // Operations to be done at the execution end
  void endJob() override {
    // === SPECIFIC INSTRUCTIONS ===
    // close skim ntuple and file
    closeSkim();
    return;
  }

  // An optional function to draw some plots at the execution end can be
  // implemented; see simpleNtupleRead.cc for an example.
  // See simpleNtupleRead.cc also about histogram saving.

  // Parameters used in the (pre)selection and analysis
  // See (set/get)UserParameter above for additional informations.
  int iCut;

  // === SPECIFIC INSTRUCTIONS ===
  // ROOT file for skimmed ntuple
  TFile* filterFile;

};

// It's essential to instantiate a global "SimpleNtupleReader" object,
// so that it's created before the execution starts; it's then retrieved
// and used inside the library according to the needs.
static SimpleNtupleFilter filter;

int main( int argc, char* argv[] ) {

  // Create an analyzer object
  cout << "create analyzer" << endl;
  TreeStandardAnalyzer* tsa = TreeStandardAnalyzer::getInstance();

  // Run the analyzer
  tsa->run( argc, argv );

  return 0;

}

