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

void RhoV4_RhoV5() {
double Sample_BinValue_2Particle_Correlation;
double Sample_BinValue_3Particle_Correlation;
double Sample_BinValue_4Particle_Correlation;
double BinValue_2Particle_Correlation;
double BinValue_3Particle_Correlation;
double BinValue_4Particle_Correlation;
double sqrt_fsample_2particle_correlation;
double sqrt_fsample_4particle_correlation;
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
    TFile *file = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/V4_Linear_NonLinear_Response.root", "Read");
    if(!file) return;
    hCV422 = (TH1D*)file->Get("hCV422");
    hC22 = (TH1D*) file->Get("hC22");

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

    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35");  //..<<3>>_{5|-3,-2}
    
    TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25_Gap");  //..V5{2}
    TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22_Gap");  //..v2^{2}
    TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23_Gap");  //..v3^{2}
    TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35_Gap");  //..<<3>>_{5|-3,-2}



    //..Loop over bins to calculate rho:
    for(int i=1; i<201; i++) {
        double error = 0.0;
        for(int sample=1; sample < 11; sample++ ) {
            // TString foo(TString::Format("fTprof24_number%dNtrks1bin", sample));
            // TProfile *prof24 = (TProfile*)list->FindObject(foo);
            // TString bar(TString::Format("fTprof34_number%dNtrks1bin", sample));	
            // TProfile *prof34 = (TProfile*)list->FindObject(bar);
            // TString foo2(TString::Format("fTprof42_number%dNtrks1bin", sample));	
            // TProfile *prof42 = (TProfile*)list->FindObject(foo2);

            TString foo(TString::Format("fTprof24_number%dGapNtrks1bin", sample));
            TProfile *prof24 = (TProfile*)list->FindObject(foo);
            TString bar(TString::Format("fTprof34_number%dGapNtrks1bin", sample));	
            TProfile *prof34 = (TProfile*)list->FindObject(bar);
            TString foo2(TString::Format("fTprof42_number%dGapNtrks1bin", sample));	
            TProfile *prof42 = (TProfile*)list->FindObject(foo2);
            
            Sample_BinValue_2Particle_Correlation = prof24->GetBinContent(i);
            Sample_BinValue_3Particle_Correlation = prof34->GetBinContent(i);
            Sample_BinValue_4Particle_Correlation = prof42->GetBinContent(i);

            BinValue_2Particle_Correlation = Cn24->GetBinContent(i);
            BinValue_3Particle_Correlation = Cn34->GetBinContent(i);
            BinValue_4Particle_Correlation = Cn42->GetBinContent(i);

            if(Sample_BinValue_2Particle_Correlation > 0 && Sample_BinValue_4Particle_Correlation > 0 && BinValue_4Particle_Correlation > 0 && BinValue_2Particle_Correlation > 0 ) {
                
                sqrt_fsample_2particle_correlation = sqrt(Sample_BinValue_2Particle_Correlation);
                sqrt_fsample_4particle_correlation = sqrt(Sample_BinValue_4Particle_Correlation);
                
                Valuesqrt_2Particle_Correlation = sqrt(BinValue_2Particle_Correlation);
                Valuesqrt_4Particle_Correlation = sqrt(BinValue_4Particle_Correlation);
            }
            else continue;
            if(Valuesqrt_4Particle_Correlation > 0 && sqrt_fsample_4particle_correlation > 0 && Sample_BinValue_3Particle_Correlation > 0 && BinValue_3Particle_Correlation > 0 ){
                
                V422 = BinValue_3Particle_Correlation / (Valuesqrt_4Particle_Correlation);
                V422_Sample = Sample_BinValue_3Particle_Correlation / (sqrt_fsample_4particle_correlation); 
                
                RhoV422 = V422 / (Valuesqrt_2Particle_Correlation);
                RhoV422_Sample = V422_Sample / (sqrt_fsample_2particle_correlation);
                error += pow(RhoV422_Sample - RhoV422, 2);
            }
            else continue;
        }
        Final_Error = sqrt(error/ (N * N) );           
        hRho_V422->SetBinContent(i, RhoV422); 
        hRho_V422->SetBinError(i, Final_Error);    
    }

    //..V5,32 Calculation for Rho_532:
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
        hRho_V532->SetBinContent(j, RhoV532); 
        hRho_V532->SetBinError(j, Final_Error);
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
    
    hRho_V422->SetMarkerStyle(20);
    hRho_V422->SetMarkerColorAlpha(kBlue, 4.5);
    hRho_V422->SetAxisRange(0., 110);
    hRho_V422->SetMarkerSize(1.);
    hRho_V422->SetXTitle("# of tracks");
    hRho_V422->Draw();
    c->BuildLegend();

    // hRho_V532->SetMarkerStyle(20);
    // hRho_V532->SetMarkerColorAlpha(kRed, 4.5);
    // hRho_V532->SetAxisRange(0., 110);
    // hRho_V532->SetMarkerSize(1.);
    // hRho_V532->SetXTitle("# of tracks");
    // hRho_V532->Draw();
    // c->BuildLegend();

    TFile* fileOutput = new TFile("Rho_v422_Rho_v532_Gap02.root","RECREATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hRho_V422->Write();
    hRho_V532->Write();
    fileOutput->Close();
    return;

}