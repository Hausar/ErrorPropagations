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

void Plot_Rho422_Rho532() 
{    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //..Open the Root.file:

     TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Rebin_Plots_Helene_You_Rho422_Rho532/Rebin_RhoV422_Helene.root","READ");


    TH1D* Rebin_Rho_V532_Gap00A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap00");
    TH1D* Rebin_Rho_V532_Gap01A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap01");
    TH1D* Rebin_Rho_V532_Gap02A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap02");
    TH1D* Rebin_Rho_V532_Gap03A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap03");
    TH1D* Rebin_Rho_V532_Gap04A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap04");
    TH1D* Rebin_Rho_V532_Gap05A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap05");
    TH1D* Rebin_Rho_V532_Gap06A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap06");
    TH1D* Rebin_Rho_V532_Gap07A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap07");
    TH1D* Rebin_Rho_V532_Gap08A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap08");



    Rebin_Rho_V532_Gap00A->SetMarkerStyle(kFullCircle); 
    Rebin_Rho_V532_Gap00A->SetMarkerColor(kBlue+1);
    Rebin_Rho_V532_Gap00A->SetStats(0);
    Rebin_Rho_V532_Gap00A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_V532_Gap00A->Draw("P");
    Rebin_Rho_V532_Gap00A->GetYaxis()->SetRangeUser(-0.01, 3.);
    Rebin_Rho_V532_Gap00A->GetYaxis()->SetTitleOffset(1.5);
    //Rebin_Rho_V532_Gap00A->GetYaxis()->SetTitleSize(0.1);
    //Rebin_Rho_V532_Gap00A->GetYaxis()->CenterTitle(true);
    Rebin_Rho_V532_Gap00A->GetYaxis()->SetTitle("#rho_{5,32}");
    Rebin_Rho_V532_Gap00A->GetXaxis()->SetTitle("N_{trks}");
    Rebin_Rho_V532_Gap00A->GetXaxis()->SetTitleOffset(1.4);
    Rebin_Rho_V532_Gap00A->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    Rebin_Rho_V532_Gap00A->SetTitle("|#Delta #eta |> 0.0 A");
    //Rebin_Rho_V532_Gap00A->GetXaxis()->CenterTitle(true);
    //gStyle->SetTitleFontSize(0.2);
    //Rebin_Rho_V532_Gap00A->SetFillColor(kRed-9);

    Rebin_Rho_V532_Gap01A->SetMarkerStyle(kFullTriangleUp); 
    Rebin_Rho_V532_Gap01A->SetMarkerColor(kRed+1);
    Rebin_Rho_V532_Gap01A->SetLineColor(kRed+1);
    Rebin_Rho_V532_Gap01A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_V532_Gap01A->SetTitle("|#Delta #eta |> 0.1 A");
    Rebin_Rho_V532_Gap01A->Draw("same");

    Rebin_Rho_V532_Gap02A->SetMarkerStyle(kCircle); 
    Rebin_Rho_V532_Gap02A->SetMarkerColor(kSpring);
    Rebin_Rho_V532_Gap02A->SetLineColor(kSpring+1);
    Rebin_Rho_V532_Gap02A->SetStats(0);
    Rebin_Rho_V532_Gap01A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_V532_Gap02A->SetTitle("|#Delta #eta |> 0.2 A");
    Rebin_Rho_V532_Gap02A->Draw("same");

    Rebin_Rho_V532_Gap03A->SetMarkerStyle(kOpenSquare); 
    Rebin_Rho_V532_Gap03A->SetMarkerColor(kGreen+3);
    Rebin_Rho_V532_Gap03A->SetLineColor(kGreen+3);
    Rebin_Rho_V532_Gap03A->SetStats(0);
    Rebin_Rho_V532_Gap03A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_V532_Gap03A->SetTitle("|#Delta #eta |> 0.3 A");
    Rebin_Rho_V532_Gap03A->Draw("same");

    Rebin_Rho_V532_Gap04A->SetMarkerStyle(kOpenDiamond); 
    Rebin_Rho_V532_Gap04A->SetMarkerColor(kBlack);
    Rebin_Rho_V532_Gap04A->SetLineColor(kBlack);
    Rebin_Rho_V532_Gap04A->SetMarkerSize(2);
    Rebin_Rho_V532_Gap04A->SetStats(0);
    Rebin_Rho_V532_Gap04A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_V532_Gap04A->SetTitle("|#Delta #eta |> 0.4 A");
    Rebin_Rho_V532_Gap04A->Draw("same");

    Rebin_Rho_V532_Gap05A->SetMarkerStyle(kFullStar); 
    Rebin_Rho_V532_Gap05A->SetMarkerColor(kOrange);
    Rebin_Rho_V532_Gap05A->SetLineColor(kOrange);
    Rebin_Rho_V532_Gap05A->SetMarkerSize(2);
    Rebin_Rho_V532_Gap05A->SetStats(0);
    Rebin_Rho_V532_Gap05A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_V532_Gap05A->SetTitle("|#Delta #eta |> 0.5 A");
    Rebin_Rho_V532_Gap05A->Draw("same");

    Rebin_Rho_V532_Gap06A->SetMarkerStyle(kFullCross); 
    Rebin_Rho_V532_Gap06A->SetMarkerColor(kBlue-9);
    Rebin_Rho_V532_Gap06A->SetMarkerSize(2);
    Rebin_Rho_V532_Gap06A->SetStats(0);
    Rebin_Rho_V532_Gap06A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_V532_Gap06A->SetTitle("|#Delta #eta |> 0.6 A");
    Rebin_Rho_V532_Gap06A->Draw("same");

    Rebin_Rho_V532_Gap07A->SetMarkerStyle(kFullDiamond); 
    Rebin_Rho_V532_Gap07A->SetMarkerColor(kTeal-2);
    Rebin_Rho_V532_Gap07A->SetMarkerSize(2);
    Rebin_Rho_V532_Gap07A->SetStats(0);
    Rebin_Rho_V532_Gap07A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_V532_Gap07A->SetTitle("|#Delta #eta |> 0.7 A");
    Rebin_Rho_V532_Gap07A->Draw("same");

    Rebin_Rho_V532_Gap08A->SetMarkerStyle(kFullCircle); 
    Rebin_Rho_V532_Gap08A->SetMarkerColor(kMagenta);
    //Rebin_Rho_V532_Gap08A->SetMarkerSize(1);
    Rebin_Rho_V532_Gap08A->SetStats(0);
    Rebin_Rho_V532_Gap08A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_V532_Gap08A->SetTitle("|#Delta #eta |> 0.8 A");
    Rebin_Rho_V532_Gap08A->Draw("same");
    
    //..Draw a Constant line at y=1
    gPad->Modified(); 
    gPad->Update(); // make sure gPad is updated 
    TLine *line = new TLine(gPad->GetUxmin(), 1, gPad->GetUxmax(), 1);
    line->SetLineStyle(9);
    line->SetLineWidth(2); 
    line->SetLineColor(kBlack);
    line->Draw(); 

    c->BuildLegend();
    Rebin_Rho_V532_Gap00A->SetTitle(0); 
    
    TLatex latex;
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,2.8,"ALICE");

    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,2.6,"p+Pb collisions");
    
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,2.4,"#sqrt{s_{NN}} = 5.02 TeV");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(25,2.2,"|#Delta #eta| < 0.8");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(25,2.," 0.2 < p_{T} < 3.0 GeV/c");

    c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_SymmetryPlanes_Rho422_Rho532/Rho532.png");

}ª