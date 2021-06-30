#ifndef NtuTool_Read_EDMTypeReader_h
#define NtuTool_Read_EDMTypeReader_h
/** \class EDMTypeReader
 *
 *  Description: 
 *    Base class to read data from EDM ntuples
 *
 *  $Date: 2011/03/01 18:09:03 $
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
#include "NtuTool/Read/interface/EDMTypeReaderManager.h"


//---------------
// C++ Headers --
//---------------
#include <string>

//              ---------------------
//              -- Class Interface --
//              ---------------------

template <class T>
class EDMTypeReader: public TypeHandler<T,EDMTypeReaderManager> {

 public:

  /** Constructor
   */
  EDMTypeReader( DataReset::resetMode mode ):
                 TypeHandler<T,EDMTypeReaderManager>( mode ) {}
  EDMTypeReader( DataReset* dr ):
                 TypeHandler<T,EDMTypeReaderManager>( dr )   {}

  /** Destructor
   */
  virtual ~EDMTypeReader();

  /** Operations
   */
  /// get concrete object
  DataHandler* getInstance( const std::string& name,
                            const std::string& code ) override;

  /// Read functions
  void process( void* p ) override;

  /// Utility functions
  void* setAuxPtr( void* p, DataHandlerManager* hm ) override;

 protected:

  EDMTypeReader( const std::string& name,
                 const std::string& code,
                 const std::string& type );
  EDMTypeReader( bool dum ) {}

 private:

  EDMTypeReader           ( const EDMTypeReader& e ) = delete;
  EDMTypeReader& operator=( const EDMTypeReader& e ) = delete;

};

#include "NtuTool/Read/interface/EDMTypeReader.hpp"

#endif // NtuTool_Read_EDMTypeReader_h




