//Macro To Calculate the Error Propagation:
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

void QA_plots() {
    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    gPad->SetLogy();
    
    //Open the root.file:
    //TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/fEventCut_QA_Plots.root", "READ");
    TFile *file = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/bar_GF/Helene_WNUA/merging/DCA_distribution_cut.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");   
    TProfile *Vtz_raw = (TProfile*)list->FindObject("Vtz_raw");  
    TProfile *Vtz_selected = (TProfile*)list->FindObject("Vtz_selected");
    TProfile *fHistCentralityDis = (TProfile*)list->FindObject("fHistCentralityDis");
    TProfile *fHistMult = (TProfile*)list->FindObject("fHistMult");
    TProfile *fHistPt = (TProfile*)list->FindObject("fHistPt");
    TProfile *fHistPtAfter = (TProfile*)list->FindObject("fHistPtAfter");
    TProfile *fHistEta = (TProfile*)list->FindObject("fHistEta");
    TProfile *fHistEtaAfter = (TProfile*)list->FindObject("fHistEtaAfter");
    TProfile *hDCAxyBefore = (TProfile*)list->FindObject("hDCAxyBefore");
    TProfile *hDCAzBefore = (TProfile*)list->FindObject("hDCAzBefore");
    TProfile *hDCAxyAfter = (TProfile*)list->FindObject("hDCAxyAfter");
    TProfile *hDCAzAfter = (TProfile*)list->FindObject("hDCAzAfter");
    //**************************************************************************    
    //..Plot the Histograms
    Vtz_raw->SetStats(0);
    Vtz_raw->GetYaxis()->SetTitleOffset(1.4);
    Vtz_raw->SetTitle(0);
    //Vtz_raw->GetYaxis()->SetRangeUser(-10, 4000 );
    //Vtz_raw->GetXaxis()->SetRangeUser(0.2., 3.0 );
    //Vtz_raw->Draw();
    
    Vtz_selected->SetStats(0);
    Vtz_selected->GetYaxis()->SetTitleOffset(1.4);
    Vtz_selected->SetLineColor(kRed+1);
    Vtz_selected->SetTitle(0);
    //Vtz_selected->GetYaxis()->SetRangeUser(-10, 4000 );
    //Vtz_selected->Draw("same");

    fHistCentralityDis->SetStats(0);
    fHistCentralityDis->GetYaxis()->SetTitleOffset(1.4);
    fHistCentralityDis->SetTitle(0);
    //fHistCentralityDis->Draw();

    fHistMult->SetStats(0);
    fHistMult->GetYaxis()->SetTitle("Counts");
    fHistMult->GetYaxis()->SetTitleOffset(1.4);
    fHistMult->SetTitle(0);
    //fHistMult->Draw();

    fHistPt->SetStats(0);
    fHistPt->GetYaxis()->SetTitle("Counts");
    fHistPt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
    fHistPt->GetYaxis()->SetTitleOffset(1.4);
    fHistPt->GetYaxis()->SetRangeUser(10e-1, 10e11 );
    fHistPt->GetXaxis()->SetRangeUser(-3, 10.0 );
    fHistPt->SetTitle(0);
    //fHistPt->Draw("hist");

    fHistPtAfter->SetStats(0);
    fHistPtAfter->GetYaxis()->SetTitle("Counts");
    fHistPtAfter->GetXaxis()->SetTitle("p_{T}[GeV/c]");
    fHistPtAfter->GetYaxis()->SetTitleOffset(1.4);
    fHistPtAfter->GetYaxis()->SetRangeUser(10e-1., 10e11 );
    fHistPtAfter->GetXaxis()->SetRangeUser(-3, 10.0 );
    fHistPtAfter->SetTitle(0);
    fHistPtAfter->SetLineColor(kRed);
    //fHistPtAfter->Draw("same hist");
    
    fHistEta->SetStats(0);
    fHistEta->GetYaxis()->SetTitle("Counts");
    fHistEta->GetXaxis()->SetTitle("#eta");
    fHistEta->GetYaxis()->SetTitleOffset(1.3);
    fHistEta->SetTitle(0);
    //fHistEta->Draw("l hist");

    fHistEtaAfter->SetStats(0);
    fHistEtaAfter->GetYaxis()->SetTitle("Counts");
    fHistEtaAfter->GetXaxis()->SetTitle("#eta");
    fHistEtaAfter->GetYaxis()->SetTitleOffset(1.5);
    fHistEtaAfter->SetLineColor(kRed+1);
    fHistEtaAfter->SetTitle(0);
    //fHistEtaAfter->Draw("l hist same");

    hDCAxyBefore->SetStats(0);
    hDCAxyBefore->GetYaxis()->SetTitle("Counts");
    hDCAxyBefore->GetXaxis()->SetTitle("DCA_{xy}");
    hDCAxyBefore->GetYaxis()->SetTitleOffset(1.3);
    hDCAxyBefore->GetYaxis()->SetRangeUser(10, 10e12 );
    hDCAxyBefore->GetXaxis()->SetRangeUser(-0.1., 5.0 );
    hDCAxyBefore->SetTitle(0);
    //hDCAxyBefore->Draw("hist");

    hDCAzBefore->SetStats(0);
    hDCAzBefore->GetYaxis()->SetTitle("Counts");
    hDCAzBefore->GetXaxis()->SetTitle("DCA_{z}");
    hDCAzBefore->GetYaxis()->SetTitleOffset(1.3);
    hDCAzBefore->GetXaxis()->SetRangeUser(-3., 3.0 );
    hDCAzBefore->GetYaxis()->SetRangeUser(1, 10e10 );
    hDCAzBefore->SetTitle(0);
    //hDCAzBefore->Draw("hist");

    hDCAxyAfter->SetStats(0);
    hDCAxyAfter->GetYaxis()->SetTitle("Counts");
    hDCAxyAfter->GetXaxis()->SetTitle("DCA_{xy}");
    hDCAxyAfter->GetYaxis()->SetTitleOffset(1.4);
    hDCAxyAfter->GetYaxis()->SetRangeUser(10, 10e12 );
    hDCAxyAfter->GetXaxis()->SetRangeUser(-0.5, 5 );
    hDCAxyAfter->SetLineColor(kRed+1);
    hDCAxyAfter->SetTitle(0);
    //hDCAxyAfter->Draw("same hist");
    
    hDCAzAfter->SetStats(0);
    hDCAzAfter->GetYaxis()->SetTitle("Counts");
    hDCAzAfter->GetXaxis()->SetTitle("DCA_{z}");
    hDCAzAfter->GetYaxis()->SetTitleOffset(1.4);
    hDCAzAfter->SetLineColor(kRed+1);
    //hDCAzAfter->GetXaxis()->SetRangeUser(-3., 3.0 );
    hDCAzAfter->GetYaxis()->SetRangeUser(1, 10e10 );
    hDCAzAfter->SetTitle(0);
    //hDCAzAfter->Draw("same hist");

    //..Add Legend to plot:
    TLegend *legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(fHistPt,"Before cut", "l");
    legend->AddEntry(fHistPtAfter,"After cut","l");
    legend->Draw();
    c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_QA/new_Plots_QA/DCA_xy_pT_2D.png");
}   