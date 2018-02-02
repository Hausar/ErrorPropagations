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

void Delta_eta_dependent_Three_Four_partcorr() {


    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //..Create New file.root Eta-dependant of <<3>> and <<4>> plots
    TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Eta_Dependent/New_Delta_eta_dependent_3Part_4Part/New_Delta_eta_dependent_3part_4part_correlation.root","RECREATE");

    int n= 9;
    double EtaGap[9]= {0, 1, 2, 3, 4, 5, 6, 7, 8};
    double y1[9] = {};
    double y2[9] = {};
    double y3[9] = {};
    double y4[9] = {};

    //**************************************************************************
    //TEST:
    // TGraph* gr = new TGraph(n, EtaGap, hC22);
    // gr->SetLineColor(2);
    // gr->SetLineWidth(4);
    // gr->SetMarkerColor(4);
    // gr->SetMarkerStyle(21);
    // gr->SetTitle("v_{4}{2} 2-Particle correlations");
    // gr->GetXaxis()->SetTitle("#Delta #eta");
    // gr->GetYaxis()->SetTitle("v_{4}{2}");
    // gr->GetYaxis()->SetTitleOffset(1.4);
    // //gr->Draw("ACP");
    // //gr->Draw("AC*");

    //  TGraph* gr = new TGraph(n, EtaGap, hCV422);
    // gr->SetLineColor(2);
    // gr->SetLineWidth(4);
    // gr->SetMarkerColor(4);
    // gr->SetMarkerStyle(21);
    // gr->SetTitle("v_{4,22} Non-Linear Response");
    // gr->GetXaxis()->SetTitle("#Delta #eta");
    // gr->GetYaxis()->SetTitle("v_{4,22}");
    // gr->GetYaxis()->SetTitleOffset(1.4);
    // //gr->Draw("ACP");
    // //gr->Draw("AC*");

    // TGraph* gr = new TGraph(n, EtaGap, hCLinear);
    // gr->SetLineColor(2);
    // gr->SetLineWidth(4);
    // gr->SetMarkerColor(4);
    // gr->SetMarkerStyle(21);
    // gr->SetTitle("v_{4}^{L} Linear Response");
    // gr->GetXaxis()->SetTitle("#Delta #eta");
    // gr->GetYaxis()->SetTitle("v_{4}^{L}");
    // gr->GetYaxis()->SetTitleOffset(1.4);
    // //gr->Draw("ACP");
    // //gr->Draw("AC*");

    // TGraph* gr = new TGraph(n, EtaGap, y);
    // gr->SetLineColor(2);
    // gr->SetLineWidth(4);
    // gr->SetMarkerColor(4);
    // gr->SetMarkerStyle(21);
    // gr->SetTitle("Test");
    // gr->GetXaxis()->SetTitle("#Delta #eta");
    // gr->GetYaxis()->SetTitle("");
    // gr->GetYaxis()->SetTitleOffset(1.4);
    //gr->Draw("ACP");
    //gr->Draw("AC*");
    //**************************************************************************
    TFile* file = TFile::Open(
    "/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Cut_RawData_3particle_4particle/New_Rebin_Cut_Data_3_4_particle/New_Rebin_Cut_Data_3part_4part_histograms.root", "READ");

    for(int i=1; i < 6; i++) {
        for(int gap=0; gap < 9; gap++) {
            
            //..<<3>>_Rebin and <<4>>_Rebin:
            TString foo_34(TString::Format("hC34_Rebin_Gap0%0d", gap));
            TString foo_35(TString::Format("hC35_Rebin_Gap0%0d", gap));
            TString foo_42(TString::Format("hC42_Rebin_Gap0%0d", gap));
            TString foo_43(TString::Format("hC43_Rebin_Gap0%0d", gap));

            //..<<3>>_Rebin and <<4>>_Rebin:
            TH1D *hC34_gap = (TH1D*)file->Get(foo_34);
            TH1D *hC35_gap = (TH1D*)file->Get(foo_35);
            TH1D *hC42_gap = (TH1D*)file->Get(foo_42);
            TH1D *hC43_gap = (TH1D*)file->Get(foo_43);
            
            // //..V4:
            y1[gap] = hC34_gap->GetBinContent(i);   //??? for i loop?
            y2[gap] = hC35_gap->GetBinContent(i);
            y3[gap] = hC42_gap->GetBinContent(i);
            y4[gap] = hC43_gap->GetBinContent(i);

        
            //..V5:
            // TString foo_25(TString::Format("hC25_Rebin_Gap0%0d", gap));
            // TString foo_NL532(TString::Format("hCV532_Rebin_Gap0%0d", gap));
            // TString foo_LV5(TString::Format("hCLinearV5_Rebin_Gap0%0d", gap));
            
            // //..V5:
            // TH1D *hC25_gap = (TH1D*)file->Get(foo_25);
            // TH1D *hCV532_gap = (TH1D*)file->Get(foo_NL532);
            // TH1D *hCLinearV5_gap = (TH1D*)file->Get(foo_LV5);
            
            // y1[gap] = hC25_gap->GetBinContent(i); 
            // y2[gap] = hCV532_gap->GetBinContent(i);
            // y3[gap] = hCLinearV5_gap->GetBinContent(i);
            cout << "*********************************************" << endl;
            cout << "y1: " << y1[gap] << endl;
            cout << "y2: " << y2[gap] << endl;
            cout << "y3: " << y3[gap] << endl;
            cout << "y4: " << y4[gap] << endl;
            cout << "i: " << i <<endl;
            cout << "Gap: " << gap << endl;
            nbin_range = hC34_gap->GetXaxis()->FindBin(106) - hC34_gap->GetXaxis()->FindBin(5);
            cout << "Number of bins: " << nbin_range << endl; 
            cout << "**********************************************" << endl;
            //*********************************************************************
            // //..V4
            // TGraph* gr1 = new TGraph(n, EtaGap, y1);
            // gr1->SetLineColor(2);
            // gr1->SetLineWidth(4);
            // gr1->SetMarkerColor(4);
            // gr1->SetMarkerStyle(21);
            // gr1->SetTitle(TString::Format("v_{4}{2} 2-Particle correlations_Bin%0d", i));
            // gr1->GetXaxis()->SetTitle("#Delta #eta");
            // gr1->GetYaxis()->SetTitle("v_{4}{2}");
            // gr1->GetYaxis()->SetTitleOffset(1.4);
            // gr1->Draw("ACP");
            // //gr1->Draw("AC*");

            // TGraph* gr2 = new TGraph(n, EtaGap, y2);
            // gr2->SetLineColor(2);
            // gr2->SetLineWidth(4);
            // gr2->SetMarkerColor(4);
            // gr2->SetMarkerStyle(21);
            // gr2->SetTitle(Form("v_{4,22} Non-Linear Response, Bin%0d", i));
            // gr2->GetXaxis()->SetTitle("#Delta #eta");
            // gr2->GetYaxis()->SetTitle("v_{4,22}");
            // gr2->GetYaxis()->SetTitleOffset(1.4);
            // gr2->Draw("ACP");
            // //gr2->Draw("AC*");


            // TGraph* gr3 = new TGraph(n, EtaGap, y3);
            // gr3->SetLineColor(2);
            // gr3->SetLineWidth(4);
            // gr3->SetMarkerColor(4);
            // gr3->SetMarkerStyle(21);
            // gr3->SetTitle(Form("v_{4}^{L} Linear Response, Bin%0d", i));
            // gr3->GetXaxis()->SetTitle("#Delta #eta");
            // gr3->GetYaxis()->SetTitle("v_{4}^{L}");
            // gr3->GetYaxis()->SetTitleOffset(1.4);
            // gr3->Draw("ACP");
            // //gr3->Draw("AC*");
            
  
            //*********************************************************************
            // //..V5
            
            TGraph* gr1 = new TGraph(n, EtaGap, y1);
            gr1->SetLineColor(2);
            gr1->SetLineWidth(4);
            gr1->SetMarkerColor(4);
            gr1->SetMarkerStyle(21);
            gr1->SetTitle(TString::Format("<<3>>_{4|-2,-2} 3-Particle correlations, Bin%0d", i));
            gr1->GetXaxis()->SetTitle("#Delta #eta");
            gr1->GetYaxis()->SetTitle("<<3>>_{4|-2,-2}");
            gr1->GetYaxis()->SetTitleOffset(1.4);
            gr1->Draw("ACP");
            //gr1->Draw("AC*");

            TGraph* gr2 = new TGraph(n, EtaGap, y2);
            gr2->SetLineColor(2);
            gr2->SetLineWidth(4);
            gr2->SetMarkerColor(4);
            gr2->SetMarkerStyle(21);
            gr2->SetTitle(Form("<<3>>_{5|-3,-2} 3-Particle correlations, Bin%0d", i));
            gr2->GetXaxis()->SetTitle("#Delta #eta");
            gr2->GetYaxis()->SetTitle("<<3>>_{5|-3,-2}");
            gr2->GetYaxis()->SetTitleOffset(1.4);
            gr2->Draw("ACP");
            //gr2->Draw("AC*");


            TGraph* gr3 = new TGraph(n, EtaGap, y3);
            gr3->SetLineColor(2);
            gr3->SetLineWidth(4);
            gr3->SetMarkerColor(4);
            gr3->SetMarkerStyle(21);
            gr3->SetTitle(Form("<<4>>_{2,2|-2,-2} 4-Particle correlations, Bin%0d", i));
            gr3->GetXaxis()->SetTitle("#Delta #eta");
            gr3->GetYaxis()->SetTitle("<<4>>_{2,2|-2,-2}");
            gr3->GetYaxis()->SetTitleOffset(1.4);
            gr3->Draw("ACP");
            //gr3->Draw("AC*");

            TGraph* gr4 = new TGraph(n, EtaGap, y4);
            gr4->SetLineColor(2);
            gr4->SetLineWidth(4);
            gr4->SetMarkerColor(4);
            gr4->SetMarkerStyle(21);
            gr4->SetTitle(Form("<<4>>_{2,3|-2,-3} 4-Particle correlations, Bin%0d", i));
            gr4->GetXaxis()->SetTitle("#Delta #eta");
            gr4->GetYaxis()->SetTitle("<<4>>_{2,2|-2,-2}");
            gr4->GetYaxis()->SetTitleOffset(1.4);
            gr4->Draw("ACP");
            //gr4->Draw("AC*");
   
        }
        if(!fileOutput) return;
        fileOutput->cd();
        gr1->Write(Form("<<3>>_{4|-2,-2} 3-Particle correlations, Bin%0d", i));
        gr2->Write(Form("<<3>>_{5|-3,-2} 3-Particle correlations, Bin%0d", i));
        gr3->Write(Form("<<4>>_{2,2|-2,-2} 4-Particle correlations, Bin%0d", i));
        gr4->Write(Form("<<4>>_{2,3|-2,-3} 4-Particle correlations, Bin%0d", i));
        
        // if(!fileOutput2) return;
        // fileOutput2->cd();
        // gr1->Write(Form("EtaDependent_V5_2particle_plots_Bin%0d", i));
        // gr2->Write(Form("EtaDependent_V5_NL532_plots_Bin%0d", i));
        // gr3->Write(Form("EtaDependent_V5_Linear_plots_Bin%0d", i));
        //c->SaveAs("/Users/Helena/Desktop/Plots/Delta_eta_plots/test.png");
        cout << "i finished: " << i <<endl;
        //return;
    }

}



