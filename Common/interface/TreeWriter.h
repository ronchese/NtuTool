#ifndef NtuTool_Common_TreeWriter_h
#define NtuTool_Common_TreeWriter_h

#include "NtuTool/Common/interface/TreeWrapper.h"

class TFile;
class TDirectory;

class TreeWriter: public virtual TreeWrapper {

 public:

  TreeWriter();
  ~TreeWriter() override;

  virtual void initWrite( TFile* file );
  virtual void fill();
  virtual void close();

 protected:

 private:

  TreeWriter           ( const TreeWriter& t ) = delete;
  TreeWriter& operator=( const TreeWriter& t ) = delete;

  TDirectory* treeDir;

};


#endif // NtuTool_Common_TreeWriter_h
