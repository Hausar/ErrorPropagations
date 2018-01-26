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

void Plot_Macro() 
{    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //..Open the Root.file:

    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/Rebin_V4_AllGaps/Rebin_V4_Linear_NL_histograms.root","READ");

    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/Rebin_V5_AllGaps/Rebin_V5_Linear_NL_histograms.root","READ");

    // TH1D* hC22 = (TH1D*)file->Get("hC22");
    // if(!hC22) return;
    //hC22->Draw();



// ..Plot the results:
    //..v_{4,22}
    //hC22_Rebin->GetYaxis()->SetRangeUser(0., 4.);
    //hC22_Rebin->GetXaxis()->SetRangeUser(0., 140);
    // hC22_Rebin->SetMarkerSize(1.);
    // hC22_Rebin->Draw("same");
    // hC22_Rebin->SetTitle("Non-Linear Response v_{4,22} for pPb at #sqrt{s_{NN}} = 5.02 TeV");
    // hC22_Rebin->SetMarkerStyle(kFullTriangleUp); 
    // hC22_Rebin->SetMarkerColor(kRed+1);
    // hC22_Rebin->GetYaxis()->SetTitleOffset(1.4);
    // //hC22_Rebin->GetYaxis()->CenterTitle(true);
    // hC22_Rebin->GetYaxis()->SetTitle("v_{4,22}");

    // hC22_Rebin->GetXaxis()->SetTitleOffset(1.4);
    // //hC22_Rebin->GetXaxis()->CenterTitle(true);
    // gStyle->SetTitleFontSize(0.2);
    // hC22_Rebin->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    // hC22_Rebin->SetFillColor(kRed-9);
    // c->Update();
    
    // TLatex latex;
    // latex.SetTextSize(0.035);
    // latex.SetTextAlign(13);  //align at top
    // latex.DrawLatex(10,3.5,"#sqrt{s_{NN}} = 5.02 TeV");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(10,3.3,"|#Delta #eta| < 0.8");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(10,3.1," 0.2 < p_{T} < 3.0");

    // TLegend *leg = new TLegend(0.4, 0.5, 0.55, 0.55); 
    // leg->AddEntry(hC22_Rebin, "v_{4,22}", "fp");
    // leg->Draw("same");

    // leg->SetBorderSize(0);
    // gStyle->SetTitleFontSize(0.2);
    //**************************************************************************        
    // hCLinear_Rebin->SetMarkerStyle(21);
    // hCLinear_Rebin->SetMarkerColorAlpha(kBlack, 4.5);
    // hCLinear_Rebin->SetXTitle("# of tracks");
    // hCLinear_Rebin->SetYTitle("v_{4}^{L}");
    // hCLinear_Rebin->SetMarkerSize(1.);
    // hCLinear_Rebin->Draw();
    // c->BuildLegend();



    // TLegend *leg = new TLegend(0.4, 0.5, 0.55, 0.55); 
    // leg->AddEntry(hChi422_Rebin, "v_{4,22}", "fp");
    // leg->Draw("same");

    // hCLinear_Rebin->SetMarkerStyle(21);
    // hCLinear_Rebin->SetMarkerColorAlpha(kTeal, 4.5);
    // hCLinear_Rebin->SetXTitle("# of tracks");
    // hCLinear_Rebin->SetYTitle("v_{5}^{L}");
    // hCLinear_Rebin->SetMarkerSize(2.);
    // hCLinear_Rebin->Draw();
    // c->BuildLegend();

    // hCV422_Rebin->SetMarkerStyle(34);
    // hCV422_Rebin->SetMarkerColorAlpha(kBlue, 0.45);
    // hCV422_Rebin->SetXTitle("# of tracks");
    // hCV422_Rebin->SetYTitle("v_{4,22}");
    // hCV422_Rebin->SetMarkerSize(2.);
	// hCV422_Rebin->Draw("same");
    // c->BuildLegend();

    // hCV532_Rebin->SetMarkerStyle(34);
    // hCV532_Rebin->SetMarkerColorAlpha(kGreen, 0.45);
    // hCV532_Rebin->SetXTitle("# of tracks");
    // hCV532_Rebin->SetYTitle("v_{5,32}");
    // hCV532_Rebin->SetMarkerSize(2.);
	// hCV532_Rebin->Draw("same");
    // c->BuildLegend();

    // hC22_Rebin->SetMarkerStyle(22);
    // hC22_Rebin->SetMarkerColorAlpha(kViolet, 4.5);
    // hC22_Rebin->SetMarkerSize(2.);
    // hC22_Rebin->SetXTitle("# of tracks");
    // hC22_Rebin->SetYTitle("v_{5}");
    // gStyle->SetOptStat(0);
    // hC22_Rebin->Draw("same");
    // c->BuildLegend();

//     //**************************************************************************
//     //..Plot Chi422: 
//     hChi422_Rebin->GetYaxis()->SetRangeUser(0., 4.);
//     hChi422_Rebin->GetXaxis()->SetRangeUser(0., 140);
//     hChi422_Rebin->SetMarkerSize(1.);
//     hChi422_Rebin->Draw("same");
//     hChi422_Rebin->SetTitle("Non-Linear coefficient #chi_{4,22} of v_{4,22} for pPb at 5.02 TeV");
//     hChi422_Rebin->SetMarkerStyle(kFullTriangleUp); 
//     hChi422_Rebin->SetMarkerColor(kRed+1);
//     hChi422_Rebin->GetYaxis()->SetTitleOffset(1.4);
//     //hChi422_Rebin->GetYaxis()->CenterTitle(true);
//     hChi422_Rebin->GetYaxis()->SetTitle("#chi_{4,22}");

//     hChi422_Rebin->GetXaxis()->SetTitleOffset(1.4);
//     //hChi422_Rebin->GetXaxis()->CenterTitle(true);
//     gStyle->SetTitleFontSize(0.2);
//     hChi422_Rebin->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
//     hChi422_Rebin->SetFillColor(kRed-9);
//     c->Update();
    
    // TLatex latex;
    // latex.SetTextSize(0.035);
    // latex.SetTextAlign(13);  //align at top
    // latex.DrawLatex(10,3.5,"#sqrt{s_{NN}} = 5.02 TeV");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(10,3.3,"|#Delta #eta| < 0.8");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(10,3.1," 0.2 < p_{T} < 3.0");

    // TLegend *leg = new TLegend(0.4, 0.5, 0.55, 0.55); 
    // leg->AddEntry(hChi422_Rebin, "#chi_{4,22}", "fp");
    // leg->Draw("same");

    // leg->SetBorderSize(0);
    // gStyle->SetTitleFontSize(0.2);

//     //************************************************
//     //..Plot Chi532
//     hChi532_Rebin->GetYaxis()->SetRangeUser(0., 10.);
//     hChi532_Rebin->GetXaxis()->SetRangeUser(0., 140);
//     hChi532_Rebin->SetMarkerSize(1.);
//     hChi532_Rebin->Draw("same");
//     hChi532_Rebin->SetTitle("Non-Linear coefficient #chi_{5,32} of v_{5,32} for pPb at 5.02 TeV");
//     hChi532_Rebin->SetMarkerStyle(kFullTriangleUp); 
//     hChi532_Rebin->SetMarkerColor(kBlue+1);
//     hChi532_Rebin->GetYaxis()->SetTitleOffset(1.4);
//     //hChi532_Rebin->GetYaxis()->CenterTitle(true);
//     hChi532_Rebin->GetYaxis()->SetTitle("#chi_{5,32}");

//     hChi532_Rebin->GetXaxis()->SetTitleOffset(1.4);
//     //hChi532_Rebin->GetXaxis()->CenterTitle(true);
//     gStyle->SetTitleFontSize(0.2);
//     hChi532_Rebin->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
//     hChi532_Rebin->SetFillColor(kBlue-9);
//     c->Update();
    
//     TLatex latex;
//     latex.SetTextSize(0.035);
//     latex.SetTextAlign(13);  //align at top
//     latex.DrawLatex(10,3.5,"#sqrt{s_{NN}} = 5.02 TeV");

//     latex.SetTextAlign(13);  //centered
//     latex.DrawLatex(10,3.3,"|#Delta #eta| < 0.8");

//     latex.SetTextAlign(13);  //centered
//     latex.DrawLatex(10,3.1," 0.2 < p_{T} < 3.0");

//     TLegend *leg = new TLegend(0.4, 0.5, 0.55, 0.55); 
//     leg->AddEntry(hChi532_Rebin, "#chi_{5,32}", "fp");
//     leg->Draw("same");
    
//     leg->SetBorderSize(0);
//     gStyle->SetTitleFontSize(0.2);