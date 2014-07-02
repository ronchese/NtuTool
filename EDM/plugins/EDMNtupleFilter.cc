#include "NtuTool/EDM/plugins/EDMNtupleFilter.h"

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/MakerMacros.h"

EDMNtupleFilter::EDMNtupleFilter( const edm::ParameterSet& ps ) {
}


EDMNtupleFilter::~EDMNtupleFilter() {
}


bool EDMNtupleFilter::filter( edm::Event& ev, const edm::EventSetup& es ) {
  return EDMTreeWriter::select;
}

//define this as a plug-in
DEFINE_FWK_MODULE( EDMNtupleFilter );
