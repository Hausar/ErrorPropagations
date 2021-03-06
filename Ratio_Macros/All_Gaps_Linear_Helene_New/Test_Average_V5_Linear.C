
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

void Test_Average_V5_Linear() {
    double BinValue35A = 0.0;
    double BinValue35B = 0.0; 
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
    double Linear_A = 0.0;
    double Linear_B = 0.0;
    double Linear_Sample_A = 0.0;
    double Linear_Sample_B = 0.0;
    double Linear_value_A = 0.0;
    double Linear_value_B = 0.0;
    double Linear_average = 0.0; 
    double Linear_average_sample = 0.0;
    double Linear_value_sample_A = 0.0;
    double Linear_value_sample_B = 0.0;
    double Linear_Error = 0.0; 
    double final_error_2part = 0.0;
    double Sample_Linear = 0.0; 
    double V532_A = 0.0;
    double V532_B = 0.0;
    double V532_A_Sample = 0.0;
    double V532_B_Sample = 0.0;


    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd(); 
    TH1D *hCLinear = new TH1D("hCLinear", " The Linear Response V5^{L} |#Delta#eta| > 0.0 ", 200, 0, 200); //this is just define a histogram which will fill the data.
    hCLinear->Sumw2();
    //Open the latest root.file:
    TFile *file = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_Corrected_4particle.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");
    
    //**************************************************************************
    //..open the TProfiles:
    TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap07Ntrks1bin");   //..V5{2}
    TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap07Ntrks1bin");   //..v2^{2}
    TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap07Ntrks1bin");  //..v3^{2} 
    TProfile *Cn35A = (TProfile*)list->FindObject("fTprofC35Gap07ANtrks1bin"); //..<<3>>_{5|-3,-2}  
    TProfile *Cn35B = (TProfile*)list->FindObject("fTprofC35Gap07BNtrks1bin"); 
    //**************************************************************************
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
        BinValue22 = Cn22->GetBinContent(bin);
        BinValue23 = Cn23->GetBinContent(bin);
        BinValue25 = Cn25->GetBinContent(bin);
        BinValue35A = Cn35A->GetBinContent(bin);
        BinValue35B = Cn35B->GetBinContent(bin); 
        BinValue22_Entries = Cn22->GetBinEffectiveEntries(bin);
        BinValue23_Entries = Cn23->GetBinEffectiveEntries(bin);
        BinValue25_Entries = Cn25->GetBinEffectiveEntries(bin);
        BinValue35A_Entries = Cn35A->GetBinEffectiveEntries(bin);
        BinValue35B_Entries = Cn35B->GetBinEffectiveEntries(bin);
        if( BinValue22_Entries > 1000 && BinValue23_Entries > 1000 && BinValue25_Entries > 1000 && BinValue35A_Entries > 1000 && BinValue35B_Entries > 1000 && BinValue23 > 0 && BinValue22 > 0 && BinValue25 > 0 ) {
            BinValue22_Sqrt = sqrt(BinValue22);
            BinValue23_Sqrt = sqrt(BinValue23);
            BinValue25_Sqrt = sqrt(BinValue25);
            V532_A = BinValue35A / (BinValue22_Sqrt * BinValue23_Sqrt);
            V532_B = BinValue35B / (BinValue22_Sqrt * BinValue23_Sqrt);
            Linear_A = pow(BinValue25_Sqrt, 2) - pow(V532_A, 2);
            Linear_B = pow(BinValue25_Sqrt, 2) - pow(V532_B, 2);
            if(Linear_A > 0 && Linear_B > 0 ) {
                Linear_value_A = sqrt(Linear_A);
                Linear_value_B = sqrt(Linear_B);
                Linear_average = (Linear_value_A + Linear_value_B / (2));
            } else {
                continue;
            }   
        } else {
            cout << "0" << endl; 
            continue;
        }
        for (int sample=1; sample<11; sample++) {
            //..Gap = 0.0-0.8
            TString foo_35A(TString::Format("fTprof35_number%dGap07ANtrks1bin", sample));
            TProfile *prof35A = (TProfile*)list->FindObject(foo_35A);
            TString foo_35B(TString::Format("fTprof35_number%dGap07BNtrks1bin", sample));
            TProfile *prof35B = (TProfile*)list->FindObject(foo_35B);
            TString foo_25(TString::Format("fTprof25_number%dGap07Ntrks1bin", sample));
            TProfile *prof25 = (TProfile*)list->FindObject(foo_25);
            TString foo_22(TString::Format("fTprof22_number%dGap07Ntrks1bin", sample));	
            TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            TString foo_23(TString::Format("fTprof23_number%dGap07Ntrks1bin", sample));	
            TProfile *prof23 = (TProfile*)list->FindObject(foo_23);
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
            
            if( BinValue25_Entries_Sample > 100 && BinValue35A_Entries_Sample > 100 && BinValue35B_Entries_Sample > 100 && BinValue22_Entries_Sample > 100 && BinValue23_Entries_Sample > 100 && BinValue22_Sample > 0 && BinValue23_Sample > 0 && BinValue25_Sample > 0) {
                cout << "1";
                BinValue22_Sample_Sqrt = sqrt(BinValue22_Sample);
                BinValue23_Sample_Sqrt = sqrt(BinValue23_Sample);
                BinValue25_Sample_Sqrt = sqrt(BinValue25_Sample);
                //..Calculate v532 Non-Linear:
                V532_A_Sample = BinValue35A_Sample / (BinValue22_Sample_Sqrt * BinValue23_Sample_Sqrt); 
                V532_B_Sample = BinValue35B_Sample / (BinValue22_Sample_Sqrt * BinValue23_Sample_Sqrt);              
                Linear_Sample_A = pow(BinValue25_Sample_Sqrt, 2) - pow(V532_A_Sample, 2);
                Linear_Sample_B = pow(BinValue25_Sample_Sqrt, 2) - pow(V532_B_Sample, 2); 
                if(Linear_Sample_A > 0 && Linear_Sample_B > 0 ) {
                    Counter += 1;
                    Linear_value_sample_A = sqrt(Linear_Sample_A);
                    Linear_value_sample_B = sqrt(Linear_Sample_B);
                    Linear_average_sample = Linear_value_sample_A + Linear_value_sample_B / (2);
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
    //c->SaveAs("/Users/Helena/Desktop/pic/Katka_plots/Debug2_V4_Linear_gap07.png");
    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Debugged_Average_V5_Linear_A+B_NUA+NUE.root","UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hCLinear->Write("V5_Linear_Gap07_A+B");
} 