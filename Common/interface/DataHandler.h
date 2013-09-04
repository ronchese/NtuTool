#ifndef DataHandler_H
#define DataHandler_H
/** \class DataHandler
 *
 *  Description: 
 *    Base class to select type-specific calls to EDProducer and Event
 *    functions
 *
 *  $Date: 2011/03/01 18:06:55 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------


//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
class DataHandlerManager;
class DataReset;
class TTree;
class TBranch;
namespace edm {
  class EDProducer;
  class Event;
}

//---------------
// C++ Headers --
//---------------
#include <string>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class DataHandler {

 public:

//  enum conversionType{ null, copyString, copyVector };
  enum conversionType{ null, ppReference, copyVector };

  /** Constructor
   */
  DataHandler();

  /** Destructor
   */
  virtual ~DataHandler();

  /** Operations
   */
  /// get concrete object
  virtual DataHandler* getInstance( const std::string& name,
                                    const std::string& code );

  /// get basic info
  const std::string& getName();
  const std::string& getCode();
  const std::string& getType();
  const std::string& getSize();
  conversionType     getConv();

  /// TTree function
  virtual TBranch* branch( TTree* tree, const std::string* name, void** p,
                           int bufferSize = 32000,
                           int splitLevel = 99 );

  /// EDProducer function
  virtual void produces( edm::EDProducer* p );

  /// Event function
  virtual void put( edm::Event& e, const void* p );

  /// Branch function
  virtual std::string getBranchName( const std::string& processName,
                                     const std::string& producerName );

  /// Read functions
  virtual void process( void* p );

  /// Utility functions
  virtual void reset( void* p );
  virtual void buildPtr( void* p );
  virtual void clearPtr( void* p );
  void* auxiliaryPtr();
  virtual void* setAuxPtr( void* p, DataHandlerManager* hm = 0 );

  virtual void setMemberPtr( TTree* tree,
                             const std::string& branchName,
                             void* dataPtr );

 protected:

  /** Constructor
   */
  DataHandler( const std::string& name,
               const std::string& code,
               const std::string& type );
  DataHandler( bool dum );

  std::string dataName;
  std::string dataCode;
  std::string dataType;
  std::string dataSize;
  conversionType convType;
  void* auxPtr;
  DataReset* dataReset;

 private:

  DataHandler( const DataHandler& e );
  DataHandler& operator=( const DataHandler& e );

};


#endif // DataHandler_H

