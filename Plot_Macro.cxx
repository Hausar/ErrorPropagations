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

    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/Rebin_V4_AllGaps_CutData/Rebin_V4_Linear_NL_histograms_CutData.root","READ");

    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/Rebin_V5_AllGaps_CutData/Rebin_V5_Linear_NL_histograms_CutData.root","READ");

    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Rebin_CutData_Chi422_Chi532_AllGaps/Rebin_CutData_Chi422_Chi532_histograms.root","READ");

    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/Rebin_CutData_Rho_v422_v532/Rebin_CutData_Rho_v422_v532_histograms.root","READ");


    //TFile* fileOutput = new TFile("/Users/Helena/Desktop/New_Weights_NUA_NUE/TrackingEfficiency_pPb5TeV_LHC16q_CENT_wSDD.root","READ");

    //TFile* fileOutput = new TFile("/Users/Helena/Desktop/New_Weights_NUA_NUE/PhiWeight_LHC16q_CENT_wSDD.root","READ");
    TFile* fileOutput = new TFile("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_Corrected_4particle.root","READ");
    TDirectory *dir = (TDirectoryFile*)fileOutput->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");
    TH2F *fHistEtaPhi2D = (TH2F*)list->FindObject("fHistEtaPhi2D");
    
    // TH1D* hC22 = (TH1D*)file->Get("hC22");
    // if(!hC22) return;
    // hC22->Draw();

    //TH2F* NUE_hist = (TH2F*)fileOutput->Get("eff_265525");
    //TH3F* NUE_hist = (TH3F*)fileOutput->Get("fPhiWeight_265525");
    //if(!NUE_hist) return;
    //NUE_hist->Draw();
    //h1 = NUE_hist->ProjectionZ();
    h1 = fHistEtaPhi2D->ProjectionX();
    //h1->SetMarkerStyle(kFullCircle); 
    // Float_t ymax = h1.GetMaximum();
    // TLine *line = new TLine(0,ymax,6,ymax);
    // line->SetLineColor(kRed);
    // line->Draw();
    h1->SetMarkerColor(kBlue+1);
    h1->Draw("P");
    //h1->GetYaxis()->SetRangeUser(0., 1);
    //h1->GetXaxis()->SetRangeUser(0., 105);
    //c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/NUA_py.png");




// ..Plot the results:
    // //..v_{4,22}
    // hC22_Rebin_Gap00->GetYaxis()->SetRangeUser(0., 0.03);
    // hC22_Rebin_Gap08->GetXaxis()->SetRangeUser(0., 105);
    // hC22_Rebin_Gap08->SetMarkerSize(1.);
    // hC22_Rebin_Gap08->Draw("same");
    // hC22_Rebin_Gap08->SetTitle("Non-Linear Response v_{4,22} for pPb at #sqrt{s_{NN}} = 5.02 TeV");
    // hC22_Rebin_Gap08->SetMarkerStyle(kFullTriangleUp); 
    // hC22_Rebin_Gap08->SetMarkerColor(kRed+1);
    // hC22_Rebin_Gap08->GetYaxis()->SetTitleOffset(1.4);
    // //hC22_Rebin_Gap08->GetYaxis()->CenterTitle(true);
    // hC22_Rebin_Gap08->GetYaxis()->SetTitle("v_{4,22}");

    // hC22_Rebin_Gap08->GetXaxis()->SetTitleOffset(1.4);
    // //hC22_Rebin_Gap08->GetXaxis()->CenterTitle(true);
    // gStyle->SetTitleFontSize(0.2);
    // hC22_Rebin_Gap08->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    // hC22_Rebin_Gap08->SetFillColor(kRed-9);
    // gStyle->SetOptStat(0);
    // c->Update();
    
    // TLatex latex;
    // latex.SetTextSize(0.035);
    // latex.SetTextAlign(13);  //align at top
    // latex.DrawLatex(10,0.0032,"#sqrt{s_{NN}} = 5.02 TeV");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(10,0.003,"|#Delta #eta| < 0.8");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(10,0.0028," 0.2 < p_{T} < 3.0");

    // TLegend *leg = new TLegend(0.4, 0.5, 0.55, 0.55); 
    // leg->AddEntry(hC22_Rebin_Gap08, "v_{4,22}", "fp");
    // leg->Draw("same");
    // c->SaveAs("/Users/Helena/Desktop/Plots/New_plots/v422_NL_plot02.png");

    // leg->SetBorderSize(0);
    // gStyle->SetTitleFontSize(0.2);
    //************************************************************************** 

    //..v_{5,32}
    // hC25_Rebin_Gap00->GetYaxis()->SetRangeUser(0., 0.04);
    // hC25_Rebin_Gap00->GetXaxis()->SetRangeUser(0., 105);
    // hC25_Rebin_Gap00->SetMarkerSize(1.);
    // hC25_Rebin_Gap00->Draw("same");
    // hC25_Rebin_Gap00->SetTitle("Non-Linear Response v_{5,32} for pPb at #sqrt{s_{NN}} = 5.02 TeV");
    // hC25_Rebin_Gap00->SetMarkerStyle(kFullTriangleUp); 
    // hC25_Rebin_Gap00->SetMarkerColor(kBlue+1);
    // hC25_Rebin_Gap00->GetYaxis()->SetTitleOffset(1.4);
    // //hC25_Rebin_Gap00->GetYaxis()->CenterTitle(true);
    // hC25_Rebin_Gap00->GetYaxis()->SetTitle("v_{5,32}");

    // hC25_Rebin_Gap00->GetXaxis()->SetTitleOffset(1.4);
    // //hC25_Rebin_Gap00->GetXaxis()->CenterTitle(true);
    // gStyle->SetTitleFontSize(0.2);
    // hC25_Rebin_Gap00->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    // hC25_Rebin_Gap00->SetFillColor(kRed-9);
    // gStyle->SetOptStat(0);
    // c->Update();
    
    // TLatex latex;
    // latex.SetTextSize(0.035);
    // latex.SetTextAlign(13);  //align at top
    // latex.DrawLatex(10,0.015,"#sqrt{s_{NN}} = 5.02 TeV");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(10,0.013,"|#Delta #eta| < 0.0");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(10,0.011," 0.2 < p_{T} < 3.0");

    // TLegend *leg = new TLegend(0.4, 0.5, 0.55, 0.55); 
    // leg->AddEntry(hC25_Rebin_Gap00, "v_{5,32}", "fp");
    // leg->Draw("same");


