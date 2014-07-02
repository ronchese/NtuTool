#ifndef SimpleEDMAnalyzer_H
#define SimpleEDMAnalyzer_H

#include "NtuTool/Common/test/stubs/SimpleNtuple.h"
#include "NtuTool/Read/interface/EDMTreeReader.h"

#include "TH1.h"

// The class used to read the EDM ntuple must inherit from
// "SimpleTree" containing the tree definition
// "EDMTreeReader" provided by the tool

class SimpleEDMAnalyzer: private SimpleNtuple,
                         private EDMTreeReader {

 public:

  SimpleEDMAnalyzer();
  virtual ~SimpleEDMAnalyzer();

  // function to do initialization
  virtual void beginJob();
  // function to book histograms, called after "beginJob"
  void book();

  // function to do file-specific initialization
  virtual void beginFile();

  // functions called for each event
  virtual void reset();
  virtual bool analyze( int entry, int event_file, int event_tot );

  // function to do file-specific final operations
  virtual void endFile();
  // function to do final operations
  virtual void endJob();

  // functions called at the end of the event loop
  virtual void plot();   // plot the histograms on the screen
  // "save" function not needed for auto-saved histos,
  // see .cc for details
//  virtual void save();   // save the histograms on a ROOT file

 private:

  TH1F* hist;
  TH1F* hisd;
  TH1F* hisc;

  // dummy copy and assignment constructors
  SimpleEDMAnalyzer( const SimpleEDMAnalyzer& );
  SimpleEDMAnalyzer& operator=( const SimpleEDMAnalyzer& );

};


#endif

