import FWCore.ParameterSet.Config as cms

process = cms.Process("ntuWriter")

### an empty source is used here for testing purposes
process.source = cms.Source("EmptySource",
    numberEventsInRun   = cms.untracked.uint32(10)
)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )

### open a ROOT file via TFileService
process.TFileService = cms.Service('TFileService',
    fileName = cms.string('simple_ntuple.root'),
    closeFileFast = cms.untracked.bool(True)
)

process.simpleNtupleModule = cms.EDAnalyzer( 'SimpleNtupleModule',
### if the file name is given as "-" use the TFileService file
    fileName = cms.untracked.string('-')
#    fileName = cms.untracked.string('another_ntuple.root')
   ,
### if the ROOT file is opened via TFileService then "fileMode" is neglected
    fileMode = cms.untracked.string('RECREATE')
   ,
### cut used in the event selection
    nCut = cms.uint32( 6 )
)


process.p = cms.Path(process.simpleNtupleModule)

