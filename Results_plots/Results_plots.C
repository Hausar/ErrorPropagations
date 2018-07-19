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

void Results_plots() 
{    
    // TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    // c->SetFillColor(10);
    // c->cd();

    // create canvas
    TCanvas *canRatio = new TCanvas("canRatio", "", 600, 450);
    // only after creating canvas, you call gPad
    
    gPad->SetBottomMargin(0.12); // increase bottom margin to have space for x-axis title                                                                  
    gPad->SetLeftMargin(0.17); // increase left margin to have space for y-axis title
    gPad->SetRightMargin(0.03); // decrease right margin because there you don't have any text (except for 2D plots)
    //============================================================================================
    //..Unit bins:
    //Open the Data root.file:
    // TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_New_Checked.root", "READ");
    // TDirectory *dir = (TDirectoryFile*)file->Get("default");
    // TList *list = (TList*)dir->Get("Flow_Refs_default");

    // TProfile *Cn24_Data0= (TProfile*)list->FindObject("fTprofC25Gap00Ntrks1bin");   //..V5{2}
    // TProfile *Cn22_Data = (TProfile*)list->FindObject("fTprofC22Gap00Ntrks1bin");   //..v2^{2}
    // TProfile *Cn23_Data = (TProfile*)list->FindObject("fTprofC23Gap00Ntrks1bin");   //..v3^{2}
    // TProfile *Cn24_Data = (TProfile*)list->FindObject("fTprofC35Gap00ANtrks1bin");  //..<<3>>_{5|-3,-2}
    // TProfile *Cn24_Data = (TProfile*)list->FindObject("fTprofC34Gap00ANtrks1bin");  //..<<3>>_{4|-2,-2}
    // TProfile *Cn24_Data = (TProfile*)list->FindObject("fTprofC42Gap00Ntrks1bin");
    // TProfile *Cn24_Data = (TProfile*)list->FindObject("fTprofC43Gap00Ntrks1bin");
    //=============================================================================================
    //..Rebin Data:
    //Open the Rebin Data root.file:
    TFile *file1 = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/Rebin_MC_Data/Results_Rebin_Data.root","READ");
    TH1D* Data_Rebin_Cn24_Gap00 = (TH1D*)file1->Get("Rebin_Cn24_Gap00");
    TH1D* Data_Rebin_Cn24_Gap01 = (TH1D*)file1->Get("Rebin_Cn24_Gap01");
    TH1D* Data_Rebin_Cn24_Gap02 = (TH1D*)file1->Get("Rebin_Cn24_Gap02");
    TH1D* Data_Rebin_Cn24_Gap03 = (TH1D*)file1->Get("Rebin_Cn24_Gap03");
    TH1D* Data_Rebin_Cn24_Gap04 = (TH1D*)file1->Get("Rebin_Cn24_Gap04");
    TH1D* Data_Rebin_Cn24_Gap05 = (TH1D*)file1->Get("Rebin_Cn24_Gap05");
    TH1D* Data_Rebin_Cn24_Gap06 = (TH1D*)file1->Get("Rebin_Cn24_Gap06");
    TH1D* Data_Rebin_Cn24_Gap07 = (TH1D*)file1->Get("Rebin_Cn24_Gap07");
    TH1D* Data_Rebin_Cn24_Gap08 = (TH1D*)file1->Get("Rebin_Cn24_Gap08");    
//:=====================================================================://
////////////////////// Plot of Data: ////////////////////////////////////

    Data_Rebin_Cn24_Gap00->SetMarkerStyle(kFullCircle); 
    Data_Rebin_Cn24_Gap00->SetMarkerColor(kBlue+1);
    Data_Rebin_Cn24_Gap00->SetStats(0);
    Data_Rebin_Cn24_Gap00->SetTitle(0);
    Data_Rebin_Cn24_Gap00->GetYaxis()->SetTitleOffset(1.6); // pushes the title of the x-axis more down
    Data_Rebin_Cn24_Gap00->GetYaxis()->SetTitleSize(0.055); // this size I usually use (or also 0.06)
    Data_Rebin_Cn24_Gap00->GetYaxis()->SetNdivisions(505); // sometimes this makes the axes look prettier, it decreases number of ticks
    Data_Rebin_Cn24_Gap00->GetYaxis()->SetLabelSize(0.055); // label size should be the same as title size for consistency
    Data_Rebin_Cn24_Gap00->GetYaxis()->SetRangeUser(-0.00022, 0.002);
    Data_Rebin_Cn24_Gap00->GetXaxis()->SetTitleOffset(1.0); // pushes the title of the x-axis more down
    Data_Rebin_Cn24_Gap00->GetXaxis()->SetTitleSize(0.055); // this size I usually use (or also 0.06)
    Data_Rebin_Cn24_Gap00->GetXaxis()->SetNdivisions(505); // sometimes this makes the axes look prettier, it decreases number of ticks
    Data_Rebin_Cn24_Gap00->GetXaxis()->SetLabelSize(0.055); // label size should be the same as title size for consistency
    Data_Rebin_Cn24_Gap00->GetXaxis()->SetRangeUser(20, 90);
    Data_Rebin_Cn24_Gap00->GetXaxis()->SetTitle("N_{ch}(|#eta| < 0.8)");
    //ge->GetYaxis()->CenterTitle(true);
    Data_Rebin_Cn24_Gap00->GetYaxis()->SetTitle("<<2>>_{4|-4}");
    Data_Rebin_Cn24_Gap00->Draw("Psame");
    // Data_Rebin_Cn24_Gap01->SetMarkerStyle(kFullCircle); 
    // Data_Rebin_Cn24_Gap01->SetMarkerColor(kRed+1);
    // Data_Rebin_Cn24_Gap01->SetLineColor(kRed+1);
    // Data_Rebin_Cn24_Gap01->Draw("Psame");
    
    // Data_Rebin_Cn24_Gap02->SetMarkerStyle(kFullCircle); 
    // Data_Rebin_Cn24_Gap02->SetMarkerColor(3);
    // Data_Rebin_Cn24_Gap02->SetLineColor(3);
    // Data_Rebin_Cn24_Gap02->Draw("Psame");
    
    // Data_Rebin_Cn24_Gap03->SetMarkerStyle(kFullSquare); 
    // Data_Rebin_Cn24_Gap03->SetMarkerColor(kPink+9);
    // Data_Rebin_Cn24_Gap03->SetLineColor(kPink+9);
    // Data_Rebin_Cn24_Gap03->Draw("Psame");
    
    // Data_Rebin_Cn24_Gap04->SetMarkerStyle(kFullDiamond); 
    // Data_Rebin_Cn24_Gap04->SetMarkerColor(kCyan+1);
    // Data_Rebin_Cn24_Gap04->SetLineColor(kCyan+1);
    // Data_Rebin_Cn24_Gap04->SetMarkerSize(2);
    // Data_Rebin_Cn24_Gap04->Draw("Psame");

    // Data_Rebin_Cn24_Gap05->SetMarkerStyle(kFullStar); 
    // Data_Rebin_Cn24_Gap05->SetMarkerColor(kOrange+3);
    // Data_Rebin_Cn24_Gap05->SetLineColor(kOrange+3);
    // Data_Rebin_Cn24_Gap05->SetMarkerSize(2);
    // Data_Rebin_Cn24_Gap05->Draw("Psame");

    // Data_Rebin_Cn24_Gap06->SetMarkerStyle(kFullCross); 
    // Data_Rebin_Cn24_Gap06->SetMarkerColor(kMagenta+2);
    // Data_Rebin_Cn24_Gap06->SetLineColor(kMagenta+2);
    // Data_Rebin_Cn24_Gap06->SetMarkerSize(2);
    // Data_Rebin_Cn24_Gap06->Draw("Psame");

    // Data_Rebin_Cn24_Gap07->SetMarkerStyle(kFullDiamond); 
    // Data_Rebin_Cn24_Gap07->SetMarkerColor(kGreen+3);
    // Data_Rebin_Cn24_Gap07->SetLineColor(kGreen+2);
    // Data_Rebin_Cn24_Gap07->SetMarkerSize(2);
    // Data_Rebin_Cn24_Gap07->Draw("Psame");
    
    Data_Rebin_Cn24_Gap08->SetMarkerStyle(kFullCircle); 
    Data_Rebin_Cn24_Gap08->SetMarkerColor(kYellow+3);
    Data_Rebin_Cn24_Gap08->SetLineColor(kYellow+3);
    Data_Rebin_Cn24_Gap08->GetYaxis()->SetTitleOffset(1.4); // pushes the title of the x-axis more down
    Data_Rebin_Cn24_Gap08->GetYaxis()->SetTitleSize(0.055); // this size I usually use (or also 0.06)
    Data_Rebin_Cn24_Gap08->GetYaxis()->SetNdivisions(505); // sometimes this makes the axes look prettier, it decreases number of ticks
    Data_Rebin_Cn24_Gap08->GetYaxis()->SetLabelSize(0.055); // label size should be the same as title size for consistency
    //c->BuildLegend();
    Data_Rebin_Cn24_Gap08->GetYaxis()->SetRangeUser(0, 0.0001);
    Data_Rebin_Cn24_Gap08->GetXaxis()->SetTitleOffset(1.4); // pushes the title of the x-axis more down
    Data_Rebin_Cn24_Gap08->GetXaxis()->SetTitleSize(0.055); // this size I usually use (or also 0.06)
    Data_Rebin_Cn24_Gap08->GetXaxis()->SetLabelSize(0.055); // label size should be the same as title size for consistency
    Data_Rebin_Cn24_Gap08->GetXaxis()->SetNdivisions(505); // sometimes this makes the axes look prettier, it decreases number of ticks
    Data_Rebin_Cn24_Gap08->GetXaxis()->SetRangeUser(20, 90);
    Data_Rebin_Cn24_Gap08->Draw("Psame");
    
    TLatex latex;
    latex.SetTextSize(0.05);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,0.0019,"ALICE");

    latex.SetTextSize(0.045);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,0.0017,"p-Pb collisions");
    
    latex.SetTextSize(0.045);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(25,0.0015,"#sqrt{s_{NN}} = 5.02 TeV");

    latex.SetTextSize(0.045);
    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(25,0.0013,"|#eta| < 0.8");

    latex.SetTextSize(0.045);
    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(25,0.0011," 0.2 < p_{T} < 3.0 GeV/c");

    latex.SetTextSize(0.045);
    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(40,0.0019,"(This thesis)");
   
   //TLegend *legend = new TLegend(0.6,0.2,0.89,0.5);
   TLegend *legend = new TLegend(0.6,0.6,0.89,0.88);
   legend->SetBorderSize(-1);
   //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    legend->AddEntry(Data_Rebin_Cn24_Gap00,"|#Delta #eta| > 0.0","lep");
    // legend->AddEntry(Data_Rebin_Cn24_Gap01,"|#Delta #eta| > 0.1","lep");
    // legend->AddEntry(Data_Rebin_Cn24_Gap02,"|#Delta #eta| > 0.2","lep");
    // legend->AddEntry(Data_Rebin_Cn24_Gap03,"|#Delta #eta| > 0.3","lep");
    // legend->AddEntry(Data_Rebin_Cn24_Gap04,"|#Delta #eta| > 0.4","lep");
    // legend->AddEntry(Data_Rebin_Cn24_Gap05,"|#Delta #eta| > 0.5","lep");
    //legend->AddEntry(Data_Rebin_Cn24_Gap06,"|#Delta #eta| > 0.6","lep");
    //legend->AddEntry(Data_Rebin_Cn24_Gap07,"|#Delta #eta| > 0.7","lep");
    legend->AddEntry(Data_Rebin_Cn24_Gap08,"|#Delta #eta| > 0.8","lep");
    legend->Draw();

    // canRatio->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_MC/Plots_Data_Thesis/Data_Cn24_Gap00_Gap08_nr2.pdf");
}
