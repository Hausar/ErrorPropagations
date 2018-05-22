//..The macro for plot Rebin: V4_NL, V4_L, V4{2} and 
//..The macro for plot Rebin: V5_NL, V5_L, V5{2}
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

void Plot_MonteCarlo_Data() 
{    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //============================================================================================
    //..Unit bins:
    //Open the Data root.file:
    // TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_New_Checked.root", "READ");
    // TDirectory *dir = (TDirectoryFile*)file->Get("default");
    // TList *list = (TList*)dir->Get("Flow_Refs_default");

    // TProfile *Cn25_Data0= (TProfile*)list->FindObject("fTprofC25Gap00Ntrks1bin");   //..V5{2}
    // TProfile *Cn22_Data = (TProfile*)list->FindObject("fTprofC22Gap00Ntrks1bin");   //..v2^{2}
    // TProfile *Cn23_Data = (TProfile*)list->FindObject("fTprofC23Gap00Ntrks1bin");   //..v3^{2}
    // TProfile *Cn35_Data = (TProfile*)list->FindObject("fTprofC35Gap00ANtrks1bin");  //..<<3>>_{5|-3,-2}
    // TProfile *Cn34_Data = (TProfile*)list->FindObject("fTprofC34Gap00ANtrks1bin");  //..<<3>>_{4|-2,-2}
    // TProfile *Cn35_Data = (TProfile*)list->FindObject("fTprofC42Gap00Ntrks1bin");
    // TProfile *Cn35_Data = (TProfile*)list->FindObject("fTprofC43Gap00Ntrks1bin");

    //..Open the MC root.file: 
    // TFile *fileMC = TFile::Open
    // ("/Users/Helena/Desktop/MonteCarlo_Runs/merging/Monte_Carlo_Checks.root", "READ");
    // TDirectory *dirMC = (TDirectoryFile*)fileMC->Get("default");
    // TList *listMC = (TList*)dirMC->Get("Flow_Refs_default");

    // TProfile *Cn25_MC = (TProfile*)listMC->FindObject("fTprofC25Gap00Ntrks1bin");   //..V5{2}
    // TProfile *Cn22_MC = (TProfile*)listMC->FindObject("fTprofC22Gap00Ntrks1bin");   //..v2^{2}
    // TProfile *Cn23_MC = (TProfile*)listMC->FindObject("fTprofC23Gap00Ntrks1bin");   //..v3^{2}
    // TProfile *Cn35_MC = (TProfile*)listMC->FindObject("fTprofC35Gap00ANtrks1bin");  //..<<3>>_{5|-3,-2}
    // TProfile *Cn34_MC = (TProfile*)listMC->FindObject("fTprofC34Gap00ANtrks1bin");  //..<<3>>_{4|-2,-2}
    // TProfile *Cn42_MC = (TProfile*)listMC->FindObject("fTprofC42Gap00Ntrks1bin");  //..<<4>>_{3,2|-3,-2}
    // TProfile *Cn43_MC = (TProfile*)listMC->FindObject("fTprofC43Gap00Ntrks1bin");  //..<<4>>_{2,2|-2,-2}

    //=============================================================================================
    //..Rebin Data:
    //Open the Rebin Data root.file:
    TFile *file1 = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Rebin_MC_Data/Results_Rebin_Data.root","READ");
    TH1D* Data_Rebin_Cn34_Gap00 = (TH1D*)file1->Get("Rebin_Cn34_Gap00");
    TH1D* Data_Rebin_Cn34_Gap01 = (TH1D*)file1->Get("Rebin_Cn34_Gap01");
    TH1D* Data_Rebin_Cn34_Gap02 = (TH1D*)file1->Get("Rebin_Cn34_Gap02");
    TH1D* Data_Rebin_Cn34_Gap03 = (TH1D*)file1->Get("Rebin_Cn34_Gap03");
    TH1D* Data_Rebin_Cn34_Gap04 = (TH1D*)file1->Get("Rebin_Cn34_Gap04");
    TH1D* Data_Rebin_Cn34_Gap05 = (TH1D*)file1->Get("Rebin_Cn34_Gap05");
    TH1D* Data_Rebin_Cn34_Gap06 = (TH1D*)file1->Get("Rebin_Cn34_Gap06");
    TH1D* Data_Rebin_Cn34_Gap07 = (TH1D*)file1->Get("Rebin_Cn34_Gap07");
    TH1D* Data_Rebin_Cn34_Gap08 = (TH1D*)file1->Get("Rebin_Cn34_Gap08");

    TFile *file2 = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Rebin_MC_Data/Rebin_MC.root","READ");
    
    TH1D* MC_Rebin_Cn34_Gap00 = (TH1D*)file2 ->Get("MC_Rebin_Cn34_Gap00");
    TH1D* MC_Rebin_Cn34_Gap01 = (TH1D*)file2->Get("MC_Rebin_Cn34_Gap01");
    TH1D* MC_Rebin_Cn34_Gap02 = (TH1D*)file2->Get("MC_Rebin_Cn34_Gap02");
    TH1D* MC_Rebin_Cn34_Gap03 = (TH1D*)file2->Get("MC_Rebin_Cn34_Gap03");
    TH1D* MC_Rebin_Cn34_Gap04 = (TH1D*)file2->Get("MC_Rebin_Cn34_Gap04");
    TH1D* MC_Rebin_Cn34_Gap05 = (TH1D*)file2->Get("MC_Rebin_Cn34_Gap05");
    TH1D* MC_Rebin_Cn34_Gap06 = (TH1D*)file2->Get("MC_Rebin_Cn34_Gap06");
    TH1D* MC_Rebin_Cn34_Gap07 = (TH1D*)file2->Get("MC_Rebin_Cn34_Gap07");
    TH1D* MC_Rebin_Cn34_Gap08 = (TH1D*)file2->Get("MC_Rebin_Cn34_Gap08");

    double y[100] = {0};
    double x[100] = {0};
    double ex[100] = {0};
    double ey[100] = {0}; 

    double y1[100] = {0};
    double x1[100] = {0};
    double ey1[100] = {0};

    double y2[100] = {0};
    double x2[100] = {0};
    double ey2[100] = {0}; 

    double y3[100] = {0};
    double x3[100] = {0};
    double ey3[100] = {0}; 
    
    double y4[100] = {0};
    double x4[100] = {0};
    double ey4[100] = {0}; 

    double y5[100] = {0};
    double x5[100] = {0};
    double ey5[100] = {0}; 

    double y6[100] = {0};
    double x6[100] = {0};
    double ey6[100] = {0}; 

    double y7[100] = {0};
    double x7[100] = {0};
    double ey7[100] = {0}; 

    double y8[100] = {0};
    double x8[100] = {0};
    double ey8[100] = {0}; 

    int n = 10;
    for(int i=1; i<12; i++) {
        y[i] = MC_Rebin_Cn34_Gap00->GetBinContent(i);
        ey[i] = MC_Rebin_Cn34_Gap00->GetBinError(i);
        x[i] = MC_Rebin_Cn34_Gap00->GetBinCenter(i);  //This one will give you the x-axis
        
        y1[i] = MC_Rebin_Cn34_Gap01->GetBinContent(i);
        ey1[i] = MC_Rebin_Cn34_Gap01->GetBinError(i);
        x1[i] = MC_Rebin_Cn34_Gap01->GetBinCenter(i);

        y2[i] = MC_Rebin_Cn34_Gap02->GetBinContent(i);
        ey2[i] = MC_Rebin_Cn34_Gap02->GetBinError(i);
        x2[i] = MC_Rebin_Cn34_Gap02->GetBinCenter(i);
        
        y3[i] = MC_Rebin_Cn34_Gap03->GetBinContent(i);
        ey3[i] = MC_Rebin_Cn34_Gap03->GetBinError(i);
        x3[i] = MC_Rebin_Cn34_Gap03->GetBinCenter(i);

        y4[i] = MC_Rebin_Cn34_Gap04->GetBinContent(i);
        ey4[i] = MC_Rebin_Cn34_Gap04->GetBinError(i);
        x4[i] = MC_Rebin_Cn34_Gap04->GetBinCenter(i);

        y5[i] = MC_Rebin_Cn34_Gap05->GetBinContent(i);
        ey5[i] = MC_Rebin_Cn34_Gap05->GetBinError(i);
        x5[i] = MC_Rebin_Cn34_Gap05->GetBinCenter(i);

        y6[i] = MC_Rebin_Cn34_Gap06->GetBinContent(i);
        ey6[i] = MC_Rebin_Cn34_Gap06->GetBinError(i);
        x6[i] = MC_Rebin_Cn34_Gap06->GetBinCenter(i);

        y7[i] = MC_Rebin_Cn34_Gap07->GetBinContent(i);
        ey7[i] = MC_Rebin_Cn34_Gap07->GetBinError(i);
        x7[i] = MC_Rebin_Cn34_Gap07->GetBinCenter(i);

        y8[i] = MC_Rebin_Cn34_Gap08->GetBinContent(i);
        ey8[i] = MC_Rebin_Cn34_Gap08->GetBinError(i);
        x8[i] = MC_Rebin_Cn34_Gap08->GetBinCenter(i);

    }
    TMultiGraph *mg = new TMultiGraph();
    mg->SetTitle("Exclusion graphs");

    TGraphErrors* ge = new TGraphErrors(n, x, y, ex, ey);
    ge->SetFillColor(0);
    ge->SetFillColorAlpha(kBlue+1, .3);
    ge->SetFillStyle(3006);
    ge->SetTitle(0);
    ge->GetXaxis()->SetTitle("N_{Ch}(|#eta| < 0.8)");
    ge->GetYaxis()->SetTitle("C_{422}{3} ");
    ge->GetYaxis()->SetTitleOffset(1.6);
    ge->GetYaxis()->CenterTitle(true);
    ge->GetXaxis()->SetRangeUser(10, 90);
    ge->GetYaxis()->SetRangeUser(-0.0002, 0.0014);
    //ge->Draw("L");
    ge->Draw("a3");
       
    TGraphErrors* ge1 = new TGraphErrors(n, x1, y1, ex, ey1);
    //ge1->SetFillColor(kRed+1);
    ge1->SetFillColorAlpha(kRed+1, .3);
    ge1->SetFillStyle(3006);
    ge1->SetTitle("DPMJET, |#Delta #eta| > 0.1");
    ge1->GetYaxis()->SetTitleOffset(1.4);
    //ge1->Draw("L");
    //ge1->Draw("3same");

    TGraphErrors* ge2 = new TGraphErrors(n, x2, y2, ex, ey2);
    //ge2->SetFillColor(3);
    ge2->SetFillColorAlpha(3, .5);
    ge2->SetFillStyle(3006);
    ge2->SetTitle(0);
    //ge2->SetTitle("DPMJET, |#Delta #eta| > 0.2");
    ge2->GetXaxis()->SetTitle("N_{Ch}(|#eta| < 0.8)");
    ge2->GetYaxis()->SetTitle("C_{5}{2} ");
    ge2->GetYaxis()->CenterTitle(true);
    ge2->GetYaxis()->SetTitleOffset(1.4);
    ge2->GetXaxis()->SetRangeUser(10, 100);
    //ge2->GetYaxis()->SetRangeUser(-0.00001, 0.0002);
    //ge2->Draw("a3same");

    TGraphErrors* ge3 = new TGraphErrors(n, x3, y3, ex, ey3);
    ge3->SetFillColorAlpha(kPink+9, .5);
    ge3->SetFillStyle(3006);
    ge3->SetTitle("DPMJET, |#Delta #eta| > 0.3");
    ge3->GetYaxis()->SetTitleOffset(1.4);
    //ge3->Draw("3same");

    TGraphErrors* ge4 = new TGraphErrors(n, x4, y4, ex, ey4);
    ge4->SetFillColorAlpha(kCyan+1, .5);
    ge4->SetFillStyle(3006);
    ge4->SetTitle(0);
    //ge4->SetTitle("DPMJET, |#Delta #eta| > 0.4");
    ge4->GetXaxis()->SetTitle("N_{Ch}(|#eta| < 0.8)");
    ge4->GetYaxis()->SetTitle("C_{532}{3} ");
    ge4->GetYaxis()->CenterTitle(true);
    ge4->GetYaxis()->SetTitleOffset(1.3);
    ge4->GetXaxis()->SetRangeUser(20, 100);
    //ge4->GetYaxis()->SetRangeUser(-0.00005, 0.00008);
    //ge4->Draw("a3same");

    TGraphErrors* ge5 = new TGraphErrors(n, x5, y5, ex, ey5);
    ge5->SetFillColorAlpha(kOrange+3, .5);
    ge5->SetFillStyle(3006);
    ge5->SetTitle("DPMJET, |#Delta #eta| > 0.5");
    ge5->GetYaxis()->SetTitleOffset(1.55);
    //ge5->Draw("3same");

    TGraphErrors* ge6 = new TGraphErrors(n, x6, y6, ex, ey6);
    ge6->SetFillColorAlpha(kMagenta+2, .5);
    ge6->SetFillStyle(3006);
    ge6->SetTitle(0);
    //ge6->SetTitle("DPMJET, |#Delta #eta| > 0.6");
    ge6->GetXaxis()->SetTitle("N_{Ch}(|#eta| < 0.8)");
    ge6->GetYaxis()->SetTitle("C_{532}{3} ");
    ge6->GetYaxis()->CenterTitle(true);
    ge6->GetYaxis()->SetTitleOffset(1.3);
    ge6->GetXaxis()->SetRangeUser(15, 100);
    ge6->GetYaxis()->SetRangeUser(-0.0001, 0.00014);
    //ge6->Draw("a3same");

    TGraphErrors* ge7 = new TGraphErrors(n, x7, y7, ex, ey7);
    ge7->SetFillColorAlpha(kGreen+3, .5);
    ge7->SetFillStyle(3006);
    ge7->SetTitle("DPMJET, |#Delta #eta| > 0.7");
    ge7->GetYaxis()->SetTitleOffset(1.3);
    //ge7->Draw("3same");

    TGraphErrors* ge8 = new TGraphErrors(n, x8, y8, ex, ey8);
    ge8->SetFillColorAlpha(kYellow+1, .36);
    ge8->SetFillStyle(3006);
    ge8->SetTitle("DPMJET, |#Delta #eta| > 0.8");
    ge8->GetYaxis()->SetTitleOffset(1.3);
    ge8->Draw("3same");
    
//:=====================================================================://
////////////////////// Plot of Data: ////////////////////////////////////

    Data_Rebin_Cn34_Gap00->SetMarkerStyle(kFullCircle); 
    Data_Rebin_Cn34_Gap00->SetMarkerColor(kBlue+1);
    Data_Rebin_Cn34_Gap00->SetStats(0);
    Data_Rebin_Cn34_Gap00->Draw("Psame");
    
    // Data_Rebin_Cn34_Gap01->SetMarkerStyle(kFullCircle); 
    // Data_Rebin_Cn34_Gap01->SetMarkerColor(kRed+1);
    // Data_Rebin_Cn34_Gap01->SetLineColor(kRed+1);
    // Data_Rebin_Cn34_Gap01->Draw("Psame");
    
    // Data_Rebin_Cn34_Gap02->SetMarkerStyle(kFullCircle); 
    // Data_Rebin_Cn34_Gap02->SetMarkerColor(3);
    // Data_Rebin_Cn34_Gap02->SetLineColor(3);
    // Data_Rebin_Cn34_Gap02->Draw("Psame");
    
    // Data_Rebin_Cn34_Gap03->SetMarkerStyle(kFullSquare); 
    // Data_Rebin_Cn34_Gap03->SetMarkerColor(kPink+9);
    // Data_Rebin_Cn34_Gap03->SetLineColor(kPink+9);
    // Data_Rebin_Cn34_Gap03->Draw("Psame");
    
    // Data_Rebin_Cn34_Gap04->SetMarkerStyle(kFullDiamond); 
    // Data_Rebin_Cn34_Gap04->SetMarkerColor(kCyan+1);
    // Data_Rebin_Cn34_Gap04->SetLineColor(kCyan+1);
    // Data_Rebin_Cn34_Gap04->SetMarkerSize(2);
    // Data_Rebin_Cn34_Gap04->Draw("Psame");

    // Data_Rebin_Cn34_Gap05->SetMarkerStyle(kFullStar); 
    // Data_Rebin_Cn34_Gap05->SetMarkerColor(kOrange+3);
    // Data_Rebin_Cn34_Gap05->SetLineColor(kOrange+3);
    // Data_Rebin_Cn34_Gap05->SetMarkerSize(2);
    // Data_Rebin_Cn34_Gap05->Draw("Psame");

    // Data_Rebin_Cn34_Gap06->SetMarkerStyle(kFullCross); 
    // Data_Rebin_Cn34_Gap06->SetMarkerColor(kMagenta+2);
    // Data_Rebin_Cn34_Gap06->SetLineColor(kMagenta+2);
    // Data_Rebin_Cn34_Gap06->SetMarkerSize(2);
    // Data_Rebin_Cn34_Gap06->Draw("Psame");

    // Data_Rebin_Cn34_Gap07->SetMarkerStyle(kFullDiamond); 
    // Data_Rebin_Cn34_Gap07->SetMarkerColor(kGreen+3);
    // Data_Rebin_Cn34_Gap07->SetLineColor(kGreen+2);
    // Data_Rebin_Cn34_Gap07->SetMarkerSize(2);
    // Data_Rebin_Cn34_Gap07->Draw("Psame");
    
    Data_Rebin_Cn34_Gap08->SetMarkerStyle(kFullCircle); 
    Data_Rebin_Cn34_Gap08->SetMarkerColor(kYellow+1);
    Data_Rebin_Cn34_Gap08->SetLineColor(kYellow+1);
    Data_Rebin_Cn34_Gap08->Draw("Psame");

    //c->BuildLegend();
    
    // TLatex latex;
    // latex.SetTextSize(0.035);
    // latex.SetTextAlign(13);  //align at top
    // latex.DrawLatex(15,0.00099,"ALICE");

    // latex.SetTextSize(0.035);
    // latex.SetTextAlign(13);  //align at top
    // latex.DrawLatex(15,0.0009,"p+Pb collisions");
    
    // latex.SetTextSize(0.035);
    // latex.SetTextAlign(13);  //align at top
    // latex.DrawLatex(15,0.0008,"#sqrt{s_{NN}} = 5.02 TeV");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(15,0.0007,"|#eta| < 0.8");

    // latex.SetTextAlign(13);  //centered
    // latex.DrawLatex(15,0.0006," 0.2 < p_{T} < 3.0 GeV/c");

   //TLegend *legend = new TLegend(0.1,0.7,0.48,0.9);
   TLegend *legend = new TLegend(0.6,0.6,0.89,0.9);
   //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    legend->AddEntry(ge,"DPMJET |#Delta #eta| > 0.0", "f");
    // legend->AddEntry(ge1,"DPMJET |#Delta #eta| > 0.1", "f");
    // legend->AddEntry(ge2,"DPMJET |#Delta #eta| > 0.2","f");
    // legend->AddEntry(ge3,"DPMJET |#Delta #eta| > 0.3","f");
    // legend->AddEntry(ge4,"DPMJET |#Delta #eta| > 0.4","f");
    // legend->AddEntry(ge5,"DPMJET |#Delta #eta| > 0.5","f");
    //legend->AddEntry(ge6,"DPMJET |#Delta #eta| > 0.6","f");
    //legend->AddEntry(ge7,"DPMJET |#Delta #eta| > 0.7","f");
    legend->AddEntry(ge8,"DPMJET |#Delta #eta| > 0.8","f");
    legend->AddEntry(Data_Rebin_Cn34_Gap00,"|#Delta #eta| > 0.0","lep");
    // legend->AddEntry(Data_Rebin_Cn34_Gap01,"|#Delta #eta| > 0.1","lep");
    // legend->AddEntry(Data_Rebin_Cn34_Gap02,"|#Delta #eta| > 0.2","lep");
    // legend->AddEntry(Data_Rebin_Cn34_Gap03,"|#Delta #eta| > 0.3","lep");
    // legend->AddEntry(Data_Rebin_Cn34_Gap04,"|#Delta #eta| > 0.4","lep");
    // legend->AddEntry(Data_Rebin_Cn34_Gap05,"|#Delta #eta| > 0.5","lep");
    //legend->AddEntry(Data_Rebin_Cn34_Gap06,"|#Delta #eta| > 0.6","lep");
    //legend->AddEntry(Data_Rebin_Cn34_Gap07,"|#Delta #eta| > 0.7","lep");
    legend->AddEntry(Data_Rebin_Cn34_Gap08,"|#Delta #eta| > 0.8","lep");
    legend->Draw();

    c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_MC/Plots_MC_Data_Smallest_Largest_Eta/Range10_MC_Data_Cn34_Gap00_Gap08.png");
}