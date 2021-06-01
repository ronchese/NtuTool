#ifndef SimpleAnalyze_H
#define SimpleAnalyze_H

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
    return;
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
  }

 protected:

  TH1F* hCount;
  TH1F* hContA;
  TH1F* hContI;
  TH1F* hContF;

 private:

  SimpleAnalyze           ( const SimpleAnalyze& x ) = delete;
  SimpleAnalyze& operator=( const SimpleAnalyze& x ) = delete;

};

#endif
