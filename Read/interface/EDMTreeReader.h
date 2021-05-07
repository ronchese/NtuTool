#ifndef EDMTreeReader_h
#define EDMTreeReader_h

#include "NtuTool/Common/interface/TreeReader.h"
#include "NtuTool/Read/interface/TreeDataProcess.h"

class EDMTreeReader: public TreeDataProcess,
                     public virtual TreeReader {

 public:

  EDMTreeReader();
  ~EDMTreeReader() override;

 protected:

  void setProcessName(  const std::string& name );
  void setProducerName( const std::string& name );

  void initRead( TTree* tree ) override;

 private:

  EDMTreeReader           ( const EDMTreeReader& t ) = delete;
  EDMTreeReader& operator=( const EDMTreeReader& t ) = delete;

  std::string producerName;
  std::string  processName;

};


#endif
