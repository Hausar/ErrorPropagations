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

    //hC42_eta_Dependent_Bin3->Draw();
    TF1 *f = new TF1("f", "[0] + [1] * x + [2]* x * x");
    f->SetParameters(0.35, 0.2, 0.4);
    hC34_eta_Dependent_Bin1->GetXaxis()->SetLimits(0, 2);
    hC34_eta_Dependent_Bin1->Fit(f);
    hC34_eta_Dependent_Bin1->Draw("AL");

    //..It works only for data points:
    // hC34_eta_Dependent_Bin1->Fit("pol3");
    // hC34_eta_Dependent_Bin1->Draw("AL");
    // hC34_eta_Dependent_Bin1->GetXaxis()->SetLimits(0, 2);
    // hC34_eta_Dependent_Bin1->Draw("AL");
    //**********************************************************


}