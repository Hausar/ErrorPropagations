//////////
/////////
//Macro to take the Ratio of <<3>> to <<4>> which results the symmetry plane correlations:
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

void MyRatio_Results() {

    TCanvas *c1 = new TCanvas("c1","The Ratio HISTOGRAM ", 100,8,700,600);
    c1->SetFillColor(19);
    c1->cd();

    TProfile *tprof = new TProfile("tprof", "The Projection to X", 200, 0, 200); 
    tprof->Sumw2();
    
    //Open the root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/LHC16q_CENT_SDD_W_NUA_Final.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("MyTaskResults");
    TList *list = (TList*)dir->Get("Flow_Refs_MyTaskResults");
   
    if(file) { 
        //..Read Tprofiles: For Ratio of <<3>> / <<4>> 
        TProfile *fc22 = (TProfile*)list->FindObject("fTprofC22");
        TProfile *fc23 = (TProfile*)list->FindObject("fTprofC23");  
        TProfile *fc24 = (TProfile*)list->FindObject("fTprofC24");
        //Projection to X:
        TH1D *h1 = fc22->ProjectionX("h1");
        TH1D *h2 = fc23->ProjectionX("h2");
        TH1D *h3 = fc24->ProjectionX("h3");
    }
    // //Open the root.file From Katarinas Results:
    TFile* fileKitkat = TFile::Open("/Users/Helena/Desktop/Katarina_LHC16q/pPb5TeV_LHC16q_CENT_wSDD_FB96_pt0230_eta08_Vz10_wNUA.root","READ");
    if(fileKitkat) {
        Hcum22Ntrks = (TH2F*) fileKitkat->Get("Hcum22Ntrks");
        Hcum32Ntrks = (TH2F*) fileKitkat->Get("Hcum32Ntrks");
        Hcum42Ntrks = (TH2F*) fileKitkat->Get("Hcum42Ntrks");
    }
    

    // //h1->SetMarkerStyle(kFullCircle); 
    // h1->SetMarkerColorAlpha(kRed, 4.5);
    // h1->SetLineColor(kRed);
    // h1->Draw();
    
    // //Hcum22Ntrks->SetMarkerStyle(kFullSquare);
    // Hcum22Ntrks->SetMarkerColorAlpha(kBlue, 6.);
    // Hcum22Ntrks->SetLineColor(kBlue);
    // Hcum22Ntrks->Draw("same");
    // c1->SaveAs("/Users/Helena/Desktop/Ratio_plots_Helene/Compare22.pdf");

    // h2->SetMarkerColorAlpha(kRed, 4.5);
    // h2->SetLineColor(kRed);
    // h2->Draw();
    
    // //Hcum22Ntrks->SetMarkerStyle(kFullSquare);
    // Hcum32Ntrks->SetMarkerColorAlpha(kBlue, 6.);
    // Hcum32Ntrks->SetLineColor(kBlue);
    // Hcum32Ntrks->Draw("same");
    // c1->SaveAs("/Users/Helena/Desktop/Ratio_plots_Helene/Compare23.pdf");

    // h3->SetMarkerColorAlpha(kRed, 4.5);
    // h3->SetLineColor(kRed);
    // h3->Draw();
    
    // //Hcum22Ntrks->SetMarkerStyle(kFullSquare);
    // Hcum42Ntrks->SetMarkerColorAlpha(kBlue, 6.);
    // Hcum42Ntrks->SetLineColor(kBlue);
    // Hcum42Ntrks->Draw("same");
    // c1->SaveAs("/Users/Helena/Desktop/Ratio_plots_Helene/Compare24.pdf");

    //gPad->BuildLegend();
    //Hcum32Ntrks->Draw();
    //Hcum42Ntrks->Draw();


    h1->SetMarkerColorAlpha(kRed, 4.5);
    h1->SetLineColor(kRed);
    h1->Divide(Hcum22Ntrks); 
    h1->Draw();
    
    TLine *line = new TLine(0, 1, 200., 1);
    line->SetLineColor(kBlack);
    line->Draw("same");
 

    //Hcum22Ntrks->Divide(h1);
    //*******************
    // for ratio of <<3>> / <<4>> 
    //Projection to X:

    //..Divide two Tprofile to get Ratio:
    // h1->Divide(Hcum22Ntrks); 
    // h1->SetMarkerColorAlpha(kRed, 4.5);
    // Hcum22Ntrks->SetMarkerColorAlpha(kBlue, 4.5);
    // h1->Draw("EP");

    // h2->Divide(Hcum32Ntrks); 
    // h2->Draw();

    // h3->Divide(Hcum42Ntrks);
    // h3->SetMarkerStyle(kFullCircle); 
    // h3->Draw();


    // Hcum22Ntrks->Divide(h1);
    // Hcum22Ntrks->Draw();

}

