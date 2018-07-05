
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

void Thesis_test_average_v4Linear() {
    double BinValue34A = 0.0; 
    double BinValue34B = 0.0;
    double BinValue24 = 0.0;
    double BinValue42 = 0.0;
    double BinValue34A_Sample = 0.0;
    double BinValue34B_Sample  = 0.0;
    double BinValue24_Sample = 0.0;
    double BinValue42_Sample = 0.0;
    double BinValue34A_Entries = 0.0;
    double BinValue34B_Entries = 0.0;
    double BinValue24_Entries = 0.0;
    double BinValue42_Entries = 0.0;
    double BinValue24_Sample = 0.0;
    double BinValue42_Sample = 0.0;
    double BinValue34A_Entries_Sample = 0.0;
    double BinValue34B_Entries_Sample = 0.0;
    double BinValue24_Entries_Sample = 0.0;
    double BinValue42_Entries_Sample = 0.0;
    double BinValue24_Sqrt = 0.0;
    double BinValue42_Sqrt = 0.0;
    double BinValue24_Sample_Sqrt = 0.0;
    double BinValue42_Sample_Sqrt = 0.0;
    double Linear = 0.0;
    double Linear_Error = 0.0;
    double Linear_Sample = 0.0;
    double v422_average = 0.0;
    double v422_average_sample = 0.0;
    double Linear_average = 0.0; 
    double Linear_average_sample = 0.0;
    double V422_A = 0.0;
    double V422_B = 0.0;
    double V422_A_Sample = 0.0;
    double V422_B_Sample = 0.0;

    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd(); 
    TH1D *hCLinear = new TH1D("hCLinear", " The Linear Response V4^{L} ", 200, 0, 200); 
    hCLinear->Sumw2();
    //Open the latest root.file:
    TFile *file = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_New_Checked.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");
    
    //**************************************************************************
    //..open the TProfiles:
    //..Gaps
    TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap08Ntrks1bin");
    TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap08Ntrks1bin");  
    TProfile *Cn34A = (TProfile*)list->FindObject("fTprofC34Gap08ANtrks1bin");
    TProfile *Cn34B = (TProfile*)list->FindObject("fTprofC34Gap08BNtrks1bin");
    //**************************************************************************
    //..V4_Linear:
    for(int bin=1; bin<201; bin++) {        
        double Counter = 0.0;
        double error_L = 0.0;
        BinValue24 = Cn24->GetBinContent(bin);
        BinValue42 = Cn42->GetBinContent(bin);
        BinValue34A = Cn34A->GetBinContent(bin);
        BinValue34B = Cn34B->GetBinContent(bin);
        BinValue24_Entries = Cn24->GetBinEffectiveEntries(bin);
        BinValue34A_Entries = Cn34A->GetBinEffectiveEntries(bin);
        BinValue34B_Entries = Cn34B->GetBinEffectiveEntries(bin);
        BinValue42_Entries = Cn42->GetBinEffectiveEntries(bin);
        if( BinValue24_Entries > 1000 && BinValue34A_Entries > 1000 && BinValue34B_Entries > 1000 && BinValue42_Entries > 1000 && BinValue24 > 0 && BinValue42 > 0) {
            BinValue42_Sqrt = sqrt(BinValue42);
            BinValue24_Sqrt = sqrt(BinValue24);
            V422_A = ((BinValue34A) / (BinValue42_Sqrt));
            V422_B = ((BinValue34B) / (BinValue42_Sqrt));
            v422_average = ((V422_A + V422_B) / (2));
            Linear = pow(BinValue24_Sqrt, 2) - pow(v422_average, 2);
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
            TString foo_34A(TString::Format("fTprof34_number%dGap08ANtrks1bin", sample));
            TProfile *prof34A = (TProfile*)list->FindObject(foo_34A);
            TString foo_34B(TString::Format("fTprof34_number%dGap08BNtrks1bin", sample));
            TProfile *prof34B = (TProfile*)list->FindObject(foo_34B);
            TString foo_24(TString::Format("fTprof24_number%dGap08Ntrks1bin", sample));
            TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            TString foo_42(TString::Format("fTprof42_number%dGap08Ntrks1bin", sample));	
            TProfile *prof42 = (TProfile*)list->FindObject(foo_42);
            BinValue34A_Sample = prof34A->GetBinContent(bin);
            BinValue34B_Sample = prof34B->GetBinContent(bin);
            BinValue24_Sample = prof24->GetBinContent(bin);
            BinValue42_Sample = prof42->GetBinContent(bin);
            BinValue34A_Entries_Sample = prof34A->GetBinEffectiveEntries(bin);
            BinValue34B_Entries_Sample = prof34B->GetBinEffectiveEntries(bin);
            BinValue24_Entries_Sample = prof24->GetBinEffectiveEntries(bin);
            BinValue42_Entries_Sample = prof42->GetBinEffectiveEntries(bin);
            if( BinValue24_Entries_Sample > 100 && BinValue34A_Entries_Sample > 100 && BinValue34B_Entries_Sample > 100 && BinValue42_Entries_Sample > 100 && BinValue24_Sample > 0 && BinValue42_Sample > 0 ) {
                cout << "1";
                BinValue24_Sample_Sqrt = sqrt(BinValue24_Sample);
                BinValue42_Sample_Sqrt = sqrt(BinValue42_Sample);
                V422_A_Sample = ((BinValue34A_Sample) / (BinValue42_Sample_Sqrt));
                V422_B_Sample = ((BinValue34B_Sample) / (BinValue42_Sample_Sqrt));
                v422_average_sample = ((V422_A_Sample + V422_B_Sample) / (2));
                Linear_Sample = pow(BinValue24_Sample_Sqrt, 2) - pow(v422_average_sample, 2); 
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
    //c->SaveAs("/Users/Helena/Desktop/pic/Katka_plots/Debug2_V4_Linear_gap08.png");
    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/V4_V5_Linear_Debug/4particle_newDebug_V4_V5_Linear.root","UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hCLinear->Write("V4_Linear_Gap08_A+B");
} 