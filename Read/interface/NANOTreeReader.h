#ifndef NANOTreeReader_h
#define NANOTreeReader_h

#include "NtuTool/Common/interface/TreeReader.h"
#include <vector>

class NANOTreeReader: public TreeReader {

 public:

  NANOTreeReader();
  ~NANOTreeReader() override;

  TChain* initRead( const std::string& file ) override;

 protected:

  void initRead( TTree* tree ) override;
  void process( int ientry ) override;
  void process( TBranch* b, int ientry ) override;

 private:

  NANOTreeReader           ( const NANOTreeReader& t ) = delete;
  NANOTreeReader& operator=( const NANOTreeReader& t ) = delete;

  std::vector<unsigned int*> addInts;

};


#endif
