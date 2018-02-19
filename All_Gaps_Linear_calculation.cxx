
//Macro To Calculate the v422, Linear for all gaps:
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

void All_Gaps_Linear_calculation() {
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
    double NL_BinValue_hCV422;
    double Linear;
    double Linear_value; 
    double Linear_value_sample;
    double final_error;
    double Linear_Error; 
    double test;
    double BinValue_Sapmle24;
    double BinValue_Total24;
    double BinValue_Sample_34;
    double BinValue_Sample_42;
    double BinValue_Total_34;
    double BinValue_Total_42;
    int N = 10;


    //values for Linear error sampling:
    double Sample_Linear; 
    double fsample_2particle_correlation = 0.0;
    double Sample_Valuesqrt_2particle_correlation = 0.0;
    double fsample_3particle_correlation = 0.0;
    double fsample_4particle_correlation = 0.0;
    double Sample_Valuesqrt_4particle_correlation = 0.0;
    double BinValue_Total42 = 0.0;
    double BinValue_Sample42 = 0.0;
    double BinValue_Total_24 = 0.0; 
    double BinValue_Sample_24 = 0.0;

    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    
    TH1D *hC22 = new TH1D("hC22", " V4{2},  #sqrt{< v_{4}^{2} >}, 2-Particle correlation", 200, 0, 200); //this is just define a histogram which will fill the data.
    hC22->Sumw2();
    
    TH1D *hC42 = new TH1D("hC42", " #sqrt{< v_{2}^{4} >} 4-Particle correlation", 200, 0, 200); //this is just define a histogram 
	hC42->Sumw2();

    TH1D *hCV422 = new TH1D("hCV422", "The Non-Linear Response, v_{4,22} = #frac {<<3>>} {#sqrt{< v_{2}^{4} >}}", 200, 0, 200); //this is just define a histogram which will fill the data of V422.
    hCV422->Sumw2();
 
    TH1D *hCLinear = new TH1D("hCLinear", " The Linear Response V4^{L} ", 200, 0, 200); //this is just define a histogram which will fill the data.
    hCLinear->Sumw2();

    //Open the root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/LHC16q_CENT_SDD_0Gap_2_08Gap_FullGaps.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("MyTaskResults");
    TList *list = (TList*)dir->Get("Flow_Refs_MyTaskResults");
    
    TFile *file2 = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Cut_RawData_3particle_4particle/New_Cut_Data_3_4_particle/Gap00_Cut_Tprofile_3_4_particle.root", "READ");

    TProfile *CTprof34 = (TProfile*)file2->Get("fTprofC34Gap00Ntrks1bin");
    CTprof34->Draw();


    //..Uden Gap
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Ntrks1bin"); 

    //..Gap= 0.0
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap0Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap0Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap0Ntrks1bin"); 
    
    //..Gap= 0.1
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap01Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap01Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap01Ntrks1bin"); 

    //..Gap= 0.2
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap02Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap02Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap02Ntrks1bin");

    //..Gap= 0.3
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap03Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap03Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap03Ntrks1bin");     
 
    //..Gap= 0.4
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap04Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap04Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap04Ntrks1bin"); 

    //..Gap= 0.5
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap05Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap05Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap05Ntrks1bin"); 

    //..Gap= 0.6
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap06Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap06Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap06Ntrks1bin"); 

    //..Gap= 0.7
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap07Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap07Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap07Ntrks1bin");

    //..Gap= 0.8
    TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap08Ntrks1bin");
    TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap08Ntrks1bin");  
    TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap08Ntrks1bin");  

    //..Projection on Xaxis:
    TH1D *h1 = Cn24->ProjectionX("h1");
    TH1D *h2 = Cn42->ProjectionX("h2");
    TH1D *h3 = Cn34->ProjectionX("h3");


    //****************************************************
    //// Loop to get sqrt of each bin in Tprofile of//////
    ////   Cn{4} = <<4>> = <vn^4> = <<4>> - 2 <<2>>^2 ////
    /////     v2{4} = sqrt(<<4>>_{2,2|-2,-2})        /////
    //*****************************************************
    for(int i=1; i<201; i++)
    {
        double error = 0.0;
        for(int sample=1; sample<11; sample++)
        {
            TString foo(TString::Format("fTprof42_number%0dNtrks1bin", sample));	
            TProfile *fprof42 = (TProfile*)list->FindObject(foo);
            TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Ntrks1bin");
    
            BinValue42_Sample = fprof42->GetBinContent(i);
            BinValue42 = Cn42->GetBinContent(i); 

            BinValue_Total42 = Cn42->GetBinEffectiveEntries(i);
            BinValue_Sample42 = fprof42->GetBinEffectiveEntries(i);
    
            if(BinValue_Total42 > 1000 && BinValue_Sample42 > 100 ) {

            if(BinValue42 > 0 && BinValue42_Sample > 0 ) {
                Valuesqrt_4Particle_Correlation = sqrt(BinValue42);
                Valuesqrt_4Particle_Sample = sqrt(BinValue42_Sample);
            }
            else continue;
            cout << "The second If statement is passed " << endl;
            error += pow(Valuesqrt_4Particle_Sample - Valuesqrt_4Particle_Correlation, 2);
            }
            else continue; 
            cout << "Multiplicity check passed" << endl;
            // cout << "fsample: " << foo << endl;
            // cout << "BinVlue42: " << BinValue42 << endl;
            // cout << "BinVlue42_Sample: " << BinValue42_Sample << endl;
            // cout << " Valuesqrt 4Particle: " << Valuesqrt_4Particle_Correlation << endl;
            // cout << "error: " << error << endl; 
        
        }
        final_error = sqrt(error / (N * N) );
        //cout << "final_error: " << final_error << endl;
        if(BinValue_Total42 > 1000 && BinValue_Sample42 > 100 ) {
            hC42->SetBinContent(i, Valuesqrt_4Particle_Correlation);
            hC42->SetBinError(i, final_error);
        }

    }
    //*************************************************************************
     //  Cn{2} = <<2>> = < vn^2 > and /////////
    //.. Loop for get the v4{2} = sqrt(<<2>>_{4|-4})
    //************************************************************************
    for(int i=1; i < 201; i++)
    {
        double error = 0.0;
        for(int sample =1; sample < 11; sample++)
        {   
            //..Uden Gap
            // TString foo_24(TString::Format("fTprof24_number%dNtrks1bin", sample));
            // TProfile *fprof24 = (TProfile*)list->FindObject(foo_24);

            //..Gap= 0.0
            // TString foo_24(TString::Format("fTprof24_number%dGap0Ntrks1bin", sample));
            // TProfile *fprof24 = (TProfile*)list->FindObject(foo_24);

            //..Gap= 0.1
            // TString foo_24(TString::Format("fTprof24_number%dGap01Ntrks1bin", sample));
            // TProfile *fprof24 = (TProfile*)list->FindObject(foo_24);

            //..Gap= 0.2
            // TString foo_24(TString::Format("fTprof24_number%dGap02Ntrks1bin", sample));
            // TProfile *fprof24 = (TProfile*)list->FindObject(foo_24);

            //..Gap= 0.3
            // TString foo_24(TString::Format("fTprof24_number%dGap03Ntrks1bin", sample));
            // TProfile *fprof24 = (TProfile*)list->FindObject(foo_24);

            //..Gap= 0.4
            // TString foo_24(TString::Format("fTprof24_number%dGap04Ntrks1bin", sample));
            // TProfile *fprof24 = (TProfile*)list->FindObject(foo_24);

            //..Gap= 0.5
            // TString foo_24(TString::Format("fTprof24_number%dGap05Ntrks1bin", sample));
            // TProfile *fprof24 = (TProfile*)list->FindObject(foo_24);

            //..Gap= 0.6
            // TString foo_24(TString::Format("fTprof24_number%dGap06Ntrks1bin", sample));
            // TProfile *fprof24 = (TProfile*)list->FindObject(foo_24);

            //..Gap= 0.7
            // TString foo_24(TString::Format("fTprof24_number%dGap07Ntrks1bin", sample));
            // TProfile *fprof24 = (TProfile*)list->FindObject(foo_24);

            //..Gap= 0.8
            TString foo_24(TString::Format("fTprof24_number%dGap08Ntrks1bin", sample));
            TProfile *fprof24 = (TProfile*)list->FindObject(foo_24);

            BinValue24 = Cn24->GetBinContent(i);
            BinValue24_Sample = fprof24->GetBinContent(i);
            
            //..Multiplicity Test:
            BinValue_Total24 = Cn24->GetBinEffectiveEntries(i);
            BinValue_Sapmle24 = fprof24->GetBinEffectiveEntries(i);

            if( BinValue_Total24 > 1000 && BinValue_Sapmle24 > 100) {

            if(BinValue24_Sample > 0 && BinValue24 > 0 ) {
                Valuesqrt_2Particle_Correlation = sqrt(BinValue24);
                Valuesqrt_2Particle_Sample = sqrt(BinValue24_Sample); 
            }
            else continue;
            error += pow(Valuesqrt_2Particle_Sample - Valuesqrt_2Particle_Correlation, 2);
            // cout << "BinValue24_Sample: " << BinValue24_Sample << endl;
            // cout << "BinValue24: " << BinValue24 << endl;
            // cout << "error: " << error << endl;
            }
            else continue;
            cout << "Multiplicity check finished: " << i << endl;

        }
        final_error = sqrt(error/ (N * N) );
        
        if( BinValue_Total24 > 1000 && BinValue_Sapmle24 > 100) {
            hC22->SetBinContent(i, Valuesqrt_2Particle_Correlation);
            hC22->SetBinError(i, final_error);
        }
        else continue;
        //cout << "final error: " << final_error << endl;
        //cout << "BinValue24_Sample: " << BinValue24_Sample << endl;
        //cout << "BinValue_h1: " << BinValue_h1 << endl;
        // cout << "BinTest_24Total: " << BinValue_Total24 << endl;
        // cout << "BinTest_24Sample: " << BinValue_Sapmle24 << endl;
    }
    
    //*************************************************************************
    // //..Loop over fSample for Error propagation for Non-Linear Response:
    
    //**************************************************************************
    for (int j=1; j<201; j++) {
        double error = 0.0;
        for (int i = 1; i < 11; i++) {
            
            //..uden Gap
            // TString bar_34(TString::Format("fTprof34_number%dNtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dNtrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);
            
            //..Gap= 0.0  
            // TString bar_34(TString::Format("fTprof34_number%dGap0Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap0Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            // //..Gap= 0.1
            // TString bar_34(TString::Format("fTprof34_number%dGap01Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap01Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.2
            // TString bar_34(TString::Format("fTprof34_number%dGap02Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap02Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);
            
            // //..Gap= 0.3  
            // TString bar_34(TString::Format("fTprof34_number%dGap03Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap03Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.4  
            // TString bar_34(TString::Format("fTprof34_number%dGap04Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap04Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.5  
            // TString bar_34(TString::Format("fTprof34_number%dGap05Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap05Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.6
            // TString bar_34(TString::Format("fTprof34_number%dGap06Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap06Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.7
            // TString bar_34(TString::Format("fTprof34_number%dGap07Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap07Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.8
            TString bar_34(TString::Format("fTprof34_number%dGap08Ntrks1bin", i));	
            TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            TString foo_42(TString::Format("fTprof42_number%dGap08Ntrks1bin", i));	
            TProfile *prof42 = (TProfile*)list->FindObject(foo_42);



            Sample_BinValue_3Particle_Correlation = prof34->GetBinContent(j);
            Sample_BinValue_4Particle_Correlation = prof42->GetBinContent(j);
            
            BinValue_3Particle_Correlation = Cn34->GetBinContent(j);
            BinValue_4Particle_Correlation = Cn42->GetBinContent(j);

        //..Check for Multiplicity, in the way in the sampling plot has to be at least N_ch>100 and in the total          N_ch>1000 in each bins. 
            BinValue_Total_34 = Cn34->GetBinEffectiveEntries(j);
            BinValue_Total_42 = Cn42->GetBinEffectiveEntries(j);

            BinValue_Sample_34 = prof34->GetBinEffectiveEntries(j);
            BinValue_Sample_42 = prof42->GetBinEffectiveEntries(j);
            
            if(BinValue_Total_34 > 1000 && BinValue_Total_42 > 1000 && BinValue_Sample_34 >100 && BinValue_Sample_42 > 100) {

            if (Sample_BinValue_4Particle_Correlation > 0  && BinValue_4Particle_Correlation > 0 && BinValue_3Particle_Correlation > 0 && Sample_BinValue_3Particle_Correlation > 0 ) {
            
                Valuesqrt_4Particle_Correlation = sqrt(BinValue_4Particle_Correlation);
                Sample_Valuesqrt_4Particle_Correlation = sqrt(Sample_BinValue_4Particle_Correlation);
                
                V422 = BinValue_3Particle_Correlation / Valuesqrt_4Particle_Correlation;
                V422_Sample = Sample_BinValue_3Particle_Correlation / Sample_Valuesqrt_4Particle_Correlation; 
                
                error += pow(V422_Sample - V422, 2);

            }
            else continue; 
            cout << "The If statement for BinContent is passed " << endl;
            }
            else continue;
            cout << "Multiplicity Check passed: " << j << endl; 

            
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
        if( BinValue_Total_34 > 1000 && BinValue_Total_42 > 1000 && BinValue_Sample_34 >100 && BinValue_Sample_42 >100) {
            hCV422->SetBinContent(j, V422);
            hCV422->SetBinError(j, sigma_z1); 
        }
        else continue;
        // cout << "BinValue_Total_34: " << BinValue_Total_34 << endl;
        // cout << "BinValue_Total_42: " << BinValue_Total_42 << endl;
        // cout << "BinValue_Sample_34: " << BinValue_Sample_34 << endl;
        // cout << "BinValue_Sample_42: " << BinValue_Sample_42 << endl;
        
    }
        //***************************************************************************************************************
        //..Linear Response calculation:
        //.. The L and NL are uncorrelated means they are perpendicular so they make a 90 triangle when the "Hypotenuse" is v4 (sqrt(<<2>>_{4|-4})) and the two others are L response and Non-Linear response which is the "<<3>> / sqrt(<<4>>)" so by using the "Pythagorean theoerem" the v4^2 = L^2 + NL ^2 
        /////                                               L^2 = v4^2 - NL^2  we dont have L response so
        ////////                              L = sqrt (v4^2 - NL^2) Here v4 is sqrt( <<2>>_{4,-4}) and NL is <<3>> /sqrt(<<4>> )
        //***************************************************************************************************************

    for (int j=1; j<201; j++) {
        double error = 0.0;
        for (int i = 1; i < 11; i++) {
            //..Uden Gap 
            // TString foo_24(TString::Format("fTprof24_number%dNtrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dNtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dNtrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.0
            // TString foo_24(TString::Format("fTprof24_number%dGap0Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap0Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap0Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.1
            // TString foo_24(TString::Format("fTprof24_number%dGap01Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap01Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap01Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.2
            // TString foo_24(TString::Format("fTprof24_number%dGap02Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap02Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap02Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.3
            // TString foo_24(TString::Format("fTprof24_number%dGap03Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap03Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap03Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.4
            // TString foo_24(TString::Format("fTprof24_number%dGap04Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap04Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap04Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.5
            // TString foo_24(TString::Format("fTprof24_number%dGap05Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap05Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap05Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.6
            // TString foo_24(TString::Format("fTprof24_number%dGap06Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap06Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap06Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.7
            // TString foo_24(TString::Format("fTprof24_number%dGap07Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap07Ntrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap07Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.8
            TString foo_24(TString::Format("fTprof24_number%dGap08Ntrks1bin", i));
            TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            TString bar_34(TString::Format("fTprof34_number%dGap08Ntrks1bin", i));	
            TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            TString foo_42(TString::Format("fTprof42_number%dGap08Ntrks1bin", i));	
            TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            Sample_BinValue_2Particle_Correlation = prof24->GetBinContent(j);
            Sample_BinValue_3Particle_Correlation = prof34->GetBinContent(j);
            Sample_BinValue_4Particle_Correlation = prof42->GetBinContent(j);

            BinValue_2Particle_Correlation = Cn24->GetBinContent(j);
            BinValue_3Particle_Correlation = Cn34->GetBinContent(j);
            BinValue_4Particle_Correlation = Cn42->GetBinContent(j);
            
            //..Check the multiplicity in each bins:
            BinValue_Total_24 = Cn24->GetBinEffectiveEntries(j);
            BinValue_Total_34 = Cn34->GetBinEffectiveEntries(j);
            BinValue_Total_42 = Cn42->GetBinEffectiveEntries(j);

            BinValue_Sample_24 = prof24->GetBinEffectiveEntries(j);
            BinValue_Sample_34 = prof34->GetBinEffectiveEntries(j);
            BinValue_Sample_42 = prof42->GetBinEffectiveEntries(j);
            
            if( BinValue_Total_24 > 1000 && BinValue_Total_34 > 1000 && BinValue_Total_42 > 1000 && BinValue_Sample_24 >100 && BinValue_Sample_34 >100 && BinValue_Sample_42 >100) {
            
            if(Sample_BinValue_2Particle_Correlation > 0 && Sample_BinValue_4Particle_Correlation > 0 && BinValue_4Particle_Correlation > 0 && BinValue_2Particle_Correlation > 0 ) {

                Sample_Valuesqrt_2particle_correlation = sqrt(Sample_BinValue_2Particle_Correlation);
                Sample_Valuesqrt_4particle_correlation = sqrt(Sample_BinValue_4Particle_Correlation);
                
                Valuesqrt_2Particle_Correlation = sqrt(BinValue_2Particle_Correlation);
                Valuesqrt_4Particle_Correlation = sqrt(BinValue_4Particle_Correlation);
            }
            else continue; 
            cout << "The If statement for BinContent is passed: " << endl;   

            if(Valuesqrt_4Particle_Correlation > 0 && Sample_Valuesqrt_4particle_correlation > 0 && Sample_BinValue_3Particle_Correlation > 0 && BinValue_3Particle_Correlation > 0 ){
                
                V422 = BinValue_3Particle_Correlation / (Valuesqrt_4Particle_Correlation);
                V422_Sample = Sample_BinValue_3Particle_Correlation / (Sample_Valuesqrt_4particle_correlation);               
                
                Linear = pow(Valuesqrt_2Particle_Correlation, 2) - pow(V422, 2);   
                Sample_Linear = pow(Sample_Valuesqrt_2particle_correlation, 2) - pow(V422_Sample, 2); 
            }
            if(Sample_Linear > 0 && Linear > 0 ) {
                Linear_value_sample = sqrt(Sample_Linear);
                Linear_value = sqrt(Linear);
                error += pow(Linear_value_sample - Linear_value, 2);
            }
            else continue;
            cout << "Thirs if statement passed" << endl;
            }
            else continue; 
            cout << "Multiplicity check finished: " << j << endl; 
        }
        Linear_Error = sqrt(error/ (N * N) );
        if( BinValue_Total_24 > 1000 && BinValue_Total_34 > 1000 && BinValue_Total_42 > 1000 && BinValue_Sample_24 >100 && BinValue_Sample_34 >100 && BinValue_Sample_42 >100) {
            hCLinear->SetBinContent(j, Linear_value); 
            hCLinear->SetBinError(j, Linear_Error); 
        }
        else continue;
        
        // cout << "BinValue_Total_24: " << BinValue_Total_24 << endl;
        // cout << "BinValue_Total_34: " << BinValue_Total_34 << endl;
        // cout << "BinValue_Total_42: " << BinValue_Total_42 << endl;
        // cout << "BinValue_Sample_24: " << BinValue_Sample_24 << endl;
        // cout << "BinValue_Sample_34: " << BinValue_Sample_34 << endl;
        // cout << "BinValue_Sample_42: " << BinValue_Sample_42 << endl;
        // cout << "Valuesqrt_2Particle_Correlation: " << Valuesqrt_2Particle_Correlation << endl; 
        // cout << "Valuesqrt_4Particle_Correlation: " << Valuesqrt_4Particle_Correlation << endl; 
        // cout << "Sample_Valuesqrt_2particle_correlation: " << Sample_Valuesqrt_2particle_correlation << endl; 
        // cout << "Sample_Valuesqrt_4particle_correlation: " << Sample_Valuesqrt_4particle_correlation << endl; 
        // cout << "BinValue_3Particle_Correlation: " << BinValue_3Particle_Correlation << endl; 
        // cout << "Valuesqrt_4Particle_Correlation: " << Valuesqrt_4Particle_Correlation << endl; 
        //cout << "V4_BinValue_hC22: " << V4_BinValue_hC22 << endl;
        //cout << "NL_BinValue_hCV422: " << NL_BinValue_hCV422 << endl;
        // cout << "Linear3: " << Linear << endl;
        // cout << "Sample_Linear: " << Sample_Linear << endl; 
        // cout << "Linear_value: " << Linear_value << endl;
        // cout << "Linear_value_sample: " << Linear_value_sample << endl;   
        
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

    // // hC42->SetMarkerStyle(21);
    // // hC42->SetMarkerColorAlpha(kBlack, 10.0);
	//hC42->Draw("same");
    
    //..V4{2}
    // hC22->SetMarkerStyle(20);
    // hC22->SetMarkerColorAlpha(kRed, 4.5);
    // hC22->SetAxisRange(0., 110);
    // hC22->SetMarkerSize(1.);
    // hC22->SetXTitle("# of tracks");
    // gStyle->SetOptStat(0);
    //hC22->Draw("same");
    

    //..V4^L
    // hCLinear->SetMarkerStyle(21);
    // hCLinear->SetMarkerColorAlpha(kBlack, 4.5);
    // //hCLinear->SetAxisRange(0., 110);
    // hCLinear->SetMarkerSize(1.);
    //hCLinear->Draw("same");

    //..V4,22
    // hCV422->SetMarkerStyle(34);
    // hCV422->SetMarkerColorAlpha(kBlue, 0.45);
    // //hCV422->GetYaxis()->SetRangeUser(0., 3.);
    // //hCV422->GetXaxis()->SetRangeUser(0., 140);
    // hCV422->SetMarkerSize(2.);
	// hCV422->Draw("same");
    // c->BuildLegend();
    
    
    //..Create a root.file:
    //..Uden Gap
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_NewCondition_V4_Linear_NL/WOGap_Conditions_V4_Linear_NonLinear_Response.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC22->Write();
    // hCV422->Write();
    // hCLinear->Write();
    // return;
    
    //..Gap= 0.0
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_NewCondition_V4_Linear_NL/Gap00_V4_Linear_NonLinear_Response_NewCondition.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC22->Write();
    // hCV422->Write();
    // hCLinear->Write();
    // return;
    
    //..Gap= 0.1
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_NewCondition_V4_Linear_NL/Gap01_V4_Linear_NonLinear_Response_NewCondition.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC22->Write();
    // hCV422->Write();
    // hCLinear->Write();
    // return;

    //..Gap= 0.2
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_NewCondition_V4_Linear_NL/Gap02_V4_Linear_NonLinear_Response_NewCondition.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC22->Write();
    // hCV422->Write();
    // hCLinear->Write();
    // return;

    //..Gap= 0.3
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_NewCondition_V4_Linear_NL/Gap03_V4_Linear_NonLinear_Response_NewCondition.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC22->Write();
    // hCV422->Write();
    // hCLinear->Write();
    // return;
  
    //..Gap= 0.4
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_NewCondition_V4_Linear_NL/Gap04_V4_Linear_NonLinear_Response_NewCondition.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC22->Write();
    // hCV422->Write();
    // hCLinear->Write();
    // return;

    //..Gap= 0.5
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_NewCondition_V4_Linear_NL/Gap05_V4_Linear_NonLinear_Response_NewCondition.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC22->Write();
    // hCV422->Write();
    // hCLinear->Write();
    // return;

    //..Gap= 0.6
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_NewCondition_V4_Linear_NL/Gap06_V4_Linear_NonLinear_Response_NewCondition.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC22->Write();
    // hCV422->Write();
    // hCLinear->Write();
    // return;

    //..Gap= 0.7
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_NewCondition_V4_Linear_NL/Gap07_V4_Linear_NonLinear_Response_NewCondition.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC22->Write();
    // hCV422->Write();
    // hCLinear->Write();
    // return;

    //..Gap= 0.8
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_NewCondition_V4_Linear_NL/Gap08_V4_Linear_NonLinear_Response_NewCondition.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC22->Write();
    // hCV422->Write();
    // hCLinear->Write();
    // return;

}