#ifndef NtuTool_EDM_NANOTableWrapper_h
#define NtuTool_EDM_NANOTableWrapper_h

#include "DataFormats/NanoAOD/interface/FlatTable.h"

class NANOTableWrapper {

 public:

  template<class T>
  static void addColumn( nanoaod::FlatTable* table,
                         const std::string& name,
                         const std::vector<T>& v,
                         const std::string& doc,
                         nanoaod::FlatTable::ColumnType type,
                         int nBits ) {
    table->template addColumn<T>( name, v, doc, type, nBits );
  }
  typedef nanoaod::FlatTable::ColumnType cType;
  static constexpr cType Float = nanoaod::FlatTable::FloatColumn;
  static constexpr cType Int   = nanoaod::FlatTable::IntColumn;
  static constexpr cType UInt8 = nanoaod::FlatTable::UInt8Column;
  static constexpr cType Bool  = nanoaod::FlatTable::BoolColumn;

};


#endif // NtuTool_EDM_NANOTableWrapper_h
