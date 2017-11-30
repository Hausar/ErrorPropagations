void PrepareWeight()
{
    TFile* file = TFile::Open("/Users/Helena/Desktop/WeightMaximum-merging/Merge/pPb_Results.root","READ");
    if(!file) return;

    file->cd("MyTaskResults");
    TList* list = (TList*) gDirectory->Get("Flow_Refs_MyTaskResults");
    if(!list) return;
    
    TH2F* fHistEtaPhi2D = (TH2F*) list->FindObject("fHistEtaPhi2D");
    if(!fHistEtaPhi2D) return;
    
    fHistEtaPhi2D->Draw("colz");

    // at this it is loaded
    TH1 *hx = fHistEtaPhi2D->ProjectionX();
    //hx->Draw();

    // here put the weight code
    // The method "Clone" is very smart to just reuse the old histogram.
    TH2F* fHistWeightEtaPhi2D = (TH2F*) fHistEtaPhi2D->Clone("fHistWeightEtaPhi2D");
    fHistWeightEtaPhi2D->Reset();  //Reset alle data i histogram men bin er tilbage.

    double weight;
    //double maxeta; 

    printf("Max %f",fHistEtaPhi2D->GetMaximum());
    
    for(int i = 1; i < fHistEtaPhi2D->GetNbinsX()+1; i++)
    {
        for(int j = 1; j < fHistEtaPhi2D->GetNbinsY()+1; j++)
        {
            if(fHistEtaPhi2D->GetBinContent(i, j) > 0.)
        
            fHistEtaPhi2D->GetYaxis()->SetRange(j,j);
                //double maxeta = fHistEtaPhi2D->GetMaximum();
                cout << "j: " << j << endl; 
                //cout << "maxetaPhi: " << maxeta << endl; 
        
            weight = fHistEtaPhi2D->GetMaximum() / fHistEtaPhi2D->GetBinContent(i,j);
                
            else
            {
                weight = 1.;        
            }
            fHistWeightEtaPhi2D->SetBinContent(i, j, weight);
        }
    }

    //**********************************************************************
    //How to make a root.file and write into it.

    TFile* fileOutput = new TFile("Weights_EtaSlides2D.root","RECREATE");
    if(!fileOutput) return;
    fileOutput->cd();
    fHistWeightEtaPhi2D->Write();
    return;

}