#include <iostream>
#include <fstream>
#include <string>

#include "NtuTool/Common/interface/TreeWrapper.h"
#include "NtuTool/Common/interface/DataHandler.h"

#include "TFile.h"
#include "TTree.h"
#include "TApplication.h"
#include "TRint.h"
#include "TROOT.h"
#include "TList.h"


TreeWrapper::TreeWrapper():
     readEvts( 0 ),
 analyzedEvts( 0 ),
 acceptedEvts( 0 ) {
  setUserParameter( "histoMode", "CREATE" );
}


TreeWrapper::~TreeWrapper() {
}


const std::string& TreeWrapper::name() const {
  return treeName;
}


void TreeWrapper::setConfiguration( const std::string& file ) {
  std::ifstream cfg( file.c_str() );
  int length;
  int lenMax = 1000;
  char* line = new char[lenMax];
  char* lptr;
  while ( cfg.getline( line, lenMax ) ) {
    lptr = line;
    while ( *lptr == ' ' ) ++lptr;
    if    ( *lptr == '#' ) continue;
    std::string key( lptr );
    length = key.find( " " );
    if ( length < 0 ) {
      std::cout << "invalid configuration input: " << line << std::endl;
      continue;
    }
    key = key.substr( 0, length );
    lptr += length;
    while ( *lptr == ' ' ) ++lptr;
    std::string val( lptr );
    length = val.find( " " );
    if ( length >= 0 )
    val = val.substr( 0, length );
    setUserParameter( key, val );
  }
  delete[] line;
  return;
}


void TreeWrapper::setUserParameter( const std::string& key,
                                    const std::string& val ) {
  std::map<std::string,std::string>::iterator
                                     iter = userParameters.find( key );
  std::map<std::string,std::string>::iterator
                                     iend = userParameters.end();
  if ( iter != iend ) iter->second = val;
  else                userParameters.insert( make_pair( key, val ) );
  return;
}


void TreeWrapper::setUserParameter( const std::string& key,
                                    const        bool& val ) {
  setUserParameter( key, val ? "t" : "f" );
  return;
}


const std::string& TreeWrapper::getUserParameter( const std::string& key ) {
  static std::string dum( "" );
  std::map<std::string,std::string>::iterator
                                     iter = userParameters.find( key );
  std::map<std::string,std::string>::iterator
                                     iend = userParameters.end();
  if ( iter != iend ) return iter->second;
  return dum;
}


void TreeWrapper::getUserParameter( const std::string& key, bool& val ) {
  const char* flag = getUserParameter( key ).c_str();
  val = (   ( *flag == 't' ) || ( *flag == 'T' ) ||
          ( ( *flag >= '1' ) && ( *flag <= '9' ) ) );
  return;
}


void TreeWrapper::dumpAll( std::ostream& os ) {
  std::map<std::string,std::string>::const_iterator
                                           iter = userParameters.begin();
  std::map<std::string,std::string>::const_iterator
                                           iend = userParameters.end();
  while ( iter != iend ) {
    const std::pair<std::string,std::string>& entry = *iter++;
    os << entry.first << " " << entry.second << std::endl;
  }
  return;
}


void TreeWrapper::beginJob() {
// default analysis - dummy
  return;
}


void TreeWrapper::book() {
// default analysis - dummy
  return;
}


void TreeWrapper::beginFile() {
// default analysis - dummy
  return;
}


void TreeWrapper::endFile() {
// default analysis - dummy
  return;
}


void TreeWrapper::endJob() {
// default analysis - dummy
  return;
}


void TreeWrapper::plot( int argc, char* argv[], char flag ) {
  TApplication* app = nullptr;
  std::string name( treeName + "_app" );
  const char* cn = name.c_str();
  switch ( flag ) {
  case 'y':
    plot();
  case 'b':
    return;
  case 'i':
  case 'j':
    app = new TRint( cn, &argc, argv );
    break;
  default:
    app = new TApplication( cn, &argc, argv );
    break;
  }
  histoPlotted = true;
  if ( flag != 'i' ) plot();
  if ( histoPlotted || ( flag == 'j' ) ) app->Run( kTRUE );
  else std::cout << "no plot to draw" << std::endl;
  return;
}


void TreeWrapper::plot() {
// default analysis - dummy
// set "histoPlotted" to false to avoid execution getting stuck when
// "x" option is given
  histoPlotted = false;
  return;
}


void TreeWrapper::save( const std::string& name ) {
  TDirectory* currentDir = gDirectory;
  TFile file( name.c_str(), getUserParameter( "histoMode" ).c_str() );
  save();
  file.Close();
  currentDir->cd();
  return;
}


void TreeWrapper::save() {
// default analysis - autosave
  autoSave();
//  autoSave( gROOT );
  return;
}


int TreeWrapper::readEvents() {
  return readEvts;
}


int TreeWrapper::analyzedEvents() {
  return analyzedEvts;
}


int TreeWrapper::acceptedEvents() {
  return acceptedEvts;
}


