//Macro To Calculate the Rebin Tprofiles:
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

void Thesis_Rebin_3part_4part_corr() {
    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //*************************************************************************
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

    //Open the root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_New_Checked.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");

    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Ntrks1bin"); 

    TProfile *Cn34_Gap00 = (TProfile*)list->FindObject("fTprofC34Gap00ANtrks1bin"); 
    TProfile *Cn35_Gap00 = (TProfile*)list->FindObject("fTprofC35Gap00ANtrks1bin");
    TProfile *Cn42_Gap00 = (TProfile*)list->FindObject("fTprofC42Gap00Ntrks1bin");  
    TProfile *Cn43_Gap00 = (TProfile*)list->FindObject("fTprofC43Gap00Ntrks1bin");  

    TProfile *Cn34_Gap01 = (TProfile*)list->FindObject("fTprofC34Gap01ANtrks1bin"); 
    TProfile *Cn35_Gap01 = (TProfile*)list->FindObject("fTprofC35Gap01ANtrks1bin");
    TProfile *Cn42_Gap01 = (TProfile*)list->FindObject("fTprofC42Gap01Ntrks1bin");  
    TProfile *Cn43_Gap01 = (TProfile*)list->FindObject("fTprofC43Gap01Ntrks1bin");  

    TProfile *Cn34_Gap02 = (TProfile*)list->FindObject("fTprofC34Gap02ANtrks1bin"); 
    TProfile *Cn35_Gap02 = (TProfile*)list->FindObject("fTprofC35Gap02ANtrks1bin");
    TProfile *Cn42_Gap02 = (TProfile*)list->FindObject("fTprofC42Gap02Ntrks1bin");  
    TProfile *Cn43_Gap02 = (TProfile*)list->FindObject("fTprofC43Gap02Ntrks1bin");  

    TProfile *Cn34_Gap03 = (TProfile*)list->FindObject("fTprofC34Gap03ANtrks1bin"); 
    TProfile *Cn35_Gap03 = (TProfile*)list->FindObject("fTprofC35Gap03ANtrks1bin");
    TProfile *Cn42_Gap03 = (TProfile*)list->FindObject("fTprofC42Gap03Ntrks1bin");  
    TProfile *Cn43_Gap03 = (TProfile*)list->FindObject("fTprofC43Gap03Ntrks1bin");  


    TProfile *Cn34_Gap04 = (TProfile*)list->FindObject("fTprofC34Gap04ANtrks1bin"); 
    TProfile *Cn35_Gap04 = (TProfile*)list->FindObject("fTprofC35Gap04ANtrks1bin");
    TProfile *Cn42_Gap04 = (TProfile*)list->FindObject("fTprofC42Gap04Ntrks1bin");  
    TProfile *Cn43_Gap04 = (TProfile*)list->FindObject("fTprofC43Gap04Ntrks1bin");  

    TProfile *Cn34_Gap05 = (TProfile*)list->FindObject("fTprofC34Gap05ANtrks1bin"); 
    TProfile *Cn35_Gap05 = (TProfile*)list->FindObject("fTprofC35Gap05ANtrks1bin");
    TProfile *Cn42_Gap05 = (TProfile*)list->FindObject("fTprofC42Gap05Ntrks1bin");  
    TProfile *Cn43_Gap05 = (TProfile*)list->FindObject("fTprofC43Gap05Ntrks1bin");  

    TProfile *Cn34_Gap06 = (TProfile*)list->FindObject("fTprofC34Gap06ANtrks1bin"); 
    TProfile *Cn35_Gap06 = (TProfile*)list->FindObject("fTprofC35Gap06ANtrks1bin");
    TProfile *Cn42_Gap06 = (TProfile*)list->FindObject("fTprofC42Gap06Ntrks1bin");  
    TProfile *Cn43_Gap06 = (TProfile*)list->FindObject("fTprofC43Gap06Ntrks1bin");  

    TProfile *Cn34_Gap07 = (TProfile*)list->FindObject("fTprofC34Gap07ANtrks1bin"); 
    TProfile *Cn35_Gap07 = (TProfile*)list->FindObject("fTprofC35Gap07ANtrks1bin");
    TProfile *Cn42_Gap07 = (TProfile*)list->FindObject("fTprofC42Gap07Ntrks1bin");  
    TProfile *Cn43_Gap07 = (TProfile*)list->FindObject("fTprofC43Gap07Ntrks1bin");  

    TProfile *Cn34_Gap08 = (TProfile*)list->FindObject("fTprofC34Gap08ANtrks1bin"); 
    TProfile *Cn35_Gap08 = (TProfile*)list->FindObject("fTprofC35Gap08ANtrks1bin");
    TProfile *Cn42_Gap08 = (TProfile*)list->FindObject("fTprofC42Gap08Ntrks1bin");  
    TProfile *Cn43_Gap08 = (TProfile*)list->FindObject("fTprofC43Gap08Ntrks1bin");  
    
    //=================================================================================
    //==========================================================================
    int binning = 10;
    double errorNum;
    double sumNum = 0;
    double sumDenom = 1;
    double content = 0;

    if(binning == 10)RebinAll(Cn43_Gap00, Rebin_Ratio_1, 10);
    if(!Cn43_Gap00) fPrint("Warning there is no histogram");
    Rebin_Ratio_1->GetXaxis()->SetRangeUser(10, 100);
    Rebin_Ratio_1->Draw("same");

    if(binning == 10)RebinAll(Cn43_Gap01, Rebin_Ratio_2, 10);
    if(!Cn43_Gap01) fPrint("Warning there is no histogram");
    Rebin_Ratio_2->GetXaxis()->SetRangeUser(10, 100);
    Rebin_Ratio_2->Draw("same");

    if(binning == 10)RebinAll(Cn43_Gap02, Rebin_Ratio_3, 10);
    if(!Cn43_Gap02) fPrint("Warning there is no histogram");
    Rebin_Ratio_3->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_3->Draw("same");

    if(binning == 10)RebinAll(Cn43_Gap03, Rebin_Ratio_4, 10);
    if(!Cn43_Gap03) fPrint("Warning there is no histogram");
    Rebin_Ratio_4->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_4->Draw("same");

    if(binning == 10)RebinAll(Cn43_Gap04, Rebin_Ratio_5, 10);
    if(!Cn43_Gap04) fPrint("Warning there is no histogram");
    Rebin_Ratio_5->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_5->Draw("same");

    if(binning == 10)RebinAll(Cn43_Gap05, Rebin_Ratio_6, 10);
    if(!Cn43_Gap05) fPrint("Warning there is no histogram");
    Rebin_Ratio_6->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_6->Draw("same");

    if(binning == 10)RebinAll(Cn43_Gap06, Rebin_Ratio_7, 10);
    if(!Cn43_Gap06) fPrint("Warning there is no histogram");
    Rebin_Ratio_7->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_7->Draw("same");

    if(binning == 10)RebinAll(Cn43_Gap07, Rebin_Ratio_8, 10);
    if(!Cn43_Gap07) fPrint("Warning there is no histogram");
    Rebin_Ratio_8->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_8->Draw("same");

    if(binning == 10)RebinAll(Cn43_Gap08, Rebin_Ratio_9, 10);
    if(!Cn43_Gap08) fPrint("Warning there is no histogram");
    Rebin_Ratio_9->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_9->Draw("same");

    //..Create New root.file:
    TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Fit_Eta_Dependent_3part_4_part_Macros/Fit_Delta_eta_3part_4part_Correlations/Thesis_Delta_eta_dependent_output/Cut_Rebin_3part_4part_thesis.root","UPDATE");
    if(!fileOutput) return;
    fileOutput->cd();
    Rebin_Ratio_1->Write("Rebin_43particle_Gap00A");
    Rebin_Ratio_2->Write("Rebin_43particle_Gap01A");
    Rebin_Ratio_3->Write("Rebin_43particle_Gap02A");  
    Rebin_Ratio_4->Write("Rebin_43particle_Gap03A");
    Rebin_Ratio_5->Write("Rebin_43particle_Gap04A");
    Rebin_Ratio_6->Write("Rebin_43particle_Gap05A");
    Rebin_Ratio_7->Write("Rebin_43particle_Gap06A");
    Rebin_Ratio_8->Write("Rebin_43particle_Gap07A");
    Rebin_Ratio_9->Write("Rebin_43particle_Gap08A");
}
//_____________________________________________________________________________
// //..Define Rebin Function
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

