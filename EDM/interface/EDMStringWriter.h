#ifndef NtuTool_EDM_EDMStringWriter_h
#define NtuTool_EDM_EDMStringWriter_h
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
  ~EDMStringWriter() override;

  /** Operations
   */
  /// get concrete object
  DataHandler* getInstance( const std::string& name,
                            const std::string& code ) override;

  /// Event function
  void put( edm::Event& e, const void* p ) override;

 protected:

  EDMStringWriter( const std::string& name,
                   const std::string& code,
                   const std::string& type );

 private:

  EDMStringWriter           ( const EDMStringWriter& e ) = delete;
  EDMStringWriter& operator=( const EDMStringWriter& e ) = delete;

};

//#include "NtuTool/EDM/interface/EDMStringWriter.hpp"

#endif // NtuTool_EDM_EDMStringWriter_h


