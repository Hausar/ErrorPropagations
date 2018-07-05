// This file is made for plot the correct Nch in new histogram

void plot_correctAxis() {

	TFile *newfile = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/AllGaps_Rho_v422_v532_NUA+NUE/Rho_n,mk/Correct_Nch_Rho_nmk_NUA+NUE_A+B.root", "READ");
	newfile->cd();

    TGraph *graph0 = (TGraph*)newfile->Get("Nch_Rho_422_Gap00");
    TGraph *graph1 = (TGraph*)newfile->Get("Nch_Rho_422_Gap01");
    TGraph *graph2 = (TGraph*)newfile->Get("Nch_Rho_422_Gap02");
    //gStyle->SetErrorX(1);
    Nch_Rho_422_Gap00->RemovePoint(0);
    Nch_Rho_422_Gap00->RemovePoint(9);
    Nch_Rho_422_Gap00->RemovePoint(8);
    Nch_Rho_422_Gap00->Draw("ap");

    Nch_Rho_422_Gap01->RemovePoint(0);
    Nch_Rho_422_Gap01->RemovePoint(9);
    Nch_Rho_422_Gap01->RemovePoint(8);
    Nch_Rho_422_Gap01->Draw("paSame");

    Nch_Rho_422_Gap02->RemovePoint(0);
    Nch_Rho_422_Gap02->RemovePoint(9);
    Nch_Rho_422_Gap02->RemovePoint(8);
    Nch_Rho_422_Gap02->Draw("apSame");

    //Nch_Rho_422_Gap01->Draw("same");

    // TH1D *histogram_correctNch = new TH1D("histogram_correctNch", "", 20, 0, 200);
	// histogram_correctNch->Sumw2();
    // histogram_correctNch->SetStats(0);
    // histogram_correctNch->GetXaxis()->SetRangeUser(10, 140);
	// histogram_correctNch->Draw();
    TFile *newfile = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/AllGaps_Rho_v422_v532_NUA+NUE/Rho_n,mk/Removed_points_Nch_Rho_nmk_NUA+NUE_A+B.root", "UPDATE");
	newfile->cd();
	graph0->Write("Nch_Rho_422_Gap00");
    graph1->Write("Nch_Rho_422_Gap01");
}


