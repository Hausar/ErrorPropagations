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

    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_Rebin_NewCondition_V4/Rebin_V4_Linear_NL_histograms_NewCondition.root","READ");

    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_Rebin_NewCondition_V5/Rebin_V5_Linear_NL_histograms_NewCondition.root","READ");

    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Rebin_NewCondition_Chi422_Chi532_AllGaps/Rebin_NewCondition_Chi422_Chi532_histograms.root","READ");

    TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/Rebin_NewConditions_Rho_v422_v532/Rebin_NewCondition_Rho_v422_v532_histograms.root","READ");

    // TH1D* hC22 = (TH1D*)file->Get("hC22");
    // if(!hC22) return;
    //hC22->Draw();



// ..Plot the results:
    // //..v_{4,22}
    // //hC22_Rebin_Gap00->GetYaxis()->SetRangeUser(0., 0.08);
    // //hC22_Rebin_Gap00->GetXaxis()->SetRangeUser(0., 140);
    // hC22_Rebin_Gap02->SetMarkerSize(1.);
    // hC22_Rebin_Gap02->Draw("same");
    // hC22_Rebin_Gap02->SetTitle("Non-Linear Response v_{4,22} for pPb at #sqrt{s_{NN}} = 5.02 TeV");
    // hC22_Rebin_Gap02->SetMarkerStyle(kFullTriangleUp); 
    // hC22_Rebin_Gap02->SetMarkerColor(kRed+1);
    // hC22_Rebin_Gap02->GetYaxis()->SetTitleOffset(1.4);
    // //hC22_Rebin_Gap00->GetYaxis()->CenterTitle(true);
    // hC22_Rebin_Gap02->GetYaxis()->SetTitle("v_{4,22}");

    // hC22_Rebin_Gap02->GetXaxis()->SetTitleOffset(1.4);
    // //hC22_Rebin_Gap00->GetXaxis()->CenterTitle(true);
    // gStyle->SetTitleFontSize(0.2);
    // hC22_Rebin_Gap02->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    // hC22_Rebin_Gap02->SetFillColor(kRed-9);
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
    // leg->AddEntry(hC22_Rebin_Gap02, "v_{4,22}", "fp");
    // leg->Draw("same");
    //c->SaveAs("/Users/Helena/Desktop/Plots/New_plots/v422_NL_plot02.png");

    // leg->SetBorderSize(0);
    // gStyle->SetTitleFontSize(0.2);
    //************************************************************************** 

    //..v_{4,22}
    //hC22_Rebin_Gap00->GetYaxis()->SetRangeUser(0., 0.08);
    //hC22_Rebin_Gap00->GetXaxis()->SetRangeUser(0., 140);
    // hC25_Rebin_Gap08->SetMarkerSize(1.);
    // hC25_Rebin_Gap08->Draw("same");
    // hC25_Rebin_Gap08->SetTitle("Non-Linear Response v_{5,32} for pPb at #sqrt{s_{NN}} = 5.02 TeV");
    // hC25_Rebin_Gap08->SetMarkerStyle(kFullTriangleUp); 
    // hC25_Rebin_Gap08->SetMarkerColor(kBlue+1);
    // hC25_Rebin_Gap08->GetYaxis()->SetTitleOffset(1.4);
    // //hC25_Rebin_Gap00->GetYaxis()->CenterTitle(true);
    // hC25_Rebin_Gap08->GetYaxis()->SetTitle("v_{5,32}");

    // hC25_Rebin_Gap08->GetXaxis()->SetTitleOffset(1.4);
    // //hC25_Rebin_Gap00->GetXaxis()->CenterTitle(true);
    // gStyle->SetTitleFontSize(0.2);
    // hC25_Rebin_Gap08->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    // hC25_Rebin_Gap08->SetFillColor(kRed-9);
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
    // leg->AddEntry(hC25_Rebin_Gap08, "v_{5,32}", "fp");
    // leg->Draw("same");


//     //**************************************************************************
//     //..Plot Chi422: 
    // hChi422_Rebin_Gap04->GetYaxis()->SetRangeUser(0., 4.);
    // hChi422_Rebin_Gap04->GetXaxis()->SetRangeUser(0., 140);
    // hChi422_Rebin_Gap04->SetMarkerSize(1.);
    // hChi422_Rebin_Gap04->Draw("same");
    // hChi422_Rebin_Gap04->SetTitle("Non-Linear coefficient #chi_{4,22} of v_{4,22} for pPb at 5.02 TeV");
    // hChi422_Rebin_Gap04->SetMarkerStyle(kFullTriangleUp); 
    // hChi422_Rebin_Gap04->SetMarkerColor(kRed+1);
    // hChi422_Rebin_Gap04->GetYaxis()->SetTitleOffset(1.4);
    // //hChi422_Rebin_Gap04->GetYaxis()->CenterTitle(true);
    // hChi422_Rebin_Gap04->GetYaxis()->SetTitle("#chi_{4,22}");

    // hChi422_Rebin_Gap04->GetXaxis()->SetTitleOffset(1.4);
    // //hChi422_Rebin_Gap04->GetXaxis()->CenterTitle(true);
    // gStyle->SetTitleFontSize(0.2);
    // hChi422_Rebin_Gap04->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    // hChi422_Rebin_Gap04->SetFillColor(kRed-9);
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
    // leg->AddEntry(hChi422_Rebin_Gap04, "#chi_{4,22}", "fp");
    // leg->Draw("same");

    // leg->SetBorderSize(0);
    // gStyle->SetTitleFontSize(0.2);

