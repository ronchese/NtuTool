#ifndef NtuTool_Common_TreeWrapper_h
#define NtuTool_Common_TreeWrapper_h

#include "NtuTool/Common/interface/BranchInterface.h"

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

#define SET_USER_PARAMETER(NAME) setUserParameter(#NAME,NAME);
#define GET_USER_PARAMETER(NAME) getUserParameter(#NAME,NAME);
#define ASS_USER_PARAMETER(NAME,VALUE) setUserParameter(#NAME,NAME=VALUE);

class TreeWrapper: public BranchInterface {

 public:

  TreeWrapper();
  ~TreeWrapper() override;

  const std::string& name() const;

  void setConfiguration( const std::string& file );
  void setUserParameter( const std::string& key,
                         const std::string& val );
  template <class T>
  void setUserParameter( const std::string& key,
                         const           T& val );
  void setUserParameter( const std::string& key,
                         const        bool& val );
  const std::string& getUserParameter( const std::string& key );
  template <class T>
  void               getUserParameter( const std::string& key,    T& val );
  void               getUserParameter( const std::string& key, bool& val );
  template <class T>
  T                  getUserParameter( const std::string& key );

  void dumpAll( std::ostream& os );

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

  int     readEvents();
  int analyzedEvents();
  int acceptedEvents();

 protected:

  std::string treeName;

  int     readEvts;
  int analyzedEvts;
  int acceptedEvts;


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
    template <class T>
    AutoSavedObject& operator=( const std::vector<T*>& vObj ) {
      int i;
      int n = vObj.size();
      for ( i = 0; i < n; ++i ) *this = vObj[i];
      return *this;
    }
    template <class T>
    AutoSavedObject& operator=( const std::vector<T*>* vObj ) {
      *this = *vObj;
      return *this;
    }
   private:
    obj_list objectList;
    dir_map directoryMap;
  };
  AutoSavedObject autoSavedObject;
  void autoSave( TList* list = nullptr );

  virtual bool writable( const TObject* obj );
  virtual bool writable( const std::string& type );

 private:

  TreeWrapper           ( const TreeWrapper& t ) = delete;
  TreeWrapper& operator=( const TreeWrapper& t ) = delete;

  std::map<std::string,std::string> userParameters;
  bool histoPlotted;

};

#include "NtuTool/Common/interface/TreeWrapper.hpp"

#endif // NtuTool_Common_TreeWrapper_h
