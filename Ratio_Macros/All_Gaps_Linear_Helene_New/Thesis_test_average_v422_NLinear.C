
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

void Thesis_test_average_v422_NLinear() {
    double BinValue34A = 0.0;
    double BinValue34B = 0.0;
    double BinValue42 = 0.0;
    double BinValue24 = 0.0;
    double BinValue34A_Sample = 0.0;
    double BinValue34B_Sample = 0.0;
    double BinValue42_Sample = 0.0;
    double BinValue24_Sample = 0.0;
    double BinValue34A_Entries = 0.0;
    double BinValue34B_Entries = 0.0;
    double BinValue42_Entries = 0.0;
    double BinValue24_Entries = 0.0;
    double BinValue42_Sample = 0.0;
    double BinValue24_Sample = 0.0;
    double BinValue34A_Entries_Sample = 0.0;
    double BinValue42_Entries_Sample = 0.0;
    double BinValue24_Entries_Sample = 0.0;
    double BinValue42_Sqrt = 0.0;
    double BinValue24_Sqrt = 0.0;
    double BinValue42_Sample_Sqrt = 0.0;
    double BinValue24_Sample_Sqrt = 0.0;
    double Linear = 0.0;
    double Linear_Sample = 0.0;
    double Linear_value = 0.0; 
    double Linear_value_sample = 0.0;
    double Linear_Error = 0.0; 
    double NonLinear_Error = 0.0;
    double final_error_4part = 0.0;
    double Sample_Linear = 0.0; 
    double v422_average = 0.0;
    double v422_average_sample = 0.0;
    double V422_A = 0.0; 
    double V422_B = 0.0;
    double V422_A_Sample = 0.0;
    double V422_B_Sample = 0.0;
    double BinValuev422A = 0.0;
    double BinValuev422B = 0.0;
    double BinValuev422A_Entries = 0.0;
    double BinValuev422B_Entries = 0.0;
    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    TH1D *hv422_average = new TH1D("hv422_average", "The Non-Linear Response, v_{4,22} (A+B) ", 200, 0, 200); //this is just define a histogram which will fill the data of V422.
    hv422_average->Sumw2();
    //Open root.file:
    TFile *file = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_New_Checked.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");

    // TFile *file2 = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Debug_Average_V422_NUA+NUE.root", "READ");
    
    // TH1D *v422A = (TH1D*)file2->Get("v422_Gap08A");
    // TH1D *v422B = (TH1D*)file2->Get("v422_Gap07B");
    //v422A->Draw();
    //v422B->Draw();
    //**************************************************************************
    //..Gap= 0.8
    //TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap06Ntrks1bin");
    TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap08Ntrks1bin"); 
    TProfile *Cn34A = (TProfile*)list->FindObject("fTprofC34Gap08ANtrks1bin");  
    TProfile *Cn34B = (TProfile*)list->FindObject("fTprofC34Gap08BNtrks1bin");  
    //**************************************************************************
    //************************************************************************
    // Average v422 from GapA + GapB 
    //************************************************************************
    for(int bin=1; bin<201; bin++) {        
        double Counter = 0.0;
        double error_NL = 0.0;
        BinValue34A = Cn34A->GetBinContent(bin);
        BinValue34B = Cn34B->GetBinContent(bin); 
        BinValue42 = Cn42->GetBinContent(bin);
        BinValue34A_Entries = Cn34A->GetBinEffectiveEntries(bin);
        BinValue34B_Entries = Cn34B->GetBinEffectiveEntries(bin);
        BinValue42_Entries = Cn42->GetBinEffectiveEntries(bin);
        if( BinValue34A_Entries > 1000 && BinValue34B_Entries > 1000 && BinValue42_Entries > 1000 && BinValue42 > 0 ) {
            BinValue42_Sqrt = sqrt(BinValue42);
            V422_A = ((BinValue34A) / (BinValue42_Sqrt));
            V422_B = ((BinValue34B) / (BinValue42_Sqrt)); 
            v422_average = ((V422_A + V422_B) / (2)); 
        } else {
            cout << "0"; 
            continue;
        }
        for (int sample=1; sample<11; sample++) {
            TString foo_34B(TString::Format("fTprof34_number%dGap08BNtrks1bin", sample));	
            TProfile *prof34B = (TProfile*)list->FindObject(foo_34B);
            TString foo_34A(TString::Format("fTprof34_number%dGap08ANtrks1bin", sample));	
            TProfile *prof34A = (TProfile*)list->FindObject(foo_34A);
            TString foo_42(TString::Format("fTprof42_number%dGap08Ntrks1bin", sample));	
            TProfile *prof42 = (TProfile*)list->FindObject(foo_42);
            BinValue34A_Sample = prof34A->GetBinContent(bin);
            BinValue34B_Sample = prof34B->GetBinContent(bin);
            BinValue42_Sample = prof42->GetBinContent(bin);
            BinValue34A_Entries_Sample = prof34A->GetBinEffectiveEntries(bin);
            BinValue34B_Entries_Sample = prof34B->GetBinEffectiveEntries(bin);
            BinValue42_Entries_Sample = prof42->GetBinEffectiveEntries(bin);    
            if( BinValue34A_Entries_Sample > 100 && BinValue34B_Entries_Sample > 100 && BinValue42_Entries_Sample > 100 && BinValue42_Sample > 0) {
                Counter += 1;
                cout << "1";
                BinValue42_Sample_Sqrt = sqrt(BinValue42_Sample);
                V422_A_Sample = BinValue34A_Sample / (BinValue42_Sample_Sqrt);
                V422_B_Sample = BinValue34B_Sample / (BinValue42_Sample_Sqrt);
                v422_average_sample = ((V422_A_Sample + V422_B_Sample) / (2));   
                error_NL += pow(v422_average_sample - v422_average, 2);                  
            } else {
                cout << "0"; 
                continue;
            }
        }
        if(Counter!=0) {
            NonLinear_Error = sqrt((error_NL) / (Counter * Counter) );
            hv422_average->SetBinContent(bin, v422_average); 
            hv422_average->SetBinError(bin, NonLinear_Error); 
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
            continue;
        }
    }
    //..Plot:
    hv422_average->Draw();
    //c->SaveAs("/Users/Helena/Desktop/pic/Katka_plots/Debug2_V4_Linear_gap08.png");
    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Average_V422_NUA+NUE/4particle_Debug_Average_V422_V532_A+B.root","UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hv422_average->Write("v422_Gap08_A+B");
}