void Alice_template_rho_chi_plot() {
// example of script showing how to divide a canvas
// into adjacent subpads + axis labels on the top and right side
// of the pads.
//Author; Rene Brun

   TCanvas *c1 = new TCanvas("c1","multipads",900,700);
   gStyle->SetOptStat(0);
   c1->Divide(2,2,0,0);
  //  TH2F *h1 = new TH2F("h1","test1",6,20,80,20,0,0.11);
  //  TH2F *h2 = new TH2F("h2","test2",6,20,80,20,0,0.11);
  //  TH2F *h3 = new TH2F("h3","test3",6,20,80,20,-1,1);
  //  TH2F *h4 = new TH2F("h4","test4",6,20,80,20,0,1000);

   c1->cd(1);
   gPad->SetTickx(2);
    //..Open root.file V422:
     TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Rebin_Plots_Helene_You_Chi_422_532/Rebin_Chi_422_532_Helene_10Length.root","READ");

    TH1D* Rebin_Chi_V422_Gap00A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap00A");
    TH1D* Rebin_Chi_V422_Gap01A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap01A");
    TH1D* Rebin_Chi_V422_Gap02A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap02A");
    TH1D* Rebin_Chi_V422_Gap03A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap03A");
    TH1D* Rebin_Chi_V422_Gap04A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap04A");
    TH1D* Rebin_Chi_V422_Gap05A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap05A");
    TH1D* Rebin_Chi_V422_Gap06A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap06A");
    TH1D* Rebin_Chi_V422_Gap07A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap07A");
    TH1D* Rebin_Chi_V422_Gap08A = (TH1D*)fileOutput->Get("Rebin_Chi_V422_Gap08A");

    // Rebin_Chi_V422_Gap00A->SetMarkerStyle(kFullCircle); 
    // Rebin_Chi_V422_Gap00A->SetMarkerColor(kBlue+1);
    // Rebin_Chi_V422_Gap00A->SetLineColor(kBlue+1);
    // Rebin_Chi_V422_Gap00A->SetStats(0);
    // Rebin_Chi_V422_Gap00A->SetTitle(0);
    // Rebin_Chi_V422_Gap00A->GetXaxis()->SetRangeUser(20, 70);
    // Rebin_Chi_V422_Gap00A->GetYaxis()->SetRangeUser(-2, 4.5);
    // Rebin_Chi_V422_Gap00A->GetYaxis()->SetTitleOffset(1.2);
    // Rebin_Chi_V422_Gap00A->GetYaxis()->SetTitle("#chi_{4,22}");
    // Rebin_Chi_V422_Gap00A->GetYaxis()->CenterTitle(true);
    // Rebin_Chi_V422_Gap00A->GetXaxis()->SetTitle("N_{ch}(|#Delta#eta| < 0.8)");
    // Rebin_Chi_V422_Gap00A->GetXaxis()->SetLabelSize(.05);
    // Rebin_Chi_V422_Gap00A->GetXaxis()->CenterTitle(true);
    // Rebin_Chi_V422_Gap00A->GetXaxis()->SetTitleOffset(1.4);
    Rebin_Chi_V422_Gap00A->Draw("P");

    // Rebin_Chi_V422_Gap01A->SetMarkerStyle(kFullTriangleUp); 
    // Rebin_Chi_V422_Gap01A->SetMarkerColor(kRed+1);
    // Rebin_Chi_V422_Gap01A->SetLineColor(kRed+1);
    // Rebin_Chi_V422_Gap01A->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_Chi_V422_Gap01A->SetTitle("|#Delta #eta |> 0.1 A");
    Rebin_Chi_V422_Gap01A->Draw("same");

    // Rebin_Chi_V422_Gap02A->SetMarkerStyle(kCircle); 
    // Rebin_Chi_V422_Gap02A->SetMarkerColor(kSpring);
    // Rebin_Chi_V422_Gap02A->SetLineColor(kSpring+1);
    // Rebin_Chi_V422_Gap02A->SetStats(0);
    // Rebin_Chi_V422_Gap01A->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_Chi_V422_Gap02A->SetTitle("|#Delta #eta |> 0.2 A");
    Rebin_Chi_V422_Gap02A->Draw("same");

    // Rebin_Chi_V422_Gap03A->SetMarkerStyle(kFullSquare); 
    // Rebin_Chi_V422_Gap03A->SetMarkerColor(kGreen+3);
    // Rebin_Chi_V422_Gap03A->SetLineColor(kGreen+3);
    // Rebin_Chi_V422_Gap03A->SetStats(0);
    // Rebin_Chi_V422_Gap03A->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_Chi_V422_Gap03A->SetTitle("|#Delta #eta |> 0.3 A");
    // Rebin_Chi_V422_Gap03A->Draw("same");

    // Rebin_Chi_V422_Gap04A->SetMarkerStyle(kFullDiamond); 
    // Rebin_Chi_V422_Gap04A->SetMarkerColor(kBlack);
    // Rebin_Chi_V422_Gap04A->SetLineColor(kBlack);
    // Rebin_Chi_V422_Gap04A->SetMarkerSize(2);
    // Rebin_Chi_V422_Gap04A->SetStats(0);
    // Rebin_Chi_V422_Gap04A->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_Chi_V422_Gap04A->SetTitle("|#Delta #eta |> 0.4 A");
    // Rebin_Chi_V422_Gap04A->Draw("same");

    // Rebin_Chi_V422_Gap05A->SetMarkerStyle(kFullStar); 
    // Rebin_Chi_V422_Gap05A->SetMarkerColor(kOrange);
    // Rebin_Chi_V422_Gap05A->SetLineColor(kOrange);
    // Rebin_Chi_V422_Gap05A->SetMarkerSize(2);
    // Rebin_Chi_V422_Gap05A->SetStats(0);
    // Rebin_Chi_V422_Gap05A->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_Chi_V422_Gap05A->SetTitle("|#Delta #eta |> 0.5 A");
    // Rebin_Chi_V422_Gap05A->Draw("same");

    // Rebin_Chi_V422_Gap06A->SetMarkerStyle(kFullCross); 
    // Rebin_Chi_V422_Gap06A->SetMarkerColor(kBlue-9);
    // Rebin_Chi_V422_Gap06A->SetLineColor(kBlue-9);
    // Rebin_Chi_V422_Gap06A->SetMarkerSize(2);
    // Rebin_Chi_V422_Gap06A->SetStats(0);
    // Rebin_Chi_V422_Gap06A->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_Chi_V422_Gap06A->SetTitle("|#Delta #eta |> 0.6 A");
    // Rebin_Chi_V422_Gap06A->Draw("same");

    // Rebin_Chi_V422_Gap07A->SetMarkerStyle(kFullDiamond); 
    // Rebin_Chi_V422_Gap07A->SetMarkerColor(kTeal-2);
    // Rebin_Chi_V422_Gap07A->SetLineColor(kTeal-2);
    // Rebin_Chi_V422_Gap07A->SetMarkerSize(2);
    // Rebin_Chi_V422_Gap07A->SetStats(0);
    // Rebin_Chi_V422_Gap07A->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_Chi_V422_Gap07A->SetTitle("|#Delta #eta |> 0.7 A");
    // Rebin_Chi_V422_Gap07A->Draw("same");

    // Rebin_Chi_V422_Gap08A->SetMarkerStyle(kFullCircle); 
    // Rebin_Chi_V422_Gap08A->SetMarkerColor(kMagenta);
    // Rebin_Chi_V422_Gap08A->SetLineColor(kMagenta);
    // //Rebin_Chi_V422_Gap08A->SetMarkerSize(1);
    // Rebin_Chi_V422_Gap08A->SetStats(0);
    // Rebin_Chi_V422_Gap08A->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_Chi_V422_Gap08A->SetTitle("|#Delta #eta |> 0.8 A");
    // Rebin_Chi_V422_Gap08A->Draw("same");

    //..Draw a Constant line at y=1
    gPad->Modified(); 
    gPad->Update(); // make sure gPad is updated 
    TLine *line = new TLine(gPad->GetUxmin(), 1, gPad->GetUxmax(), 1);
    line->SetLineStyle(9);
    line->SetLineWidth(2); 
    line->SetLineColor(kBlack);
    line->Draw(); 

    TLatex latex;
    latex.SetTextSize(0.055);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(23,3.9,"ALICE");

    latex.SetTextSize(0.045);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(23,3.6,"p-Pb collisions (This Thesis)");
    
    latex.SetTextSize(0.045);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(53,3.8,"#sqrt{s_{NN}} = 5.02 TeV");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(53,3.5,"|#eta| < 0.8");

    latex.SetTextAlign(13);  //centered
    latex.DrawLatex(53,3.2," 0.2 < p_{T} < 3.0 GeV/c");

    TLegend *leg = new TLegend(0.18 , 0.6, 0.33, 0.99); 
    //TLegend *leg = new TLegend(0.65 , 0.2, 0.89, 0.39); 
    leg->AddEntry(Rebin_Chi_V422_Gap00A, "|#Delta#eta| > 0.0", "lep");
    leg->AddEntry(Rebin_Chi_V422_Gap00A, "|#Delta#eta| > 0.1", "lep");
    leg->AddEntry(Rebin_Chi_V422_Gap02A, "|#Delta#eta| > 0.2", "lep");
    // leg->AddEntry(Rebin_Chi_V422_Gap03A, "|#Delta#eta| > 0.3", "lep");
    // leg->AddEntry(Rebin_Chi_V422_Gap04A, "|#Delta#eta| > 0.4", "lep");
    // leg->AddEntry(Rebin_Chi_V422_Gap05A, "|#Delta#eta| > 0.5", "lep");
    // leg->AddEntry(Rebin_Chi_V422_Gap06A, "|#Delta#eta| > 0.6", "lep");
    // leg->AddEntry(Rebin_Chi_V422_Gap07A, "|#Delta#eta| > 0.7", "lep");
    // leg->AddEntry(Rebin_Chi_V422_Gap08A, "|#Delta#eta| > 0.8", "lep");
    leg->Draw("same");

    //==========================================================================
   c1->cd(2);
   gPad->SetTickx(2);
   gPad->SetTicky(2);
    //..Open root.file  V532:
        //..Open root.file V422:
    //  TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Rebin_Plots_Helene_You_Chi_422_532/Rebin_Chi_422_532_Helene_10Length.root","READ");

    TH1D* Rebin_Chi_V532_Gap00A = (TH1D*)fileOutput->Get("Rebin_Chi_V532_Gap00A");
    TH1D* Rebin_Chi_V532_Gap01A = (TH1D*)fileOutput->Get("Rebin_Chi_V532_Gap01A");
    TH1D* Rebin_Chi_V532_Gap02A = (TH1D*)fileOutput->Get("Rebin_Chi_V532_Gap02A");
    TH1D* Rebin_Chi_V532_Gap03A = (TH1D*)fileOutput->Get("Rebin_Chi_V532_Gap03A");
    TH1D* Rebin_Chi_V532_Gap04A = (TH1D*)fileOutput->Get("Rebin_Chi_V532_Gap04A");
    TH1D* Rebin_Chi_V532_Gap05A = (TH1D*)fileOutput->Get("Rebin_Chi_V532_Gap05A");
    TH1D* Rebin_Chi_V532_Gap06A = (TH1D*)fileOutput->Get("Rebin_Chi_V532_Gap06A");
    TH1D* Rebin_Chi_V532_Gap07A = (TH1D*)fileOutput->Get("Rebin_Chi_V532_Gap07A");
    TH1D* Rebin_Chi_V532_Gap08A = (TH1D*)fileOutput->Get("Rebin_Chi_V532_Gap08A");

//     Rebin_Chi_V532_Gap00A->SetMarkerStyle(kFullCircle); 
//     Rebin_Chi_V532_Gap00A->SetMarkerColor(kBlue+1);
//     Rebin_Chi_V532_Gap00A->SetLineColor(kBlue+1);
//     Rebin_Chi_V532_Gap00A->SetStats(0);
//     Rebin_Chi_V532_Gap00A->SetTitle(0);
//     Rebin_Chi_V532_Gap00A->GetXaxis()->SetRangeUser(20, 70);
    Rebin_Chi_V532_Gap00A->Draw("P");
//     Rebin_Chi_V532_Gap00A->GetYaxis()->SetRangeUser(-2, 4.5);
//     Rebin_Chi_V532_Gap00A->GetYaxis()->SetTitleOffset(1.3);
//     //Rebin_Chi_V532_Gap00A->GetYaxis()->SetTitleSize(0.1);
//     //Rebin_Chi_V532_Gap00A->GetYaxis()->CenterTitle(true);
//     Rebin_Chi_V532_Gap00A->GetYaxis()->SetTitle("#chi_{5,32}");
//     Rebin_Chi_V532_Gap00A->GetXaxis()->CenterTitle(true);
//     Rebin_Chi_V532_Gap00A->GetXaxis()->SetTitle("N_{ch}(|#Delta#eta| < 0.8)");
//     Rebin_Chi_V532_Gap00A->GetXaxis()->SetTitleOffset(1.4);

//     Rebin_Chi_V532_Gap01A->SetMarkerStyle(kFullTriangleUp); 
//     Rebin_Chi_V532_Gap01A->SetMarkerColor(kRed+1);
//     Rebin_Chi_V532_Gap01A->SetLineColor(kRed+1);
    Rebin_Chi_V532_Gap01A->Draw("same");

//     Rebin_Chi_V532_Gap02A->SetMarkerStyle(kFullCircle); 
//     Rebin_Chi_V532_Gap02A->SetMarkerColor(kSpring);
//     Rebin_Chi_V532_Gap02A->SetLineColor(kSpring+1);
//     Rebin_Chi_V532_Gap02A->SetStats(0);
//     Rebin_Chi_V532_Gap01A->GetXaxis()->SetRangeUser(10, 90);
    Rebin_Chi_V532_Gap02A->Draw("same");

//     Rebin_Chi_V532_Gap03A->SetMarkerStyle(kFullSquare); 
//     Rebin_Chi_V532_Gap03A->SetMarkerColor(kGreen+3);
//     Rebin_Chi_V532_Gap03A->SetLineColor(kGreen+3);
//     Rebin_Chi_V532_Gap03A->SetStats(0);
//     Rebin_Chi_V532_Gap03A->Draw("same");

//     Rebin_Chi_V532_Gap04A->SetMarkerStyle(kFullDiamond); 
//     Rebin_Chi_V532_Gap04A->SetMarkerColor(kBlack);
//     Rebin_Chi_V532_Gap04A->SetLineColor(kBlack);
//     Rebin_Chi_V532_Gap04A->SetMarkerSize(2);
//     Rebin_Chi_V532_Gap04A->SetStats(0);
//     Rebin_Chi_V532_Gap04A->Draw("same");

//     Rebin_Chi_V532_Gap05A->SetMarkerStyle(kFullStar); 
//     Rebin_Chi_V532_Gap05A->SetMarkerColor(kOrange);
//     Rebin_Chi_V532_Gap05A->SetLineColor(kOrange);
//     Rebin_Chi_V532_Gap05A->SetMarkerSize(2);
//     Rebin_Chi_V532_Gap05A->SetStats(0);
//     Rebin_Chi_V532_Gap05A->Draw("same");

//     // Rebin_Chi_V532_Gap06A->SetMarkerStyle(kFullCross); 
//     // Rebin_Chi_V532_Gap06A->SetMarkerColor(kBlue-9);
//     // Rebin_Chi_V532_Gap06A->SetMarkerSize(2);
//     // Rebin_Chi_V532_Gap06A->SetStats(0);
//     // Rebin_Chi_V532_Gap06A->GetXaxis()->SetRangeUser(10, 90);
//     // Rebin_Chi_V532_Gap06A->SetTitle("|#Delta #eta |> 0.6 A");
//     // Rebin_Chi_V532_Gap06A->Draw("same");

//     // Rebin_Chi_V532_Gap07A->SetMarkerStyle(kFullDiamond); 
//     // Rebin_Chi_V532_Gap07A->SetMarkerColor(kTeal-2);
//     // Rebin_Chi_V532_Gap07A->SetMarkerSize(2);
//     // Rebin_Chi_V532_Gap07A->SetStats(0);
//     // Rebin_Chi_V532_Gap07A->GetXaxis()->SetRangeUser(10, 90);
//     // Rebin_Chi_V532_Gap07A->SetTitle("|#Delta #eta |> 0.7 A");
//     // Rebin_Chi_V532_Gap07A->Draw("same");

//     // Rebin_Chi_V532_Gap08A->SetMarkerStyle(kFullCircle); 
//     // Rebin_Chi_V532_Gap08A->SetMarkerColor(kMagenta);
//     // //Rebin_Chi_V532_Gap08A->SetMarkerSize(1);
//     // Rebin_Chi_V532_Gap08A->SetStats(0);
//     // Rebin_Chi_V532_Gap08A->GetXaxis()->SetRangeUser(10, 90);
//     // Rebin_Chi_V532_Gap08A->SetTitle("|#Delta #eta |> 0.8 A");
//     // Rebin_Chi_V532_Gap08A->Draw("same");

//     //..Draw a Constant line at y=1
//     gPad->Modified(); 
//     gPad->Update(); // make sure gPad is updated 
//     TLine *line = new TLine(gPad->GetUxmin(), 1, gPad->GetUxmax(), 1);
//     line->SetLineStyle(9);
//     line->SetLineWidth(2); 
//     line->SetLineColor(kBlack);
//     line->Draw(); 

//     TLegend *leg = new TLegend(0.11, 0.6, 0.3, 0.99); 
//     //TLegend *leg = new TLegend(0.65 , 0.2, 0.89, 0.39); 
//     leg->AddEntry(Rebin_Chi_V532_Gap00A, "|#Delta#eta| > 0.0", "lep");
//     leg->AddEntry(Rebin_Chi_V532_Gap01A, "|#Delta#eta| > 0.1", "lep");
//     leg->AddEntry(Rebin_Chi_V532_Gap02A, "|#Delta#eta| > 0.2", "lep");
//     leg->AddEntry(Rebin_Chi_V532_Gap03A, "|#Delta#eta| > 0.3", "lep");
//     leg->AddEntry(Rebin_Chi_V532_Gap04A, "|#Delta#eta| > 0.4", "lep");
//     leg->AddEntry(Rebin_Chi_V532_Gap05A, "|#Delta#eta| > 0.5", "lep");
//     leg->Draw("same");


c1->cd(3);
//    TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Rebin_Plots_Helene_You_Rho422_Rho532/Rebin_RhoV422_Helene.root","READ");

//     TH1D* Rebin_Rho_V422_Gap00A = (TH1D*)fileOutput->Get("Rebin_Rho_V422_Gap00");
//     TH1D* Rebin_Rho_V422_Gap01A = (TH1D*)fileOutput->Get("Rebin_Rho_V422_Gap01");
//     TH1D* Rebin_Rho_V422_Gap02A = (TH1D*)fileOutput->Get("Rebin_Rho_V422_Gap02");
//     TH1D* Rebin_Rho_V422_Gap03A = (TH1D*)fileOutput->Get("Rebin_Rho_V422_Gap03");
//     TH1D* Rebin_Rho_V422_Gap04A = (TH1D*)fileOutput->Get("Rebin_Rho_V422_Gap04");
//     TH1D* Rebin_Rho_V422_Gap05A = (TH1D*)fileOutput->Get("Rebin_Rho_V422_Gap05");
//     TH1D* Rebin_Rho_V422_Gap06A = (TH1D*)fileOutput->Get("Rebin_Rho_V422_Gap06");
//     TH1D* Rebin_Rho_V422_Gap07A = (TH1D*)fileOutput->Get("Rebin_Rho_V422_Gap07");
//     TH1D* Rebin_Rho_V422_Gap08A = (TH1D*)fileOutput->Get("Rebin_Rho_V422_Gap08");
    
//     Rebin_Rho_V422_Gap00A->SetMarkerStyle(kFullCircle); 
//     Rebin_Rho_V422_Gap00A->SetMarkerColor(kBlue+1);
//     Rebin_Rho_V422_Gap00A->SetStats(0);
//     Rebin_Rho_V422_Gap00A->SetTitle(0);
//     Rebin_Rho_V422_Gap00A->GetXaxis()->SetRangeUser(20, 80);
//     Rebin_Rho_V422_Gap00A->Draw("P");
//     Rebin_Rho_V422_Gap00A->GetYaxis()->SetRangeUser(0.2, 1.3);
//     Rebin_Rho_V422_Gap00A->GetYaxis()->SetTitleOffset(1.2);
//     //Rebin_Rho_V422_Gap00A->GetYaxis()->SetTitleSize(0.1);
//     Rebin_Rho_V422_Gap00A->GetYaxis()->SetTitle("#rho_{4,22}");
//     Rebin_Rho_V422_Gap00A->GetYaxis()->CenterTitle(true);
//     Rebin_Rho_V422_Gap00A->GetXaxis()->SetTitle("N_{ch}(|#Delta#eta| < 0.8)");
//     Rebin_Rho_V422_Gap00A->GetXaxis()->CenterTitle(true);
//     Rebin_Rho_V422_Gap00A->GetXaxis()->SetTitleOffset(1.4);

//     Rebin_Rho_V422_Gap01A->SetMarkerStyle(kFullTriangleUp); 
//     Rebin_Rho_V422_Gap01A->SetMarkerColor(kRed+1);
//     Rebin_Rho_V422_Gap01A->SetLineColor(kRed+1);
//     Rebin_Rho_V422_Gap01A->Draw("same");

//     Rebin_Rho_V422_Gap02A->SetMarkerStyle(kFullCircle); 
//     Rebin_Rho_V422_Gap02A->SetMarkerColor(kSpring);
//     Rebin_Rho_V422_Gap02A->SetLineColor(kSpring+1);
//     Rebin_Rho_V422_Gap02A->SetStats(0);
//     Rebin_Rho_V422_Gap02A->Draw("same");

//     Rebin_Rho_V422_Gap03A->SetMarkerStyle(kFullSquare); 
//     Rebin_Rho_V422_Gap03A->SetMarkerColor(kGreen+3);
//     Rebin_Rho_V422_Gap03A->SetLineColor(kGreen+3);
//     Rebin_Rho_V422_Gap03A->SetStats(0);
//     Rebin_Rho_V422_Gap03A->Draw("same");

//     Rebin_Rho_V422_Gap04A->SetMarkerStyle(kFullDiamond); 
//     Rebin_Rho_V422_Gap04A->SetMarkerColor(kBlack);
//     Rebin_Rho_V422_Gap04A->SetLineColor(kBlack);
//     Rebin_Rho_V422_Gap04A->SetMarkerSize(2);
//     Rebin_Rho_V422_Gap04A->SetStats(0);
//     Rebin_Rho_V422_Gap04A->Draw("same");

//     Rebin_Rho_V422_Gap05A->SetMarkerStyle(kFullStar); 
//     Rebin_Rho_V422_Gap05A->SetMarkerColor(kOrange);
//     Rebin_Rho_V422_Gap05A->SetLineColor(kOrange);
//     Rebin_Rho_V422_Gap05A->SetMarkerSize(2);
//     Rebin_Rho_V422_Gap05A->SetStats(0);
//     Rebin_Rho_V422_Gap05A->Draw("same");

//     Rebin_Rho_V422_Gap06A->SetMarkerStyle(kFullCross); 
//     Rebin_Rho_V422_Gap06A->SetMarkerColor(kBlue-9);
//     Rebin_Rho_V422_Gap06A->SetMarkerSize(2);
//     Rebin_Rho_V422_Gap06A->SetStats(0);
//     Rebin_Rho_V422_Gap06A->Draw("same");

//     Rebin_Rho_V422_Gap07A->SetMarkerStyle(kFullDiamond); 
//     Rebin_Rho_V422_Gap07A->SetMarkerColor(kTeal-2);
//     Rebin_Rho_V422_Gap07A->SetMarkerSize(2);
//     Rebin_Rho_V422_Gap07A->SetStats(0);
//     Rebin_Rho_V422_Gap07A->Draw("same");

//     Rebin_Rho_V422_Gap08A->SetMarkerStyle(kFullCircle); 
//     Rebin_Rho_V422_Gap08A->SetMarkerColor(kMagenta);
//     Rebin_Rho_V422_Gap08A->SetLineColor(kMagenta);
//     //Rebin_Rho_V422_Gap08A->SetMarkerSize(1);
//     Rebin_Rho_V422_Gap08A->SetStats(0);
//     Rebin_Rho_V422_Gap08A->Draw("same");
//     //..Draw a Constant line at y=1
//     gPad->Modified(); 
//     gPad->Update(); // make sure gPad is updated 
//     TLine *line = new TLine(gPad->GetUxmin(), 1, gPad->GetUxmax(), 1);
//     line->SetLineStyle(9);
//     line->SetLineWidth(2); 
//     line->SetLineColor(kBlack);
//     line->Draw(); 
//    //h3->Draw();

//     // TLegend *leg = new TLegend(0.18 , 0.6, 0.33, 0.99); 
//     // //TLegend *leg = new TLegend(0.65 , 0.2, 0.89, 0.39); 
//     // leg->AddEntry(Rebin_Rho_V422_Gap00A, "|#Delta#eta| > 0.0", "lep");
//     // leg->AddEntry(Rebin_Rho_V422_Gap01A, "|#Delta#eta| > 0.1", "lep");
//     // leg->AddEntry(Rebin_Rho_V422_Gap02A, "|#Delta#eta| > 0.2", "lep");
//     // leg->AddEntry(Rebin_Rho_V422_Gap03A, "|#Delta#eta| > 0.3", "lep");
//     // leg->AddEntry(Rebin_Rho_V422_Gap04A, "|#Delta#eta| > 0.4", "lep");
//     // leg->AddEntry(Rebin_Rho_V422_Gap05A, "|#Delta#eta| > 0.5", "lep");
//     // leg->AddEntry(Rebin_Rho_V422_Gap06A, "|#Delta#eta| > 0.6", "lep");
//     // leg->AddEntry(Rebin_Rho_V422_Gap07A, "|#Delta#eta| > 0.7", "lep");
//     // leg->AddEntry(Rebin_Rho_V422_Gap08A, "|#Delta#eta| > 0.8", "lep");
//     // leg->Draw("same");

   c1->cd(4);
//    gPad->SetTicky(2);
//       TFile* fileOutput = new TFile("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/Comparison_Katka_Helene_NUA+NUE/Rebin_Plots_Helene_You_Rho422_Rho532/Rebin_RhoV422_Helene.root","READ");

//     TH1D* Rebin_Rho_V532_Gap00A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap00");
//     TH1D* Rebin_Rho_V532_Gap01A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap01");
//     TH1D* Rebin_Rho_V532_Gap02A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap02");
//     TH1D* Rebin_Rho_V532_Gap03A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap03");
//     TH1D* Rebin_Rho_V532_Gap04A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap04");
//     TH1D* Rebin_Rho_V532_Gap05A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap05");
//     TH1D* Rebin_Rho_V532_Gap06A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap06");
//     TH1D* Rebin_Rho_V532_Gap07A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap07");
//     TH1D* Rebin_Rho_V532_Gap08A = (TH1D*)fileOutput->Get("Rebin_Rho_V532_Gap08");
    
//     Rebin_Rho_V532_Gap00A->SetMarkerStyle(kFullCircle); 
//     Rebin_Rho_V532_Gap00A->SetMarkerColor(kBlue+1);
//     Rebin_Rho_V532_Gap00A->SetStats(0);
//     Rebin_Rho_V532_Gap00A->SetTitle(0);
//     Rebin_Rho_V532_Gap00A->GetXaxis()->SetRangeUser(20, 80);
//     Rebin_Rho_V532_Gap00A->Draw("P");
//     Rebin_Rho_V532_Gap00A->GetYaxis()->SetRangeUser(0.2, 1.3);
//     Rebin_Rho_V532_Gap00A->GetYaxis()->SetTitleOffset(1.5);
//     //Rebin_Rho_V532_Gap00A->GetYaxis()->SetTitleSize(0.1);
//     Rebin_Rho_V532_Gap00A->GetYaxis()->SetTitle("#rho_{5,32}");
//     Rebin_Rho_V532_Gap00A->GetYaxis()->CenterTitle(true);
//     Rebin_Rho_V532_Gap00A->GetXaxis()->SetTitle("N_{ch}(|#Delta#eta| < 0.8)");
//     Rebin_Rho_V532_Gap00A->GetXaxis()->CenterTitle(true);
//     Rebin_Rho_V532_Gap00A->GetXaxis()->SetTitleOffset(1.4);

//     Rebin_Rho_V532_Gap01A->SetMarkerStyle(kFullTriangleUp); 
//     Rebin_Rho_V532_Gap01A->SetMarkerColor(kRed+1);
//     Rebin_Rho_V532_Gap01A->SetLineColor(kRed+1);
//     Rebin_Rho_V532_Gap01A->Draw("same");

//     Rebin_Rho_V532_Gap02A->SetMarkerStyle(kFullCircle); 
//     Rebin_Rho_V532_Gap02A->SetMarkerColor(kSpring);
//     Rebin_Rho_V532_Gap02A->SetLineColor(kSpring+1);
//     Rebin_Rho_V532_Gap02A->SetStats(0);
//     Rebin_Rho_V532_Gap02A->Draw("same");

//     Rebin_Rho_V532_Gap03A->SetMarkerStyle(kFullSquare); 
//     Rebin_Rho_V532_Gap03A->SetMarkerColor(kGreen+3);
//     Rebin_Rho_V532_Gap03A->SetLineColor(kGreen+3);
//     Rebin_Rho_V532_Gap03A->SetStats(0);
//     Rebin_Rho_V532_Gap03A->Draw("same");

//     Rebin_Rho_V532_Gap04A->SetMarkerStyle(kFullDiamond); 
//     Rebin_Rho_V532_Gap04A->SetMarkerColor(kBlack);
//     Rebin_Rho_V532_Gap04A->SetLineColor(kBlack);
//     Rebin_Rho_V532_Gap04A->SetMarkerSize(2);
//     Rebin_Rho_V532_Gap04A->SetStats(0);
//     Rebin_Rho_V532_Gap04A->Draw("same");

//     Rebin_Rho_V532_Gap05A->SetMarkerStyle(kFullStar); 
//     Rebin_Rho_V532_Gap05A->SetMarkerColor(kOrange);
//     Rebin_Rho_V532_Gap05A->SetLineColor(kOrange);
//     Rebin_Rho_V532_Gap05A->SetMarkerSize(2);
//     Rebin_Rho_V532_Gap05A->SetStats(0);
//     Rebin_Rho_V532_Gap05A->Draw("same");

    // Rebin_Rho_V532_Gap06A->SetMarkerStyle(kFullCross); 
    // Rebin_Rho_V532_Gap06A->SetMarkerColor(kBlue-9);
    // Rebin_Rho_V532_Gap06A->SetMarkerSize(2);
    // Rebin_Rho_V532_Gap06A->SetStats(0);
    // Rebin_Rho_V532_Gap06A->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_Rho_V532_Gap06A->SetTitle("|#Delta #eta |> 0.6 A");
    // Rebin_Rho_V532_Gap06A->Draw("same");

    // Rebin_Rho_V532_Gap07A->SetMarkerStyle(kFullDiamond); 
    // Rebin_Rho_V532_Gap07A->SetMarkerColor(kTeal-2);
    // Rebin_Rho_V532_Gap07A->SetMarkerSize(2);
    // Rebin_Rho_V532_Gap07A->SetStats(0);
    // Rebin_Rho_V532_Gap07A->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_Rho_V532_Gap07A->SetTitle("|#Delta #eta |> 0.7 A");
    // Rebin_Rho_V532_Gap07A->Draw("same");
    // Rebin_Rho_V532_Gap08A->SetMarkerStyle(kFullCircle); 
    // Rebin_Rho_V532_Gap08A->SetMarkerColor(kMagenta);
    // //Rebin_Rho_V532_Gap08A->SetMarkerSize(1);
    // Rebin_Rho_V532_Gap08A->SetStats(0);
    // Rebin_Rho_V532_Gap08A->GetXaxis()->SetRangeUser(10, 90);
    // Rebin_Rho_V532_Gap08A->SetTitle("|#Delta #eta |> 0.8 A");
    // Rebin_Rho_V532_Gap08A->Draw("same");
    //..Draw a Constant line at y=1
    gPad->Modified(); 
    gPad->Update(); // make sure gPad is updated 
    TLine *line = new TLine(gPad->GetUxmin(), 1, gPad->GetUxmax(), 1);
    line->SetLineStyle(9);
    line->SetLineWidth(2); 
    line->SetLineColor(kBlack);
    line->Draw(); 

    // TLegend *leg = new TLegend(0.11, 0.6, 0.3, 0.99); 
    // //TLegend *leg = new TLegend(0.65 , 0.2, 0.89, 0.39); 
    // leg->AddEntry(Rebin_Rho_V532_Gap00A, "|#Delta#eta| > 0.0", "lep");
    // leg->AddEntry(Rebin_Rho_V532_Gap01A, "|#Delta#eta| > 0.1", "lep");
    // leg->AddEntry(Rebin_Rho_V532_Gap02A, "|#Delta#eta| > 0.2", "lep");
    // leg->AddEntry(Rebin_Rho_V532_Gap03A, "|#Delta#eta| > 0.3", "lep");
    // leg->AddEntry(Rebin_Rho_V532_Gap04A, "|#Delta#eta| > 0.4", "lep");
    // leg->AddEntry(Rebin_Rho_V532_Gap05A, "|#Delta#eta| > 0.5", "lep");
    // leg->Draw("same");
    //c1->SaveAs("/Users/Helena/Dropbox/0-Speciale/DFS/Pic/Chin_Rhon.png");
}

