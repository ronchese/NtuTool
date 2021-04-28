#ifndef EDMTreeWriter_h
#define EDMTreeWriter_h

#include "NtuTool/Common/interface/TreeWrapper.h"
#include "NtuTool/EDM/interface/EDProducerWrapper.h"

#include "FWCore/Framework/interface/EDProducer.h"

#include <map>

class EDMDataHandler;
//class DataHandlerManager;

class EDMTreeWriter: public virtual EDProducerWrapper,
                     public virtual TreeWrapper {

  friend class EDMNtupleFilter;

 public:

  EDMTreeWriter();
  ~EDMTreeWriter() override;

  void beginJob() override;
  void   endJob() override;
  virtual void beginRun( edm::Run& r, edm::EventSetup const & es );
  virtual void   endRun( edm::Run& r, edm::EventSetup const & es );

 protected:

  void produce( edm::Event& ev, const edm::EventSetup& es );
  virtual void initWrite();
  virtual bool fill( const edm::Event& ev, const edm::EventSetup& es );

 private:

  EDMTreeWriter           ( const EDMTreeWriter& t ) = delete;
  EDMTreeWriter& operator=( const EDMTreeWriter& t ) = delete;

  void build();
  void put( edm::Event& ev );

  std::map<DataHandler*,EDMDataHandler*> edmHMap;

  static bool select;

//  DataHandlerManager* handlerManager;

};


#endif
