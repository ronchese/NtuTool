#include "NtuTool/Common/interface/TreeStandardAnalyzer.h"
#include "TROOT.h"

int main( int argc, char* argv[] ) {

  gROOT->ProcessLine("#include <vector>");
  TreeStandardAnalyzer* ta = TreeStandardAnalyzer::getInstance();
  return ta->run( argc, argv );

}



