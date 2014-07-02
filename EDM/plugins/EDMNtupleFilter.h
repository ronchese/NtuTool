#ifndef EDMNtupleFilter_h
#define EDMNtupleFilter_h

#include "FWCore/Framework/interface/EDFilter.h"
#include "NtuTool/EDM/interface/EDMTreeWriter.h"

//class DataHandlerManager;

class EDMNtupleFilter: public edm::EDFilter {

 public:

  EDMNtupleFilter( const edm::ParameterSet& ps );
  virtual ~EDMNtupleFilter();

 private:

  EDMNtupleFilter( const EDMNtupleFilter& t );
  EDMNtupleFilter& operator=( const EDMNtupleFilter& t );

  virtual bool filter( edm::Event& ev, const edm::EventSetup& es );

};


#endif
