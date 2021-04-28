#ifndef NANOTableHandler_H
#define NANOTableHandler_H
/** \class NANOTableHandler
 *
 *  Description: 
 *    Base class for auxiliary functions needed to create and fill
 *    NANOAOD tables and columns
 *
 *  $Date: 2020/07/03 18:06:55 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "NtuTool/Read/interface/NANOHandler.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "DataFormats/NanoAOD/interface/FlatTable.h"
namespace edm {
  class EDProducer;
  class Event;
}

//---------------
// C++ Headers --
//---------------
#include <string>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class NANOTableHandler: public NANOHandler {

 public:

  /** Constructor
   */
  NANOTableHandler() {}

  /** Destructor
   */
  ~NANOTableHandler() override {}

  /** Operations
   */
  /// EDProducer function
  virtual void produces( edm::EDProducer* p,
                         const std::string& tableName ) = 0;

  /// Event function
//  virtual void  put( edm::Event& e, const void* p ) = 0;
  virtual void* put( edm::Event& e,
                     const BranchInterfaceData::branch_desc* b, void* t ) = 0;

  /// Add column
  virtual void addC( const void* p, void* t,
                     const std::string& name, const std::string& doc ) = 0;

  static nanoaod::FlatTable* tPtr( void* t ) {
    return static_cast<nanoaod::FlatTable*>( t );
  }

  template<class S, class D>
  static void addC( const S& s, int n, void* t,
                    const std::string& name, const std::string& doc,
                    nanoaod::FlatTable::ColumnType type ) {
    std::vector<D> d( n );
    int i;
    for ( i = 0; i < n; ++i ) d[i] = s[i];
    tPtr( t )->template addColumn<D>( name, d, doc, type, -1 );
  }

 private:

  NANOTableHandler           ( const NANOTableHandler& e ) = delete;
  NANOTableHandler& operator=( const NANOTableHandler& e ) = delete;

};


#endif // NANOTableHandler_H

