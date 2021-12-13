#include <fstream>
#include <iostream>
using namespace std;
class Benhnhan
{
    private:
        int _ngayv,_thangv,_namv;
        string _MasoBS;
        string _MasoBN;
        string _HotenBN;
        string _Cmnd;
        string _Gioitinh;
        int _Namsinh;
        string _Diachi;
        string _SDT;
        string _Tenbenh;
    public:
        void Docfile2(ifstream &);
        void Xuatmanhinh2();
        void Xuatfile2(ofstream &);
        void Inlaivaofile2(ofstream &);
        string MasoBS2();
        string MasoBN2();
        string HotenBN2();
        string Cmnd2();
        string Gioitinh2();
        int Namsinh2();
        string Diachi2();
        string SDT2();
        string Tenbenh2();
        string MasoBS2(string);
        string MasoBN2(string);
        string HotenBN2(string);
        string Cmnd2(string);
        string Gioitinh2(string);
        int Namsinh2(int);
        string Diachi2(string);
        string SDT2(string);
        string Tenbenh2(string);
        int ngayv();
        int thangv();
        int namv();
        friend istream &operator>>(istream &, Benhnhan &);
        friend ostream &operator<<(ostream &, const Benhnhan &);
};
