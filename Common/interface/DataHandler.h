#ifndef NtuTool_Common_DataHandler_h
#define NtuTool_Common_DataHandler_h
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
#include "NtuTool/Common/interface/BranchInterfaceData.h"
class DataHandlerManager;
class DataReset;
class TTree;
class TBranch;

//---------------
// C++ Headers --
//---------------
#include <string>
#include <iostream>
//              ---------------------
//              -- Class Interface --
//              ---------------------

class DataHandler {

 public:

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

  /// Read functions
  virtual void process( void* p );

  /// Utility functions
  virtual void reset( void* p );
  virtual void buildPtr( void* p );
  virtual void clearPtr( void* p );
  void* auxiliaryPtr();
  void* additionalInfo();
  virtual void* setAuxPtr( void* p, DataHandlerManager* hm = nullptr );
  virtual void* setAddInfo( void* p );

  virtual void setMemberPtr( TTree* tree,
                             const std::string& branchName,
                             void* dataPtr );
  void print() const {
    std::cout << "Handler: " << this << ' '
              << dataName << ' '
              << dataCode << ' '
              << dataType << ' '
              << dataSize << std::endl;
  }

 protected:

  /** Constructor
   */
  DataHandler( const std::string& name,
               const std::string& code,
               const std::string& type );

  std::string dataName;
  std::string dataCode;
  std::string dataType;
  std::string dataSize;
  conversionType convType;
  void* auxPtr;
  void* addInfo;
  DataReset* dataReset;

 private:

  DataHandler           ( const DataHandler& e ) = delete;
  DataHandler& operator=( const DataHandler& e ) = delete;

};


#endif // NtuTool_Common_DataHandler_h


