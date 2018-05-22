// Example displaying two histograms and their ratio.
// Author: Olivier Couet
void Ratio_MC_Data() {

//******************************************************************************
//..Monte Carlo && Data Ratio:
//******************************************************************************
    //=============================================================================================
    //Open the Rebin Data:
    // TFile *file1 = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Rebin_MC_Data/Results_Rebin_Data.root","READ");
    // TH1D* h1 = (TH1D*)file1->Get("Rebin_Cn25_Gap08");
    // TH1D* h2 = (TH1D*)file1->Get("Rebin_Cn25_Gap00");

    // //Open MC data:
    TFile *file2 = TFile::Open("/Users/Helena/Desktop/Helen_simpletask/ErrorPropagations/Rebin_MC_Data/Rebin_MC.root","READ");
    TH1D* h1 = (TH1D*)file2->Get("MC_Rebin_Cn43_Gap08");//Open root.file:
    TH1D* h2 = (TH1D*)file2 ->Get("MC_Rebin_Cn43_Gap00");

//***************************************************************************
    // Define the Canvas
    TCanvas *c = new TCanvas("c", "canvas", 800, 800);
    //***********h1***************
    h1->SetStats(0);          // No statistics on upper plot
    h1->SetTitle(0);          // No Title on the upper plot
    //h1->SetMinimum(1e4);
    //h1->SetMaximum(40e6);
    h1->SetMarkerStyle(kFullCircle); 
    h1->SetMarkerColor(kBlue+1);
    h1->SetStats(0);
    h1->GetYaxis()->SetTitleOffset(1.6);
    h1->GetXaxis()->SetTitle("N_{Ch} (|#eta| < 0.8)");
    h1->GetXaxis()->SetRangeUser(20, 90); // Only for Eta 
    //h1->Draw("e1");               // Draw h1
    

    //********** h2 **************
    h2->SetMarkerStyle(kOpenSquare); 
    h2->SetMarkerColor(kRed);
    h2->SetLineColor(kRed);
    h2->SetLineWidth(2);
    h2->SetStats(0);
    h2->GetXaxis()->SetRangeUser(20, 90); // Only for Eta 
    //h2->Draw("same");         // Draw h2 on top of h1


    // // Define the ratio plot
    TH1D *h3 = (TH1D*)h1->Clone("h3");
    h3->SetLineColor(kRed);   //kBlack
    h3->SetMinimum(-70);  // Define Y ..
    h3->SetMaximum(50); // .. range
    h3->Sumw2();
    h3->SetStats(0);      // No statistics on lower plot
    h3->Divide(h2);
    h3->SetMarkerStyle(kFullCircle);
    h3->SetMarkerSize(1.5);
    h3->SetMarkerColor(kRed+1);
    h3->SetLineColor(kRed+1);
    h3->Draw("ep");       // Draw the ratio plot

    // // h1 settings:==============:
    h1->SetLineColor(kRed+1);
    h1->SetLineWidth(2);

    // // Y axis h1 plot settings
    h1->GetYaxis()->SetTitleSize(20);
    h1->GetYaxis()->SetTitleFont(43);
    //h1->GetXaxis()->SetTitle("p_{T}(GeV/c)");
    //h1->GetXaxis()->SetTitle("V_{z}(cm)");
    //h1->GetYaxis()->SetTitle("Counts");
    
    // h2 settings:==============:
    h2->SetLineColor(kRed);
    h2->SetLineWidth(2);
    //c->BuildLegend();

    // Ratio plot (h3) settings:===============
    h3->SetTitle(0); // Remove the ratio title

    // Y axis ratio plot settings:=============:
    h3->GetYaxis()->SetTitle("C_{23}{4}");
    //h3->SetTitle("; p_{T}; Efficiency");  Another way of doing that: first one is title, xaxis, yaxis
    h3->GetYaxis()->SetNdivisions(505);
    h3->GetYaxis()->SetTitleSize(20);
    h3->GetYaxis()->SetTitleFont(43);
    h3->GetYaxis()->SetTitleOffset(1.3);
    h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetYaxis()->SetLabelSize(15);

    // X axis ratio plot settings:==============:
    //h3->GetXaxis()->SetTitle("p_{T} (GeV/c)");
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
    TLegend *leg = new TLegend(0.35,0.2,0.75,0.4);  //Make a good position
    //leg->AddEntry(h1,"MC-Reco", "ep");
    //leg->AddEntry(h2,"MC-Truth", "ep");
    leg->AddEntry(h3, "#frac{MC-#Delta#eta-0.8}{MC-#Delta#eta-0.0}", "ep");
    //of MC-Reco to MC-Truth
    leg->Draw();
    //h3->Draw("ep");       // Draw the ratio plot
    // Save in Pic Folder:======================:
    // c->SaveAs("/Users/Helena/Dropbox/0-Speciale/code/panda/Sand_boks/Old/pic/Plots_MC/Ratio_Plots_MC_Data_Smallest_Largest/Ratio_MC_C43_Gap00_Gap08.png");
    }