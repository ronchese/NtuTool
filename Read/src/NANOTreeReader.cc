#include <iostream>

#include "NtuTool/Read/interface/NANOTreeReader.h"
#include "NtuTool/Read/interface/NANOTypeReaderManager.h"
#include "NtuTool/Read/interface/NANOHandler.h"
#include "NtuTool/Common/interface/DataHandlerManager.h"
#include "NtuTool/Common/interface/DataHandler.h"
#include "NtuTool/Common/interface/DataConvert.h"

#include "TFile.h"
#include "TChain.h"


NANOTreeReader::NANOTreeReader() {
  treeName = "Events";
  handlerManager = new NANOTypeReaderManager;
}


NANOTreeReader::~NANOTreeReader() {
}


void NANOTreeReader::initRead( TTree* tree ) {

  currentTree() = tree;
  currentTree()->SetMakeClass(1);

  branch_iterator iter = treeBegin();
  branch_iterator iend = treeEnd();
  while ( iter != iend ) {
    branch_desc* bDesc = *iter++;
    DataHandler* handler = handlerManager->setHandler( bDesc );
    if ( bDesc->splitLevel < 0 )
        handler->setAuxPtr( bDesc->dataPtr, handlerManager );
    bDesc->dataHandler = handler;
  }
  void* sizePtr = nullptr;
  std::string tName;
  int aSize = -1;
  branch_desc* bSize = nullptr;
  iter = treeBegin();
  while ( iter != iend ) {
    branch_desc* bDesc = *iter++;
    if ( bDesc->firstBranch == nullptr ) {
      tName = BranchInterfaceData::getInfo( bDesc, NANOHandler::nanoTableName,
                                           *bDesc->branchName );
      aSize = BranchInterfaceData::getInfo( bDesc, NANOHandler::nanoTableSize,
                                            10000 );
      sizePtr = nullptr;
      bSize = nullptr;
    }
    DataHandler* handler = bDesc->dataHandler;
    if ( handler == nullptr ) continue;
    int dSize = dynamic_cast<NANOHandler*>( handler )->cSize( nullptr );
    bool tSize = false; // native variable followed by array or std container
    bool mSize = false; // std container as first branch in a table
    std::string bName = "";
    if ( dSize < 0 ) {
      const branch_desc* nextBranch = bDesc->nextBranch;
      if ( nextBranch != nullptr ) {
        DataHandler* nextHandler = nextBranch->dataHandler;
        if ( nextHandler != nullptr ) {
          dSize = dynamic_cast<NANOHandler*>( nextHandler )->cSize( nullptr );
          if ( dSize >= 0 ) tSize = true;
	}
      }
    }
    else
    if ( ( handler->getConv() != DataHandler::copyVector ) &&
         ( bDesc->firstBranch == nullptr ) ) mSize = true;
    if ( tSize ) {
      bName = "n" + tName;
      bSize = bDesc;
    }
    else {
      if ( mSize ) {
        sizePtr = new unsigned int( 0 );
        std::string sizeBName = "n" + tName;
        currentTree()->SetBranchAddress( sizeBName.c_str(),
                                         static_cast<unsigned int*>( sizePtr ),
                                         new TBranch* );
        addInts.push_back( static_cast<unsigned int*>( sizePtr ) );
      }
      bName = tName + "_" + handler->getName();
    }
    if ( bDesc->splitLevel < 0 ) {
      NANOHandler::AdditionalInfo* aInfo = new NANOHandler::AdditionalInfo;
      if ( handler->getConv() == DataHandler::copyVector ) {
        aInfo->maxSize = aSize;
      }
      else {
        aInfo->maxSize = 1;
      }
      handler->setAddInfo( aInfo );
      currentTree()->SetBranchAddress( bName.c_str(),
                                       ( aInfo->arrayPtr == nullptr ?
                                         bDesc->dataPtr : aInfo->arrayPtr ),
                                       bDesc->branchPtr );
    }
    else {
      handler->setAuxPtr( sizePtr, handlerManager );
      NANOHandler::AdditionalInfo* aInfo = new NANOHandler::AdditionalInfo;
      aInfo->maxSize = aSize;
      handler->setAddInfo( aInfo );
      std::string tmpName = bName;
      currentTree()->SetBranchAddress( tmpName.c_str(), aInfo->arrayPtr,
                                                        bDesc->branchPtr );
    }
    if ( bSize != nullptr ) sizePtr = bSize->dataPtr;
  }

  fillBranchMap();

  return;

}

