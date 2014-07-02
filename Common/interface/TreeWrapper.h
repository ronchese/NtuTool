#ifndef TreeWrapper_h
#define TreeWrapper_h

#include <vector>
#include <map>
#include <string>
class DataHandler;
class DataHandlerManager;
class TFile;
class TTree;
class TBranch;
class TObject;
class TDirectory;
class TList;

class TreeWrapper {

 public:

  TreeWrapper();
  virtual ~TreeWrapper();

  const std::string& name() const;

  void setConfiguration( const std::string& file );
  void setUserParameter( const std::string& key,
                         const std::string& val );
  template<class T>
  void setUserParameter( const std::string& key,
                         const           T& val );
  void setUserParameter( const std::string& key,
                         const        bool& val );
  const std::string& getUserParameter( const std::string& key );
  template<class T>
  void               getUserParameter( const std::string& key,    T& val );
  void               getUserParameter( const std::string& key, bool& val );

  void dumpAll();

  // function to do initialization
  virtual void beginJob();
  // function to book histograms, called after "beginJob"
  virtual void book();
  // function to do file-specific initialization
  virtual void beginFile();
  // function to do file-specific final operations
  virtual void endFile();
  // function to do final operations
  virtual void endJob();
  // function to plot histograms, called after "endJob"
  virtual void plot( int argc, char* argv[], char flag );
  virtual void plot();
  // function to save histograms, called after "plot"
  virtual void save( const std::string& name );
  virtual void save();

  int analyzedEvents();
  int acceptedEvents();

 protected:

  std::string treeName;

  // tree pointer
  TTree* currentTree;

  int analyzedEvts;
  int acceptedEvts;

  void setBranch( const char* branchName, void* dataPtr,
                  const char* branchData );
  void setBranch( const char* branchName, void* dataPtr,
                  const char* branchData,
                  TBranch** branchPtr );
  void setBranch( const char* branchName, void* dataPtr,
                  int bufferSize,
                  int splitLevel,
                  const char* branchData );
  void setBranch( const char* branchName, void* dataPtr,
                  int bufferSize,
                  int splitLevel,
                  const char* branchData,
                  TBranch** branchPtr );
  template<class T>
  void setBranch( const char* branchName, T* dataPtr,
                  int bufferSize = 32000,
                  int splitLevel = 99 );
  template<class T>
  void setBranch( const char* branchName, T* dataPtr,
                  int bufferSize,
                  int splitLevel,
                  TBranch** branchPtr );
  template<class T>
  void setBranch( const char* branchName, T** dataPtr,
                  int bufferSize = 32000,
                  int splitLevel = 99 );
  template<class T>
  void setBranch( const char* branchName, T** dataPtr,
                  int bufferSize,
                  int splitLevel,
                  TBranch** branchPtr );

  // function to reset class content before reading from file
  virtual void reset();
  // function to do event-by-event analysis,
  // return value "true" for accepted events
  virtual bool analyze( int entry, int event_file, int event_tot );

  DataHandlerManager* handlerManager;
  void autoReset();

  class AutoSavedObject {
   public:
    typedef std::vector<const TObject*> obj_list;
    typedef obj_list::const_iterator    obj_iter;
    typedef std::map<const TObject*, TDirectory*> dir_map;
    typedef dir_map::const_iterator               dir_iter;
    void insert( const TObject* obj, TDirectory* dir );
    obj_iter objBegin();
    obj_iter objEnd();
    dir_iter dirBegin();
    dir_iter dirFind( const TObject* obj );
    dir_iter dirEnd();
    AutoSavedObject& operator=( TObject* obj );
   private:
    obj_list objectList;
    dir_map directoryMap;
  };
  AutoSavedObject autoSavedObject;
  void autoSave( TList* list = 0 );
//  void autoSave( TDirectory* dir );

  struct branch_desc {
    std::string* branchName;
    void*        dataPtr;
    std::string* branchData;
    TBranch**    branchPtr;
    int          bufferSize;
    int          splitLevel;
    bool         ppRef;
    DataHandler* dataHandler;
  };
  typedef std::vector< branch_desc* > branch_list;
  typedef branch_list::const_iterator branch_iterator;
  typedef branch_list::const_reverse_iterator branch_rev_iter;

  branch_iterator treeBegin();
  branch_iterator treeEnd();

  virtual bool writable( const TObject* obj );
  virtual bool writable( const std::string& type );

 private:

  TreeWrapper( const TreeWrapper& t );
  TreeWrapper& operator=( const TreeWrapper& t );

  std::map<std::string,std::string> userParameters;
  bool histoPlotted;

  branch_list branchList;

  branch_desc* newBranch( const char* branchName, void* dataPtr,
                          const char* branchData );

};

#include "NtuTool/Common/interface/TreeWrapper.icc"

#endif
