#include "NtuTool/Common/test/SimpleNtuple.h"
#include "NtuTool/Common/test/SimpleFill.h"
#include "NtuTool/EDM/interface/EDMTreeWriter.h"

#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "TFile.h"
#include "TTree.h"

// A simple CMSSW EDProducer built assembling parts from other classes.
// This example is very simple, another one making use of a dedicated library
// with several functionalities dedicated to usage in CMS data model
// can be found in NtuAnalysis.

// Actually the inheritance from EDProducer is got through EDMTreeWriter.
// SimpleNtuple contains the ntuple definition.
// SimpleFill contains the code to fill ntuple data with random numbers.
// The important point here is inheriting from both "SimpleNtuple", with the
// ntuple definition from the user, and "EDMTreeWriter", from the library
// taking care of interfacing with EDProducer.
class SimpleNtuEDMModule: public SimpleNtuple, // ntuple definition,
                          public SimpleFill,   // assign values to data,
                          public EDMTreeWriter {  // create branches

 public:

  explicit SimpleNtuEDMModule( const edm::ParameterSet& ps ) {
    nCut = ps.getParameter<unsigned int>( "nCut" );
    // define branches, this must be done in the constructor
    setup();                   // define ntuple structure (in SimpleNtuple)
    initWrite();               // create tree branches    (in EMDTreeWriter)
  }

  ~SimpleNtuEDMModule() override {
  }

  bool fill( const edm::Event& ev, const edm::EventSetup& es ) override {
    // set variables; there's no need to reset ntuple content,
    // it's automatically done inside EDMTreeWriter functions
    edm::EventID id = ev.id();
    setData( id.run(),         // assign values to data   (in SimpleFill  )
             id.event() );
    return n_arr > nCut;       // return value (true/false) controls if data
                               // are actually added to the edm::Event, it can
                               // can be also used in an EDFilter to choose
                               // if the event is to be passed to following
                               // modules, or not (see cfg_ntuEDM.py)
  }

  // parameters used in event selection
  unsigned int nCut;

};

#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_FWK_MODULE( SimpleNtuEDMModule );
