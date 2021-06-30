#include "NtuTool/Common/test/LegacyTree.h"
#include "NtuTool/Common/test/SimpleFill.h"
#include "NtuTool/EDM/interface/EDAnalyzerWrapper.h"

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "TFile.h"
#include "TTree.h"

#include <string>
#include <iostream>

using namespace std;

// A simple CMSSW EDAnalyzer built assembling parts from other classes.
// This example code does NOT use NtuTool functionalities, it's just a 
// reference to show how code handling ntuples changes using NtuTool:
// see "SimpleNtupleModule.cc" for a comparison.

// EDAnalyzerWrapper is simply a wrapper to edm::EDAnalyzer to use
// transparently different CMSSW version without taking care of some required
// specifiers (essentially "noexcept").
// LegacyTree contains the calls to reset ntuple content and create branches;
// note that different calls are required when writing or reading the tree.
// SimpleFill contains the code to fill ntuple data with random numbers.

class SimpleLegacyModule: public EDAnalyzerWrapper,
                          public LegacyTree,
                          public SimpleFill {

 public:

  explicit SimpleLegacyModule( const edm::ParameterSet& ps ) {
    nCut = ps.getParameter<unsigned int>( "nCut" );
    name = ps.getUntrackedParameter<string>( "fileName" );
    mode = ps.getUntrackedParameter<string>( "fileMode" );
  }

  ~SimpleLegacyModule() override {
  }

  void beginJob() override {
    // open file or get it from CMSSW TFileService
    file = ( name == "-" ? &fs->file() :
                           new TFile( name.c_str(), mode.c_str() ) );
    file->cd();
    // create tree
    tree = new TTree( "simpleNtuple", "simpleNtuple" );
    // define branches
    setBranchesWrite( tree );
    return;
  }

  void analyze( const edm::Event& ev, const edm::EventSetup& es ) override {
    // reset ntuple content
    resetNtupleContent();
    // set variables
    edm::EventID id = ev.id();
    setData( id.run(), id.event() );
    // actually fill the tree
    if ( n_arr > nCut ) tree->Fill();
    return;
  }

  void endJob() override {
    tree->Write();
    return;
  }

 private:

  // parameters used in event selection
  unsigned int nCut;

  // output ROOT file informations
  string name; // ROOT file name
  string mode; // ROOT file open mode ( "NEW", "CREATE", "RECREATE", "READ" )
  TFile* file; // ROOT file pointer
  TTree* tree; // tree pointer
  edm::Service<TFileService> fs; // ROOT file access through CMSSW service

};

#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_FWK_MODULE( SimpleLegacyModule );
