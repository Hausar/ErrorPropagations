
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

void Test_Average_Cn422() {
    double BinValue34A = 0.0;
    double BinValue34B = 0.0;
    double BinValue34A_Sample = 0.0;
    double BinValue34B_Sample = 0.0;
    double BinValue34A_Entries = 0.0;
    double BinValue34B_Entries = 0.0;
    double BinValue34A_Entries_Sample = 0.0; 
    double BinValue34B_Entries_Sample = 0.0; 
    double NonLinear_Error = 0.0;
    double Cn422_average = 0.0;
    double Cn422_average_sample = 0.0;
    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    TH1D *hV422_average = new TH1D("hV422_average", "3-particle correlations, C_{4,22} (A+B) ", 200, 0, 200); //this is just define a histogram which will fill the data of V422.
    hV422_average->Sumw2();
    //Open root.file:
    TFile *file = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_New_Checked.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");
    //**************************************************************************
    TProfile *Cn34A = (TProfile*)list->FindObject("fTprofC34Gap08ANtrks1bin");  
    TProfile *Cn34B = (TProfile*)list->FindObject("fTprofC34Gap08BNtrks1bin");  
    //**************************************************************************
    //************************************************************************
    // Average Cn422 from GapA + GapB 
    //************************************************************************
    for(int bin=1; bin<201; bin++) {        
        double Counter = 0.0;
        double error_NL = 0.0;
        BinValue34A = Cn34A->GetBinContent(bin);
        BinValue34B = Cn34B->GetBinContent(bin); 
        BinValue34A_Entries = Cn34A->GetBinEffectiveEntries(bin);
        BinValue34B_Entries = Cn34B->GetBinEffectiveEntries(bin);
        if( BinValue34A_Entries > 1000 && BinValue34B_Entries > 1000 ) {
            Cn422_average = (BinValue34A + BinValue34B) / (2) ; 
        } else {
            cout << "0"; 
            continue;
        }
        for (int sample=1; sample<11; sample++) {
            TString foo_34B(TString::Format("fTprof34_number%dGap08BNtrks1bin", sample));	
            TProfile *prof34B = (TProfile*)list->FindObject(foo_34B);
            TString foo_34A(TString::Format("fTprof34_number%dGap08ANtrks1bin", sample));	
            TProfile *prof34A = (TProfile*)list->FindObject(foo_34A);
            BinValue34A_Sample = prof34A->GetBinContent(bin);
            BinValue34B_Sample = prof34B->GetBinContent(bin);
            BinValue34A_Entries_Sample = prof34A->GetBinEffectiveEntries(bin);
            BinValue34B_Entries_Sample = prof34B->GetBinEffectiveEntries(bin);   
            if( BinValue34A_Entries_Sample > 100 && BinValue34B_Entries_Sample > 100 ) {
                Counter += 1;
                cout << "1";
                Cn422_average_sample = (BinValue34A_Sample + BinValue34B_Sample) / (2);    
                error_NL += pow(Cn422_average_sample - Cn422_average, 2);                  
            } else {
                cout << "0"; 
                continue;
            }
        }
        if(Counter!=0) {
            NonLinear_Error = sqrt(error_NL / (Counter * Counter) );
            hV422_average->SetBinContent(bin, Cn422_average); 
            hV422_average->SetBinError(bin, NonLinear_Error); 
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
            continue;
        }
    }
    //..Plot:
    hV422_average->Draw();
    //v422A->Draw("same");
    //c->SaveAs("/Users/Helena/Desktop/pic/Katka_plots/Debug2_V4_Linear_gap08.png");
    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Debug_Average_Cn422_A+B_NUA+NUE.root","UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hV422_average->Write("Cn422_Gap08_A+B");
}