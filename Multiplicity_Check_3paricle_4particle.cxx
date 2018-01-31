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

void Multiplicity_Check_3paricle_4particle() {
    double BinValue_Total34;
    double BinValue_Total42;
    double BinValue_Sample34;
    double BinValue_Sample42;
    double BinValue_Total35;
    double BinValue_Total22;
    double BinValue_Total23;
    double BinValue_Sample35;
    double BinValue_Sample22;
    double BinValue_Sample23;


    TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 100, 8, 700, 600);
    c->SetFillColor(10);
    c->cd();

    // TH1F *Rebin_hist_C24 = new TH1F("Rebin_hist_C24", "the new Rebin plot for <<2>>_{4,-4} with #eta Gap = 0.2", 20, 0, 200);
    // Rebin_hist_C24->Sumw2();

    // TProfile *Rebinhist34 = new TProfile("Rebinhist34", "the new Rebin plot", 10, 0, 200);
    // Rebinhist34->Sumw2();

    //Open the root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/LHC16q_CENT_SDD_0Gap_2_08Gap_FullGaps.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("MyTaskResults");
    TList *list = (TList*)dir->Get("Flow_Refs_MyTaskResults");

    //..<<3>>_{5|3,2}:
    //..WO Gap
    // TProfile *Cn25 = (TProfile*)list->FindObject("fTprofC25Ntrks1bin");  //..V5{2}
    // TProfile *Cn22 = (TProfile*)list->FindObject("fTprofC22Ntrks1bin");  //..v2^{2}
    // TProfile *Cn23 = (TProfile*)list->FindObject("fTprofC23Ntrks1bin");  //..v3^{2}
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Ntrks1bin");  //..<<3>>_{5|-3,-2}

    
    // //..Gap= 0.0
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap0Ntrks1bin"); 
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap0Ntrks1bin");  //..<<3>>_{5|-3,-2}
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap0Ntrks1bin"); 
    // TProfile *Cn43 = (TProfile*)list->FindObject("fTprofC43Gap0Ntrks1bin");  
    
    // //..Gap= 0.1
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap01Ntrks1bin"); 
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap01Ntrks1bin");  //..<<3>>_{5|-3,-2}
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap01Ntrks1bin"); 
    // TProfile *Cn43 = (TProfile*)list->FindObject("fTprofC43Gap01Ntrks1bin"); 

    //..Gap= 0.2
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap02Ntrks1bin"); 
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap02Ntrks1bin");  //..<<3>>_{5|-3,-2}
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap02Ntrks1bin"); 
    // TProfile *Cn43 = (TProfile*)list->FindObject("fTprofC43Gap02Ntrks1bin"); 

    // //..Gap= 0.3
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap03Ntrks1bin"); 
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap03Ntrks1bin");  //..<<3>>_{5|-3,-2}
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap03Ntrks1bin"); 
    // TProfile *Cn43 = (TProfile*)list->FindObject("fTprofC43Gap03Ntrks1bin"); 

    //..Gap= 0.4
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap04Ntrks1bin"); 
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap04Ntrks1bin");  //..<<3>>_{5|-3,-2}
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap04Ntrks1bin"); 
    // TProfile *Cn43 = (TProfile*)list->FindObject("fTprofC43Gap04Ntrks1bin"); 

    //..Gap= 0.5
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap05Ntrks1bin"); 
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap05Ntrks1bin");  //..<<3>>_{5|-3,-2}
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap05Ntrks1bin"); 
    // TProfile *Cn43 = (TProfile*)list->FindObject("fTprofC43Gap05Ntrks1bin"); 

    // //..Gap= 0.6
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap06Ntrks1bin"); 
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap06Ntrks1bin");  //..<<3>>_{5|-3,-2}
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap06Ntrks1bin"); 
    // TProfile *Cn43 = (TProfile*)list->FindObject("fTprofC43Gap06Ntrks1bin"); 

    // //..Gap= 0.7
    TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap07Ntrks1bin"); 
    TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap07Ntrks1bin");  //..<<3>>_{5|-3,-2}
    TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap07Ntrks1bin"); 
    TProfile *Cn43 = (TProfile*)list->FindObject("fTprofC43Gap07Ntrks1bin"); 

    //..Gap= 0.8
    // TProfile *Cn34 = (TProfile*)list->FindObject("fTprofC34Gap08Ntrks1bin"); 
    // TProfile *Cn35 = (TProfile*)list->FindObject("fTprofC35Gap08Ntrks1bin");  //..<<3>>_{5|-3,-2}
    // TProfile *Cn42 = (TProfile*)list->FindObject("fTprofC42Gap08Ntrks1bin"); 
    // TProfile *Cn43 = (TProfile*)list->FindObject("fTprofC43Gap08Ntrks1bin"); 



    for(int i=1; i < 201; i++) {
        //..Test Multiplicity
        // BinValue_Total22 = Cn22->GetBinEffectiveEntries(i);
        // BinValue_Total23 = Cn23->GetBinEffectiveEntries(i);
        BinValue_Total34 = Cn34->GetBinEffectiveEntries(i);
        BinValue_Total35 = Cn35->GetBinEffectiveEntries(i);
        BinValue_Total42 = Cn42->GetBinEffectiveEntries(i);
        BinValue_Total43 = Cn43->GetBinEffectiveEntries(i);

        if( BinValue_Total34 > 1000 && BinValue_Total42 > 1000 && BinValue_Total35 > 1000 && BinValue_Total43 > 1000 ) {
            cout << "Passed Multiplicity Test Good" << endl;
            cout << "******************************" << endl;
            cout << "i: " << i << endl;
            cout << "BinValue_Total34: " << BinValue_Total34 << endl;
            cout <<"BinValue_Total35: " << BinValue_Total35 << endl;
            cout << "BinValue_Total42: " << BinValue_Total42 << endl;
            cout <<"BinValue_Total43: " << BinValue_Total43 << endl;
        }
        else continue; 
    }
    Cn34->Draw();
    Cn34->SetAxisRange(5., 104);
    Cn35->Draw();
    Cn35->SetAxisRange(5., 104);
    Cn42->Draw();
    Cn42->SetAxisRange(5., 104);
    Cn43->Draw();
    Cn43->SetAxisRange(5., 104);

    //..Save to file.root
    TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Cut_RawData_3particle_4particle/Gap07_Cut_Tprofile_3_4_particle.root","RECREATE");
    if(!fileOutput) return;
    fileOutput->cd();
    Cn34->Write();
    Cn35->Write();
    Cn42->Write();
    Cn43->Write();
    return;

}