#include "NtuTool/Common/test/SimpleNtuple.h"
#include "NtuTool/Common/test/SimpleAnalyze.h"
#include "NtuTool/Common/interface/TreeReader.h"
#include "NtuTool/Common/interface/TreeStandardAnalyzer.h"

#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"

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
// ntuple definition from the user, and "TreeReader", from the library taking
// care of the actual calls to "TTree::SetBranchAddress".
class SimpleNtupleReader: public SimpleNtuple,  // ntuple definition,
                          public SimpleAnalyze, // analyze data and fill histos
                          public TreeReader {   // create branches and
                                                //   read ntuple from file

 public:

  SimpleNtupleReader() {
    // Here an integer cut is set ("nCut" is declared at the bottom of the
    // definition of this class) as an "user parameter", so that it can
    // be changed at run time giving a new value in the command line, e.g.:
    // ..../simpleNtupleRead .... -v nCut 7
    // and then retrieved (see the "beginJob" function),
    // with no need to recompile
    setUserParameter<unsigned int>( "nCut", 6 );
    // The value type (unsigned int in this case) is specified when the value is
    // given as a constant, to avoid misinterpretations; the value is
    // anyway stored with its representation as a string.
    // Two macros can be used when the parameter name is the same as
    // the variable name:
//    SET_USER_PARAMETER( nCut );    // equivalent to
//                                   // setUserParameter( "nCut", nCut );
//    ASS_USER_PARAMETER( nCut, 6 ); // equivalent to
//                                   // setUserParameter( "nCut", nCut = 6 );
//                                   // (the value can be itself an expression)
  }

  // Operations to be done at the execution begin
  void beginJob() override {   // virtual function defined in TreeWrapper
    setup();                   // define ntuple structure (in SimpleNtuple)
    // Any other operation to be done at the execution start can be put
    // in this function, apart on histogram creation that is to be put in
    // a dedicated function.
    // A similar function "beginFile()" can be declared and implemented
    // as overriding a virtual function defined in TreeWrapper, for any
    // operation to do when starting the analysis of a new ntuple file.
    // Here the value of the parameter "nCut" is retrieved; 
    nCut = getUserParameter<unsigned int>( "nCut" );
    // The value type (int in this case) is specified because values are stored
    // as strings, and they've to be interpreted correctly.
    // Alternatively the target value can be passed as a parameter:
//    getUserParameter( "nCut", nCut ); 
    // A macro can be used when the parameter name is the same as
    // the variable name:
//    GET_USER_PARAMETER( nCut );    // equivalent to
//                                   // getUserParameter( "nCut", nCut );
    return;
  }

  // Histograms creation
  void book() override {       // virtual function defined in TreeWrapper
    createHisto( autoSavedObject ); // forward the call to class "SimpleAnalyze"
                               // "autoSavedObject" is a tool to mark
                               // histograms for automatic saving to output
                               // file                    (in TreeWrapper )
    return;
  }

  //  Optional preliminary processing
//  bool getEntry( int ientry ) override {
                               // virtual function defined in TreeWrapper:
                               // some preliminary processing can be done here,
                               // e.g. read just some branch and choose if
                               // this entry is to be kept or skipped without 
                               // spending the time to read the whole data
                               // structure
//    b_n_arr->GetEntry( ientry );       // read only n_arr from file
//    if ( n_arr < nCut ) return false;  // if less than a cut skip this entry
//    currentTree()->GetEntry( ientry ); // otherwise read the full data
//    return true;                       // and go on with the analysis
//  }

  // Data analysis
  bool analyze( int entry, int event_file, int event_tot ) override {
                               // virtual function defined in TreeWrapper
    // Data are automatically reset and read from ntuple file for each
    // entry; no explicit call to GetEntry is needed here.
    // The 3 parameters are:
    //  - the entry number,
    //  - the number of entries actually processed in this ntuple file
    //  - the number of entries actually processed in the whole analysis
    fillHisto();               // analyze data and
                               // fill histograms         (in SimpleAnalyze)
    return true; // return "true" or "false" to accept or reject entries.
                 // This value is essentially used to count events, but 
                 // it can be used in other libraries implementing additional
                 // functionalities.
  }

  // Operations to be done at the execution end
  void endJob() override {       // virtual function defined in TreeWrapper
    // Any other operation to be done at the execution end can be put
    // in this function, apart on histogram saving to file that is to be put in
    // a dedicated function (unless relying on automatic saving, in that case
    // nothing is to be done).
    // A similar function "endFile()" can be declared and implemented
    // as overriding a virtual function defined in TreeWrapper, for any
    // operation to do when starting the analysis of a new ntuple file.
    return;
  }

  // Optional function to draw some plots at the execution end: see the
  // INSTRUCTIONS file for details about running options.
  // This function is executed before saving histograms, so any operation 
  // done to them through the graphic interface will be persistent.
  // This function can be simply left not declared and not implemented, but
  // do not declare an empty function, otherwise execution could get stuck
  // in some situations. If the "plot()" function is removed, the library
  // "Gpad" can be also removed from the BuildFile.xml as well as from
  // the compile.sh script.
  void plot() override {
    TCanvas* c1 = new TCanvas( "c1", "c1", 800, 600 );
    c1->Divide( 2, 2 );
    c1->cd( 1 ); hCount->Draw();
    c1->cd( 2 ); hContA->Draw();
    c1->cd( 3 ); hContI->Draw();
    c1->cd( 4 ); hContF->Draw();
    c1->Print( "c1.pdf" );
    TCanvas* c2 = new TCanvas( "c2", "c2", 800, 600 );
    c2->Divide( 2, 2 );
    c2->cd( 1 ); hRandI->Draw();
    c2->cd( 2 ); hRandS->Draw();
    c2->cd( 3 ); hRandF->Draw();
    c2->cd( 4 ); hRandD->Draw();
    c2->Print( "c2.pdf" );
  }

  // A function "save()" can be declared, but if relevant histograms are 
  // marked with "autoSavedObjects" (see the "book()" function) it can be 
  // left not declared and not implemented.
  // If some operation is to be done in addition to the automatic histogram 
  // saving, these operations can be put in this function together with
  // a call to "autoSave()".
//  void save() override {
// //    autoSave(); // automatic save of marked histograms (see above)
//    hCount->Write(); // explicit save (alternative to "autoSave()")
//    hContA->Write();
//    hContI->Write();
//    hContF->Write();
//    return;
//  }

  // Parameters used in the (pre)selection and analysis
  // See (set/get)UserParameter above for additional informations
  unsigned int nCut;

};

// It's essential to instantiate a global "SimpleNtupleReader" object,
// so that it's created before the execution starts; it's then retrieved
// and used inside the library according to the needs.
static SimpleNtupleReader reader;

int main( int argc, char* argv[] ) {

  // Create an analyzer object
  cout << "create analyzer" << endl;
  TreeStandardAnalyzer* tsa = TreeStandardAnalyzer::getInstance();

  // Run the analyzer
  // No detailed instruction is needed, the sequence of call to the 
  // functions "beginJob()", "book()", "analyze(...)" and so on are 
  // done automatically inside the library.
  tsa->run( argc, argv );

  return 0;

}

