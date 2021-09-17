#ifndef NtuTool_Read_TreeDataProcess_h
#define NtuTool_Read_TreeDataProcess_h

#include "NtuTool/Common/interface/TreeReader.h"
#include <iostream>

class TreeDataProcess: public virtual TreeReader {

 public:

  TreeDataProcess() {}
  ~TreeDataProcess() override {}

 protected:

  using TreeReader::process;
  void process( int ientry ) override {
    branch_iterator iter = treeBegin();
    branch_iterator iend = treeEnd();
    while ( iter != iend ) process( *iter++, ientry );
    return;
  }
  void process( TBranch** b, int ientry ) override {
    const std::map<TBranch**,branch_desc*>& bMap = branchMap();
    std::map<TBranch**,branch_desc*>::const_iterator iter = bMap.find( b );
    std::map<TBranch**,branch_desc*>::const_iterator iend = bMap.end();
    if ( iter != iend ) process( iter->second, ientry );
    return;
  }

 private:

  TreeDataProcess           ( const TreeDataProcess& t ) = delete;
  TreeDataProcess& operator=( const TreeDataProcess& t ) = delete;

};


#endif // NtuTool_Read_TreeDataProcess_h
