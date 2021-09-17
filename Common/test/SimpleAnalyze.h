#ifndef NtuTool_Common_SimpleAnalyze_h
#define NtuTool_Common_SimpleAnalyze_h

#include "NtuTool/Common/test/SimpleData.h"
#include "TH1.h"

#include <vector>

// Class to analyze a simple data structure with random numbers

class SimpleAnalyze: public virtual SimpleData {

 public:

  SimpleAnalyze() {
  }

  ~SimpleAnalyze() override {
  }

  // function to set variables
  template <typename T>
  void createHisto( T& autoSavedObject ) {
    // An histogram is automatically marked for saving on file by putting
    // "autoSavedObject" in front of the its creation:
    // "autoSavedObject" is defined inside the NtuTool library, so
    // here it's passed as a template argument so that in "traditional" ntuple
    // analysis a reference to a TObject* can be passed and the same code
    // can be reused in examples where the NtuTool library is actually not used.
    autoSavedObject =
    hCount = new TH1F( "Count", "Count",   4,   4.5,  8.5 );
    autoSavedObject =
    hContA = new TH1F( "ContA", "ContA",   7,  -0.5,  6.5 );
    autoSavedObject =
    hContI = new TH1F( "ContI", "ContI",  10,  15.5, 25.5 );
    autoSavedObject =
    hContF = new TH1F( "ContF", "ContF", 100, -20.0, 30.0 );
    autoSavedObject =
    hRandI = new TH1F( "RandI", "RandI", 100, -50.0, 50.0 );
    autoSavedObject =
    hRandS = new TH1F( "RandS", "RandS", 100, -50.0, 50.0 );
    autoSavedObject =
    hRandF = new TH1F( "RandF", "RandF", 100, -50.0, 50.0 );
    autoSavedObject =
    hRandD = new TH1F( "RandD", "RandD", 100, -50.0, 50.0 );
    return;
  }

  bool vCut( int cut ) {
    // look for at least one element in "i_arr" larger than "cut"
    int i = n_arr;
    while ( i-- ) if ( i_arr[i] > cut ) return true;
    return false;
  }

  void fillHisto() {
    hCount->Fill( n_arr );
    const auto& f_vec = *f_vpt;
    int i = n_arr;
    while ( i-- ) hContA->Fill( i_arr[i] );
    int j = i_vec.size();
    while ( j-- ) hContI->Fill( i_vec[j] );
    int k = f_vec.size();
    while ( k-- ) hContF->Fill( f_vec[k] );
    hRandI->Fill( i_ran );
    hRandS->Fill( s_ran );
    hRandF->Fill( f_ran );
    hRandD->Fill( d_ran );
  }

 protected:

  TH1F* hCount;
  TH1F* hContA;
  TH1F* hContI;
  TH1F* hContF;

  TH1F* hRandI;
  TH1F* hRandS;
  TH1F* hRandF;
  TH1F* hRandD;

 private:

  SimpleAnalyze           ( const SimpleAnalyze& x ) = delete;
  SimpleAnalyze& operator=( const SimpleAnalyze& x ) = delete;

};

#endif // NtuTool_Common_SimpleAnalyze_h

