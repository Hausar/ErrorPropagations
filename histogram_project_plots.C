// Example displaying a 2D histogram with its two projections.
// Author: Olivier Couet

void histogram_project_plots () {

   TCanvas *c1 = new TCanvas("c1", "c1",900,900);
   //gStyle->SetOptStat(0);
   
   // Create the three pads
   TPad *center_pad = new TPad("center_pad", "center_pad",0.0,0.0,0.6,0.6);
   center_pad->Draw();

   right_pad = new TPad("right_pad", "right_pad",0.55,0.0,1.0,0.6);
   right_pad->Draw();

   top_pad = new TPad("top_pad", "top_pad",0.0,0.55,0.6,1.0);
   top_pad->Draw();


   //top_right_pad = new TPad("top_right_pad", "top_right_pad",0.55,0.6,1.0,1.0);
   //top_right_pad->Draw();


   // Create, fill and project a 2D histogram.

    TFile *file_2D = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_Corrected_4particle.root","READ"); 
    TDirectory *dir_2D = (TDirectoryFile*)file_2D->Get("default");
    TList *list_2D = (TList*)dir_2D->Get("Flow_Refs_default");

    TH2F *h2 = (TH2F*)list_2D->FindObject("fHistEtaPhi2D");
    //h2->Draw("colz");
    h2->SetStats(0);
    h2->SetTitle(0);

   TH1D * projh2X = h2->ProjectionX();
   TH1D * projh2Y = h2->ProjectionY();

   // Drawing
   center_pad->cd();
   gStyle->SetPalette(1);
   h2->Draw("COL");

   top_pad->cd();
   projh2X->SetFillColor(kBlue+1);
   projh2X->SetMinimum(0);
   projh2X->SetStats(0);
   projh2X->Draw("bar");

   right_pad->cd();
   projh2Y->SetFillColor(kBlue-2);
   projh2Y->SetStats(0);
   projh2Y->Draw("hbar");
   
   c1->cd();
   TLatex *t = new TLatex();
   t->SetTextFont(42);
   t->SetTextSize(0.02);
   t->DrawLatex(0.6,0.88,"2D-histogram and its two projections on #eta and #phi.");
   t->DrawLatex(0.6,0.85,"Non-uniform acceptance (NUA) of #phi.");

//    c1->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_NUA/2Dhistogram_EtaPhi_projection.png");

    //==========================================================================
    //..Open the 3D histogram of NUA weights:
    TFile *file_NUA = TFile::Open("/Users/Helena/Desktop/New_Weights_NUA_NUE/NUA_3D_weights_katarina/PhiWeight_LHC16q_CENT_wSDD.root", "READ");  

    TH3F *h3 = (TH3F*)file_NUA->Get("fPhiWeight_265332");
    h3->SetStats(0);
    h3->SetTitle(0);

    // TH1D * projh3X = h3->ProjectionX();
    // TH1D * projh3Y = h3->ProjectionY();
    // TH1D * projh3Z = h3->ProjectionZ();
    //======== It didnt work ==============
    // TH2D *projhXY = h3->Project3D("xy");
    // projhXY->Draw("colz");
    //======================================

    // center_pad->cd();
    // gStyle->SetPalette(1);
    // h3->SetFillColor(kCyan);
    // //h3->Draw("BOX3");

    // top_pad->cd();
    // projh3X->SetFillColor(kBlue+1);
    // //projh3X->Draw("bar");

    // right_pad->cd();
    // projh3Y->SetFillColor(kBlue-2);
    // //projh3Y->Draw("hbar");

    // top_right_pad->cd();
    // projh3Z->SetFillColor(kBlue-2);
    // //projh3Z->Draw("hbar");


    // c1->cd();
    // TLatex *t = new TLatex();
    // t->SetTextFont(42);
    // t->SetTextSize(0.02);
    // t->DrawLatex(0.6,0.88,"3D-histogram and its projections on #eta #phi and #V_z.");
    // t->DrawLatex(0.6,0.85,"Non-uniform acceptance (NUA) corrections of #phi.");
    // //c1->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_NUA/3Dhistogram_NUA_projection.png");
}