void TreeWrapper::reset() {
// default analysis - no operation 
// automatic reset to be explicitly required by overriding function
//  autoReset();
  return;
}


bool TreeWrapper::analyze( int entry, int event_file, int event_tot ) {
// default analysis - dummy
  return true;
}


void TreeWrapper::autoReset() {
  branch_rev_iter iter = treeRBegin();//branchList.rbegin();
  branch_rev_iter iend = treeREnd();//branchList.rend();
  while ( iter != iend ) {
    branch_desc* bDesc = *iter++;
    DataHandler* handler = bDesc->dataHandler;
    if ( handler == nullptr ) continue;
    void* dataPtr = nullptr;
    if ( bDesc->ppRef ) dataPtr = *pPtr( bDesc->dataPtr );
    else                dataPtr =        bDesc->dataPtr;
    if ( dataPtr == nullptr ) continue;
    handler->reset( dataPtr );
  }
  return;
}


void TreeWrapper::AutoSavedObject::insert( const TObject* obj,
                                           TDirectory* dir ) {
  dir_iter iter = directoryMap.find( obj );
  dir_iter iend = directoryMap.end();
  if ( iter != iend ) return;
  directoryMap.insert( std::pair<const TObject*,
                                 TDirectory*>( obj, dir ) );
  return;
}


TreeWrapper::AutoSavedObject&
TreeWrapper::AutoSavedObject::operator=( TObject* obj ) {
  objectList.push_back( obj );
  std::string type = obj->ClassName();
  if ( type.substr( 0, 10 ) == "TDirectory" ) 
       dynamic_cast<TDirectory*>( obj )->cd();
  else if ( obj == gROOT )
       gROOT->cd();
  return *this;
}


TreeWrapper::AutoSavedObject::obj_iter
TreeWrapper::AutoSavedObject::objBegin() {
  return objectList.begin();
}


TreeWrapper::AutoSavedObject::obj_iter
TreeWrapper::AutoSavedObject::objEnd() {
  return objectList.end();
}


TreeWrapper::AutoSavedObject::dir_iter
TreeWrapper::AutoSavedObject::dirBegin() {
  return directoryMap.begin();
}


TreeWrapper::AutoSavedObject::dir_iter
TreeWrapper::AutoSavedObject::dirFind( const TObject* obj ) {
  return directoryMap.find( obj );
}


TreeWrapper::AutoSavedObject::dir_iter
TreeWrapper::AutoSavedObject::dirEnd() {
  return directoryMap.end();
}


void TreeWrapper::autoSave( TList* list ) {
  std::string type = gDirectory->ClassName();
  if ( ( type != "TFile" ) && 
       ( type != "TDirectoryFile" ) ) {
    std::cout << "File not open" << std::endl;
    return;
  }
  autoSavedObject.insert( gROOT, gDirectory );
  AutoSavedObject::obj_iter o_iter = autoSavedObject.objBegin();
  AutoSavedObject::obj_iter o_iend = autoSavedObject.objEnd();
  while ( o_iter != o_iend ) {
    const TObject* obj = *o_iter++;
    type = obj->ClassName();
    AutoSavedObject::dir_iter d_iter = autoSavedObject.dirFind( obj );
    AutoSavedObject::dir_iter d_iend = autoSavedObject.dirEnd();
    bool dirFound = ( d_iter != d_iend );
    bool dirType  = ( type.substr( 0, 10 ) == "TDirectory" );
    if ( dirType || dirFound ) {
      TDirectory* dir;
      if ( !dirFound ) {
        std::string name = obj->GetName();
        dir = gDirectory->mkdir( name.c_str() );
        autoSavedObject.insert( obj, dir );
      }
      else {
        dir = d_iter->second;
      }
      dir->cd();
    }
    else if ( writable( obj ) ) {
      if ( list == nullptr ) obj->Write();
      else                   list->FindObject( obj->GetName() )->Write();
    }
  }
  return;
}

/*
// not working, "GetListOfKeys" returns nullptr for memory resident directories
void TreeWrapper::autoSave( TDirectory* dir ) {
  TDirectory* current = gDirectory;
  TList* kl = dir->GetListOfKeys();
  int kn = kl->GetSize();
  int ki;
  TObject* obj;
  for ( ki = 0; ki < kn; ++ki ) {
    std::string nstd( kl->At( ki )->GetName() );
    const char* name = nstd.c_str();
    obj = dir->Get( name );
    std::string type( obj->ClassName() );
    if ( type.substr( 0, 10 ) == "TDirectory" ) {
      current->mkdir( name )->cd();
      autoSave( dir->GetDirectory( name ) );
    }
    else {
      obj->Write();
    }
  }
  current->cd();
  return;
}
*/

bool TreeWrapper::writable( const TObject* obj ) {
  return writable( obj->ClassName() );
}


bool TreeWrapper::writable( const std::string& type ) {
  if ( type.substr( 0, 2 ) == "TH"       ) return true;
  if ( type                == "TProfile" ) return true;
  if ( type                == "TCanvas"  ) return true;
  return false;
}

