#ifndef TreeTypeWriter_H
#define TreeTypeWriter_H
/** \class TreeTypeWriter
 *
 *  Description: 
 *    Base class to select type-specific calls to EDProducer and Event
 *    functions
 *
 *  $Date: 2010-11-05 16:31:20 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "NtuTool/Common/interface/DataHandler.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------


//---------------
// C++ Headers --
//---------------
#include <string>

//              ---------------------
//              -- Class Interface --
//              ---------------------

template <class T>
class TreeTypeWriter: public DataHandler {

 public:

  /** Constructor
   */
  TreeTypeWriter();

  /** Destructor
   */
  virtual ~TreeTypeWriter();

  /** Operations
   */
  /// get concrete object
  virtual DataHandler* getInstance( const std::string& name,
                                    const std::string& code );

  /// TTree function
  virtual TBranch* branch( TTree* tree, const std::string* name, void** p,
                           int bufferSize = 32000,
                           int splitLevel = 99 );

  /// Utility functions
/*
//  virtual void reset( void* p );
  virtual void buildPtr( void* p );
  virtual void clearPtr( void* p );
*/
  virtual void* setAuxPtr( void* p, DataHandlerManager* hm = 0 );

 protected:

  TreeTypeWriter( const std::string& name,
                  const std::string& code,
                  const std::string& type );
  TreeTypeWriter( bool dum );

 private:

  TreeTypeWriter( const TreeTypeWriter& e );
  TreeTypeWriter& operator=( const TreeTypeWriter& e );

  T* dummyPtr;

};

#include "NtuTool/Common/interface/TreeTypeWriter.hpp"

#endif // TreeTypeWriter_H



