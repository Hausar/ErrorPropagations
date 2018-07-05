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

void Plot_Rebin_V422_NL() 
{    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //..Open the Root.file:
    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Average_V422_NUA+NUE/Debug_Rebin_Average_v532_A+B.root","READ");

    TH1D* Rebin_hV422_Gap00A = (TH1D*)fileOutput->Get("Rebin_v532_Gap00A_A+B");
    TH1D* Rebin_hV422_Gap01A = (TH1D*)fileOutput->Get("Rebin_v532_Gap01A_A+B");
    TH1D* Rebin_hV422_Gap02A = (TH1D*)fileOutput->Get("Rebin_v532_Gap02A_A+B");
    TH1D* Rebin_hV422_Gap03A = (TH1D*)fileOutput->Get("Rebin_v532_Gap03A_A+B");
    TH1D* Rebin_hV422_Gap04A = (TH1D*)fileOutput->Get("Rebin_v532_Gap04A_A+B");
    TH1D* Rebin_hV422_Gap05A = (TH1D*)fileOutput->Get("Rebin_v532_Gap05A_A+B");
    TH1D* Rebin_hV422_Gap06A = (TH1D*)fileOutput->Get("Rebin_v532_Gap06A_A+B");
    TH1D* Rebin_hV422_Gap07A = (TH1D*)fileOutput->Get("Rebin_v532_Gap07A_A+B");
    TH1D* Rebin_hV422_Gap08A = (TH1D*)fileOutput->Get("Rebin_v532_Gap08A_A+B");



    Rebin_hV422_Gap00A->SetMarkerStyle(kFullCircle); 
    Rebin_hV422_Gap00A->SetMarkerColor(kBlue+1);
    Rebin_hV422_Gap00A->SetStats(0);
    Rebin_hV422_Gap00A->GetXaxis()->SetRangeUser(20, 90);
    Rebin_hV422_Gap00A->Draw("P");
    Rebin_hV422_Gap00A->GetYaxis()->SetRangeUser(-0.035, 0.055);
    Rebin_hV422_Gap00A->GetYaxis()->SetTitleOffset(1.5);
    //Rebin_hV422_Gap00A->GetYaxis()->SetTitleSize(0.1);
    //Rebin_hV422_Gap00A->GetYaxis()->CenterTitle(true);
    Rebin_hV422_Gap00A->GetYaxis()->SetTitle("v_{5,32}");
    Rebin_hV422_Gap00A->GetXaxis()->SetTitle("N_{trks}");
    Rebin_hV422_Gap00A->GetXaxis()->SetTitleOffset(1.3);
    //Rebin_hV422_Gap00A->GetXaxis()->CenterTitle(true);
    //gStyle->SetTitleFontSize(0.2);
    Rebin_hV422_Gap00A->GetXaxis()->SetTitle("N_{Ch}(|#eta| < 0.8)");
    //Rebin_hV422_Gap00A->SetFillColor(kRed-9);
    

    Rebin_hV422_Gap01A->SetMarkerStyle(kFullTriangleUp); 
    Rebin_hV422_Gap01A->SetMarkerColor(kRed+1);
    Rebin_hV422_Gap01A->SetLineColor(kRed+1);
    Rebin_hV422_Gap01A->SetMarkerSize(1.3);
    Rebin_hV422_Gap01A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV422_Gap01A->Draw("same");

    Rebin_hV422_Gap02A->SetMarkerStyle(kFullCircle); 
    Rebin_hV422_Gap02A->SetMarkerColor(kRed+4);
    Rebin_hV422_Gap02A->SetLineColor(kRed+4);
    Rebin_hV422_Gap02A->SetStats(0);
    Rebin_hV422_Gap01A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV422_Gap02A->Draw("same");

    Rebin_hV422_Gap03A->SetMarkerStyle(kFullSquare); 
    Rebin_hV422_Gap03A->SetMarkerColor(kGreen+3);
    Rebin_hV422_Gap03A->SetLineColor(kGreen+3);
    Rebin_hV422_Gap03A->SetMarkerSize(1.2);
    Rebin_hV422_Gap03A->SetStats(0);
    Rebin_hV422_Gap03A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV422_Gap03A->Draw("same");

    Rebin_hV422_Gap04A->SetMarkerStyle(kFullDiamond); 
    Rebin_hV422_Gap04A->SetMarkerColor(kBlack+3);
    Rebin_hV422_Gap04A->SetLineColor(kBlack+3);
    Rebin_hV422_Gap04A->SetMarkerSize(2.);
    Rebin_hV422_Gap04A->SetStats(0);
    Rebin_hV422_Gap04A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV422_Gap04A->Draw("same");

    Rebin_hV422_Gap05A->SetMarkerStyle(kFullStar); 
    Rebin_hV422_Gap05A->SetMarkerColor(kOrange-3);
    Rebin_hV422_Gap05A->SetLineColor(kOrange-3);
    Rebin_hV422_Gap05A->SetMarkerSize(2.1);
    Rebin_hV422_Gap05A->SetStats(0);
    Rebin_hV422_Gap05A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV422_Gap05A->Draw("same");

    Rebin_hV422_Gap06A->SetMarkerStyle(kFullCross); 
    Rebin_hV422_Gap06A->SetMarkerColor(kSpring+5);
    Rebin_hV422_Gap06A->SetLineColor(kSpring+5);
    Rebin_hV422_Gap06A->SetMarkerSize(2.);
    Rebin_hV422_Gap06A->SetStats(0);
    Rebin_hV422_Gap06A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV422_Gap06A->Draw("same");

    Rebin_hV422_Gap07A->SetMarkerStyle(kFullDiamond); 
    Rebin_hV422_Gap07A->SetMarkerColor(kCyan-7);
    Rebin_hV422_Gap07A->SetLineColor(kCyan-7);
    Rebin_hV422_Gap07A->SetMarkerSize(2.2);
    Rebin_hV422_Gap07A->SetStats(0);
    Rebin_hV422_Gap07A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV422_Gap07A->Draw("same");

    Rebin_hV422_Gap08A->SetMarkerStyle(kFullCircle); 
    Rebin_hV422_Gap08A->SetMarkerColor(kMagenta);
    Rebin_hV422_Gap08A->SetLineColor(kMagenta);
    Rebin_hV422_Gap08A->SetMarkerSize(1.2);
    Rebin_hV422_Gap08A->SetStats(0);
    Rebin_hV422_Gap08A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_hV422_Gap08A->Draw("same");


    //c->BuildLegend();
    Rebin_hV422_Gap00A->SetTitle(0);
    
    
    TLatex latex;
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(23,0.05,"ALICE");

    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(23,0.045,"p+Pb collisions (This Thesis)");
    
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(23,0.04,"#sqrt{s_{NN}} = 5.02 TeV");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(23,0.035,"|#eta| < 0.8");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(23,0.03," 0.2 < p_{T} < 3.0 GeV/c");
    
    TLegend *leg = new TLegend(0.51 , 0.6, 0.71, 0.89); 
    leg->AddEntry(Rebin_hV422_Gap00A, "|#Delta#eta| > 0.0 ", "lep");
    leg->AddEntry(Rebin_hV422_Gap01A, "|#Delta#eta| > 0.1 ", "lep");
    leg->AddEntry(Rebin_hV422_Gap02A, "|#Delta#eta| > 0.2 ", "lep");
    leg->AddEntry(Rebin_hV422_Gap03A, "|#Delta#eta| > 0.3 ", "lep");
    leg->AddEntry(Rebin_hV422_Gap04A, "|#Delta#eta| > 0.4 ", "lep");
    leg->AddEntry(Rebin_hV422_Gap05A, "|#Delta#eta| > 0.5 ", "lep");
    leg->AddEntry(Rebin_hV422_Gap06A, "|#Delta#eta| > 0.6 ", "lep");
    leg->AddEntry(Rebin_hV422_Gap07A, "|#Delta#eta| > 0.7 ", "lep");
    leg->AddEntry(Rebin_hV422_Gap08A, "|#Delta#eta| > 0.8 ", "lep");
    leg->Draw("same");

    c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_NonLinear_V532/Average_v532_NonLinear.png");
}