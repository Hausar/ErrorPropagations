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

void DCA_xy_pT_2D() {
    double BinValue_Xaxis = 0.0;
    double BinValue_Yaxis = 0.0;
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    //gPad->SetLogy();
    
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

    //..Define and Fill 2D hist with DCAxy && pT:
    hDCA_xy_pT_2D = new TH2F("hDCA_xy_pT_2D", "2D Distribution of #DCA_{xy} versus p_{T}; p_{T} [GeV/c]; DCA_{xy}", 50, 0, 5, 20, -1., 1.);
    hDCA_xy_pT_2D->Sumw2();
    //DCA_xy_pT_2D->Draw();
    for(int i=1; i < fHistPt->GetNbinsX()+1; i++ ) {
            BinValue_Xaxis = fHistPt->GetBinContent(i); 
        for(int j = 1; j < hDCAxyBefore->GetNbinsX()+1; j++) {
            BinValue_Yaxis = hDCAxyBefore->GetBinContent(j);
            // cout << BinValue_Xaxis << endl;
            // cout << BinValue_Yaxis << endl;
        }
        if(BinValue_Xaxis = 0) continue;
        if(BinValue_Yaxis = 0) continue;
    hDCA_xy_pT_2D->Fill(BinValue_Xaxis, BinValue_Yaxis);
    }

    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/QA_plots/DCA_pT_2D.root","RECREATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hDCA_xy_pT_2D->Write();
    //return;
    // //..Add Legend to plot:
    // TLegend *legend = new TLegend(0.6,0.7,0.9,0.9);
    // legend->AddEntry(fHistPt,"Before cut", "l");
    // legend->AddEntry(fHistPtAfter,"After cut","l");
    // legend->Draw();
    // c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_QA/new_Plots_QA/DCA_xy_pT_2D.png");
}   