
//Macro To Calculate the v422, Linear for all gaps to compare with You's results:
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

void V5_2particle_Debug() {
    double BinValuev532 = 0.0; 
    double BinErrorv532 = 0.0;
    double BinValue24 = 0.0;
    double BinValue22 = 0.0;
    double BinValue23 = 0.0;
    double BinValue35A_Sample = 0.0;
    double BinValue35B_Sample  = 0.0;
    double BinValue24_Sample = 0.0;
    double BinValue22_Sample = 0.0;
    double BinValue23_Sample = 0.0;
    double BinValue35A_Entries = 0.0;
    double BinValue35B_Entries = 0.0;
    double BinValue24_Entries = 0.0;
    double BinValue22_Entries = 0.0;
    double BinValue23_Entries = 0.0;
    double BinValue24_Sample = 0.0;
    double BinValue22_Sample = 0.0;
    double BinValue23_Sample = 0.0;
    double BinValue35A_Entries_Sample = 0.0;
    double BinValue35B_Entries_Sample = 0.0;
    double BinValue24_Entries_Sample = 0.0;
    double BinValue22_Entries_Sample = 0.0;
    double BinValue23_Entries_Sample = 0.0;
    double BinValue24_Sqrt = 0.0;
    double BinValue22_Sqrt = 0.0;
    double BinValue23_Sqrt = 0.0;
    double BinValue24_Sample_Sqrt = 0.0;
    double BinValue22_Sample_Sqrt = 0.0;
    double BinValue23_Sample_Sqrt = 0.0;
    double Linear = 0.0;
    double Linear_Sample = 0.0;
    double Linear_value_A = 0.0;
    double Linear_value_B = 0.0;
    double Linear_average = 0.0; 
    double Linear_average_sample = 0.0;
    double Linear_value_sample_A = 0.0;
    double Linear_value_sample_B = 0.0;
    double Final_Error = 0.0; 
    double final_error_2part = 0.0;
    double Sample_Linear = 0.0; 
    double V532_A = 0.0;
    double V532_B = 0.0;
    double V532_A_Sample = 0.0;
    double V532_B_Sample = 0.0;

    // |#Delta#eta| > 0.0
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd(); 
    TH1D *hCV52 = new TH1D("hCV52", " V4{2} = #sqrt{<<2>>_{4|-4}}", 200, 0, 200); //this is just define a histogram which will fill the data.
    hCV52->Sumw2();
    //Open the latest root.file:
    TFile *file = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_Corrected_4particle.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");
    
    //**************************************************************************
    //..open the TProfiles:
    //TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC25Ntrks1bin");   //..V5{2}-wo-gap
    TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap00Ntrks1bin");   //..V5{2}
    //*************************************************************************
    //                          V5{2} = (<<2>>_{5,-5})^1/2
    //**************************************************************************
    for(int bin=1; bin<201; bin++) {        
        double Counter = 0.0;
        double error_L = 0.0;
        BinValue24 = Cn24->GetBinContent(bin);
        BinValue24_Entries = Cn24->GetBinEffectiveEntries(bin);
        if( BinValue24_Entries > 1000 && BinValue24 > 0 ) {
            BinValue24_Sqrt = sqrt(BinValue24);  
        } else {
            cout << "0" << endl; 
            continue;
        }
        for (int sample=1; sample<11; sample++) {
            TString foo_24(TString::Format("fTprof24_number%dGap00Ntrks1bin", sample));
            TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            BinValue24_Sample = prof24->GetBinContent(bin);
            BinValue24_Entries_Sample = prof24->GetBinEffectiveEntries(bin);
            if( BinValue24_Entries_Sample > 100 && BinValue24_Sample > 0) {
                cout << "1";
                Counter += 1;
                BinValue24_Sample_Sqrt = sqrt(BinValue24_Sample); 
                error_L += pow(BinValue24_Sample_Sqrt - BinValue24_Sqrt, 2);
            } else {
                cout << "0"; 
                continue;
            }
        }
        if(Counter!=0) {
            Final_Error = sqrt(error_L / (Counter * Counter) );
            hCV52->SetBinContent(bin, BinValue24_Sqrt); 
            hCV52->SetBinError(bin, Final_Error); 
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
            continue;
        }
    }
    //..Plot:
    hCV52->Draw();
    //c->SaveAs("/Users/Helena/Desktop/pic/Katka_plots/Debug2_V4_Linear_gap00.png");
    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/V5_V4_{2}/V5_V4_2particle_NUA+NUE.root","UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hCV52->Write("V4_2particle_Gap00_A+B");
} 