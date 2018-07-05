
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

void Thesis_test_average_v532_NLinear() {
    double BinValue35A = 0.0;
    double BinValue35B = 0.0;
    double BinValue43 = 0.0;
    double BinValue35A_Sample = 0.0;
    double BinValue35B_Sample = 0.0;
    double BinValue43_Sample = 0.0;
    double BinValue35A_Entries = 0.0;
    double BinValue35B_Entries = 0.0;
    double BinValue43_Entries = 0.0;
    double BinValue35A_Entries_Sample = 0.0;
    double BinValue35B_Entries_Sample = 0.0;
    double BinValue43_Entries_Sample = 0.0;
    double BinValue43_Sqrt = 0.0;
    double BinValue43_Sample_Sqrt = 0.0;
    double NonLinear_Error = 0.0;
    double v532_average = 0.0;
    double v532_average_sample = 0.0;
    double V532_A = 0.0; 
    double V532_B = 0.0;
    double V532_A_Sample = 0.0;
    double V532_B_Sample = 0.0;
    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    TH1D *hV532_average = new TH1D("hV532_average", "The Non-Linear Response, v_{5,32} (A+B) ", 200, 0, 200);
    hV532_average->Sumw2();
    //Open root.file:
    TFile *file = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_New_Checked.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");

    // TFile *file2 = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V532_NL_Linear_NUA+NUE/Debug_Average_V532_NUA+NUE.root", "READ");
    
    // TH1D *v532A = (TH1D*)file2->Get("v532_Gap08A");
    // TH1D *v532B = (TH1D*)file2->Get("v532_Gap07B");
    //v532A->Draw();
    //v532B->Draw();
    //**************************************************************************
    TProfile *Cn43 = (TProfile*)list->FindObject("fTprofC43Gap08Ntrks1bin"); 
    TProfile *Cn35A = (TProfile*)list->FindObject("fTprofC35Gap08ANtrks1bin");  
    TProfile *Cn35B = (TProfile*)list->FindObject("fTprofC35Gap08BNtrks1bin");  
    //**************************************************************************
    //************************************************************************
    // Average v532 from GapA + GapB 
    //************************************************************************
    for(int bin=1; bin<201; bin++) {        
        double Counter = 0.0;
        double error_NL = 0.0;
        BinValue35A = Cn35A->GetBinContent(bin);
        BinValue35B = Cn35B->GetBinContent(bin); 
        BinValue43 = Cn43->GetBinContent(bin);
        BinValue35A_Entries = Cn35A->GetBinEffectiveEntries(bin);
        BinValue35B_Entries = Cn35B->GetBinEffectiveEntries(bin);
        BinValue43_Entries = Cn43->GetBinEffectiveEntries(bin);
        //cout << "bin " << bin << endl; 
        if( BinValue35A_Entries > 1000 && BinValue35B_Entries > 1000 && BinValue43_Entries > 1000 && BinValue43 > 0 ) {
            BinValue43_Sqrt = sqrt(BinValue43);
            V532_A = ((BinValue35A) / (BinValue43_Sqrt));
            V532_B = ((BinValue35B) / (BinValue43_Sqrt));
            v532_average = ((V532_A + V532_B) / (2));
        } else {
            cout << "0"; 
            continue;
        }
        for (int sample=1; sample<11; sample++) {
            TString foo_35A(TString::Format("fTprof35_number%dGap08ANtrks1bin", sample));
            TProfile *prof35A = (TProfile*)list->FindObject(foo_35A);
            TString foo_35B(TString::Format("fTprof35_number%dGap08BNtrks1bin", sample));
            TProfile *prof35B = (TProfile*)list->FindObject(foo_35B);            
            TString foo_43(TString::Format("fTprof43_number%dGap08Ntrks1bin", sample));	
            TProfile *prof43 = (TProfile*)list->FindObject(foo_43);
            BinValue35A_Sample = prof35A->GetBinContent(bin);
            BinValue35B_Sample = prof35B->GetBinContent(bin);
            BinValue43_Sample = prof43->GetBinContent(bin);
            BinValue35A_Entries_Sample = prof35A->GetBinEffectiveEntries(bin);
            BinValue35B_Entries_Sample = prof35B->GetBinEffectiveEntries(bin);
            BinValue43_Entries_Sample = prof43->GetBinEffectiveEntries(bin);
            if( BinValue35A_Entries_Sample > 100 && BinValue35B_Entries_Sample > 100 && BinValue43_Entries_Sample > 100 && BinValue43_Sample > 0 ) {
                Counter += 1;
                //cout << "sample " << Counter << endl;
                BinValue43_Sample_Sqrt = sqrt(BinValue43_Sample);
                V532_A_Sample = ((BinValue35A_Sample) / (BinValue43_Sample_Sqrt));
                V532_B_Sample = ((BinValue35B_Sample) / (BinValue43_Sample_Sqrt));
                v532_average_sample = ((V532_A_Sample + V532_B_Sample) / (2));    
                error_NL += pow(v532_average_sample - v532_average, 2);                  
            } else {
                cout << "0"; 
                continue;
            }
        }
        if(Counter!=0) {
            NonLinear_Error = sqrt(error_NL / (Counter * Counter) );
            //cout << "Counter: " << Counter << endl; 
            hV532_average->SetBinContent(bin, v532_average); 
            hV532_average->SetBinError(bin, NonLinear_Error); 
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
            continue;
        }
    }
    //..Plot:
    hV532_average->Draw();
    //v532A->Draw("same");
    //c->SaveAs("/Users/Helena/Desktop/pic/Katka_plots/Debug2_V4_Linear_gap08.png");
    TFile* fileOutput = new TFile ("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Average_V422_NUA+NUE/4particle_Debug_Average_V422_V532_A+B.root", "UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hV532_average->Write("v532_Gap08_A+B");
}