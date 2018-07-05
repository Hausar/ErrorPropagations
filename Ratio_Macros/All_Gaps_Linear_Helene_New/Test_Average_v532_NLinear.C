
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

void Test_Average_v532_NLinear() {
    double BinValue35A = 0.0;
    double BinValue35B = 0.0;
    double BinValue22 = 0.0;
    double BinValue23 = 0.0;
    double BinValue25 = 0.0;
    double BinValue35A_Sample = 0.0;
    double BinValue35B_Sample = 0.0;
    double BinValue22_Sample = 0.0;
    double BinValue23_Sample = 0.0;
    double BinValue25_Sample = 0.0;
    double BinValue35A_Entries = 0.0;
    double BinValue35B_Entries = 0.0;
    double BinValue22_Entries = 0.0;
    double BinValue23_Entries = 0.0;
    double BinValue25_Entries = 0.0;
    double BinValue35A_Entries_Sample = 0.0;
    double BinValue35B_Entries_Sample = 0.0;
    double BinValue22_Entries_Sample = 0.0;
    double BinValue23_Entries_Sample = 0.0;
    double BinValue25_Entries_Sample = 0.0;
    double BinValue22_Sqrt = 0.0;
    double BinValue23_Sqrt = 0.0;
    double BinValue25_Sqrt = 0.0;
    double BinValue22_Sample_Sqrt = 0.0;
    double BinValue23_Sample_Sqrt = 0.0;
    double BinValue25_Sample_Sqrt = 0.0;
    double Linear = 0.0;
    double Linear_Sample = 0.0;
    double Linear_value = 0.0; 
    double Linear_value_sample = 0.0;
    double Linear_Error = 0.0; 
    double NonLinear_Error = 0.0;
    double final_error_4part = 0.0;
    double Sample_Linear = 0.0; 
    double v532_average = 0.0;
    double v532_average_sample = 0.0;
    double V532_A = 0.0; 
    double V532_B = 0.0;
    double V532_A_Sample = 0.0;
    double V532_B_Sample = 0.0;
    double BinValuev532A = 0.0;
    double BinValuev532B = 0.0;
    double BinValuev532A_Entries = 0.0;
    double BinValuev532B_Entries = 0.0;
    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    TH1D *hV532_average = new TH1D("hV532_average", "The Non-Linear Response, v_{5,32} (A+B) ", 200, 0, 200); //this is just define a histogram which will fill the data of V532.
    hV532_average->Sumw2();
    //Open root.file:
    TFile *file = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_New_Checked.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");

    // TFile *file2 = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V532_NL_Linear_NUA+NUE/Debug_Average_V532_NUA+NUE.root", "READ");
    
    // TH1D *v532A = (TH1D*)file2->Get("v532_Gap08A");
    // TH1D *v532B = (TH1D*)file2->Get("v532_Gap08B");
    //v532A->Draw();
    //v532B->Draw();
    //**************************************************************************
    //..Gap= 0.8
    //TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap06Ntrks1bin");
    TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap08Ntrks1bin");
    TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap08Ntrks1bin"); 
    TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap08Ntrks1bin");  
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
        BinValue22 = Cn22->GetBinContent(bin);
        BinValue23 = Cn23->GetBinContent(bin);
        BinValue25 = Cn25->GetBinContent(bin);
        BinValue35A_Entries = Cn35A->GetBinEffectiveEntries(bin);
        BinValue35B_Entries = Cn35B->GetBinEffectiveEntries(bin);
        BinValue22_Entries = Cn22->GetBinEffectiveEntries(bin);
        BinValue23_Entries = Cn23->GetBinEffectiveEntries(bin);
        BinValue25_Entries = Cn25->GetBinEffectiveEntries(bin);
        if( BinValue35A_Entries > 1000 && BinValue35B_Entries > 1000 && BinValue23_Entries > 1000 && BinValue22_Entries > 1000 && BinValue25_Entries > 1000 && BinValue23 > 0 && BinValue22 > 0 && BinValue25 > 0 ) {
            BinValue22_Sqrt = sqrt(BinValue22);
            BinValue23_Sqrt = sqrt(BinValue23);
            BinValue25_Sqrt = sqrt(BinValue25);
            V532_A = BinValue35A / (BinValue22_Sqrt * BinValue23_Sqrt);
            V532_B = BinValue35B / (BinValue22_Sqrt * BinValue23_Sqrt);
            // V532_A = Bin2alue35A / (BinValue42_Sqrt);
            // V532_B = Bin2alue35B / (BinValue42_Sqrt); 
            v532_average = ( (V532_A + V532_B) / (2) ); 
        } else {
            cout << "0"; 
            continue;
        }
        for (int sample=1; sample<11; sample++) {
            TString foo_35A(TString::Format("fTprof35_number%dGap08ANtrks1bin", sample));
            TProfile *prof35A = (TProfile*)list->FindObject(foo_35A);
            TString foo_35B(TString::Format("fTprof35_number%dGap08BNtrks1bin", sample));
            TProfile *prof35B = (TProfile*)list->FindObject(foo_35B);
            TString foo_22(TString::Format("fTprof22_number%dGap08Ntrks1bin", sample));	
            TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            TString foo_23(TString::Format("fTprof23_number%dGap08Ntrks1bin", sample));	
            TProfile *prof23 = (TProfile*)list->FindObject(foo_23);
            TString foo_25(TString::Format("fTprof25_number%dGap08Ntrks1bin", sample));
            TProfile *prof25 = (TProfile*)list->FindObject(foo_25);
            
            BinValue35A_Sample = prof35A->GetBinContent(bin);
            BinValue35B_Sample = prof35B->GetBinContent(bin);
            BinValue25_Sample = prof25->GetBinContent(bin);
            BinValue22_Sample = prof22->GetBinContent(bin);
            BinValue23_Sample = prof23->GetBinContent(bin);
            BinValue35A_Entries_Sample = prof35A->GetBinEffectiveEntries(bin);
            BinValue35B_Entries_Sample = prof35B->GetBinEffectiveEntries(bin);
            BinValue25_Entries_Sample = prof25->GetBinEffectiveEntries(bin);
            BinValue22_Entries_Sample = prof22->GetBinEffectiveEntries(bin);
            BinValue23_Entries_Sample = prof23->GetBinEffectiveEntries(bin);

            if( BinValue35A_Entries_Sample > 100 && BinValue35B_Entries_Sample > 100 && BinValue25_Entries_Sample > 100 && BinValue22_Entries_Sample > 100 && BinValue23_Entries_Sample > 100 && BinValue22_Sample > 0 && BinValue23_Sample > 0 && BinValue25_Sample > 0 ) {
                Counter += 1;
                cout << "1";
                BinValue22_Sample_Sqrt = sqrt(BinValue22_Sample);
                BinValue23_Sample_Sqrt = sqrt(BinValue23_Sample);
                BinValue25_Sample_Sqrt = sqrt(BinValue25_Sample);
                V532_A_Sample = BinValue35A_Sample / (BinValue22_Sample_Sqrt * BinValue23_Sample_Sqrt);
                V532_B_Sample = BinValue35B_Sample / (BinValue22_Sample_Sqrt * BinValue23_Sample_Sqrt);
                v532_average_sample = (V532_A_Sample + V532_B_Sample) / (2);
                //error_NL += pow(V532_Sample - V532, 2);     
                error_NL += pow(v532_average_sample - v532_average, 2);                  
            } else {
                cout << "0"; 
                continue;
            }
        }
        if(Counter!=0) {
            NonLinear_Error = sqrt(error_NL / (Counter * Counter) );
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
    TFile* fileOutput = new TFile ("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Average_V422_NUA+NUE/Thesis_Debug_Average_V532_A+B_NUA+NUE.root", "UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    //hC42->Write("hC42_Sqrt_Gap00");
    //hCLinear->Write("V4Linear_Gap00");
    hV532_average->Write("v532_Gap08_A+B");
}