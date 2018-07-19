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

void Plot_Chi_nmk() {    
    // create canvas
    TCanvas *canRatio = new TCanvas("canRatio", "", 600, 450);
    // only after creating canvas, you call gPad
    gPad->SetBottomMargin(0.12); // increase bottom margin to have space for x-axis title                                               
    gPad->SetLeftMargin(0.13); // increase left margin to have space for y-axis title
    gPad->SetRightMargin(0.03); // decrease right margin because there you don't have any text (except for 2D plots)
    //..Open the Root.file:
    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Chi422_Chi532_AllGaps_NUA+NUE/Chi_n,mk/Rebin_Chi_nmk_NUA+NUE_A+B.root","READ");

    TH1D* Rebin_Chi_532_Gap00A = (TH1D*)fileOutput->Get("Rebin_Chi_532_Gap00");
    TH1D* Rebin_Chi_532_Gap01A = (TH1D*)fileOutput->Get("Rebin_Chi_532_Gap01");
    TH1D* Rebin_Chi_532_Gap02A = (TH1D*)fileOutput->Get("Rebin_Chi_532_Gap02");
    TH1D* Rebin_Chi_532_Gap03A = (TH1D*)fileOutput->Get("Rebin_Chi_532_Gap03");
    TH1D* Rebin_Chi_532_Gap04A = (TH1D*)fileOutput->Get("Rebin_Chi_532_Gap04");
    TH1D* Rebin_Chi_532_Gap05A = (TH1D*)fileOutput->Get("Rebin_Chi_532_Gap05");
    TH1D* Rebin_Chi_532_Gap06A = (TH1D*)fileOutput->Get("Rebin_Chi_532_Gap06");
    TH1D* Rebin_Chi_532_Gap07A = (TH1D*)fileOutput->Get("Rebin_Chi_532_Gap07");
    TH1D* Rebin_Chi_532_Gap08A = (TH1D*)fileOutput->Get("Rebin_Chi_532_Gap08");

    Rebin_Chi_532_Gap00A->SetMarkerStyle(kFullCircle); 
    Rebin_Chi_532_Gap00A->SetMarkerColor(kBlue+1);
    Rebin_Chi_532_Gap00A->SetLineColor(kBlue+1);
    Rebin_Chi_532_Gap00A->SetStats(0);
    Rebin_Chi_532_Gap00A->SetTitle(0);
    Rebin_Chi_532_Gap00A->GetYaxis()->SetTitle("#chi_{5,32}");
    Rebin_Chi_532_Gap00A->GetYaxis()->SetRangeUser(-30, 30);
    Rebin_Chi_532_Gap00A->GetYaxis()->SetTitleOffset(0.7);
    Rebin_Chi_532_Gap00A->GetYaxis()->SetTitleSize(0.06);
    Rebin_Chi_532_Gap00A->GetYaxis()->SetNdivisions(505); // sometimes this makes the axes look prettier, it decreases number of ticks
    Rebin_Chi_532_Gap00A->GetYaxis()->SetLabelSize(0.055); // label size should be the same as title size for consistency

    Rebin_Chi_532_Gap00A->GetXaxis()->SetNdivisions(505); // sometimes this makes the axes look prettier, it decreases number of ticks
    //Rebin_Chi_532_Gap00A->GetYaxis()->CenterTitle(true);
    Rebin_Chi_532_Gap00A->GetXaxis()->SetLabelSize(0.055); // label size should be the same as title size for consistency
    Rebin_Chi_532_Gap00A->GetXaxis()->SetRangeUser(20, 70);
    Rebin_Chi_532_Gap00A->GetXaxis()->SetTitleOffset(1.0);
    Rebin_Chi_532_Gap00A->GetXaxis()->SetTitleSize(0.055);
    Rebin_Chi_532_Gap00A->GetXaxis()->SetTitle("N_{ch}(|#eta| < 0.8)");
    Rebin_Chi_532_Gap00A->Draw("P");

    Rebin_Chi_532_Gap01A->SetMarkerStyle(kFullTriangleUp); 
    Rebin_Chi_532_Gap01A->SetMarkerColor(kRed+1);
    Rebin_Chi_532_Gap01A->SetLineColor(kRed+1);
    Rebin_Chi_532_Gap01A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Chi_532_Gap01A->SetTitle("|#Delta #eta |> 0.1 ");
    Rebin_Chi_532_Gap01A->Draw("same");

    Rebin_Chi_532_Gap02A->SetMarkerStyle(kFullCircle); 
    Rebin_Chi_532_Gap02A->SetMarkerColor(kRed+4);
    Rebin_Chi_532_Gap02A->SetLineColor(kRed+4);
    Rebin_Chi_532_Gap02A->SetStats(0);
    Rebin_Chi_532_Gap01A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Chi_532_Gap02A->SetTitle("|#Delta #eta |> 0.2 ");
    Rebin_Chi_532_Gap02A->Draw("same");

    Rebin_Chi_532_Gap03A->SetMarkerStyle(kFullSquare); 
    Rebin_Chi_532_Gap03A->SetMarkerColor(kGreen+3);
    Rebin_Chi_532_Gap03A->SetLineColor(kGreen+3);
    Rebin_Chi_532_Gap03A->SetStats(0);
    Rebin_Chi_532_Gap03A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Chi_532_Gap03A->SetTitle("|#Delta #eta |> 0.3 ");
    Rebin_Chi_532_Gap03A->Draw("same");

    Rebin_Chi_532_Gap04A->SetMarkerStyle(kFullDiamond); 
    Rebin_Chi_532_Gap04A->SetMarkerColor(kBlack+2);
    Rebin_Chi_532_Gap04A->SetLineColor(kBlack+2);
    Rebin_Chi_532_Gap04A->SetMarkerSize(2);
    Rebin_Chi_532_Gap04A->SetStats(0);
    Rebin_Chi_532_Gap04A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Chi_532_Gap04A->SetTitle("|#Delta #eta |> 0.4 ");
    Rebin_Chi_532_Gap04A->Draw("same");

    Rebin_Chi_532_Gap05A->SetMarkerStyle(kFullStar); 
    Rebin_Chi_532_Gap05A->SetMarkerColor(kOrange-3);
    Rebin_Chi_532_Gap05A->SetLineColor(kOrange-3);
    Rebin_Chi_532_Gap05A->SetMarkerSize(2);
    Rebin_Chi_532_Gap05A->SetStats(0);
    Rebin_Chi_532_Gap05A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Chi_532_Gap05A->SetTitle("|#Delta #eta |> 0.5 ");
    Rebin_Chi_532_Gap05A->Draw("same");

    // Rebin_Chi_532_Gap06A->SetMarkerStyle(kFullCross); 
    // Rebin_Chi_532_Gap06A->SetMarkerColor(kSpring+5);
    // Rebin_Chi_532_Gap06A->SetLineColor(kSpring+5);
    // Rebin_Chi_532_Gap06A->SetMarkerSize(2);
    // Rebin_Chi_532_Gap06A->SetStats(0);
    // Rebin_Chi_532_Gap06A->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_Chi_532_Gap06A->SetTitle("|#Delta #eta |> 0.6 ");
    // Rebin_Chi_532_Gap06A->Draw("same");

    // Rebin_Chi_532_Gap07A->SetMarkerStyle(kFullDiamond); 
    // Rebin_Chi_532_Gap07A->SetMarkerColor(kCyan-7);
    // Rebin_Chi_532_Gap07A->SetLineColor(kCyan-7);
    // Rebin_Chi_532_Gap07A->SetMarkerSize(2);
    // Rebin_Chi_532_Gap07A->SetStats(0);
    // Rebin_Chi_532_Gap07A->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_Chi_532_Gap07A->SetTitle("|#Delta #eta |> 0.7 ");
    // Rebin_Chi_532_Gap07A->Draw("same");

    Rebin_Chi_532_Gap08A->SetMarkerStyle(kFullCircle); 
    Rebin_Chi_532_Gap08A->SetMarkerColor(kMagenta);
    Rebin_Chi_532_Gap08A->SetLineColor(kMagenta);
    Rebin_Chi_532_Gap08A->SetStats(0);
    Rebin_Chi_532_Gap08A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Chi_532_Gap08A->SetTitle("|#Delta #eta |> 0.8 ");
    Rebin_Chi_532_Gap08A->Draw("same");
    
    //..Draw a Constant line at y=1
    gPad->Modified(); 
    gPad->Update(); // make sure gPad is updated 
    TLine *line = new TLine(gPad->GetUxmin(), 1, gPad->GetUxmax(), 1);
    line->SetLineStyle(9);
    line->SetLineWidth(2); 
    line->SetLineColor(kBlack);
    line->Draw(); 

    TLatex latex;
    latex.SetTextSize(0.05);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(23,28,"ALICE");

    latex.SetTextSize(0.05);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(30,28,"(This thesis)");

    latex.SetTextSize(0.045);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(23,23,"p-Pb collisions");
    
    latex.SetTextSize(0.045);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(23,18,"#sqrt{s_{NN}} = 5.02 TeV");

    latex.SetTextSize(0.045);
    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(45,23,"|#eta| < 0.8");

    latex.SetTextSize(0.045);
    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(45,18," 0.2 < p_{T} < 3.0 GeV/c");

    //TLegend *leg = new TLegend(0.61, 0.62, 0.82, 0.89); 
    TLegend *leg = new TLegend(0.18 , 0.15, 0.41, 0.41); 
    leg->SetBorderSize(-1);
    leg->AddEntry(Rebin_Chi_532_Gap00A, "|#Delta#eta| > 0.0 ", "lep");
    leg->AddEntry(Rebin_Chi_532_Gap01A, "|#Delta#eta| > 0.1 ", "lep");
    leg->AddEntry(Rebin_Chi_532_Gap02A, "|#Delta#eta| > 0.2 ", "lep");
    leg->AddEntry(Rebin_Chi_532_Gap03A, "|#Delta#eta| > 0.3 ", "lep");
    leg->AddEntry(Rebin_Chi_532_Gap04A, "|#Delta#eta| > 0.4 ", "lep");
    leg->AddEntry(Rebin_Chi_532_Gap05A, "|#Delta#eta| > 0.5 ", "lep");
    //leg->AddEntry(Rebin_Chi_532_Gap06A, "|#Delta#eta| > 0.6 ", "lep");
    //leg->AddEntry(Rebin_Chi_532_Gap07A, "|#Delta#eta| > 0.7 ", "lep");
    leg->AddEntry(Rebin_Chi_532_Gap08A, "|#Delta#eta| > 0.8 ", "lep");
    leg->Draw("same");

    canRatio->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_NL_Coefficient_Chi422_Chi532/Final_Chi_n,mk/Chi532_WO_gap06_gap07.pdf");
}