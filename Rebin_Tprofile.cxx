//Macro To Calculate the Rebin Tprofiles:
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

void Rebin_Tprofile() {
    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(19);
    c->cd();

    TH1F *Rebin_hist_C24 = new TH1F("Rebin_hist_C24", "the new Rebin plot for <<2>>_{4,-4} with #eta Gap = 0.2", 20, 0, 200);
    Rebin_hist_C24->Sumw2();

    //Open the root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/LHC16q_CENT_SDD_0Gap_2_08Gap_FullGaps.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("MyTaskResults");
    TList *list = (TList*)dir->Get("Flow_Refs_MyTaskResults");

    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC22Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Ntrks1bin"); 

    TProfile *Cn24_Gap02 = (TProfile*)list->FindObject("fTprofC22Gap02Ntrks1bin");
    TProfile *Cn42_Gap02 = (TProfile*)list->FindObject("fTprofC42Gap02Ntrks1bin");  
    TProfile *Cn34_Gap02 = (TProfile*)list->FindObject("fTprofC34Gap02Ntrks1bin"); 

    //..Rebin the Tprofile
    //Cn24_Gap02->Rebin(2);
    TH1F *hCn24_Gap02_Rebin = Cn24_Gap02->Rebin(10, "hCn24_Gap02_Rebin");
    hCn24_Gap02_Rebin->SetAxisRange(0., 160);
    
    TH1F *hCn42_Gap02_Rebin = Cn42_Gap02->Rebin(10, "hCn42_Gap02_Rebin");
    hCn42_Gap02_Rebin->SetAxisRange(0., 160);

    TH1F *hCn34_Gap02_Rebin = Cn34_Gap02->Rebin(10, "hCn34_Gap02_Rebin");
    hCn34_Gap02_Rebin->SetAxisRange(0., 160);
    //..Plot the data 
    
    // Cn24->Draw();
    // Cn42->Draw();
    // Cn34->Draw();
    //Cn24_Gap02->Draw();
    // Cn42_Gap02->Draw();
    // Cn34_Gap02->Draw();
    hCn24_Gap02_Rebin->Draw();
    hCn42_Gap02_Rebin->Draw();
    hCn34_Gap02_Rebin->Draw();
    //..Save to file.root
    TFile* fileOutput = new TFile("Rebin_histogram_Test.root","RECREATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hCn24_Gap02_Rebin->Write();
    hCn42_Gap02_Rebin->Write();
    hCn34_Gap02_Rebin->Write();
    
    return;
}