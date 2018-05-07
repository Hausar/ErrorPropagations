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

void Plot_Chi422_Chi532() 
{    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //..Open the Root.file:

     TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Rebin_Plots_Helene_You_Chi_422_532/Rebin_Chi_422_532_Helene_10Length.root","READ");


    TH1D* Rebin_Chi_V422_Gap00A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap00A");
    TH1D* Rebin_Chi_V422_Gap01A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap01A");
    TH1D* Rebin_Chi_V422_Gap02A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap02A");
    TH1D* Rebin_Chi_V422_Gap03A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap03A");
    TH1D* Rebin_Chi_V422_Gap04A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap04A");
    TH1D* Rebin_Chi_V422_Gap05A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap05A");
    TH1D* Rebin_Chi_V422_Gap06A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap06A");
    TH1D* Rebin_Chi_V422_Gap07A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap07A");
    TH1D* Rebin_Chi_V422_Gap08A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap08A");


    Rebin_Chi_V422_Gap00A->SetMarkerStyle(kFullCircle); 
    Rebin_Chi_V422_Gap00A->SetMarkerColor(kBlue+1);
    Rebin_Chi_V422_Gap00A->SetStats(0);
    Rebin_Chi_V422_Gap00A->GetXaxis()->SetRangeUser(20, 80);
    Rebin_Chi_V422_Gap00A->Draw("P");
    Rebin_Chi_V422_Gap00A->GetYaxis()->SetRangeUser(-1, 5);
    Rebin_Chi_V422_Gap00A->GetYaxis()->SetTitleOffset(1.3);
    //Rebin_Chi_V422_Gap00A->GetYaxis()->SetTitleSize(0.1);
    //Rebin_Chi_V422_Gap00A->GetYaxis()->CenterTitle(true);
    Rebin_Chi_V422_Gap00A->GetYaxis()->SetTitle("#chi_{4,22}");
    Rebin_Chi_V422_Gap00A->GetXaxis()->SetTitle("N_{trks}");
    Rebin_Chi_V422_Gap00A->GetXaxis()->SetTitleOffset(1.4);
    Rebin_Chi_V422_Gap00A->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    Rebin_Chi_V422_Gap00A->SetTitle("|#Delta #eta |> 0.0 A");
    //Rebin_Chi_V422_Gap00A->GetXaxis()->CenterTitle(true);
    //gStyle->SetTitleFontSize(0.2);
    //Rebin_Chi_V422_Gap00A->SetFillColor(kRed-9);

    Rebin_Chi_V422_Gap01A->SetMarkerStyle(kFullTriangleUp); 
    Rebin_Chi_V422_Gap01A->SetMarkerColor(kRed+1);
    Rebin_Chi_V422_Gap01A->SetLineColor(kRed+1);
    Rebin_Chi_V422_Gap01A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Chi_V422_Gap01A->SetTitle("|#Delta #eta |> 0.1 A");
    Rebin_Chi_V422_Gap01A->Draw("same");

    Rebin_Chi_V422_Gap02A->SetMarkerStyle(kCircle); 
    Rebin_Chi_V422_Gap02A->SetMarkerColor(kSpring);
    Rebin_Chi_V422_Gap02A->SetLineColor(kSpring+1);
    Rebin_Chi_V422_Gap02A->SetStats(0);
    Rebin_Chi_V422_Gap01A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Chi_V422_Gap02A->SetTitle("|#Delta #eta |> 0.2 A");
    Rebin_Chi_V422_Gap02A->Draw("same");

    Rebin_Chi_V422_Gap03A->SetMarkerStyle(kOpenSquare); 
    Rebin_Chi_V422_Gap03A->SetMarkerColor(kGreen+3);
    Rebin_Chi_V422_Gap03A->SetLineColor(kGreen+3);
    Rebin_Chi_V422_Gap03A->SetStats(0);
    Rebin_Chi_V422_Gap03A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Chi_V422_Gap03A->SetTitle("|#Delta #eta |> 0.3 A");
    Rebin_Chi_V422_Gap03A->Draw("same");

    Rebin_Chi_V422_Gap04A->SetMarkerStyle(kOpenDiamond); 
    Rebin_Chi_V422_Gap04A->SetMarkerColor(kBlack);
    Rebin_Chi_V422_Gap04A->SetLineColor(kBlack);
    Rebin_Chi_V422_Gap04A->SetMarkerSize(2);
    Rebin_Chi_V422_Gap04A->SetStats(0);
    Rebin_Chi_V422_Gap04A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Chi_V422_Gap04A->SetTitle("|#Delta #eta |> 0.4 A");
    Rebin_Chi_V422_Gap04A->Draw("same");

    Rebin_Chi_V422_Gap05A->SetMarkerStyle(kFullStar); 
    Rebin_Chi_V422_Gap05A->SetMarkerColor(kOrange);
    Rebin_Chi_V422_Gap05A->SetLineColor(kOrange);
    Rebin_Chi_V422_Gap05A->SetMarkerSize(2);
    Rebin_Chi_V422_Gap05A->SetStats(0);
    Rebin_Chi_V422_Gap05A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Chi_V422_Gap05A->SetTitle("|#Delta #eta |> 0.5 A");
    Rebin_Chi_V422_Gap05A->Draw("same");

    Rebin_Chi_V422_Gap06A->SetMarkerStyle(kFullCross); 
    Rebin_Chi_V422_Gap06A->SetMarkerColor(kBlue-9);
    Rebin_Chi_V422_Gap06A->SetMarkerSize(2);
    Rebin_Chi_V422_Gap06A->SetStats(0);
    Rebin_Chi_V422_Gap06A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Chi_V422_Gap06A->SetTitle("|#Delta #eta |> 0.6 A");
    Rebin_Chi_V422_Gap06A->Draw("same");

    Rebin_Chi_V422_Gap07A->SetMarkerStyle(kFullDiamond); 
    Rebin_Chi_V422_Gap07A->SetMarkerColor(kTeal-2);
    Rebin_Chi_V422_Gap07A->SetMarkerSize(2);
    Rebin_Chi_V422_Gap07A->SetStats(0);
    Rebin_Chi_V422_Gap07A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Chi_V422_Gap07A->SetTitle("|#Delta #eta |> 0.7 A");
    Rebin_Chi_V422_Gap07A->Draw("same");

    Rebin_Chi_V422_Gap08A->SetMarkerStyle(kFullCircle); 
    Rebin_Chi_V422_Gap08A->SetMarkerColor(kMagenta);
    //Rebin_Chi_V422_Gap08A->SetMarkerSize(1);
    Rebin_Chi_V422_Gap08A->SetStats(0);
    Rebin_Chi_V422_Gap08A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Chi_V422_Gap08A->SetTitle("|#Delta #eta |> 0.8 A");
    Rebin_Chi_V422_Gap08A->Draw("same");
    
    // //..Draw a Constant line at y=1
    // gPad->Modified(); 
    // gPad->Update(); // make sure gPad is updated 
    // TLine *line = new TLine(gPad->GetUxmin(), 1, gPad->GetUxmax(), 1);
    // line->SetLineStyle(9);
    // line->SetLineWidth(2); 
    // line->SetLineColor(kBlack);
    // line->Draw(); 

    c->BuildLegend();
    Rebin_Chi_V422_Gap00A->SetTitle(0); 
    
    TLatex latex;
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,4.8,"ALICE");

    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,4.5,"p+Pb collisions");
    
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,4.2,"#sqrt{s_{NN}} = 5.02 TeV");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(25,3.9,"|#Delta #eta| < 0.8");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(25,3.6," 0.2 < p_{T} < 3.0 GeV/c");

    c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_NL_Coefficient_Chi422_Chi532/Chi422_10Length_Smallrange_2.png");

}