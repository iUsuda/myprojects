#ifndef ONDOTORI_H_
#define ONDOTORI_H_
#include<vector>
#include<fstream>
#include<iostream>
#include<TDatime.h>
#include<TAxis.h>
#include<TGraph.h>

class ond
{
    public:
    static int ReadTR7(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch2);
    static int ReadTR7(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch2, double start, double end);
    static int ReadTR7(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1);
    static int ReadTR7(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, double start, double end);
    static int ReadTR7_bt(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch2);
    static int ReadTR7_bt(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch2, double start, double end);
    static int ReadTR7_bt(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1);
    static int ReadTR7_bt(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, double start, double end);
    static int ReadTR73U(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch3);
    static int ReadTR73U(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch3, double start, double end);
    static void SetFormat(TGraph *g, Color_t color, Float_t alpha, std::string title = "", std::string TimeFormat = "#splitline{%m/%d}{%H:%M}", double TimeOffset = 9*3600);
};

inline int ond::ReadTR7(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch2){
    double time, ch1, ch2;
    int y, m, d, hh, mm, ss;

    TDatime DateTime;

    std::ifstream ifs(file);
    if(ifs.fail()){
        std::cerr << "File Open Failed : " << file << std::endl;
        exit(1);
    }
    std::string buf;
    int linecnt = 0;
    while(getline(ifs, buf)){
        if(linecnt < 4){
            linecnt++;
            continue;
        }
        sscanf(buf.data(), "\"%d-%d-%d %d:%d:%d\",\"%*lf\",\"%lf\",\"%lf\"", &y, &m, &d, &hh, &mm, &ss, &ch1, &ch2);

        DateTime.Set(y, m, d, hh, mm, ss);
        time = DateTime.Convert();

        v_time.push_back(time);
        v_ch1.push_back(ch1);
        v_ch2.push_back(ch2);
    }
    ifs.close();
    return v_time.size();
}

inline int ond::ReadTR7(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch2, double start, double end){
    double time, ch1, ch2;
    int y, m, d, hh, mm, ss;

    TDatime DateTime;

    std::ifstream ifs(file);
    if(ifs.fail()){
        std::cerr << "File Open Failed : " << file << std::endl;
        exit(1);
    }
    std::string buf;
    int linecnt = 0;
    while(getline(ifs, buf)){
        if(linecnt < 4){
            linecnt++;
            continue;
        }
        sscanf(buf.data(), "\"%d-%d-%d %d:%d:%d\",\"%*lf\",\"%lf\",\"%lf\"", &y, &m, &d, &hh, &mm, &ss, &ch1, &ch2);

        DateTime.Set(y, m, d, hh, mm, ss);
        time = DateTime.Convert();
        if(time < start) continue;
        if(time > end) break;

        v_time.push_back(time);
        v_ch1.push_back(ch1);
        v_ch2.push_back(ch2);
    }
    ifs.close();
    return v_time.size();
}

inline int ond::ReadTR7(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1){
    double time, ch1;
    int y, m, d, hh, mm, ss;

    TDatime DateTime;

    std::ifstream ifs(file);
    if(ifs.fail()){
        std::cerr << "File Open Failed : " << file << std::endl;
        exit(1);
    }
    std::string buf;
    int linecnt = 0;
    while(getline(ifs, buf)){
        if(linecnt < 4){
            linecnt++;
            continue;
        }
        sscanf(buf.data(), "\"%d-%d-%d %d:%d:%d\",\"%*lf\",\"%lf\",\"%*lf\"", &y, &m, &d, &hh, &mm, &ss, &ch1);

        DateTime.Set(y, m, d, hh, mm, ss);
        time = DateTime.Convert();

        v_time.push_back(time);
        v_ch1.push_back(ch1);
    }
    ifs.close();
    return v_time.size();
}

inline int ond::ReadTR7(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, double start, double end){
    double time, ch1;
    int y, m, d, hh, mm, ss;

    TDatime DateTime;

    std::ifstream ifs(file);
    if(ifs.fail()){
        std::cerr << "File Open Failed : " << file << std::endl;
        exit(1);
    }
    std::string buf;
    int linecnt = 0;
    while(getline(ifs, buf)){
        if(linecnt < 4){
            linecnt++;
            continue;
        }
        sscanf(buf.data(), "\"%d-%d-%d %d:%d:%d\",\"%*lf\",\"%lf\",\"%*lf\"", &y, &m, &d, &hh, &mm, &ss, &ch1);

        DateTime.Set(y, m, d, hh, mm, ss);
        time = DateTime.Convert();
        if(time < start) continue;
        if(time > end) break;

        v_time.push_back(time);
        v_ch1.push_back(ch1);
    }
    ifs.close();
    return v_time.size();
}

inline int ond::ReadTR7_bt(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch2){
    double time, ch1, ch2;
    int y, m, d, hh, mm, ss;

    TDatime DateTime;

    std::ifstream ifs(file);
    if(ifs.fail()){
        std::cerr << "File Open Failed : " << file << std::endl;
        exit(1);
    }
    std::string buf;
    int linecnt = 0;
    while(getline(ifs, buf)){
        if(linecnt < 4){
            linecnt++;
            continue;
        }
        sscanf(buf.data(), "%d/%d/%d %d:%d:%d,%lf,%lf", &y, &m, &d, &hh, &mm, &ss, &ch1, &ch2);
        
        DateTime.Set(y, m, d, hh, mm, ss);
        time = DateTime.Convert();

        v_time.push_back(time);
        v_ch1.push_back(ch1);
        v_ch2.push_back(ch2);
    }
    ifs.close();
    return v_time.size();
}

