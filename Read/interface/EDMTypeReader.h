#ifndef EDMTypeReader_H
#define EDMTypeReader_H
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
#include "NtuTool/Common/interface/DataHandler.h"

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

template <class T>
class EDMTypeReader: public DataHandler {

 public:

  /** Constructor
   */
  EDMTypeReader();

  /** Destructor
   */
  virtual ~EDMTypeReader();

  /** Operations
   */
  /// get concrete object
  virtual DataHandler* getInstance( const std::string& name,
                                    const std::string& code );

  /// Read functions
  virtual void process( void* p );

  /// Utility functions
  virtual void* setAuxPtr( void* p, DataHandlerManager* hm = 0 );

 protected:

  EDMTypeReader( const std::string& name,
                 const std::string& code,
                 const std::string& type );
  EDMTypeReader( bool dum );

  T* dummyPtr;

 private:

  EDMTypeReader( const EDMTypeReader& e );
  EDMTypeReader& operator=( const EDMTypeReader& e );

};

#include "NtuTool/Read/interface/EDMTypeReader.icc"

#endif // EDMTypeReader_H



