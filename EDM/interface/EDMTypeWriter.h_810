#ifndef NtuTool_EDM_EDMTypeWriter_h
#define NtuTool_EDM_EDMTypeWriter_h
/** \class EDMTypeWriter
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
#include "NtuTool/EDM/interface/EDMTypeWriterManager.h"
#include "NtuTool/EDM/interface/EDMDataHandler.h"
namespace edm {
  class Event;
}
class EDProducerWrapper;

//---------------
// C++ Headers --
//---------------
#include <string>
#include <vector>
#include <memory>

//              ---------------------
//              -- Class Interface --
//              ---------------------

template <class T>
class EDMTypeWriter: public TypeHandler<T,EDMTypeWriterManager>,
                     public EDMDataHandler {

 public:

  /** Constructor
   */
  EDMTypeWriter( DataReset::resetMode mode ):
                 TypeHandler<T,EDMTypeWriterManager>( mode ) {}
  EDMTypeWriter( DataReset* dr ):
                 TypeHandler<T,EDMTypeWriterManager>( dr )   {}

  /** Destructor
   */
  ~EDMTypeWriter() override;

  /** Operations
   */
  /// get concrete object
  DataHandler* getInstance( const std::string& name,
                            const std::string& code ) override;

  /// EDProducer function
  void produces( EDProducerWrapper* p ) override;

  /// Event function
  void put( edm::Event& e, const void* p ) override;

  /// Utility functions
  void buildPtr( void* p ) override;
  void clearPtr( void* p ) override;

  typedef std::unique_ptr<T> typePtr;
  typedef std::unique_ptr< std::vector<T> > vectPtr;

 protected:

  EDMTypeWriter( const std::string& name,
                 const std::string& code,
                 const std::string& type );

  EDMTypeWriter( bool dum ) {}

 private:

  EDMTypeWriter           ( const EDMTypeWriter& e ) = delete;
  EDMTypeWriter& operator=( const EDMTypeWriter& e ) = delete;

};

#include "NtuTool/EDM/interface/EDMTypeWriter.hpp"

#endif // NtuTool_EDM_EDMTypeWriter_h




