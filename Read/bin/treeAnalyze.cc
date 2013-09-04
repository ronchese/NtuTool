#include "NtuTool/Read/interface/TreeStandardAnalyzer.h"

int main( int argc, char* argv[] ) {

  TreeStandardAnalyzer* ta = TreeStandardAnalyzer::getInstance();
  return ta->run( argc, argv );

}