//     //**************************************************************************
//     //..Plot Chi422: 
    // hChi422_Rebin_Gap00->GetYaxis()->SetRangeUser(0., 3.);
    // hChi422_Rebin_Gap00->GetXaxis()->SetRangeUser(0., 105);
    // hChi422_Rebin_Gap00->SetMarkerSize(1.);
    // hChi422_Rebin_Gap00->Draw("same");
    // hChi422_Rebin_Gap00->SetTitle("Non-Linear coefficient #chi_{4,22} of v_{4,22} for pPb at 5.02 TeV");
    // hChi422_Rebin_Gap00->SetMarkerStyle(kFullTriangleUp); 
    // hChi422_Rebin_Gap00->SetMarkerColor(kRed+1);
    // hChi422_Rebin_Gap00->GetYaxis()->SetTitleOffset(1.4);
    // //hChi422_Rebin_Gap00->GetYaxis()->CenterTitle(true);
    // hChi422_Rebin_Gap00->GetYaxis()->SetTitle("#chi_{4,22}");

    // hChi422_Rebin_Gap00->GetXaxis()->SetTitleOffset(1.4);
    // //hChi422_Rebin_Gap00->GetXaxis()->CenterTitle(true);
    // gStyle->SetTitleFontSize(0.2);
    // hChi422_Rebin_Gap00->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    // hChi422_Rebin_Gap00->SetFillColor(kRed-9);
    // gStyle->SetOptStat(0);
    // c->Update();
    
    // TLatex latex;
    // latex.SetTextSize(0.035);
    // latex.SetTextAlign(13);  //align at top
    // latex.DrawLatex(10,2.5,"#sqrt{s_{NN}} = 5.02 TeV");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(10,2.3,"|#Delta #eta| < 0.0");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(10,2.1," 0.2 < p_{T} < 3.0");

    // TLegend *leg = new TLegend(0.4, 0.5, 0.55, 0.55); 
    // leg->AddEntry(hChi422_Rebin_Gap00, "#chi_{4,22}", "fp");
    // leg->Draw("same");

    // leg->SetBorderSize(0);
    // gStyle->SetTitleFontSize(0.2);

