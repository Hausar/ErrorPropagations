
//Macro To Calculate the Error Propagation:
//Root file:
#include <TFile.h>
#include <TMath.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TProfile.h>
#include <TComplex.h>
#include "TLatex.h"
#include <iostream>
using namespace std;  

void Chi532() {
    double BinValue_3Particle_Correlation = 0.0;
    double BinValue_22Particle_Correlation = 0.0;
    double BinValue_23Particle_Correlation = 0.0;
    double Sample_BinValue_3Particle_Correlation = 0.0;
    double Sample_BinValue_22Particle_Correlation = 0.0;
    double Sample_BinValue_23Particle_Correlation = 0.0;
    double Valuesqrt_22Particle_Correlation = 0.0;
    double Valuesqrt_23Particle_Correlation = 0.0;
    double Sample_Valuesqrt_22Particle_Correlation = 0.0;
    double Sample_Valuesqrt_23Particle_Correlation = 0.0;
    double Sample_BinValue_25Particle_Correlation = 0.0;
    double Sample_BinValue_35Particle_Correlation = 0.0;
    double Sample_Value_sqrt_25particle_correlation = 0.0;
    double Sample_Value_sqrt_22particle_correlation = 0.0;
    double Sample_Value_sqrt_23particle_correlation = 0.0;
    double Valuesqrt_25Particle_Correlation = 0.0;
    double BinValue_25Particle_Correlation = 0.0;
    double BinValue_35Particle_Correlation = 0.0;
    double V532;
    double V532_Sample;
    double Chi532;
    double Chi532_Sample;

    double sigma_z1;
    double BinValue42;
    double BinValue_sample;
    double BinValue42_Sample;
    double BinValue25_Sample; 
    double BinValue25; 
    double Valuesqrt_2Particle_Sample;
    double Valuesqrt_4Particle_Sample;
    double V4_BinValue_hC22; 
    double NL_BinValue_hCV422;
    double Linear;
    double Linear_value; 
    double Linear_value_sample;
    double final_error;
    double Linear_Error; 
    int N = 10.;
    double fsample_Linear; 

    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    gStyle->SetOptStat(kFALSE);
    gStyle->SetLineStyleString(7,"400 200");
    

    TH1D *hC22 = new TH1D("hC22", " V5{2},  #sqrt{< v_{5}^{2} >}", 200, 0, 200); //this is just define a histogram which will fill the data.
    hC22->Sumw2();
    
    //TH1D *hC52 = new TH1D("hC52", " #sqrt{< v_{2}^{2} >}", 200, 0, 200); //this is just define a histogram 
	//hC52->Sumw2();

    TH1D *hCV532 = new TH1D("hCV532", "The Non-Linear Response, v_{5,32} = <<3>> / #sqrt{ < v_{3}^{2} v_{2}^{2} > }", 200, 0, 200); //this is just define a histogram which will fill the data of V422.
    hCV532->Sumw2();
 
    TH1D *hCLinear = new TH1D("hCLinear", " The Linear Response V5^{L} ", 200, 0, 200); //this is just define a histogram which will fill the data.
    hCLinear->Sumw2();

    TH1D *hChi532 = new TH1D("hChi532", "The Non-Linear Coefficient, #chi_{5,32}", 200, 0, 200); //this is just define a histogram which will fill the data of Chi_532.
    hChi532->Sumw2();

    //Open the root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/Run_wNUA_Wo_NUA/LHC16q_CENT_SDD_W_NUA_3particle_02Gap.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("MyTaskResults");
    TList *list = (TList*)dir->Get("Flow_Refs_MyTaskResults");
    
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35");  //..<<3>>_{5|-3,-2}
    
    TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25_Gap");  //..V5{2}
    TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22_Gap");  //..v2^{2}
    TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23_Gap");  //..v3^{2}
    TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35_Gap");  //..<<3>>_{5|-3,-2}

    
    //..Projection on Xaxis:
    // TH1D *h1 = Cn24->ProjectionX("h1");
    // TH1D *h2 = Cn42->ProjectionX("h2");
    // TH1D *h3 = Cn34->ProjectionX("h3");
    
    //**************************************************************************
    //..Loop over fSample for Error propagation for Non-Linear Response:

    for (int j=1; j<201; j++) {
        double error = 0.0;
        for (int i = 1; i < 11; i++) {

            // TString bar(TString::Format("fTprof35_number%dNtrks1bin", i));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar);
            // TString foo(TString::Format("fTprof22_number%dNtrks1bin", i));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo);
            // TString foo2(TString::Format("fTprof23_number%dNtrks1bin", i));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo2);

            TString bar(TString::Format("fTprof35_number%dGapNtrks1bin", i));	
            TProfile *prof35 = (TProfile*)list->FindObject(bar);
            TString foo(TString::Format("fTprof22_number%dGapNtrks1bin", i));	
            TProfile *prof22 = (TProfile*)list->FindObject(foo);
            TString foo2(TString::Format("fTprof23_number%dGapNtrks1bin", i));	
            TProfile *prof23 = (TProfile*)list->FindObject(foo2);
                    
            Sample_BinValue_3Particle_Correlation = prof35->GetBinContent(j);
            Sample_BinValue_22Particle_Correlation = prof22->GetBinContent(j);
            Sample_BinValue_23Particle_Correlation = prof23->GetBinContent(j);

            BinValue_3Particle_Correlation = Cn35->GetBinContent(j);
            BinValue_22Particle_Correlation = Cn22->GetBinContent(j);
            BinValue_23Particle_Correlation = Cn23->GetBinContent(j);

            if (Sample_BinValue_22Particle_Correlation > 0  && BinValue_22Particle_Correlation > 0  &&  Sample_BinValue_23Particle_Correlation > 0 && BinValue_23Particle_Correlation > 0 &&  BinValue_3Particle_Correlation > 0 && Sample_BinValue_3Particle_Correlation > 0 ) {
            
                Valuesqrt_22Particle_Correlation = sqrt(BinValue_22Particle_Correlation);
                Valuesqrt_23Particle_Correlation = sqrt(BinValue_23Particle_Correlation);
                
                Sample_Valuesqrt_22Particle_Correlation = sqrt(Sample_BinValue_22Particle_Correlation);
                Sample_Valuesqrt_23Particle_Correlation = sqrt(Sample_BinValue_23Particle_Correlation);
                
                V532 = BinValue_3Particle_Correlation / (Valuesqrt_22Particle_Correlation * Valuesqrt_23Particle_Correlation );
                V532_Sample = Sample_BinValue_3Particle_Correlation / (Sample_Valuesqrt_22Particle_Correlation * Sample_Valuesqrt_23Particle_Correlation ); 

                //..Calculation for Chi_532:
                Chi532 = V532 / (Valuesqrt_22Particle_Correlation * Valuesqrt_23Particle_Correlation );
                Chi532_Sample = V532_Sample / (Sample_Valuesqrt_22Particle_Correlation * Sample_Valuesqrt_23Particle_Correlation);
                
                //error += pow(V532_Sample - V532, 2);
                error += pow(Chi532_Sample - Chi532, 2);

            }
            else continue; 
            // cout << "prof34: " << bar << endl;
            // cout << "prof42: " << foo << endl;
            // cout << "Sample_BinValue_3Particle_Correlation: " << Sample_BinValue_3Particle_Correlation << endl;
            // cout << "Sample_BinValue_4Particle_Correlation: " << Sample_BinValue_4Particle_Correlation << endl;
            // cout << "bin: "  << j << endl;
            // cout << "BinValue_3Particle_Correlation: " << BinValue_3Particle_Correlation << endl;
            // cout << "BinValue_4Particle_Correlation: " << BinValue_4Particle_Correlation << endl;
            // cout << "Valuesqrt_4Particle_Correlation: " << Valuesqrt_4Particle_Correlation << endl;  
            // cout << "V422:   "   << V422 << endl;
            // cout << "V422_Sample: " << V422_Sample << endl;
            // cout << "error: " << error << endl;
        }
        sigma_z1 = sqrt(error/ (N * N) );
        //cout << "sigma: " << sigma_z1 << endl;
        hChi532->SetBinContent(j, Chi532);
        hChi532->SetBinError(j, sigma_z1);

        }

    //..Plot the Histograms


    //h1->SetMarkerStyle(23);
    //h1->SetMarkerColorAlpha(kRed, 4.5);  
    //h1->Draw();

    //h2->SetMarkerStyle(23);
    //h2->SetMarkerColorAlpha(kRed, 4.5);  
    //h2->Draw();

    // h3->SetMarkerStyle(23);
    // h3->SetMarkerColorAlpha(kRed, 4.5);
    // h3->Divide(hC42);    
    // h3->Draw();
    //h3->Divide(hC22);

    //hChi532->SetMarkerStyle(21);
    //hChi532->SetMarkerColorAlpha(kBlack, 4.5);
    hChi532->GetYaxis()->SetRangeUser(0., 30.);
    hChi532->GetXaxis()->SetRangeUser(0., 140);
    hChi532->SetMarkerSize(1.);
    hChi532->Draw("same");
    //c->BuildLegend();
    hChi532->SetTitle("Non-Linear coefficient #chi_{5,32} of v_{5,32} for pPb at 5.02 TeV");
    hChi532->SetMarkerStyle(kFullTriangleUp); 
    hChi532->SetMarkerColor(kBlue+1);
    hChi532->GetYaxis()->SetTitleOffset(1.4);
    //hChi532->GetYaxis()->CenterTitle(true);
    hChi532->GetYaxis()->SetTitle("#chi_{5,32}");

    hChi532->GetXaxis()->SetTitleOffset(1.4);
    //hChi532->GetXaxis()->CenterTitle(true);
    gStyle->SetTitleFontSize(0.2);
    hChi532->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    hChi532->SetFillColor(kBlue-9);
    c->Update();
    
    TLatex latex;
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(10,20,"#sqrt{s_{NN}} = 5.02 TeV");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(10,18,"|#Delta #eta| < 0.8");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(10,16," 0.2 < p_{T} < 3.0");

    TLegend *leg = new TLegend(0.4, 0.7, 0.85, 0.85); 
    leg->AddEntry(hChi532, "#chi_{5,32}", "fp");
    leg->Draw("same");
    
    leg->SetBorderSize(0);
    gStyle->SetTitleFontSize(0.2);

    // //..Create a root.file:
    TFile* fileOutput = new TFile("Chi422_Chi532_Gap02.root","UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hChi532->Write();
    return;

    // TFile* fileOutput = new TFile("V5_Linear_NonLinear_Response_WOGap.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC22->Write();
    // hCV532->Write();
    // hCLinear->Write();
    // return;
}   