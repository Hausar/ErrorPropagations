// Example displaying two histograms and their ratio.
// Author: Olivier Couet
void Example_Ratioplots() {
   // Define two gaussian histograms. Note the X and Y title are defined
   // at booking time using the convention "Hist_title ; X_title ; Y_title"
   TH1D *h1 = new TH1D("h1", "Two gaussian plots and their ratio;x title; h1 and h2 gaussian histograms", 200, 0, 200);
   TH1D *h2 = new TH1D("h2", "h2", 200, 0, 200);
   
   
    //Open root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_Corrected_4particle.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("Flow_Refs_default");

    TProfile *Cn22_Gap08 = (TProfile*)list->FindObject("fTprofC22Gap08Ntrks1bin");
    TProfile *Cn23_Gap08 = (TProfile*)list->FindObject("fTprofC23Gap08Ntrks1bin");
    TProfile *Cn24_Gap08 = (TProfile*)list->FindObject("fTprofC24Gap08Ntrks1bin");
    TProfile *Cn25_Gap02 = (TProfile*)list->FindObject("fTprofC25Gap02Ntrks1bin");
    TProfile *Cn42_Gap00 = (TProfile*)list->FindObject("fTprofC42Gap00Ntrks1bin");  
    TProfile *Cn43_Gap00 = (TProfile*)list->FindObject("fTprofC43Gap00Ntrks1bin");  
    TProfile *Cn44_Gap00 = (TProfile*)list->FindObject("fTprofC44Gap00Ntrks1bin");  
    TProfile *Cn34_Gap08 = (TProfile*)list->FindObject("fTprofC34Gap08ANtrks1bin");
    TProfile *Cn35_Gap08 = (TProfile*)list->FindObject("fTprofC35Gap08ANtrks1bin"); 

    //h1 = Cn22_Gap08->ProjectionX();
    //h1 = Cn23_Gap08->ProjectionX();
    h1 = Cn24_Gap08->ProjectionX();
    //h1 = Cn25_Gap02->ProjectionX();
    
    
    //h1 = Cn42_Gap00->ProjectionX();
    //h1 = Cn43_Gap00->ProjectionX();
    //h1 = Cn44_Gap00->ProjectionX();
    //h1 = Cn34_Gap08->ProjectionX();
    //h1 = Cn35_Gap08->ProjectionX();
   

    //Open You's root.file:
    // TFile *file2 = TFile::Open("/Users/Helena/Desktop/Katarina_all/You_comparision/Output_Nch.root", "READ");
    // if(file2) {
    //     h2 = (TH1D*)file2->Get("fc422Gap8A"); 
    //     //h2 = (TH1D*)file2->Get("fc532Gap8A");
    //     //h2 = (TH1D*)file2->Get("fc24Gap0");
    //     //h2 = (TH1D*)file2->Get("fc3232Gap0");
    // }

    //..Katarinas results: 
    TFile *file_katka = TFile::Open("/Users/Helena/Desktop/Katarina_all/Katarina_comparison_NUA+NUE/pPb5TeV_LHC16q_CENT_wSDD.root", "READ");
    TDirectory *dir_katka = (TDirectoryFile*)file_katka->Get("default");
    TList *list_katka = (TList*)dir_katka->Get("output_default");

    TProfile *Cn22_Gap08_Katka = (TProfile*)list_katka->FindObject("fChc22Gap8Ntrks1bin");  
    TProfile *Cn23_Gap08_Katka = (TProfile*)list_katka->FindObject("fChc32Gap8Ntrks1bin");
    TProfile *Cn24_Gap08_Katka = (TProfile*)list_katka->FindObject("fChc42Gap8Ntrks1bin");
    TProfile *Cn25_Gap02_Katka = (TProfile*)list_katka->FindObject("fChc52Gap2Ntrks1bin");  
    
    TProfile *Cn42_Gap0_Katka = (TProfile*)list_katka->FindObject("fChc24Gap0Ntrks1bin");
    TProfile *Cn43_Gap0_Katka = (TProfile*)list_katka->FindObject("fChc34Gap0Ntrks1bin");
    TProfile *Cn44_Gap0_Katka = (TProfile*)list_katka->FindObject("fChc44Gap0Ntrks1bin"); 
    
    TProfile *Cn34_Gap02_Katka = (TProfile*)list_katka->FindObject("fChc422Gap2Part2Ntrks1bin");
    TProfile *Cn35_Gap02_Katka = (TProfile*)list_katka->FindObject("fChc532Gap2Part2Ntrks1bin"); 


    //h2 = Cn22_Gap08_Katka->ProjectionX();
    //h2 = Cn23_Gap08_Katka->ProjectionX();
    h2 = Cn24_Gap08_Katka->ProjectionX();
    //h2 = Cn25_Gap02_Katka->ProjectionX();


    //h2 = Cn42_Gap0_Katka->ProjectionX();
    //h2 = Cn43_Gap0_Katka->ProjectionX();
    //h2 = Cn44_Gap0_Katka->ProjectionX();
    //h2 = Cn34_Gap02_Katka->ProjectionX();
    //h2 = Cn35_Gap02_Katka->ProjectionX();
    

   //h1->FillRandom("gaus");
   //h2->FillRandom("gaus");

   // Define the Canvas
   TCanvas *c = new TCanvas("c", "canvas", 800, 800);

   // Upper plot will be in pad1
   TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
   pad1->SetBottomMargin(0); // Upper and lower plot are joined
   pad1->SetGridx();         // Vertical grid
   pad1->Draw();             // Draw the upper pad: pad1
   pad1->cd();               // pad1 becomes the current pad
   h1->SetStats(0);          // No statistics on upper plot
   h1->Draw();               // Draw h1
   h2->Draw("same");         // Draw h2 on top of h1

   // Do not draw the Y axis label on the upper plot and redraw a small
   // axis instead, in order to avoid the first label (0) to be clipped.
   h1->GetYaxis()->SetLabelSize(0.);
   TGaxis *axis = new TGaxis( -5, 20, -5, 220, 20,220,510,"");
   axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   axis->SetLabelSize(15);
   axis->Draw();

   // lower plot will be in pad
   c->cd();          // Go back to the main canvas before defining pad2
   TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
   pad2->SetTopMargin(0);
   pad2->SetBottomMargin(0.2);
   pad2->SetGridx(); // vertical grid
   pad2->Draw();
   pad2->cd();       // pad2 becomes the current pad

   // Define the ratio plot
   TH1D *h3 = (TH1D*)h1->Clone("h3");
   h3->SetLineColor(kBlack);
   h3->SetMinimum(0.3);  // Define Y ..
   h3->SetMaximum(1.65); // .. range
   h3->Sumw2();
   h3->SetStats(0);      // No statistics on lower plot
   h3->Divide(h2);
   h3->SetMarkerStyle(21);
   h3->Draw("ep");       // Draw the ratio plot

   // h1 settings
   h1->SetLineColor(kBlue+1);
   h1->SetLineWidth(2);

   // Y axis h1 plot settings
   h1->GetYaxis()->SetTitleSize(20);
   h1->GetYaxis()->SetTitleFont(43);
   h1->GetYaxis()->SetTitleOffset(1.55);

   // h2 settings
   h2->SetLineColor(kRed);
   h2->SetLineWidth(2);

   // Ratio plot (h3) settings
   h3->SetTitle(""); // Remove the ratio title

   // Y axis ratio plot settings
   h3->GetYaxis()->SetTitle("ratio h1/h2 ");
   h3->GetYaxis()->SetNdivisions(505);
   h3->GetYaxis()->SetTitleSize(20);
   h3->GetYaxis()->SetTitleFont(43);
   h3->GetYaxis()->SetTitleOffset(1.55);
   h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   h3->GetYaxis()->SetLabelSize(15);

   // X axis ratio plot settings
   h3->GetXaxis()->SetTitleSize(20);
   h3->GetXaxis()->SetTitleFont(43);
   h3->GetXaxis()->SetTitleOffset(4.);
   h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   h3->GetXaxis()->SetLabelSize(15);

//    //..Try to save all ratio plots in file.root
//     TFile* fileOutput = new TFile("/Users/Helena/Desktop/Katarina_all/Katarina_comparison_NUA+NUE/Ratio_plots_Katka_helene.root","RECREATE");
//     if(!fileOutput) return;
//     fileOutput->cd();
//     h3->Write("Ratio_plots_Helene_You_4particle_2222");

//c->SaveAs("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Ratio_Helene_Katka_2part_Gap00_08/Ratio_Helene_Katka_2part_44_Gap08_Corrected.png");
}