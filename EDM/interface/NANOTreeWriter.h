#ifndef NtuTool_EDM_NANOTreeWriter_h
#define NtuTool_EDM_NANOTreeWriter_h

#include "NtuTool/Common/interface/TreeWrapper.h"
#include "NtuTool/EDM/interface/EDProducerWrapper.h"

#include "FWCore/Framework/interface/EDProducer.h"

#include <map>

class NANOTableHandler;

class NANOTreeWriter: public virtual EDProducerWrapper,
                      public virtual TreeWrapper {

 public:

  NANOTreeWriter();
  ~NANOTreeWriter() override;

  void beginJob() override;
  void   endJob() override;
  void beginRun( const edm::Run& r, const edm::EventSetup& es ) override;
  void   endRun( const edm::Run& r, const edm::EventSetup& es ) override;

 protected:

  void produce( edm::Event& ev, const edm::EventSetup& es ) override;
  virtual void initWrite();
  virtual bool fill( const edm::Event& ev, const edm::EventSetup& es );

 private:

  NANOTreeWriter           ( const NANOTreeWriter& t ) = delete;
  NANOTreeWriter& operator=( const NANOTreeWriter& t ) = delete;

  void put( edm::Event& ev );

  std::map<DataHandler*,NANOTableHandler*> nanoHMap;

  static bool select;

};


#endif // NtuTool_EDM_NANOTreeWriter_h
