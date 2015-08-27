#ifndef EDMStringWriter_H
#define EDMStringWriter_H
/** \class EDMStringWriter
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
#include "NtuTool/EDM/interface/EDMTypeWriter.h"

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

class EDMStringWriter: public EDMTypeWriter<std::string> {

 public:

  /** Constructor
   */
  EDMStringWriter();

  /** Destructor
   */
  virtual ~EDMStringWriter();

  /** Operations
   */
  /// get concrete object
  virtual DataHandler* getInstance( const std::string& name,
                                    const std::string& code );
  /// Event function
  virtual void put( edm::Event& e, const void* p );

  /// Utility functions
//  virtual void reset( void* p );
//  virtual void* setAuxPtr( void* p, DataHandlerManager* hm = 0 );

 protected:

  EDMStringWriter( const std::string& name,
                   const std::string& code,
                  const std::string& type );
  EDMStringWriter( bool dum );

 private:

  EDMStringWriter( const EDMStringWriter& e );
  EDMStringWriter& operator=( const EDMStringWriter& e );

};

//#include "NtuTool/EDM/interface/EDMStringWriter.hpp"

#endif // EDMStringWriter_H

