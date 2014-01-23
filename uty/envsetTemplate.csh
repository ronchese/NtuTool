setenv NTU_TOOL_DIR INSTALLDIR
setenv LD_LIBRARY_PATH `printenv | grep LD_LIBRARY_PATH | awk -F= '($1=="LD_LIBRARY_PATH"){print $2}'`
eval `echo $LD_LIBRARY_PATH | awk -F: '{for(i=1;i<=NF;++i)print $i}' | grep -v NtuTool | awk 'BEGIN{printf("setenv LD_LIBRARY_PATH ")} {printf($0":")} END{print " ;"}'`
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}${NTU_TOOL_DIR}/lib
if ( $?SCRAM_ARCH ) then
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}":"
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}${NTU_TOOL_DIR}/lib/${SCRAM_ARCH}
endif
