#ifndef NtuTool_Common_TreeTypeHandler_h
#define NtuTool_Common_TreeTypeHandler_h
/** \class TreeTypeHandler
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
#include "NtuTool/Common/interface/TypeHandler.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "NtuTool/Common/interface/TreeTypeManager.h"

//---------------
// C++ Headers --
//---------------
#include <string>

//              ---------------------
//              -- Class Interface --
//              ---------------------

template <class T, class Manager=TreeTypeManager>
class TreeTypeHandler: public TypeHandler<T,Manager> {

 public:

  /** Constructor
   */
  TreeTypeHandler( DataReset::resetMode mode ):
      TypeHandler<T,Manager>( mode ) {}
  TreeTypeHandler( DataReset* dr ):
      TypeHandler<T,Manager>( dr )   {}

  /** Destructor
   */
  virtual ~TreeTypeHandler();

  /** Operations
   */
  /// get concrete object
  virtual DataHandler* getInstance( const std::string& name,
                                    const std::string& code );

  /// TTree function
  virtual TBranch* branch( TTree* tree, const std::string* name, void** p,
                           int bufferSize = 32000,
                           int splitLevel = 99 );

 protected:

  TreeTypeHandler( const std::string& name,
                   const std::string& code,
                   const std::string& type );
  TreeTypeHandler( bool dum ) {}

 private:

  TreeTypeHandler           ( const TreeTypeHandler& e ) = delete;
  TreeTypeHandler& operator=( const TreeTypeHandler& e ) = delete;

};

#include "NtuTool/Common/interface/TreeTypeHandler.hpp"

#endif // NtuTool_Common_TreeTypeHandler_h




