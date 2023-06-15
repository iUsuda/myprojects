# ondotori.h
「おんどとり」に記録されたデータをROOTでグラフ化することを目的としたツール  
おんどとりの種類やデータの吸い出し方に応じた関数が入っている

## 注意点
あくまでROOTを用いての描画を目的にしているため、時刻指定はROOTに合わせてTDatetimeを使ってunixtimeもどきにする必要がある。

### サンプルコードの実行
引数の説明はsample.cppを参照  
ターミナルで`root -l -q -b sample.cpp`を実行すると、sample1.pdf、sample2.pdfが出力される。

## ReadTR7
対応機種：TR7シリーズ  
吸い出し方：おんどとりWeb Storage、USB接続(TR7 for Windows)

- int ReadTR7(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch2)  
  - ch1、ch2の記録値を全て取得し、vectorに詰める
- int ReadTR7(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch2, double start, double end)
  - ch1, ch2の記録値のうち、指定の時間範囲のもののみvectorに詰める
- int ReadTR7(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1)
  - ch1の記録値のみ全て取得し、vectorに詰める
- int ReadTR7(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, double start, double end)
  - ch1の記録値のうち、指定の時間範囲のもののみvectorに詰める

戻り値は全てデータ数

## ReadTR7_bt
対応機種：TR7シリーズ  
吸い出し方：Bluetooth(T&D Thermo)

- int ReadTR7_bt(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch2)  
  - ch1、ch2の記録値を全て取得し、vectorに詰める
- int ReadTR7_bt(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch2, double start, double end)
  - ch1, ch2の記録値のうち、指定の時間範囲のもののみvectorに詰める
- int ReadTR7_bt(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1)
  - ch1の記録値のみ全て取得し、vectorに詰める
- int ReadTR7_bt(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, double start, double end)
  - ch1の記録値のうち、指定の時間範囲のもののみvectorに詰める

戻り値は全てデータ数

## ReadTR73U
対応機種：TR73U
吸い出し方：USB接続(T&D Recorder for windows)
- int ReadTR73U(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch2, std::vector<double>& v_ch3)
  - ch1、ch2、ch3の記録値を全て取得し、vectorに詰める
- int ReadTR73U(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch2, std::vector<double>& v_ch3, double start, double end)
  - ch1, ch2の記録値のうち、指定の時間範囲のもののみvectorに詰める

戻り値は全てデータ数

## SetFormat
TGraphオブジェクトの横軸を時刻表記にし、タイトル、データ点(線)の色、サイズを変更する
- void SetFormat(TGraph \*g, Color_t color, Float_t alpha, std::string title = "", std::string TimeFormat = "#splitline{%m/%d}{%H:%M}", double TimeOffset = 9*3600);
