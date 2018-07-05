void example_canvas_Linear() {
// example of script showing how to divide a canvas
// into adjacent subpads + axis labels on the top and right side
// of the pads.
//Author; Rene Brun

   TCanvas *c1 = new TCanvas("c1","multipads",900,700);
   gStyle->SetOptStat(0);
   c1->Divide(2,1,0,0);
   TH2F *h1 = new TH2F("h1","test1",6,20,80,20,0,0.11);
   TH2F *h2 = new TH2F("h2","test2",6,20,80,20,0,0.11);

   c1->cd(1);
   gPad->SetTickx(2);
    //..Open root.file V422:
    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Average_V422_NUA+NUE/Debug_Rebin_Average_v422_A+B.root","READ");
    TH1D* Rebin_NonLinear_V4 = (TH1D*)fileOutput->Get("Rebin_v422_Gap08_A+B");

    TFile* fileOutput1 = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Rebin_Modified_V4_Linear_A+B_NUA+NUE.root","READ");
    TH1D* Rebin_Linear_V4 = (TH1D*)fileOutput1->Get("Modified_Rebin_hCLinear_Gap08_A+B");

    TFile* fileOutput2 = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/V5_V4_{2}/Rebin_V5_V4_2particle_NUA+NUE.root","READ");
    TH1D* Rebin_Vn_V4 = (TH1D*)fileOutput2->Get("Rebin_V4_2particle_Gap08_A+B");
    h1->Draw();
    Rebin_Vn_V4->SetMarkerStyle(kFullCircle); 
    Rebin_Vn_V4->SetMarkerColor(kRed+1);
    Rebin_Vn_V4->SetLineColor(kRed+1);
    Rebin_Vn_V4->SetStats(0);
    Rebin_Vn_V4->SetTitle(0);
    Rebin_Vn_V4->GetXaxis()->SetRangeUser(20, 80);
    Rebin_Vn_V4->GetYaxis()->SetRangeUser(-0.01, 0.032);
    Rebin_Vn_V4->GetYaxis()->SetTitleOffset(0.6);
    Rebin_Vn_V4->GetYaxis()->SetTitle("v_{n}");
    //Rebin_Vn_V4->GetYaxis()->CenterTitle(true);
    Rebin_Vn_V4->GetYaxis()->SetTitleSize(0.05);
    Rebin_Vn_V4->GetXaxis()->SetTitleOffset(0.6);
    Rebin_Vn_V4->GetXaxis()->SetTitle("N_{ch}(|#eta| < 0.8)");
    Rebin_Vn_V4->GetXaxis()->CenterTitle(true);
    Rebin_Vn_V4->GetXaxis()->SetTitleSize(0.06);
    Rebin_Vn_V4->Draw("P");

    Rebin_Linear_V4->SetMarkerStyle(kFullSquare); 
    Rebin_Linear_V4->SetMarkerColor(kBlue+1);
    Rebin_Linear_V4->SetLineColor(kBlue+1);
    Rebin_Linear_V4->SetMarkerSize(1.2);
    Rebin_Linear_V4->Draw("same");
    
    Rebin_NonLinear_V4->SetMarkerStyle(kFullCross); 
    Rebin_NonLinear_V4->SetMarkerColor(kGreen+2);
    Rebin_NonLinear_V4->SetLineColor(kGreen+2);
    Rebin_NonLinear_V4->SetMarkerSize(2.);
    Rebin_NonLinear_V4->Draw("same");

    TLatex latex;
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(23,0.03,"ALICE");

    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(23,0.028,"p-Pb collisions (This Thesis)");
    
    latex.SetTextSize(0.035);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(23,0.026,"#sqrt{s_{NN}} = 5.02 TeV");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(23,0.024,"|#eta| < 0.8");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(23,0.022," 0.2 < p_{T} < 3.0 GeV/c");


    TLegend *leg = new TLegend(0.6, 0.7, 0.91, 0.99); 
    //TLegend *leg = new TLegend(0.65 , 0.2, 0.89, 0.39); 
    leg->AddEntry(Rebin_Vn_V4, "V4{2} (|#Delta#eta| > 0.8)", "lep");
    leg->AddEntry(Rebin_Linear_V4, "V_{4}^{L} (|#Delta#eta| > 0.8)", "lep");
    leg->AddEntry(Rebin_NonLinear_V4, "v_{4,22} (|#Delta#eta| > 0.8)", "lep");
    leg->Draw("same");

    //==========================================================================
   c1->cd(2);
   gPad->SetTickx(2);
   gPad->SetTicky(2);
    //..Open root.file  V532:
    TFile* fileOutput3 = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Average_V422_NUA+NUE/Debug_Rebin_Average_v532_A+B.root","READ");
    TH1D* Rebin_NonLinear = (TH1D*)fileOutput3->Get("Rebin_v532_Gap05A_A+B");
    //..Open root.file V5Linear:
    TFile* fileOutput4 = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/Rebin_Modified_V5_Linear_A+B_NUA+NUE.root","READ");
    TH1D* Rebin_Linear = (TH1D*)fileOutput4->Get("Modified_Rebin_hCLinear_Gap05A");

    TFile* fileOutput5 = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/AllGaps_Linear_NL_V4_V5/AllGaps_V422_NL_Linear_NUA+NUE/V5_V4_{2}/Rebin_V5_V4_2particle_NUA+NUE.root","READ");
    TH1D* Rebin_Vn  = (TH1D*)fileOutput5->Get("Rebin_V5_2particle_Gap05_A+B");

    Rebin_Vn->SetMarkerStyle(kFullCircle); 
    Rebin_Vn->SetMarkerColor(kRed+1);
    Rebin_Vn->SetLineColor(kRed+1);
    Rebin_Vn->SetStats(0);
    Rebin_Vn->SetTitle(0);
    Rebin_Vn->GetXaxis()->SetRangeUser(20, 80);
    Rebin_Vn->GetYaxis()->SetRangeUser(-0.01, 0.032);
    Rebin_Vn->GetYaxis()->SetTitleOffset(0.8);
    Rebin_Vn->GetYaxis()->SetTitle("v_{n}");
    Rebin_Vn->GetYaxis()->SetTitleSize(0.06);
    Rebin_Vn->GetYaxis()->CenterTitle(true);
    Rebin_Vn->GetXaxis()->SetTitleOffset(0.8);
    Rebin_Vn->GetXaxis()->SetTitle("N_{ch}(|#eta| < 0.8)");
    Rebin_Vn->GetXaxis()->SetTitleSize(0.06);
    Rebin_Vn->GetXaxis()->CenterTitle(true);
    Rebin_Vn->Draw("P");

    Rebin_Linear->SetMarkerStyle(kFullSquare); 
    Rebin_Linear->SetMarkerColor(kBlue+1);
    Rebin_Linear->SetLineColor(kBlue+1);
    Rebin_Linear->SetMarkerSize(1.2);
    Rebin_Linear->Draw("same");
    
    Rebin_NonLinear->SetMarkerStyle(kFullCross); 
    Rebin_NonLinear->SetMarkerColor(kGreen+2);
    Rebin_NonLinear->SetLineColor(kGreen+2);
    Rebin_NonLinear->SetMarkerSize(2.);
    Rebin_NonLinear->Draw("same");

    
    TLegend *leg = new TLegend(0.1, 0.7, 0.43, 0.99); 
    //TLegend *leg = new TLegend(0.65 , 0.2, 0.89, 0.39); 
    leg->AddEntry(Rebin_Vn, "V5{2} (|#Delta#eta| > 0.5)", "lep");
    leg->AddEntry(Rebin_Linear, "V_{5}^{L} (|#Delta#eta| > 0.5)", "lep");
    leg->AddEntry(Rebin_NonLinear, "v_{5,32} (|#Delta#eta| > 0.5)", "lep");
    leg->Draw("same");
    //c1->SaveAs("/Users/Helena/Dropbox/0-Speciale/DFS/Pic/Linear_V4_V5.png");

   }