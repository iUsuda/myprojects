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
    vector<double> v_time1;//時刻情報を入れるvector
    vector<double> v_temp1;//ch1の情報(温度)を入れるvector
    vector<double> v_humi1;//ch2の情報(湿度)を入れるvector

    int cnt1 = ond::ReadTR7(file, v_time1, v_temp1, v_humi1);//vectorの要素数を返す

    TGraph *g_temp1 = new TGraph(cnt1, v_time1.data(), v_temp1.data());
    Color_t color1 = kRed;//マーカー、線の色
    float alpha1 = 1;//マーカー、線の透明度(0:透明、1:透明でない)
    string title1 = "sample1;;Temperature[#circC]";//タイトル、軸ラベル
    string TimeFormat = "#splitline{%m/%d}{%H:%M}";//横軸のフォーマット。フォーマット指定子の詳細は(https://root.cern.ch/doc/master/classTAxis.html#adf83fc3e553a916d2dc1d27a8f40e429)を参照
    double TimeOffset = 9*3600;//標準時からの時差(秒)
    ond::SetFormat(g_temp1, color1, alpha1, title1, TimeFormat, TimeOffset);

    g_temp1->GetYaxis()->SetLabelSize(0.04);
    g_temp1->GetXaxis()->SetLabelSize(0.04);
    g_temp1->GetXaxis()->SetLabelOffset(0.03);
    g_temp1->GetYaxis()->SetTitleSize(0.06);
    g_temp1->GetYaxis()->SetTitleOffset(0.6);

    g_temp1->Draw("AP");
    c->Print("sample1.pdf");
    c->Clear();

    //時刻指定あり
    TDatime datime_start(2023, 5, 10, 0, 0, 0);//開始時刻
    double time_start = datime_start.Convert();
    TDatime datime_end(2023, 5, 15, 0, 0, 0);//終了時刻
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