// Example displaying ratio of Rebin Chi_422 and Chi_532 Helene and You's results.
// Author: Helene Ausar
void Ratio_Rebin_Chi_422_532_You_Helene() {

    //Open root.file:
    TFile *file = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Rebin_Plots_Helene_You_Chi_422_532/Rebin_Chi_422_532_Helene.root", "READ");
    if(file) {
        //h1 = (TH1D*)file->Get("Rebin_Chi_V422_Gap00A");
        //h1 = (TH1D*)file->Get("Rebin_Chi_V422_Gap02A");
        //h1 = (TH1D*)file->Get("Rebin_Chi_V422_Gap04A");
        //h1 = (TH1D*)file->Get("Rebin_Chi_V422_Gap06A");
        //h1 = (TH1D*)file->Get("Rebin_Chi_V422_Gap08A");

        //h1 = (TH1D*)file->Get("Rebin_Chi_V532_Gap00A");
        //h1 = (TH1D*)file->Get("Rebin_Chi_V532_Gap02A");
        //h1 = (TH1D*)file->Get("Rebin_Chi_V532_Gap04A");
        //h1 = (TH1D*)file->Get("Rebin_Chi_V532_Gap06A");
        h1 = (TH1D*)file->Get("Rebin_Chi_V532_Gap08A");
    }

    //Open You's root.file:
    TFile *file2 = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Rebin_Plots_Helene_You_Chi_422_532/Rebin_Chi_422_532_You.root", "READ");
    if(file2) {
        //h2 = (TH1D*)file2->Get("Rebin_Chi_422_Gap00A"); 
        //h2 = (TH1D*)file2->Get("Rebin_Chi_422_Gap02A"); 
        //h2 = (TH1D*)file2->Get("Rebin_Chi_422_Gap04A"); 
        //h2 = (TH1D*)file2->Get("Rebin_Chi_422_Gap06A"); 
        //h2 = (TH1D*)file2->Get("Rebin_Chi_422_Gap08A"); 

        //h2 = (TH1D*)file2->Get("Rebin_Chi_532_Gap00A"); 
        //h2 = (TH1D*)file2->Get("Rebin_Chi_532_Gap02A"); 
        //h2 = (TH1D*)file2->Get("Rebin_Chi_532_Gap04A"); 
        //h2 = (TH1D*)file2->Get("Rebin_Chi_532_Gap06A"); 
        h2 = (TH1D*)file2->Get("Rebin_Chi_532_Gap08A"); 

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
   h1->SetTitle("#chi_{532} (This thesis)");
   h2->SetTitle("#chi_{532}");
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
   TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
   pad2->SetTopMargin(0);
   pad2->SetBottomMargin(0.2);
   pad2->SetGridx(); // vertical grid
   pad2->Draw();
   pad2->cd();       // pad2 becomes the current pad
    

   // Define the ratio plot
   TH1D *h3 = (TH1D*)h1->Clone("h3");
   h3->SetStats(0);      // No statistics on lower plot
   h3->Divide(h2);
   h3->SetMinimum(-35);  // Define Y ..
   h3->SetMaximum(30); // .. range
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

   // Y axis h1 plot settings
   h1->GetYaxis()->SetTitleSize(20);
   h1->GetYaxis()->SetTitleFont(43);
   h1->GetYaxis()->SetTitleOffset(1.55);

   h1->SetMinimum(-20.4);  // Define Y ..
   h1->SetMaximum(85); // .. range

   // h2 settings
   h2->SetLineColor(kRed);
   h2->SetLineWidth(2);
   h2->SetMarkerColor(kRed);
   h2->SetMarkerStyle(kOpenCross);

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

    gPad->Modified(); 
    gPad->Update(); // make sure gPad is updated 
    TLine *line = new TLine(gPad->GetUxmin(), 1, gPad->GetUxmax(), 1);
    line->SetLineStyle(9);
    line->SetLineWidth(2); 
    line->SetLineColor(kTeal+9);
    line->Draw(); 


// c->SaveAs("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/All_Rebin_Ratio_Plots_Helene_You_Plots/Rebin_Ratio_plots_Chi_532_422_HelYou/Ratio_Helene_You_Chi532_Gap08A.png");
}