import FWCore.ParameterSet.Config as cms

process = cms.Process("ntuWriter")

### an empty source is used here for testing purposes
process.source = cms.Source("EmptySource",
    numberEventsInRun   = cms.untracked.uint32(10)
)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )

process.simpleNtuEDMModule = cms.EDProducer( 'SimpleNtuEDMModule',
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
process.out = cms.OutputModule(
    "PoolOutputModule",
    fileName = cms.untracked.string('simple_ntuEDM.root'),
    outputCommands = cms.untracked.vstring(
      "drop *",
      "keep *_simpleNtuEDMModule_*_*"
    )
)


process.p = cms.Path(process.simpleNtuEDMModule
#                     *process.ntuFilter
)

process.e = cms.EndPath(process.out)

