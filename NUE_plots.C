// Example displaying two histograms and their ratio.
// Author: Olivier Couet
void NUE_plots() {

    //=========================================================================
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
    //==========================================================================
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
    h1 = hReco->ProjectionX("MC-Reco");
    h2 = hTruth->ProjectionX("MC-Truth");

    //..Projection on eta:
    // h1 = hReco->ProjectionY("MC-Reco");
    // h2 = hTruth->ProjectionY("MC-Truth");

    //..Projection on Vz:
    // h1 = hReco->ProjectionZ("MC-Reconstructed");
    // h2 = hTruth->ProjectionZ("MC-Truth");

//***************************************************************************
    // Define the Canvas
    TCanvas *c = new TCanvas("c", "canvas", 800, 800);
    //***********h1***************
    h1->SetStats(0);          // No statistics on upper plot
    h1->SetTitle(0);          // No Title on the upper plot
    h1->SetMinimum(1e4);
    h1->SetMaximum(40e6);
    h1->SetMarkerStyle(kFullCircle); 
    h1->SetMarkerColor(kBlue+1);
    h1->SetStats(0);
    h1->GetYaxis()->SetTitleOffset(1.6);
    //h1->GetXaxis()->SetRangeUser(-0.8, 0.8); // Only for Eta 
    //h1->Draw("e1");               // Draw h1
    

    //********** h2 **************
    h2->SetMarkerStyle(kOpenSquare); 
    h2->SetMarkerColor(kRed);
    h2->SetLineColor(kRed);
    h2->SetLineWidth(2);
    h2->SetStats(0);
    //h2->Draw("same");         // Draw h2 on top of h1


    // // Define the ratio plot
    TH1D *h3 = (TH1D*)h1->Clone("h3");
    h3->SetLineColor(kRed);   //kBlack
    h3->SetMinimum(0.0);  // Define Y ..
    h3->SetMaximum(2.); // .. range
    h3->Sumw2();
    h3->SetStats(0);      // No statistics on lower plot
    h3->Divide(h2);
    h3->SetMarkerStyle(kOpenDiamond);
    h3->SetMarkerSize(2);
    h3->SetMarkerColor(kMagenta+1);
    h3->SetLineColor(kMagenta+1);
    h3->Draw("ep");       // Draw the ratio plot

    // // h1 settings:==============:
    h1->SetLineColor(kBlue+1);
    h1->SetLineWidth(2);

    // // Y axis h1 plot settings
    h1->GetYaxis()->SetTitleSize(20);
    h1->GetYaxis()->SetTitleFont(43);
    //h1->GetXaxis()->SetTitle("p_{T}(GeV/c)");
    h1->GetXaxis()->SetTitle("#eta");
    //h1->GetXaxis()->SetTitle("V_{z}(cm)");
    //h1->GetYaxis()->SetTitle("Counts");
    
    // h2 settings:==============:
    h2->SetLineColor(kRed);
    h2->SetLineWidth(2);
    //c->BuildLegend();

    // Ratio plot (h3) settings:===============
    h3->SetTitle(0); // Remove the ratio title

    // Y axis ratio plot settings:=============:
    h3->GetYaxis()->SetTitle("Efficiency");
    //h3->SetTitle("; p_{T}; Efficiency");  Another way of doing that: first one is title, xaxis, yaxis
    h3->GetYaxis()->SetNdivisions(505);
    h3->GetYaxis()->SetTitleSize(20);
    h3->GetYaxis()->SetTitleFont(43);
    h3->GetYaxis()->SetTitleOffset(1.3);
    h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetYaxis()->SetLabelSize(15);

    // X axis ratio plot settings:==============:
    h3->GetXaxis()->SetTitle("p_{T} (GeV/c)");
    //h3->GetXaxis()->SetTitle("#eta");
    //h3->GetXaxis()->SetTitle("V_{z}(cm)");
    h3->GetXaxis()->SetTitleSize(20);
    h3->GetXaxis()->SetTitleFont(43);
    h3->GetXaxis()->SetTitleOffset(1.3);
    h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetXaxis()->SetLabelSize(15);
    //..Only for eta-distribution cut on Xaxis:==========:
    //h3->GetXaxis()->SetRangeUser(-0.8, 0.8);

    //..Draw a Constant line at y=1:============:
    gPad->Modified(); 
    gPad->Update(); // make sure gPad is updated 
    TLine *line = new TLine(gPad->GetUxmin(), 1, gPad->GetUxmax(), 1);
    line->SetLineStyle(9);
    line->SetLineWidth(2); 
    line->SetLineColor(kBlack);
    line->Draw(); 
    
    //x1, y1, x2, y2
    //TLegend *leg = new TLegend(0.56,0.75,0.89,0.9);
    TLegend *leg = new TLegend(0.36,0.6,0.75,0.8);  //Make a good position
    //leg->AddEntry(h1,"MC-Reco", "ep");
    //leg->AddEntry(h2,"MC-Truth", "ep");
    leg->AddEntry(h3, "#frac{MC-Reco}{MC-Truth}", "ep");
    //of MC-Reco to MC-Truth
    leg->Draw();
    //h3->Draw("ep");       // Draw the ratio plot
    // Save in Pic Folder:======================:
    c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_NUE/Ratio_MCReco_MCTruth_pTX_Projection.png");
    }