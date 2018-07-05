//..The macro for plot Rebin: V4{2} 
//..The macro for plot Rebin: V5{2}
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

void Plot_V4_V5_2particle_Debug() {    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    //..Open the Root.file:
    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/V5_V4_{2}/Rebin_V5_V4_2particle_NUA+NUE.root","READ");
    TH1D* Rebin_V5_2particle_Gap00 = (TH1D*)fileOutput->Get("Rebin_V5_2particle_Gap00_A+B");
    TH1D* Rebin_V5_2particle_Gap01 = (TH1D*)fileOutput->Get("Rebin_V5_2particle_Gap01_A+B");
    TH1D* Rebin_V5_2particle_Gap02 = (TH1D*)fileOutput->Get("Rebin_V5_2particle_Gap02_A+B");
    TH1D* Rebin_V5_2particle_Gap03 = (TH1D*)fileOutput->Get("Rebin_V5_2particle_Gap03_A+B");
    TH1D* Rebin_V5_2particle_Gap04 = (TH1D*)fileOutput->Get("Rebin_V5_2particle_Gap04_A+B");
    TH1D* Rebin_V5_2particle_Gap05 = (TH1D*)fileOutput->Get("Rebin_V5_2particle_Gap05_A+B");
    TH1D* Rebin_V5_2particle_Gap06 = (TH1D*)fileOutput->Get("Rebin_V5_2particle_Gap06_A+B");
    TH1D* Rebin_V5_2particle_Gap07 = (TH1D*)fileOutput->Get("Rebin_V5_2particle_Gap07_A+B");
    TH1D* Rebin_V5_2particle_Gap08 = (TH1D*)fileOutput->Get("Rebin_V5_2particle_Gap08_A+B");

    Rebin_V5_2particle_Gap00->SetMarkerStyle(kFullCircle); 
    Rebin_V5_2particle_Gap00->SetMarkerColor(kBlue+1);
    Rebin_V5_2particle_Gap00->SetLineColor(kBlue+1);
    Rebin_V5_2particle_Gap00->SetStats(0);
    Rebin_V5_2particle_Gap00->SetTitle(0); 
    Rebin_V5_2particle_Gap00->GetXaxis()->SetRangeUser(20, 90);
    Rebin_V5_2particle_Gap00->GetYaxis()->SetRangeUser(0.0,0.05);
    Rebin_V5_2particle_Gap00->GetYaxis()->SetTitleOffset(1.2);
    //Rebin_V5_2particle_Gap00->GetYaxis()->CenterTitle(true);
    Rebin_V5_2particle_Gap00->GetYaxis()->SetTitle("v_{5}{2}");
    Rebin_V5_2particle_Gap00->GetYaxis()->SetTitleSize(0.04);
    //Rebin_V5_2particle_Gap00->GetXaxis()->SetTitle("N_{ch}");
    Rebin_V5_2particle_Gap00->GetXaxis()->SetTitleOffset(0.9);
    //Rebin_V5_2particle_Gap00->GetXaxis()->CenterTitle(true);
    Rebin_V5_2particle_Gap00->GetXaxis()->SetTitle("N_{ch}(|#eta| < 0.8)");
    Rebin_V5_2particle_Gap00->GetXaxis()->SetTitleSize(0.05);
    Rebin_V5_2particle_Gap00->Draw("P");
    //Rebin_V5_2particle_Gap00->SetFillColor(kRed-9);

    // Rebin_V5_2particle_Gap01->SetMarkerStyle(kFullTriangleUp); 
    // Rebin_V5_2particle_Gap01->SetMarkerColor(kRed+1);
    // Rebin_V5_2particle_Gap01->SetLineColor(kRed+1);
    // Rebin_V5_2particle_Gap01->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_V5_2particle_Gap01->SetTitle("|#Delta #eta |> 0.1 A");
    // Rebin_V5_2particle_Gap01->Draw("same");

    // Rebin_V5_2particle_Gap02->SetMarkerStyle(kFullCircle); 
    // Rebin_V5_2particle_Gap02->SetMarkerColor(kRed+4);
    // Rebin_V5_2particle_Gap02->SetLineColor(kRed+4);
    // Rebin_V5_2particle_Gap02->SetStats(0);
    // Rebin_V5_2particle_Gap01->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_V5_2particle_Gap02->SetTitle("|#Delta #eta |> 0.2 A");
    // Rebin_V5_2particle_Gap02->Draw("same");

    // Rebin_V5_2particle_Gap03->SetMarkerStyle(kFullSquare); 
    // Rebin_V5_2particle_Gap03->SetMarkerColor(kGreen+3);
    // Rebin_V5_2particle_Gap03->SetLineColor(kGreen+3);
    // Rebin_V5_2particle_Gap03->SetStats(0);
    // Rebin_V5_2particle_Gap03->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_V5_2particle_Gap03->SetTitle("|#Delta #eta |> 0.3 A");
    // Rebin_V5_2particle_Gap03->Draw("same");

    // Rebin_V5_2particle_Gap04->SetMarkerStyle(kFullDiamond); 
    // Rebin_V5_2particle_Gap04->SetMarkerColor(kBlack+2);
    // Rebin_V5_2particle_Gap04->SetLineColor(kBlack+2);
    // Rebin_V5_2particle_Gap04->SetMarkerSize(2);
    // Rebin_V5_2particle_Gap04->SetStats(0);
    // Rebin_V5_2particle_Gap04->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_V5_2particle_Gap04->SetTitle("|#Delta #eta |> 0.4 A");
    // Rebin_V5_2particle_Gap04->Draw("same");

    // Rebin_V5_2particle_Gap05->SetMarkerStyle(kFullStar); 
    // Rebin_V5_2particle_Gap05->SetMarkerColor(kOrange-3);
    // Rebin_V5_2particle_Gap05->SetLineColor(kOrange-3);
    // Rebin_V5_2particle_Gap05->SetMarkerSize(2);
    // Rebin_V5_2particle_Gap05->SetStats(0);
    // Rebin_V5_2particle_Gap05->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_V5_2particle_Gap05->SetTitle("|#Delta #eta |> 0.5 A");
    // Rebin_V5_2particle_Gap05->Draw("same");

    // Rebin_V5_2particle_Gap06->SetMarkerStyle(kFullCross); 
    // Rebin_V5_2particle_Gap06->SetMarkerColor(kSpring+5);
    // Rebin_V5_2particle_Gap06->SetLineColor(kSpring+5);
    // Rebin_V5_2particle_Gap06->SetMarkerSize(2);
    // Rebin_V5_2particle_Gap06->SetStats(0);
    // Rebin_V5_2particle_Gap06->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_V5_2particle_Gap06->SetTitle("|#Delta #eta |> 0.6 A");
    // Rebin_V5_2particle_Gap06->Draw("same");

    // Rebin_V5_2particle_Gap07->SetMarkerStyle(kFullDiamond); 
    // Rebin_V5_2particle_Gap07->SetMarkerColor(kCyan-7);
    // Rebin_V5_2particle_Gap07->SetLineColor(kCyan-7);
    // Rebin_V5_2particle_Gap07->SetMarkerSize(2.2);
    // Rebin_V5_2particle_Gap07->SetStats(0);
    // Rebin_V5_2particle_Gap07->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_V5_2particle_Gap07->SetTitle("|#Delta #eta |> 0.7 A");
    // Rebin_V5_2particle_Gap07->Draw("same");

    Rebin_V5_2particle_Gap08->SetMarkerStyle(kFullCircle); 
    Rebin_V5_2particle_Gap08->SetMarkerColor(kYellow+3);
    Rebin_V5_2particle_Gap08->SetLineColor(kYellow+3);
    //Rebin_V5_2particle_Gap08->SetMarkerSize(1);
    Rebin_V5_2particle_Gap08->SetStats(0);
    Rebin_V5_2particle_Gap08->GetXaxis()->SetRangeUser(10, 90);
    Rebin_V5_2particle_Gap08->SetTitle("|#Delta #eta |> 0.8 A");
    Rebin_V5_2particle_Gap08->Draw("same");
    
    //..Draw a Constant line at y=1
    gPad->Modified(); 
    gPad->Update(); // make sure gPad is updated 
    TLine *line = new TLine(gPad->GetUxmin(), 1, gPad->GetUxmax(), 1);
    line->SetLineStyle(9);
    line->SetLineWidth(2); 
    line->SetLineColor(kBlack);
    line->Draw(); 

    TLatex latex;
    latex.SetTextSize(0.045);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,0.049,"ALICE");

    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,0.044,"p-Pb collisions");
    
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,0.039,"#sqrt{s_{NN}} = 5.02 TeV");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(25,0.034,"|#eta| < 0.8");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(25,0.029," 0.2 < p_{T} < 3.0 GeV/c");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(45,0.044," (This thesis)");
 
    TLegend *leg = new TLegend(0.68, 0.55, 0.89, 0.89); 
    //TLegend *leg = new TLegend(0.11 , 0.6, 0.41, 0.82); 
    leg->SetBorderSize(-1);
    leg->AddEntry(Rebin_V5_2particle_Gap00, "|#Delta#eta| > 0.0 ", "lep");
    // leg->AddEntry(Rebin_V5_2particle_Gap01, "|#Delta#eta| > 0.1 ", "lep");
    // leg->AddEntry(Rebin_V5_2particle_Gap02, "|#Delta#eta| > 0.2 ", "lep");
    // leg->AddEntry(Rebin_V5_2particle_Gap03, "|#Delta#eta| > 0.3 ", "lep");
    // leg->AddEntry(Rebin_V5_2particle_Gap04, "|#Delta#eta| > 0.4 ", "lep");
    // leg->AddEntry(Rebin_V5_2particle_Gap05, "|#Delta#eta| > 0.5 ", "lep");
    // leg->AddEntry(Rebin_V5_2particle_Gap06, "|#Delta#eta| > 0.6 ", "lep");
    // leg->AddEntry(Rebin_V5_2particle_Gap07, "|#Delta#eta| > 0.7 ", "lep");
    leg->AddEntry(Rebin_V5_2particle_Gap08, "|#Delta#eta| > 0.8 ", "lep");
    leg->Draw("same");

    c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_V4_V5_2particle/Thesis_V5_gap00_gap08_newcolor.png");

}