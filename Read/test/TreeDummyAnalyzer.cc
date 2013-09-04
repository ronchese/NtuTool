/*
 *  See header file for a description of this class.
 *
 *  $Date: 2011-03-02 13:35:36 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "NtuTool/Read/test/TreeDummyAnalyzer.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Read/interface/TreeReader.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

//-------------------
// Initializations --
//-------------------
static TreeDummyAnalyzer tda;

//----------------
// Constructors --
//----------------
TreeDummyAnalyzer::TreeDummyAnalyzer() {
}

//--------------
// Destructor --
//--------------
TreeDummyAnalyzer::~TreeDummyAnalyzer() {
}


//--------------
// Operations --
//--------------
/// run the application
int TreeDummyAnalyzer::run( int argc, char* argv[] ) {

  std::cout << "DUMMY ANALYZER" << std::endl;

  return 0;

}



