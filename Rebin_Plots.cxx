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

void Rebin_Plots() 
{    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //**************************************************************************
    //..V4,22 

    // TH1D *hC22_Rebin = new TH1D("hC22_Rebin", "v_{4}{2}, |#Delta #eta| > 0.2", 20, 0, 200); //this is just define a histogram which will fill the data.
    // hC22_Rebin->Sumw2();
    // //hC22_Rebin->Draw();

    // TH1D *hCV422_Rebin = new TH1D("hCV422_Rebin", "Non-Linear Response, v_{4,22}", 20, 0, 200); //this is just define a histogram which will fill the data of V422.
    // hCV422_Rebin->Sumw2();

    // TH1D *hCLinear_Rebin = new TH1D("hCLinear_Rebin", " The Linear Response V4^{L} ", 20, 0, 200); //this is just define a histogram which will fill the data.
    // hCLinear_Rebin->Sumw2();

    // //..Open Root.File:
    // //TFile *file = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/V4_Linear_NonLinear_Response_WOGap.root", "READ");
    // TFile *file = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/V4_Linear_NonLinear_Response_Gap02.root", "READ");

    // TH1D *hC22 = (TH1D*)file->Get("hC22");
    // TH1D *hCV422 = (TH1D*)file->Get("hCV422");
    // TH1D *hCLinear = (TH1D*)file->Get("hCLinear");
    // // hC22->Draw("same");
    // // hCV422->Draw("same");
    // // hCLinear->Draw("same");
    // int binning = 10;
    // double errorNum;
    // double sumNum = 0;
    // double sumDenom = 1;
    // double content = 0;

    // if(binning == 10)RebinAll(hC22, hC22_Rebin, 10);
    // if(!hC22) fPrint("Warning there is no histogram");
    // hC22_Rebin->GetXaxis()->SetRangeUser(10, 110);
    // //hC22_Rebin->Draw("same");

    // if(binning == 10)RebinAll(hCV422, hCV422_Rebin, 10);
    // if(!hCV422) fPrint("Warning there is no histogram");
    // hCV422_Rebin->GetXaxis()->SetRangeUser(10, 110);
    // //hCV422_Rebin->Draw("same");

    // if(binning == 10)RebinAll(hCLinear, hCLinear_Rebin, 10);
    // if(!hCLinear) fPrint("Warning there is no histogram");
    // hCLinear_Rebin->GetXaxis()->SetRangeUser(10, 110);
    // //hCLinear_Rebin->Draw("same");

    //********************************************************************************************************************
    //.. V5,32: 
    //TFile *file = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/V5_Linear_NonLinear_Response_WOGap.root", "READ");
    // TFile *file = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/V5_Linear_NonLinear_Response_Gap02.root", "READ");
    
    // //..TProfile for V5:
    // TH1D *hC22_Rebin = new TH1D("hC22_Rebin", " v_{5}{2}, |#Delta #eta| > 0.2", 20, 0, 200); //this is just define a histogram which will fill the data.
    // hC22_Rebin->Sumw2();
    // //hC22_Rebin->Draw();

    // TH1D *hCV532_Rebin = new TH1D("hCV532_Rebin", "Non-Linear Response, v_{5,32} |#Delta #eta| > 0.2", 20, 0, 200); //this is just define a histogram which will fill the data of V422.
    // hCV532_Rebin->Sumw2();


    // TH1D *hCLinear_Rebin = new TH1D("hCLinear_Rebin", " The Linear Response v_{5}^{L} ", 20, 0, 200); //this is just define a histogram which will fill the data.
    // hCLinear_Rebin->Sumw2();

    // TH1D *hC22 = (TH1D*)file->Get("hC22");
    // TH1D *hCV532 = (TH1D*)file->Get("hCV532");
    // TH1D *hCLinear = (TH1D*)file->Get("hCLinear");

    // //hC22->Draw("same");
    // // hCV532->Draw("same");
    // // hCLinear->Draw("same");
    // int binning = 10;
    // double errorNum;
    // double sumNum = 0;
    // double sumDenom = 1;
    // double content = 0;

    // if(binning == 10)RebinAll(hC22, hC22_Rebin, 10);
    // if(!hC22) fPrint("Warning there is no histogram");
    // hC22_Rebin->GetXaxis()->SetRangeUser(10, 110);
    // //hC22_Rebin->Draw("same");

    // if(binning == 10)RebinAll(hCV532, hCV532_Rebin, 10);
    // if(!hCV532) fPrint("Warning there is no histogram");
    // hCV532_Rebin->GetXaxis()->SetRangeUser(10, 110);
    // //hCV532_Rebin->Draw("same");

    // if(binning == 10)RebinAll(hCLinear, hCLinear_Rebin, 10);
    // if(!hCLinear) fPrint("Warning there is no histogram");
    // hCLinear_Rebin->GetXaxis()->SetRangeUser(10, 110);
    // //hCLinear_Rebin->Draw("same");

    //********************************************************************************************************************
    //.. Chi_4,22 and Chi_5,32: 
    TFile *file = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Chi422_Chi532_Gap02.root", "READ");
    // TFile *file = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/V5_Linear_NonLinear_Response_Gap02.root", "READ");
    
    //..TProfile for V5:
    TH1D *hChi422_Rebin = new TH1D("hChi422_Rebin", " #chi_{4,22}, |#Delta #eta| > 0.2", 20, 0, 200); //this is just define a histogram which will fill the data.
    hChi422_Rebin->Sumw2();
    //hChi422_Rebin->Draw();

    TH1D *hChi532_Rebin = new TH1D("hChi532_Rebin", " #chi_{5,32} |#Delta #eta| > 0.2", 20, 0, 200); //this is just define a histogram which will fill the data of hChi532.
    hChi532_Rebin->Sumw2();

    TH1D *hChi422 = (TH1D*)file->Get("hChi422");
    TH1D *hChi532 = (TH1D*)file->Get("hChi532");

    // hChi422->Draw("same"); 
    // hChi532->Draw("same");
    
    int binning = 10;
    double errorNum;
    double sumNum = 0;
    double sumDenom = 1;
    double content = 0;

    if(binning == 10)RebinAll(hChi422, hChi422_Rebin, 10);
    if(!hChi422) fPrint("Warning there is no histogram");
    hChi422_Rebin->GetXaxis()->SetRangeUser(10, 140);
    hChi422_Rebin->GetYaxis()->SetRangeUser(0, 10);
    //hChi422_Rebin->Draw("same");

    if(binning == 10)RebinAll(hChi532, hChi532_Rebin, 10);
    if(!hChi532) fPrint("Warning there is no histogram");
    hChi532_Rebin->GetXaxis()->SetRangeUser(10, 140);
    hChi532_Rebin->GetYaxis()->SetRangeUser(0, 10);
    //hChi532_Rebin->Draw("same");

    // *****************************************************************************
    // ..Plot the results:        
    // hCLinear_Rebin->SetMarkerStyle(21);
    // hCLinear_Rebin->SetMarkerColorAlpha(kBlack, 4.5);
    // hCLinear_Rebin->SetXTitle("# of tracks");
    // hCLinear_Rebin->SetYTitle("v_{4}^{L}");
    // hCLinear_Rebin->SetMarkerSize(1.);
    // hCLinear_Rebin->Draw();
    // c->BuildLegend();

    // hCLinear_Rebin->SetMarkerStyle(21);
    // hCLinear_Rebin->SetMarkerColorAlpha(kTeal, 4.5);
    // hCLinear_Rebin->SetXTitle("# of tracks");
    // hCLinear_Rebin->SetYTitle("v_{5}^{L}");
    // hCLinear_Rebin->SetMarkerSize(2.);
    // hCLinear_Rebin->Draw();
    // c->BuildLegend();

    // hCV422_Rebin->SetMarkerStyle(34);
    // hCV422_Rebin->SetMarkerColorAlpha(kBlue, 0.45);
    // hCV422_Rebin->SetXTitle("# of tracks");
    // hCV422_Rebin->SetYTitle("v_{4,22}");
    // hCV422_Rebin->SetMarkerSize(2.);
	// hCV422_Rebin->Draw("same");
    // c->BuildLegend();

    // hCV532_Rebin->SetMarkerStyle(34);
    // hCV532_Rebin->SetMarkerColorAlpha(kGreen, 0.45);
    // hCV532_Rebin->SetXTitle("# of tracks");
    // hCV532_Rebin->SetYTitle("v_{5,32}");
    // hCV532_Rebin->SetMarkerSize(2.);
	// hCV532_Rebin->Draw("same");
    // c->BuildLegend();

    // hC22_Rebin->SetMarkerStyle(22);
    // hC22_Rebin->SetMarkerColorAlpha(kViolet, 4.5);
    // hC22_Rebin->SetMarkerSize(2.);
    // hC22_Rebin->SetXTitle("# of tracks");
    // hC22_Rebin->SetYTitle("v_{5}");
    // gStyle->SetOptStat(0);
    // hC22_Rebin->Draw("same");
    // c->BuildLegend();

    //**************************************************************************
    //..Plot Chi422: 
    hChi422_Rebin->GetYaxis()->SetRangeUser(0., 4.);
    hChi422_Rebin->GetXaxis()->SetRangeUser(0., 140);
    hChi422_Rebin->SetMarkerSize(1.);
    hChi422_Rebin->Draw("same");
    hChi422_Rebin->SetTitle("Non-Linear coefficient #chi_{4,22} of v_{4,22} for pPb at 5.02 TeV");
    hChi422_Rebin->SetMarkerStyle(kFullTriangleUp); 
    hChi422_Rebin->SetMarkerColor(kRed+1);
    hChi422_Rebin->GetYaxis()->SetTitleOffset(1.4);
    //hChi422_Rebin->GetYaxis()->CenterTitle(true);
    hChi422_Rebin->GetYaxis()->SetTitle("#chi_{4,22}");

    hChi422_Rebin->GetXaxis()->SetTitleOffset(1.4);
    //hChi422_Rebin->GetXaxis()->CenterTitle(true);
    gStyle->SetTitleFontSize(0.2);
    hChi422_Rebin->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    hChi422_Rebin->SetFillColor(kRed-9);
    c->Update();
    
    TLatex latex;
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(10,3.5,"#sqrt{s_{NN}} = 5.02 TeV");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(10,3.3,"|#Delta #eta| < 0.8");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(10,3.1," 0.2 < p_{T} < 3.0");

    TLegend *leg = new TLegend(0.4, 0.5, 0.55, 0.55); 
    leg->AddEntry(hChi422_Rebin, "#chi_{4,22}", "fp");
    leg->Draw("same");
    
    leg->SetBorderSize(0);
    gStyle->SetTitleFontSize(0.2);

    //************************************************
    //..Plot Chi532
    hChi532_Rebin->GetYaxis()->SetRangeUser(0., 10.);
    hChi532_Rebin->GetXaxis()->SetRangeUser(0., 140);
    hChi532_Rebin->SetMarkerSize(1.);
    hChi532_Rebin->Draw("same");
    hChi532_Rebin->SetTitle("Non-Linear coefficient #chi_{5,32} of v_{5,32} for pPb at 5.02 TeV");
    hChi532_Rebin->SetMarkerStyle(kFullTriangleUp); 
    hChi532_Rebin->SetMarkerColor(kBlue+1);
    hChi532_Rebin->GetYaxis()->SetTitleOffset(1.4);
    //hChi532_Rebin->GetYaxis()->CenterTitle(true);
    hChi532_Rebin->GetYaxis()->SetTitle("#chi_{5,32}");

    hChi532_Rebin->GetXaxis()->SetTitleOffset(1.4);
    //hChi532_Rebin->GetXaxis()->CenterTitle(true);
    gStyle->SetTitleFontSize(0.2);
    hChi532_Rebin->GetXaxis()->SetTitle("N_{Ch}(|#Delta#eta| < 0.8)");
    hChi532_Rebin->SetFillColor(kBlue-9);
    c->Update();
    
    TLatex latex;
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(10,3.5,"#sqrt{s_{NN}} = 5.02 TeV");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(10,3.3,"|#Delta #eta| < 0.8");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(10,3.1," 0.2 < p_{T} < 3.0");

    TLegend *leg = new TLegend(0.4, 0.5, 0.55, 0.55); 
    leg->AddEntry(hChi532_Rebin, "#chi_{5,32}", "fp");
    leg->Draw("same");
    
    leg->SetBorderSize(0);
    gStyle->SetTitleFontSize(0.2);

    //***************************************************************************
    //..Writting to the Root.file:
    //..V4,22
    // TFile* fileOutput = new TFile("Rebin_Plots_V4_Linear_NonLinear_Response_Gap02.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC22_Rebin->Write();
    // hCV422_Rebin->Write();
    // hCLinear_Rebin->Write();
    // fileOutput->Close();
    // return;

    //..V5,32
    // TFile* fileOutput = new TFile("Rebin_Plots_V5_Linear_NonLinear_Response_Gap02.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // hC22_Rebin->Write();
    // hCV532_Rebin->Write();
    // hCLinear_Rebin->Write();
    // fileOutput->Close();
    // return;

    //..Chi4,22 and Chi5,32
    TFile* fileOutput = new TFile("Rebin_Plots_Chi422_Chi532_Gap02.root","RECREATE");
    if(!fileOutput) return;
    fileOutput->cd();
    hChi422_Rebin->Write();
    hChi532_Rebin->Write();
    fileOutput->Close();
    return;
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
            //if(sumDenom[i] != 0) error[i] = TMath::Sqrt(errorNum[i] * 1/ (TMath::Power(sumDenom[i], 2.)));
            cout << "i: " << i << endl;
            cout << "error: " << error[i] << endl;
			h2->SetBinContent(i, content[i]);
			h2->SetBinError(i, error[i]);
		}
	}

}
//_______________________________________________________________________________
