#ifndef EDMTreeReader_h
#define EDMTreeReader_h

#include "NtuTool/Read/interface/TreeReader.h"

class EDMTreeReader: public TreeReader {

 public:

  EDMTreeReader();
  virtual ~EDMTreeReader();

  virtual TChain* initRead( const std::string& file );

 protected:

  void setProcessName(  const std::string& name );
  void setProducerName( const std::string& name );

  virtual void initRead( TTree* tree );
  virtual void process( int ientry );

 private:

  EDMTreeReader( const EDMTreeReader& t );
  EDMTreeReader& operator=( const EDMTreeReader& t );

  std::string producerName;
  std::string  processName;

};


#endif
