#include "NtuTool/Common/test/SimpleNtuple.h"
#include "NtuTool/Common/test/SimpleFill.h"
#include "NtuTool/Common/interface/TreeWriter.h"
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
// This example is very simple, another one making use of a dedicated library
// with several functionalities dedicated to usage in CMS data model
// can be found in NtuAnalysis.

// EDAnalyzerWrapper is simply a wrapper to edm::EDAnalyzer to use
// transparently different CMSSW version without taking care of some required
// specifiers (essentially "noexcept").
// SimpleNtuple contains the ntuple definition.
// SimpleFill contains the code to fill ntuple data with random numbers.
// The important point here is inheriting from both "SimpleNtuple", with the
// ntuple definition from the user, and "TreeWriter", from the library taking
// care of the actual calls to "TTree::Branch".
class SimpleNtupleModule: public EDAnalyzerWrapper,
                          public SimpleNtuple, // ntuple definition,
                          public SimpleFill,   // assign values to data,
                          public TreeWriter {  // create branches and
                                               //   write ntuple to file

 public:

  explicit SimpleNtupleModule( const edm::ParameterSet& ps ) {
    nCut = ps.getParameter<unsigned int>( "nCut" );
    name = ps.getUntrackedParameter<string>( "fileName" );
    mode = ps.getUntrackedParameter<string>( "fileMode" );
  }

  ~SimpleNtupleModule() override {
  }

  void beginJob() override {
    // open file, or get it from CMSSW TFileService
    file = ( name == "-" ? &fs->file() :
                           new TFile( name.c_str(), mode.c_str() ) );
    // define branches
    setup();                   // define ntuple structure (in SimpleNtuple)
    initWrite( file );         // create tree branches    (in TreeWriter  )
    return;
  }

  void analyze( const edm::Event& ev, const edm::EventSetup& es ) override {
    // reset ntuple content
    reset();                   // reset ntuple content    (in SimpleNtuple)
    // set variables
    edm::EventID id = ev.id();
    setData( id.run(),         // assign values to data   (in SimpleFill  )
             id.event() );
    // actually fill the tree
    if ( n_arr > nCut ) fill();// write ntuple to file    (in TreeWriter  )
    return;
  }

  void endJob() override {
    close();                   // save ntuple             (in TreeWriter  )
    return;
  }

 private:

  // parameters used in event selection
  unsigned int nCut;

  // output ROOT file informations
  string name; // ROOT file name
  string mode; // ROOT file open mode ( "NEW", "CREATE", "RECREATE", "READ" )
  TFile* file; // ROOT file pointer
  edm::Service<TFileService> fs; // ROOT file access through CMSSW service

};

#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_FWK_MODULE( SimpleNtupleModule );