//_____________________________________________________________________________
void SetStyle(Bool_t graypalette) {
  // cout << "Setting style!" << std::end;

  gStyle->Reset("Plain");
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  if(graypalette) gStyle->SetPalette(8,0);
  else gStyle->SetPalette(1);
  gStyle->SetCanvasColor(10);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetFrameLineWidth(1);
  gStyle->SetFrameFillColor(kWhite);
  gStyle->SetPadColor(10);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetHistLineWidth(1);
  gStyle->SetHistLineColor(kRed);
  gStyle->SetFuncWidth(2);
  gStyle->SetFuncColor(kGreen);
  gStyle->SetLineWidth(2);
  gStyle->SetLabelSize(0.045,"xyz");
  gStyle->SetLabelOffset(0.01,"y");
  gStyle->SetLabelOffset(0.01,"x");
  gStyle->SetLabelColor(kBlack,"xyz");
  gStyle->SetTitleSize(0.05,"xyz");
  gStyle->SetTitleOffset(1.25,"y");
  gStyle->SetTitleOffset(1.2,"x");
  gStyle->SetTitleFillColor(kWhite);
  gStyle->SetTextSizePixels(26);
  gStyle->SetTextFont(42);
  //  gStyle->SetTickLength(0.04,"X");  gStyle->SetTickLength(0.04,"Y");

  gStyle->SetLegendBorderSize(0);
  gStyle->SetLegendFillColor(kWhite);
  //  gStyle->SetFillColor(kWhite);
  gStyle->SetLegendFont(42);
}