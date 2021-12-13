#include<iostream>
#include<string>
#include <fstream>
using namespace std;
class LKCP
{
private:
    string _MasoBN;
    string _Phuonngphap;
    string _Ngaykham;
    string _Trangthai;
    long long _CPkhambenh;
    long long _CPphongbenh;
    long long _CPphauthuat;
    long long _Thuoc;
public:
    void Docfiletxt(ifstream&);
    string MasoBN3();
    string Phuongphap3();
    string Ngaykham3();
    string Trangthai3();
    long long CPkhambenh3();
    long long CPphongbenh3();
    long long CPphauthuat3();
    long long Thuoc3();
};