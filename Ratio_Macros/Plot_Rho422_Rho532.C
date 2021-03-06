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

     TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/AllGaps_Rho_v422_v532_NUA+NUE/Rho_n,mk/Rebin_Rho_nmk_NUA+NUE_A+B.root","READ");

    TH1D* Rebin_Rho_422_Gap00A = (TH1D*)fileOutput->Get("Rebin_Rho_422_Gap00");
    TH1D* Rebin_Rho_422_Gap01A = (TH1D*)fileOutput->Get("Rebin_Rho_422_Gap01");
    TH1D* Rebin_Rho_422_Gap02A = (TH1D*)fileOutput->Get("Rebin_Rho_422_Gap02");
    TH1D* Rebin_Rho_422_Gap03A = (TH1D*)fileOutput->Get("Rebin_Rho_422_Gap03");
    TH1D* Rebin_Rho_422_Gap04A = (TH1D*)fileOutput->Get("Rebin_Rho_422_Gap04");
    TH1D* Rebin_Rho_422_Gap05A = (TH1D*)fileOutput->Get("Rebin_Rho_422_Gap05");
    TH1D* Rebin_Rho_422_Gap06A = (TH1D*)fileOutput->Get("Rebin_Rho_422_Gap06");
    TH1D* Rebin_Rho_422_Gap07A = (TH1D*)fileOutput->Get("Rebin_Rho_422_Gap07");
    TH1D* Rebin_Rho_422_Gap08A = (TH1D*)fileOutput->Get("Rebin_Rho_422_Gap08");

    Rebin_Rho_422_Gap00A->SetMarkerStyle(kFullCircle); 
    Rebin_Rho_422_Gap00A->SetMarkerColor(kBlue+1);
    Rebin_Rho_422_Gap00A->SetLineColor(kBlue+1);
    Rebin_Rho_422_Gap00A->SetStats(0);
    Rebin_Rho_422_Gap00A->SetTitle(0); 
    Rebin_Rho_422_Gap00A->GetXaxis()->SetRangeUser(20, 90);
    Rebin_Rho_422_Gap00A->GetYaxis()->SetRangeUser(-0.005, 2.0);
    Rebin_Rho_422_Gap00A->GetYaxis()->SetTitleOffset(0.6);
    //Rebin_Rho_422_Gap00A->GetYaxis()->CenterTitle(true);
    Rebin_Rho_422_Gap00A->GetYaxis()->SetTitle("#rho_{4,22}");
    Rebin_Rho_422_Gap00A->GetYaxis()->SetTitleSize(0.06);
    //Rebin_Rho_422_Gap00A->GetXaxis()->SetTitle("N_{ch}");
    Rebin_Rho_422_Gap00A->GetXaxis()->SetTitleOffset(0.9);
    //Rebin_Rho_422_Gap00A->GetXaxis()->CenterTitle(true);
    Rebin_Rho_422_Gap00A->GetXaxis()->SetTitle("N_{ch}(|#eta| < 0.8)");
    Rebin_Rho_422_Gap00A->GetXaxis()->SetTitleSize(0.05);
    Rebin_Rho_422_Gap00A->Draw("P");
    //Rebin_Rho_422_Gap00A->SetFillColor(kRed-9);

    Rebin_Rho_422_Gap01A->SetMarkerStyle(kFullTriangleUp); 
    Rebin_Rho_422_Gap01A->SetMarkerColor(kRed+1);
    Rebin_Rho_422_Gap01A->SetLineColor(kRed+1);
    Rebin_Rho_422_Gap01A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_422_Gap01A->SetTitle("|#Delta #eta |> 0.1 A");
    Rebin_Rho_422_Gap01A->Draw("same");

    Rebin_Rho_422_Gap02A->SetMarkerStyle(kFullCircle); 
    Rebin_Rho_422_Gap02A->SetMarkerColor(kRed+4);
    Rebin_Rho_422_Gap02A->SetLineColor(kRed+4);
    Rebin_Rho_422_Gap02A->SetStats(0);
    Rebin_Rho_422_Gap01A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_422_Gap02A->SetTitle("|#Delta #eta |> 0.2 A");
    Rebin_Rho_422_Gap02A->Draw("same");

    Rebin_Rho_422_Gap03A->SetMarkerStyle(kFullSquare); 
    Rebin_Rho_422_Gap03A->SetMarkerColor(kGreen+3);
    Rebin_Rho_422_Gap03A->SetLineColor(kGreen+3);
    Rebin_Rho_422_Gap03A->SetStats(0);
    Rebin_Rho_422_Gap03A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_422_Gap03A->SetTitle("|#Delta #eta |> 0.3 A");
    Rebin_Rho_422_Gap03A->Draw("same");

    Rebin_Rho_422_Gap04A->SetMarkerStyle(kFullDiamond); 
    Rebin_Rho_422_Gap04A->SetMarkerColor(kBlack+3);
    Rebin_Rho_422_Gap04A->SetLineColor(kBlack+3);
    Rebin_Rho_422_Gap04A->SetMarkerSize(2);
    Rebin_Rho_422_Gap04A->SetStats(0);
    Rebin_Rho_422_Gap04A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_422_Gap04A->SetTitle("|#Delta #eta |> 0.4 A");
    Rebin_Rho_422_Gap04A->Draw("same");

    Rebin_Rho_422_Gap05A->SetMarkerStyle(kFullStar); 
    Rebin_Rho_422_Gap05A->SetMarkerColor(kOrange-3);
    Rebin_Rho_422_Gap05A->SetLineColor(kOrange-3);
    Rebin_Rho_422_Gap05A->SetMarkerSize(2);
    Rebin_Rho_422_Gap05A->SetStats(0);
    Rebin_Rho_422_Gap05A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_422_Gap05A->SetTitle("|#Delta #eta |> 0.5 A");
    Rebin_Rho_422_Gap05A->Draw("same");

    Rebin_Rho_422_Gap06A->SetMarkerStyle(kFullCross); 
    Rebin_Rho_422_Gap06A->SetMarkerColor(kSpring+5);
    Rebin_Rho_422_Gap06A->SetLineColor(kSpring+5);
    Rebin_Rho_422_Gap06A->SetMarkerSize(2);
    Rebin_Rho_422_Gap06A->SetStats(0);
    Rebin_Rho_422_Gap06A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_422_Gap06A->SetTitle("|#Delta #eta |> 0.6 A");
    Rebin_Rho_422_Gap06A->Draw("same");

    Rebin_Rho_422_Gap07A->SetMarkerStyle(kFullDiamond); 
    Rebin_Rho_422_Gap07A->SetMarkerColor(kCyan-7);
    Rebin_Rho_422_Gap07A->SetLineColor(kCyan-7);
    Rebin_Rho_422_Gap07A->SetMarkerSize(2.2);
    Rebin_Rho_422_Gap07A->SetStats(0);
    Rebin_Rho_422_Gap07A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_422_Gap07A->SetTitle("|#Delta #eta |> 0.7 A");
    Rebin_Rho_422_Gap07A->Draw("same");

    Rebin_Rho_422_Gap08A->SetMarkerStyle(kFullCircle); 
    Rebin_Rho_422_Gap08A->SetMarkerColor(kMagenta);
    Rebin_Rho_422_Gap08A->SetLineColor(kMagenta);
    //Rebin_Rho_422_Gap08A->SetMarkerSize(1);
    Rebin_Rho_422_Gap08A->SetStats(0);
    Rebin_Rho_422_Gap08A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Rho_422_Gap08A->SetTitle("|#Delta #eta |> 0.8 A");
    Rebin_Rho_422_Gap08A->Draw("same");
    
    //..Draw a Constant line at y=1
    gPad->Modified(); 
    gPad->Update(); // make sure gPad is updated 
    TLine *line = new TLine(gPad->GetUxmin(), 1, gPad->GetUxmax(), 1);
    line->SetLineStyle(9);
    line->SetLineWidth(2); 
    line->SetLineColor(kBlack);
    line->Draw(); 


    //Rebin_Rho_422_Gap00A->SetTitle(0); 
    
    // TLatex latex;
    // latex.SetTextSize(0.045);
    // latex.SetTextAlign(13);  //align at top
    // latex.DrawLatex(15,2.8,"ALICE");

    // latex.SetTextSize(0.035);
    // latex.SetTextAlign(13);  //align at top
    // latex.DrawLatex(15,2.6,"p-Pb collisions (This thesis)");
    
    // latex.SetTextSize(0.035);
    // latex.SetTextAlign(13);  //align at top
    // latex.DrawLatex(15,2.4,"#sqrt{s_{NN}} = 5.02 TeV");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(15,2.2,"|#eta| < 0.8");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(15,2.," 0.2 < p_{T} < 3.0 GeV/c");

    TLatex latex;
    latex.SetTextSize(0.045);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,1.95,"ALICE");

    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,1.75,"p-Pb collisions");
    
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,1.65,"#sqrt{s_{NN}} = 5.02 TeV");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(25,1.55,"|#eta| < 0.8");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(25,1.45," 0.2 < p_{T} < 3.0 GeV/c");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(35,1.95," (This thesis)");
 
    TLegend *leg = new TLegend(0.46, 0.55, 0.89, 0.89); 
    //TLegend *leg = new TLegend(0.11 , 0.6, 0.41, 0.82); 
    leg->SetBorderSize(-1);
    leg->AddEntry(Rebin_Rho_422_Gap00A, "|#Delta#eta| > 0.0 ", "lep");
    leg->AddEntry(Rebin_Rho_422_Gap01A, "|#Delta#eta| > 0.1 ", "lep");
    leg->AddEntry(Rebin_Rho_422_Gap02A, "|#Delta#eta| > 0.2 ", "lep");
    leg->AddEntry(Rebin_Rho_422_Gap03A, "|#Delta#eta| > 0.3 ", "lep");
    leg->AddEntry(Rebin_Rho_422_Gap04A, "|#Delta#eta| > 0.4 ", "lep");
    leg->AddEntry(Rebin_Rho_422_Gap05A, "|#Delta#eta| > 0.5 ", "lep");
    leg->AddEntry(Rebin_Rho_422_Gap06A, "|#Delta#eta| > 0.6 ", "lep");
    leg->AddEntry(Rebin_Rho_422_Gap07A, "|#Delta#eta| > 0.7 ", "lep");
    leg->AddEntry(Rebin_Rho_422_Gap08A, "|#Delta#eta| > 0.8 ", "lep");
    leg->Draw("same");

    c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_SymmetryPlanes_Rho422_Rho532/Final_Rho_n,mk/Final_Rho_422.pdf");

}