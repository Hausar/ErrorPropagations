//..The macro for plot Rebin: V4_NL, V4_L, V4{2} and 
//..The macro for plot Rebin: V5_NL, V5_L, V5{2}
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

void Plot_Rebin_V532_NL() 
{    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //..Open the Root.file:

     TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Rebin_Plots_Helene_You_V4L_V5L_NL/Rebin_V532_NL_Helene.root","READ");


    TH1D* Rebin_hV532_Gap00A = (TH1D*)fileOutput->Get("Rebin_hV532_Gap00A");
    TH1D* Rebin_hV532_Gap01A = (TH1D*)fileOutput->Get("Rebin_hV532_Gap01A");
    TH1D* Rebin_hV532_Gap02A = (TH1D*)fileOutput->Get("Rebin_hV532_Gap02A");
    TH1D* Rebin_hV532_Gap03A = (TH1D*)fileOutput->Get("Rebin_hV532_Gap03A");
    TH1D* Rebin_hV532_Gap04A = (TH1D*)fileOutput->Get("Rebin_hV532_Gap04A");
    TH1D* Rebin_hV532_Gap05A = (TH1D*)fileOutput->Get("Rebin_hV532_Gap05A");
    TH1D* Rebin_hV532_Gap06A = (TH1D*)fileOutput->Get("Rebin_hV532_Gap06A");
    TH1D* Rebin_hV532_Gap07A = (TH1D*)fileOutput->Get("Rebin_hV532_Gap07A");
    TH1D* Rebin_hV532_Gap08A = (TH1D*)fileOutput->Get("Rebin_hV532_Gap08A");



    Rebin_hV532_Gap00A->SetMarkerStyle(kFullCircle); 
    Rebin_hV532_Gap00A->SetMarkerColor(kBlue+1);
    Rebin_hV532_Gap00A->SetStats(0);
    Rebin_hV532_Gap00A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV532_Gap00A->Draw("P");
    Rebin_hV532_Gap00A->GetYaxis()->SetRangeUser(-0.002, 0.05);
    Rebin_hV532_Gap00A->GetYaxis()->SetTitleOffset(1.5);
    //Rebin_hV532_Gap00A->GetYaxis()->SetTitleSize(0.1);
    //Rebin_hV532_Gap00A->GetYaxis()->CenterTitle(true);
    Rebin_hV532_Gap00A->GetYaxis()->SetTitle("v_{5,32}");
    Rebin_hV532_Gap00A->GetXaxis()->SetTitle("N_{trks}");
    Rebin_hV532_Gap00A->GetXaxis()->SetTitleOffset(1.4);
    //Rebin_hV532_Gap00A->GetXaxis()->CenterTitle(true);
    //gStyle->SetTitleFontSize(0.2);
    Rebin_hV532_Gap00A->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    //Rebin_hV532_Gap00A->SetFillColor(kRed-9);
    

    Rebin_hV532_Gap01A->SetMarkerStyle(kFullTriangleUp); 
    Rebin_hV532_Gap01A->SetMarkerColor(kRed+1);
    Rebin_hV532_Gap01A->SetLineColor(kRed+1);
    Rebin_hV532_Gap01A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV532_Gap01A->Draw("same");

    Rebin_hV532_Gap02A->SetMarkerStyle(kCircle); 
    Rebin_hV532_Gap02A->SetMarkerColor(kSpring);
    Rebin_hV532_Gap02A->SetLineColor(kSpring+1);
    Rebin_hV532_Gap02A->SetStats(0);
    Rebin_hV532_Gap01A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV532_Gap02A->Draw("same");

    Rebin_hV532_Gap03A->SetMarkerStyle(kOpenSquare); 
    Rebin_hV532_Gap03A->SetMarkerColor(kGreen+3);
    Rebin_hV532_Gap03A->SetLineColor(kGreen+3);
    Rebin_hV532_Gap03A->SetStats(0);
    Rebin_hV532_Gap03A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV532_Gap03A->Draw("same");

    Rebin_hV532_Gap04A->SetMarkerStyle(kOpenDiamond); 
    Rebin_hV532_Gap04A->SetMarkerColor(kBlack);
    Rebin_hV532_Gap04A->SetLineColor(kBlack);
    Rebin_hV532_Gap04A->SetStats(0);
    Rebin_hV532_Gap04A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV532_Gap04A->Draw("same");

    Rebin_hV532_Gap05A->SetMarkerStyle(kFullStar); 
    Rebin_hV532_Gap05A->SetMarkerColor(kOrange);
    Rebin_hV532_Gap05A->SetLineColor(kOrange);
    Rebin_hV532_Gap05A->SetMarkerSize(2);
    Rebin_hV532_Gap05A->SetStats(0);
    Rebin_hV532_Gap05A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV532_Gap05A->Draw("same");

    Rebin_hV532_Gap06A->SetMarkerStyle(kFullCross); 
    Rebin_hV532_Gap06A->SetMarkerColor(kBlue-9);
    Rebin_hV532_Gap06A->SetMarkerSize(2);
    Rebin_hV532_Gap06A->SetStats(0);
    Rebin_hV532_Gap06A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV532_Gap06A->Draw("same");

    Rebin_hV532_Gap07A->SetMarkerStyle(kFullDiamond); 
    Rebin_hV532_Gap07A->SetMarkerColor(kTeal-2);
    Rebin_hV532_Gap07A->SetMarkerSize(2);
    Rebin_hV532_Gap07A->SetStats(0);
    Rebin_hV532_Gap07A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV532_Gap07A->Draw("same");

    Rebin_hV532_Gap08A->SetMarkerStyle(kFullCircle); 
    Rebin_hV532_Gap08A->SetMarkerColor(kMagenta);
    //Rebin_hV532_Gap08A->SetMarkerSize(1);
    Rebin_hV532_Gap08A->SetStats(0);
    Rebin_hV532_Gap08A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV532_Gap08A->Draw("same");


    c->BuildLegend();
    Rebin_hV532_Gap00A->SetTitle(0);
    
    
    TLatex latex;
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,0.038,"ALICE");
    
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,0.035,"#sqrt{s_{NN}} = 5.02 TeV");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(25,0.032,"|#Delta #eta| < 0.8");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(25,0.029," 0.2 < p_{T} < 3.0");

    c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_NonLinear_V532/v532_NonLinear_10bin_Length.png");

}