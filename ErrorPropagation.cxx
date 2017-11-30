
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

void ErrorPropagation() {
    double valuesqrt;
    double BinValue;
    double error;
    double valuesqrt2;
    double BinValue2;
    double BinValueA;
    double BinValueB;
    double error2;
    double sigma_z1;
    double sigma_z2;
    double part1;
    double part2;
    double part3;
    double part11;
    double part22;
    double part33;
    double x_sqrt;
    double x_sqrt2;
    double subtraction; 
    double Ratio;
    double BinValue_sample;
    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(19);
    c->cd();

    // TProfile *Tprofv422 = new TProfile ("Tprofv422", "C_{4}{2} = #sqrt{< v_{4}^{2} >}", 200, 0, 200);
    // Tprofv422->Sumw2(); 

    //TProfile *Tprof42 = new TProfile ("Tprof42", "C_{2}{4} = #sqrt{< v_{2}^{4} >}", 200, 0, 200);
    //Tprof42->Sumw2();

    TH1D *hC22 = new TH1D("hC22", " #sqrt{< v_{4}^{2} >}", 200, 0, 200); //this is just define a histogram which will fill the data.
    hC22->Sumw2();
    
    TH1D *hC42 = new TH1D("hC42", " #sqrt{<< v_{2}^{4} >>}", 200, 0, 200); //this is just define a histogram 
	hC42->Sumw2();

    TH1D *hCV422 = new TH1D("hCV422", " #sqrt{< v_{4}^{2} >}", 200, 0, 200); //this is just define a histogram which will fill the data.
    hC22->Sumw2();

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

    //..Loop over fSample for Error propagation:
    error = 0.;
    int N = 10;
    for (int j=1; j<201; j++)
        for (int i = 1; i < 11; i++)
    {
        {
            TString foo(TString::Format("fTprof42_number%dNtrks1bin", i));	
            TProfile *fsample = (TProfile*)list->FindObject(foo);

            TString bar(TString::Format("fTprof34_number%dNtrks1bin", i));	
            TProfile *fsample2 = (TProfile*)list->FindObject(bar);

            TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42");
            TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34"); 
            
            BinValueA = Cn34->GetBinContent(j);
            BinValueB = Cn42->GetBinContent(j);
            valuesqrt = sqrt(BinValueB);
            Ratio = BinValueA / (valuesqrt);
            
            BinValue = fsample->GetBinContent(j);
            BinValue2 = fsample2->GetBinContent(j);
            BinValue_sample = BinValue / (BinValue2); 
            if (BinValue > 0 && BinValue2 > 0 && BinValueA > 0 && BinValueB > 0 ) {
                error += pow(BinValue_sample - Ratio, 2);

            }
            else continue; 
            
            cout << "fsample: " << foo << endl;
            cout << "BinValue: " << BinValue << endl;
            cout << "BinValue2: " << BinValue2 << endl;
            cout << "bin: "  << j << endl;
            cout << "error: " << error << endl;
            cout << "BinValueA: " << BinValueA << endl;
            cout << "BinValueB: " << BinValueB << endl;
            cout << "valuesqrt: " << valuesqrt << endl;  
            cout << "Ratio:   "   << Ratio << endl;
            fc42->Draw();		
        }
        sigma_z1 = sqrt(error/ (N*N) );
        cout << "sigma: " << sigma_z1 << endl;
        hC42->SetBinContent(j, valuesqrt);
        hC42->SetBinError(j, sigma_z1);
        hCV422->SetBinContent(j, Ratio);
        hCV422->SetBinError(j, sigma_z1);
        //hC42->Draw();
        hCV422->Draw();
        }

    // for (int i = 1; i < 11; i++)
	// {
	// 	for (int j=0; j<4; j++)
	// 	{
	// 		TString foo(TString::Format("fTprof2%d_number%dNtrks1bin", j+2, i));	
    //         TProfile *fsample = (TProfile*)list->FindObject(foo);
	// 		TString bar(TString::Format("fTprofC2%d", j+2));	            
    //         TProfile *Cn22 = (TProfile*)list->FindObject(bar); // the right Tprofile will be found here. and then "FindObject" will find the right one. name has to be written correctly.
	// 		for (int h=0; h<200; h++)
    //         {
    //             BinValue = fsample->GetBinContent(h);
    //             BinValue2 = Cn22->GetBinContent(h);

    //             cout << "BinValue:  " << BinValue << endl;
    //             cout << "BinValue 2: " << BinValue2 << endl;
    //             cout << "first step:  " << foo << endl; 
    //         }
			
            
		
	// 		fsample->Draw("EP");  


	// 		// bin_val = c22->GetBinContent(j);
	// 		// bin_val_fc = fc22->GetBinContent(j);
	// 		// std::cout << "bin_val" << c22->GetBinContent(j) << std::qendl;
	// 	}
	// }
    //****************************************************
    //// Loop to get sqrt of each bin in Tprofile of//////
    //     Cn{2} = <<2>> = < vn^2 > and //////////////////
    ////   Cn{4} = <<4>> = <vn^4> = <<4>> - 2 <<2>>^2 ////
    //*****************************************************
    // for(int i=0; i<200; i++)
    // {
    //     BinValue = h1->GetBinContent(i);
    //     error = h1->GetBinError(i); 
    //     cout << "BinValue: " << BinValue << endl; 
    //     cout << "Error: " << error << endl;
    // if(BinValue > 0)
    // {
    //     valuesqrt = sqrt(BinValue);
    //     x_sqrt = 1/valuesqrt;
    //     cout << "sqrtBinValue: "<< valuesqrt <<endl;
    //     cout << "x_sqrt: " << x_sqrt << endl;

    //     part1 = 0.5 * x_sqrt;
    //     cout << "part1: " << part1 << endl;

    //     part2 = part1 * error; 
    //     cout << "part2: " << part2 << endl; 
        
    //     part3 = pow(part2, 2); 
    //     cout << "part3: " << part3 << endl;

    //     sigma_z1 = sqrt(part3);
    //     cout << "sigma_z1: " << sigma_z1 << endl;
 
    //     hC22->SetBinContent(i, valuesqrt);
    //     hC22->SetBinError(i, sigma_z1);
    // }
    // else(BinValue <= 0);  
    // {
    //     continue;
    // }

    // }

    // for(int j=0; j<200; j++)
    // {
    //     BinValue2 = h2->GetBinContent(j);
    //     error2 = h2->GetBinError(j);
    //     //if(BinValue2 <= 0){ continue;
    //     cout << "BinValue2: " << BinValue2 << endl; 
    //     cout << "Error2: " << error2 << endl;
    //     if(BinValue2 > 0)
    //     {
    //         valuesqrt2 = sqrt(BinValue2);
    //         cout << "sqrtBinValue2: "<< valuesqrt2 <<endl; 
    //         x_sqrt2 = 1/valuesqrt2;
            
    //         part11 = 0.5 * x_sqrt2;
    //         cout << "part11: " << part1 << endl;
            
    //         part22 = part11 * error2; 
    //         cout << "part22: " << part22 << endl; 

    //         part33 = pow(part22, 2); 
    //         cout << "part33: " << part33 << endl;

    //         sigma_z2 = sqrt(part33);
    //         cout << "sigma_z2: " << sigma_z2 << endl;

    //         hC42->SetBinContent(j, valuesqrt2);
    //         hC42->SetBinError(j, sigma_z2);
    //     }
    //     // else(BinValue2 <= 0);  
    //     // {
    //     // continue;
    //     // }
    
    // }

    //fc34->Draw();

    // fc34->SetMarkerStyle(23);
    // fc34->SetMarkerColorAlpha(kRed, 4.5);
    // fc34->Draw("EP");

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
    
    // fc42->SetMarkerStyle(23);
    // fc42->SetMarkerColorAlpha(kRed, 4.5);
    // fc42->Draw("EP");
    
    // hC22->SetMarkerStyle(23);
    // hC22->SetMarkerColorAlpha(kRed, 4.5);
    // hC22->Draw("EP");
    
    // hC42->SetMarkerStyle(23);
    // hC42->SetMarkerColorAlpha(kRed, 10.0);
	// hC42->Draw("EP");
    // fc34->Divide(hC42);
    // fc34->Draw();
}