#ifndef EDMXYZVectorReader_H
#define EDMXYZVectorReader_H
/** \class EDMXYZVectorReader
 *
 *  Description: 
 *    Base class to select type-specific calls to EDProducer and Event
 *    functions
 *
 *  $Date: 2011/03/01 18:09:03 $
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
#include "NtuTool/Common/interface/Math.h"

//---------------
// C++ Headers --
//---------------
#include <string>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class EDMXYZVectorReader: public EDMTypeReader<math::XYZVector> {

 public:

  /** Constructor
   */
  EDMXYZVectorReader();

  /** Destructor
   */
  virtual ~EDMXYZVectorReader();

  /** Operations
   */
  /// Utility functions
  /// get concrete object
  virtual DataHandler* getInstance( const std::string& name,
                                    const std::string& code );

  /// Utility functions
  virtual void setMemberPtr( TTree* tree,
                             const std::string& branchName,
                             void* dataPtr );

 protected:

  EDMXYZVectorReader( const std::string& name,
                      const std::string& code,
                      const std::string& type );
  EDMXYZVectorReader( bool dum );

 private:

  EDMXYZVectorReader( const EDMXYZVectorReader& e );
  EDMXYZVectorReader& operator=( const EDMXYZVectorReader& e );

};

#endif // EDMXYZVectorReader_H



