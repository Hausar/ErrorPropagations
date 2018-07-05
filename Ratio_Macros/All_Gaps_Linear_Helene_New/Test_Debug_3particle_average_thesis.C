
//Macro To Calculate the v532, Linear for all gaps to compare with You's results:
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

void Test_Debug_3particle_average_thesis() {
    double BinValue35A = 0.0;
    double BinValue35B = 0.0;
    double BinValue35A_Sample = 0.0;
    double BinValue35B_Sample = 0.0;
    double BinValue35A_Entries = 0.0;
    double BinValue35B_Entries = 0.0;
    double Final_Error = 0.0;
    double C35_A_B = 0.0;
    double BinValue35A_Entries_Sample = 0.0;
    double BinValue35B_Entries_Sample = 0.0;
    double C35_A_B_Sample = 0.0;
    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    TH1D *C35_average = new TH1D("C35_average", "The 3-particle, <<3>>_{5,32} (A+B) ", 200, 0, 200); //this is just define a histogram which will fill the data of V532.
    C35_average->Sumw2();
    //Open root.file:
    TFile *file = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_Corrected_4particle.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");

    //**************************************************************************
    //..Gap= 0.8 
    TProfile *Cn35A = (TProfile*)list->FindObject("fTprofC35Gap00ANtrks1bin");  
    TProfile *Cn35B = (TProfile*)list->FindObject("fTprofC35Gap00BNtrks1bin");  
    //**************************************************************************
    //************************************************************************
    // Average Cn35 from GapA + GapB 
    //************************************************************************
    for(int bin=1; bin<201; bin++) {        
        double Counter = 0.0;
        double error_NL = 0.0;
        BinValue35A = Cn35A->GetBinContent(bin);
        BinValue35B = Cn35B->GetBinContent(bin); 
        BinValue35A_Entries = Cn35A->GetBinEffectiveEntries(bin);
        BinValue35B_Entries = Cn35B->GetBinEffectiveEntries(bin);
        if( BinValue35A_Entries > 1000 && BinValue35B_Entries > 1000 ) {
            C35_A_B = (BinValue35A + BinValue35B) / 2;
        } else {
            cout << "0"; 
            continue;
        }
        for (int sample=1; sample<11; sample++) {
            TString foo_35A(TString::Format("fTprof35_number%dGap00ANtrks1bin", sample));
            TProfile *prof35A = (TProfile*)list->FindObject(foo_35A);
            TString foo_35B(TString::Format("fTprof35_number%dGap00BNtrks1bin", sample));
            TProfile *prof35B = (TProfile*)list->FindObject(foo_35B);

            BinValue35A_Sample = prof35A->GetBinContent(bin);
            BinValue35B_Sample = prof35B->GetBinContent(bin);
            BinValue35A_Entries_Sample = prof35A->GetBinEffectiveEntries(bin);
            BinValue35B_Entries_Sample = prof35B->GetBinEffectiveEntries(bin);

            if( BinValue35A_Entries_Sample > 100 && BinValue35B_Entries_Sample > 100 ) {
                Counter += 1;
                cout << "1";
                C35_A_B_Sample = (BinValue35A_Sample + BinValue35B_Sample) / 2;     
                error_NL += pow(C35_A_B_Sample - C35_A_B, 2);                  
            } else {
                cout << "0"; 
                continue;
            }
        }
        if(Counter!=0) {
            Final_Error = sqrt(error_NL / (Counter * Counter) );
            C35_average->SetBinContent(bin, C35_A_B); 
            C35_average->SetBinError(bin, Final_Error); 
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
            continue;
        }
    }
    //..Plot:
    C35_average->Draw();
    //c->SaveAs("/Users/Helena/Desktop/pic/Katka_plots/Debug2_V4_Linear_gap00.png");
    TFile* fileOutput = new TFile ("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Cn34_Cn35_{3}_average_A+B/Debug_Cn35_average_A+B.root", "UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    C35_average->Write("Cn35_Gap00_A+B");
}