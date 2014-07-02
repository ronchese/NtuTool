import FWCore.ParameterSet.Config as cms

process = cms.Process("PIPPO")

process.source = cms.Source("EmptyIOVSource",
    timetype   = cms.string('runnumber'),
    firstValue = cms.uint64(123456),
    lastValue  = cms.uint64(123465),
    interval   = cms.uint64(1)
)


process.simpleEDMWriter = cms.EDProducer(
    "SimpleEDMWriter"
)


process.out = cms.OutputModule(
    "PoolOutputModule",
    fileName = cms.untracked.string('ntuple_edm.root'),
    outputCommands = cms.untracked.vstring(
      "drop *",
      "keep *_simpleEDMWriter_*_*"      
    )
)

process.p = cms.Path(process.simpleEDMWriter)
process.e = cms.EndPath(process.out)

