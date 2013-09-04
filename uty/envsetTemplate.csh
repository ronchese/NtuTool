setenv NTU_TOOL_DIR INSTALLDIR
eval `echo $LD_LIBRARY_PATH | awk -F: '{for(i=1;i<=NF;++i)print $i}' | grep -v NtuTool | awk 'BEGIN{printf("setenv LD_LIBRARY_PATH ")} (NR==1){printf($0)} (NR>1){printf(":"$0)} END{print " ;"}'`
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${NTU_TOOL_DIR}/lib
if ( `printenv | grep SCRAM_ARCH | awk -F= '{print $1}'` == "SCRAM_ARCH" ) then
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${NTU_TOOL_DIR}/lib/${SCRAM_ARCH}
endif
