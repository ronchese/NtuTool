#ifndef EDMTreeReader_h
#define EDMTreeReader_h

#include "NtuTool/Common/interface/TreeReader.h"

class EDMTreeReader: public TreeReader {

 public:

  EDMTreeReader();
  ~EDMTreeReader() override;

  TChain* initRead( const std::string& file ) override;

 protected:

  void setProcessName(  const std::string& name );
  void setProducerName( const std::string& name );

  virtual void initRead( TTree* tree );
  virtual void process( int ientry );
  virtual void process( TBranch* b, int ientry );

 private:

  EDMTreeReader           ( const EDMTreeReader& t ) = delete;
  EDMTreeReader& operator=( const EDMTreeReader& t ) = delete;

  std::string producerName;
  std::string  processName;

};


#endif
