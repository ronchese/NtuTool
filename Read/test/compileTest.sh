rm -f treeAnalyze_Base
c++ `root-config --cflags --glibs` \
    -D NTUPLE_TYPE=BASE \
    -I ${CMSSW_BASE}/src -o treeAnalyze_Base \
    ${CMSSW_BASE}/src/NtuTool/Read/bin/treeAnalyze.cc \
    ${CMSSW_BASE}/src/NtuTool/Common/test/stubs/SimpleNtuple.cc \
    stubs/GenericSimpleAnalyzer.cc \
    -L ${CMSSW_BASE}/lib/${SCRAM_ARCH} \
    -lNtuToolRead -lNtuToolCommon
#c++ `root-config --cflags --glibs` \
#    -I ${CMSSW_BASE}/src -o treeAnalyze_Base \
#    ${CMSSW_BASE}/src/NtuTool/Read/bin/treeAnalyze.cc \
#    ${CMSSW_BASE}/src/NtuTool/Common/test/stubs/SimpleNtuple.cc \
#    stubs/SimpleAnalyzer.cc \
#    -L ${CMSSW_BASE}/lib/${SCRAM_ARCH} \
#    -lNtuToolRead -lNtuToolCommon
rm -f treeAnalyze_EDM
c++ `root-config --cflags --glibs` \
    -D NTUPLE_TYPE=EDM \
    -I ${CMSSW_BASE}/src -o treeAnalyze_EDM \
    ${CMSSW_BASE}/src/NtuTool/Read/bin/treeAnalyze.cc \
    ${CMSSW_BASE}/src/NtuTool/Common/test/stubs/SimpleNtuple.cc \
    stubs/GenericSimpleAnalyzer.cc \
    -L ${CMSSW_BASE}/lib/${SCRAM_ARCH} \
    -lNtuToolRead -lNtuToolCommon
#c++ `root-config --cflags --glibs` \
#    -I ${CMSSW_BASE}/src -o treeAnalyze_EDM \
#    ${CMSSW_BASE}/src/NtuTool/Read/bin/treeAnalyze.cc \
#    ${CMSSW_BASE}/src/NtuTool/Common/test/stubs/SimpleNtuple.cc \
#    stubs/EDMSimpleAnalyzer.cc \
#    -L ${CMSSW_BASE}/lib/${SCRAM_ARCH} \
#    -lNtuToolRead -lNtuToolCommon
rm -f treeFilter
c++ `root-config --cflags --glibs` \
    -I ${CMSSW_BASE}/src -o treeFilter \
    ${CMSSW_BASE}/src/NtuTool/Read/bin/treeAnalyze.cc \
    ${CMSSW_BASE}/src/NtuTool/Common/test/stubs/SimpleNtuple.cc \
    stubs/SimpleFilter.cc \
    -L ${CMSSW_BASE}/lib/${SCRAM_ARCH} \
    -lNtuToolRead -lNtuToolCommon
