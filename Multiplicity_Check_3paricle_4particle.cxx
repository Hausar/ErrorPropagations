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
    double BinValue_Total34wo;
    double BinValue_Total34gap0;
    double BinValue_Total34gap01;
    double BinValue_Total34gap02;
    double BinValue_Total34gap03;
    double BinValue_Total34gap04;
    double BinValue_Total34gap05;
    double BinValue_Total34gap06;
    double BinValue_Total34gap07;
    double BinValue_Total34gap08;

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
    //TProfile *Cn34wo = (TProfile*)list->FindObject("fTprofC34Ntrks1bin"); 
    // TProfile *Cn35wo = (TProfile*)list->FindObject("fTprofC35Ntrks1bin");  //..<<3>>_{5|-3,-2}
    // TProfile *Cn42wo = (TProfile*)list->FindObject("fTprofC42Ntrks1bin"); 
    // TProfile *Cn43wo = (TProfile*)list->FindObject("fTprofC43Ntrks1bin");  
    
    // //..Gap= 0.0
    TProfile *Cn3400 = (TProfile*)list->FindObject("fTprofC34Gap0Ntrks1bin"); 
    TProfile *Cn3500 = (TProfile*)list->FindObject("fTprofC35Gap0Ntrks1bin");  //..<<3>>_{5|-3,-2}
    TProfile *Cn4200 = (TProfile*)list->FindObject("fTprofC42Gap0Ntrks1bin"); 
    TProfile *Cn4300 = (TProfile*)list->FindObject("fTprofC43Gap0Ntrks1bin");

    //Cn3400->Draw();   
    TProfile* fTprofC34Gap00Ntrks1bin = (TProfile*) Cn3400->Clone("fTprofC34Gap00Ntrks1bin");
    fTprofC34Gap00Ntrks1bin->Draw();

    TProfile* fTprofC35Gap00Ntrks1bin = (TProfile*) Cn3500->Clone("fTprofC35Gap00Ntrks1bin");
    fTprofC35Gap00Ntrks1bin->Draw();

    TProfile* fTprofC42Gap00Ntrks1bin = (TProfile*) Cn4200->Clone("fTprofC42Gap00Ntrks1bin");
    fTprofC42Gap00Ntrks1bin->Draw();

    TProfile* fTprofC43Gap00Ntrks1bin = (TProfile*) Cn4300->Clone("fTprofC43Gap00Ntrks1bin");
    fTprofC43Gap00Ntrks1bin->Draw();
    

    //..Gap= 0.1
    TProfile *Cn34_01 = (TProfile*)list->FindObject("fTprofC34Gap01Ntrks1bin"); 
    TProfile *Cn35_01 = (TProfile*)list->FindObject("fTprofC35Gap01Ntrks1bin");  //..<<3>>_{5|-3,-2}
    TProfile *Cn42_01 = (TProfile*)list->FindObject("fTprofC42Gap01Ntrks1bin"); 
    TProfile *Cn43_01 = (TProfile*)list->FindObject("fTprofC43Gap01Ntrks1bin"); 

    //..Gap= 0.2
    TProfile *Cn34_02 = (TProfile*)list->FindObject("fTprofC34Gap02Ntrks1bin"); 
    TProfile *Cn35_02 = (TProfile*)list->FindObject("fTprofC35Gap02Ntrks1bin");  //..<<3>>_{5|-3,-2}
    TProfile *Cn42_02 = (TProfile*)list->FindObject("fTprofC42Gap02Ntrks1bin"); 
    TProfile *Cn43_02 = (TProfile*)list->FindObject("fTprofC43Gap02Ntrks1bin"); 

    // //..Gap= 0.3
    TProfile *Cn34_03 = (TProfile*)list->FindObject("fTprofC34Gap03Ntrks1bin"); 
    TProfile *Cn35_03 = (TProfile*)list->FindObject("fTprofC35Gap03Ntrks1bin");  //..<<3>>_{5|-3,-2}
    TProfile *Cn42_03 = (TProfile*)list->FindObject("fTprofC42Gap03Ntrks1bin"); 
    TProfile *Cn43_03 = (TProfile*)list->FindObject("fTprofC43Gap03Ntrks1bin"); 

    //..Gap= 0.4
    TProfile *Cn34_04 = (TProfile*)list->FindObject("fTprofC34Gap04Ntrks1bin"); 
    TProfile *Cn35_04 = (TProfile*)list->FindObject("fTprofC35Gap04Ntrks1bin");  //..<<3>>_{5|-3,-2}
    TProfile *Cn42_04 = (TProfile*)list->FindObject("fTprofC42Gap04Ntrks1bin"); 
    TProfile *Cn43_04 = (TProfile*)list->FindObject("fTprofC43Gap04Ntrks1bin"); 

    //..Gap= 0.5
    TProfile *Cn34_05 = (TProfile*)list->FindObject("fTprofC34Gap05Ntrks1bin"); 
    TProfile *Cn35_05 = (TProfile*)list->FindObject("fTprofC35Gap05Ntrks1bin");  //..<<3>>_{5|-3,-2}
    TProfile *Cn42_05 = (TProfile*)list->FindObject("fTprofC42Gap05Ntrks1bin"); 
    TProfile *Cn43_05 = (TProfile*)list->FindObject("fTprofC43Gap05Ntrks1bin"); 

    // //..Gap= 0.6
    TProfile *Cn34_06 = (TProfile*)list->FindObject("fTprofC34Gap06Ntrks1bin"); 
    TProfile *Cn35_06 = (TProfile*)list->FindObject("fTprofC35Gap06Ntrks1bin");  //..<<3>>_{5|-3,-2}
    TProfile *Cn42_06 = (TProfile*)list->FindObject("fTprofC42Gap06Ntrks1bin"); 
    TProfile *Cn43_06 = (TProfile*)list->FindObject("fTprofC43Gap06Ntrks1bin"); 

    // //..Gap= 0.7
    TProfile *Cn34_07 = (TProfile*)list->FindObject("fTprofC34Gap07Ntrks1bin"); 
    TProfile *Cn35_07 = (TProfile*)list->FindObject("fTprofC35Gap07Ntrks1bin");  //..<<3>>_{5|-3,-2}
    TProfile *Cn42_07 = (TProfile*)list->FindObject("fTprofC42Gap07Ntrks1bin"); 
    TProfile *Cn43_07 = (TProfile*)list->FindObject("fTprofC43Gap07Ntrks1bin"); 

    //..Gap= 0.8
    TProfile *Cn34_08 = (TProfile*)list->FindObject("fTprofC34Gap08Ntrks1bin"); 
    TProfile *Cn35_08 = (TProfile*)list->FindObject("fTprofC35Gap08Ntrks1bin");  //..<<3>>_{5|-3,-2}
    TProfile *Cn42_08 = (TProfile*)list->FindObject("fTprofC42Gap08Ntrks1bin"); 
    TProfile *Cn43_08 = (TProfile*)list->FindObject("fTprofC43Gap08Ntrks1bin"); 



    // for(int i=1; i < 201; i++) {
    //     //..Test Multiplicity
    //     // BinValue_Total22 = Cn22->GetBinEffectiveEntries(i);
    //     // BinValue_Total23 = Cn23->GetBinEffectiveEntries(i);
    //     //BinValue_Total34wo = Cn34wo->GetBinEffectiveEntries(i);
    //     //BinValue_Total34gap0 = Cn3400->GetBinEffectiveEntries(i);
    //     // BinValue_Total34gap01 = Cn34_01->GetBinEffectiveEntries(i);
    //     // BinValue_Total34gap02 = Cn34_02->GetBinEffectiveEntries(i);
    //     // BinValue_Total34gap03 = Cn34_03->GetBinEffectiveEntries(i);
    //     //BinValue_Total34gap04 = Cn34_04->GetBinEffectiveEntries(i);
    //     // BinValue_Total34gap05 = Cn34_05->GetBinEffectiveEntries(i);
    //     //BinValue_Total34gap06 = Cn34_06->GetBinEffectiveEntries(i);
    //     // BinValue_Total34gap07 = Cn34_07->GetBinEffectiveEntries(i);
    //     BinValue_Total34gap08 = Cn34_08->GetBinEffectiveEntries(i);
        
    //     // BinValue_Total35 = Cn35->GetBinEffectiveEntries(i);
    //     // BinValue_Total42 = Cn42->GetBinEffectiveEntries(i);
    //     // BinValue_Total43 = Cn43->GetBinEffectiveEntries(i);
    //     cout << "**************Start Check bin****************" << endl; 
    //     cout << "i: " << i <<endl;
    //     cout << "BinEntries: " << BinValue_Total34gap08 << endl;
    //     cout << "=============================================" << endl;

    //     if(BinValue_Total34gap08 > 1000 ) {
    //         cout << "#########################################" << endl;
    //         cout << "Yes, BinValue is Valid :) " << endl;
    //         cout << "BinValueValid: " << BinValue_Total34gap08 << endl;
    //         cout << "Bin number i: " << i << endl;
    //         cout << "##########################################" << endl;
    //     }
    //     else  {
    //         cout << "/////////////////////////////////////////////" << endl;
    //         cout << "Bin is not Valid !!!! " << BinValue_Total34gap08 << endl;
    //         cout << "Bin i is : " << i << endl;
    //         cout << "//////////////////////////////////////////////" << endl;
    //     }

        
    //     // if( BinValue_Total34wo > 1000 && BinValue_Total34gap0 > 1000 && BinValue_Total34gap01 > 1000 && BinValue_Total34gap02 > 1000 && BinValue_Total34gap03 > 1000 && BinValue_Total34gap04 > 1000 && BinValue_Total34gap05 > 1000 && BinValue_Total34gap06 > 1000 && BinValue_Total34gap07 > 1000 && BinValue_Total34gap08 > 1000  ) {
    //     //     cout << "Passed Multiplicity Test Good" << endl;
    //     //     cout << "******************************" << endl;
    //     //     cout << "i: " << i << endl;
    //     //     cout << "BinValue_Total34: " << BinValue_Total34wo << endl;
    //     //     cout <<"BinValue_Total34gap0: " << BinValue_Total34gap0 << endl;
    //     //     cout << "BinValue_Total34gap01: " << BinValue_Total34gap01 << endl;
    //     //     cout <<"BinValue_Total34gap02: " << BinValue_Total34gap02 << endl;
    //     //     cout << "BinValue_Total34gap03: " << BinValue_Total34gap03 << endl;
    //     //     cout <<"BinValue_Total34gap04: " << BinValue_Total34gap04 << endl;
    //     //     cout << "BinValue_Total34gap05: " << BinValue_Total34gap05 << endl;
    //     //     cout <<"BinValue_Total34gap06: " << BinValue_Total34gap06 << endl;
    //     //     cout << "BinValue_Total34gap07: " << BinValue_Total34gap07 << endl;
    //     //     cout <<"BinValue_Total34gap08: " << BinValue_Total34gap08 << endl;
    //     // }
    //     // else continue; 
    // }

    fTprofC34Gap00Ntrks1bin->Draw();
    fTprofC34Gap00Ntrks1bin->SetAxisRange(5, 105);

    fTprofC35Gap00Ntrks1bin->Draw();
    fTprofC35Gap00Ntrks1bin->SetAxisRange(5, 105);

    fTprofC42Gap00Ntrks1bin->Draw();
    fTprofC42Gap00Ntrks1bin->SetAxisRange(5, 105);

    fTprofC43Gap00Ntrks1bin->Draw();
    fTprofC43Gap00Ntrks1bin->SetAxisRange(5, 105);
    
    Cn34_01->Draw();
    Cn34_01->SetAxisRange(5, 105);
    Cn35_01->Draw();
    Cn35_01->SetAxisRange(5, 105);
    Cn42_01->Draw();
    Cn42_01->SetAxisRange(5, 105);
    Cn43_01->Draw();
    Cn43_01->SetAxisRange(5, 105);

    Cn34_02->Draw();
    Cn34_02->SetAxisRange(5, 105);
    Cn35_02->Draw();
    Cn35_02->SetAxisRange(5, 105);
    Cn42_02->Draw();
    Cn42_02->SetAxisRange(5, 105);
    Cn43_02->Draw();
    Cn43_02->SetAxisRange(5, 105);

    Cn34_03->Draw();
    Cn34_03->SetAxisRange(5, 105);
    Cn35_03->Draw();
    Cn35_03->SetAxisRange(5, 105);
    Cn42_03->Draw();
    Cn42_03->SetAxisRange(5, 105);
    Cn43_03->Draw();
    Cn43_03->SetAxisRange(5, 105);

    Cn34_04->Draw();
    Cn34_04->SetAxisRange(5, 105);
    Cn35_04->Draw();
    Cn35_04->SetAxisRange(5, 105);
    Cn42_04->Draw();
    Cn42_04->SetAxisRange(5, 105);
    Cn43_04->Draw();
    Cn43_04->SetAxisRange(5, 105);

    Cn34_05->Draw();
    Cn34_05->SetAxisRange(5, 105);
    Cn35_05->Draw();
    Cn35_05->SetAxisRange(5, 105);
    Cn42_05->Draw();
    Cn42_05->SetAxisRange(5, 105);
    Cn43_05->Draw();
    Cn43_05->SetAxisRange(5, 105);

    Cn34_06->Draw();
    Cn34_06->SetAxisRange(5, 105);
    Cn35_06->Draw();
    Cn35_06->SetAxisRange(5, 105);
    Cn42_06->Draw();
    Cn42_06->SetAxisRange(5, 105);
    Cn43_06->Draw();
    Cn43_06->SetAxisRange(5, 105);

    Cn34_07->Draw();
    Cn34_07->SetAxisRange(5, 105);
    Cn35_07->Draw();
    Cn35_07->SetAxisRange(5, 105);
    Cn42_07->Draw();
    Cn42_07->SetAxisRange(5, 105);
    Cn43_07->Draw();
    Cn43_07->SetAxisRange(5, 105);

    Cn34_08->Draw();
    Cn34_08->SetAxisRange(5, 105);
    Cn35_08->Draw();
    Cn35_08->SetAxisRange(5, 105);
    Cn42_08->Draw();
    Cn42_08->SetAxisRange(5, 105);
    Cn43_08->Draw();
    Cn43_08->SetAxisRange(5, 105);

    //..Save to file.root
    TFile* fileOutput = new TFile("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Cut_RawData_3particle_4particle/New_Cut_Data_3_4_particle/Gap08_Cut_Tprofile_3_4_particle.root","RECREATE");
    if(!fileOutput) return;
    fileOutput->cd();
    // fTprofC34Gap00Ntrks1bin->Write();
    // fTprofC35Gap00Ntrks1bin->Write();
    // fTprofC42Gap00Ntrks1bin->Write();
    // fTprofC43Gap00Ntrks1bin->Write();
    // Cn34_01->Write();
    // Cn35_01->Write();
    // Cn42_01->Write();
    // Cn43_01->Write();

    // Cn34_02->Write();
    // Cn35_02->Write();
    // Cn42_02->Write();
    // Cn43_02->Write();

    // Cn34_03->Write();
    // Cn35_03->Write();
    // Cn42_03->Write();
    // Cn43_03->Write();

    // Cn34_04->Write();
    // Cn35_04->Write();
    // Cn42_04->Write();
    // Cn43_04->Write();

    // Cn34_05->Write();
    // Cn35_05->Write();
    // Cn42_05->Write();
    // Cn43_05->Write();

    // Cn34_06->Write();
    // Cn35_06->Write();
    // Cn42_06->Write();
    // Cn43_06->Write();

    // Cn34_07->Write();
    // Cn35_07->Write();
    // Cn42_07->Write();
    // Cn43_07->Write();

    Cn34_08->Write();
    Cn35_08->Write();
    Cn42_08->Write();
    Cn43_08->Write();

    return;

}