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

void Ratio_Rebin_Plots() 
{    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //**************************************************************************
    //..Define New Histograms

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

    //==========================================================================
    //Open Helene's root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_Corrected_4particle.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");

    // TProfile *Cn22_Gap06 = (TProfile*)list->FindObject("fTprofC22Gap06Ntrks1bin");
    // TProfile *Cn23_Gap06 = (TProfile*)list->FindObject("fTprofC23Gap06Ntrks1bin");
    // TProfile *Cn24_Gap06 = (TProfile*)list->FindObject("fTprofC24Gap06Ntrks1bin");
    // TProfile *Cn25_Gap02 = (TProfile*)list->FindObject("fTprofC25Gap02Ntrks1bin");
    TProfile *Cn42_Gap07 = (TProfile*)list->FindObject("fTprofC42Gap07Ntrks1bin");  
    TProfile *Cn43_Gap07 = (TProfile*)list->FindObject("fTprofC43Gap07Ntrks1bin");  
    TProfile *Cn44_Gap07 = (TProfile*)list->FindObject("fTprofC44Gap07Ntrks1bin");  
    TProfile *Cn34_Gap07 = (TProfile*)list->FindObject("fTprofC34Gap07ANtrks1bin");
    TProfile *Cn35_Gap07 = (TProfile*)list->FindObject("fTprofC35Gap07ANtrks1bin"); 

    h1_Cn42 = Cn42_Gap07->ProjectionX();
    h1_Cn43 = Cn43_Gap07->ProjectionX();
    h1_Cn44 = Cn44_Gap07->ProjectionX();
    h1_Cn34 = Cn34_Gap07->ProjectionX();
    h1_Cn35 = Cn35_Gap07->ProjectionX();

    //**************************************************************************
    //Open You's root.file:
    TFile *file2 = TFile::Open("/Users/Helena/Desktop/Katarina_all/You_comparision/Output_Nch.root", "READ");
    if(file2) {
        h2_Cn42 = (TH1D*)file2->Get("fc24Gap6");
        h2_Cn43 = (TH1D*)file2->Get("fc3232Gap6");
        h2_Cn34 = (TH1D*)file2->Get("fc422Gap6A"); 
        h2_Cn35 = (TH1D*)file2->Get("fc532Gap6A");
    }

    //==========================================================================
    int binning = 20;
    double errorNum;
    double sumNum = 0;
    double sumDenom = 1;
    double content = 0;

    if(binning == 20)RebinAll(h1_Cn42, Rebin_Ratio_1, 20);
    if(!h1_Cn42) fPrint("Warning there is no histogram");
    Rebin_Ratio_1->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_1->Draw("same");

    if(binning == 20)RebinAll(h1_Cn43, Rebin_Ratio_2, 20);
    if(!h1_Cn43) fPrint("Warning there is no histogram");
    Rebin_Ratio_2->GetXaxis()->SetRangeUser(10, 100);
    Rebin_Ratio_2->Draw("same");

    if(binning == 20)RebinAll(h1_Cn44, Rebin_Ratio_3, 20);
    if(!h1_Cn44) fPrint("Warning there is no histogram");
    Rebin_Ratio_3->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_3->Draw("same");

    if(binning == 20)RebinAll(h1_Cn34, Rebin_Ratio_4, 20);
    if(!h1_Cn34) fPrint("Warning there is no histogram");
    Rebin_Ratio_4->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_4->Draw("same");

    if(binning == 20)RebinAll(h1_Cn35, Rebin_Ratio_5, 20);
    if(!h1_Cn35) fPrint("Warning there is no histogram");
    Rebin_Ratio_5->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_5->Draw("same");

    //***************************************************************************************************
    //..Writting to the Root.file:
    //..V4,22
    TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Rebin_Raw_Plots_Helene_You_3_4_part/Rebin_Raw_plots_Helene_3part_4particle.root","UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    Rebin_Ratio_1->Write("Rebin_Cn42_Gap07");
    Rebin_Ratio_2->Write("Rebin_Cn43_Gap07");
    Rebin_Ratio_3->Write("Rebin_Cn44_Gap07");  // You don't have <<4>>_{44}
    Rebin_Ratio_4->Write("Rebin_Cn34_Gap07");
    Rebin_Ratio_5->Write("Rebin_Cn35_Gap07");
    fileOutput->Close();
}

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
