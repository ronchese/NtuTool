#ifndef TreeDummyAnalyzer_H
#define TreeDummyAnalyzer_H
/** \class TreeDummyAnalyzer
 *
 *  Description: 
 *    Class to steer the tree analysis:
 *          - open all files in sequence
 *          - loop over the tree for each file
 *
 *  $Date: 2011-03-02 13:35:36 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "NtuTool/Read/interface/TreeStandardAnalyzer.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------


//---------------
// C++ Headers --
//---------------


//              ---------------------
//              -- Class Interface --
//              ---------------------

class TreeDummyAnalyzer: public TreeStandardAnalyzer {

 public:

  /** Constructor
   */
  TreeDummyAnalyzer();

  /** Destructor
   */
  virtual ~TreeDummyAnalyzer();

  /** Operations
   */
  /// run the application
  virtual int run( int argc, char* argv[] );

 private:

  static TreeDummyAnalyzer* analyzerInstance;

  TreeDummyAnalyzer( const TreeDummyAnalyzer& t );
  TreeDummyAnalyzer& operator=( const TreeDummyAnalyzer& t );

};


#endif // TreeDummyAnalyzer_H

