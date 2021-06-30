#include "NtuTool/Common/test/SimpleNtuple.h"
#include "NtuTool/Common/test/SimpleAnalyze.h"
#include "NtuTool/Common/interface/TreeStandardAnalyzer.h"
#include "NtuTool/Read/interface/EDMTreeReader.h"

#include "TFile.h"
#include "TTree.h"

#include <iostream>

using namespace std;

// This example code actually uses NtuTool functionalities:
// see "simpleLegacyRead.cc" for a comparison.

// This class do some assembling of parts from other classes.
// Usually histograms can be declared and created directly in this class,
// as well as doing the analysis; here these operations are encapsulated
// in another class (SimpleAnalyze) to allow its reusage in a different
// context, i.e. the example that does not use NtuTool (simpleLegacyRead.cc).
// The important point here is inheriting from both "SimpleNtuple", with the
// ntuple definition from the user, and "EDMTreeReader", from the library taking
// care of the actual calls to "TTree::SetBranchAddress".
class SimpleNtuEDMReader: public SimpleNtuple,  // ntuple definition,
                          public SimpleAnalyze, // analyze data and fill histos
                          public EDMTreeReader {// create branches and
                                                //   read ntuple from file
 public:

  // The following code is almost identical to the one in
  // NtuTool/Common/test/simpleNtupleRead.cc, look there for comments.
  // Any difference is well marked to be easily spotted.

  SimpleNtuEDMReader() {
    setUserParameter<unsigned int>( "nCut", 6 );
    // === SPECIFIC INSTRUCTIONS ===
    // additional info to be set according to cfg.py
    // used when writing the ntuple
    setProcessName( "ntuWriter" );
    setProducerName( "simpleNtuEDMModule" );
  }

  // Operations to be done at the execution begin
  void beginJob() override {
    setup( false ); // === SPECIFIC INSTRUCTIONS ===
                    // argument "false" used, to avoid overriding ntuple name,
                    // fixed in CMSSW
                    // (see NtuTool/Common/test/simpleNtupleRead.cc)
    nCut = getUserParameter<unsigned int>( "nCut" );
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
    return true;
  }

  // Operations to be done at the execution end
  void endJob() override {
    return;
  }

  // An optional function to draw some plots at the execution end can be
  // implemented; see simpleNtupleRead.cc for an example.
  // See simpleNtupleRead.cc also about histogram saving.

  // Parameters used in the (pre)selection and analysis
  // See (set/get)UserParameter above for additional informations.
  unsigned int nCut;

};

// It's essential to instantiate a global "SimpleNtuEDMReader" object,
// so that it's created before the execution starts; it's then retrieved
// and used inside the library according to the needs.
static SimpleNtuEDMReader reader;

int main( int argc, char* argv[] ) {

  // Create an analyzer object
  cout << "create analyzer" << endl;
  TreeStandardAnalyzer* tsa = TreeStandardAnalyzer::getInstance();

  // Run the analyzer
  tsa->run( argc, argv );

  return 0;

}

