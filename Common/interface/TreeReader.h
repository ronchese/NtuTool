#ifndef NtuTool_Common_TreeReader_h
#define NtuTool_Common_TreeReader_h

#include "NtuTool/Common/interface/TreeWrapper.h"

#include <string>

class TChain;

class TreeReader: public virtual TreeWrapper {

 public:

  TreeReader();
  ~TreeReader() override;

  static TreeReader* getInstance();

  virtual TChain* initRead( const std::string& file );
  virtual int  loop( int evtmax = 0, int evskip = 0, int accmax = 0, 
                     bool anaexe = true );

 protected:

  std::string currentFile;

  virtual void initRead( TTree* tree );
  virtual bool getEntry( int ientry );

 private:

  static TreeReader*& instance();

  TreeReader           ( const TreeReader& t ) = delete;
  TreeReader& operator=( const TreeReader& t ) = delete;

};


#endif // NtuTool_Common_TreeReader_h
