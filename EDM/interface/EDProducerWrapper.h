#ifndef EDProducerWrapper_h
#define EDProducerWrapper_h

#include "FWCore/Framework/interface/EDProducer.h"

class EDProducerWrapper: public edm::EDProducer {

 public:

  EDProducerWrapper() {}
  virtual ~EDProducerWrapper() noexcept {}

};


#endif
