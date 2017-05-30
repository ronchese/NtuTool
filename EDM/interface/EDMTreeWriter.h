#ifndef EDMTreeWriter_h
#define EDMTreeWriter_h

#include "NtuTool/Common/interface/TreeWrapper.h"
#include "NtuTool/EDM/interface/EDProducerWrapper.h"

#include "FWCore/Framework/interface/EDProducer.h"

//class DataHandlerManager;

class EDMTreeWriter: public virtual EDProducerWrapper,
                     public virtual TreeWrapper {

  friend class EDMNtupleFilter;

 public:

  EDMTreeWriter();
  virtual ~EDMTreeWriter();

  virtual void beginJob();
  virtual void   endJob();
  virtual void beginRun( edm::Run& r, edm::EventSetup const & es );
  virtual void   endRun( edm::Run& r, edm::EventSetup const & es );

 protected:

  void produce( edm::Event& ev, const edm::EventSetup& es );
  virtual void initWrite();
  virtual bool fill( const edm::Event& ev, const edm::EventSetup& es );

 private:

  EDMTreeWriter( const EDMTreeWriter& t );
  EDMTreeWriter& operator=( const EDMTreeWriter& t );

  void build();
  void put( edm::Event& ev );

  static bool select;

//  DataHandlerManager* handlerManager;

};


#endif
