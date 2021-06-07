#include "NtuTool/EDM/interface/EDMTreeWriter.h"
#include "NtuTool/EDM/interface/EDFilterWrapper.h"

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/MakerMacros.h"


class EDMNtupleFilter: public EDFilterWrapper {

 public:

  EDMNtupleFilter( const edm::ParameterSet& ps ) {}
  ~EDMNtupleFilter() override {}

 private:

  EDMNtupleFilter           ( const EDMNtupleFilter& t ) = delete;
  EDMNtupleFilter& operator=( const EDMNtupleFilter& t ) = delete;

  bool filter( edm::Event& ev, const edm::EventSetup& es ) override {
    return EDMTreeWriter::select;
  }

};

//define this as a plug-in
DEFINE_FWK_MODULE( EDMNtupleFilter );
