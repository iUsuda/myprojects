#include<TGraph.h>
#include<TCanvas.h>
#include"ondotori.h"
using namespace std;

void sample(){
    string file = "./sample_TR72wf.csv";

    TCanvas *c = new TCanvas("c", "c", 1600, 900);
    gPad->SetRightMargin(0.05);
    gPad->SetLeftMargin(0.1);
    gPad->SetTopMargin(0.08);
    gPad->SetBottomMargin(0.1);

    //時刻指定無し
    vector<double> v_time1;
    vector<double> v_temp1;
    vector<double> v_humi1;

    int cnt1 = ond::ReadTR7(file, v_time1, v_temp1, v_humi1);

    TGraph *g_temp1 = new TGraph(cnt1, v_time1.data(), v_temp1.data());
    ond::SetFormat(g_temp1, kRed, 1, "sample1;;Temperature[#circC]");

    g_temp1->GetYaxis()->SetLabelSize(0.04);
    g_temp1->GetXaxis()->SetLabelSize(0.04);
    g_temp1->GetXaxis()->SetLabelOffset(0.03);
    g_temp1->GetYaxis()->SetTitleSize(0.06);
    g_temp1->GetYaxis()->SetTitleOffset(0.6);

    g_temp1->Draw("AP");
    c->Print("sample1.pdf");
    c->Clear();

    //時刻指定あり
    TDatime datime_start(2023, 5, 10, 0, 0, 0);
    double time_start = datime_start.Convert();
    TDatime datime_end(2023, 5, 15, 0, 0, 0);
    double time_end = datime_end.Convert();

    vector<double> v_time2;
    vector<double> v_temp2;
    vector<double> v_humi2;

    int cnt2 = ond::ReadTR7(file, v_time2, v_temp2, v_humi2, time_start, time_end);

    TGraph *g_temp2 = new TGraph(cnt2, v_time2.data(), v_temp2.data());
    ond::SetFormat(g_temp2, kRed, 1, "sample2;;Temperature[#circC]");

    g_temp2->GetYaxis()->SetLabelSize(0.04);
    g_temp2->GetXaxis()->SetLabelSize(0.04);
    g_temp2->GetXaxis()->SetLabelOffset(0.03);
    g_temp2->GetYaxis()->SetTitleSize(0.06);
    g_temp2->GetYaxis()->SetTitleOffset(0.6);

    g_temp2->Draw("AP");
    c->Print("sample2.pdf");
    c->Clear();

}