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

void Rebin_V4_V5_NL_Helene() 
{    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //**************************************************************************
    //..Define histograms

    TH1D *Rebin_Ratio_1 = new TH1D("Rebin_Ratio_1", "|#Delta #eta| > 0.0 A", 20, 0, 200);
    Rebin_Ratio_1->Sumw2();

    TH1D *Rebin_Ratio_2 = new TH1D("Rebin_Ratio_2", "|#Delta #eta| > 0.1 A", 20, 0, 200);
    Rebin_Ratio_2->Sumw2();

    TH1D *Rebin_Ratio_3 = new TH1D("Rebin_Ratio_3", "|#Delta #eta| > 0.2 A", 20, 0, 200);
    Rebin_Ratio_3->Sumw2();

    TH1D *Rebin_Ratio_4 = new TH1D("Rebin_Ratio_4", "|#Delta #eta| > 0.3 A", 20, 0, 200); 
    Rebin_Ratio_4->Sumw2();

    TH1D *Rebin_Ratio_5 = new TH1D("Rebin_Ratio_5", "|#Delta #eta| > 0.4 A", 20, 0, 200); 
    Rebin_Ratio_5->Sumw2();

    TH1D *Rebin_Ratio_6 = new TH1D("Rebin_Ratio_6", "|#Delta #eta| > 0.5 A", 20, 0, 200);
    Rebin_Ratio_6->Sumw2();

    TH1D *Rebin_Ratio_7 = new TH1D("Rebin_Ratio_7", "|#Delta #eta| > 0.6 A", 20, 0, 200); 
    Rebin_Ratio_7->Sumw2();

    TH1D *Rebin_Ratio_8 = new TH1D("Rebin_Ratio_8", "|#Delta #eta| > 0.7 A", 20, 0, 200);
    Rebin_Ratio_8->Sumw2();

    TH1D *Rebin_Ratio_9 = new TH1D("Rebin_Ratio_9", "|#Delta #eta| > 0.8 A", 20, 0, 200);
    Rebin_Ratio_9->Sumw2();
    //==========================================================================
    //Open Helenes root.file for V4_L && V5_L && v422 && v532 && 2-particle_sqrt
    // 4-particle-sqrt:
    // TFile *file = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/V532_NL_Linear_NUA+NUE.root", "READ");
    //In thesis: Debug_Average_V532_A+B_NUA+NUE.root
    TFile *file = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Average_V422_NUA+NUE/4particle_Debug_Average_V532_A+B_NUA+NUE.root", "READ");

    if(!file) return; 
    v532_Gap00 = (TH1D*)file->Get("v532_Gap00_A+B");
    // v532_Gap01 = (TH1D*)file->Get("v532_Gap01_A+B");
    // v532_Gap02 = (TH1D*)file->Get("v532_Gap02_A+B"); 
    // v532_Gap03 = (TH1D*)file->Get("v532_Gap03_A+B");
    // v532_Gap04 = (TH1D*)file->Get("v532_Gap04_A+B");
    v532_Gap05 = (TH1D*)file->Get("v532_Gap05_A+B");
    // v532_Gap06 = (TH1D*)file->Get("v532_Gap06_A+B");
    // v532_Gap07 = (TH1D*)file->Get("v532_Gap07_A+B");
    v532_Gap08 = (TH1D*)file->Get("v532_Gap08_A+B");
    //==========================================================================
    int binning = 10;
    double errorNum;
    double sumNum = 0;
    double sumDenom = 1;
    double content = 0;

    if(binning == 10)RebinAll(v532_Gap00, Rebin_Ratio_1, 10);
    if(!v532_Gap00) fPrint("Warning there is no histogram");
    //Rebin_Ratio_1->GetXaxis()->SetRangeUser(10, 100);
    Rebin_Ratio_1->Draw("same");

    // if(binning == 10)RebinAll(v532_Gap01, Rebin_Ratio_2, 10);
    // if(!v532_Gap01) fPrint("Warning there is no histogram");
    // //Rebin_Ratio_2->GetXaxis()->SetRangeUser(10, 90);  //There is an outlier for bins > 90 cut at 10 < bin < 90
    // //Rebin_Ratio_2->Draw("same");

    // if(binning == 10)RebinAll(v532_Gap02, Rebin_Ratio_3, 10);
    // if(!v532_Gap02) fPrint("Warning there is no histogram");
    // //Rebin_Ratio_3->GetXaxis()->SetRangeUser(10, 100);
    // //Rebin_Ratio_3->Draw("same");  //There is an outlier for cut 10 < bins < 100 

    // if(binning == 10)RebinAll(v532_Gap03, Rebin_Ratio_4, 10);
    // if(!v532_Gap03) fPrint("Warning there is no histogram");
    // //Rebin_Ratio_4->GetXaxis()->SetRangeUser(10, 100);
    // //Rebin_Ratio_4->Draw("same");

    // if(binning == 10)RebinAll(v532_Gap04, Rebin_Ratio_5, 10);
    // if(!v532_Gap04) fPrint("Warning there is no histogram");
    // //Rebin_Ratio_5->GetXaxis()->SetRangeUser(10, 100);
    // //Rebin_Ratio_5->Draw("same");

    if(binning == 10)RebinAll(v532_Gap05, Rebin_Ratio_6, 10);
    if(!v532_Gap05) fPrint("Warning there is no histogram");
    //Rebin_Ratio_6->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_6->Draw("same");

    // if(binning == 10)RebinAll(v532_Gap06, Rebin_Ratio_7, 10);
    // if(!v532_Gap06) fPrint("Warning there is no histogram");
    // //Rebin_Ratio_7->GetXaxis()->SetRangeUser(10, 100);
    // //Rebin_Ratio_7->Draw("same");

    // if(binning == 10)RebinAll(v532_Gap07, Rebin_Ratio_8, 10);
    // if(!v532_Gap07) fPrint("Warning there is no histogram");
    // //Rebin_Ratio_8->GetXaxis()->SetRangeUser(10, 100);
    // //Rebin_Ratio_8->Draw("same");

    if(binning == 10)RebinAll(v532_Gap08, Rebin_Ratio_9, 10);
    if(!v532_Gap08) fPrint("Warning there is no histogram");
    //Rebin_Ratio_9->GetXaxis()->SetRangeUser(10, 100);
    Rebin_Ratio_9->Draw("same");

    //..Writting to the Root.file:
    // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Average_V422_NUA+NUE/4particle_Rebin_Debug_Average_v532_A+B.root","UPDATE");
    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Average_V422_NUA+NUE/4particle_Rebin_Debug_Average_v532_A+B.root", "UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    Rebin_Ratio_1->Write("Rebin_v532_Gap00A_A+B");
    // Rebin_Ratio_2->Write("Rebin_v532_Gap01A_A+B");
    // Rebin_Ratio_3->Write("Rebin_v532_Gap02A_A+B"); 
    // Rebin_Ratio_4->Write("Rebin_v532_Gap03A_A+B");
    // Rebin_Ratio_5->Write("Rebin_v532_Gap04A_A+B");
    Rebin_Ratio_6->Write("Rebin_v532_Gap05A_A+B");
    // Rebin_Ratio_7->Write("Rebin_v532_Gap06A_A+B");
    // Rebin_Ratio_8->Write("Rebin_v532_Gap07A_A+B");
    Rebin_Ratio_9->Write("Rebin_v532_Gap08A_A+B");
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
