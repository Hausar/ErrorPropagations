//Macro To Calculate the Rho_V4 and Rho_V5:
//Root file:
#include <TFile.h>
#include <TMath.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TProfile.h>
#include <TComplex.h>
#include <iostream>
using namespace std;  

void Chi_532() {
double BinValue35A = 0.0;
double BinValue35B = 0.0;
double BinValue43 = 0.0;
double BinValue35A_Entries = 0.0;
double BinValue35B_Entries = 0.0;
double BinValue43_Entries = 0.0;
double BinValue43_Sqrt = 0.0;
double V532_A = 0.0;
double V532_B = 0.0;
double v532_average = 0.0;
double Chi532 = 0.0;
double Sample_BinValue35A = 0.0;
double Sample_BinValue35B = 0.0;
double Sample_BinValue43 = 0.0;
double Sample_BinValue35A_Entries = 0.0;
double Sample_BinValue35B_Entries = 0.0;
double Sample_BinValue43_Entries = 0.0;
double Sample_BinValue43_Sqrt = 0.0;
double Sample_V532_A = 0.0;
double Sample_V532_B = 0.0;
double Sample_v532_average = 0.0;
double Sample_Chi532 = 0.0;
double Chi_Error = 0.0;

    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    TH1D *hChi_532 = new TH1D("hChi_532", "#chi_{5,32}", 200, 0, 200);
    hChi_532->Sumw2();        
    //Open the root.file:
    TFile *file = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_New_Checked.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");
    //==========================================================================
    //**************************************************************************
    //..Chi_5,32    
    // //..eta-Gap
    TProfile *Cn43 = (TProfile*)list->FindObject("fTprofC43Gap00Ntrks1bin");  
    TProfile *Cn35A = (TProfile*)list->FindObject("fTprofC35Gap00ANtrks1bin"); 
    TProfile *Cn35B = (TProfile*)list->FindObject("fTprofC35Gap00BNtrks1bin");
    //**************************************************************************
    //..Loop over bins to calculate Rho_4,22:
    for(int bin=1; bin<201; bin++) {
        double Counter = 0.0;
        double error = 0.0;
        BinValue35A = Cn35A->GetBinContent(bin);
        BinValue35B = Cn35B->GetBinContent(bin); 
        BinValue43 = Cn43->GetBinContent(bin);
        BinValue35A_Entries = Cn35A->GetBinEffectiveEntries(bin);
        BinValue35B_Entries = Cn35B->GetBinEffectiveEntries(bin);
        BinValue43_Entries = Cn43->GetBinEffectiveEntries(bin);
        if( BinValue35A_Entries > 1000 && BinValue35B_Entries > 1000 && BinValue43_Entries > 1000 && BinValue43 > 0 ) {
            BinValue43_Sqrt = sqrt(BinValue43);
            V532_A = (BinValue35A) / (BinValue43_Sqrt);
            V532_B = (BinValue35B) / (BinValue43_Sqrt);
            v532_average = ((V532_A + V532_B) / (2));
            Chi532 = ((v532_average) / (BinValue43_Sqrt)); 
        } else {
            cout << "0"; 
            continue;
        }
        for(int sample=1; sample < 11; sample++ ) {
            TString foo_35A(TString::Format("fTprof35_number%dGap00ANtrks1bin", sample));	
            TProfile *prof35A = (TProfile*)list->FindObject(foo_35A);
            TString foo_35B(TString::Format("fTprof35_number%dGap00BNtrks1bin", sample));	
            TProfile *prof35B = (TProfile*)list->FindObject(foo_35B);
            TString foo_43(TString::Format("fTprof43_number%dGap00Ntrks1bin", sample));	
            TProfile *prof43 = (TProfile*)list->FindObject(foo_43);
            Sample_BinValue35A = prof35A->GetBinContent(bin);
            Sample_BinValue35B = prof35B->GetBinContent(bin);
            Sample_BinValue43 = prof43->GetBinContent(bin);
            Sample_BinValue35A_Entries = prof35A->GetBinEffectiveEntries(bin);
            Sample_BinValue35B_Entries = prof35B->GetBinEffectiveEntries(bin);
            Sample_BinValue43_Entries = prof43->GetBinEffectiveEntries(bin);

            if( Sample_BinValue35A_Entries > 100 && Sample_BinValue35B_Entries > 100 && Sample_BinValue43_Entries > 100 && Sample_BinValue43 > 0 ) {
                Counter += 1;
                Sample_BinValue43_Sqrt = sqrt(Sample_BinValue43);
                Sample_V532_A = Sample_BinValue35A / (Sample_BinValue43_Sqrt);
                Sample_V532_B = Sample_BinValue35B / (Sample_BinValue43_Sqrt);
                Sample_v532_average = ((Sample_V532_A + Sample_V532_B) / (2));
                Sample_Chi532 = ((Sample_v532_average) / (Sample_BinValue43_Sqrt)); 
                error += pow(Sample_Chi532 - Chi532, 2);
            } else {
                cout << "0"; 
                continue;
            }
        }
        if(Counter!=0) {
            Chi_Error = sqrt(error / (Counter * Counter) );
            cout << "Counter: " << Counter << endl; 
            hChi_532->SetBinContent(bin, Chi532); 
            hChi_532->SetBinError(bin, Chi_Error); 
            cout << "Bin" << bin << endl;
        } else {
            cout << "0" << endl;
            continue;
        }
    }
    //..Plot:
    hChi_532->Draw();
    //..Gap= 0.0, 0.1, 0.2,..,0.8
    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Chi422_Chi532_AllGaps_NUA+NUE/Chi_n,mk/Chi_nmk_NUA+NUE_A+B.root","UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hChi_532->Write("Gap00_Chi_532_NUA+NUE");
    fileOutput->Close();
    return;
}