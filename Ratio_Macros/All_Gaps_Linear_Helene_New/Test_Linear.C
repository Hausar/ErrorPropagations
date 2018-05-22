
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

void Test_Linear() {
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
    double final_error_4part = 0.0;
    double Sample_Linear = 0.0; 
    double V422 = 0.0;
    double V422_Sample = 0.0;
    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    
    TH1D *hC22 = new TH1D("hC22", " V4{2},  #sqrt{< v_{4}^{2} >}, 2-Particle correlation", 200, 0, 200); //this is just define a histogram which will fill the data.
    hC22->Sumw2();
    
    TH1D *hC42 = new TH1D("hC42", " #sqrt{< v_{2}^{4} >} 4-Particle correlation", 200, 0, 200); //this is just define a histogram 
	hC42->Sumw2();

    TH1D *hV422 = new TH1D("hV422", "The Non-Linear Response, v_{4,22} = #frac {<<3>>} {#sqrt{< v_{2}^{4} >}}", 200, 0, 200); //this is just define a histogram which will fill the data of V422.
    hV422->Sumw2();
 
    TH1D *hCLinear = new TH1D("hCLinear", " The Linear Response V4^{L} ", 200, 0, 200); //this is just define a histogram which will fill the data.
    hCLinear->Sumw2();

    //Open the latest root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_Corrected_4particle.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");
    
    //**************************************************************************
    //..Gap= 0.8
    TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap00Ntrks1bin");
    TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap00Ntrks1bin");  
    TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap00ANtrks1bin");  
    //**************************************************************************
    //****************************************************
    //// Loop to get sqrt of each bin in Tprofile of//////
    ////   Cn{4} = <<4>> = <vn^4> = <<4>> - 2 <<2>>^2 ////
    /////     v2{4} = sqrt(<<4>>_{2,2|-2,-2})        /////
    /////     ********** <<4>> *************        //////
    //*****************************************************
    for(int bin=1; bin<201; bin++) { 
        double Counter = 0.0;
        double error_4part = 0.0;
        BinValue42 = Cn42->GetBinContent(bin); 
        BinValue42_Entries = Cn42->GetBinEffectiveEntries(bin); 
        if(BinValue42_Entries > 1000 && BinValue42 > 0 ) {
            BinValue42_Sqrt = sqrt(BinValue42);
        } else {
            cout << "0"; 
            continue;
        }
        for(int sample=1; sample<11; sample++) {   
            TString foo_42(TString::Format("fTprof42_number%0dGap00Ntrks1bin", sample)); 
            TProfile *fprof42 = (TProfile*)list->FindObject(foo_42);
            BinValue42_Sample = fprof42->GetBinContent(bin);
            BinValue42_Entries_Sample = fprof42->GetBinEffectiveEntries(bin);
            if(BinValue42_Entries_Sample > 100 && BinValue42_Sample > 0 ) {
                Counter += 1;
                cout << "1";
                BinValue42_Sample_Sqrt = sqrt(BinValue42_Sample);
                error_4part += pow(BinValue42_Sample_Sqrt - BinValue42_Sqrt, 2);
            } else {
                cout << "0"; 
                continue;
            }
        }
        if(Counter!=0) {
            final_error_4part = sqrt(error_4part / (Counter * Counter) );
            hC42->SetBinContent(bin, BinValue42_Sqrt);
            hC42->SetBinError(bin, final_error_4part);
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
            continue;
        }
    }
 //****************************************************************************
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
        BinValue24 = Cn24->GetBinContent(bin);
        BinValue34 = Cn34->GetBinContent(bin);
        BinValue42 = Cn42->GetBinContent(bin);
        BinValue24_Entries = Cn24->GetBinEffectiveEntries(bin);
        BinValue34_Entries = Cn34->GetBinEffectiveEntries(bin);
        BinValue42_Entries = Cn42->GetBinEffectiveEntries(bin);
        if( BinValue24_Entries > 1000 && BinValue34_Entries > 1000 && BinValue42_Entries > 1000 && BinValue42 > 0 && BinValue24 > 0 ) {
            BinValue24_Sqrt = sqrt(BinValue24);
            BinValue42_Sqrt = sqrt(BinValue42);
            V422 = BinValue34 / (BinValue42_Sqrt);
            Linear = pow(BinValue24_Sqrt, 2) - pow(V422, 2);
            if(Linear > 0) {
                Linear_value = sqrt(Linear);
            } else {
                continue;
            }   
        } else {
            cout << "0" << endl; 
            continue;
        }
        for (int sample=1; sample<11; sample++) {
            //..Gap= 0.8
            TString foo_24(TString::Format("fTprof24_number%dGap00Ntrks1bin", sample));
            TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            TString foo_34(TString::Format("fTprof34_number%dGap00ANtrks1bin", sample));	
            TProfile *prof34 = (TProfile*)list->FindObject(foo_34);
            TString foo_42(TString::Format("fTprof42_number%dGap00Ntrks1bin", sample));	
            TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            BinValue24_Sample = prof24->GetBinContent(bin);
            BinValue34_Sample = prof34->GetBinContent(bin);
            BinValue42_Sample = prof42->GetBinContent(bin);
            BinValue24_Entries_Sample = prof24->GetBinEffectiveEntries(bin);
            BinValue34_Entries_Sample = prof34->GetBinEffectiveEntries(bin);
            BinValue42_Entries_Sample = prof42->GetBinEffectiveEntries(bin);
            
            if( BinValue24_Entries_Sample > 100 && BinValue34_Entries_Sample > 100 && BinValue42_Entries_Sample > 100 && BinValue24_Sample > 0 && BinValue42_Sample > 0) {
                cout << "1";
                BinValue24_Sample_Sqrt = sqrt(BinValue24_Sample);
                BinValue42_Sample_Sqrt = sqrt(BinValue42_Sample);
                //..Calculate v422 Non-Linear:
                V422_Sample = BinValue34_Sample / (BinValue42_Sample_Sqrt);               
                Linear_Sample = pow(BinValue24_Sample_Sqrt, 2) - pow(V422_Sample, 2); 
                if(Linear_Sample > 0 ) {
                    Counter += 1;
                    Linear_value_sample = sqrt(Linear_Sample);
                    error_L += pow(Linear_value_sample - Linear_value, 2);
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
            hCLinear->SetBinContent(bin, Linear_value); 
            hCLinear->SetBinError(bin, Linear_Error); 
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
            continue;
        }
    }
    //..Plot:
    //hC42->Draw();
    hCLinear->Draw();
    //c->SaveAs("/Users/Helena/Desktop/pic/Katka_plots/Debug2_V4_Linear_gap08.png");
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Debugged_V422_Linear_NUA+NUE.root","UPDATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC42->Write("hC42_Sqrt_Gap00");
    // hCLinear->Write("V4Linear_Gap00");
}