//..This macro is made for fit the correlations of 3-particle and 4-particle seperately. 

#include <TF1.h>
#include <TFile.h>
#include <TMath.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TProfile.h>
#include <TComplex.h>
#include <iostream>
using namespace std; 

void Thesis_Fit_Delta_dependent() {

    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //..Create an empty histogram:
    
    TH1D *hist_new = new TH1D("hist_new", "The 3-particle correlation #eta dependent", 30, 0, 3); //this is just define a histogram which will fill the data of Chi_532.
    hist_new->Sumw2();
    hist_new->SetStats(0);
    hist_new->GetYaxis()->SetRangeUser(-0.00005, 0.06e-3);
    hist_new->Draw();

    // int n= 21;
    // double EtaGap[21]= {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0};
    // double y1[21] = {};
    // double error1 [21] = {};

    // TGraphErrors* gr = new TGraphErrors(n, EtaGap, y1, 0, error1);
    // gr->SetLineColor(2);
    // gr->SetLineWidth(1);
    // gr->SetMarkerColor(4);
    // gr->SetMarkerStyle(21);
    // gr->SetTitle("");
    // gr->GetXaxis()->SetTitle("#Delta #eta");
    // gr->GetYaxis()->SetTitle("<<4>>_{2,2|-2,-2}");
    // gr->GetYaxis()->SetTitleOffset(1.4);
    // //gr->Draw("ACP");
    // //gr->Draw("AC*");
    // gr->Draw("ap");


    //..Create a file.root to save the output
    // TFile *fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Fit_Eta_Dependent_3part_4_part/", "RECREATE");

    //..Open the file.root:
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Eta_Dependent/New_Delta_eta_dependent_3Part_4Part/ErrorBar_Delta_eta_dependent_3part_4part_correlation.root","READ");

    TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Fit_Eta_Dependent_3part_4_part_Macros/Fit_Delta_eta_3part_4part_Correlations/Thesis_Delta_eta_dependent_output/thesis_Delta_eta_dependent_3part_4part_correlation.root","READ");

    // //..Plot 1/x :
    // // TF1 *f1 = new TF1("f1", "[0]* 1/(x-[1]) + [2]", 0, 3);
    // // f1->SetParameter(0, 0.0005);  // par a control the y-axis is ok now!
    // // f1->SetParameter(1, -0.83);  // par x0 control the position to left and right
    // // f1->SetParameter(2, -0.0002);   //par b, change position up and down "lodret"
    // // f1->SetLineColor(kRed); 
    // // f1->SetLineStyle(2);
    // //f1->SetMinimum(0.);
    // //f1->SetMaximum(0.0004);
    // // f1->GetYaxis()->SetRangeUser(0, 0.04);

    // // TF1 *f = new TF1("f", "[0] + [1] * x + 1/sin(x)");
    // // f->SetParameters(0.35, 0.3, 0.1);
    // // hC34_eta_Dependent_Bin1->GetXaxis()->SetLimits(0, 2);
    // //hC34_eta_Dependent_Bin1->Fit("f1"); //
    // //f1->Draw(); //
    // // hC34_eta_Dependent_Bin1->Draw("AL");

    // //hC34_eta_Dependent_Bin1->GetYaxis()->SetRangeUser(0, 0.0001);
    // //hC34_eta_Dependent_Bin1->Draw("same"); //

    // //..<<4>>:
    // TF1 *f1 = new TF1("f1", "([0]* 1/(x-[1])) + ([2] * x + [3])", 0., 1.);
    // //TF1 *f1 = new TF1("f1", "TMath::Exp(-x)* [0] + [1]", 0, 1);
    // f1->SetParameter(0, 0.0004);  // par a control the y-axis is ok now!
    // f1->SetParameter(1, -0.0083);  // par x0 control the position to left and right
    // f1->SetParameter(2, +0.0002);   //par b, change position up and down "lodret"
    // f1->SetParameter(3, 0.0001);
    // f1->SetLineColor(kRed); 
    // f1->SetLineStyle(2);
    // //f1->SetMinimum(0.);
    // //f1->SetMaximum(0.0004);
    // //hC42_eta_Dependent_Bin1->Fit("f1"); 
    // //f1->Draw();
    // //hC42_eta_Dependent_Bin1->Draw("same");
    // //hC42_eta_Dependent_Bin2->Draw();

    // //hC34_eta_Dependent_Bin1->GetYaxis()->SetRangeUser(0, 0.0001);
    // //hC34_eta_Dependent_Bin1->Draw("same"); //

    // //..exponential fit:
    // TF1 *f2 = new TF1("f2", "[0]* TMath::Exp(-x-[1]) + [2]", 0, 3);
    // f2->SetParameter(0, 0.0036);  // par a control the y-axis is ok now!
    // f2->SetParameter(1, 2);  // par x0 control the position to left and right
    // f2->SetParameter(2, -0.00013);   //par b, change position up and down "lodret"
    // f2->SetLineColor(kRed); 
    // f2->SetLineStyle(2);
    //f1->SetMinimum(0.);
    //f1->SetMaximum(0.0004);
    //hC34_eta_Dependent_Bin1->Fit("f2");
    //hC42_eta_Dependent_Bin1->Fit("f2");
    //f2->Draw();
    //hC34_eta_Dependent_Bin1->Draw("same");
    //hC42_eta_Dependent_Bin1->Draw("same");
    
    // //..It works only for data points:
    TF1 *f1 = new TF1("f1", "expo", 0, 3);
    hC35_eta_Dependent_Bin4->Fit("f1");

    // TF1 *f = new TF1("f","expo",0.0,10);
    // hC34_eta_Dependent_Bin4->Fit(f,"R");
    // //hC34_eta_Dependent_Bin2->Draw("AL");
    //hC34_eta_Dependent_Bin2->GetXaxis()->SetLimits(0, 3);
    //hC34_eta_Dependent_Bin4->GetXaxis()->SetRangeUser(0, 3);
    hC35_eta_Dependent_Bin4->Draw("same");
    f1->Draw("same");
    c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Delta_eta_dependent_plots/hC35_eta_Dependent_Bin4.png");

    // //**********************************************************


}