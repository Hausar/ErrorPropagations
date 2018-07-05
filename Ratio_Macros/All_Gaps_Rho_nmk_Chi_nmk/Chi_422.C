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

void Chi_422() {
double BinValue34A = 0.0;
double BinValue34B = 0.0;
double BinValue42 = 0.0;
double BinValue34A_Entries = 0.0;
double BinValue34B_Entries = 0.0;
double BinValue42_Entries = 0.0;
double BinValue42_Sqrt = 0.0;
double V422_A = 0.0;
double V422_B = 0.0;
double v422_average = 0.0;
double Chi422 = 0.0;
double Sample_BinValue34A = 0.0;
double Sample_BinValue34B = 0.0;
double Sample_BinValue42 = 0.0;
double Sample_BinValue34A_Entries = 0.0;
double Sample_BinValue34B_Entries = 0.0;
double Sample_BinValue42_Entries = 0.0;
double Sample_BinValue42_Sqrt = 0.0;
double Sample_V422_A = 0.0;
double Sample_V422_B = 0.0;
double Sample_v422_average = 0.0;
double Sample_Chi422 = 0.0;
double Chi_Error = 0.0;

    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    TH1D *hChi_422 = new TH1D("hChi_422", "#chi_{4,22}", 200, 0, 200);
    hChi_422->Sumw2();        
    //Open the root.file:
    TFile *file = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_New_Checked.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");
    //==========================================================================
    //**************************************************************************
    //..Chi_4,22    
    // //..eta-Gap
    TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap08Ntrks1bin");  
    TProfile *Cn34A = (TProfile*)list->FindObject("fTprofC34Gap08ANtrks1bin"); 
    TProfile *Cn34B = (TProfile*)list->FindObject("fTprofC34Gap08BNtrks1bin");
    //**************************************************************************
    //..Loop over bins to calculate Rho_4,22:
    for(int bin=1; bin<201; bin++) {
        double Counter = 0.0;
        double error = 0.0;
        BinValue34A = Cn34A->GetBinContent(bin);
        BinValue34B = Cn34B->GetBinContent(bin); 
        BinValue42 = Cn42->GetBinContent(bin);
        BinValue34A_Entries = Cn34A->GetBinEffectiveEntries(bin);
        BinValue34B_Entries = Cn34B->GetBinEffectiveEntries(bin);
        BinValue42_Entries = Cn42->GetBinEffectiveEntries(bin);
        if( BinValue34A_Entries > 1000 && BinValue34B_Entries > 1000 && BinValue42_Entries > 1000 && BinValue42 > 0 ) {
            BinValue42_Sqrt = sqrt(BinValue42);
            V422_A = (BinValue34A) / (BinValue42_Sqrt);
            V422_B = (BinValue34B) / (BinValue42_Sqrt);
            v422_average = ((V422_A + V422_B) / (2));
            Chi422 = ((v422_average) / (BinValue42_Sqrt)); 
        } else {
            cout << "0"; 
            continue;
        }
        for(int sample=1; sample < 11; sample++ ) {
            TString foo_34A(TString::Format("fTprof34_number%dGap08ANtrks1bin", sample));	
            TProfile *prof34A = (TProfile*)list->FindObject(foo_34A);
            TString foo_34B(TString::Format("fTprof34_number%dGap08BNtrks1bin", sample));	
            TProfile *prof34B = (TProfile*)list->FindObject(foo_34B);
            TString foo_42(TString::Format("fTprof42_number%dGap08Ntrks1bin", sample));	
            TProfile *prof42 = (TProfile*)list->FindObject(foo_42);
            Sample_BinValue34A = prof34A->GetBinContent(bin);
            Sample_BinValue34B = prof34B->GetBinContent(bin);
            Sample_BinValue42 = prof42->GetBinContent(bin);
            Sample_BinValue34A_Entries = prof34A->GetBinEffectiveEntries(bin);
            Sample_BinValue34B_Entries = prof34B->GetBinEffectiveEntries(bin);
            Sample_BinValue42_Entries = prof42->GetBinEffectiveEntries(bin);

            if( Sample_BinValue34A_Entries > 100 && Sample_BinValue34B_Entries > 100 && Sample_BinValue42_Entries > 100 && Sample_BinValue42 > 0 ) {
                Counter += 1;
                Sample_BinValue42_Sqrt = sqrt(Sample_BinValue42);
                Sample_V422_A = Sample_BinValue34A / (Sample_BinValue42_Sqrt);
                Sample_V422_B = Sample_BinValue34B / (Sample_BinValue42_Sqrt);
                Sample_v422_average = ((Sample_V422_A + Sample_V422_B) / (2));
                Sample_Chi422 = ((Sample_v422_average) / (Sample_BinValue42_Sqrt)); 
                error += pow(Sample_Chi422 - Chi422, 2);
            } else {
                cout << "0"; 
                continue;
            }
        }
        if(Counter!=0) {
            Chi_Error = sqrt(error / (Counter * Counter) );
            cout << "Counter: " << Counter << endl; 
            hChi_422->SetBinContent(bin, Chi422); 
            hChi_422->SetBinError(bin, Chi_Error); 
            cout << "Bin" << bin << endl;
        } else {
            cout << "0" << endl;
            continue;
        }
    }
    //..Plot:
    hChi_422->Draw();
    //..Gap= 0.0, 0.1, 0.2,..,0.8
    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Chi422_Chi532_AllGaps_NUA+NUE/Chi_n,mk/Chi_nmk_NUA+NUE_A+B.root","UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hChi_422->Write("Gap08_Chi_422_NUA+NUE");
    fileOutput->Close();
    return;
}