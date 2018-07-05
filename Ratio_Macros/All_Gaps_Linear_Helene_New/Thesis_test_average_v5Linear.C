
//Macro To Calculate the V5_Linear for all gaps:
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

void Thesis_test_average_v5Linear() {
    double BinValue35A = 0.0; 
    double BinValue35B = 0.0;
    double BinValue25 = 0.0;
    double BinValue43 = 0.0;
    double BinValue35A_Sample = 0.0;
    double BinValue35B_Sample  = 0.0;
    double BinValue25_Sample = 0.0;
    double BinValue43_Sample = 0.0;
    double BinValue35A_Entries = 0.0;
    double BinValue35B_Entries = 0.0;
    double BinValue25_Entries = 0.0;
    double BinValue43_Entries = 0.0;
    double BinValue25_Sample = 0.0;
    double BinValue43_Sample = 0.0;
    double BinValue35A_Entries_Sample = 0.0;
    double BinValue35B_Entries_Sample = 0.0;
    double BinValue25_Entries_Sample = 0.0;
    double BinValue43_Entries_Sample = 0.0;
    double BinValue25_Sqrt = 0.0;
    double BinValue43_Sqrt = 0.0;
    double BinValue25_Sample_Sqrt = 0.0;
    double BinValue43_Sample_Sqrt = 0.0;
    double Linear = 0.0;
    double Linear_Error = 0.0;
    double Linear_Sample = 0.0;
    double v532_average = 0.0;
    double v532_average_sample = 0.0;
    double Linear_average = 0.0; 
    double Linear_average_sample = 0.0;
    double V532_A = 0.0;
    double V532_B = 0.0;
    double V532_A_Sample = 0.0;
    double V532_B_Sample = 0.0;

    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd(); 
    TH1D *hCLinear = new TH1D("hCLinear", " The Linear Response V5^{L} ", 200, 0, 200); 
    hCLinear->Sumw2();
    //Open the latest root.file:
    TFile *file = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_New_Checked.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");
    
    //**************************************************************************
    //..open the TProfiles:
    //..Gaps
    TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap00Ntrks1bin");
    TProfile *Cn43 = (TProfile*)list->FindObject("fTprofC43Gap00Ntrks1bin");  
    TProfile *Cn35A = (TProfile*)list->FindObject("fTprofC35Gap00ANtrks1bin");
    TProfile *Cn35B = (TProfile*)list->FindObject("fTprofC35Gap00BNtrks1bin");
    //**************************************************************************
    //..Linear Response calculation:****
    // *********************************
    //.. The L and NL are uncorrelated means they are perpendicular so they make 
    //a 90 triangle when the "Hypotenuse" is v4 (sqrt(<<2>>_{4|-4})) 
    ///  and the two others are L response and Non-Linear response which is the 
    // NL----->  "<<3>> / sqrt(<<4>>)" so by 
    ///  using the "Pythagorean theoerem" the v4^2 = L^2 + NL ^2 
    /////              L^2 = v4^2 - NL^2  we don't have L response so
    /////              L = sqrt (v4^2 - NL^2) 
    ///// Here v4 is sqrt( <<2>>_{4,-4})  &&    NL is <<3>> /sqrt(<<4>> )
    //**************************************************************************
    for(int bin=1; bin<201; bin++) {        
        double Counter = 0.0;
        double error_L = 0.0;
        BinValue25 = Cn25->GetBinContent(bin);
        BinValue43 = Cn43->GetBinContent(bin);
        BinValue35A = Cn35A->GetBinContent(bin);
        BinValue35B = Cn35B->GetBinContent(bin);
        BinValue25_Entries = Cn25->GetBinEffectiveEntries(bin);
        BinValue35A_Entries = Cn35A->GetBinEffectiveEntries(bin);
        BinValue35B_Entries = Cn35B->GetBinEffectiveEntries(bin);
        BinValue43_Entries = Cn43->GetBinEffectiveEntries(bin);
        if( BinValue25_Entries > 1000 && BinValue35A_Entries > 1000 && BinValue35B_Entries > 1000 && BinValue43_Entries > 1000 && BinValue25 > 0 && BinValue43 > 0) {
            BinValue43_Sqrt = sqrt(BinValue43);
            BinValue25_Sqrt = sqrt(BinValue25);
            V532_A = ((BinValue35A) / (BinValue43_Sqrt));
            V532_B = ((BinValue35B) / (BinValue43_Sqrt));
            v532_average = ((V532_A + V532_B) / (2));
            Linear = pow(BinValue25_Sqrt, 2) - pow(v532_average, 2);
            if(Linear > 0 ) {
                Linear_average = sqrt(Linear);
            } else {
                continue;
            }   
        } else {
            cout << "0" << endl; 
            continue;
        }
        for (int sample=1; sample<11; sample++) {
            //..Gap = 0.0-0.8
            TString foo_35A(TString::Format("fTprof35_number%dGap00ANtrks1bin", sample));
            TProfile *prof35A = (TProfile*)list->FindObject(foo_35A);
            TString foo_35B(TString::Format("fTprof35_number%dGap00BNtrks1bin", sample));
            TProfile *prof35B = (TProfile*)list->FindObject(foo_35B);
            TString foo_25(TString::Format("fTprof25_number%dGap00Ntrks1bin", sample));
            TProfile *prof25 = (TProfile*)list->FindObject(foo_25);
            TString foo_43(TString::Format("fTprof43_number%dGap00Ntrks1bin", sample));	
            TProfile *prof43 = (TProfile*)list->FindObject(foo_43);
            BinValue35A_Sample = prof35A->GetBinContent(bin);
            BinValue35B_Sample = prof35B->GetBinContent(bin);
            BinValue25_Sample = prof25->GetBinContent(bin);
            BinValue43_Sample = prof43->GetBinContent(bin);
            BinValue35A_Entries_Sample = prof35A->GetBinEffectiveEntries(bin);
            BinValue35B_Entries_Sample = prof35B->GetBinEffectiveEntries(bin);
            BinValue25_Entries_Sample = prof25->GetBinEffectiveEntries(bin);
            BinValue43_Entries_Sample = prof43->GetBinEffectiveEntries(bin);
            if( BinValue25_Entries_Sample > 100 && BinValue35A_Entries_Sample > 100 && BinValue35B_Entries_Sample > 100 && BinValue43_Entries_Sample > 100 && BinValue25_Sample > 0 && BinValue43_Sample > 0 ) {
                cout << "1";
                BinValue25_Sample_Sqrt = sqrt(BinValue25_Sample);
                BinValue43_Sample_Sqrt = sqrt(BinValue43_Sample);
                V532_A_Sample = ((BinValue35A_Sample) / (BinValue43_Sample_Sqrt));
                V532_B_Sample = ((BinValue35B_Sample) / (BinValue43_Sample_Sqrt));
                v532_average_sample = ((V532_A_Sample + V532_B_Sample) / (2));
                Linear_Sample = pow(BinValue25_Sample_Sqrt, 2) - pow(v532_average_sample, 2); 
                if(Linear_Sample > 0 ) {
                    Counter += 1;
                    Linear_average_sample = sqrt(Linear_Sample);
                    error_L += pow(Linear_average_sample - Linear_average, 2);
                } else { 
                    continue; 
                }

            } else {
                cout << "0"; 
                continue;
            }
        }
        if(Counter!=0) {
            Linear_Error = sqrt(error_L / (Counter * Counter) );
            hCLinear->SetBinContent(bin, Linear_average); 
            hCLinear->SetBinError(bin, Linear_Error); 
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
            continue;
        }
    }
    //..Plot:
    //hC25->Draw();
    hCLinear->Draw();
    //c->SaveAs("/Users/Helena/Desktop/pic/Katka_plots/Debug2_V4_Linear_gap00.png");
    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/V4_V5_Linear_Debug/4particle_newDebug_V4_V5_Linear.root","UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hCLinear->Write("V5_Linear_Gap00_A+B");
} 