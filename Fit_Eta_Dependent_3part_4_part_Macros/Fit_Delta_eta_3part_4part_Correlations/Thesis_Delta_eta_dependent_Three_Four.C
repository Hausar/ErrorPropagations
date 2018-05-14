//Macro To Calculate the Final results for  <<3>> and <<4>> plot vs. Delta_EtaGap to study the correlations instead of observables:
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

void Thesis_Delta_eta_dependent_Three_Four() {


    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //..Create New file.root Eta-dependant of <<3>> and <<4>> plots
    TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Fit_Eta_Dependent_3part_4_part_Macros/Fit_Delta_eta_3part_4part_Correlations/Thesis_Delta_eta_dependent_output/thesis_Delta_eta_dependent_3part_4part_correlation.root","RECREATE");

    int n= 9;
    double EtaGap[9]= {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8};
    double y1[9] = {};
    double y2[9] = {};
    double y3[9] = {};
    double y4[9] = {};
    double error1 [9] = {};
    double error2 [9] = {};
    double error3 [9] = {};
    double error4 [9] = {};
    //double errx1 [9] = {0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05};
    //**************************************************************************
    //**************************************************************************
    TFile* file = TFile::Open(
    "/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Fit_Eta_Dependent_3part_4_part_Macros/Fit_Delta_eta_3part_4part_Correlations/Thesis_Delta_eta_dependent_output/Cut_Rebin_3part_4part_thesis.root", "READ");

    for(int i=1; i < 10; i++) {
        for(int gap=0; gap < 9; gap++) {
            
            //..<<3>>_Rebin and <<4>>_Rebin:
            TString foo_34(TString::Format("Rebin_34particle_Gap0%0dA", gap));
            TString foo_35(TString::Format("Rebin_35particle_Gap0%0dA", gap));
            TString foo_42(TString::Format("Rebin_42particle_Gap0%0dA", gap));
            TString foo_43(TString::Format("Rebin_43particle_Gap0%0dA", gap));

            //..<<3>>_Rebin and <<4>>_Rebin:
            TH1D *hC34_gap = (TH1D*)file->Get(foo_34);
            TH1D *hC35_gap = (TH1D*)file->Get(foo_35);
            TH1D *hC42_gap = (TH1D*)file->Get(foo_42);
            TH1D *hC43_gap = (TH1D*)file->Get(foo_43);
            
            // //..open the TH1D:
            y1[gap] = hC34_gap->GetBinContent(i);   //??? for i loop?
            y2[gap] = hC35_gap->GetBinContent(i);
            y3[gap] = hC42_gap->GetBinContent(i);
            y4[gap] = hC43_gap->GetBinContent(i);

            //..Error for TH1D:
            error1[gap] = hC34_gap->GetBinError(i);
            error2[gap] = hC35_gap->GetBinError(i);
            error3[gap] = hC42_gap->GetBinError(i);
            error4[gap] = hC43_gap->GetBinError(i);

            cout << "*********************************************" << endl;
            cout << "y1: " << y1[gap] << endl;
            cout << "y2: " << y2[gap] << endl;
            cout << "y3: " << y3[gap] << endl;
            cout << "y4: " << y4[gap] << endl;
            cout << "i: " << i <<endl;
            cout << "Gap: " << gap << endl;
            cout << "error: " << error1[gap] << endl;
            //nbin_range = hC34_gap->GetXaxis()->FindBin(106) - hC34_gap->GetXaxis()->FindBin(5);
            //cout << "Number of bins: " << nbin_range << endl; 
            cout << "**********************************************" << endl;
            
            //*********************************************************************  
            //*********************************************************************
            // //..plot <<3>>_422 
            TGraphErrors* gr1 = new TGraphErrors(n, EtaGap, y1, 0, error1);
            gr1->SetLineColor(2);
            gr1->SetLineWidth(1);
            gr1->SetMarkerColor(4);
            gr1->SetMarkerStyle(4);
            gr1->SetTitle(TString::Format("<<3>>_{4|-2,-2} 3-Particle correlations, Bin%0d", i));
            gr1->GetXaxis()->SetTitle("#Delta #eta");
            gr1->GetYaxis()->SetTitle("<<3>>_{4|-2,-2}");
            gr1->GetYaxis()->SetTitleOffset(1.4);
            //gr1->Draw("ACP");
            //gr1->Draw("AC*");
            gr1->Draw("ap");

            //..Plot <<3>>_532
            TGraphErrors* gr2 = new TGraphErrors(n, EtaGap, y2, 0, error2);
            gr2->SetLineColor(2);
            gr2->SetLineWidth(1);
            gr2->SetMarkerColor(4);
            gr2->SetMarkerStyle(4);
            gr2->SetTitle(Form("<<3>>_{5|-3,-2} 3-Particle correlations, Bin%0d", i));
            gr2->GetXaxis()->SetTitle("#Delta #eta");
            gr2->GetYaxis()->SetTitle("<<3>>_{5|-3,-2}");
            gr2->GetYaxis()->SetTitleOffset(1.4);
            //gr2->Draw("ACP");
            //gr2->Draw("AC*");
            gr2->Draw("ap");

            //..plot <<4>>_22,22
            TGraphErrors* gr3 = new TGraphErrors(n, EtaGap, y3, 0, error3);
            gr3->SetLineColor(2);
            gr3->SetLineWidth(1);
            gr3->SetMarkerColor(4);
            gr3->SetMarkerStyle(4);
            gr3->SetTitle(Form("<<4>>_{2,2|-2,-2} 4-Particle correlations, Bin%0d", i));
            gr3->GetXaxis()->SetTitle("#Delta #eta");
            gr3->GetYaxis()->SetTitle("<<4>>_{2,2|-2,-2}");
            gr3->GetYaxis()->SetTitleOffset(1.4);
            //gr3->Draw("ACP");
            //gr3->Draw("AC*");
            //gr3->Draw("ap");

            //..plot <<4>>_23,23
            TGraphErrors* gr4 = new TGraphErrors(n, EtaGap, y4, 0, error4);
            gr4->SetLineColor(2);
            gr4->SetLineWidth(1);
            gr4->SetMarkerColor(4);
            gr4->SetMarkerStyle(4);
            gr4->SetTitle(Form("<<4>>_{2,3|-2,-3} 4-Particle correlations, Bin%0d", i));
            gr4->GetXaxis()->SetTitle("#Delta #eta");
            gr4->GetYaxis()->SetTitle("<<4>>_{2,3|-2,-3}");
            gr4->GetYaxis()->SetTitleOffset(1.4);
            //gr4->Draw("ACP");
            //gr4->Draw("AC*");
            //gr4->Draw("ap");
   
        }
        if(!fileOutput) return;
        fileOutput->cd();
        gr1->Write(Form("hC34_eta_Dependent_Bin%0d", i));
        gr2->Write(Form("hC35_eta_Dependent_Bin%0d", i));
        gr3->Write(Form("hC42_eta_Dependent_Bin%0d", i));
        gr4->Write(Form("hC43_eta_Dependent_Bin%0d", i));
        
        //c->SaveAs("/Users/Helena/Desktop/Plots/Delta_eta_plots/test.png");
        cout << "i finished: " << i <<endl;
        //return;
    }

}