//     //************************************************
//     //..Plot Chi532
    // hChi532_Rebin_Gap08->GetYaxis()->SetRangeUser(0., 20.);
    // hChi532_Rebin_Gap08->GetXaxis()->SetRangeUser(0., 140);
    // hChi532_Rebin_Gap08->SetMarkerSize(1.);
    // hChi532_Rebin_Gap08->Draw("same");
    // hChi532_Rebin_Gap08->SetTitle("Non-Linear coefficient #chi_{5,32} of v_{5,32} for pPb at 5.02 TeV");
    // hChi532_Rebin_Gap08->SetMarkerStyle(kFullTriangleUp); 
    // hChi532_Rebin_Gap08->SetMarkerColor(kBlue+1);
    // hChi532_Rebin_Gap08->GetYaxis()->SetTitleOffset(1.4);
    // //hChi532_Rebin_Gap08->GetYaxis()->CenterTitle(true);
    // hChi532_Rebin_Gap08->GetYaxis()->SetTitle("#chi_{5,32}");

    // hChi532_Rebin_Gap08->GetXaxis()->SetTitleOffset(1.4);
    // //hChi532_Rebin_Gap08->GetXaxis()->CenterTitle(true);
    // gStyle->SetTitleFontSize(0.2);
    // hChi532_Rebin_Gap08->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    // hChi532_Rebin_Gap08->SetFillColor(kBlue-9);
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
    // leg->AddEntry(hChi532_Rebin_Gap08, "#chi_{5,32}", "fp");
    // leg->Draw("same");
    
    // leg->SetBorderSize(0);
    // gStyle->SetTitleFontSize(0.2);

    //......rho
    // ////..Plot Chi422: 
    // hRho_V422_Rebin_Gap08->GetYaxis()->SetRangeUser(0., 4.);
    // hRho_V422_Rebin_Gap08->GetXaxis()->SetRangeUser(0., 140);
    // hRho_V422_Rebin_Gap08->SetMarkerSize(1.);
    // hRho_V422_Rebin_Gap08->Draw("same");
    // hRho_V422_Rebin_Gap08->SetTitle("Symmetry plane correlations #rho_{4,22} for pPb at 5.02 TeV");
    // hRho_V422_Rebin_Gap08->SetMarkerStyle(kFullTriangleUp); 
    // hRho_V422_Rebin_Gap08->SetMarkerColor(kRed+1);
    // hRho_V422_Rebin_Gap08->GetYaxis()->SetTitleOffset(1.4);
    // //hRho_V422_Rebin_Gap08->GetYaxis()->CenterTitle(true);
    // hRho_V422_Rebin_Gap08->GetYaxis()->SetTitle("#rho_{4,22}");

    // hRho_V422_Rebin_Gap08->GetXaxis()->SetTitleOffset(1.4);
    // //hRho_V422_Rebin_Gap08->GetXaxis()->CenterTitle(true);
    // gStyle->SetTitleFontSize(0.2);
    // hRho_V422_Rebin_Gap08->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    // hRho_V422_Rebin_Gap08->SetFillColor(kRed-9);
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
    // leg->AddEntry(hRho_V422_Rebin_Gap08, "#rho_{4,22}", "fp");
    // leg->Draw("same");

    // leg->SetBorderSize(0);
    // gStyle->SetTitleFontSize(0.2);

    // ////..Plot Chi422: 
    hRho_V532_Rebin_Gap04->GetYaxis()->SetRangeUser(0., 6.);
    hRho_V532_Rebin_Gap04->GetXaxis()->SetRangeUser(0., 140);
    hRho_V532_Rebin_Gap04->SetMarkerSize(1.);
    hRho_V532_Rebin_Gap04->Draw("same");
    hRho_V532_Rebin_Gap04->SetTitle("Symmetry plane correlations #rho_{5,32} for pPb at 5.02 TeV");
    hRho_V532_Rebin_Gap04->SetMarkerStyle(kFullTriangleUp); 
    hRho_V532_Rebin_Gap04->SetMarkerColor(kRed+1);
    hRho_V532_Rebin_Gap04->GetYaxis()->SetTitleOffset(1.4);
    //hRho_V532_Rebin_Gap04->GetYaxis()->CenterTitle(true);
    hRho_V532_Rebin_Gap04->GetYaxis()->SetTitle("#rho_{5,32}");

    hRho_V532_Rebin_Gap04->GetXaxis()->SetTitleOffset(1.4);
    //hRho_V532_Rebin_Gap04->GetXaxis()->CenterTitle(true);
    gStyle->SetTitleFontSize(0.2);
    hRho_V532_Rebin_Gap04->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    hRho_V532_Rebin_Gap04->SetFillColor(kRed-9);
    c->Update();
    
    TLatex latex;
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(10,3.5,"#sqrt{s_{NN}} = 5.02 TeV");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(10,3.3,"|#Delta #eta| < 0.8");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(10,3.1," 0.2 < p_{T} < 3.0");

    TLegend *leg = new TLegend(0.4, 0.5, 0.55, 0.55); 
    leg->AddEntry(hRho_V532_Rebin_Gap04, "#rho_{5,32}", "fp");
    leg->Draw("same");

    leg->SetBorderSize(0);
    gStyle->SetTitleFontSize(0.2);
}