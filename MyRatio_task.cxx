//#include "myMacro.h"
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

void MyRatio_task(){

    TCanvas *c1 = new TCanvas("c1","The HISTOGRAM example",100,8,700,600);
    c1->SetFillColor(19);
    c1->cd();

    Ratio_hist = new TH1F("Ratio_hist", "Ratio_hist", 360, 0, TMath::TwoPi());   // create your histogram for phi
    Ratio_hist->Sumw2();

    hwx = new TH1D("hwx", "hwx", 360, 0, TMath::TwoPi());   // create your histogram for phi
    hwx->Sumw2();

    hwKatarina = new TH1D("hwKatarina", "hwKatarina", 360, 0, TMath::TwoPi());   // create your histogram for phi
    hwKatarina->Sumw2();

    TFile *file = TFile::Open("/Users/Helena/Desktop/bar/WeightMaximum_Finalversion/merging/merge/merge_265425/Weight_Runnumber_265425.root","READ");  
    if(file)
    {
        Weight_Runnumber_265425 = (TH2F*) file->Get("Weight_Runnumber_265425");
    }
    else cout << "weights not found" << endl;  

    if(Weight_Runnumber_265425)
    {
        hwx = Weight_Runnumber_265425->ProjectionX();
        //hwx->Draw(" ");
        //Weight_Runnumber_265425->Draw("colz");    
    }

    //Weight_Runnumber_265425->Rebin2D(1,2);
    //Weight_Runnumber_265425->Draw("colz");
    
    TFile *fileKatarina = TFile::Open("/Users/Helena/Desktop/Katarina_LHC16q/PhiWeight2D_LHC16q_CENT_wSDD.root","READ");  
    // if(fileKatarina)
    // {
    //     fPhiWeight_LHC16q_CENT_wSDD = (TH2F*) fileKatarina->Get("fPhiWeight_LHC16q_CENT_wSDD");
    // }
    
    if(fPhiWeight_LHC16q_CENT_wSDD)
    {
        hwKatarina = fPhiWeight_LHC16q_CENT_wSDD_265425->ProjectionX();
        cout << "The Ratio of phi:" << endl;
        //fPhiWeight_LHC16q_CENT_wSDD_265425->Draw("colz");
    }
    //fPhiWeight_LHC16q_CENT_wSDD_265425->Divide(Weight_Runnumber_265425); 
    //fPhiWeight_LHC16q_CENT_wSDD_265425->Draw("colz");

    Ratio_hist->Divide(hwx, hwKatarina, 1., 1., "b");
    //Ratio_hist->Draw("e");

    TFile* fileOutput = new TFile("Ratio_Weights_Phi_hist.root","RECREATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hwx->Write();
    //return;

    //..Make comparison with Katarinas resuts 
    TFile *test = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/LHC16q_CENT_SDD_W_NUA_Kitkat.root","READ");  
    if(!test) return;

    test->cd("MyTaskResults");
    TList* list = (TList*) gDirectory->Get("Flow_Refs_MyTaskResults");
    if(!list) return;
    
    TProfile* fTprofC24 = (TProfile*) list->FindObject("fTprofC24");
    if(!fTprofC24) return;
    
    fTprofC24->Draw();

    // TFile *test_Kat = TFile::Open("/Users/Helena/Desktop/Katarina_LHC16q/pPb5TeV_LHC16q_CENT_wSDD_FB96_pt0230_eta08_Vz10_wNUA.root","READ");  
    // if(!test_Kat) return;

    // Hcum42Ntrks = (TH1D*) test_Kat->Get("Hcum42Ntrks");
    // Hcum42Ntrks->Draw("same");
    TFile *test = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/LHC16q_CENT_SDD_W_NUA_Final.root","READ");  
    if(!test) return;

    test->cd("MyTaskResults");
    TList* list = (TList*) gDirectory->Get("Flow_Refs_MyTaskResults");
    if(!list) return;
    
    TProfile* fTprofC24 = (TProfile*) list->FindObject("fTprofC24");
    if(!fTprofC24) return;
    fTprofC24->Draw("same");


}    