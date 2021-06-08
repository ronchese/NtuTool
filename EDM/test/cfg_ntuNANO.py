import FWCore.ParameterSet.Config as cms

process = cms.Process('ntuWriter')

process.load('PhysicsTools.NanoAOD.nano_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')

### an empty source is used here for testing purposes
process.source = cms.Source("EmptySource",
    numberEventsInRun   = cms.untracked.uint32(10)
)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )

process.simpleNtuTable = cms.EDProducer( 'SimpleNtuNANOModule',
### cut used in the event selection
    nCut = cms.uint32( 6 )
)

### A filter can be included in the path, to pass the event to following
### modules, only for event selected by SimpleNtuEDMModule::fill function.
### Unluckily this is implemented in a largely suboptimal way, using
### a "static bool" flag: it's incompatible with multithread running and
### doesn't comply with CMSSW rules.
### A better solution will be implemented a.s.a.p.
process.ntuFilter = cms.EDFilter('EDMNtupleFilter')

# Output definition
process.out = cms.OutputModule("NanoAODOutputModule",
    compressionAlgorithm = cms.untracked.string('LZMA'),
    compressionLevel = cms.untracked.int32(9),
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('NANOAOD'),
        filterName = cms.untracked.string('')
    ),
    fileName = cms.untracked.string('file:simple_ntuNANO.root'),
    outputCommands = process.NANOAODEventContent.outputCommands
)
### appending tokens to the outputCommands is not necessary for producers
### named "process.xxxxTable:

process.p = cms.Path(process.simpleNtuTable
#                     *process.ntuFilter
)

process.e = cms.EndPath(process.out)

