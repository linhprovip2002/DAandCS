#include <fstream>
#include<iostream>
using namespace std;
class Bacsi
{
    private:
        string _MasoBS;
        string _HotenBS;
        string _Gioitinh;
        int _Namsinh;
        string _SDT;
        string _Chuyenkhoa;
    public:
        void Docfile1(ifstream &);
        void Xuatmanhinh1();
        void Xuatfile1(ofstream &);
        void Inlaivaofile1(ofstream &);
        string MasoBS1();
        string HotenBS1();
        string Gioitinh1();
        int Namsinh1();
        string SDT1();
        string Chuyenkhoa1();
        string HotenBS1(string);
        string Gioitinh1(string);
        int Namsinh1(int);
        string SDT1(string);
        string Chuyenkhoa1(string);
        friend istream& operator>> (istream &, Bacsi &);
        friend ostream& operator<< (ostream &, const Bacsi &);
};