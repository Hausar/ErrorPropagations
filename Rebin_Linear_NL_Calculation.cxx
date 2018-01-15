//Macro To Calculate the Error Propagation and Linear, Non-Linear Calculation from the Rebin Tprofiles:
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

void Rebin_Linear_NL_Calculation() {    
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
    int N = 10;
    //values for Linear error sampling:
    double fsample_Linear; 
    double fsample_2particle_correlation = 0.0;
    double sqrt_fsample_2particle_correlation = 0.0;
    double fsample_3particle_correlation = 0.0;
    double fsample_4particle_correlation = 0.0;
    double sqrt_fsample_4particle_correlation = 0.0;

    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(19);
    c->cd();

    TH1D *hC22 = new TH1D("hC22", " V4{2},  #sqrt{< v_{4}^{2} >}", 20, 0, 200); //this is just define a histogram which will fill the data.
    hC22->Sumw2();
    
    TH1D *hC42 = new TH1D("hC42", " #sqrt{< v_{2}^{4} >}", 20, 0, 200); //this is just define a histogram 
	hC42->Sumw2();

    TH1D *hCV422 = new TH1D("hCV422", "The Non-Linear Response, v_{4,22} = <<3>> / #sqrt{< v_{2}^{4} >}", 20, 0, 200); //this is just define a histogram which will fill the data of V422.
    hCV422->Sumw2();
 
    TH1D *hCLinear = new TH1D("hCLinear", " The Linear Response V4^{L} ", 20, 0, 200); //this is just define a histogram which will fill the data.
    hCLinear->Sumw2();

    //Open the Rebin root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Rebin_histogram_Test.root", "READ");
    TH1F *hCn24_Gap02_Rebin = (TH1F*)file->Get("hCn24_Gap02_Rebin");
    TH1F *hCn42_Gap02_Rebin = (TH1F*)file->Get("hCn42_Gap02_Rebin");
    TH1F *hCn34_Gap02_Rebin = (TH1F*)file->Get("hCn34_Gap02_Rebin");
    
    //hCn24_Gap02_Rebin->Draw();
    //hCn42_Gap02_Rebin->Draw();
    //hCn34_Gap02_Rebin->Draw();

    //..Open the Total root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/LHC16q_CENT_SDD_0Gap_2_08Gap_FullGaps.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("MyTaskResults");
    TList *list = (TList*)dir->Get("Flow_Refs_MyTaskResults");


    //****************************************************
    //// Loop to get sqrt of each bin in Tprofile of//////
    //     Cn{2} = <<2>> = < vn^2 > and //////////////////
    ////   Cn{4} = <<4>> = <vn^4> = <<4>> - 2 <<2>>^2 ////

    /////********  v2{4} = sqrt(<<4>>_{2,2|-2,-2})  ******////////////
    //*****************************************************
    for(int i=1; i<201; i++)
    {
        double error = 0.0;
        for(int sample=1; sample<11; sample++)
        {
            TString foo(TString::Format("fTprof42_number%dNtrks1bin", sample));	
            TProfile *fprof42 = (TProfile*)list->FindObject(foo);
            //..we have the total one already rebined 
            
            TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42");
            BinValue42_Sample = fprof42->GetBinContent(i);
            BinValue42 = Cn42->GetBinContent(i); 

            if(BinValue42 > 0 && BinValue42_Sample > 0 ) {
                Valuesqrt_4Particle_Correlation = sqrt(BinValue42);
                Valuesqrt_4Particle_Sample = sqrt(BinValue42_Sample);
            }
            else continue;
            error += pow(Valuesqrt_4Particle_Sample - Valuesqrt_4Particle_Correlation, 2);

            // cout << "fsample: " << foo << endl;
            // cout << "BinVlue42: " << BinValue42 << endl;
            // cout << "BinVlue42_Sample: " << BinValue42_Sample << endl;
            // cout << " Valuesqrt 4Particle: " << Valuesqrt_4Particle_Correlation << endl;
            // cout << "error: " << error << endl; 
        
        }
        final_error = sqrt(error / (N * N) );
        //cout << "final_error: " << final_error << endl;
        hC42->SetBinContent(i, Valuesqrt_4Particle_Correlation);
        hC42->SetBinError(i, final_error);

    }
    //*************************************************************************





}


















