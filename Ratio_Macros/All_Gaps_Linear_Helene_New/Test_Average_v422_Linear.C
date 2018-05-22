
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

void Test_Average_v422_Linear() {
    double BinValue34 = 0.0;
    double BinValue42 = 0.0;
    double BinValue24 = 0.0;
    double BinValue34_Sample = 0.0;
    double BinValue42_Sample = 0.0;
    double BinValue24_Sample = 0.0;
    double BinValue34_Entries = 0.0;
    double BinValue42_Entries = 0.0;
    double BinValue24_Entries = 0.0;
    double BinValue34_Sample = 0.0;
    double BinValue42_Sample = 0.0;
    double BinValue24_Sample = 0.0;
    double BinValue34_Entries_Sample = 0.0;
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
    double V422 = 0.0;
    double V422_Sample = 0.0;
    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    
    // TH1D *hC22 = new TH1D("hC22", " V4{2},  #sqrt{< v_{4}^{2} >}, 2-Particle correlation", 200, 0, 200); //this is just define a histogram which will fill the data.
    // hC22->Sumw2();
    
    // TH1D *hC42 = new TH1D("hC42", " #sqrt{< v_{2}^{4} >} 4-Particle correlation", 200, 0, 200); //this is just define a histogram 
	// hC42->Sumw2();

    TH1D *hV422 = new TH1D("hV422", "The Non-Linear Response, v_{4,22} = {<<3>>} {#sqrt{< v_{2}^{4} >}}", 200, 0, 200); //this is just define a histogram which will fill the data of V422.
    hV422->Sumw2();
 
    // TH1D *hCLinear = new TH1D("hCLinear", " The Linear Response V4^{L} ", 200, 0, 200); //this is just define a histogram which will fill the data.
    // hCLinear->Sumw2();

    //Open the latest root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_Corrected_4particle.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");
    
    //**************************************************************************
    //..Gap= 0.8
    //TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap04Ntrks1bin");
    TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap08Ntrks1bin");  
    TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap08BNtrks1bin");  
    //**************************************************************************
    //************************************************************************
    // Average v422 from GapA + GapB 
    //************************************************************************
    for(int bin=1; bin<201; bin++) {        
        double Counter = 0.0;
        double error_NL = 0.0;
        BinValue34 = Cn34->GetBinContent(bin);
        BinValue42 = Cn42->GetBinContent(bin);
        BinValue34_Entries = Cn34->GetBinEffectiveEntries(bin);
        BinValue42_Entries = Cn42->GetBinEffectiveEntries(bin);
        if( BinValue34_Entries > 1000 && BinValue42_Entries > 1000 && BinValue42 > 0  ) {
            BinValue42_Sqrt = sqrt(BinValue42);
            V422 = BinValue34 / (BinValue42_Sqrt); 
        } else {
            cout << "0"; 
            continue;
        }
        for (int sample=1; sample<11; sample++) {
            TString foo_34(TString::Format("fTprof34_number%dGap08BNtrks1bin", sample));	
            TProfile *prof34 = (TProfile*)list->FindObject(foo_34);
            TString foo_42(TString::Format("fTprof42_number%dGap08Ntrks1bin", sample));	
            TProfile *prof42 = (TProfile*)list->FindObject(foo_42);
            BinValue34_Sample = prof34->GetBinContent(bin);
            BinValue42_Sample = prof42->GetBinContent(bin);
            BinValue34_Entries_Sample = prof34->GetBinEffectiveEntries(bin);
            BinValue42_Entries_Sample = prof42->GetBinEffectiveEntries(bin);    
            if( BinValue34_Entries_Sample > 100 && BinValue42_Entries_Sample > 100 && BinValue42_Sample > 0) {
                Counter += 1;
                cout << "1";
                BinValue42_Sample_Sqrt = sqrt(BinValue42_Sample);
                V422_Sample = BinValue34_Sample / (BinValue42_Sample_Sqrt);
                error_NL += pow(V422_Sample - V422, 2);                 
            } else {
                cout << "0"; 
                continue;
            }
        }
        if(Counter!=0) {
            NonLinear_Error = sqrt(error_NL / (Counter * Counter) );
            hV422->SetBinContent(bin, V422); 
            hV422->SetBinError(bin, NonLinear_Error); 
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
            continue;
        }
    }




    //..Plot:
    hV422->Draw();
    //c->SaveAs("/Users/Helena/Desktop/pic/Katka_plots/Debug2_V4_Linear_gap08.png");
    TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Debug_Average_V422_NUA+NUE.root","UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    //hC42->Write("hC42_Sqrt_Gap00");
    //hCLinear->Write("V4Linear_Gap00");
    hV422->Write("v422_Gap08B");
}