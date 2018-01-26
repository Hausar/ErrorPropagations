//Macro To Calculate the Final results for plot Rho422 && Rho532 vs. Delta_EtaGap (Symmetry plane correlations):
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

void Delta_eta_dependent_rho422_rho532() {

    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();


    //..Root.file for all Eta-dependant plots
    TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Eta_Dependent/Delta_eta_dependent_rho422_rho532.root","RECREATE");


    int n= 9;
    double EtaGap[9]= {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8};
    double y1[9] = {};
    double y2[9] = {};

    //**************************************************************************
    TFile* file = TFile::Open(
    "/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/Rebin_Rho_v422_v532/Rebin_Rho_v422_v532_histograms.root", "READ");
    
    //..loop over bins and eta-gaps:
    for(int i=1; i<11; i++) {
        for(int gap=0; gap < 9; gap++) {
            
            //..Rho422 & Rho532:
            TString foo_422(TString::Format("hRho_V422_Rebin_Gap0%0d", gap));
            TString foo_532(TString::Format("hRho_V532_Rebin_Gap0%0d", gap));
            
            //..Rho422 && Rho532:
            TH1D *hRho422_gap = (TH1D*)file->Get(foo_422);
            TH1D *hRho532_gap = (TH1D*)file->Get(foo_532);
            
            y1[gap] = hRho422_gap->GetBinContent(i);
            y2[gap] = hRho532_gap->GetBinContent(i);

            cout << "y: " << y1[gap] << endl;
            cout << "i: " << i <<endl;
            cout << "Gap: " << gap << endl;
                        
            //*********************************************************************
            //..Plot the Rho422 vs. eta_gaps:
            
            TGraph* gr1 = new TGraph(n, EtaGap, y1);
            gr1->SetLineColor(2);
            gr1->SetLineWidth(4);
            gr1->SetMarkerColor(4);
            gr1->SetMarkerStyle(21);
            gr1->SetTitle(TString::Format("#rho_{4,22} Symmetry Plane Correlations Bin%0d", i));
            gr1->GetXaxis()->SetTitle("#Delta #eta");
            gr1->GetYaxis()->SetTitle("#rho_{4,22}");
            gr1->GetYaxis()->SetTitleOffset(1.4);
            gr1->Draw("ACP");
            //gr1->Draw("AC*");

            TGraph* gr2 = new TGraph(n, EtaGap, y2);
            gr2->SetLineColor(2);
            gr2->SetLineWidth(4);
            gr2->SetMarkerColor(4);
            gr2->SetMarkerStyle(21);
            gr2->SetTitle(Form("#rho_{5,32} Symmetry Plane Correlations, Bin%0d", i));
            gr2->GetXaxis()->SetTitle("#Delta #eta");
            gr2->GetYaxis()->SetTitle("#rho_{5,32}");
            gr2->GetYaxis()->SetTitleOffset(1.4);
            gr2->Draw("ACP");
            //gr2->Draw("AC*");            
            
        }
        
        if(!fileOutput) return;
        fileOutput->cd();
        gr1->Write(Form("EtaDependent_Rho422_Symmetryplane_correlation_Bin%0d", i));
        gr2->Write(Form("EtaDependent_Rho532_Symmetryplane_correlation_Bin%0d", i));
        
        //c->SaveAs("/Users/Helena/Desktop/Plots/Delta_eta_plots/test.png");
        cout << "i finished: " << i <<endl;
        //return;
    }
}



