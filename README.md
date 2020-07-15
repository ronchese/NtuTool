# NtuTool: a tool for writing and reading ntuples

## To use the package in CMSSW
```
cd ${CMSSW_BASE}/src
git clone git@github.com:ronchese/NtuTool.git
scram b
```

## To use the package outside CMSSW

To install it outside a CMSSW environment use the command 

`${CMSSW_BASE}/src/NtuTool/uty/export.sh` 

then copy the `NtuTool_XX_YY_ZZ.tgz` file shown wherever you prefer and follow these instructions:

```
tar -xzf NtuTool_XX_YY_ZZ.tgz
NtuTool_XX_YY_ZZ/uty/install.sh
NtuTool_XX_YY_ZZ/uty/compile.sh
source NtuTool_XX_YY_ZZ/uty/envset.(sh|csh)
```

The latest command must be issued for any new session. 

To install the package without having a CMSSW working area available, the following instructions can be used:

```
cd /the/path/where/install
wget https://github.com/ronchese/NtuTool/archive/master.zip -O NtuTool.zip
unzip NtuTool.zip
NtuTool-master/uty/export.sh
rm -rf NtuTool-master NtuTool.zip
```

Then go on unpacking the `NtuTool_XX_YY_ZZ.tgz` file and installing as shown above. 

## Examples and common tasks

### Write
An example that write a simple ROOT tree with no use of the tool
functionalities, just as a comparison; it produces `simple_tree.root`
that contains simply the run number
```
cd ${CMSSW_BASE}/src/NtuTool/EDM/test
cmsRun treew.py
```

An example that does the same operation using the tool, to show how 
the code changes; it produces `ntuple_base.root`
```
cd ${CMSSW_BASE}/src/NtuTool/EDM/test
cmsRun sntuw.py
```

An example that write the same informations in and EDM ntuple; 
it produces `ntuple_edm.root`
```
cd ${CMSSW_BASE}/src/NtuTool/EDM/test
cmsRun sedmw.py
```

### Read in a CMSSW area

Compile the examples
```
cd ${CMSSW_BASE}/src/NtuTool/Read/test
compileTest.sh
```
then copy the previously produced .root files

Read `ntuple_base.root`:
```
treeAnalyze_Base ntuList -n 6 -s 2 -a 5 hs.root x
```

```
ntuList    : is a text file with the list of the files to read
hs.root    : is the ouptut histogram file
-n         : set the max number of events to read, if negative its applied 
           : to each input file
-s         : set the number of events to skip, if negative its applied 
           : to each input file
-a         : set the max number of events to accept, if negative its applied 
           : to each input file
x          : a flag to draw the histograms at the end (as coded in plot() )
           : at the end of the execution
-v key val : to set user parameter "key" as "val"
-c cfgFile : to read all parameters from cfgFile

alternatives:

i       a flag to have a ROOT prompt at the end of the execution
j       a flag to draw the histograms at the end (as coded in plot() )
        at the end of the execution and then have a ROOT prompt
b       a flag to simply save the histograms

-v histoMode RECREATE
        to open the output file with RECREATE option (CREATE by default)
```

Read `ntuple_edm.root`:
```
treeAnalyze_EDM edmList -n 6 -s 2 hs.root x
```

### Export examples outside CMSSW

Complete the writing examples described above, then do the following
```
cd ${CMSSW_BASE}/src/NtuTool/Read/test
export/exportExample.sh
```

Then copy the file `examples.tgz` wherever you want

### Read examples outside CMSSW

```
tar -xzf examples.tgz
compileExample.sh
```
(to compile in a CMSSW-independent c++/ROOT environment) or
`compileExample_CMSSW.sh`

(to compile with c++/ROOT as defined in CMSSW)

then run in the same way as before

