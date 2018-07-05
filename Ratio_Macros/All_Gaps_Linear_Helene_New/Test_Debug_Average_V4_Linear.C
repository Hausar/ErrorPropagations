
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

void Test_Debug_Average_V4_Linear() {
    double BinValuev422 = 0.0; 
    double BinErrorv422 = 0.0;
    double BinValue25 = 0.0;
    double BinValue22 = 0.0;
    double BinValue23 = 0.0;
    double BinValue35A_Sample = 0.0;
    double BinValue35B_Sample  = 0.0;
    double BinValue25_Sample = 0.0;
    double BinValue22_Sample = 0.0;
    double BinValue23_Sample = 0.0;
    double BinValue35A_Entries = 0.0;
    double BinValue35B_Entries = 0.0;
    double BinValue25_Entries = 0.0;
    double BinValue22_Entries = 0.0;
    double BinValue23_Entries = 0.0;
    double BinValue25_Sample = 0.0;
    double BinValue22_Sample = 0.0;
    double BinValue23_Sample = 0.0;
    double BinValue35A_Entries_Sample = 0.0;
    double BinValue35B_Entries_Sample = 0.0;
    double BinValue25_Entries_Sample = 0.0;
    double BinValue22_Entries_Sample = 0.0;
    double BinValue23_Entries_Sample = 0.0;
    double BinValue25_Sqrt = 0.0;
    double BinValue22_Sqrt = 0.0;
    double BinValue23_Sqrt = 0.0;
    double BinValue25_Sample_Sqrt = 0.0;
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
    double Linear_Error = 0.0; 
    double final_error_2part = 0.0;
    double Sample_Linear = 0.0; 
    double V422_A = 0.0;
    double V422_B = 0.0;
    double V422_A_Sample = 0.0;
    double V422_B_Sample = 0.0;

    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd(); 
    TH1D *hCLinear = new TH1D("hCLinear", " The Linear Response V4^{L}|#Delta#eta| > 0.8 ", 200, 0, 200); //this is just define a histogram which will fill the data.
    hCLinear->Sumw2();
    //Open the latest root.file:
    TFile *file = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_Corrected_4particle.root", "READ");
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
    TFile* fileOutput = new TFile ("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Average_V422_NUA+NUE/Debug_Average_V532_A+B_NUA+NUE.root", "READ");
    v422_Average = (TH1D*)fileOutput->Get("v532_Gap08_A+B");
    //v422_Average->Draw();
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
        double Weight = 0.0;
        BinValue24 = Cn24->GetBinContent(bin);
        BinValue42 = Cn42->GetBinContent(bin);
        BinValue34A = Cn34A->GetBinContent(bin);
        BinValue34B = Cn34B->GetBinContent(bin);
        BinValuev422 = v422_Average->GetBinContent(bin);
        BinErrorv422 = v422_Average->GetBinError(bin);
        BinValue24_Entries = Cn24->GetBinEffectiveEntries(bin);
        if( BinValue24_Entries > 1000 && BinValue24 > 0 ) {
            BinValue24_Sqrt = sqrt(BinValue24);
            Linear = pow(BinValue24_Sqrt, 2) - pow(BinValuev422, 2);
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
            // TString foo_23(TString::Format("fTprof23_number%dGap08Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);
            BinValue34A_Sample = prof34A->GetBinContent(bin);
            BinValue34B_Sample = prof34B->GetBinContent(bin);
            BinValue24_Sample = prof24->GetBinContent(bin);
            BinValue42_Sample = prof42->GetBinContent(bin);
            // BinValue23_Sample = prof23->GetBinContent(bin);
            BinValue34A_Entries_Sample = prof34A->GetBinEffectiveEntries(bin);
            BinValue34B_Entries_Sample = prof34B->GetBinEffectiveEntries(bin);
            BinValue24_Entries_Sample = prof24->GetBinEffectiveEntries(bin);
            BinValue42_Entries_Sample = prof42->GetBinEffectiveEntries(bin);
            // BinValue23_Entries_Sample = prof23->GetBinEffectiveEntries(bin);
            
            if( BinValue24_Entries_Sample > 100 && BinValue24_Sample > 0  ) {
                cout << "1";
                // BinValue22_Sample_Sqrt = sqrt(BinValue22_Sample);
                BinValue24_Sample_Sqrt = sqrt(BinValue24_Sample);
                Linear_Sample = pow(BinValue24_Sample_Sqrt, 2) - pow(BinValuev422, 2); 
                
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
    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/V4_V5_Linear_Debug/4particle_Debug_V4_V5_Linear.root","UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hCLinear->Write("V4_Linear_Gap08_A+B");
} 