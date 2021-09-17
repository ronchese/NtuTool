#ifndef NtuTool_Common_TreeStandardAnalyzer_h
#define NtuTool_Common_TreeStandardAnalyzer_h
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

  /** Destructor
   */
  virtual ~TreeStandardAnalyzer();

  static TreeStandardAnalyzer* getInstance();

  /** Operations
   */
  /// run the application
  virtual int run( int argc, char* argv[] );

 protected:

  /** Constructor
   */
  TreeStandardAnalyzer();

  /// loop over files
  virtual int loop( TreeReader* tr, std::ifstream& treeListFile,
                    int evtmax, int evskip, int accmax, bool anaexe = true );

 private:

  static TreeStandardAnalyzer*& instance();

  TreeStandardAnalyzer           ( const TreeStandardAnalyzer& t ) = delete;
  TreeStandardAnalyzer& operator=( const TreeStandardAnalyzer& t ) = delete;

};


#endif // NtuTool_Common_TreeStandardAnalyzer_h


