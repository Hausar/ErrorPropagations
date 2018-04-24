//Macro To Rebin the Results plots for V4_Linear_NL_Response for W/WO Gap = 0.2:
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

void Ratio_Rebin_Rho_V422_V532() 
{    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //**************************************************************************
    //..Define histograms

    TH1D *Rebin_Ratio_1 = new TH1D("Rebin_Ratio_1", "|#Delta #eta| > 0.8", 10, 0, 200); 
    Rebin_Ratio_1->Sumw2();

    TH1D *Rebin_Ratio_2 = new TH1D("Rebin_Ratio_2", "|#Delta #eta| > 0.8", 10, 0, 200); 
    Rebin_Ratio_2->Sumw2();

    TH1D *Rebin_Ratio_3 = new TH1D("Rebin_Ratio_3", "|#Delta #eta| > 0.8", 10, 0, 200);
    Rebin_Ratio_3->Sumw2();

    TH1D *Rebin_Ratio_4 = new TH1D("Rebin_Ratio_4", "|#Delta #eta| > 0.8", 10, 0, 200); 
    Rebin_Ratio_4->Sumw2();

    TH1D *Rebin_Ratio_5 = new TH1D("Rebin_Ratio_5", "|#Delta #eta| > 0.8", 10, 0, 200); 
    Rebin_Ratio_5->Sumw2();

    TH1D *Rebin_Ratio_6 = new TH1D("Rebin_Ratio_6", "|#Delta #eta| > 0.8", 10, 0, 200);
    Rebin_Ratio_6->Sumw2();

    TH1D *Rebin_Ratio_7 = new TH1D("Rebin_Ratio_7", "|#Delta #eta| > 0.8", 10, 0, 200); 
    Rebin_Ratio_7->Sumw2();

    TH1D *Rebin_Ratio_8 = new TH1D("Rebin_Ratio_8", "|#Delta #eta| > 0.8", 10, 0, 200);
    Rebin_Ratio_8->Sumw2();

    TH1D *Rebin_Ratio_9 = new TH1D("Rebin_Ratio_9", "|#Delta #eta| > 0.8", 10, 0, 200);
    Rebin_Ratio_9->Sumw2();
    //==========================================================================
    //Open Helenes root.file for Rho_422 and Rho_532:
    TFile *file = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/All_Gaps_Chi_422_Chi_532/Chi422_Chi532_AllGaps_NUA+NUE/Corrected_Chi_422_Chi_532_NUA+NUE.root", "READ");
    if(!file) return; 
    Rho_V532_Gap00 = (TH1D*)file->Get("Gap00_Rho_V532_NUA+NUE");
    Rho_V532_Gap01 = (TH1D*)file->Get("Gap01_Rho_V532_NUA+NUE");
    Rho_V532_Gap02 = (TH1D*)file->Get("Gap02_Rho_V532_NUA+NUE"); 
    Rho_V532_Gap03 = (TH1D*)file->Get("Gap03_Rho_V532_NUA+NUE");
    Rho_V532_Gap04 = (TH1D*)file->Get("Gap04_Rho_V532_NUA+NUE");
    Rho_V532_Gap05 = (TH1D*)file->Get("Gap05_Rho_V532_NUA+NUE");
    Rho_V532_Gap06 = (TH1D*)file->Get("Gap06_Rho_V532_NUA+NUE");
    Rho_V532_Gap07 = (TH1D*)file->Get("Gap07_Rho_V532_NUA+NUE");
    Rho_V532_Gap08 = (TH1D*)file->Get("Gap08_Rho_V532_NUA+NUE");
    
    Rho_V532_Gap00 = (TH1D*)file->Get("Gap00_Rho_V532_NUA+NUE");
    Rho_V532_Gap01 = (TH1D*)file->Get("Gap01_Rho_V532_NUA+NUE");
    Rho_V532_Gap02 = (TH1D*)file->Get("Gap02_Rho_V532_NUA+NUE"); 
    Rho_V532_Gap03 = (TH1D*)file->Get("Gap03_Rho_V532_NUA+NUE");
    Rho_V532_Gap04 = (TH1D*)file->Get("Gap04_Rho_V532_NUA+NUE");
    Rho_V532_Gap05 = (TH1D*)file->Get("Gap05_Rho_V532_NUA+NUE");
    Rho_V532_Gap06 = (TH1D*)file->Get("Gap06_Rho_V532_NUA+NUE");
    Rho_V532_Gap07 = (TH1D*)file->Get("Gap07_Rho_V532_NUA+NUE");
    Rho_V532_Gap08 = (TH1D*)file->Get("Gap08_Rho_V532_NUA+NUE");

    //==========================================================================
    int binning = 20;
    double errorNum;
    double sumNum = 0;
    double sumDenom = 1;
    double content = 0;

    if(binning == 20)RebinAll(Rho_V532_Gap00, Rebin_Ratio_1, 20);
    if(!Rho_V532_Gap00) fPrint("Warning there is no histogram");
    Rebin_Ratio_1->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_1->Draw("same");

    if(binning == 20)RebinAll(Rho_V532_Gap01, Rebin_Ratio_2, 20);
    if(!Rho_V532_Gap01) fPrint("Warning there is no histogram");
    Rebin_Ratio_2->GetXaxis()->SetRangeUser(10, 100);
    Rebin_Ratio_2->Draw("same");

    if(binning == 20)RebinAll(Rho_V532_Gap02, Rebin_Ratio_3, 20);
    if(!Rho_V532_Gap02) fPrint("Warning there is no histogram");
    Rebin_Ratio_3->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_3->Draw("same");

    if(binning == 20)RebinAll(Rho_V532_Gap03, Rebin_Ratio_4, 20);
    if(!Rho_V532_Gap03) fPrint("Warning there is no histogram");
    Rebin_Ratio_4->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_4->Draw("same");

    if(binning == 20)RebinAll(Rho_V532_Gap04, Rebin_Ratio_5, 20);
    if(!Rho_V532_Gap04) fPrint("Warning there is no histogram");
    Rebin_Ratio_5->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_5->Draw("same");

    if(binning == 20)RebinAll(Rho_V532_Gap05, Rebin_Ratio_6, 20);
    if(!Rho_V532_Gap05) fPrint("Warning there is no histogram");
    Rebin_Ratio_6->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_6->Draw("same");

    if(binning == 20)RebinAll(Rho_V532_Gap06, Rebin_Ratio_7, 20);
    if(!Rho_V532_Gap06) fPrint("Warning there is no histogram");
    Rebin_Ratio_7->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_7->Draw("same");

    if(binning == 20)RebinAll(Rho_V532_Gap07, Rebin_Ratio_8, 20);
    if(!Rho_V532_Gap07) fPrint("Warning there is no histogram");
    Rebin_Ratio_8->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_8->Draw("same");

    if(binning == 20)RebinAll(Rho_V532_Gap08, Rebin_Ratio_9, 20);
    if(!Rho_V532_Gap08) fPrint("Warning there is no histogram");
    Rebin_Ratio_9->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_9->Draw("same");

    //..Writting to the Root.file:
    //..V4,22
    TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Rebin_Plots_Helene_You_Rho422_Rho532/Rebin_RhoV422_Helene.root","UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    Rebin_Ratio_1->Write("Rebin_Rho_V532_Gap00");
    Rebin_Ratio_2->Write("Rebin_Rho_V532_Gap01");
    Rebin_Ratio_3->Write("Rebin_Rho_V532_Gap02");  // You don't have <<4>>_{44}
    Rebin_Ratio_4->Write("Rebin_Rho_V532_Gap03");
    Rebin_Ratio_5->Write("Rebin_Rho_V532_Gap04");
    Rebin_Ratio_6->Write("Rebin_Rho_V532_Gap05");
    Rebin_Ratio_7->Write("Rebin_Rho_V532_Gap06");
    Rebin_Ratio_8->Write("Rebin_Rho_V532_Gap07");
    Rebin_Ratio_9->Write("Rebin_Rho_V532_Gap08");
    
} // End of the Macro

