
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

void Linear_caculation() {
    double BinValue_3Particle_Correlation;
    double BinValue_4Particle_Correlation;
    double Sample_BinValue_3Particle_Correlation;
    double Sample_BinValue_4Particle_Correlation;
    double Valuesqrt_4Particle_Correlation;
    double Sample_Valuesqrt_4Particle_Correlation;
    double V422;
    double V422_Sample;
    double sigma_z1;
    double BinValue42;
    double BinValue_sample;
    double BinValue42_Sample;
    double Valuesqrt_2Particle_Sample;
    double final_error;
    int N = 10.;
    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(19);
    c->cd();

    // TProfile *Tprofv422 = new TProfile ("Tprofv422", "C_{4}{2} = #sqrt{< v_{4}^{2} >}", 200, 0, 200);
    // Tprofv422->Sumw2(); 

    //TProfile *Tprof42 = new TProfile ("Tprof42", "C_{2}{4} = #sqrt{< v_{2}^{4} >}", 200, 0, 200);
    //Tprof42->Sumw2();
    
    TH1D *hTest = new TH1D("hTest", " TEST HISTOGRAM ", 200, 0, 200); //this is just define a histogram which will fill the data.
    hTest->Sumw2();


    TH1D *hC22 = new TH1D("hC22", " #sqrt{< v_{4}^{2} >}", 200, 0, 200); //this is just define a histogram which will fill the data.
    hC22->Sumw2();
    
    TH1D *hC42 = new TH1D("hC42", " #sqrt{<< v_{2}^{4} >>}", 200, 0, 200); //this is just define a histogram 
	hC42->Sumw2();

    TH1D *hCV422 = new TH1D("hCV422", " <<3>> / #sqrt{< v_{2}^{4} >}", 200, 0, 200); //this is just define a histogram which will fill the data of V422.
    hCV422->Sumw2();
 
    //Open the root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/LHC16q_CENT_SDD_W_NUA_3particle_correlation.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("MyTaskResults");
    TList *list = (TList*)dir->Get("Flow_Refs_MyTaskResults");
    
    TProfile *fc24 = (TProfile*)list->FindObject("fTprofC24");
    TProfile *fc42 = (TProfile*)list->FindObject("fTprofC42");  
    TProfile *fc34 = (TProfile*)list->FindObject("fTprofC34"); 
    
 
    //..Projection on Xaxis:
    TH1D *h1 = fc24->ProjectionX("h1");
    TH1D *h2 = fc42->ProjectionX("h2");
    TH1D *h3 = fc34->ProjectionX("h3");

    //****************************************************
    //// Loop to get sqrt of each bin in Tprofile of//////
    //     Cn{2} = <<2>> = < vn^2 > and //////////////////
    ////   Cn{4} = <<4>> = <vn^4> = <<4>> - 2 <<2>>^2 ////
    //*****************************************************
    // for(int i=1; i<201; i++)
    // {
    //     double error = 0.0;
    //     for(int sample=1; sample<11; sample++)
    //     {
    //         TString foo(TString::Format("fTprof42_number%dNtrks1bin", sample));	
    //         TProfile *fprof42 = (TProfile*)list->FindObject(foo);
    //         //TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42");
    //         BinValue42_Sample = fprof42->GetBinContent(i);
    //         BinValue42 = h2->GetBinContent(i); 

    //         if(BinValue42 > 0 && BinValue42_Sample > 0 ) {
    //             Valuesqrt_4Particle_Correlation = sqrt(BinValue42);
    //         }
    //         else continue;
    //         error += pow(BinValue42_Sample - BinValue42, 2);

    //         cout << "fsample: " << foo << endl;
    //         cout << "BinVlue42: " << BinValue42 << endl;
    //         cout << "BinVlue42_Sample: " << BinValue42_Sample << endl;
    //         cout << " Valuesqrt 4Particle: " << Valuesqrt_4Particle_Correlation << endl;
    //         cout << "error: " << error << endl; 
        
    //     }
    //     final_error = sqrt(error / (N * N) );
    //     cout << "final_error: " << final_error << endl;
    //     hC42->SetBinContent(i, Valuesqrt_4Particle_Correlation);
    //     hC42->SetBinError(i, final_error);

    // }
    //*************************************************************************
    //.. Loop for get the v4 = sqrt(<<2>>_{4|-4})
    for(int i=1; i < 201; i++)
    {
        double error = 0.0;
        for(int sample =1; sample < 11; sample++)
        {
            TString foo(TString::Format("fTprof24_number%dNtrks1bin", sample));
            TProfile *fprof24 = (TProfile*)list->FindObject(foo);

            BinValue24_Sample = fprof24->GetBinContent(i);
            BinValue24 = fc24->GetBinContent(i);
            if(BinValue24_Sample > 0 && BinValue24 > 0 ) {
                Valuesqrt_2Particle_Correlation = sqrt(BinValue24);
                Valuesqrt_2Particle_Sample = sqrt(BinValue24_Sample); 
            }
            else continue;
            error += pow(Valuesqrt_2Particle_Sample - Valuesqrt_2Particle_Correlation, 2);
            cout << "BinValue24_Sample: " << BinValue24_Sample << endl;
            cout << "BinValue24: " << BinValue24 << endl;
            cout << "error: " << error << endl;
        }
        final_error = sqrt(error/ (N * N) );
        cout << "final error: " << final_error << endl;
        hC22->SetBinContent(i, Valuesqrt_2Particle_Correlation);
        hC22->SetBinError(i, final_error);
    }
    

    // //..Loop over fSample for Error propagation:

    for (int j=1; j<201; j++) {
        double error = 0.0;
        for (int i = 1; i < 11; i++) {

            TString bar(TString::Format("fTprof34_number%dNtrks1bin", i));	
            TProfile *prof34 = (TProfile*)list->FindObject(bar);
            TString foo(TString::Format("fTprof42_number%dNtrks1bin", i));	
            TProfile *prof42 = (TProfile*)list->FindObject(foo);

            TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34"); 
            TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42");
            
            Sample_BinValue_3Particle_Correlation = prof34->GetBinContent(j);
            Sample_BinValue_4Particle_Correlation = prof42->GetBinContent(j);
            
            BinValue_3Particle_Correlation = Cn34->GetBinContent(j);
            BinValue_4Particle_Correlation = Cn42->GetBinContent(j);
            
            if (Sample_BinValue_4Particle_Correlation > 0  && BinValue_4Particle_Correlation > 0 && BinValue_3Particle_Correlation > 0 && Sample_BinValue_3Particle_Correlation > 0 ) {
            
                Valuesqrt_4Particle_Correlation = sqrt(BinValue_4Particle_Correlation);
                Sample_Valuesqrt_4Particle_Correlation = sqrt(Sample_BinValue_4Particle_Correlation);
                
                V422 = BinValue_3Particle_Correlation / Valuesqrt_4Particle_Correlation;
                V422_Sample = Sample_BinValue_3Particle_Correlation / Sample_Valuesqrt_4Particle_Correlation; 
                
                error += pow(V422_Sample - V422, 2);

            }
            else continue; 
            cout << "prof34: " << bar << endl;
            cout << "prof42: " << foo << endl;
            cout << "Sample_BinValue_3Particle_Correlation: " << Sample_BinValue_3Particle_Correlation << endl;
            cout << "Sample_BinValue_4Particle_Correlation: " << Sample_BinValue_4Particle_Correlation << endl;
            cout << "bin: "  << j << endl;
            cout << "BinValue_3Particle_Correlation: " << BinValue_3Particle_Correlation << endl;
            cout << "BinValue_4Particle_Correlation: " << BinValue_4Particle_Correlation << endl;
            cout << "Valuesqrt_4Particle_Correlation: " << Valuesqrt_4Particle_Correlation << endl;  
            cout << "V422:   "   << V422 << endl;
            cout << "V422_Sample: " << V422_Sample << endl;
            cout << "error: " << error << endl;

            //fc42->Draw("EP");
            //Cn34->Draw();
            //Cn42->Draw();		
        }
        sigma_z1 = sqrt(error/ (N * N) );
        cout << "sigma: " << sigma_z1 << endl;
        //hC42->SetBinContent(j, Valuesqrt_4Particle_Correlation);
        //hC42->SetBinError(j, sigma_z1);
        //hC42->Draw();
        hCV422->SetBinContent(j, V422);
        hCV422->SetBinError(j, sigma_z1);
        
        }
    
    //************************************************************************
    //.. Test the Error, her is only for testing <<4>> error manually.
    // for (int i = 1; i < 201; i++)
	// {
    //     double error = 0.0;
	// 	for (int j=1; j<11; j++)
	// 	{
	// 		TString foo(TString::Format("fTprof42_number%dNtrks1bin", j));	
    //         TProfile *prof42 = (TProfile*)list->FindObject(foo);
    //         BinValue_sample = prof42->GetBinContent(i);
    //         BinValue_4Particle_Correlation = fc42->GetBinContent(i);

    //         cout << "BinValue_sample:  " << BinValue_sample << endl;
    //         cout << "BinValue 4Particle: " << BinValue_4Particle_Correlation << endl;
    //         cout << "first step:  " << foo << endl; 
    //         if (BinValue_sample > 0 && BinValue_4Particle_Correlation > 0)
    //             error += pow(BinValue_sample - BinValue_4Particle_Correlation, 2);
    //         else continue;
    //         }
    //     final_error = sqrt(error/ (N * N ));
    //     hTest->SetBinContent(i, BinValue_4Particle_Correlation);
    //     hTest->SetBinError(i, final_error);
	// 	//prof42->Draw("EP");  
    // }	
    //************************************************************************          
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
    
    // fc24->SetMarkerStyle(23);
    // fc24->SetMarkerColorAlpha(kRed, 4.5);
    // fc24->Draw("EP");
    
    // fc34->SetMarkerStyle(23);
    // fc34->SetMarkerColorAlpha(kRed, 4.5);
    // fc34->Draw("EP");
    
    // fc42->SetMarkerStyle(23);
    // fc42->SetMarkerColorAlpha(kRed, 4.5);
    // fc42->Draw("EP");
    
    //hC22->SetMarkerStyle(23);
    //hC22->SetMarkerColorAlpha(kRed, 4.5);
    hC22->Draw("EP");
    
    // hC42->SetMarkerStyle(23);
    // hC42->SetMarkerColorAlpha(kRed, 10.0);
	// hC42->Draw("EP");

    // hCV422->SetMarkerStyle(20);
    // hCV422->SetMarkerColorAlpha(kBlue, 0.35);
	// hCV422->Draw("same");

    c->BuildLegend();
    //hTest->Draw();
}