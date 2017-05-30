#ifndef TestBaseNtuple_h
#define TestBaseNtuple_h

#include "NtuTool/Common/test/stubs/SimpleNtuple.h"
#include "NtuTool/Common/interface/TreeWriter.h"
#include "NtuTool/EDM/interface/EDAnalyzerWrapper.h"

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

class TFile;

// the analyzer inherits from two more classes in addition to EDAnalyzer:
//     "SimpleTree"   is defined from the user and contains the variables
//     "TreeWriter"   is defined inside the tool

class SimpleWriter: public EDAnalyzerWrapper,
                    public TreeWriter,
                    public SimpleNtuple {

 public:

  explicit SimpleWriter( const edm::ParameterSet& ps );
  virtual ~SimpleWriter();

  virtual void beginJob();
  virtual void analyze( const edm::Event& ev, const edm::EventSetup& es );
  virtual void endJob();

 private:

  TFile* file;

  // the pointer to the TTree is no more needed
  // the variables are now defined inside "SimpleTree"

  // function (by the user) to encapsulate operations to set variables
  void setData( unsigned int iRun );

};

#endif
