#ifndef NtuTool_Read_NANOHandler_h
#define NtuTool_Read_NANOHandler_h
/** \class NANOHandler
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


//------------------------------------
// Collaborating Class Declarations --
//------------------------------------


//---------------
// C++ Headers --
//---------------
#include <string>
#include <vector>
#include <iostream>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class NANOHandler {

 public:

  /** Constructor
   */
  NANOHandler() {}

  /** Destructor
   */
  virtual ~NANOHandler() {}

  /** Operations
   */
  virtual int cSize( const void* p ) = 0;

  struct AdditionalInfo {
    void* arrayPtr;
    int maxSize;
  };

  template <class S, class D>
  static void convertToVector( const void* p, void* q, int n ) {
    const
    S* sp = static_cast<const S*>( p );
    std::vector<D>* v = static_cast<std::vector<D>*>( q );
    v->clear();
    v->reserve( n );
    while ( n-- ) v->push_back( *sp++ );
    return;
  }

  template <class S, class D>
  static void convertToArray( const void* p, void* q, int n ) {
    const
    S* sp = static_cast<const S*>( p );
    D* sq = static_cast<D*>( q );
    while ( n-- ) *sq++ = *sp++;
    return;
  }

  class NANOConvert {
   public:
    NANOConvert() {}
    virtual ~NANOConvert() {}
    virtual void operator()( const void* p, void* q, int n ) const = 0;
  };

  template<class S, class D>
  class ConvertToVector: public NANOConvert {
   public:
    ConvertToVector() {}
    ~ConvertToVector() override {}
    void operator()( const void* p, void* q, int n ) const override {
      convertToVector<S,D>( p, q, n );
    }
  };
  template<class S, class D>
  class ConvertToArray: public NANOConvert {
   public:
    ConvertToArray() {}
    ~ConvertToArray() override {}
    void operator()( const void* p, void* q, int n ) const override {
      convertToArray<S,D>( p, q, n );
    }
  };
  class ConvertToString: public NANOConvert {
   public:
    ConvertToString() {}
    ~ConvertToString() override {}
    void operator()( const void* p, void* q, int n ) const override {
      std::string* s = static_cast<std::string*>( q );
      s->clear();
      s->reserve( n + 1 );
      s->insert( 0, static_cast<const char*>( p ), n );
    }
  };

  static const int nanoTableName;
  static const int nanoTableSize;
  static const int nanoBranchDoc;

 private:

  NANOHandler           ( const NANOHandler& e ) = delete;
  NANOHandler& operator=( const NANOHandler& e ) = delete;

};


#endif // NtuTool_Read_NANOHandler_h


