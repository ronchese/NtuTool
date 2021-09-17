#ifndef NtuTool_Common_BranchInterfaceData_h
#define NtuTool_Common_BranchInterfaceData_h

#include <vector>
#include <map>
#include <set>
#include <string>
class DataHandler;
class TTree;
class TBranch;

class BranchInterfaceData {

 public:

  BranchInterfaceData() {}
  ~BranchInterfaceData() {
    for ( auto& e : bMap ) {
      auto& b = e.second;
      delete b->branchName;
      delete b->branchData;
// to fix: only forward declaration for DataHandler is available,
// full header inclusion is forbidden 
// because DataHandler uses BranchInterfaceData
// and a circular inclusion would appear
//      delete b->dataHandler;
    }
  }

  std::string treeName;

  // tree pointer
  TTree* currentTree;

  struct branch_desc {
    std::string* branchName;
    void*        dataPtr;
    std::string* branchData;
    TBranch**    branchPtr;
    int          bufferSize;
    int          splitLevel;
    bool         ppRef;
    branch_desc* firstBranch;
    branch_desc*  nextBranch;
    DataHandler* dataHandler;
    std::map<int,const void*> addInfo;
  };

  static const std::string& getInfo( const branch_desc* b, int t,
                                     const char* d ) {
    std::string s( d );
    static std::set<std::string> ds;
    const std::string& ref = *( ds.insert( s ).first );
    if ( b == nullptr ) return ref;
    const std::map<int,const void*>& m = b->addInfo;
    std::map<int,const void*>::const_iterator iter = m.find( t );
    return ( iter == m.end() ? ref :
             *static_cast<const std::string*>( iter->second ) );
  }
  template<class T>
  static const T& getInfo( const branch_desc* b, int t, const T& d ) {
    if ( b == nullptr ) return d;
    const std::map<int,const void*>& m = b->addInfo;
    std::map<int,const void*>::const_iterator iter = m.find( t );
    return ( iter == m.end() ? d : *static_cast<const T*>( iter->second ) );
  }

  static int infoId( const std::string& s ) {
    auto& m = typeMap();
    return m.insert( make_pair( s, m.size() ) ).first->second;
  }

  typedef std::vector<branch_desc*> branch_list;
  branch_desc* lastBranch;
  branch_list bList;
  std::map<TBranch**,branch_desc*> bMap;

 private:

  BranchInterfaceData           ( const BranchInterfaceData& t ) = delete;
  BranchInterfaceData& operator=( const BranchInterfaceData& t ) = delete;

  static std::map<std::string,int>& typeMap() {
    static std::map<std::string,int> m;
    return m;
  }

};

#endif // NtuTool_Common_BranchInterfaceData_h
