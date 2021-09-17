#ifndef NtuTool_Read_NANOTypeReader_h
#define NtuTool_Read_NANOTypeReader_h
/** \class NANOTypeReader
 *
 *  Description: 
 *    Base class to read data from NANOAOD
 *
 *  $Date: 2020/07/23 18:09:03 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "NtuTool/Read/interface/NANOHandler.h"
#include "NtuTool/Common/interface/TypeHandler.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "NtuTool/Read/interface/NANOTypeReaderManager.h"
#include "NtuTool/Common/interface/DataConvert.h"


//---------------
// C++ Headers --
//---------------
#include <string>
#include <iostream>

//              ---------------------
//              -- Class Interface --
//              ---------------------

template <class T>
class NANOTypeReader: public TypeHandler<T,NANOTypeReaderManager>,
                      public NANOHandler {

 public:

  /** Constructor
   */
  NANOTypeReader( DataReset::resetMode mode, NANOConvert* conv ):
                  TypeHandler<T,NANOTypeReaderManager>( mode ),
                  nConv( conv ) {}
  NANOTypeReader( DataReset* dr, NANOConvert* conv ):
                  TypeHandler<T,NANOTypeReaderManager>( dr ),
                  nConv( conv ) {}

  /** Destructor
   */
  ~NANOTypeReader() override;

  /** Operations
   */
  /// get concrete object
  DataHandler* getInstance( const std::string& name,
                            const std::string& code ) override;

  /// Read functions
  void process( void* p ) override;

  /// Utility functions
  void* setAddInfo( void* p ) override;

 protected:

  NANOTypeReader( const std::string& name,
                  const std::string& code,
                  const std::string& type );
  NANOTypeReader( bool dum ) {}

  NANOConvert* nConv;

  int cSize( const void* p ) override;
  void* tmpArray( int n );
  void translate( void* sPtr, void* dPtr, int n );

 private:

  NANOTypeReader           ( const NANOTypeReader& e ) = delete;
  NANOTypeReader& operator=( const NANOTypeReader& e ) = delete;

};

#include "NtuTool/Read/interface/NANOTypeReader.hpp"

#endif // NtuTool_Read_NANOTypeReader_h

