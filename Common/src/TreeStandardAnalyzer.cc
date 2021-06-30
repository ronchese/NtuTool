/*
 *  See header file for a description of this class.
 *
 *  $Date: 2012/10/06 03:31:57 $
 *  $Revision: 1.12 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "NtuTool/Common/interface/TreeStandardAnalyzer.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Common/interface/TreeReader.h"
#include "TChain.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

//----------------
// Constructors --
//----------------
TreeStandardAnalyzer::TreeStandardAnalyzer() {
  TreeStandardAnalyzer*& analyzerInstance = instance();
  if ( analyzerInstance == nullptr ) analyzerInstance = this;
}

//--------------
// Destructor --
//--------------
TreeStandardAnalyzer::~TreeStandardAnalyzer() {
}


TreeStandardAnalyzer* TreeStandardAnalyzer::getInstance() {
  TreeStandardAnalyzer*& analyzerInstance = instance();
  if ( analyzerInstance == nullptr ) new TreeStandardAnalyzer;
  return analyzerInstance;
}


//--------------
// Operations --
//--------------
/// run the application
int TreeStandardAnalyzer::run( int argc, char* argv[] ) {

  TreeReader* tr = TreeReader::getInstance();

  std::string treeListName( "treeList" );
  std::string histFileName( "hist.root" );
  std::stringstream nmaxString;
  nmaxString.str( "0" );
  std::stringstream skipString;
  skipString.str( "0" );
  std::stringstream amaxString;
  amaxString.str( "0" );
  char type = 'b';
  bool listMissing = true;
  bool histMissing = true;
  std::string key = "";
  std::string val = "";
  char** argp = argv;
  char** argl = argp++ + argc;
  while ( argp < argl ) {
    std::string args( *argp++ );
    if ( args == "-n" ) {
      nmaxString.str( *argp++ );
      continue;
    }
    if ( args == "-s" ) {
      skipString.str( *argp++ );
      continue;
    }
    if ( args == "-a" ) {
      amaxString.str( *argp++ );
      continue;
    }
    if ( args == "-c" ) {
      tr->setConfiguration( *argp++ );
      continue;
    }
    if ( args == "-v" ) {
      key = *argp++;
      val = *argp++;
      tr->setUserParameter( key, val );
      continue;
    }
    if ( listMissing ) {
      treeListName = args;
      listMissing = false;
      continue;
    }
    if ( histMissing ) {
      histFileName = args;
      histMissing = false;
      continue;
    }
    type = *args.c_str();
  }

  std::ifstream treeListFile( treeListName.c_str() );
  int evtmax;
  nmaxString >> evtmax;
  int evskip;
  skipString >> evskip;
  int accmax;
  amaxString >> accmax;

  tr->beginJob();
  tr->book();

  loop( tr, treeListFile, evtmax, evskip, accmax );
  std::cout << std::endl << tr->    readEvents() << " events read, "
                         << tr->analyzedEvents() << " analyzed, "
                         << tr->acceptedEvents() << " accepted" << std::endl;

  tr->endJob();

  argc = 1;
  tr->plot( argc, argv, type );
  tr->save( histFileName );

  return 0;

}


/// loop over files
int TreeStandardAnalyzer::loop( TreeReader* tr, std::ifstream& treeListFile,
                                int evtmax, int evskip, int accmax,
                                bool anaexe ) {

  bool nmaxTotal = ( evtmax > 0 );
  bool skipTotal = ( evskip > 0 );
  bool accnTotal = ( accmax > 0 );
  if ( !nmaxTotal ) evtmax = -evtmax;
  if ( !skipTotal ) evskip = -evskip;
  if ( !accnTotal ) accmax = -accmax;

  char* treeListLine = new char[1000];
  char* treeListLptr;
  char* treeFileName;
  int evcount = 0;
  while ( treeListFile.getline( treeListLine, 1000 ) ) {
    treeListLptr = treeListLine;
    while ( *treeListLptr == ' ' ) treeListLptr++;
    if ( *treeListLptr == 'b' ) break;
    if ( *treeListLptr == 'B' ) break;
    if ( *treeListLptr == 'Y' ) *treeListLptr = 'y';
    if ( *treeListLptr != 'y' ) continue;
    treeListLptr++;
    while ( *treeListLptr == ' ' ) treeListLptr++;
    treeFileName = treeListLptr;
    while ( ( *treeListLptr != ' ' ) &&
            ( *treeListLptr != '\0' ) ) treeListLptr++;
    *treeListLptr = '\0';
    std::cout << "open file " << treeFileName << std::endl;
    TChain* c = tr->initRead( treeFileName );
    int tmpmax = ( accmax && !accnTotal ?
                   accmax + tr->acceptedEvents() : accmax );
    int evfile = 
    tr->loop( evtmax, evskip, tmpmax, anaexe );
    delete c;
    int evfana = evfile - evskip;
    if ( evfana <= 0 ) evfana = 0;
    if ( evfana > evtmax ) evcount += ( evtmax ? evtmax : evfana );
    else                   evcount += evfana;
    if ( accnTotal && tr->acceptedEvents() >= accmax ) break;
    if ( nmaxTotal ) {
      evtmax -= evfana;
      if ( evtmax <= 0 ) break;
    }
    if ( skipTotal ) evskip -= evfile;
    if ( evskip <= 0 ) evskip = 0;
  }

  delete[] treeListLine;
  return evcount;

}


TreeStandardAnalyzer*& TreeStandardAnalyzer::instance() {
  static TreeStandardAnalyzer* analyzerInstance = nullptr;
  return analyzerInstance;
}


