///// This macro is made to Merge TProfile together:
// Author: Helene Ausar
// ROOT includes
#include <TList.h>
#include <TFile.h>
#include <TF1.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TProfile.h>


void Merge_Profiles(){
    
    TCanvas *c = new TCanvas("c","The HISTOGRAM example",100,8,700,600);
    c->SetFillColor(10);
    c->cd();

    TProfile *Merge_Profile = new TProfile("Merge_Profiles", "Merge_Profile", 200, 0, 200);
    
    //Open root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_Vertexz_new_Version.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");

    TProfile *Cn22_Gap0 = (TProfile*)list->FindObject("fTprofC22Gap0Ntrks1bin");
    TProfile *Cn23_Gap0 = (TProfile*)list->FindObject("fTprofC23Gap0Ntrks1bin");
    TProfile *Cn42_Gap0 = (TProfile*)list->FindObject("fTprofC42Gap0Ntrks1bin");  
    TProfile *Cn43_Gap0 = (TProfile*)list->FindObject("fTprofC43Gap0Ntrks1bin");  
    TProfile *Cn44_Gap0 = (TProfile*)list->FindObject("fTprofC44Gap0Ntrks1bin");  
    TProfile *Cn34_Gap0 = (TProfile*)list->FindObject("fTprofC34Gap0Ntrks1bin");
    TProfile *Cn35_Gap0 = (TProfile*)list->FindObject("fTprofC35Gap0Ntrks1bin"); 

    
    TFile *file_list = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Merge_3particle_correlations/new_list.root", "RECREATE");
    TFile *file_new = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Merge_3particle_correlations/new_file.root", "RECREATE");

    TChain ch("T");
    
    fOutputList = new TList();    
    fOutputList->Add(Cn34_Gap0);
    fOutputList->Add(Cn35_Gap0);
    fOutputList->Write("fOutputList");
    file_list->Write("fOutputList");
    ch.Merge("file_new");
    //Merge_Profile->Merge(file_list);
    //Merge_Profiles->Draw();

}

