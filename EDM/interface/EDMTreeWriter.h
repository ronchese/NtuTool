#ifndef NtuTool_EDM_EDMTreeWriter_h
#define NtuTool_EDM_EDMTreeWriter_h

#include "NtuTool/Common/interface/TreeWrapper.h"
#include "NtuTool/EDM/interface/EDProducerWrapper.h"

#include "FWCore/Framework/interface/EDProducer.h"

#include <map>

class EDMDataHandler;

class EDMTreeWriter: public virtual EDProducerWrapper,
                     public virtual TreeWrapper {

  friend class EDMNtupleFilter;

 public:

  EDMTreeWriter();
  ~EDMTreeWriter() override;

  void beginJob() override;
  void   endJob() override;
  void beginRun( const edm::Run& r, const edm::EventSetup& es ) override;
  void   endRun( const edm::Run& r, const edm::EventSetup& es ) override;

 protected:

  void produce( edm::Event& ev, const edm::EventSetup& es ) override;
  virtual void initWrite();
  virtual bool fill( const edm::Event& ev, const edm::EventSetup& es );

 private:

  EDMTreeWriter           ( const EDMTreeWriter& t ) = delete;
  EDMTreeWriter& operator=( const EDMTreeWriter& t ) = delete;

  void build();
  void put( edm::Event& ev );

  std::map<DataHandler*,EDMDataHandler*> edmHMap;

  static bool select;

};


#endif // NtuTool_EDM_EDMTreeWriter_h
