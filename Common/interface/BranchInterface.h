#ifndef NtuTool_Common_BranchInterface_h
#define NtuTool_Common_BranchInterface_h

#include "NtuTool/Common/interface/BranchInterfaceData.h"

#include <vector>
#include <map>
#include <string>
class DataHandler;
class DataHandlerManager;
class TBranch;

class BranchInterface {

 public:

  BranchInterface();
  virtual ~BranchInterface();

  BranchInterface* setBranch( const char* branchName, void* dataPtr,
                              const char* branchData,
                              TBranch** branchPtr = nullptr );
  BranchInterface* setBranch( const char* branchName, void* dataPtr,
                              int bufferSize,
                              const char* branchData,
                              TBranch** branchPtr = nullptr );
  template <class T>
  BranchInterface* setBranch( const char* branchName, T* dataPtr,
                              int bufferSize,
                              int splitLevel,
                              TBranch** branchPtr = nullptr );
  template <class T>
  BranchInterface* setBranch( const char* branchName, T** dataPtr,
                              int bufferSize,
                              int splitLevel,
                              TBranch** branchPtr = nullptr );

  BranchInterface* setInfo( int type, const char* s );
  template <class T>
  BranchInterface* setInfo( int type, const T& info );

  static        void** pPtr(  void* p ) {
    return static_cast<       void**>( p );
  } 
  static          int* iPtr( void* p ) {
    return static_cast<         int*>( p );
  } 
  static unsigned int* uPtr( void* p ) {
    return static_cast<unsigned int*>( p );
  } 

 protected:

  const std::string& treeName() { return biData->treeName; }

  // tree pointer
  TTree*& currentTree() { return biData->currentTree; }

  typedef BranchInterfaceData::branch_desc branch_desc;
  typedef BranchInterfaceData::branch_list branch_list;
  typedef branch_list::const_iterator branch_iterator;
  typedef branch_list::const_reverse_iterator branch_rev_iter;

  const std::map<TBranch**,branch_desc*>& branchMap() { return biData->bMap; }
  void fillBranchMap();
  virtual void process( int ientry );
  virtual void process( TBranch** b, int ientry );
  virtual void process( const branch_desc* b, int ientry );

  branch_iterator treeBegin();
  branch_iterator treeEnd();
  branch_rev_iter treeRBegin();
  branch_rev_iter treeREnd();

 private:

  BranchInterface           ( const BranchInterface& t ) = delete;
  BranchInterface& operator=( const BranchInterface& t ) = delete;

  BranchInterface( BranchInterface* bi );

  BranchInterface* biShadow;
  BranchInterfaceData* biData;

  const branch_list& branchList() { return biData->bList; }
  branch_desc* newBranch( const char* branchName, void* dataPtr,
                          const char* branchData );

};

#include "NtuTool/Common/interface/BranchInterface.hpp"

#endif // NtuTool_Common_BranchInterface_h
