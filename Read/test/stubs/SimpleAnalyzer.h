#ifndef SimpleAnalyzer_H
#define SimpleAnalyzer_H

#include "NtuTool/Common/test/stubs/SimpleNtuple.h"
#include "NtuTool/Read/interface/TreeReader.h"

#include "TH1.h"

// The class used to read the tree must inherit from
// "SimpleTree" containing the tree definition
// "TreeReader" provided by the tool

class SimpleAnalyzer: private SimpleNtuple,
                      private TreeReader {

 public:

  SimpleAnalyzer();
  virtual ~SimpleAnalyzer();

  // function to do initialization
  virtual void beginJob();
  // function to book histograms, called after "beginJob"
  void book();

  // function to do file-specific initialization
  virtual void beginFile();

  // functions called for each event
  virtual void reset();
  // function to get current entry from ntuple, to be overridden if
  // a "preliminary analysis" is to be performed over part of events
//  virtual bool getEntry( int ientry );
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
  SimpleAnalyzer( const SimpleAnalyzer& );
  SimpleAnalyzer& operator=( const SimpleAnalyzer& );

};


#endif

