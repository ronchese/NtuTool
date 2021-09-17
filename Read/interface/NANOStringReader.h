#ifndef NtuTool_Read_NANOStringReader_h
#define NtuTool_Read_NANOStringReader_h
/** \class NANOStringReader
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
#include "NtuTool/Read/interface/NANOTypeReader.h"

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

class NANOStringReader: public NANOTypeReader<unsigned char> {

 public:

  /** Constructor
   */
  NANOStringReader();

  /** Destructor
   */
  ~NANOStringReader() override;

  /** Operations
   */
  /// get concrete object
  DataHandler* getInstance( const std::string& name,
                            const std::string& code ) override;

 protected:

  NANOStringReader( const std::string& name,
                    const std::string& code,
                    const std::string& type );

 private:

  NANOStringReader           ( const NANOStringReader& e ) = delete;
  NANOStringReader& operator=( const NANOStringReader& e ) = delete;

};

#endif // NtuTool_Read_NANOStringReader_h


