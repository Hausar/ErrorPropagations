//..The macro for Rebin the V4_NL, V4_L, V4{2} and 
//..The macro for Rebin the V5_NL, V5_L, V5{2}
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

void All_Gaps_Rebin_V4_V5_NL_L() 
{    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //..Create TFile.root for all Rebin histograms:
    
    //..v422
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/Rebin_V4_AllGaps/Rebin_V4_Linear_NL_histograms.root","RECREATE");

   //..v422 for new condition: 
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_Rebin_NewCondition_V4/Rebin_V4_Linear_NL_histograms_NewCondition.root","RECREATE");
    
    //..v532
    // TFile* fileOutput1 = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_Rebin_NewCondition_V5/Rebin_V5_Linear_NL_histograms_NewCondition.root","RECREATE");
    
    //..chi422/chi532
    TFile* fileOutput2 = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Rebin_NewCondition_Chi422_Chi532_AllGaps/Rebin_NewCondition_Chi422_Chi532_histograms.root","RECREATE");

    //..Rho_v422_v532
    // TFile* fileOutput3 = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/Rebin_NewConditions_Rho_v422_v532/Rebin_NewCondition_Rho_v422_v532_histograms.root","RECREATE");
    //**************************************************************************
    //..V4,22 
    // //..Open Root.File:
    // int EtaGap[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    // for(int i=0; i <9; i++) {
    //     // TString fPath (TString::Format("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/V4_AllGaps/Gap0%0d_V4_Linear_NonLinear_Response.root", EtaGap[i]));

    //     TString fPath (TString::Format("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_NewCondition_V4_Linear_NL/Gap0%0d_V4_Linear_NonLinear_Response_NewCondition.root", EtaGap[i]));

    //     TFile* file = TFile::Open(fPath, "READ");
    //     if(!file) return;

    //     TH1D* hC22 = (TH1D*)file->Get("hC22");
    //     if(!hC22) return;
    //     //hC22->Draw();

    //     TH1D* hC22_Rebin = new TH1D(Form("hC22_Rebin_Gap0%0d", EtaGap[i]),"v_{4}{2}, 2-Particle correlations; #N_ch; #v_{4}{2}", 10, 0, 200);
	// 	hC22_Rebin->Sumw2();
    //     //hC22_Rebin->Draw();

    //     TH1D* hCV422_Rebin = new TH1D(Form("hCV422_Rebin_Gap0%0d", EtaGap[i]),"v_{4,22} Non-Linear Response; #N_ch; #v_{4,22}", 10, 0, 200);
	// 	hCV422_Rebin->Sumw2();

    //     TH1D* hCLinear_Rebin = new TH1D(Form("hCLinear_Rebin_Gap0%0d", EtaGap[i]),"v_{4}^{L} Linear Response; #N_ch; #v_{4}^{L}", 10, 0, 200);
	// 	hCLinear_Rebin->Sumw2();

    //     Printf("the merge directory exist:");
    //     cout << "EtaGap: " << EtaGap[i] << endl;
    //     cout << "i : " << i << endl; 

    //     int binning = 20;
    //     double errorNum;
    //     double sumNum = 0;
    //     double sumDenom = 1;
    //     double content = 0;
        
    //     if(binning == 20)RebinAll(hC22, hC22_Rebin, 20);
    //     if(!hC22) fPrint("Warning there is no histogram");
    //     //hC22_Rebin->GetXaxis()->SetRangeUser(10, 110);
    //     //hC22_Rebin->Draw("same");

    //     if(binning == 20)RebinAll(hCV422, hCV422_Rebin, 20);
    //     if(!hCV422) fPrint("Warning there is no histogram");
    //     //hCV422_Rebin->GetXaxis()->SetRangeUser(10, 110);
    //     //hCV422_Rebin->Draw("same");

    //     if(binning == 20)RebinAll(hCLinear, hCLinear_Rebin, 20);
    //     if(!hCLinear) fPrint("Warning there is no histogram");
    //     //hCLinear_Rebin->GetXaxis()->SetRangeUser(10, 110);
    //     //hCLinear_Rebin->Draw("same");

    //     if(!fileOutput) return;
    //     fileOutput->cd();
    //     hC22_Rebin->Write();
    //     hCV422_Rebin->Write();
    //     hCLinear_Rebin->Write();
    //     fileOutput->Write(Form("hC22_Rebin_Gap0%0d", EtaGap[i]));
    //     fileOutput->Write(Form("hCV422_Rebin_Gap0%0d", EtaGap[i]));
    //     fileOutput->Write(Form("hCLinear_Rebin_Gap0%0d", EtaGap[i]));

    // }   //..End of loop

    //******************************************************************************************************************************
    //..V5,32 
    //..Open Root.File:
    // int EtaGap[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    // for(int i=0; i <9; i++) {
    //     TString fPath (TString::Format("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_NewCondition_V5_Linear_NL/Gap0%0d_V5_Linear_NonLinear_Response_NewCondition.root", EtaGap[i]));

    //     TFile* file = TFile::Open(fPath, "READ");
    //     if(!file) return;

    //     TH1D* hC22 = (TH1D*)file->Get("hC22");
    //     if(!hC22) return;
    //     //hC22->Draw();

    //     TH1D* hCV532 = (TH1D*)file->Get("hCV532");
    //     if(!hC22) return;

    //     TH1D* hCLinear = (TH1D*)file->Get("hCLinear");
    //     if(!hCLinear) return;

    //     TH1D* hC22_Rebin = new TH1D(Form("hC25_Rebin_Gap0%0d", EtaGap[i]),"v_{5}{2}, 2-Particle correlations; #N_ch; #v_{5}{2}", 10, 0, 200);
	// 	hC22_Rebin->Sumw2();
    //     //hC22_Rebin->Draw();

    //     TH1D* hCV532_Rebin = new TH1D(Form("hCV532_Rebin_Gap0%0d", EtaGap[i]),"v_{5,32} Non-Linear Response; #N_ch; #v_{5,32}", 10, 0, 200);
	// 	hCV532_Rebin->Sumw2();

    //     TH1D* hCLinear_Rebin = new TH1D(Form("hCLinearV5_Rebin_Gap0%0d", EtaGap[i]),"v_{5}^{L} Linear Response; #N_ch; #v_{5}^{L}", 10, 0, 200);
	// 	hCLinear_Rebin->Sumw2();

    //     Printf("the merge directory exist:");
    //     cout << "EtaGap: " << EtaGap[i] << endl;
    //     cout << "i : " << i << endl; 

    //     int binning = 20;
    //     double errorNum;
    //     double sumNum = 0;
    //     double sumDenom = 1;
    //     double content = 0;
        
    //     if(binning == 20)RebinAll(hC22, hC22_Rebin, 20);
    //     if(!hC22) fPrint("Warning there is no histogram");
    //     //hC22_Rebin->GetXaxis()->SetRangeUser(10, 110);
    //     //hC22_Rebin->Draw("same");

    //     if(binning == 20)RebinAll(hCV532, hCV532_Rebin, 20);
    //     if(!hCV532) fPrint("Warning there is no histogram");
    //     //hCV422_Rebin->GetXaxis()->SetRangeUser(10, 110);
    //     //hCV422_Rebin->Draw("same");

    //     if(binning == 20)RebinAll(hCLinear, hCLinear_Rebin, 20);
    //     if(!hCLinear) fPrint("Warning there is no histogram");
    //     //hCLinear_Rebin->GetXaxis()->SetRangeUser(10, 110);
    //     //hCLinear_Rebin->Draw("same");

    //     if(!fileOutput1) return;
    //     fileOutput1->cd();
    //     hC22_Rebin->Write();
    //     hCV532_Rebin->Write();
    //     hCLinear_Rebin->Write();
    //     fileOutput1->Write(Form("hC25_Rebin_Gap0%0d", EtaGap[i]));
    //     fileOutput1->Write(Form("hCV532_Rebin_Gap0%0d", EtaGap[i]));
    //     fileOutput1->Write(Form("hCLinearV5_Rebin_Gap0%0d", EtaGap[i]));

    // }  //..End of loop

    //******************************************************************************************************************************
    //..Chi422 and
    //..Chi532: 
    //..Open Root.File:
    int EtaGap[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    for(int i=0; i <9; i++) {
        TString fPath (TString::Format("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/NewCondition_Chi422_Chi532_AllGaps/Gap0%0d_NewCondition_Chi_422_Chi_532.root", EtaGap[i]));

        TFile* file = TFile::Open(fPath, "READ");
        if(!file) return;

        TH1D* hChi422 = (TH1D*)file->Get("hChi422");
        if(!hChi422) return;
        //hChi422->Draw();

        TH1D* hChi422_Rebin = new TH1D(Form("hChi422_Rebin_Gap0%0d", EtaGap[i])," #chi_{4,22}; #N_ch; #chi_{4,22}", 10, 0, 200);
		hChi422_Rebin->Sumw2();
        //hC22_Rebin->Draw();

        TH1D* hChi532_Rebin = new TH1D(Form("hChi532_Rebin_Gap0%0d", EtaGap[i])," #chi_{5,32}; #N_ch; #v_{5,32}", 10, 0, 200);
		hChi532_Rebin->Sumw2();

        Printf("the merge directory exist:");
        cout << "EtaGap: " << EtaGap[i] << endl;
        cout << "i : " << i << endl; 

        int binning = 20;
        double errorNum;
        double sumNum = 0;
        double sumDenom = 1;
        double content = 0;
        
        if(binning == 20)RebinAll(hChi422, hChi422_Rebin, 20);
        if(!hChi422) fPrint("Warning there is no histogram");
        //hC22_Rebin->GetXaxis()->SetRangeUser(10, 110);
        //hC22_Rebin->Draw("same");

        if(binning == 20)RebinAll(hChi532, hChi532_Rebin, 20);
        if(!hChi532) fPrint("Warning there is no histogram");
        //hCV422_Rebin->GetXaxis()->SetRangeUser(10, 110);
        //hCV422_Rebin->Draw("same");

        if(!fileOutput2) return;
        fileOutput2->cd();
        hChi422_Rebin->Write(Form("hChi422_Rebin_Gap0%0d", EtaGap[i]));
        hChi532_Rebin->Write(Form("hChi532_Rebin_Gap0%0d", EtaGap[i]));
        fileOutput2->Write(Form("hChi422_Rebin_Gap0%0d", EtaGap[i]));
        fileOutput2->Write(Form("hChi532_Rebin_Gap0%0d", EtaGap[i]));

    } //..End of loop
    //*****************************************************************************    
    //..Rho_v422 and
    //..Rho_v532: 
    //..Open Root.File:
    // int EtaGap[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    // for(int i=0; i <9; i++) {
    //     TString fPath (TString::Format("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/AllGaps_NewConditions_Rho_v422_v532/Gap0%0d_NewCondition_Rho_v422_Rho_v532.root", EtaGap[i])); 

    //     TFile* file = TFile::Open(fPath, "READ");
    //     if(!file) return;

    //     TH1D* hRho_V422_Rebin = new TH1D(Form("hRho_V422_Rebin_Gap0%0d", EtaGap[i])," #rho_{4,22}; #N_ch; #rho_{4,22}", 10, 0, 200);
	// 	hRho_V422_Rebin->Sumw2();
    //     //hC22_Rebin->Draw();

    //     TH1D* hRho_V532_Rebin = new TH1D(Form("hRho_V532_Rebin_Gap0%0d", EtaGap[i])," #rho_{5,32}; #N_ch; #rho_{5,32}", 10, 0, 200);
	// 	hRho_V532_Rebin->Sumw2();

    //     Printf("the merge directory exist:");
    //     cout << "EtaGap: " << EtaGap[i] << endl;
    //     cout << "i : " << i << endl; 

    //     int binning = 20;
    //     double errorNum;
    //     double sumNum = 0;
    //     double sumDenom = 1;
    //     double content = 0;
        
    //     if(binning == 20)RebinAll(hRho_V422, hRho_V422_Rebin, 20);
    //     if(!hRho_V422) fPrint("Warning there is no histogram");
    //     //hC22_Rebin->GetXaxis()->SetRangeUser(10, 110);
    //     //hC22_Rebin->Draw("same");

    //     if(binning == 20)RebinAll(hRho_V532, hRho_V532_Rebin, 20);
    //     if(!hRho_V532) fPrint("Warning there is no histogram");
    //     //hCV422_Rebin->GetXaxis()->SetRangeUser(10, 110);
    //     //hCV422_Rebin->Draw("same");

    //     if(!fileOutput3) return;
    //     fileOutput3->cd();
    //     hRho_V422_Rebin->Write();
    //     hRho_V532_Rebin->Write();
    //     fileOutput3->Write(Form("hRho_V422_Rebin_Gap0%0d", EtaGap[i]));
    //     fileOutput3->Write(Form("hRho_V532_Rebin_Gap0%0d", EtaGap[i]));

    // }  //..End of loop
    //*****************************************************************************  

}   //..End of the File

// //..Define Rebin Function
// //_______________________________________________________________________________
void RebinAll(TH1D *h1, TH1D *h2, int binning)
{
    
    double sumNum[200] = {0};
    double sumDenom[200] = {0};
    double errorNum[200] = {0};
    double content[200] = {0};
    double error[200] = {0};
    
    int bin = 1;

    if(binning == 5)
    {
        for(int j=1; j<200; j=j+5)
        {
            for(int i=0; i<5; i++)
            {
                if(h1->GetBinContent(j+i) != 0)
                {
                    errorNum[bin] += TMath::Power(h1->GetBinError(j+i), 2.);
                    sumNum[bin] += h1->GetBinContent(j+i);
                    sumDenom[bin] += 1;
                }
            }
            bin += 1;
        }

        for(int i=1; i<40; i++)
        {
            if(sumDenom[i] != 0) content[i] = sumNum[i]/sumDenom[i];
            if(sumDenom[i] != 0) error[i] = TMath::Sqrt(errorNum[i]/TMath::Power(sumDenom[i], 2.));
            h2->SetBinContent(i, content[i]);
            h2->SetBinError(i, error[i]);
        }
    }

    if(binning == 10)
    {
        for(int j=1; j<200; j=j+10)
        {
            for(int i=0; i<10; i++)
            {
                if(h1->GetBinContent(j+i) != 0)
                {
                    errorNum[bin] += TMath::Power(h1->GetBinError(j+i), 2.);
                    sumNum[bin] += h1->GetBinContent(j+i);
                    sumDenom[bin] += 1;
                }
            }
            bin += 1;
        }

        for(int i=1; i<20; i++)
        {
            if(sumDenom[i] != 0) content[i] = sumNum[i]/sumDenom[i];
            if(sumDenom[i] != 0) error[i] = TMath::Sqrt(errorNum[i]/TMath::Power(sumDenom[i], 2.));
            h2->SetBinContent(i, content[i]);
            h2->SetBinError(i, error[i]);
        }
    }

    if(binning == 20)
    {
        for(int j=1; j<201; j=j+20)
        {
            for(int i=0; i<20; i++)
            {
                if(h1->GetBinContent(j+i) != 0)
                {
                    errorNum[bin] += TMath::Power(h1->GetBinError(j+i), 2.);
                    sumNum[bin] += h1->GetBinContent(j+i);
                    sumDenom[bin] += 1;
                }
            }
            bin += 1;
        }

        for(int i=1; i<11; i++)
        {
            if(sumDenom[i] != 0) content[i] = sumNum[i]/sumDenom[i];
            if(sumDenom[i] != 0) error[i] = TMath::Sqrt(errorNum[i]/TMath::Power(sumDenom[i], 2.));
            h2->SetBinContent(i, content[i]);
            h2->SetBinError(i, error[i]);
        }
    }

    if(binning == 40)
    {
        for(int j=1; j<201; j=j+40)
        {
            for(int i=0; i<40; i++)
            {
                if(h1->GetBinContent(j+i) != 0)
                {
                    errorNum[bin] += TMath::Power(h1->GetBinError(j+i), 2.);
                    sumNum[bin] += h1->GetBinContent(j+i);
                    sumDenom[bin] += 1;
                }
            }
            bin += 1;
        }

        for(int i=1; i<6; i++)
        {
            if(sumDenom[i] != 0) content[i] = sumNum[i]/sumDenom[i];
            if(sumDenom[i] != 0) error[i] = TMath::Sqrt(errorNum[i]/TMath::Power(sumDenom[i], 2.));
            h2->SetBinContent(i, content[i]);
            h2->SetBinError(i, error[i]);
        }
    }
}   //..End of Function

