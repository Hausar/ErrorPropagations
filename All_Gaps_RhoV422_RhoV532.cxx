//Macro To Calculate the Rho_V4 and Rho_V5:
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

void All_Gaps_RhoV422_RhoV532() {
double Sample_BinValue_2Particle_Correlation;
double Sample_BinValue_3Particle_Correlation;
double Sample_BinValue_4Particle_Correlation;
double BinValue_2Particle_Correlation;
double BinValue_3Particle_Correlation;
double BinValue_4Particle_Correlation;
double Sample_Valuesqrt_2particle_correlation;
double Sample_Valuesqrt_4particle_correlation;
double Valuesqrt_2Particle_Correlation;
double Valuesqrt_4Particle_Correlation;
double V422;
double V422_Sample;
double RhoV422; 
double RhoV422_Sample;

//...
double Sample_BinValue_25Particle_Correlation = 0.0;
double Sample_BinValue_35Particle_Correlation = 0.0;
double Sample_BinValue_22Particle_Correlation = 0.0;
double Sample_BinValue_23Particle_Correlation = 0.0;
double BinValue_25Particle_Correlation = 0.0;
double BinValue_35Particle_Correlation = 0.0;
double BinValue_22Particle_Correlation = 0.0;
double BinValue_23Particle_Correlation = 0.0;
double Sample_Value_sqrt_22particle_correlation = 0.0;
double Sample_Value_sqrt_23particle_correlation = 0.0;
double Sample_Value_sqrt_25particle_correlation = 0.0;
double Valuesqrt_22Particle_Correlation = 0.0;
double Valuesqrt_23Particle_Correlation = 0.0;
double Valuesqrt_25Particle_Correlation = 0.0;
double V532;
double V532_Sample; 
double RhoV532; 
double RhoV532_Sample;

double Final_Error;
int N = 10;


    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    TH1D *hRho_V422 = new TH1D("hRho_V422", "#rho_{4,22} = < cos (4 #Psi_{4} - 4 #Psi_{2}) > ", 200, 0, 200); //this is just define a histogram which will fill the data.
    hRho_V422->Sumw2();

    TH1D *hRho_V532 = new TH1D("hRho_V532", "#rho_{5,32} = < cos (5 #Psi_{5} - 3 #Psi_{3} - 2 #Psi_{2}) > ", 200, 0, 200); //this is just define a histogram which will fill the data.
    hRho_V532->Sumw2();
    
    TH1D *hC42 = new TH1D("hC42", " #sqrt{< v_{2}^{4} >}", 200, 0, 200); //this is just define a histogram 
	hC42->Sumw2();
    //..hCV422 is Non-Linear response and hC22 is V4{2} = sqrt(<v4^2>)
    
    //..Open root.file contains info:
    // TFile *file = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/V4_AllGaps/Gap0_V4_Linear_NonLinear_Response.root", "Read");
    // if(!file) return;  
    // hCV422 = (TH1D*)file->Get("hCV422");
    // hC22 = (TH1D*) file->Get("hC22");

    //Open the root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/LHC16q_CENT_SDD_0Gap_2_08Gap_FullGaps.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("MyTaskResults");
    TList *list = (TList*)dir->Get("Flow_Refs_MyTaskResults");
    //**************************************************************************
    //..v4,22
    //..WO Gap
    TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Ntrks1bin");
    TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Ntrks1bin");  
    TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Ntrks1bin"); 
    
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
    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC24Gap08Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap08Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap08Ntrks1bin"); 
    //**************************************************************************
    //..v5,32
    //..WO Gap
    TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Ntrks1bin");  //..V5{2}
    TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Ntrks1bin");  //..v2^{2}
    TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Ntrks1bin");  //..v3^{2}
    TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Ntrks1bin");  //..<<3>>_{5|-3,-2}
    
    //..Gap= 0.0
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap0Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap0Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap0Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap0Ntrks1bin");  //..<<3>>_{5|-3,-2}

    //..Gap= 0.1
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap01Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap01Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap01Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap01Ntrks1bin");  //..<<3>>_{5|-3,-2}

    //..Gap= 0.2
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap02Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap02Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap02Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap02Ntrks1bin");  //..<<3>>_{5|-3,-2}

    //..Gap= 0.3
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

    //..Gap= 0.6
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap06Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap06Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap06Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap06Ntrks1bin");  //..<<3>>_{5|-3,-2}

    //..Gap= 0.7
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap07Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap07Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap07Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap07Ntrks1bin");  //..<<3>>_{5|-3,-2}

    //..Gap= 0.8
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Gap08Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Gap08Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Gap08Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap08Ntrks1bin");  //..<<3>>_{5|-3,-2}

    //**************************************************************************
    //..Loop over bins to calculate rho:
    for(int i=1; i<201; i++) {
        double error = 0.0;
        for(int sample=1; sample < 11; sample++ ) {
            //..WO Gap
            TString foo_24(TString::Format("fTprof24_number%dNtrks1bin", sample));
            TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            TString bar_34(TString::Format("fTprof34_number%dNtrks1bin", sample));	
            TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            TString foo_42(TString::Format("fTprof42_number%dNtrks1bin", sample));	
            TProfile *prof42 = (TProfile*)list->FindObject(foo_42);
            
            //..Gap= 0.0
            // TString foo_24(TString::Format("fTprof24_number%dGap0Ntrks1bin", sample));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap0Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap0Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.1
            // TString foo_24(TString::Format("fTprof24_number%dGap01Ntrks1bin", sample));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap01Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap01Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);
            
            //..Gap= 0.2
            // TString foo_24(TString::Format("fTprof24_number%dGap02Ntrks1bin", sample));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap02Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap02Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.3
            // TString foo_24(TString::Format("fTprof24_number%dGap03Ntrks1bin", sample));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap03Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap03Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.4
            // TString foo_24(TString::Format("fTprof24_number%dGap04Ntrks1bin", sample));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap04Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap04Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.5
            // TString foo_24(TString::Format("fTprof24_number%dGap05Ntrks1bin", sample));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap05Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap05Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.6
            // TString foo_24(TString::Format("fTprof24_number%dGap06Ntrks1bin", sample));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap06Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap06Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.7
            // TString foo_24(TString::Format("fTprof24_number%dGap07Ntrks1bin", sample));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap07Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap07Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            //..Gap= 0.8
            // TString foo_24(TString::Format("fTprof24_number%dGap08Ntrks1bin", sample));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo_24);
            // TString bar_34(TString::Format("fTprof34_number%dGap08Ntrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar_34);
            // TString foo_42(TString::Format("fTprof42_number%dGap08Ntrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo_42);

            Sample_BinValue_2Particle_Correlation = prof24->GetBinContent(i);
            Sample_BinValue_3Particle_Correlation = prof34->GetBinContent(i);
            Sample_BinValue_4Particle_Correlation = prof42->GetBinContent(i);

            BinValue_2Particle_Correlation = Cn24->GetBinContent(i);
            BinValue_3Particle_Correlation = Cn34->GetBinContent(i);
            BinValue_4Particle_Correlation = Cn42->GetBinContent(i);

            if(Sample_BinValue_2Particle_Correlation > 0 && Sample_BinValue_4Particle_Correlation > 0 && BinValue_4Particle_Correlation > 0 && BinValue_2Particle_Correlation > 0 ) {
                
                Sample_Valuesqrt_2particle_correlation = sqrt(Sample_BinValue_2Particle_Correlation);
                Sample_Valuesqrt_4particle_correlation = sqrt(Sample_BinValue_4Particle_Correlation);
                
                Valuesqrt_2Particle_Correlation = sqrt(BinValue_2Particle_Correlation);
                Valuesqrt_4Particle_Correlation = sqrt(BinValue_4Particle_Correlation);
            }
            else continue;
            if(Valuesqrt_4Particle_Correlation > 0 && Sample_Valuesqrt_4particle_correlation > 0 && Sample_BinValue_3Particle_Correlation > 0 && BinValue_3Particle_Correlation > 0 ){
                
                V422 = BinValue_3Particle_Correlation / (Valuesqrt_4Particle_Correlation);
                V422_Sample = Sample_BinValue_3Particle_Correlation / (Sample_Valuesqrt_4particle_correlation); 
                
                RhoV422 = V422 / (Valuesqrt_2Particle_Correlation);
                RhoV422_Sample = V422_Sample / (Sample_Valuesqrt_2particle_correlation);
                error += pow(RhoV422_Sample - RhoV422, 2);
            }
            else continue;
        }
        Final_Error = sqrt(error/ (N * N) );           
        hRho_V422->SetBinContent(i, RhoV422); 
        hRho_V422->SetBinError(i, Final_Error);    
    }

    //..V5,32 Calculation for Rho_532:
    for (int i=1; i<201; i++) {
        double error = 0.0;
        for (int sample = 1; sample < 11; sample++) {
            //..WO Gap
            TString foo_25(TString::Format("fTprof25_number%dNtrks1bin", sample));
            TProfile *prof25 = (TProfile*)list->FindObject(foo_25);
            TString bar_35(TString::Format("fTprof35_number%dNtrks1bin", sample));	
            TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            TString foo_22(TString::Format("fTprof22_number%dNtrks1bin", sample));	
            TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            TString foo_23(TString::Format("fTprof23_number%dNtrks1bin", sample));	
            TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            //..Gap= 0.0
            // TString foo_25(TString::Format("fTprof25_number%dGap0Ntrks1bin", sample));
            // TProfile *prof25 = (TProfile*)list->FindObject(foo_25);
            // TString bar_35(TString::Format("fTprof35_number%dGap0Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap0Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap0Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            //..Gap= 0.1
            // TString foo_25(TString::Format("fTprof25_number%dGap01Ntrks1bin", sample));
            // TProfile *prof25 = (TProfile*)list->FindObject(foo_25);
            // TString bar_35(TString::Format("fTprof35_number%dGap01Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap01Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap01Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            //..Gap= 0.2
            // TString foo_25(TString::Format("fTprof25_number%dGap02Ntrks1bin", sample));
            // TProfile *prof25 = (TProfile*)list->FindObject(foo_25);
            // TString bar_35(TString::Format("fTprof35_number%dGap02Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap02Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap02Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            //..Gap= 0.3
            // TString foo_25(TString::Format("fTprof25_number%dGap03Ntrks1bin", sample));
            // TProfile *prof25 = (TProfile*)list->FindObject(foo_25);
            // TString bar_35(TString::Format("fTprof35_number%dGap03Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap03Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap03Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            //..Gap= 0.4
            // TString foo_25(TString::Format("fTprof25_number%dGap04Ntrks1bin", sample));
            // TProfile *prof25 = (TProfile*)list->FindObject(foo_25);
            // TString bar_35(TString::Format("fTprof35_number%dGap04Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap04Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap04Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            //..Gap= 0.5
            // TString foo_25(TString::Format("fTprof25_number%dGap05Ntrks1bin", sample));
            // TProfile *prof25 = (TProfile*)list->FindObject(foo_25);
            // TString bar_35(TString::Format("fTprof35_number%dGap05Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap05Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap05Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            //..Gap= 0.6
            // TString foo_25(TString::Format("fTprof25_number%dGap06Ntrks1bin", sample));
            // TProfile *prof25 = (TProfile*)list->FindObject(foo_25);
            // TString bar_35(TString::Format("fTprof35_number%dGap06Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap06Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap06Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            //..Gap= 0.7
            // TString foo_25(TString::Format("fTprof25_number%dGap07Ntrks1bin", sample));
            // TProfile *prof25 = (TProfile*)list->FindObject(foo_25);
            // TString bar_35(TString::Format("fTprof35_number%dGap07Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap07Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap07Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            //..Gap= 0.8
            // TString foo_25(TString::Format("fTprof25_number%dGap08Ntrks1bin", sample));
            // TProfile *prof25 = (TProfile*)list->FindObject(foo_25);
            // TString bar_35(TString::Format("fTprof35_number%dGap08Ntrks1bin", sample));	
            // TProfile *prof35 = (TProfile*)list->FindObject(bar_35);
            // TString foo_22(TString::Format("fTprof22_number%dGap08Ntrks1bin", sample));	
            // TProfile *prof22 = (TProfile*)list->FindObject(foo_22);
            // TString foo_23(TString::Format("fTprof23_number%dGap08Ntrks1bin", sample));	
            // TProfile *prof23 = (TProfile*)list->FindObject(foo_23);

            Sample_BinValue_25Particle_Correlation = prof25->GetBinContent(i);
            Sample_BinValue_35Particle_Correlation = prof35->GetBinContent(i);
            Sample_BinValue_22Particle_Correlation = prof22->GetBinContent(i);
            Sample_BinValue_23Particle_Correlation = prof23->GetBinContent(i);

            BinValue_25Particle_Correlation = Cn25->GetBinContent(i);
            BinValue_35Particle_Correlation = Cn35->GetBinContent(i);
            BinValue_22Particle_Correlation = Cn22->GetBinContent(i);
            BinValue_23Particle_Correlation = Cn23->GetBinContent(i);
            
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

                RhoV532 = V532 / (Valuesqrt_25Particle_Correlation);
                RhoV532_Sample = V532_Sample / (Sample_Value_sqrt_25particle_correlation);
                error += pow(RhoV532_Sample - RhoV532, 2);
            }
            else continue;
        }         
        Final_Error = sqrt(error/ (N * N) );           
        hRho_V532->SetBinContent(i, RhoV532); 
        hRho_V532->SetBinError(i, Final_Error);
    }
    // hC22->SetMarkerStyle(20);
    // hC22->SetMarkerColorAlpha(kRed, 4.5);
    // hC22->SetAxisRange(0., 110);
    // hC22->SetMarkerSize(1.);
    // hC22->SetXTitle("# of tracks");
    // hC22->Draw("same");
    
    // hCV422->SetMarkerStyle(34);
    // hCV422->SetMarkerColorAlpha(kBlue, 0.45);
    // hCV422->SetAxisRange(0., 110);
    // hCV422->SetMarkerSize(2.);
	// hCV422->Draw("same");
    
    // hRho_V422->SetMarkerStyle(20);
    // hRho_V422->SetMarkerColorAlpha(kBlue, 4.5);
    // hRho_V422->SetAxisRange(0., 110);
    // hRho_V422->SetMarkerSize(1.);
    // hRho_V422->SetXTitle("# of tracks");
    hRho_V422->Draw();
    c->BuildLegend();

    // hRho_V532->SetMarkerStyle(20);
    // hRho_V532->SetMarkerColorAlpha(kRed, 4.5);
    // hRho_V532->SetAxisRange(0., 110);
    // hRho_V532->SetMarkerSize(1.);
    // hRho_V532->SetXTitle("# of tracks");
    hRho_V532->Draw();
    c->BuildLegend();


    //..Gap= Without Gap
    TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/WOGap_Rho_v422_Rho_v532.root","RECREATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hRho_V422->Write();
    hRho_V532->Write();
    fileOutput->Close();
    return;

    //..Gap= 0.0
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/Gap0_Rho_v422_Rho_v532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hRho_V422->Write();
    // hRho_V532->Write();
    // fileOutput->Close();
    // return;

    //..Gap= 0.1
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/Gap01_Rho_v422_Rho_v532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hRho_V422->Write();
    // hRho_V532->Write();
    // fileOutput->Close();
    // return;

    //..Gap= 0.2
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/Gap02_Rho_v422_Rho_v532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hRho_V422->Write();
    // hRho_V532->Write();
    // fileOutput->Close();
    // return;

    //..Gap= 0.3
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/Gap03_Rho_v422_Rho_v532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hRho_V422->Write();
    // hRho_V532->Write();
    // fileOutput->Close();
    // return;

    //..Gap= 0.4
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/Gap04_Rho_v422_Rho_v532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hRho_V422->Write();
    // hRho_V532->Write();
    // fileOutput->Close();
    // return;

    //..Gap= 0.5
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/Gap05_Rho_v422_Rho_v532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hRho_V422->Write();
    // hRho_V532->Write();
    // fileOutput->Close();
    // return;

    //..Gap= 0.6
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/Gap06_Rho_v422_Rho_v532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hRho_V422->Write();
    // hRho_V532->Write();
    // fileOutput->Close();
    // return;

    //..Gap= 0.7
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/Gap07_Rho_v422_Rho_v532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hRho_V422->Write();
    // hRho_V532->Write();
    // fileOutput->Close();
    // return;

    //..Gap= 0.8
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/Gap08_Rho_v422_Rho_v532.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hRho_V422->Write();
    // hRho_V532->Write();
    // fileOutput->Close();
    // return;
}