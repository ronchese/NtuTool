#ifndef NtuTool_EDM_NtuTool_EDM_NANOStringWriter_h
#define NtuTool_EDM_NtuTool_EDM_NANOStringWriter_h
/** \class NANOStringWriter
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
#include "NtuTool/EDM/interface/NANOTypeWriter.h"

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

class NANOStringWriter: public NANOTypeWriter<unsigned char> {

 public:

  /** Constructor
   */
  NANOStringWriter();

  /** Destructor
   */
  ~NANOStringWriter() override;

  /** Operations
   */
  /// get concrete object
  DataHandler* getInstance( const std::string& name,
                            const std::string& code ) override;

 protected:

  NANOStringWriter( const std::string& name,
                    const std::string& code,
                    const std::string& type );

  int cSize( const void* p ) override;
  void addC( const void* p, void* t,
             const std::string& name, const std::string& doc ) override;

 private:

  NANOStringWriter           ( const NANOStringWriter& e ) = delete;
  NANOStringWriter& operator=( const NANOStringWriter& e ) = delete;

};

//#include "NtuTool/EDM/interface/NANOStringWriter.hpp"

#endif // NtuTool_EDM_NtuTool_EDM_NANOStringWriter_h


