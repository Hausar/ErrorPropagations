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

void Fit_Delta_eta_3part_4part() {

    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //..Create a file.root to save the output
    // TFile *fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Fit_Eta_Dependent_3part_4_part/", "RECREATE");

    //..Open the file.root:
    TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Eta_Dependent/New_Delta_eta_dependent_3Part_4Part/ErrorBar_Delta_eta_dependent_3part_4part_correlation.root","READ");


    //..Plot 1/x :
    TF1 *f1 = new TF1("f1", "[0]* 1/(x-[1]) + [2]", 0, 3);
    f1->SetParameter(0, 0.0005);  // par a control the y-axis is ok now!
    f1->SetParameter(1, -0.83);  // par x0 control the position to left and right
    f1->SetParameter(2, -0.0002);   //par b, change position up and down "lodret"
    f1->SetLineColor(kRed); 
    f1->SetLineStyle(2);
    //f1->SetMinimum(0.);
    //f1->SetMaximum(0.0004);
    // f1->GetYaxis()->SetRangeUser(0, 0.04);

    // TF1 *f = new TF1("f", "[0] + [1] * x + 1/sin(x)");
    // f->SetParameters(0.35, 0.3, 0.1);
    // hC34_eta_Dependent_Bin1->GetXaxis()->SetLimits(0, 2);
    //hC34_eta_Dependent_Bin1->Fit("f1");
    //f1->Draw();
    // hC34_eta_Dependent_Bin1->Draw("AL");

    //hC34_eta_Dependent_Bin1->GetYaxis()->SetRangeUser(0, 0.0001);
    //hC34_eta_Dependent_Bin1->Draw("same");


    //..exponential fit:
    TF1 *f2 = new TF1("f2", "[0]* exp(-x-[1]) + [2]", 0, 3);
    f2->SetParameter(0, 0.0024);  // par a control the y-axis is ok now!
    f2->SetParameter(1, 1.6);  // par x0 control the position to left and right
    f2->SetParameter(2, -0.14);   //par b, change position up and down "lodret"
    f2->SetLineColor(kRed); 
    f2->SetLineStyle(2);
    //f1->SetMinimum(0.);
    //f1->SetMaximum(0.0004);
    // f1->GetYaxis()->SetRangeUser(0, 0.04);

    // //..It works only for data points:
    // hC34_eta_Dependent_Bin1->Fit("pol3");
    // hC34_eta_Dependent_Bin1->Draw("AL");
    // hC34_eta_Dependent_Bin1->GetXaxis()->SetLimits(0, 2);
    // hC34_eta_Dependent_Bin1->Draw("AL");
    // //**********************************************************


}