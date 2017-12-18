
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

void Linear_caculation_Fithharmonic() {
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
    double Valuesqrt_22Particle_Correlation = 0.0;
    double V532;
    double V532_Sample;
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

    //values for Linear error sampling:
    // double fsample_2particle_correlation = 0.0;
    // double fsample_3particle_correlation = 0.0;
    // double fsample_4particle_correlation = 0.0;


    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(19);
    c->cd();
    
    TH1D *hC22 = new TH1D("hC22", " V5{2},  #sqrt{< v_{5}^{2} >}", 200, 0, 200); //this is just define a histogram which will fill the data.
    hC22->Sumw2();
    
    //TH1D *hC52 = new TH1D("hC52", " #sqrt{< v_{2}^{2} >}", 200, 0, 200); //this is just define a histogram 
	//hC52->Sumw2();

    TH1D *hCV532 = new TH1D("hCV532", "The Non-Linear Response, v_{5,32} = <<3>> / #sqrt{ < v_{3}^{2} v_{2}^{2} > }", 200, 0, 200); //this is just define a histogram which will fill the data of V422.
    hCV532->Sumw2();
 
    TH1D *hCLinear = new TH1D("hCLinear", " The Linear Response V5^{L} ", 200, 0, 200); //this is just define a histogram which will fill the data.
    hCLinear->Sumw2();

    //Open the root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/LHC16q_CENT_SDD_W_NUA_3particle_02Gap.root", "READ");
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

    //****************************************************
    //// Loop to get sqrt of each bin in Tprofile of//////
    //     Cn{2} = <<2>> = < vn^2 > and //////////////////
    ////   Cn{4} = <<4>> = <vn^4> = <<4>> - 2 <<2>>^2 ////
    /////       v2{4} = sqrt(<<4>>_{2,2|-2,-2})        ////////////
    //*****************************************************
    // for(int i=1; i<201; i++)
    // {
    //     double error = 0.0;
    //     for(int sample=1; sample<11; sample++)
    //     {
    //         TString foo(TString::Format("fTprof42_number%dNtrks1bin", sample));	
    //         TProfile *fprof42 = (TProfile*)list->FindObject(foo);
    //         TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42");
    //         BinValue42_Sample = fprof42->GetBinContent(i);
    //         BinValue42 = Cn42->GetBinContent(i); 

    //         if(BinValue42 > 0 && BinValue42_Sample > 0 ) {
    //             Valuesqrt_4Particle_Correlation = sqrt(BinValue42);
    //             Valuesqrt_4Particle_Sample = sqrt(BinValue42_Sample);
    //         }
    //         else continue;
    //         error += pow(Valuesqrt_4Particle_Sample - Valuesqrt_4Particle_Correlation, 2);

    //         // cout << "fsample: " << foo << endl;
    //         // cout << "BinVlue42: " << BinValue42 << endl;
    //         // cout << "BinVlue42_Sample: " << BinValue42_Sample << endl;
    //         // cout << " Valuesqrt 4Particle: " << Valuesqrt_4Particle_Correlation << endl;
    //         // cout << "error: " << error << endl; 
        
    //     }
    //     final_error = sqrt(error / (N * N) );
    //     //cout << "final_error: " << final_error << endl;
    //     hC42->SetBinContent(i, Valuesqrt_4Particle_Correlation);
    //     hC42->SetBinError(i, final_error);

    // }
    //*************************************************************************
    //.. Loop for get the v5 = sqrt(<<2>>_{5|-5})
    for(int i=1; i < 201; i++)
    {
        double error = 0.0;
        for(int sample =1; sample < 11; sample++)
        {
            //TString foo(TString::Format("fTprof25_number%dNtrks1bin", sample));
            TString foo(TString::Format("fTprof25_number%dGapNtrks1bin", sample));
            TProfile *fprof25 = (TProfile*)list->FindObject(foo);

            BinValue25_Sample = fprof25->GetBinContent(i);
            BinValue25 = Cn25->GetBinContent(i);
            if(BinValue25_Sample > 0 && BinValue25 > 0 ) {
                Valuesqrt_22Particle_Correlation = sqrt(BinValue25);
                Valuesqrt_2Particle_Sample = sqrt(BinValue25_Sample); 
            }
            else continue;
            error += pow(Valuesqrt_2Particle_Sample - Valuesqrt_22Particle_Correlation, 2);
            // cout << "BinValue24_Sample: " << BinValue24_Sample << endl;
            // cout << "BinValue24: " << BinValue24 << endl;
            // cout << "error: " << error << endl;
        }
        final_error = sqrt(error/ (N * N) );
        //cout << "final error: " << final_error << endl;
        hC22->SetBinContent(i, Valuesqrt_22Particle_Correlation);
        hC22->SetBinError(i, final_error);
    }
    

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
                
                error += pow(V532_Sample - V532, 2);

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
        hCV532->SetBinContent(j, V532);
        hCV532->SetBinError(j, sigma_z1);

        }
    //     //***************************************************************************************************************
    //     //..Linear Response calculation:
    //     //.. The L and NL are uncorrelated means they are perpendicular so they make a 90 triangle when the "Hypotenuse" is v4 (sqrt(<<2>>_{4|-4})) and the two others are L response and Non-Linear response which is the "<<3>> / sqrt(<<4>>)" so by using the "Pythagorean theoerem" the v4^2 = L^2 + NL ^2 
    //     /////                                               L^2 = v4^2 - NL^2  we dont have L response so
    //     ////////                              L = sqrt (v4 - NL) Here v4 is sqrt( <<2>> ) and NL is <<3>> /sqrt(<<4>> )
    //     //***************************************************************************************************************

    for (int j=1; j<201; j++) {
        double error = 0.0;
        for (int i = 1; i < 11; i++) {
            // TString foo(TString::Format("fTprof25_number%dNtrks1bin", i));
            // TProfile *prof25 = (TProfile*)list->FindObject(foo);
            // TString bar(TString::Format("fTprof35_number%dNtrks1bin", i));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar);
            // TString foo2(TString::Format("fTprof22_number%dNtrks1bin", i));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo2);
            // TString foo3(TString::Format("fTprof23_number%dNtrks1bin", i));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo3);

            TString foo(TString::Format("fTprof25_number%dGapNtrks1bin", i));
            TProfile *prof25 = (TProfile*)list->FindObject(foo);
            TString bar(TString::Format("fTprof35_number%dGapNtrks1bin", i));	
            TProfile *prof35 = (TProfile*)list->FindObject(bar);
            TString foo2(TString::Format("fTprof22_number%dGapNtrks1bin", i));	
            TProfile *prof22 = (TProfile*)list->FindObject(foo2);
            TString foo3(TString::Format("fTprof23_number%dGapNtrks1bin", i));	
            TProfile *prof23 = (TProfile*)list->FindObject(foo3);

            Sample_BinValue_25Particle_Correlation = prof25->GetBinContent(j);
            Sample_BinValue_35Particle_Correlation = prof35->GetBinContent(j);
            Sample_BinValue_22Particle_Correlation = prof22->GetBinContent(j);
            Sample_BinValue_23Particle_Correlation = prof23->GetBinContent(j);

            BinValue_25Particle_Correlation = Cn25->GetBinContent(j);
            BinValue_35Particle_Correlation = Cn35->GetBinContent(j);
            BinValue_22Particle_Correlation = Cn22->GetBinContent(j);
            BinValue_23Particle_Correlation = Cn23->GetBinContent(j);

            // cout << "j: " << j << endl;
            // cout << "i: " << i << endl;
            // cout << "binvalue3s: " << Sample_BinValue_3Particle_Correlation << endl;
            
            if(Sample_BinValue_22Particle_Correlation > 0 && Sample_BinValue_23Particle_Correlation > 0 && BinValue_23Particle_Correlation > 0 && BinValue_22Particle_Correlation > 0 && BinValue_25Particle_Correlation > 0 && Sample_BinValue_25Particle_Correlation > 0 ) {

                Sample_Value_sqrt_22particle_correlation = sqrt(Sample_BinValue_22Particle_Correlation);
                Sample_Value_sqrt_23particle_correlation = sqrt(Sample_BinValue_23Particle_Correlation);
                Sample_Value_sqrt_25particle_correlation = sqrt(Sample_BinValue_25Particle_Correlation);
                
                Valuesqrt_22Particle_Correlation = sqrt(BinValue_22Particle_Correlation);
                Valuesqrt_23Particle_Correlation = sqrt(BinValue_23Particle_Correlation);
                Valuesqrt_25Particle_Correlation = sqrt(BinValue_25Particle_Correlation);
            }   
            if(Valuesqrt_23Particle_Correlation > 0 && Valuesqrt_22Particle_Correlation > 0 && Sample_Value_sqrt_22particle_correlation > 0 && Sample_Value_sqrt_23particle_correlation > 0  && Sample_BinValue_35Particle_Correlation > 0 && BinValue_35Particle_Correlation > 0 ){
                
                V532 = BinValue_35Particle_Correlation / (Valuesqrt_23Particle_Correlation * Valuesqrt_22Particle_Correlation );
                V532_Sample = Sample_BinValue_35Particle_Correlation / (Sample_Value_sqrt_23particle_correlation * Sample_Value_sqrt_22particle_correlation);  

                //..First part i linear calculation is v5^2{2} which means---> vn{2} = sqrt(< vn^2 >) = sqrt(<<2>>) because <<2>> = <vn^2> --> vn = sqrt(<<2>> = sqrt(<vn^2>)
                Linear = pow(Valuesqrt_25Particle_Correlation, 2) - pow(V532, 2);   
                fsample_Linear = pow(Sample_Value_sqrt_25particle_correlation, 2) - pow(V532_Sample, 2); 
            }
            if(fsample_Linear > 0 && Linear > 0 ) {
                Linear_value_sample = sqrt(fsample_Linear);
                Linear_value = sqrt(Linear);
                error += pow(Linear_value_sample - Linear_value, 2);
            }
            else continue; 
        
        }
        Linear_Error = sqrt(error/ (N * N) );           
        hCLinear->SetBinContent(j, Linear_value); 
        hCLinear->SetBinError(j, Linear_Error); 

        // cout << "Valuesqrt_22Particle_Correlation: " << Valuesqrt_22Particle_Correlation << endl; 
        // cout << "Valuesqrt_23Particle_Correlation: " << Valuesqrt_23Particle_Correlation << endl; 
        // cout << "Value_sqrt_2particle_correlation: " << Value_sqrt_2particle_correlation << endl; 
        // cout << "Value_sqrt_4particle_correlation: " << Value_sqrt_4particle_correlation << endl; 
        

        // cout << "BinValue_3Particle_Correlation: " << BinValue_3Particle_Correlation << endl; 
        // cout << "Valuesqrt_23Particle_Correlation: " << Valuesqrt_23Particle_Correlation << endl; 
        //cout << "V4_BinValue_hC22: " << V4_BinValue_hC22 << endl;
        //cout << "NL_BinValue_hCV422: " << NL_BinValue_hCV422 << endl;
        cout << "Linear3: " << Linear << endl;
        cout << "fsample_Linear: " << fsample_Linear << endl; 
        cout << "Linear_value: " << Linear_value << endl;
        cout << "Linear_value_sample: " << Linear_value_sample << endl;   
        
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
    //         BinValue_4Particle_Correlation = Cn42->GetBinContent(i);

    //         cout << "BinValue_sample:  " << BinValue_sample << endl;
    //         cout << "BinValue 4Particle: " << BinValue_4Particle_Correlation << endl;
    //         cout << "first step:  " << foo << endl; 
    //         if (BinValue_sample > 0 && BinValue_4Particle_Correlation > 0)
    //             error += pow(BinValue_sample - BinValue_4Particle_Correlation, 2);
    //         else continue;
    //         }
    //     final_error = sqrt(error/ (N * N ));
    //     hCLinear->SetBinContent(i, BinValue_4Particle_Correlation);
    //     hCLinear->SetBinError(i, final_error);
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
    
    // Cn24->SetMarkerStyle(23);
    // Cn24->SetMarkerColorAlpha(kRed, 4.5);
    // Cn24->Draw("EP");
    
    // Cn34->SetMarkerStyle(23);
    // Cn34->SetMarkerColorAlpha(kRed, 4.5);
    // Cn34->Draw("EP");
    
    // Cn42->SetMarkerStyle(23);
    // Cn42->SetMarkerColorAlpha(kRed, 4.5);
    // Cn42->Draw("EP");
    
    
    // hC42->SetMarkerStyle(21);
    // hC42->SetMarkerColorAlpha(kBlack, 10.0);
	// hC42->Draw("same");

    // hC22->SetMarkerStyle(20);
    // hC22->SetMarkerColorAlpha(kRed, 4.5);
    // hC22->SetAxisRange(0., 110);
    // hC22->SetMarkerSize(1.);
    // hC22->SetXTitle("# of tracks");
    // hC22->Draw("same");
    // //gStyle->SetOptStat(0);

    hCV532->SetMarkerStyle(34);
    hCV532->SetMarkerColorAlpha(kBlue, 0.45);
    hCV532->SetAxisRange(0., 110);
    hCV532->SetMarkerSize(2.);
	hCV532->Draw("same");
    
    // hCLinear->SetMarkerStyle(21);
    // hCLinear->SetMarkerColorAlpha(kBlack, 4.5);
    // hCLinear->SetAxisRange(0., 110);
    // hCLinear->SetMarkerSize(1.);
    // hCLinear->Draw("same");
    c->BuildLegend();
    
    // //..Create a root.file:
    // TFile* fileOutput = new TFile("V4_Linear_NonLinear_Response.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC22->Write();
    // hCV422->Write();
    // hCLinear->Write();
    // return;
}