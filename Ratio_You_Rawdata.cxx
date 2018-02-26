//This Macro is for making Ratio between my data and Yous data:
// ROOT includes
#include <TList.h>
#include <TFile.h>
#include <TMath.h>
#include <TF1.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TProfile.h>
#include <TClonesArray.h>
#include <TRandom3.h>
#include <TComplex.h>
#include <algorithm>
#include <TMath.h>

void Ratio_You_Rawdata() {

    TCanvas *c = new TCanvas("c","The HISTOGRAM example",100,8,700,600);
    c->SetFillColor(10);
    c->cd();

    Ratio_plot = new TH1D("Ratio_plot", "Ratio_plot", 200, 0, 200);
    //Ratio_plot->Draw(); 

    Cn34_Gap0_1D = new TH1D("Cn34_Gap0_1D", "Cn34_Gap0_1D", 200, 0, 200);
    //Cn34_Gap0_1D->Draw(); 



    //Open root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/LHC16q_CENT_SDD_0Gap_2_08Gap_FullGaps.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("MyTaskResults");
    TList *list = (TList*)dir->Get("Flow_Refs_MyTaskResults");

    TProfile *Cn22_Gap0 = (TProfile*)list->FindObject("fTprofC22Gap0Ntrks1bin");
    TProfile *Cn23_Gap0 = (TProfile*)list->FindObject("fTprofC23Gap0Ntrks1bin");
    TProfile *Cn42_Gap0 = (TProfile*)list->FindObject("fTprofC42Gap0Ntrks1bin");  
    TProfile *Cn34_Gap0 = (TProfile*)list->FindObject("fTprofC34Gap0Ntrks1bin");
    TProfile *Cn35_Gap0 = (TProfile*)list->FindObject("fTprofC35Gap0Ntrks1bin"); 

    Cn34_Gap0_1D = Cn34_Gap0->ProjectionX();
    Cn35_Gap0_1D = Cn35_Gap0->ProjectionX();
    Cn42_Gap0_1D = Cn42_Gap0->ProjectionX();
    Cn23_Gap0_1D = Cn23_Gap0->ProjectionX();
    Cn22_Gap0_1D = Cn22_Gap0->ProjectionX();


    //Cn34_Gap0_1D->Draw();

    //Open root.file:
    TFile *file2 = TFile::Open("/Users/Helena/Desktop/Katarina_all/You_comparision/Output_Nch.root", "READ");
    if(file2) {
        Cn34_Gap0_You = (TH1D*)file2->Get("fc422Gap0A"); 
        Cn35_Gap0_You = (TH1D*)file2->Get("fc532Gap0A");
        Cn42_Gap0_You = (TH1D*)file2->Get("fc24Gap0");
        fv22_Gap0_You = (TH1D*)file2->Get("fv22Gap0");
    }

    //..Make Ratio of two plots:
    //Cn34_Gap0_You->SetAxisRange(0., 100.,"X");
    //Cn34_Gap0_1D->SetAxisRange(0., 100., "X");

    //Ratio_plot->Divide(Cn34_Gap0_1D, Cn34_Gap0_You, 1., 1., "b");
    // auto axis = Ratio_plot->GetXaxis(); 
    // axis->SetLimits(0.,100.);
    //auto axis = Ratio_plot->GetYaxis(); 
    //axis->SetLimits(0.,10.);


    //Cn34_Gap0_1D->Draw("same");
    //Cn34_Gap0_You->Draw();
    // Cn35_Gap0_You->Draw();
    // Cn42_Gap0_You->Draw();
    //Cn22_Gap0_1D->Draw();
    //Ratio_plot->Draw();
    Cn34_Gap0_You->Divide(Cn34_Gap0_1D);
    Cn34_Gap0_You->SetAxisRange(-1., 5.,"Y");
    //Cn34_Gap0_You->Draw();

    Cn35_Gap0_You->Divide(Cn35_Gap0_1D);
    Cn35_Gap0_You->SetAxisRange(-1., 5.,"Y");
    //Cn35_Gap0_You->Draw();

    Cn42_Gap0_You->Divide(Cn42_Gap0_1D);
    Cn42_Gap0_You->SetAxisRange(-1., 3.,"Y");
    //Cn42_Gap0_You->Draw();

    // fv22_Gap0_You->Divide(Cn22_Gap0_1D);
    // fv22_Gap0_You->SetAxisRange(-1., 3.,"Y");
    // fv22_Gap0_You->Draw();


    TFile* fileOutput = new TFile("/Users/Helena/Desktop/Katarina_all/You_comparision/Raw_Data_comparision_you_helene.root","RECREATE");

    if(!fileOutput) return;
    fileOutput->cd();
    Cn34_Gap0_You->Write();
    Cn35_Gap0_You->Write();
    Cn42_Gap0_You->Write();

}