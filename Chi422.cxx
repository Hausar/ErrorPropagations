
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

void Chi422() {
    double BinValue_3Particle_Correlation = 0.0;
    double BinValue_4Particle_Correlation = 0.0;
    double BinValue_2Particle_Correlation = 0.0;
    double Sample_BinValue_3Particle_Correlation = 0.0;
    double Sample_BinValue_4Particle_Correlation = 0.0;
    double Valuesqrt_4Particle_Correlation = 0.0;
    double Valuesqrt_2Particle_Correlation = 0.0;
    double Sample_Valuesqrt_4Particle_Correlation = 0.0;
    double Sample_BinValue_2Particle_Correlation = 0.0;
    double V422;
    double V422_Sample;
    double sigma_z1;
    double BinValue42;
    double BinValue_sample;
    double BinValue42_Sample;
    double BinValue24_Sample; 
    double BinValue24; 
    double Valuesqrt_2Particle_Sample;
    double Valuesqrt_4Particle_Sample;
    double V4_BinValue_hC22; 
    int N = 10;
    double Chi422 = 0.0; 
    double Chi422_Sample = 0.0;   

    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(19);
    c->cd();
    
    TH1D *hC22 = new TH1D("hC22", " V4{2},  #sqrt{< v_{4}^{2} >}", 200, 0, 200); //this is just define a histogram which will fill the data.
    hC22->Sumw2();
    
    TH1D *hC42 = new TH1D("hC42", " #sqrt{< v_{2}^{4} >}, 4-particle correlations", 200, 0, 200); //this is just define a histogram 
	hC42->Sumw2();

    TH1D *hCV422 = new TH1D("hCV422", "The Non-Linear Response, v_{4,22} = <<3>> / #sqrt{< v_{2}^{4} >}", 200, 0, 200); //this is just define a histogram which will fill the data of V422.
    hCV422->Sumw2();
 
    TH1D *hCLinear = new TH1D("hCLinear", " The Linear Response V4^{L} ", 200, 0, 200); //this is just define a histogram which will fill the data.
    hCLinear->Sumw2();

    TH1D *hChi422 = new TH1D("hChi422", "The Non-Linear Coefficient, #Chi_{4,22} = v_{4,22} / #sqrt{< v_{2}^{4} >}", 200, 0, 200); //this is just define a histogram which will fill the data of Chi_422.
    hChi422->Sumw2();

    //Open the root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/Run_wNUA_Wo_NUA/LHC16q_CENT_SDD_W_NUA_3particle_02Gap.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("MyTaskResults");
    TList *list = (TList*)dir->Get("Flow_Refs_MyTaskResults");
    
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34"); 

    TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24_Gap");
    TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42_Gap");  
    TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34_Gap"); 
    
 
    //..Projection on Xaxis:
    TH1D *h1 = Cn24->ProjectionX("h1");
    TH1D *h2 = Cn42->ProjectionX("h2");
    TH1D *h3 = Cn34->ProjectionX("h3");

    //******************************************************************************
    //..Loop over fSample for Error propagation for Non-Linear Coefficient Chi_4,22:

    for (int j=1; j<201; j++) {
        double error = 0.0;
        for (int i = 1; i < 11; i++) {

            // TString bar(TString::Format("fTprof34_number%dNtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar);
            // TString foo(TString::Format("fTprof42_number%dNtrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo);

            TString bar(TString::Format("fTprof34_number%dGapNtrks1bin", i));	
            TProfile *prof34 = (TProfile*)list->FindObject(bar);
            TString foo(TString::Format("fTprof42_number%dGapNtrks1bin", i));	
            TProfile *prof42 = (TProfile*)list->FindObject(foo);

            
            Sample_BinValue_3Particle_Correlation = prof34->GetBinContent(j);
            Sample_BinValue_4Particle_Correlation = prof42->GetBinContent(j);
            
            BinValue_3Particle_Correlation = Cn34->GetBinContent(j);
            BinValue_4Particle_Correlation = Cn42->GetBinContent(j);
            
            if (Sample_BinValue_4Particle_Correlation > 0  && BinValue_4Particle_Correlation > 0 && BinValue_3Particle_Correlation > 0 && Sample_BinValue_3Particle_Correlation > 0 ) {
            
                Valuesqrt_4Particle_Correlation = sqrt(BinValue_4Particle_Correlation);
                Sample_Valuesqrt_4Particle_Correlation = sqrt(Sample_BinValue_4Particle_Correlation);
                
                V422 = BinValue_3Particle_Correlation / Valuesqrt_4Particle_Correlation;
                V422_Sample = Sample_BinValue_3Particle_Correlation / Sample_Valuesqrt_4Particle_Correlation; 

                //..Calculation for Chi_422:
                Chi422 = V422 / Valuesqrt_4Particle_Correlation;
                Chi422_Sample = V422_Sample / Sample_Valuesqrt_4Particle_Correlation;
                
                //error += pow(V422_Sample - V422, 2);
                error += pow(Chi422_Sample - Chi422, 2);

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
            //fc42->Draw("EP");
            //Cn34->Draw();
            //Cn42->Draw();		
            cout << "Chi422: " << Chi422 << endl;
            cout << "Chi422_Sample: " << Chi422_Sample << endl;
        }
        sigma_z1 = sqrt(error/ (N * N) );
        //cout << "sigma: " << sigma_z1 << endl;
        //hC42->SetBinContent(j, Valuesqrt_4Particle_Correlation);
        //hC42->SetBinError(j, sigma_z1);
        //hC42->Draw();
        // hCV422->SetBinContent(j, V422);
        // hCV422->SetBinError(j, sigma_z1);
        hChi422->SetBinContent(j, Chi422);
        hChi422->SetBinError(j, sigma_z1);
        
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
    
    // Cn24->SetMarkerStyle(23);
    // Cn24->SetMarkerColorAlpha(kRed, 4.5);
    // Cn24->Draw("EP");
    
    // Cn34->SetMarkerStyle(23);
    // Cn34->SetMarkerColorAlpha(kRed, 4.5);
    // Cn34->Draw("EP");
    
    // Cn42->SetMarkerStyle(23);
    // Cn42->SetMarkerColorAlpha(kRed, 4.5);
    // Cn42->Draw("EP");
    
    // hC22->SetMarkerStyle(20);
    // hC22->SetMarkerColorAlpha(kRed, 4.5);
    // //hC22->SetAxisRange(0., 110);
    // hC22->SetMarkerSize(1.);
    // hC22->SetXTitle("# of tracks");
    // //gStyle->SetOptStat(0);
    // hC22->Draw("same");
    
    // // hC42->SetMarkerStyle(21);
    // // hC42->SetMarkerColorAlpha(kBlack, 10.0);
	// // hC42->Draw("same");

    // hCV422->SetMarkerStyle(34);
    // hCV422->SetMarkerColorAlpha(kBlue, 0.45);
    // //hCV422->SetAxisRange(0., 110);
    // hCV422->SetMarkerSize(2.);
	// hCV422->Draw("same");
    
    // hCLinear->SetMarkerStyle(21);
    // hCLinear->SetMarkerColorAlpha(kBlack, 4.5);
    // //hCLinear->SetAxisRange(0., 110);
    // hCLinear->SetMarkerSize(1.);
    // hCLinear->Draw("same");
    // c->BuildLegend();

    hChi422->SetMarkerStyle(21);
    hChi422->SetMarkerColorAlpha(kBlack, 4.5);
    //hChi422->SetAxisRange(0., 110, "X");
    hChi422->GetYaxis()->SetRangeUser(0., 3.);
    hChi422->GetXaxis()->SetRangeUser(0., 140);
    hChi422->SetMarkerSize(1.);
    hChi422->Draw("same");
    c->BuildLegend();
    
    //..Create a root.file:
    TFile* fileOutput = new TFile("Chi422_Chi532_Gap02.root","RECREATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hChi422->Write();
    return;
    
    // TFile* fileOutput = new TFile("V4_Linear_NonLinear_Response_WOGap.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC22->Write();
    // hCV422->Write();
    // hCLinear->Write();
    // return;

}