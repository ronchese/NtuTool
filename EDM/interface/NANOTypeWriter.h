#ifndef NANOTypeWriter_H
#define NANOTypeWriter_H
/** \class NANOTypeWriter
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
#include "NtuTool/Common/interface/TypeHandler.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "NtuTool/EDM/interface/NANOTypeWriterManager.h"
#include "NtuTool/EDM/interface/NANOTableHandler.h"
//#include "NtuTool/EDM/interface/NANODataHandler.h"
#include "DataFormats/NanoAOD/interface/FlatTable.h"

//---------------
// C++ Headers --
//---------------
#include <string>
#include <vector>
#include <memory>
#include <iostream>
//              ---------------------
//              -- Class Interface --
//              ---------------------

template <class T>
class NANOTypeWriter: public TypeHandler<T,NANOTypeWriterManager>,
                      public NANOTableHandler {

 public:

  /** Constructor
   */
  NANOTypeWriter( DataReset::resetMode mode ):
                  TypeHandler<T,NANOTypeWriterManager>( mode ) {}
  NANOTypeWriter( DataReset* dr             ):
                  TypeHandler<T,NANOTypeWriterManager>( dr ) {}

  /** Destructor
   */
  ~NANOTypeWriter() override;

  /** Operations
   */
  /// get concrete object
  DataHandler* getInstance( const std::string& name,
                            const std::string& code ) override;

  /// EDProducer function
  void produces( edm::EDProducer* p, const std::string& tableName ) override;

  /// Event function
  void* put( edm::Event& e,
             const BranchInterfaceData::branch_desc* b, void* t ) override;

  /// Utility functions
  void buildPtr( void* p ) override;
  void clearPtr( void* p ) override;

  typedef std::unique_ptr<T> typePtr;
  typedef std::unique_ptr< std::vector<T> > vectPtr;

 protected:

  NANOTypeWriter( const std::string& name,
                  const std::string& code,
                  const std::string& type );
  NANOTypeWriter( bool dum ) {}

//  nanoaod::FlatTable* tPtr( void* t );
  int cSize( const void* p ) override;
  void addC( const void* p, void* t,
             const std::string& name, const std::string& doc ) override;

 private:

  NANOTypeWriter           ( const NANOTypeWriter& e ) = delete;
  NANOTypeWriter& operator=( const NANOTypeWriter& e ) = delete;

  template <class I>
  void addC( const void* p, void* t,
             const std::string& name, const std::string& doc,
             nanoaod::FlatTable::ColumnType type );

  template <class I>
  void addC( const void* p, int n, void* t,
             const std::string& name, const std::string& doc,
             nanoaod::FlatTable::ColumnType type );

};

#include "NtuTool/EDM/interface/NANOTypeWriter.hpp"

#endif // NANOTypeWriter_H



