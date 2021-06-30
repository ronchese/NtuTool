/*
 *  See header file for a description of this class.
 *
 *  $Date: 2011/03/01 18:06:55 $
 *  $Revision: 1.1 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
//#include "NtuTool/Common/interface/TreeTypeHandler.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "NtuTool/Common/interface/DataHandlerManager.h"
#include "TTree.h"

//---------------
// C++ Headers --
//---------------
#include <iostream>
#include <sstream>
#include <string>

//-------------------
// Initializations --
//-------------------


//----------------
// Constructors --
//----------------
template <class T,class Manager>
TreeTypeHandler<T,Manager>::TreeTypeHandler( const std::string& name,
                                             const std::string& code,
                                             const std::string& type ):
 DataHandler( name, code, type ) {
}

//--------------
// Destructor --
//--------------
template <class T,class Manager>
TreeTypeHandler<T,Manager>::~TreeTypeHandler() {
}

//--------------
// Operations --
//--------------
template <class T,class Manager>
DataHandler* TreeTypeHandler<T,Manager>::getInstance(
                                         const std::string& name,
                                         const std::string& code ) {
  TreeTypeHandler<T,Manager>* handler =
                              new TreeTypeHandler<T,Manager>( name,
                                                              code,
                                                              this->dataType );
  handler->dataReset = this->dataReset;
  return handler;
}


template <class T,class Manager>
TBranch* TreeTypeHandler<T,Manager>::branch( TTree* tree,
                                             const std::string* name, void** p,
                                             int bufferSize, int splitLevel ) {
  return tree->Branch( name->c_str(),
                       static_cast<T**>( static_cast<void*> ( p ) ),
                       bufferSize, splitLevel );
}

