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

void Rebin_3Particle_4Particle_Correlations() {
    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    TH1F *Rebin_hist_C24 = new TH1F("Rebin_hist_C24", "the new Rebin plot for <<2>>_{4,-4} with #eta Gap = 0.2", 20, 0, 200);
    Rebin_hist_C24->Sumw2();

    TProfile *Rebinhist34 = new TProfile("Rebinhist34", "the new Rebin plot", 10, 0, 200);
    Rebinhist34->Sumw2();

    //Open the root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/LHC16q_CENT_SDD_0Gap_2_08Gap_FullGaps.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("MyTaskResults");
    TList *list = (TList*)dir->Get("Flow_Refs_MyTaskResults");
    
    //*************************************************************************
    int EtaGap[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    for(int i=1; i< 201; i++) {
        for(int j=0; j <9; j++) {
            TString foo(TString::Format("fTprofC34Gap0%0dNtrks1bin", EtaGap[j]));
            TProfile *fTtest = (TProfile*)list->FindObject(foo);
            //..Try to Rebin
            TH1D* hChi422_Rebin = new TH1D(Form("hChi422_Rebin_Gap%0d", EtaGap[j])," #chi_{4,22}; #N_ch; #chi_{4,22}", 10, 0, 200);
		    hChi422_Rebin->Sumw2();
            //hChi422_Rebin = fTtest->Rebin(10, "hChi422_Rebin");
        }
    }   




    //*************************************************************************

    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC22Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Ntrks1bin"); 

    // TProfile *Cn34_Gap0 = (TProfile*)list->FindObject("fTprofC34Gap0Ntrks1bin"); 
    // TProfile *Cn35_Gap0 = (TProfile*)list->FindObject("fTprofC35Gap0Ntrks1bin");
    // TProfile *Cn42_Gap0 = (TProfile*)list->FindObject("fTprofC42Gap0Ntrks1bin");  
    // TProfile *Cn43_Gap0 = (TProfile*)list->FindObject("fTprofC43Gap0Ntrks1bin");  

    // TProfile *Cn34_Gap01 = (TProfile*)list->FindObject("fTprofC34Gap01Ntrks1bin"); 
    // TProfile *Cn35_Gap01 = (TProfile*)list->FindObject("fTprofC35Gap01Ntrks1bin");
    // TProfile *Cn42_Gap01 = (TProfile*)list->FindObject("fTprofC42Gap01Ntrks1bin");  
    // TProfile *Cn43_Gap01 = (TProfile*)list->FindObject("fTprofC43Gap01Ntrks1bin");  

    // TProfile *Cn34_Gap02 = (TProfile*)list->FindObject("fTprofC34Gap02Ntrks1bin"); 
    // TProfile *Cn35_Gap02 = (TProfile*)list->FindObject("fTprofC35Gap02Ntrks1bin");
    // TProfile *Cn42_Gap02 = (TProfile*)list->FindObject("fTprofC42Gap02Ntrks1bin");  
    // TProfile *Cn43_Gap02 = (TProfile*)list->FindObject("fTprofC43Gap02Ntrks1bin");  

    // TProfile *Cn34_Gap03 = (TProfile*)list->FindObject("fTprofC34Gap03Ntrks1bin"); 
    // TProfile *Cn35_Gap03 = (TProfile*)list->FindObject("fTprofC35Gap03Ntrks1bin");
    // TProfile *Cn42_Gap03 = (TProfile*)list->FindObject("fTprofC42Gap03Ntrks1bin");  
    // TProfile *Cn43_Gap03 = (TProfile*)list->FindObject("fTprofC43Gap03Ntrks1bin");  


    // TProfile *Cn34_Gap04 = (TProfile*)list->FindObject("fTprofC34Gap04Ntrks1bin"); 
    // TProfile *Cn35_Gap04 = (TProfile*)list->FindObject("fTprofC35Gap04Ntrks1bin");
    // TProfile *Cn42_Gap04 = (TProfile*)list->FindObject("fTprofC42Gap04Ntrks1bin");  
    // TProfile *Cn43_Gap04 = (TProfile*)list->FindObject("fTprofC43Gap04Ntrks1bin");  

    // TProfile *Cn34_Gap05 = (TProfile*)list->FindObject("fTprofC34Gap05Ntrks1bin"); 
    // TProfile *Cn35_Gap05 = (TProfile*)list->FindObject("fTprofC35Gap05Ntrks1bin");
    // TProfile *Cn42_Gap05 = (TProfile*)list->FindObject("fTprofC42Gap05Ntrks1bin");  
    // TProfile *Cn43_Gap05 = (TProfile*)list->FindObject("fTprofC43Gap05Ntrks1bin");  

    // TProfile *Cn34_Gap06 = (TProfile*)list->FindObject("fTprofC34Gap06Ntrks1bin"); 
    // TProfile *Cn35_Gap06 = (TProfile*)list->FindObject("fTprofC35Gap06Ntrks1bin");
    // TProfile *Cn42_Gap06 = (TProfile*)list->FindObject("fTprofC42Gap06Ntrks1bin");  
    // TProfile *Cn43_Gap06 = (TProfile*)list->FindObject("fTprofC43Gap06Ntrks1bin");  

    // TProfile *Cn34_Gap07 = (TProfile*)list->FindObject("fTprofC34Gap07Ntrks1bin"); 
    // TProfile *Cn35_Gap07 = (TProfile*)list->FindObject("fTprofC35Gap07Ntrks1bin");
    // TProfile *Cn42_Gap07 = (TProfile*)list->FindObject("fTprofC42Gap07Ntrks1bin");  
    // TProfile *Cn43_Gap07 = (TProfile*)list->FindObject("fTprofC43Gap07Ntrks1bin");  

    // TProfile *Cn34_Gap08 = (TProfile*)list->FindObject("fTprofC34Gap08Ntrks1bin"); 
    // TProfile *Cn35_Gap08 = (TProfile*)list->FindObject("fTprofC35Gap08Ntrks1bin");
    // TProfile *Cn42_Gap08 = (TProfile*)list->FindObject("fTprofC42Gap08Ntrks1bin");  
    // TProfile *Cn43_Gap08 = (TProfile*)list->FindObject("fTprofC43Gap08Ntrks1bin");  


    // //..Rebin the Tprofile in Manual way 
    // TH1F *TprofileRebin34 = Cn34_Gap0->Rebin(10, "TprofileRebin34");
    // TprofileRebin34->Draw();

    // TH1F *TprofileRebin35 = Cn35_Gap0->Rebin(10, "TprofileRebin35");
    // TprofileRebin35->Draw();

    // TH1F *TprofileRebin42 = Cn42_Gap0->Rebin(10, "TprofileRebin42");
    // TprofileRebin42->Draw();

    // TH1F *TprofileRebin43 = Cn43_Gap0->Rebin(10, "TprofileRebin43");
    // TprofileRebin43->Draw();

    //..Save to file.root
    // TFile* fileOutput = new TFile("Rebin_Tprofile_3_4particle.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // TprofileRebin34->Write();
    // TprofileRebin35->Write();
    // TprofileRebin42->Write();
    // TprofileRebin43->Write();
    //return;



    // //Cn24_Gap02->Rebin(2);
    // TH1F *hCn24_Gap02_Rebin = Cn24_Gap02->Rebin(10, "hCn24_Gap02_Rebin");
    // hCn24_Gap02_Rebin->SetAxisRange(0., 160);
    
    // TH1F *hCn42_Gap02_Rebin = Cn42_Gap02->Rebin(10, "hCn42_Gap02_Rebin");
    // hCn42_Gap02_Rebin->SetAxisRange(0., 160);

    // TH1F *hCn34_Gap02_Rebin = Cn34_Gap02->Rebin(10, "hCn34_Gap02_Rebin");
    // hCn34_Gap02_Rebin->SetAxisRange(0., 160);
    //..Plot the data 
    // Cn24->Draw();
    // Cn42->Draw();
    // Cn34->Draw();
    //Cn24_Gap02->Draw();
    // Cn42_Gap02->Draw();
    //Cn34_Gap02->Draw();
    //Cn34_Gap02->SetAxisRange(10., 100);
    //hCn34_Gap02_Rebin->Draw();
    //hCn42_Gap02_Rebin->Draw();
    //hCn34_Gap02_Rebin->Draw();


    //..old
    // hCn34_Gap02_Rebin->Write();
    // hCn42_Gap02_Rebin->Write();
    // hCn34_Gap02_Rebin->Write();
    
}