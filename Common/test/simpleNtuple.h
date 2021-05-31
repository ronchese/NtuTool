//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May 25 14:05:58 2021 by ROOT version 6.12/07
// from TTree simpleNtuple/simpleNtuple
// found on file: simple_ntuple.root
//////////////////////////////////////////////////////////

#ifndef simpleNtuple_h
#define simpleNtuple_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class simpleNtuple {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           iRun;
   Int_t           iEvt;
   Int_t           nArr;
   Int_t           iArr[8];   //[nArr]
   vector<int>     *iVec;
   vector<float>   *fVpt;

   // List of branches
   TBranch        *b_iRun;   //!
   TBranch        *b_iEvt;   //!
   TBranch        *b_nArr;   //!
   TBranch        *b_iArr;   //!
   TBranch        *b_iVec;   //!
   TBranch        *b_fVpt;   //!

   simpleNtuple(TTree *tree=0);
   virtual ~simpleNtuple();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef simpleNtuple_cxx
simpleNtuple::simpleNtuple(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("simple_ntuple.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("simple_ntuple.root");
      }
      f->GetObject("simpleNtuple",tree);

   }
   Init(tree);
}

simpleNtuple::~simpleNtuple()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t simpleNtuple::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t simpleNtuple::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void simpleNtuple::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   iVec = 0;
   fVpt = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("iRun", &iRun, &b_iRun);
   fChain->SetBranchAddress("iEvt", &iEvt, &b_iEvt);
   fChain->SetBranchAddress("nArr", &nArr, &b_nArr);
   fChain->SetBranchAddress("iArr", iArr, &b_iArr);
   fChain->SetBranchAddress("iVec", &iVec, &b_iVec);
   fChain->SetBranchAddress("fVpt", &fVpt, &b_fVpt);
   Notify();
}

Bool_t simpleNtuple::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void simpleNtuple::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t simpleNtuple::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef simpleNtuple_cxx
