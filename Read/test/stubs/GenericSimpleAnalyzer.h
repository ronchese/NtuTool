#ifndef GenericSimpleAnalyzer_H
#define GenericSimpleAnalyzer_H

#include "NtuTool/Common/test/stubs/SimpleNtuple.h"

#include "TH1.h"

// The class used to read the EDM ntuple must inherit from
// "SimpleTree" containing the tree definition
// "TreeReader" or "EDMTreeReader" provided by the tool
// (to read base or EDM ntuples)

// define TREE_READER as BASE or EDM
#define BASE 1
#define EDM  2
#  if NTUPLE_TYPE == BASE

#include "NtuTool/Read/interface/TreeReader.h"
class GenericSimpleAnalyzer: private SimpleNtuple,
                             private TreeReader {

#elif NTUPLE_TYPE == EDM

#include "NtuTool/Read/interface/EDMTreeReader.h"
class GenericSimpleAnalyzer: private SimpleNtuple,
                             private EDMTreeReader {

#else
#error use -D NTUPLE_TYPE=BASE or -D NTUPLE_TYPE=EDM
#endif

 public:

  GenericSimpleAnalyzer();
  virtual ~GenericSimpleAnalyzer();

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
  GenericSimpleAnalyzer( const GenericSimpleAnalyzer& );
  GenericSimpleAnalyzer& operator=( const GenericSimpleAnalyzer& );

};


#endif

