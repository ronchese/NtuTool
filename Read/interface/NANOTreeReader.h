#ifndef NANOTreeReader_h
#define NANOTreeReader_h

#include "NtuTool/Common/interface/TreeReader.h"
#include "NtuTool/Read/interface/TreeDataProcess.h"
#include <vector>

class NANOTreeReader: public TreeDataProcess,
                      public virtual TreeReader {

 public:

  NANOTreeReader();
  ~NANOTreeReader() override;

 protected:

  void initRead( TTree* tree ) override;

 private:

  NANOTreeReader           ( const NANOTreeReader& t ) = delete;
  NANOTreeReader& operator=( const NANOTreeReader& t ) = delete;

  std::vector<unsigned int*> addInts;

};


#endif
