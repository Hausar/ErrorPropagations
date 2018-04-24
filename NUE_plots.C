// Example displaying two histograms and their ratio.
// Author: Olivier Couet
void NUE_plots() {
   // Define two gaussian histograms. Note the X and Y title are defined
   // at booking time using the convention "Hist_title ; X_title ; Y_title"

   // Define the Canvas
    // TCanvas *c = new TCanvas("c","The Test HISTOGRAM ", 200, 10, 800, 700);
    // c->SetFillColor(10);
    // c->cd();


    // TFile *file_NUA = TFile::Open("/Users/Helena/Desktop/New_Weights_NUA_NUE/NUA_3D_weights_katarina/PhiWeight_LHC16q_CENT_wSDD.root", "READ");  

    // TH3F *Hist_NUA = (TH3F*)file_NUA->Get("fPhiWeight");
    // //Hist_NUA->Draw();

    // //h1 = Hist_NUA->Project3D("yx");
    // //h1->Draw("colz");


    // TFile *file_2D = TFile::Open("/Users/Helena/Desktop/bar_GF/Helene_WNUA/merging/pPb_LHC16q_NUA_NUE_Corrected_4particle.root","READ");  

    // TDirectory *dir_2D = (TDirectoryFile*)file_2D->Get("default");
    // TList *list_2D = (TList*)dir_2D->Get("Flow_Refs_default");

    // TH2F *fHistEtaPhi2D = (TH2F*)list_2D->FindObject("fHistEtaPhi2D");
    // fHistEtaPhi2D->Draw("colz");
    // fHistEtaPhi2D->SetStats(0);
    // c->SaveAs("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Ratio_NUA_2D_Weights_EtaPhi/2D_histogram_EtaPhi.png");

//******************************************************************************
//..Monte Carlo NUE Weights:
//******************************************************************************
//     //Open root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/Katarina_all/Katarina_NUE_Monte_Carlo/pPb5TeV_LHC16q_CENT_wSDD.root", "READ");
    TDirectory *dir = (TDirectoryFile*)file->Get("default");
    TList *list = (TList*)dir->Get("outputMC_default");

    TH3F *hReco = (TH3F*)list->FindObject("hReco");
    TH3F *hTruth = (TH3F*)list->FindObject("hTruth");


    //hReco->Draw();
    //hTruth->Draw();

    //..Projection on pT:
    h1 = hReco->ProjectionX("MC-Reconstructed");
    h2 = hTruth->ProjectionX("MC-Truth");

    //..Projection on eta:
    // h1 = hReco->ProjectionY("MC-Reconstructed");
    // h2 = hTruth->ProjectionY("MC-Truth");

    //..Projection on Vz:
    // h1 = hReco->ProjectionZ("MC-Reconstructed");
    // h2 = hTruth->ProjectionZ("MC-Truth");


    //h1->SetMinimum(1.e1);
    //h1->Draw();
    //h2->Draw("e same");
    //cout <<"error: " << h1->GetBinError(4) << endl;

    // Define the Canvas
    TCanvas *c = new TCanvas("c", "canvas", 800, 800);
    //c->SetLogy(1);
    // // Upper plot will be in pad1
    //TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
    //GPad->SetLogy(1);
    // //pad1->SetBottomMargin(0); // Upper and lower plot are joined
    // pad1->SetGridx();         // Vertical grid
    // pad1->Draw();             // Draw the upper pad: pad1
    // pad1->cd();               // pad1 becomes the current pad
    //h1->SetStats(0);          // No statistics on upper plot
    //h1->SetTitle(0);          // No Title on the upper plot
    //h1->SetMinimum(30e6);
    //h1->SetMaximum(90e6);
    //h1->GetXaxis()->SetRangeUser(-0.8, 0.8);
    //h1->Draw("e1");               // Draw h1
    
    //h2->GetXaxis()->SetRangeUser(-0.8, 0.8);
    //h2->SetMinimum(0.0);
    //h2->Draw("same");         // Draw h2 on top of h1
    //h1->SetTitle("MC Reconstructed / MC Truth");

    // // Do not draw the Y axis label on the upper plot and redraw a small
    // // axis instead, in order to avoid the first label (0) to be clipped.
    // //h1->GetYaxis()->SetLabelSize(0.);

    // TGaxis *axis = new TGaxis( -5, 20, -5, 220, 20,220,510,"");
    // axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    // axis->SetLabelSize(15);
    // axis->Draw();

    // // lower plot will be in pad
    // c->cd();          // Go back to the main canvas before defining pad2
    // TPad *pad2 = new TPad("pad2", "pad2", 0, 0.15, 1, 0.6);
    // pad2->SetTopMargin(0);
    // pad2->SetBottomMargin(0.2);
    // pad2->SetGridx(); // vertical grid
    // pad2->Draw();
    // pad2->cd();       // pad2 becomes the current pad

    // // Define the ratio plot
    TH1D *h3 = (TH1D*)h1->Clone("h3");
    h3->SetLineColor(kRed);   //kBlack
    h3->SetMinimum(0.0);  // Define Y ..
    h3->SetMaximum(1.65); // .. range
    h3->Sumw2();
    h3->SetStats(0);      // No statistics on lower plot
    h3->Divide(h2);
    h3->SetMarkerStyle(20);
    h3->SetMarkerColor(kMagenta+0);
    h3->Draw("ep");       // Draw the ratio plot

    // // h1 settings
    //h1->SetLineColor(kBlue+1);
    //h1->SetLineWidth(2);

    // // Y axis h1 plot settings
    //h1->GetYaxis()->SetTitleSize(20);
    //h1->GetYaxis()->SetTitleFont(43);
    //h1->GetYaxis()->SetTitleOffset(1.55);

    // // // h2 settings
    //h2->SetLineColor(kRed);
    //h2->SetLineWidth(2);
    //c->BuildLegend();

    // // Ratio plot (h3) settings
    // h3->SetTitle("Ratio of MC-Reconstructed/MC-Truth"); // Remove the ratio title

    // // // Y axis ratio plot settings
    h3->GetYaxis()->SetTitle("ratio hReco / hTruth ");
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
    //..Only for eta-distribution cut on Xaxis:
    //h3->GetXaxis()->SetRangeUser(-0.8, 0.8);

    //..Draw a Constant line at y=1
    gPad->Modified(); 
    gPad->Update(); // make sure gPad is updated 
    TLine *line = new TLine(gPad->GetUxmin(), 1, gPad->GetUxmax(), 1);
    line->SetLineStyle(9);
    line->SetLineWidth(2); 
    line->SetLineColor(kTeal+9);
    line->Draw(); 

    // c->SaveAs("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Ratio_NUE_MCReco_MCTruth/MCReco_MCTruth_Vz_ZProjection.png");
    c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/MCReco_MCTruth_divided_PtX_Projection.png");
    }