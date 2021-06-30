#ifndef NtuTool_Read_EDMStringReader_h
#define NtuTool_Read_EDMStringReader_h
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
  ~EDMStringReader() override;

  /** Operations
   */
  /// Read functions
  void process( void* p ) override;

  /// get concrete object
  DataHandler* getInstance( const std::string& name,
                            const std::string& code ) override;

  /// Utility functions
  void* setAuxPtr( void* p, DataHandlerManager* hm ) override;

 protected:

  EDMStringReader( const std::string& name,
                   const std::string& code,
                   const std::string& type );

 private:

  EDMStringReader           ( const EDMStringReader& e ) = delete;
  EDMStringReader& operator=( const EDMStringReader& e ) = delete;

};

//#include "NtuTool/Read/interface/EDMStringReader.hpp"

#endif // NtuTool_Read_EDMStringReader_h


