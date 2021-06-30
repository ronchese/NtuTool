#ifndef NtuTool_Common_TreeFilter_h
#define NtuTool_Common_TreeFilter_h

#include "NtuTool/Common/interface/TreeWrapper.h"
#include <string>
#include <set>

class TFile;
class TDirectory;

class TreeFilter: public virtual TreeWrapper {

 public:

  TreeFilter();
  ~TreeFilter() override;

  virtual void dropBranch( const std::string& name );
  virtual void initWSkim( TFile* file );
  virtual void fillSkim();
  virtual void closeSkim();

 protected:

  TTree* filterTree;

 private:

  DataHandlerManager* fhManager;

  TreeFilter           ( const TreeFilter& t ) = delete;
  TreeFilter& operator=( const TreeFilter& t ) = delete;

  TDirectory* treeDir;
  std::set<std::string> skimDrop;

};


#endif // NtuTool_Common_TreeFilter_h
