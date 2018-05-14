
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
    
    //Open the root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/fEventCut_QA_Plots.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");
    
    TProfile *Vtz_raw = (TProfile*)list->FindObject("Vtz_raw");  
    TProfile *Vtz_selected = (TProfile*)list->FindObject("Vtz_selected");
    TProfile *fHistCentralityDis = (TProfile*)list->FindObject("fHistCentralityDis");
    //**************************************************************************    
    //..Plot the Histograms
    Vtz_raw->SetStats(0);
    Vtz_raw->GetYaxis()->SetTitleOffset(1.4);
    //Vtz_raw->Draw();
    Vtz_selected->SetStats(0);
    Vtz_selected->GetYaxis()->SetTitleOffset(1.4);
    Vtz_selected->SetLineColor(kRed+1);
    //Vtz_selected->Draw("same");
    fHistCentralityDis->SetStats(0);
    fHistCentralityDis->GetYaxis()->SetTitleOffset(1.4);
    fHistCentralityDis->SetTitle(0);
    fHistCentralityDis->Draw();
    c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_QA/CentralityDist.png");

}   