inline int ond::ReadTR7_bt(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch2, double start, double end){
    double time, ch1, ch2;
    int y, m, d, hh, mm, ss;

    TDatime DateTime;

    std::ifstream ifs(file);
    if(ifs.fail()){
        std::cerr << "File Open Failed : " << file << std::endl;
        exit(1);
    }
    std::string buf;
    int linecnt = 0;
    while(getline(ifs, buf)){
        if(linecnt < 4){
            linecnt++;
            continue;
        }
        sscanf(buf.data(), "%d/%d/%d %d:%d:%d,%lf,%lf", &y, &m, &d, &hh, &mm, &ss, &ch1, &ch2);
        
        DateTime.Set(y, m, d, hh, mm, ss);
        time = DateTime.Convert();
        if(time < start) continue;
        if(time > end) break;

        v_time.push_back(time);
        v_ch1.push_back(ch1);
        v_ch2.push_back(ch2);
    }
    ifs.close();
    return v_time.size();
}

inline int ond::ReadTR7_bt(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1){
    double time, ch1;
    int y, m, d, hh, mm, ss;

    TDatime DateTime;

    std::ifstream ifs(file);
    if(ifs.fail()){
        std::cerr << "File Open Failed : " << file << std::endl;
        exit(1);
    }
    std::string buf;
    int linecnt = 0;
    while(getline(ifs, buf)){
        if(linecnt < 4){
            linecnt++;
            continue;
        }
        sscanf(buf.data(), "%d/%d/%d %d:%d:%d,%lf,%*lf", &y, &m, &d, &hh, &mm, &ss, &ch1);
        
        DateTime.Set(y, m, d, hh, mm, ss);
        time = DateTime.Convert();

        v_time.push_back(time);
        v_ch1.push_back(ch1);
    }
    ifs.close();
    return v_time.size();
}

inline int ond::ReadTR7_bt(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, double start, double end){
    double time, ch1;
    int y, m, d, hh, mm, ss;

    TDatime DateTime;

    std::ifstream ifs(file);
    if(ifs.fail()){
        std::cerr << "File Open Failed : " << file << std::endl;
        exit(1);
    }
    std::string buf;
    int linecnt = 0;
    while(getline(ifs, buf)){
        if(linecnt < 4){
            linecnt++;
            continue;
        }
        sscanf(buf.data(), "%d/%d/%d %d:%d:%d,%lf,%*lf", &y, &m, &d, &hh, &mm, &ss, &ch1);
        
        DateTime.Set(y, m, d, hh, mm, ss);
        time = DateTime.Convert();
        if(time < start) continue;
        if(time > end) break;

        v_time.push_back(time);
        v_ch1.push_back(ch1);
    }
    ifs.close();
    return v_time.size();
}

inline int ond::ReadTR73U(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch3){
    double time, ch1, ch2, ch3;
    int y, m, d, hh, mm, ss;

    TDatime DateTime;

    std::ifstream ifs(file);
    if(ifs.fail()){
        std::cerr << "File Open Failed : " << file << std::endl;
        exit(1);
    }
    std::string buf;
    int linecnt = 0;
    while(getline(ifs, buf)){
        if(linecnt < 4){
            linecnt++;
            continue;
        }
        sscanf(buf.data(),"\"%d/%d/%d %d:%d'%d\",\"%*lf\",\"%lf\",\"\",\"%lf\",\"\",\"\",\"\",\"\",\"\",", &y, &m, &d, &hh, &mm, &ss, &ch1, &ch3);
        
        DateTime.Set(y, m, d, hh, mm, ss);
        time = DateTime.Convert();

        v_time.push_back(time);
        v_ch1.push_back(ch1);
        v_ch3.push_back(ch3);
    }
    ifs.close();
    return v_time.size();
}

inline int ond::ReadTR73U(std::string file, std::vector<double>& v_time, std::vector<double>& v_ch1, std::vector<double>& v_ch3, double start, double end){
    double time, ch1, ch2, ch3;
    int y, m, d, hh, mm, ss;

    TDatime DateTime;

    std::ifstream ifs(file);
    if(ifs.fail()){
        std::cerr << "File Open Failed : " << file << std::endl;
        exit(1);
    }
    std::string buf;
    int linecnt = 0;
    while(getline(ifs, buf)){
        if(linecnt < 4){
            linecnt++;
            continue;
        }
        sscanf(buf.data(),"\"%d/%d/%d %d:%d'%d\",\"%*lf\",\"%lf\",\"\",\"%lf\",\"\",\"\",\"\",\"\",\"\",", &y, &m, &d, &hh, &mm, &ss, &ch1, &ch3);
        
        DateTime.Set(y, m, d, hh, mm, ss);
        time = DateTime.Convert();
        if(time < start) continue;
        if(time > end) break;

        v_time.push_back(time);
        v_ch1.push_back(ch1);
        v_ch3.push_back(ch3);
    }
    ifs.close();
    return v_time.size();
}

void ond::SetFormat(TGraph *g, Color_t color, Float_t alpha, std::string title, std::string TimeFormat, double TimeOffset){
    g->GetXaxis()->SetTimeDisplay(1);
    g->GetXaxis()->SetTimeOffset(TimeOffset, "gmt");
    g->GetXaxis()->SetTimeFormat(TimeFormat.c_str());
    
    g->SetTitle(title.c_str());
    g->SetLineColorAlpha(color, alpha);
    g->SetMarkerColorAlpha(color, alpha);
    g->SetMarkerStyle(20);

}

#endif //ONDOTORI_H_