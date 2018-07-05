// Author: Helene Ausar
void Ratio_GapA_GapB() {
    //Open root.file:
    TFile *file = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Average_V422_NUA+NUE/Debug_Rebin_Average_v422_GapAB.root", "READ");
    if(file) {
        h1 = (TH1D*)file->Get("Rebin_v422_Gap08A");
        h2 = (TH1D*)file->Get("Rebin_v422_Gap08B");
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
    h1->Draw();               // Draw h1
    //h1->SetTitle("v_{4,22}^{A} (This thesis)");
    h1->GetXaxis()->SetRangeUser(10, 90);
    //h2->SetTitle("v_{422}^{B} (This thesis)");
    h2->GetXaxis()->SetRangeUser(10, 90);
    h2->GetYaxis()->SetRangeUser(-0.04, 0.4);
    h2->Draw("same");         // Draw h2 on top of h1
    pad1->BuildLegend();

    // Do not draw the Y axis label on the upper plot and redraw a small
    // axis instead, in order to avoid the first label (0) to be clipped.
    //h1->GetYaxis()->SetLabelSize(0.);
    TGaxis *axis = new TGaxis( -5, 20, -5, 220, 20,220,510,"");
    axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    axis->SetLabelSize(15);
    axis->Draw();

    // lower plot will be in pad
    c->cd();          // Go back to the main canvas before defining pad2
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0.04, 1, 0.3);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.3);
    pad2->SetGridx(); // vertical grid
    pad2->Draw();
    pad2->cd();       // pad2 becomes the current pad


    // Define the ratio plot
    TH1D *h3 = (TH1D*)h1->Clone("h3");
    h3->SetStats(0);      // No statistics on lower plot
    h3->Divide(h2);
    h3->SetMinimum(-0.5);  // Define Y ..
    h3->SetMaximum(3); // .. range
    h3->Sumw2();
    h3->SetLineColor(kBlack);
    h3->SetMarkerColor(kBlack);
    h3->SetMarkerStyle(kOpenSquare);
    //h3->SetTitle("Ratio of #chi_{532}");
    h3->Draw("ep");       // Draw the ratio plot
    //pad2->BuildLegend();


    // h1 settings
    h1->SetLineColor(kBlue+1);
    h1->SetLineWidth(2);
    h1->SetMarkerColor(kBlue);
    h1->SetMarkerStyle(4);
    h1->SetMarkerSize(1.2);

    // Y axis h1 plot settings
    h1->GetYaxis()->SetTitleSize(20);
    h1->GetYaxis()->SetTitleFont(43);
    h1->GetYaxis()->SetTitleOffset(1.55);

    h1->SetMinimum(-0.1);  // Define Y ..
    h1->SetMaximum(0.1); // .. range

    // h2 settings
    h2->SetLineColor(kRed);
    h2->SetLineWidth(2);
    h2->SetMarkerColor(kRed);
    h2->SetMarkerStyle(kOpenCross);
    h2->SetMarkerSize(2.);

    // Ratio plot (h3) settings
    h3->SetTitle(""); // Remove the ratio title

    // Y axis ratio plot settings
    h3->GetYaxis()->SetTitle("ratio h1/h2 ");
    h3->GetYaxis()->SetNdivisions(504);
    h3->GetYaxis()->SetTitleSize(20);
    h3->GetYaxis()->SetTitleFont(43);
    h3->GetYaxis()->SetTitleOffset(1.55);
    h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetYaxis()->SetLabelSize(15);
    h3->GetYaxis()->SetRangeUser(-0.4, 1.8);

    // X axis ratio plot settings
    h3->GetXaxis()->SetTitleSize(20);
    h3->GetXaxis()->SetTitleFont(43);
    h3->GetXaxis()->SetTitleOffset(1.2);
    h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetXaxis()->SetLabelSize(15);

    gPad->Modified(); 
    gPad->Update(); // make sure gPad is updated 
    TLine *line = new TLine(gPad->GetUxmin(), 1, gPad->GetUxmax(), 1);
    line->SetLineStyle(9);
    line->SetLineWidth(2); 
    line->SetLineColor(kTeal+9);
    line->Draw(); 


c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_NonLinear_V422/Average_V422_NUA+NUE/Ratio_v422_Gap08A_Gap08B.png");
}
