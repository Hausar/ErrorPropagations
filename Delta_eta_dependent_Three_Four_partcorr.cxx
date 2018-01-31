//Macro To Calculate the Final results for plot vs. Delta_EtaGap:
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
    double Bin_value_v422;
    double Bin_value_hC22;
    double Bin_value_hCLinear;

    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();


    //..Root.file for all Eta-dependant plots
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Eta_Dependent/NewCondition_Delta_eta_dependent_V4L_NL422_V4_2part.root","RECREATE");

    TFile* fileOutput2 = new TFile(,"RECREATE");

    int n= 9;
    double EtaGap[9]= {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8};
    double y1[9] = {};
    double y2[9] = {};
    double y3[9] = {};
    //double hC22 [9]= {0.0301489, 0.0275432, 0.0242499, 0.0211225, 0.0185883, 0.0169007, 0.0152636, 0.0138636, 0.0127156};
    //double hCV422 [9] = {0.0171917, 0.0157672, 0.0144088, 0.0136457, 0.0136395, 0.0125566, 0.0135752, 0.0346021, 0.0334225};
    //double hCLinear [9] = {0.0263081, 0.0226898, 0.0203149, 0.0186658, 0.0160822, 0.0134485, 0.0136349, 0.0118987, 0.0118619};
    
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
    // TFile* file = TFile::Open(
    // "/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_Rebin_NewCondition_V4/Rebin_V4_Linear_NL_histograms_NewCondition.root", "READ");

    TFile* file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/LHC16q_CENT_SDD_0Gap_2_08Gap_FullGaps.root", "READ");

    for(int i=1; i<11; i++) {
        for(int gap=0; gap < 9; gap++) {
            
            // //..V4:
            // TString foo_22(TString::Format("hC22_Rebin_Gap0%0d", gap));
            // TString foo_NL422(TString::Format("hCV422_Rebin_Gap0%0d", gap));
            // TString foo_LV4(TString::Format("hCLinear_Rebin_Gap0%0d", gap));
            
            // //..V4:
            // TH1D *hC22_gap = (TH1D*)file->Get(foo_22);
            // TH1D *hCV422_gap = (TH1D*)file->Get(foo_NL422);
            // TH1D *hCLinear_gap = (TH1D*)file->Get(foo_LV4);
            
            // //..V4:
            // y1[gap] = hC22_gap->GetBinContent(i);
            // y2[gap] = hCV422_gap->GetBinContent(i);
            // y3[gap] = hCLinear_gap->GetBinContent(i);

        
            //..V5:
            TString foo_25(TString::Format("hC25_Rebin_Gap0%0d", gap));
            TString foo_NL532(TString::Format("hCV532_Rebin_Gap0%0d", gap));
            TString foo_LV5(TString::Format("hCLinearV5_Rebin_Gap0%0d", gap));
            
            //..V5:
            TH1D *hC25_gap = (TH1D*)file->Get(foo_25);
            TH1D *hCV532_gap = (TH1D*)file->Get(foo_NL532);
            TH1D *hCLinearV5_gap = (TH1D*)file->Get(foo_LV5);
            
            y1[gap] = hC25_gap->GetBinContent(i);
            y2[gap] = hCV532_gap->GetBinContent(i);
            y3[gap] = hCLinearV5_gap->GetBinContent(i);

            cout << "y: " << y1[gap] << endl;
            cout << "i: " << i <<endl;
            cout << "Gap: " << gap << endl;
            
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
            gr1->SetTitle(TString::Format("v_{5}{2} 2-Particle correlations_Bin%0d", i));
            gr1->GetXaxis()->SetTitle("#Delta #eta");
            gr1->GetYaxis()->SetTitle("v_{5}{2}");
            gr1->GetYaxis()->SetTitleOffset(1.4);
            gr1->Draw("ACP");
            //gr1->Draw("AC*");

            TGraph* gr2 = new TGraph(n, EtaGap, y2);
            gr2->SetLineColor(2);
            gr2->SetLineWidth(4);
            gr2->SetMarkerColor(4);
            gr2->SetMarkerStyle(21);
            gr2->SetTitle(Form("v_{5,32} Non-Linear Response, Bin%0d", i));
            gr2->GetXaxis()->SetTitle("#Delta #eta");
            gr2->GetYaxis()->SetTitle("v_{5,32}");
            gr2->GetYaxis()->SetTitleOffset(1.4);
            gr2->Draw("ACP");
            //gr2->Draw("AC*");


            TGraph* gr3 = new TGraph(n, EtaGap, y3);
            gr3->SetLineColor(2);
            gr3->SetLineWidth(4);
            gr3->SetMarkerColor(4);
            gr3->SetMarkerStyle(21);
            gr3->SetTitle(Form("v_{5}^{L} Linear Response, Bin%0d", i));
            gr3->GetXaxis()->SetTitle("#Delta #eta");
            gr3->GetYaxis()->SetTitle("v_{5}^{L}");
            gr3->GetYaxis()->SetTitleOffset(1.4);
            gr3->Draw("ACP");
            //gr3->Draw("AC*");

            
            
        }
        // if(!fileOutput) return;
        // fileOutput->cd();
        // gr1->Write(Form("EtaDependent_V4_2particle_plots_Bin%0d", i));
        // gr2->Write(Form("EtaDependent_V4_NL422_plots_Bin%0d", i));
        // gr3->Write(Form("EtaDependent_V4_Linear_plots_Bin%0d", i));
        
        if(!fileOutput2) return;
        fileOutput2->cd();
        gr1->Write(Form("EtaDependent_V5_2particle_plots_Bin%0d", i));
        gr2->Write(Form("EtaDependent_V5_NL532_plots_Bin%0d", i));
        gr3->Write(Form("EtaDependent_V5_Linear_plots_Bin%0d", i));
        //c->SaveAs("/Users/Helena/Desktop/Plots/Delta_eta_plots/test.png");
        cout << "i finished: " << i <<endl;
        //return;
    }

}



