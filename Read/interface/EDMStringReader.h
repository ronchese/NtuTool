#ifndef EDMStringReader_H
#define EDMStringReader_H
/** \class EDMStringReader
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
#include "NtuTool/Read/interface/EDMTypeReader.h"

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

class EDMStringReader: public EDMTypeReader<std::string> {

 public:

  /** Constructor
   */
  EDMStringReader();

  /** Destructor
   */
  virtual ~EDMStringReader();

  /** Operations
   */
  /// Read functions
  virtual void process( void* p );

  /// get concrete object
  virtual DataHandler* getInstance( const std::string& name,
                                    const std::string& code );

  /// Utility functions
  virtual void* setAuxPtr( void* p, DataHandlerManager* hm = 0 );

 protected:

  EDMStringReader( const std::string& name,
                  const std::string& code,
                  const std::string& type );
  EDMStringReader( bool dum );

 private:

  EDMStringReader( const EDMStringReader& e );
  EDMStringReader& operator=( const EDMStringReader& e );

};

//#include "NtuTool/Read/interface/EDMStringReader.hpp"

#endif // EDMStringReader_H

