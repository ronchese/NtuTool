#ifndef TreeWriter_h
#define TreeWriter_h

#include "NtuTool/Common/interface/TreeWrapper.h"

class TFile;
class TDirectory;

class TreeWriter: public virtual TreeWrapper {

 public:

  TreeWriter();
  virtual ~TreeWriter();

  virtual void initWrite( TFile* file );
  virtual void fill();
  virtual void close();

 protected:

 private:

  TreeWriter( const TreeWriter& t );
  TreeWriter& operator=( const TreeWriter& t );

  TDirectory* treeDir;

};


#endif
