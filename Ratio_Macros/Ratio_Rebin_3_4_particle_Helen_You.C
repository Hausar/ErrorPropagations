// Make Ratio plots of Rebin <<3>> and <<4>> for Helene / You:
// Author: Olivier Couet
void Ratio_Rebin_3_4_particle_Helen_You() {

      
    //Open Helene's  root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Rebin_Raw_Plots_Helene_You_3_4_part/Rebin_Raw_plots_Helene_3part_4particle.root", "READ");

    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn42_Gap00");
    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn43_Gap00");
    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn34_Gap00");
    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn35_Gap00");

    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn42_Gap02");
    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn43_Gap02");
    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn34_Gap02");
    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn35_Gap02");

    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn42_Gap04");
    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn43_Gap04");
    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn34_Gap04");
    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn35_Gap04");

    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn42_Gap06");
    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn43_Gap06");
    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn34_Gap06");
    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn35_Gap06");

    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn42_Gap08");
    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn43_Gap08");
    //TH1D *h1 = (TH1D*)file->Get("Rebin_Cn34_Gap08");
    TH1D *h1 = (TH1D*)file->Get("Rebin_Cn35_Gap08");


   
    //Open You's root.file:
    TFile *file2 = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Rebin_Raw_Plots_Helene_You_3_4_part/Rebin_Raw_plots_You_3part_4particle.root", "READ");
    if(file2) {
        //h2 = (TH1D*)file2->Get("Rebin_Cn42_Gap08"); 
        //h2 = (TH1D*)file2->Get("Rebin_Cn43_Gap08");
        //h2 = (TH1D*)file2->Get("Rebin_Cn34_Gap08");
        h2 = (TH1D*)file2->Get("Rebin_Cn35_Gap08");
    }


   // Define the Canvas
    TCanvas *c = new TCanvas("c", "canvas", 800, 800);

    // Upper plot will be in pad1
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
    pad1->SetBottomMargin(0); // Upper and lower plot are joined
    pad1->SetGridx();         // Vertical grid
    pad1->Draw();             // Draw the upper pad: pad1
    pad1->cd();               // pad1 becomes the current pad
    h1->SetStats(0);          // No statistics on upper plot
    h1->SetTitle(0);
    h1->Draw();               // Draw h1
    h2->Draw("same");         // Draw h2 on top of h1

    // Do not draw the Y axis label on the upper plot and redraw a small
    // axis instead, in order to avoid the first label (0) to be clipped.
    //h1->GetYaxis()->SetLabelSize(0.);
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
    // c->BuildLegend();

    // h1 settings
    h1->SetLineColor(kBlue+1);
    h1->SetLineWidth(2);
    h1->SetMarkerStyle(4);


    // Y axis h1 plot settings
    h1->GetYaxis()->SetTitleSize(20);
    h1->GetYaxis()->SetTitleFont(43);
    h1->GetYaxis()->SetTitleOffset(1.55);

    // h2 settings
    h2->SetLineColor(kRed);
    h2->SetLineWidth(2);
    h2->SetMarkerStyle(28);
    h2->SetTitle("");

    // Ratio plot (h3) settings
    h3->SetTitle(0); // Remove the ratio title

    // Y axis ratio plot settings
    h3->GetYaxis()->SetTitle("Ratio of <<4>>_{2222} ");
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

    //..Draw a Constant line at y=1
    gPad->Modified(); 
    gPad->Update(); // make sure gPad is updated 
    TLine *line = new TLine(gPad->GetUxmin(), 1, gPad->GetUxmax(), 1);
    line->SetLineStyle(9);
    line->SetLineWidth(2); 
    line->SetLineColor(kTeal+9);
    line->Draw(); 


    c->SaveAs("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/All_Rebin_Ratio_Plots_Helene_You_Plots/Rebin_Ratio_plots_3_4_Part_Helen_You/Ratio_Helene_You_Cn35_Gap08A_Results.png");
}