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

void Rebin_3Particle_4Particle_Correlations() {
    
    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    //..Create New root.file:
    TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Cut_RawData_3particle_4particle/New_Rebin_Cut_Data_3_4_particle/New_Rebin_Cut_Data_3part_4part_histograms.root","RECREATE");
    
    //*************************************************************************
    int EtaGap[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    for(int i=0; i <9; i++) {
        TString fPath (TString::Format("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Cut_RawData_3particle_4particle/New_Cut_Data_3_4_particle/Gap0%0d_Cut_Tprofile_3_4_particle.root", EtaGap[i]));   
        
        TFile* file = TFile::Open(fPath, "READ");
        if(!file) return;

        TProfile* fTprofC34GapNtrks1bin = (TProfile*)file->Get(Form("fTprofC34Gap0%0dNtrks1bin", EtaGap[i]));
        if(!fTprofC34GapNtrks1bin) return;
        //fTprofC34GapNtrks1bin->Draw();

        TProfile* fTprofC35GapNtrks1bin = (TProfile*)file->Get(Form("fTprofC35Gap0%0dNtrks1bin", EtaGap[i]));
        if(!fTprofC35GapNtrks1bin) return;
        //fTprofC35GapNtrks1bin->Draw();

        TProfile* fTprofC42GapNtrks1bin = (TProfile*)file->Get(Form("fTprofC42Gap0%0dNtrks1bin", EtaGap[i]));
        if(!fTprofC42GapNtrks1bin) return;
        fTprofC42GapNtrks1bin->Draw();

        TProfile* fTprofC43GapNtrks1bin = (TProfile*)file->Get(Form("fTprofC43Gap0%0dNtrks1bin", EtaGap[i]));
        if(!fTprofC43GapNtrks1bin) return;
        fTprofC43GapNtrks1bin->Draw();


        TH1D* hC34_Rebin = new TH1D(Form("hC34_Rebin_Gap0%0d", EtaGap[i])," <<3>>_{4,-2,-2} 3Particle correlations", 5, 5, 105);
		hC34_Rebin->Sumw2();
        //hC34_Rebin->Draw();

        TH1D* hC35_Rebin = new TH1D(Form("hC35_Rebin_Gap0%0d", EtaGap[i])," <<3>>_{5,-3,-2} 3Particle correlations", 5, 5, 105);
		hC35_Rebin->Sumw2();
        //hC35_Rebin->Draw();


        TH1D* hC42_Rebin = new TH1D(Form("hC42_Rebin_Gap0%0d", EtaGap[i])," <<4>>_{2,2,-2,-2} 4-Particle correlations", 5, 5, 105);
		hC42_Rebin->Sumw2();
        //hC42_Rebin->Draw();

        TH1D* hC43_Rebin = new TH1D(Form("hC43_Rebin_Gap0%0d", EtaGap[i])," <<4>>_{2,3,-2,-3} 4-Particle correlations", 5, 5, 105);
		hC43_Rebin->Sumw2();
        hC43_Rebin->Draw();


        int binning = 20;
        double errorNum;
        double sumNum = 0;
        double sumDenom = 1;
        double content = 0;
        
        if(binning == 20)RebinAll(fTprofC34GapNtrks1bin, hC34_Rebin, 20);
        if(!fTprofC34GapNtrks1bin) fPrint("Warning there is no histogram");

        if(binning == 20)RebinAll(fTprofC35GapNtrks1bin, hC35_Rebin, 20);
        if(!fTprofC35GapNtrks1bin) fPrint("Warning there is no histogram");

        if(binning == 20)RebinAll(fTprofC42GapNtrks1bin, hC42_Rebin, 20);
        if(!fTprofC42GapNtrks1bin) fPrint("Warning there is no histogram");

        if(binning == 20)RebinAll(fTprofC43GapNtrks1bin, hC43_Rebin, 20);
        if(!fTprofC43GapNtrks1bin) fPrint("Warning there is no histogram");

        if(!fileOutput) return;
        fileOutput->cd();
        hC34_Rebin->Write(Form("hC34_Rebin_Gap0%0d", EtaGap[i]));
        hC35_Rebin->Write(Form("hC35_Rebin_Gap0%0d", EtaGap[i]));
        hC42_Rebin->Write(Form("hC42_Rebin_Gap0%0d", EtaGap[i]));
        hC43_Rebin->Write(Form("hC43_Rebin_Gap0%0d", EtaGap[i]));
        
        Printf("The Tprofile exist:");
        cout << "EtaGap: " << EtaGap[i] << endl;
        cout << "i : " << i << endl; 
    } //..End of loop


} // //..Define Rebin Function
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
        for(int j=1; j<101; j=j+20)
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

        for(int i=1; i<6; i++)
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

    //..Extra info om Tprofile Rebinning directly:
    // TH2D *TprofileRebin34 = fTprofC34Gap0Ntrks1bin->RebinX(10, "TprofileRebin34");
    // TprofileRebin34->Draw();


    //*************************************************************************

    // TProfile *Cn24 = (TProfile*)list->FindObject("fTprofC22Ntrks1bin");
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Ntrks1bin");  
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Ntrks1bin"); 

    // TProfile *Cn34_Gap0 = (TProfile*)list->FindObject("fTprofC34Gap0Ntrks1bin"); 
    // TProfile *Cn35_Gap0 = (TProfile*)list->FindObject("fTprofC35Gap0Ntrks1bin");
    // TProfile *Cn42_Gap0 = (TProfile*)list->FindObject("fTprofC42Gap0Ntrks1bin");  
    // TProfile *Cn43_Gap0 = (TProfile*)list->FindObject("fTprofC43Gap0Ntrks1bin");  

    // TProfile *Cn34_Gap01 = (TProfile*)list->FindObject("fTprofC34Gap01Ntrks1bin"); 
    // TProfile *Cn35_Gap01 = (TProfile*)list->FindObject("fTprofC35Gap01Ntrks1bin");
    // TProfile *Cn42_Gap01 = (TProfile*)list->FindObject("fTprofC42Gap01Ntrks1bin");  
    // TProfile *Cn43_Gap01 = (TProfile*)list->FindObject("fTprofC43Gap01Ntrks1bin");  

    // TProfile *Cn34_Gap02 = (TProfile*)list->FindObject("fTprofC34Gap02Ntrks1bin"); 
    // TProfile *Cn35_Gap02 = (TProfile*)list->FindObject("fTprofC35Gap02Ntrks1bin");
    // TProfile *Cn42_Gap02 = (TProfile*)list->FindObject("fTprofC42Gap02Ntrks1bin");  
    // TProfile *Cn43_Gap02 = (TProfile*)list->FindObject("fTprofC43Gap02Ntrks1bin");  

    // TProfile *Cn34_Gap03 = (TProfile*)list->FindObject("fTprofC34Gap03Ntrks1bin"); 
    // TProfile *Cn35_Gap03 = (TProfile*)list->FindObject("fTprofC35Gap03Ntrks1bin");
    // TProfile *Cn42_Gap03 = (TProfile*)list->FindObject("fTprofC42Gap03Ntrks1bin");  
    // TProfile *Cn43_Gap03 = (TProfile*)list->FindObject("fTprofC43Gap03Ntrks1bin");  


    // TProfile *Cn34_Gap04 = (TProfile*)list->FindObject("fTprofC34Gap04Ntrks1bin"); 
    // TProfile *Cn35_Gap04 = (TProfile*)list->FindObject("fTprofC35Gap04Ntrks1bin");
    // TProfile *Cn42_Gap04 = (TProfile*)list->FindObject("fTprofC42Gap04Ntrks1bin");  
    // TProfile *Cn43_Gap04 = (TProfile*)list->FindObject("fTprofC43Gap04Ntrks1bin");  

    // TProfile *Cn34_Gap05 = (TProfile*)list->FindObject("fTprofC34Gap05Ntrks1bin"); 
    // TProfile *Cn35_Gap05 = (TProfile*)list->FindObject("fTprofC35Gap05Ntrks1bin");
    // TProfile *Cn42_Gap05 = (TProfile*)list->FindObject("fTprofC42Gap05Ntrks1bin");  
    // TProfile *Cn43_Gap05 = (TProfile*)list->FindObject("fTprofC43Gap05Ntrks1bin");  

    // TProfile *Cn34_Gap06 = (TProfile*)list->FindObject("fTprofC34Gap06Ntrks1bin"); 
    // TProfile *Cn35_Gap06 = (TProfile*)list->FindObject("fTprofC35Gap06Ntrks1bin");
    // TProfile *Cn42_Gap06 = (TProfile*)list->FindObject("fTprofC42Gap06Ntrks1bin");  
    // TProfile *Cn43_Gap06 = (TProfile*)list->FindObject("fTprofC43Gap06Ntrks1bin");  

    // TProfile *Cn34_Gap07 = (TProfile*)list->FindObject("fTprofC34Gap07Ntrks1bin"); 
    // TProfile *Cn35_Gap07 = (TProfile*)list->FindObject("fTprofC35Gap07Ntrks1bin");
    // TProfile *Cn42_Gap07 = (TProfile*)list->FindObject("fTprofC42Gap07Ntrks1bin");  
    // TProfile *Cn43_Gap07 = (TProfile*)list->FindObject("fTprofC43Gap07Ntrks1bin");  

    // TProfile *Cn34_Gap08 = (TProfile*)list->FindObject("fTprofC34Gap08Ntrks1bin"); 
    // TProfile *Cn35_Gap08 = (TProfile*)list->FindObject("fTprofC35Gap08Ntrks1bin");
    // TProfile *Cn42_Gap08 = (TProfile*)list->FindObject("fTprofC42Gap08Ntrks1bin");  
    // TProfile *Cn43_Gap08 = (TProfile*)list->FindObject("fTprofC43Gap08Ntrks1bin");  


    // //..Rebin the Tprofile in Manual way 
    // TH1F *TprofileRebin34 = Cn34_Gap0->Rebin(10, "TprofileRebin34");
    // TprofileRebin34->Draw();

    // TH1F *TprofileRebin35 = Cn35_Gap0->Rebin(10, "TprofileRebin35");
    // TprofileRebin35->Draw();

    // TH1F *TprofileRebin42 = Cn42_Gap0->Rebin(10, "TprofileRebin42");
    // TprofileRebin42->Draw();

    // TH1F *TprofileRebin43 = Cn43_Gap0->Rebin(10, "TprofileRebin43");
    // TprofileRebin43->Draw();

    //..Save to file.root
    // TFile* fileOutput = new TFile("Rebin_Tprofile_3_4particle.root","RECREATE");
    // if(!fileOutput) return;
    // fileOutput->cd();
    // TprofileRebin34->Write();
    // TprofileRebin35->Write();
    // TprofileRebin42->Write();
    // TprofileRebin43->Write();
    //return;



    // //Cn24_Gap02->Rebin(2);
    // TH1F *hCn24_Gap02_Rebin = Cn24_Gap02->Rebin(10, "hCn24_Gap02_Rebin");
    // hCn24_Gap02_Rebin->SetAxisRange(0., 160);
    
    // TH1F *hCn42_Gap02_Rebin = Cn42_Gap02->Rebin(10, "hCn42_Gap02_Rebin");
    // hCn42_Gap02_Rebin->SetAxisRange(0., 160);

    // TH1F *hCn34_Gap02_Rebin = Cn34_Gap02->Rebin(10, "hCn34_Gap02_Rebin");
    // hCn34_Gap02_Rebin->SetAxisRange(0., 160);
    //..Plot the data 
    // Cn24->Draw();
    // Cn42->Draw();
    // Cn34->Draw();
    //Cn24_Gap02->Draw();
    // Cn42_Gap02->Draw();
    //Cn34_Gap02->Draw();
    //Cn34_Gap02->SetAxisRange(10., 100);
    //hCn34_Gap02_Rebin->Draw();
    //hCn42_Gap02_Rebin->Draw();
    //hCn34_Gap02_Rebin->Draw();


    //..old
    // hCn34_Gap02_Rebin->Write();
    // hCn42_Gap02_Rebin->Write();
    // hCn34_Gap02_Rebin->Write();
    
//}