//..Define Rebin Function
//_____________________________________________________________________________
void RebinAll(TH1D *h1, TH1D *h2, int binning)
{
	
	double sumNum[200] = {0};
	double sumDenom[200] = {0};
	double errorNum[200] = {0};
	double content[200] = {0};
	double error[200] = {0};
	
	int bin = 1;

	if(binning == 10)
	{
		for(int j=1; j<201; j=j+10)
		{
			for(int i=0; i<10; i++)
			{
				if(h1->GetBinContent(j+i) != 0)
				{
					errorNum[bin] += TMath::Power(h1->GetBinError(j+i), 2.);
					sumNum[bin] += h1->GetBinContent(j+i);
					sumDenom[bin] += 1;
				}
                cout << "i: " << i << endl;
                cout << "sumNum: " << sumNum[i] << endl;
                cout << "errorNum: " << errorNum[i] << endl;
			}
			bin += 1;
		}

		for(int i=1; i<21; i++)
		{
			if(sumDenom[i] != 0) content[i] = sumNum[i]/sumDenom[i];
			if(sumDenom[i] != 0) error[i] = TMath::Sqrt(errorNum[i]/(TMath::Power(sumDenom[i], 2.)));
            cout << "i: " << i << endl;
            cout << "error: " << error[i] << endl;
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

}
//_______________________________________________________________________________
