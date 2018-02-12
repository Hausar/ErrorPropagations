
//Macro To Calculate the Chi422, Chi532 Error Propagation:
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

void All_Gaps_Chi422_Chi_532() {
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
    
    //..Chiv532
    double BinValue_22Particle_Correlation = 0.0;
    double BinValue_23Particle_Correlation = 0.0;
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

    
    double BinValue25_Sample; 
    double BinValue25; 
    double NL_BinValue_hCV422;
    double Linear;
    double Linear_value; 
    double Linear_value_sample;
    double final_error;
    double Linear_Error; 
    int N = 10.;
    double fsample_Linear; 

    double BinValue_Total34;
    double BinValue_Total42;
    double BinValue_Sample34;
    double BinValue_Sample42;
    double BinValue_Total35;
    double BinValue_Total22;
    double BinValue_Total23;
    double BinValue_Sample35;
    double BinValue_Sample22;
    double BinValue_Sample23;
     


    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    

    TH1D *hChi422 = new TH1D("hChi422", "The Non-Linear Coefficient, #chi_{4,22}", 200, 0, 200); //this is just define a histogram which will fill the data of Chi_422.
    hChi422->Sumw2();


    TH1D *hChi532 = new TH1D("hChi532", "The Non-Linear Coefficient, #chi_{5,32}", 200, 0, 200); //this is just define a histogram which will fill the data of Chi_532.
    hChi532->Sumw2();


    //Open the root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/LHC16q_CENT_SDD_0Gap_2_08Gap_FullGaps.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("MyTaskResults");
    TList *list = (TList*)dir->Get("Flow_Refs_MyTaskResults");
    
    //**************************************************************************
    //..Chi422:
    //..WO Gap
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

    // //..Gap= 0.2
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap02Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap02Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap02Ntrks1bin"); 

    // //..Gap= 0.3
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap03Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap03Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap03Ntrks1bin"); 

    // //..Gap= 0.4
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap04Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap04Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap04Ntrks1bin"); 

    // //..Gap= 0.5
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap05Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap05Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap05Ntrks1bin"); 

    // //..Gap= 0.6
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap06Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap06Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap06Ntrks1bin"); 

    // //..Gap= 0.7
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap07Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap07Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap07Ntrks1bin"); 

    //..Gap= 0.8
    TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap08Ntrks1bin");
    TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap08Ntrks1bin");  
    TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap08Ntrks1bin"); 
    
    //**************************************************************************
    //..Chi_532:
    //..WO Gap
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Ntrks1bin");  //..<<3>>_{5|-3,-2}
    
    // //..Gap= 0.0
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap0Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap0Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap0Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap0Ntrks1bin");  //..<<3>>_{5|-3,-2}
    
    // //..Gap= 0.1
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap01Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap01Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap01Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap01Ntrks1bin");  //..<<3>>_{5|-3,-2}

    //..Gap= 0.2
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap02Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap02Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap02Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap02Ntrks1bin");  //..<<3>>_{5|-3,-2}

    // // //..Gap= 0.3
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap03Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap03Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap03Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap03Ntrks1bin");  //..<<3>>_{5|-3,-2}

    //..Gap= 0.4
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap04Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap04Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap04Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap04Ntrks1bin");  //..<<3>>_{5|-3,-2}

    //..Gap= 0.5
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap05Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap05Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap05Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap05Ntrks1bin");  //..<<3>>_{5|-3,-2}

    // //..Gap= 0.6
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap06Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap06Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap06Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap06Ntrks1bin");  //..<<3>>_{5|-3,-2}

    // //..Gap= 0.7
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap07Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap07Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap07Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap07Ntrks1bin");  //..<<3>>_{5|-3,-2}

    //..Gap= 0.8
    TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap08Ntrks1bin");  //..V5{2}
    TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap08Ntrks1bin");  //..v2^{2}
    TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap08Ntrks1bin");  //..v3^{2}
    TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap08Ntrks1bin");  //..<<3>>_{5|-3,-2}

    //..Projection on Xaxis:
    TH1D *h1 = Cn24->ProjectionX("h1");
    TH1D *h2 = Cn42->ProjectionX("h2");
    TH1D *h3 = Cn34->ProjectionX("h3");

    //******************************************************************************
    //..Loop over fSample for Error propagation for Non-Linear Coefficient Chi_4,22:

    for (int i=1; i<201; i++) {
        double error = 0.0;
        for (int sample = 1; sample < 11; sample++) {
            //..WO Gap
            // TString bar_34(TString::Format("fTprof34_number%dNtrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dNtrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            // //..Gap= 0.0
            // TString bar_34(TString::Format("fTprof34_number%dGap0Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap0Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.1
            // TString bar_34(TString::Format("fTprof34_number%dGap01Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap01Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            // //..Gap= 0.2
            // TString bar_34(TString::Format("fTprof34_number%dGap02Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap02Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            // //..Gap= 0.3
            // TString bar_34(TString::Format("fTprof34_number%dGap03Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap03Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            // //..Gap= 0.4
            // TString bar_34(TString::Format("fTprof34_number%dGap04Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap04Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.5
            // TString bar_34(TString::Format("fTprof34_number%dGap05Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap05Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            // //..Gap= 0.6
            // TString bar_34(TString::Format("fTprof34_number%dGap06Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap06Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            // //..Gap= 0.7
            // TString bar_34(TString::Format("fTprof34_number%dGap07Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap07Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.8
            TString bar_34(TString::Format("fTprof34_number%dGap08Ntrks1bin", sample));	
            TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            TString foo_42(TString::Format("fTprof42_number%dGap08Ntrks1bin", sample));	
            TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            
            Sample_BinValue_3Particle_Correlation = prof34->GetBinContent(i);
            Sample_BinValue_4Particle_Correlation = prof42->GetBinContent(i);
            
            BinValue_3Particle_Correlation = Cn34->GetBinContent(i);
            BinValue_4Particle_Correlation = Cn42->GetBinContent(i);

            //..Test Multiplicity
            BinValue_Total34 = Cn34->GetBinEffectiveEntries(i);
            BinValue_Total42 = Cn42->GetBinEffectiveEntries(i);

            BinValue_Sample34 = prof34->GetBinEffectiveEntries(i);
            BinValue_Sample42 = prof42->GetBinEffectiveEntries(i);

            if( BinValue_Total34 > 1000 && BinValue_Total42 > 1000 && BinValue_Sample34 > 100 && BinValue_Sample42 > 100 ) {
                cout << "Passed Multiplicity Test Good" << endl;
                cout << "******************************" << endl;
                cout << "i: " << i << endl;
                cout << "Sample: " << sample << endl;
                cout << "BinValue_Total34: " << BinValue_Total34 << endl;
                cout <<"BinValue_Sample34: " << BinValue_Sample34 << endl;

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
            cout << "The Second If statement for Positive Bin content is passed" << endl; 

            }
            else continue;
            cout << "Multiplicity check is finished" << endl;  

            
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
            cout << "-----------------------------" << endl;		
            cout << "Chi422: " << Chi422 << endl;
            //cout << "Chi422_Sample: " << Chi422_Sample << endl;
        }
        sigma_z1 = sqrt(error/ (N * N) );
        if( BinValue_Total34 > 1000 && BinValue_Total42 > 1000 && BinValue_Sample34 > 100 && BinValue_Sample42 > 100 ) {
            hChi422->SetBinContent(i, Chi422);
            hChi422->SetBinError(i, sigma_z1);    
        }
        else continue; 
        cout << "BinValue_Total34: " << BinValue_Total34 << endl;
        cout <<"BinValue_Sample34: " << BinValue_Sample34 << endl;   
    }


    //**************************************************************************
    //..Loop over fSample for Error propagation for Non-Linear Response:

    for (int i=1; i<201; i++) {
        double error = 0.0;
        for (int sample = 1; sample < 11; sample++) {
            //..WO Gap
            // TString bar_35(TString::Format("fTprof35_number%dNtrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dNtrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dNtrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            //..Gap= 0.0
            // TString bar_35(TString::Format("fTprof35_number%dGap0Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap0Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap0Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            // //..Gap= 0.1
            // TString bar_35(TString::Format("fTprof35_number%dGap01Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap01Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap01Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            // // //..Gap= 0.2
            // TString bar_35(TString::Format("fTprof35_number%dGap02Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap02Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap02Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            // //..Gap= 0.3
            // TString bar_35(TString::Format("fTprof35_number%dGap03Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap03Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap03Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            // //..Gap= 0.4
            // TString bar_35(TString::Format("fTprof35_number%dGap04Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap04Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap04Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            // //..Gap= 0.5
            // TString bar_35(TString::Format("fTprof35_number%dGap05Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap05Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap05Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            // //..Gap= 0.6
            // TString bar_35(TString::Format("fTprof35_number%dGap06Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap06Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap06Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            //..Gap= 0.7
            // TString bar_35(TString::Format("fTprof35_number%dGap07Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap07Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap07Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            //..Gap= 0.8 
            TString bar_35(TString::Format("fTprof35_number%dGap08Ntrks1bin", sample));	
            TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            TString foo_22(TString::Format("fTprof22_number%dGap08Ntrks1bin", sample));	
            TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            TString foo_23(TString::Format("fTprof23_number%dGap08Ntrks1bin", sample));	
            TProfile *prof23 = (TProfile*)list->FindObject(foo_23);




            Sample_BinValue_3Particle_Correlation = prof35->GetBinContent(i);
            Sample_BinValue_22Particle_Correlation = prof22->GetBinContent(i);
            Sample_BinValue_23Particle_Correlation = prof23->GetBinContent(i);

            BinValue_3Particle_Correlation = Cn35->GetBinContent(i);
            BinValue_22Particle_Correlation = Cn22->GetBinContent(i);
            BinValue_23Particle_Correlation = Cn23->GetBinContent(i);

            //..Test Multiplicity
            BinValue_Total35 = Cn35->GetBinEffectiveEntries(i);
            BinValue_Total22 = Cn22->GetBinEffectiveEntries(i);
            BinValue_Total23 = Cn23->GetBinEffectiveEntries(i);

            BinValue_Sample35 = prof35->GetBinEffectiveEntries(i);
            BinValue_Sample22 = prof22->GetBinEffectiveEntries(i);
            BinValue_Sample23 = prof23->GetBinEffectiveEntries(i);

            if( BinValue_Total35 > 1000 && BinValue_Total22 > 1000 && BinValue_Total23 > 1000 && BinValue_Sample35 > 100 && BinValue_Sample22 > 100 && BinValue_Sample23 > 100 ) {
                cout << "Passed Multiplicity Test Good" << endl;
                cout << "******************************" << endl;
                cout << "i: " << i << endl;
                cout << "Sample: " << sample << endl;
                cout << "BinValue_Total35: " << BinValue_Total35 << endl;
                cout <<"BinValue_Sample35: " << BinValue_Sample35 << endl;

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
            cout << "The Second If statement is passed: " << i << endl; 
            }
            else continue; 
            cout << "Multiplicity check is finished: " << i << endl; 
            cout << "***********************************************************" << endl; 


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
        if( BinValue_Total35 > 1000 && BinValue_Total22 > 1000 && BinValue_Total23 > 1000 && BinValue_Sample35 > 100 && BinValue_Sample22 > 100 && BinValue_Sample23 > 100 ) {
            hChi532->SetBinContent(i, Chi532);
            hChi532->SetBinError(i, sigma_z1);  
        }
        else continue; 

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

    // hChi422->SetMarkerStyle(21);
    // hChi422->SetMarkerColorAlpha(kBlack, 4.5);
    // //hChi422->SetAxisRange(0., 110, "X");
    // hChi422->GetYaxis()->SetRangeUser(0., 3.);
    // hChi422->GetXaxis()->SetRangeUser(0., 140);
    // hChi422->SetMarkerSize(1.);
    hChi422->Draw("same");
    c->BuildLegend();
    
    // hChi532->Draw("same");
    // c->BuildLegend();


    //..Create a root.file:
    //..WO Gap
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/WOGap_NewCondition_Chi_422_Chi_532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hChi422->Write();
    // hChi532->Write();
    // return;

    //..Gap= 0.0
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Gap00_NewCondition_Chi_422_Chi_532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hChi422->Write();
    // hChi532->Write();
    // return;
    
    //..Gap= 0.1
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Gap01_NewCondition_Chi_422_Chi_532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hChi422->Write();
    // hChi532->Write();
    // return;

    //..Gap= 0.2
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Gap02_NewCondition_Chi_422_Chi_532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hChi422->Write();
    // hChi532->Write();
    // return;

    //..Gap= 0.3
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Gap03_NewCondition_Chi_422_Chi_532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hChi422->Write();
    // hChi532->Write();
    // return;

    // //..Gap= 0.4    
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Gap04_NewCondition_Chi_422_Chi_532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hChi422->Write();
    // hChi532->Write();
    // return;


    // //..Gap= 0.5    
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Gap05_NewCondition_Chi_422_Chi_532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hChi422->Write();
    // hChi532->Write();
    // return;

    // //..Gap= 0.6
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Gap06_NewCondition_Chi_422_Chi_532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hChi422->Write();
    // hChi532->Write();
    // return;

    // //..Gap= 0.7
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Gap07_NewCondition_Chi_422_Chi_532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hChi422->Write();
    // hChi532->Write();
    // return;

    //..Gap= 0.8
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Gap08_NewCondition_Chi_422_Chi_532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hChi422->Write();
    // hChi532->Write();
    // return;
}