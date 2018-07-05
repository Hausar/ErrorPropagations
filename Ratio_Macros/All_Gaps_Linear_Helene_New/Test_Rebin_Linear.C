//Macro To Calculate the Rebin plots Linear:
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
void Test_Rebin_Linear() {
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();
    //**************************************************************************
    //..Define histograms
    TH1D *Rebin_Ratio_1 = new TH1D("Rebin_Ratio_1", "|#Delta #eta| > 0.0", 20, 0, 200);
    Rebin_Ratio_1->Sumw2();    
    //..Open Root file:
    TFile* fileOutput = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Modified_Debugged_Average_V4_Linear_A+B_NUA+NUE.root","READ");
    if(!fileOutput) return; 
    hCLinear_Gap00 = (TH1D*)fileOutput->Get("V4_Linear_Gap00_A+B");
    int binning = 10;
    double errorNum;
    double sumNum = 0;
    double sumDenom = 1;
    double content = 0;
    if(binning == 10)RebinAll(hCLinear_Gap00, Rebin_Ratio_1, 10);
    if(!hCLinear_Gap00) fPrint("Warning there is no histogram");
    //Rebin_Ratio_9->GetXaxis()->SetRangeUser(10, 100);
    //Rebin_Ratio_9->Draw("same");
    TFile* fileOutput2 = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Rebin_Modified_V4_Linear_A+B_NUA+NUE.root","UPDATE");
    if(!fileOutput2) return;
    fileOutput2->cd();
    Rebin_Ratio_1->Write("Modified_Rebin_hCLinear_Gap00_A+B");
    Rebin_Ratio_1->Draw();
}
//..Define Rebin Function
_____________________________________________________________________________
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
                //cout << "i: " << i << endl;
                //cout << "sumNum: " << sumNum[i] << endl;
                //cout << "errorNum: " << errorNum[i] << endl;
			}
			bin += 1;
		}

		for(int i=1; i<21; i++)
		{
			if(sumDenom[i] != 0) content[i] = sumNum[i]/sumDenom[i];
			if(sumDenom[i] != 0) error[i] = TMath::Sqrt(errorNum[i]/(TMath::Power(sumDenom[i], 2.)));
            //cout << "i: " << i << endl;
            //cout << "error: " << error[i] << endl;
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
// //_______________________________________________________________________________
//     TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Rebin_Modified_V5_Linear_A+B_NUA+NUE.root","READ");

//     // TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Rebin_Plots_Helene_You_V4L_V5L_NL/Rebin_V5L_Helene.root","READ");

//     TH1D* Rebin_hCLinear_Gap00A = (TH1D*)fileOutput->Get("Modified_Rebin_hCLinear_Gap00A");
//     TH1D* Rebin_hCLinear_Gap01A = (TH1D*)fileOutput->Get("Modified_Rebin_hCLinear_Gap01A");
//     TH1D* Rebin_hCLinear_Gap02A = (TH1D*)fileOutput->Get("Modified_Rebin_hCLinear_Gap02A");
//     TH1D* Rebin_hCLinear_Gap03A = (TH1D*)fileOutput->Get("Modified_Rebin_hCLinear_Gap03A");
//     TH1D* Rebin_hCLinear_Gap04A = (TH1D*)fileOutput->Get("Modified_Rebin_hCLinear_Gap04A");
//     TH1D* Rebin_hCLinear_Gap05A = (TH1D*)fileOutput->Get("Modified_Rebin_hCLinear_Gap05A");
//     TH1D* Rebin_hCLinear_Gap06A = (TH1D*)fileOutput->Get("Modified_Rebin_hCLinear_Gap06A");
//     TH1D* Rebin_hCLinear_Gap07A = (TH1D*)fileOutput->Get("Modified_Rebin_hCLinear_Gap07A");
//     TH1D* Rebin_hCLinear_Gap08A = (TH1D*)fileOutput->Get("Modified_Rebin_hCLinear_Gap08A");

//     Rebin_hCLinear_Gap00A->SetMarkerStyle(kFullCircle); 
//     Rebin_hCLinear_Gap00A->SetMarkerColor(kBlue+1);
//     Rebin_hCLinear_Gap00A->SetStats(0);
//     Rebin_hCLinear_Gap00A->SetTitle(0);
//     Rebin_hCLinear_Gap00A->GetXaxis()->SetRangeUser(20, 80);
//     Rebin_hCLinear_Gap00A->Draw("P");
//     Rebin_hCLinear_Gap00A->GetYaxis()->SetRangeUser(-0.001, 0.034);
//     Rebin_hCLinear_Gap00A->GetYaxis()->SetTitleOffset(1.3);
//     //Rebin_hCLinear_Gap00A->GetYaxis()->SetTitleSize(0.1);
//     //Rebin_hCLinear_Gap00A->GetYaxis()->CenterTitle(true);
//     Rebin_hCLinear_Gap00A->GetYaxis()->SetTitle("V_{5}^{L}");
//     //Rebin_hCLinear_Gap00A->GetXaxis()->SetTitle("N_{trks}");
//     Rebin_hCLinear_Gap00A->GetXaxis()->SetTitleOffset(1.2);
//     //Rebin_hCLinear_Gap00A->GetXaxis()->CenterTitle(true);
//     //gStyle->SetTitleFontSize(0.2);
//     Rebin_hCLinear_Gap00A->GetXaxis()->SetTitle("N_{Ch}(|#eta| < 0.8)");

//     Rebin_hCLinear_Gap01A->SetMarkerStyle(kFullTriangleUp); 
//     Rebin_hCLinear_Gap01A->SetMarkerColor(kRed+1);
//     Rebin_hCLinear_Gap01A->SetLineColor(kRed+1);
//     Rebin_hCLinear_Gap01A->SetMarkerSize(1.3);
//     Rebin_hCLinear_Gap01A->GetXaxis()->SetRangeUser(10, 90);
//     Rebin_hCLinear_Gap01A->Draw("same");

//     Rebin_hCLinear_Gap02A->SetMarkerStyle(kFullCircle); 
//     Rebin_hCLinear_Gap02A->SetMarkerColor(kRed+4);
//     Rebin_hCLinear_Gap02A->SetLineColor(kRed+4);
//     Rebin_hCLinear_Gap02A->SetStats(0);
//     Rebin_hCLinear_Gap01A->GetXaxis()->SetRangeUser(10, 90);
//     Rebin_hCLinear_Gap02A->Draw("same");

//     Rebin_hCLinear_Gap03A->SetMarkerStyle(kFullSquare); 
//     Rebin_hCLinear_Gap03A->SetMarkerColor(kGreen+3);
//     Rebin_hCLinear_Gap03A->SetLineColor(kGreen+3);
//     Rebin_hCLinear_Gap03A->SetMarkerSize(1.2);
//     Rebin_hCLinear_Gap03A->SetStats(0);
//     Rebin_hCLinear_Gap03A->GetXaxis()->SetRangeUser(10, 90);
//     Rebin_hCLinear_Gap03A->Draw("same");

//     Rebin_hCLinear_Gap04A->SetMarkerStyle(kFullDiamond); 
//     Rebin_hCLinear_Gap04A->SetMarkerColor(kBlack+3);
//     Rebin_hCLinear_Gap04A->SetLineColor(kBlack+3);
//     Rebin_hCLinear_Gap04A->SetMarkerSize(2.);
//     Rebin_hCLinear_Gap04A->SetStats(0);
//     Rebin_hCLinear_Gap04A->SetMarkerSize(2);
//     Rebin_hCLinear_Gap04A->GetXaxis()->SetRangeUser(10, 90);
//     Rebin_hCLinear_Gap04A->Draw("same");

//     Rebin_hCLinear_Gap05A->SetMarkerStyle(kFullStar); 
//     Rebin_hCLinear_Gap05A->SetMarkerColor(kOrange-3);
//     Rebin_hCLinear_Gap05A->SetLineColor(kOrange-3);
//     Rebin_hCLinear_Gap05A->SetStats(0);
//     Rebin_hCLinear_Gap05A->SetMarkerSize(2.1);
//     Rebin_hCLinear_Gap05A->GetXaxis()->SetRangeUser(10, 90);
//     Rebin_hCLinear_Gap05A->Draw("same");

//     Rebin_hCLinear_Gap06A->SetMarkerStyle(kFullCross); 
//     Rebin_hCLinear_Gap06A->SetMarkerColor(kSpring+5);
//     Rebin_hCLinear_Gap06A->SetLineColor(kSpring+5);
//     Rebin_hCLinear_Gap06A->SetStats(0);
//     Rebin_hCLinear_Gap06A->SetMarkerSize(2.);
//     Rebin_hCLinear_Gap06A->GetXaxis()->SetRangeUser(10, 90);
//     Rebin_hCLinear_Gap06A->Draw("same");

//     // Rebin_hCLinear_Gap07A->SetMarkerStyle(kFullDiamond); 
//     // Rebin_hCLinear_Gap07A->SetMarkerColor(kCyan-7);
//     // Rebin_hCLinear_Gap07A->SetLineColor(kCyan-7);
//     // Rebin_hCLinear_Gap07A->SetStats(0);
//     // Rebin_hCLinear_Gap07A->SetMarkerSize(2.2);
//     // Rebin_hCLinear_Gap07A->GetXaxis()->SetRangeUser(10, 90);
//     // Rebin_hCLinear_Gap07A->Draw("same");

//     // Rebin_hCLinear_Gap08A->SetMarkerStyle(kFullCircle); 
//     // Rebin_hCLinear_Gap08A->SetMarkerColor(kMagenta);
//     // Rebin_hCLinear_Gap08A->SetLineColor(kMagenta);
//     // Rebin_hCLinear_Gap08A->SetMarkerSize(1.2);
//     // Rebin_hCLinear_Gap08A->SetStats(0);
//     // Rebin_hCLinear_Gap08A->GetXaxis()->SetRangeUser(10, 90);
//     // Rebin_hCLinear_Gap08A->Draw("same");

//     TLegend *legend = new TLegend(0.6,0.5,0.89,0.9);
//    //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
//     legend->AddEntry(Rebin_hCLinear_Gap00A,"|#Delta #eta| > 0.0", "lep");
//     legend->AddEntry(Rebin_hCLinear_Gap01A,"|#Delta #eta| > 0.1", "lep");
//     legend->AddEntry(Rebin_hCLinear_Gap02A,"|#Delta #eta| > 0.2","lep");
//     legend->AddEntry(Rebin_hCLinear_Gap03A,"|#Delta #eta| > 0.3","lep");
//     legend->AddEntry(Rebin_hCLinear_Gap04A,"|#Delta #eta| > 0.4","lep");
//     legend->AddEntry(Rebin_hCLinear_Gap05A,"|#Delta #eta| > 0.5","lep");
//     legend->AddEntry(Rebin_hCLinear_Gap06A,"|#Delta #eta| > 0.6","lep");
//     // legend->AddEntry(Rebin_hCLinear_Gap07A,"|#Delta #eta| > 0.7","lep");
//     // legend->AddEntry(Rebin_hCLinear_Gap08A,"|#Delta #eta| > 0.8","lep");
//     legend->Draw();

//     TLatex latex;
//     latex.SetTextSize(0.035);
//     latex.SetTextAlign(13);  //align at top
//     latex.DrawLatex(25,0.032,"ALICE");
       
//     latex.SetTextSize(0.036);
//     latex.SetTextAlign(13);  //align at top
//     latex.DrawLatex(25,0.03,"p-Pb collisions (This Thesis)"); 

//     latex.SetTextSize(0.036);
//     latex.SetTextAlign(13);  //align at top
//     latex.DrawLatex(25,0.028,"#sqrt{s_{NN}} = 5.02 TeV");

//     latex.SetTextAlign(13);  //centered
//     latex.DrawLatex(25,0.026,"|#Delta #eta| < 0.8");

//     latex.SetTextAlign(13);  //centered
//     latex.DrawLatex(25,0.024," 0.2 < p_{T} < 3.0 GeV/c");

//     c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_NonLinear_V532/Modified_V5_Linear_Gap06.png");
// }

