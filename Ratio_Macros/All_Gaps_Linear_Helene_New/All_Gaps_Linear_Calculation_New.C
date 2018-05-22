
//Macro To Calculate the v422, Linear for all gaps to compare with You's results:
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

void All_Gaps_Linear_Calculation_New() {
    double BinValue_3Particle_Correlation = 0.0;
    double BinValue_4Particle_Correlation = 0.0;
    double BinValue_2Particle_Correlation = 0.0;
    double Sample_BinValue_3Particle_Correlation = 0.0;
    double Sample_BinValue_4Particle_Correlation = 0.0;
    double Valuesqrt_4Particle_Correlation = 0.0;
    double Valuesqrt_2Particle_Correlation = 0.0;
    double Sample_Valuesqrt_4Particle_Correlation = 0.0;
    double Sample_BinValue_2Particle_Correlation = 0.0;
    double BinValue42 = 0.0;
    double BinValue42_Sample = 0.0;
    double BinValue24_Sample = 0.0; 
    double BinValue24 = 0.0; 
    double Valuesqrt_2Particle_Sample = 0.0;
    double Valuesqrt_4Particle_Sample = 0.0;
    double Linear = 0.0;
    double Linear_value = 0.0; 
    double Linear_value_sample = 0.0;
    double Linear_Error = 0.0; 
    double final_error_4part = 0.0;
    double final_error_2part = 0.0;
    double BinValue_Total_Sapmle24 = 0.0;
    double BinValue_Total24 = 0.0;
    double BinValue_Total_Sample_34 = 0.0;
    double BinValue_Total_Sample_42 = 0.0;
    double BinValue_Total_34 = 0.0;
    double BinValue_Total_42 = 0.0;
    double BinValue_Total_Sample42 = 0.0;
    double Sample_Linear = 0.0; 
    double Sample_Valuesqrt_2particle_correlation = 0.0;
    double Sample_Valuesqrt_4particle_correlation = 0.0;
    double BinValue_Total42 = 0.0;
    double BinValue_Total_24 = 0.0; 
    double V422 = 0.0;
    double V422_Sample = 0.0;
    double sigma_z1 = 0.0;
    int N = 10;
    int M =0;

    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    
    TH1D *hC22 = new TH1D("hC22", " V4{2},  #sqrt{< v_{4}^{2} >}, 2-Particle correlation", 200, 0, 200); //this is just define a histogram which will fill the data.
    hC22->Sumw2();
    
    TH1D *hC42 = new TH1D("hC42", " #sqrt{< v_{2}^{4} >} 4-Particle correlation", 200, 0, 200); //this is just define a histogram 
	hC42->Sumw2();

    TH1D *hV422 = new TH1D("hV422", "The Non-Linear Response, v_{4,22} = #frac {<<3>>} {#sqrt{< v_{2}^{4} >}}", 200, 0, 200); //this is just define a histogram which will fill the data of V422.
    hV422->Sumw2();
 
    TH1D *hCLinear = new TH1D("hCLinear", " The Linear Response V4^{L} ", 200, 0, 200); //this is just define a histogram which will fill the data.
    hCLinear->Sumw2();

    //Open the latest root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_Corrected_4particle.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");
    

    //**************************************************************************
    //..Uden Gap
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Ntrks1bin"); 

    //..Gap= 0.0
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap00Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap00Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap00ANtrks1bin"); 
    
    //..Gap= 0.1
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap01Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap01Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap01ANtrks1bin"); 

    //..Gap= 0.2
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap02Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap02Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap02ANtrks1bin");

    //..Gap= 0.3
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap03Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap03Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap03ANtrks1bin");     
 
    //..Gap= 0.4
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap04Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap04Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap04ANtrks1bin"); 

    //..Gap= 0.5
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap05Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap05Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap05ANtrks1bin"); 

    //..Gap= 0.6
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap06Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap06Ntrks1bin");
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap06ANtrks1bin"); 

    //..Gap= 0.7
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap07Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap07Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap07ANtrks1bin");

    //..Gap= 0.8
    TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap08Ntrks1bin");
    TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap08Ntrks1bin");  
    TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap08ANtrks1bin");  
    //**************************************************************************


    //int EtaGap[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    //****************************************************
    //// Loop to get sqrt of each bin in Tprofile of//////
    ////   Cn{4} = <<4>> = <vn^4> = <<4>> - 2 <<2>>^2 ////
    /////     v2{4} = sqrt(<<4>>_{2,2|-2,-2})        /////
    /////     ********** <<4>> *************        //////
    //*****************************************************
    for(int i=1; i<201; i++)
    {   
        double error_4part = 0.0;
        for(int sample=1; sample<11; sample++)
        {   
            //..Uden Gap
            TString foo(TString::Format("fTprof42_number%0dNtrks1bin", sample));
            TProfile *fprof42 = (TProfile*)list->FindObject(foo);

            //..Gap=0.0
            // TString foo(TString::Format("fTprof42_number%0dGap00Ntrks1bin", sample));	
            // TProfile *fprof42 = (TProfile*)list->FindObject(foo);

            // //..Gap=0.1
            // TString foo(TString::Format("fTprof42_number%0dGap01Ntrks1bin", sample));	
            // TProfile *fprof42 = (TProfile*)list->FindObject(foo);

            // //..Gap=0.2
            // TString foo(TString::Format("fTprof42_number%0dGap02Ntrks1bin", sample));	
            // TProfile *fprof42 = (TProfile*)list->FindObject(foo);

            // //..Gap=0.3
            // TString foo(TString::Format("fTprof42_number%0dGap03Ntrks1bin", sample));	
            // TProfile *fprof42 = (TProfile*)list->FindObject(foo);

            //..Gap=0.4
            // TString foo(TString::Format("fTprof42_number%0dGap04Ntrks1bin", sample));	
            // TProfile *fprof42 = (TProfile*)list->FindObject(foo);

            //..Gap=0.5
            // TString foo(TString::Format("fTprof42_number%0dGap05Ntrks1bin", sample));	
            // TProfile *fprof42 = (TProfile*)list->FindObject(foo);

            //..Gap=0.6
            // TString foo(TString::Format("fTprof42_number%0dGap06Ntrks1bin", sample));	
            // TProfile *fprof42 = (TProfile*)list->FindObject(foo);

            //..Gap=0.7
            // TString foo(TString::Format("fTprof42_number%0dGap07Ntrks1bin", sample));	
            // TProfile *fprof42 = (TProfile*)list->FindObject(foo);

            //..Gap=0.8
            // TString foo(TString::Format("fTprof42_number%0dGap08Ntrks1bin", sample));	
            // TProfile *fprof42 = (TProfile*)list->FindObject(foo);
    
            BinValue42_Sample = fprof42->GetBinContent(i);
            BinValue42 = Cn42->GetBinContent(i); 

            BinValue_Total42 = Cn42->GetBinEffectiveEntries(i);
            BinValue_Total_Sample42 = fprof42->GetBinEffectiveEntries(i);
    
            if(BinValue_Total42 > 1000 && BinValue_Total_Sample42 > 100 ) {
                M += 1;

            if(BinValue42 > 0 && BinValue42_Sample > 0 ) {
                Valuesqrt_4Particle_Correlation = sqrt(BinValue42);
                Valuesqrt_4Particle_Sample = sqrt(BinValue42_Sample);
            
                error_4part += pow(Valuesqrt_4Particle_Sample - Valuesqrt_4Particle_Correlation, 2);
            }
            else continue; 
            cout << "Multiplicity check passed" << endl;
            }
            else continue;
            cout << "The second If statement is passed " << endl;
        
        }
        //cout << "M: " << M << endl;
        final_error_4part = sqrt(error_4part / (N * N) );
        
        if(BinValue_Total42 > 1000 && BinValue_Total_Sample42 > 100 ) {
            hC42->SetBinContent(i, Valuesqrt_4Particle_Correlation);
            hC42->SetBinError(i, final_error_4part);
        }

    }
    //*************************************************************************
     /////////         Cn{2} = <<2>> = < vn^2 >       /////////
    //.. Loop for get the v4{2} = sqrt(<<2>>_{4|-4}) //////
    ////         ***********  << 2 >> ******************    /////
    //************************************************************************
    for(int i=1; i < 201; i++)
    {
        double error_2part = 0.0;
        for(int sample =1; sample < 11; sample++)
        {   
            //..Uden Gap
            TString foo_24(TString::Format("fTprof24_number%dNtrks1bin", sample));
            TProfile *fprof24 = (TProfile*)list->FindObject(foo_24);

            //..Gap= 0.0
            // TString foo_24(TString::Format("fTprof24_number%dGap00Ntrks1bin", sample));
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
            // TString foo_24(TString::Format("fTprof24_number%dGap08Ntrks1bin", sample));
            // TProfile *fprof24 = (TProfile*)list->FindObject(foo_24);

            BinValue24 = Cn24->GetBinContent(i);
            BinValue24_Sample = fprof24->GetBinContent(i);
            
            //..Multiplicity Test:
            BinValue_Total24 = Cn24->GetBinEffectiveEntries(i);
            BinValue_Total_Sapmle24 = fprof24->GetBinEffectiveEntries(i);

            if( BinValue_Total24 > 1000 && BinValue_Total_Sapmle24 > 100) {

            if(BinValue24_Sample > 0 && BinValue24 > 0 ) {
                Valuesqrt_2Particle_Correlation = sqrt(BinValue24);
                Valuesqrt_2Particle_Sample = sqrt(BinValue24_Sample); 
            }
            else continue;
            error_2part += pow(Valuesqrt_2Particle_Sample - Valuesqrt_2Particle_Correlation, 2);

            }
            else continue;
            cout << "Multiplicity check finished: " << i << endl;

        }
        final_error_2part = sqrt(error_2part/ (N * N) );
        
        if( BinValue_Total24 > 1000 && BinValue_Total_Sapmle24 > 100) {
            hC22->SetBinContent(i, Valuesqrt_2Particle_Correlation);
            hC22->SetBinError(i, final_error_2part);
        }
        else continue;
    }
    
    //*************************************************************************
    // //..Loop over fSample for Error propagation for Non-Linear Response:
    //////////////     ************ v422 *******************     //////////
    //**************************************************************************
    for (int j=1; j<201; j++) {
        double error_NL = 0.0;
        for (int i = 1; i < 11; i++) {
            
            //..uden Gap
            TString bar_34(TString::Format("fTprof34_number%dNtrks1bin", i));	
            TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            TString foo_42(TString::Format("fTprof42_number%dNtrks1bin", i));	
            TProfile *prof42 = (TProfile*)list->FindObject(foo_42);
            
            //..Gap= 0.0  
            // TString bar_34(TString::Format("fTprof34_number%dGap00ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap00Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            // //..Gap= 0.1
            // TString bar_34(TString::Format("fTprof34_number%dGap01ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap01Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.2
            // TString bar_34(TString::Format("fTprof34_number%dGap02ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap02Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);
            
            // //..Gap= 0.3  
            // TString bar_34(TString::Format("fTprof34_number%dGap03ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap03Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.4  
            // TString bar_34(TString::Format("fTprof34_number%dGap04ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap04Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.5  
            // TString bar_34(TString::Format("fTprof34_number%dGap05ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap05Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.6
            // TString bar_34(TString::Format("fTprof34_number%dGap06ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap06Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.7
            // TString bar_34(TString::Format("fTprof34_number%dGap07ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap07Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.8
            // TString bar_34(TString::Format("fTprof34_number%dGap08ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap08Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);



            Sample_BinValue_3Particle_Correlation = prof34->GetBinContent(j);
            Sample_BinValue_4Particle_Correlation = prof42->GetBinContent(j);
            
            BinValue_3Particle_Correlation = Cn34->GetBinContent(j);
            BinValue_4Particle_Correlation = Cn42->GetBinContent(j);

        //..Check for Multiplicity, in the way in the sampling plot has to be at least N_ch>100 and for         total N_ch>1000 in each bins. 

            BinValue_Total_34 = Cn34->GetBinEffectiveEntries(j);
            BinValue_Total_42 = Cn42->GetBinEffectiveEntries(j);

            BinValue_Total_Sample_34 = prof34->GetBinEffectiveEntries(j);
            BinValue_Total_Sample_42 = prof42->GetBinEffectiveEntries(j);
            
            if(BinValue_Total_34 > 1000 && BinValue_Total_42 > 1000 && BinValue_Total_Sample_34 >100 && BinValue_Total_Sample_42 > 100) {

            if (Sample_BinValue_4Particle_Correlation > 0  && BinValue_4Particle_Correlation > 0 && BinValue_3Particle_Correlation > 0 && Sample_BinValue_3Particle_Correlation > 0 ) {
            
                Valuesqrt_4Particle_Correlation = sqrt(BinValue_4Particle_Correlation);
                Sample_Valuesqrt_4Particle_Correlation = sqrt(Sample_BinValue_4Particle_Correlation);
                
                V422 = BinValue_3Particle_Correlation / Valuesqrt_4Particle_Correlation;
                V422_Sample = Sample_BinValue_3Particle_Correlation / Sample_Valuesqrt_4Particle_Correlation; 
                
                error_NL += pow(V422_Sample - V422, 2);

            }
            else continue; 
            cout << "The If statement for BinContent is passed " << endl;
            }
            else continue;
            cout << "Multiplicity Check passed: " << j << endl; 

        }
        sigma_z1 = sqrt(error_NL/ (N * N) );
        
        if( BinValue_Total_34 > 1000 && BinValue_Total_42 > 1000 && BinValue_Total_Sample_34 >100 && BinValue_Total_Sample_42 >100) {
            hV422->SetBinContent(j, V422);
            hV422->SetBinError(j, sigma_z1); 
        }
        else continue;        
    }
        //***************************************************************************************************
        //..Linear Response calculation:****
        // *********************************
        //.. The L and NL are uncorrelated means they are perpendicular so they make a 90 triangle 
        /////  when the "Hypotenuse" is v4 (sqrt(<<2>>_{4|-4})) 
        ///  and the two others are L response and Non-Linear response which is the 
        // NL----->  "<<3>> / sqrt(<<4>>)" so by 
        ///  using the "Pythagorean theoerem" the v4^2 = L^2 + NL ^2 
        /////              L^2 = v4^2 - NL^2  we don't have L response so
        /////              L = sqrt (v4^2 - NL^2) 
        ///// Here v4 is sqrt( <<2>>_{4,-4})  &&    NL is <<3>> /sqrt(<<4>> )
        //***************************************************************************************************

    for (int j=1; j<201; j++) {
        double Counter = 0.0;
        double error_L = 0.0;
        for (int i = 1; i < 11; i++) {
            //..Uden Gap 
            // TString foo_24(TString::Format("fTprof24_number%dNtrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dNtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dNtrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.0
            // TString foo_24(TString::Format("fTprof24_number%dGap00Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap00ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap00Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.1
            // TString foo_24(TString::Format("fTprof24_number%dGap01Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap01ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap01Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.2
            // TString foo_24(TString::Format("fTprof24_number%dGap02Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap02ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap02Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.3
            // TString foo_24(TString::Format("fTprof24_number%dGap03Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap03ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap03Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.4
            // TString foo_24(TString::Format("fTprof24_number%dGap04Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap04ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap04Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.5
            // TString foo_24(TString::Format("fTprof24_number%dGap05Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap05ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap05Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.6
            // TString foo_24(TString::Format("fTprof24_number%dGap06Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap06ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap06Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.7
            // TString foo_24(TString::Format("fTprof24_number%dGap07Ntrks1bin", i));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap07ANtrks1bin", i));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap07Ntrks1bin", i));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.8
            TString foo_24(TString::Format("fTprof24_number%dGap08Ntrks1bin", i));
            TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            TString bar_34(TString::Format("fTprof34_number%dGap08ANtrks1bin", i));	
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

            BinValue_Total_Sample_24 = prof24->GetBinEffectiveEntries(j);
            BinValue_Total_Sample_34 = prof34->GetBinEffectiveEntries(j);
            BinValue_Total_Sample_42 = prof42->GetBinEffectiveEntries(j);
            
            if( BinValue_Total_24 > 1000 && BinValue_Total_34 > 1000 && BinValue_Total_42 > 1000 && BinValue_Total_Sample_24 >100 && BinValue_Total_Sample_34 >100 && BinValue_Total_Sample_42 >100) {
                if(Sample_BinValue_2Particle_Correlation > 0 && Sample_BinValue_4Particle_Correlation > 0 && BinValue_4Particle_Correlation > 0 && BinValue_2Particle_Correlation > 0 ) {

                    Sample_Valuesqrt_2particle_correlation = sqrt(Sample_BinValue_2Particle_Correlation);
                    Sample_Valuesqrt_4particle_correlation = sqrt(Sample_BinValue_4Particle_Correlation);
                    
                    Valuesqrt_2Particle_Correlation = sqrt(BinValue_2Particle_Correlation);
                    Valuesqrt_4Particle_Correlation = sqrt(BinValue_4Particle_Correlation);
                    
                    //..Calculate v422 Non-Linear:
                    V422 = BinValue_3Particle_Correlation / (Valuesqrt_4Particle_Correlation);
                    V422_Sample = Sample_BinValue_3Particle_Correlation / (Sample_Valuesqrt_4particle_correlation);               
                    
                    Linear = pow(Valuesqrt_2Particle_Correlation, 2) - pow(V422, 2);   
                    Sample_Linear = pow(Sample_Valuesqrt_2particle_correlation, 2) - pow(V422_Sample, 2); 
            
                if(Sample_Linear > 0 && Linear > 0 ) {
                    Linear_value_sample = sqrt(Sample_Linear);
                    Linear_value = sqrt(Linear);
                    error_L += pow(Linear_value_sample - Linear_value, 2);
                }
                else continue;
                
                }
                else continue; 
                
            Counter += 1;
            }
            else continue; 
            cout << "*******************************" << endl;
            cout << "Sampleing: " << i << endl;
            cout << "Multiplicity check finished Bin: " << j << endl; 
            cout << "Counter : " << Counter << endl;
            cout << "*********************************" << endl;
        }
        cout << "TEST TeST !!! Counter : " << Counter << endl;
        Linear_Error = sqrt(error_L/ (Counter * Counter) );
        if( BinValue_Total_24 > 1000 && BinValue_Total_34 > 1000 && BinValue_Total_42 > 1000 && BinValue_Total_Sample_24 >100 && BinValue_Total_Sample_34 >100 && BinValue_Total_Sample_42 >100) {
            hCLinear->SetBinContent(j, Linear_value); 
            hCLinear->SetBinError(j, Linear_Error); 
        }
        else continue;
        
    }

    
    //************************************************************************      
    //..Plot the Histograms

    ///..V2{4}: << 4 >>_{22,-2-2}
    // hC42->SetLineColor(kRed);
    // hC42->SetMarkerStyle(20);
    // hC42->SetMarkerColorAlpha(kRed, 4.5);
    // //hC42->SetAxisRange(0., 110);
    // hC42->SetMarkerSize(1.);
    // hC42->SetXTitle("# of tracks");
    // gStyle->SetOptStat(0);
    //hC42->Draw("same");

    // //..V4{2}: << 2 >>_{4,-4}
    // hC22->SetLineColor(kBlue);
    // hC22->SetMarkerStyle(20);
    // hC22->SetMarkerColorAlpha(kBlue, 4.5);
    // //hC22->SetAxisRange(0., 110);
    // hC22->SetMarkerSize(1.);
    // hC22->SetXTitle("# of tracks");
    // gStyle->SetOptStat(0);
    // hC22->Draw("same");
    

    //..V4^L
    // hCLinear->SetMarkerStyle(21);
    // hCLinear->SetMarkerColorAlpha(kBlack, 4.5);
    // //hCLinear->SetAxisRange(0., 110);
    // hCLinear->SetMarkerSize(1.);
    hCLinear->Draw("same");

    //..V422_NL
    // hV422->SetMarkerStyle(34);
    // hV422->SetMarkerColorAlpha(kBlue, 0.45);
    // //hV422->GetYaxis()->SetRangeUser(0., 3.);
    // //hV422->GetXaxis()->SetRangeUser(0., 140);
    // hV422->SetMarkerSize(2.);
	//hV422->Draw("same");
    //c->BuildLegend();
    
    
    //..Create a root.file:
    //..Uden Gap
    // TFile* fileOutput_1 = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/WO_V422_NL_Linear_NUA+NUE.root","UPDATE");
    // if(!fileOutput_1) return;
    // fileOutput_1->cd();
    // hV422->Write("WO_hV422_NL_NUA+NUE");
    // hCLinear->Write("WO_hCLinear_NUA+NUE");
    // hC22->Write("WO_hC22_NUA+NUE");
    // hC42->Write("WO_hC42_NUA+NUE");
   
    
    //..Gap= 0.0, 0.1, 0.2, 0.3, 0.4,..., 0.8
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/V422_NL_Linear_NUA+NUE.root","UPDATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hV422->Write("Gap08A_hV422_NL_NUA+NUE");
    // hCLinear->Write("Gap08A_hCLinear_NUA+NUE");
    // hC22->Write("Gap08A_hC22_NUA+NUE");
    // hC42->Write("Gap08A_hC42_NUA+NUE");
}