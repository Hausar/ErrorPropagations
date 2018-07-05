TF1 *fit = 0x0;
double mean[200] = {0};
double meanError[200] = {0};
double XaxisRebin[40] = {0};
int nPtsRebin = 0;

void InitCorrectXaxis();
void CorrectXaxis(TH1D *h1, TGraphErrors *g2);

//...............................................
//		main function
//...............................................
void CorrectAxisOfHistogram(int binning=10)
{

	//	define array according the binning that is chosen
	if(binning == 5) nPtsRebin = 40;
	if(binning == 10) nPtsRebin = 20;
	if(binning == 20) nPtsRebin = 10;
	for(int i=0; i<nPtsRebin; i++) XaxisRebin[i] = i*binning;
  
	//	define random histogram and graph
	//	NOTE: in reality, the histogram will be the rebinned histogram with e.g. v422 (you choose the binning variable based on the binning of the histogram)
	//	The graph will be used to fill in the observable w.r.t. corrected axis
	// TH1D *histogram_correctNch = new TH1D("histogram_correctNch", "", nPtsRebin, 0, 200);
	// histogram_correctNch->Sumw2();
    // histogram_correctNch->SetStats(0);
	// histogram_correctNch->Draw();
	TFile *filehist = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/AllGaps_Rho_v422_v532_NUA+NUE/Rho_n,mk/Rebin_Rho_nmk_NUA+NUE_A+B.root");

	TH1D *histogram = (TH1D*)filehist->Get("Rebin_Rho_422_Gap08");
	//histogram->Draw();

	TGraphErrors *graph = new TGraphErrors();

	//	initialize the correction
	InitCorrectXaxis();

	//	do the correction
	CorrectXaxis(histogram, graph);
	graph->Draw();

	TFile *newfile = TFile::Open("/Users/Helena/Dropbox/0-Speciale/code/panda/Thesis_Macros/Helen_simpletask/ErrorPropagations/All_Gaps_Rho_v422_Rho_v532/AllGaps_Rho_v422_v532_NUA+NUE/Rho_n,mk/Correct_Nch_Rho_nmk_NUA+NUE_A+B.root", "UPDATE");
	newfile->cd();
	graph->Write("Nch_Rho_422_Gap08");
}
//-------------------------------------------------------
void InitCorrectXaxis()
{
//	this initialises the correction:
//	1. get the 2D correlation histogram
//	2. fit the histogram
//	3. slice the N_reco axis of the 2D histogram with the same binning as you have in the histogram of e.g. v422
//	4. for each slice (bin), get the mean of N_reco, for which we will then get the N_truth
//		NOTE: we take the mean of N_reco within a bin instead of just the bin center
//					because the multiplicity distribution is steeply decreasing so the bin center
//					is not a good approximation of the mean multiplicity in the given bin

	TFile *file = TFile::Open("./pPb5TeV_LHC16q_CENT_wSDD.root");
	TDirectoryFile *dir = (TDirectoryFile*)file->Get("default");
	TList *list = (TList*)dir->Get("outputMC_default");

	TH2F *hNtrksRecoTruth = (TH2F*)list->FindObject("hNtrksRecoNtrksTruth");

	fit = new TF1("fit", "pol1", 0, 200);

		//	fit the 2D histogram
	hNtrksRecoTruth->Fit(fit);

	//	get mean of N_reco for correction
	int bin = 0;

	for(int iProj=0; iProj<nPtsRebin; iProj++)
	{
		hNtrksRecoTruth->GetXaxis()->SetRangeUser(XaxisRebin[iProj], XaxisRebin[iProj+1]);
		TH1D *hist_projection = (TH1D*)hNtrksRecoTruth->ProjectionX();
		mean[bin] = hist_projection->GetMean();
		meanError[bin] = hist_projection->GetMeanError();
		delete hist_projection;

		bin = bin+1;
	}

}
//------------------------------------------
void CorrectXaxis(TH1D *h1, TGraphErrors *g2)
{

	//	get errors of the fit parameters
	double param1 = fit->GetParameter(1);
  double paramErr0 = fit->GetParError(0);
  double paramErr1 = fit->GetParError(1);

	//	correct Xaxis
  const int nbin = h1->GetNbinsX();
  double X[200] = {0}; 
  double Y[200] = {0}; 
  double eX[200] = {0}; 
  double eY[200] = {0}; 

  double corr = 1; 
	double npts = 0;

  for(int i=0; i<nbin; i++) 
  {

		Y[i] = h1->GetBinContent(i+1);
		eY[i] = h1->GetBinError(i+1);
		X[i] = fit->Eval(mean[i]);
		eX[i] = TMath::Sqrt(param1*param1*meanError[i]*meanError[i] + X[i]*X[i]*paramErr1*paramErr1 + paramErr0*paramErr0);

    g2->SetPoint(i, X[i], Y[i]);
    g2->SetPointError(i, eX[i], eY[i]);

  }
}
