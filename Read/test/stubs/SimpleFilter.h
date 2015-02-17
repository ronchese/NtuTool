#ifndef SimpleFilter_H
#define SimpleFilter_H

#include "NtuTool/Common/test/stubs/SimpleNtuple.h"

#include "TH1.h"

// The class used to filter the ntuple must inherit from
// "SimpleTree" containing the tree definition
// "TreeReader" provided by the tool
// "TreeFilter" provided by the tool

#include "NtuTool/Read/interface/TreeReader.h"
#include "NtuTool/Common/interface/TreeFilter.h"

class SimpleFilter: private SimpleNtuple,
                            private TreeReader,
                            private TreeFilter {

 public:

  SimpleFilter();
  virtual ~SimpleFilter();

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

  TFile*      filterFile;

  // dummy copy and assignment constructors
  SimpleFilter( const SimpleFilter& );
  SimpleFilter& operator=( const SimpleFilter& );

};


#endif

