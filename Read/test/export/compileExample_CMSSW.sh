rm -f treeAnalyze_Base
c++ `root-config --cflags --glibs` -o treeAnalyze_Base \
    -I ${NTU_TOOL_DIR}/include SimpleAnalyzer.cc SimpleNtuple.cc \
    -L ${NTU_TOOL_DIR}/lib/${SCRAM_ARCH}     -lNtupleTool_${CMSSW_VERSION}
rm -f treeAnalyze_EDM
c++ `root-config --cflags --glibs` -o treeAnalyze_EDM \
    -I ${NTU_TOOL_DIR}/include EDMSimpleAnalyzer.cc SimpleNtuple.cc \
    -L ${NTU_TOOL_DIR}/lib/${SCRAM_ARCH}     -lNtupleTool_${CMSSW_VERSION}