//     //************************************************
//     //..Plot Chi532
    // hChi532_Rebin_Gap00->GetYaxis()->SetRangeUser(0., 6.);
    // hChi532_Rebin_Gap00->GetXaxis()->SetRangeUser(0., 105);
    // hChi532_Rebin_Gap00->SetMarkerSize(1.);
    // hChi532_Rebin_Gap00->Draw("same");
    // hChi532_Rebin_Gap00->SetTitle("Non-Linear coefficient #chi_{5,32} of v_{5,32} for pPb at 5.02 TeV");
    // hChi532_Rebin_Gap00->SetMarkerStyle(kFullTriangleUp); 
    // hChi532_Rebin_Gap00->SetMarkerColor(kBlue+1);
    // hChi532_Rebin_Gap00->GetYaxis()->SetTitleOffset(1.4);
    // //hChi532_Rebin_Gap00->GetYaxis()->CenterTitle(true);
    // hChi532_Rebin_Gap00->GetYaxis()->SetTitle("#chi_{5,32}");

    // hChi532_Rebin_Gap00->GetXaxis()->SetTitleOffset(1.4);
    // //hChi532_Rebin_Gap00->GetXaxis()->CenterTitle(true);
    // gStyle->SetTitleFontSize(0.2);
    // hChi532_Rebin_Gap00->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    // hChi532_Rebin_Gap00->SetFillColor(kBlue-9);
    // gStyle->SetOptStat(0);
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
    // leg->AddEntry(hChi532_Rebin_Gap00, "#chi_{5,32}", "fp");
    // leg->Draw("same");
    
    // leg->SetBorderSize(0);
    // gStyle->SetTitleFontSize(0.2);

    //......rho
    // ////..Plot Rho422: 
    // hRho_V422_Rebin_Gap04->GetYaxis()->SetRangeUser(0., 2.);
    // hRho_V422_Rebin_Gap04->GetXaxis()->SetRangeUser(0., 105);
    // hRho_V422_Rebin_Gap04->SetMarkerSize(1.);
    // hRho_V422_Rebin_Gap04->Draw("same");
    // hRho_V422_Rebin_Gap04->SetTitle("Symmetry plane correlations #rho_{4,22} for pPb at 5.02 TeV");
    // hRho_V422_Rebin_Gap04->SetMarkerStyle(kFullTriangleUp); 
    // hRho_V422_Rebin_Gap04->SetMarkerColor(kRed+1);
    // hRho_V422_Rebin_Gap04->GetYaxis()->SetTitleOffset(1.4);
    // //hRho_V422_Rebin_Gap04->GetYaxis()->CenterTitle(true);
    // hRho_V422_Rebin_Gap04->GetYaxis()->SetTitle("#rho_{4,22}");

    // hRho_V422_Rebin_Gap04->GetXaxis()->SetTitleOffset(1.4);
    // //hRho_V422_Rebin_Gap04->GetXaxis()->CenterTitle(true);
    // gStyle->SetTitleFontSize(0.2);
    // hRho_V422_Rebin_Gap04->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    // hRho_V422_Rebin_Gap04->SetFillColor(kRed-9);
    // gStyle->SetOptStat(0);
    // c->Update();
    
    // TLatex latex;
    // latex.SetTextSize(0.035);
    // latex.SetTextAlign(13);  //align at top
    // latex.DrawLatex(10,1.5,"#sqrt{s_{NN}} = 5.02 TeV");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(10,1.3,"|#Delta #eta| < 0.4");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(10,1.1," 0.2 < p_{T} < 3.0");

    // TLegend *leg = new TLegend(0.4, 0.5, 0.55, 0.55); 
    // leg->AddEntry(hRho_V422_Rebin_Gap04, "#rho_{4,22}", "fp");
    // leg->Draw("same");

    // leg->SetBorderSize(0);
    // gStyle->SetTitleFontSize(0.2);

    // ////..Plot Rho532: 
    // hRho_V532_Rebin_Gap00->GetYaxis()->SetRangeUser(0., 2.);
    // hRho_V532_Rebin_Gap00->GetXaxis()->SetRangeUser(0., 105);
    // hRho_V532_Rebin_Gap00->SetMarkerSize(1.);
    // hRho_V532_Rebin_Gap00->Draw("same");
    // hRho_V532_Rebin_Gap00->SetTitle("");
    // hRho_V532_Rebin_Gap00->SetMarkerStyle(20); 
    // hRho_V532_Rebin_Gap00->SetMarkerColor(kRed+1);
    // hRho_V532_Rebin_Gap00->GetYaxis()->SetTitleOffset(1.4);
    // //hRho_V532_Rebin_Gap00->GetYaxis()->CenterTitle(true);
    // hRho_V532_Rebin_Gap00->GetYaxis()->SetTitle("#rho_{5,32}");

    // hRho_V532_Rebin_Gap00->GetXaxis()->SetTitleOffset(1.4);
    // //hRho_V532_Rebin_Gap00->GetXaxis()->CenterTitle(true);
    // gStyle->SetTitleFontSize(0.2);
    // hRho_V532_Rebin_Gap00->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    // hRho_V532_Rebin_Gap00->SetFillColor(kRed-9);
    // gStyle->SetOptStat(0);
    // c->Update();
    
    // TLatex latex;
    // latex.SetTextSize(0.035);
    // latex.SetTextAlign(13);  //align at top
    // latex.DrawLatex(-10,1.,"ALICE");
    
    // latex.SetTextAlign(13);  //align at top
    // latex.DrawLatex(-10,0.9,"pPb #sqrt{s_{NN}} = 5.02 TeV");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(-10,0.8,"|#Delta #eta| < 0.0");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(-10,0.7," 0.2 < p_{T} < 3.0");

    // // the coordinate is the percentile from 0 to 100% : x1, y1, x2, y2
    // TLegend *leg = new TLegend(0.78, 0.65, 0.89, 0.69); 
    // leg->AddEntry(hRho_V532_Rebin_Gap00, "#rho_{5,32}", "fp");
    // leg->Draw("same");

    // leg->SetBorderSize(0);
    // gStyle->SetTitleFontSize(0.2);
    // TImage *img = TImage::Create();
    // //img->FromPad(c, 10, 10, 308, 200);
    // img->FromPad(c);
    // img->WriteImage("/Users/Helena/Desktop/Plots/New_plots_Flow_meeting/canvas.png");
}