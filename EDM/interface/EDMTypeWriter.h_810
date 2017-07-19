#ifndef EDMTypeWriter_H
#define EDMTypeWriter_H
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
#include "NtuTool/Common/interface/DataHandler.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------


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
class EDMTypeWriter: public DataHandler {

 public:

  /** Constructor
   */
  EDMTypeWriter();

  /** Destructor
   */
  virtual ~EDMTypeWriter();

  /** Operations
   */
  /// get concrete object
  virtual DataHandler* getInstance( const std::string& name,
                                    const std::string& code );

  /// EDProducer function
  virtual void produces( edm::EDProducer* p );

  /// Event function
  virtual void put( edm::Event& e, const void* p );

  /// Utility functions
  virtual void buildPtr( void* p );
  virtual void clearPtr( void* p );
  virtual void* setAuxPtr( void* p, DataHandlerManager* hm = 0 );

  typedef std::unique_ptr<T> typePtr;
  typedef std::unique_ptr< std::vector<T> > vectPtr;

 protected:

  EDMTypeWriter( const std::string& name,
                 const std::string& code,
                 const std::string& type );
  EDMTypeWriter( bool dum );

  T* dummyPtr;

 private:

  EDMTypeWriter( const EDMTypeWriter& e );
  EDMTypeWriter& operator=( const EDMTypeWriter& e );

};

#include "NtuTool/EDM/interface/EDMTypeWriter.hpp"

#endif // EDMTypeWriter_H



