#ifndef TreeStandardAnalyzer_H
#define TreeStandardAnalyzer_H
/** \class TreeStandardAnalyzer
 *
 *  Description: 
 *    Class to steer the tree analysis:
 *          - open all files in sequence
 *          - loop over the tree for each file
 *
 *  $Date: 2011/07/27 10:32:24 $
 *  $Revision: 1.3 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------


//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
class TreeReader;

//---------------
// C++ Headers --
//---------------
#include <iostream>
#include <fstream>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class TreeStandardAnalyzer {

 public:

  /** Constructor
   */
  TreeStandardAnalyzer();

  /** Destructor
   */
  virtual ~TreeStandardAnalyzer();

  static TreeStandardAnalyzer* getInstance();

  /** Operations
   */
  /// run the application
  virtual int run( int argc, char* argv[] );

  /// loop over files
  virtual int loop( TreeReader* tr, std::ifstream& treeListFile,
                    int evtmax, int evskip, int accmax, bool anaexe = true );

 private:

  static TreeStandardAnalyzer* analyzerInstance;

  TreeStandardAnalyzer( const TreeStandardAnalyzer& t );
  TreeStandardAnalyzer& operator=( const TreeStandardAnalyzer& t );

};


#endif // TreeStandardAnalyzer_H

