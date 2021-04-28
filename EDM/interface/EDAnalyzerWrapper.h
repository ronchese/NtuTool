#ifndef EDAnalyzerWrapper_h
#define EDAnalyzerWrapper_h

#include "FWCore/Framework/interface/EDAnalyzer.h"

class EDAnalyzerWrapper: public edm::EDAnalyzer {

 public:

  EDAnalyzerWrapper() {}
  ~EDAnalyzerWrapper() noexcept override {}

};


#endif
