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

void Final_V4_V5_Linear_v422_v532_NL() 
{    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    //=========================================================================
    //In thesis we used: Debug_Rebin_Average_v532_A+B.root
    //  New file: 4particle_Rebin_Debug_Average_v422_v532_A+B.root
    // old Linear: Rebin_Modified_V5_Linear_A+B_NUA+NUE.root
    //***********************************************************************************
    //..Open root.file v422 && v532:
    TFile* fileOutput3 = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Average_V422_NUA+NUE/4particle_Rebin_Debug_Average_v422_v532_A+B.root","READ");
    TH1D* Rebin_NonLinear = (TH1D*)fileOutput3->Get("Rebin_v532_Gap08_A+B");

    //..Open root.file V4_Linear && V5_Linear:
    TFile* fileOutput4 = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/V4_V5_Linear_Debug/Rebin_4particle_newDebug_V4_V5_Linear_Helene.root","READ");
    TH1D* Rebin_Linear = (TH1D*)fileOutput4->Get("Rebin_V5_Linear_Gap08_A+B");
    
    //..Open root.file V4{2} && V5{2}
    TFile* fileOutput5 = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/V5_V4_{2}/Rebin_V5_V4_2particle_NUA+NUE.root","READ");
    TH1D* Rebin_Vn  = (TH1D*)fileOutput5->Get("Rebin_V5_2particle_Gap08_A+B");
    //***********************************************************************    //=======================================================================
    //..Plot:
    Rebin_Vn->SetMarkerStyle(kFullCircle); 
    Rebin_Vn->SetMarkerColor(kRed+1);
    Rebin_Vn->SetLineColor(kRed+1);
    Rebin_Vn->SetStats(0);
    Rebin_Vn->SetTitle(0);
    Rebin_Vn->GetXaxis()->SetRangeUser(20, 90);
    Rebin_Vn->GetYaxis()->SetRangeUser(-0.02, 0.05);
    Rebin_Vn->GetYaxis()->SetTitleOffset(0.8);
    Rebin_Vn->GetYaxis()->SetTitleSize(0.06);
    Rebin_Vn->GetYaxis()->SetTitle("v_{n}");
    Rebin_Vn->GetXaxis()->SetTitleOffset(0.8);
    Rebin_Vn->GetXaxis()->SetTitleSize(0.05);
    Rebin_Vn->GetXaxis()->SetTitle("N_{ch}(|#eta| < 0.8)");
    Rebin_Vn->Draw("P");

    Rebin_Linear->SetMarkerStyle(kFullSquare); 
    Rebin_Linear->SetMarkerColor(kBlue+1);
    Rebin_Linear->SetLineColor(kBlue+1);
    Rebin_Linear->SetMarkerSize(1.2);
    Rebin_Linear->Draw("same");
    
    Rebin_NonLinear->SetMarkerStyle(kFullCross); 
    Rebin_NonLinear->SetMarkerColor(kGreen+2);
    Rebin_NonLinear->SetLineColor(kGreen+2);
    Rebin_NonLinear->SetMarkerSize(2.);
    Rebin_NonLinear->Draw("same");


    
    TLatex latex;
    latex.SetTextSize(0.045);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(23,0.049,"ALICE");

    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(23,0.043,"p-Pb collisions (This thesis)");
    
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(23,0.037,"#sqrt{s_{NN}} = 5.02 TeV");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(23,0.032,"|#eta| < 0.8");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(23,0.028," 0.2 < p_{T} < 3.0 GeV/c");
    
    TLegend *leg = new TLegend(0.51 , 0.5, 0.83, 0.89); 
    //TLegend *leg = new TLegend(0.18 , 0.16, 0.49, 0.29); 
    leg->SetBorderSize(-1);
    leg->AddEntry(Rebin_Vn, "v_{5}{2, |#Delta#eta| > 0.8}", "lep");
    leg->AddEntry(Rebin_Linear, "v_{5}^{L} {|#Delta#eta| > 0.8}", "lep");
    leg->AddEntry(Rebin_NonLinear, "v_{5,32} {|#Delta#eta| > 0.8}", "lep");
    leg->Draw("same");
    c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_NonLinear+Linear+C42_C52/Thesis_Vn_VnL_vn,mk/Thesis_V5+Linear+NonLinear_Gap08.png");
}