#ifndef NtuTool_Read_NANOTreeReader_h
#define NtuTool_Read_NANOTreeReader_h

#include "NtuTool/Common/interface/TreeReader.h"
#include "NtuTool/Read/interface/TreeDataProcess.h"
#include <vector>

class NANOTreeReader: public TreeDataProcess,
                      public virtual TreeReader {

 public:

  NANOTreeReader();
  ~NANOTreeReader() override;

 protected:

  using TreeReader::initRead;
  void initRead( TTree* tree ) override;

 private:

  NANOTreeReader           ( const NANOTreeReader& t ) = delete;
  NANOTreeReader& operator=( const NANOTreeReader& t ) = delete;

  std::vector<unsigned int*> addInts;

};


#endif // NtuTool_Read_NANOTreeReader_h
