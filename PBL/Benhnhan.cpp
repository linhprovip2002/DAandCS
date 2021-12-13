#include "Benhnhan.h"
#include <fstream>
#include <iomanip>
#include <string>
void Benhnhan ::Docfile2(ifstream &fileIn)
{
    string namsinh, ngay, thang, nam;
    getline(fileIn, this->_MasoBS, ',');
    getline(fileIn, this->_MasoBN, ',');
    getline(fileIn, this->_HotenBN, ',');
    getline(fileIn, this->_Cmnd, ',');
    getline(fileIn, this->_Gioitinh, ',');
    getline(fileIn, namsinh, ',');
    this->_Namsinh = atoi(namsinh.c_str());
    getline(fileIn, this->_Diachi, ',');
    getline(fileIn, this->_SDT, ',');
    getline(fileIn, ngay, '/');
    getline(fileIn, thang, '/');
    getline(fileIn, nam, ',');
    this->_ngayv = atoi(ngay.c_str());
    this->_thangv = atoi(thang.c_str());
    this->_namv = atoi(nam.c_str());
    getline(fileIn, this->_Tenbenh, '\n');
}

void Benhnhan::Xuatmanhinh2()
{
    cout << "|   " << setw(7) << left << this->_MasoBN << "|  " << setw(20) << left << this->_HotenBN << "|  " << setw(13) << left << this->_Cmnd << "|    "
         << setw(7) << left << this->_Gioitinh << "|   " << setw(7) << left << this->_Namsinh << "|  " << setw(22) << left << this->_Diachi << "|   " << setw(13)
         << left << this->_SDT << "|  " << setw(2) << right << this->_ngayv << "/" << setw(2) << right << this->_thangv << "/" << setw(7) << left << this->_namv
         << "|    " << setw(17) << left << this->_Tenbenh << "|" << endl;
}

void Benhnhan ::Xuatfile2(ofstream &fileOut)
{
    fileOut << "|   " << setw(7) << left << this->_MasoBN << "|  " << setw(20) << left << this->_HotenBN << "|  " << setw(13) << left << this->_Cmnd << "|    "
            << setw(7) << left << this->_Gioitinh << "|   " << setw(7) << left << this->_Namsinh << "|  " << setw(22) << left << this->_Diachi << "|   " << setw(13)
            << left << this->_SDT << "|  " << setw(2) << right << this->_ngayv << "/" << setw(2) << right << this->_thangv << "/" << setw(7) << left << this->_namv
            << "|    " << setw(17) << left << this->_Tenbenh << "|" << endl;
}
void Benhnhan ::Inlaivaofile2(ofstream &fileIn)
{
    fileIn << this->_MasoBS << "," << this->_MasoBN << "," << this->_HotenBN << "," << this->_Cmnd << "," << this->_Gioitinh << "," << this->_Namsinh << ","
           << this->_Diachi << "," << this->_SDT << "," << this->_ngayv << "/" << this->_thangv << "/" << this->_namv << "," << this->_Tenbenh << endl;
}
string Benhnhan::MasoBS2()
{
    return this->_MasoBS;
}
string Benhnhan::MasoBN2()
{
    return this->_MasoBN;
}
string Benhnhan::HotenBN2()
{
    return this->_HotenBN;
}
string Benhnhan::Cmnd2()
{
    return this->_Cmnd;
}
string Benhnhan::Gioitinh2()
{
    return this->_Gioitinh;
}
int Benhnhan::Namsinh2()
{
    return this->_Namsinh;
}
string Benhnhan::Diachi2()
{
    return this->_Diachi;
}
string Benhnhan::SDT2()
{
    return this->_SDT;
}
string Benhnhan::Tenbenh2()
{
    return this->_Tenbenh;
}
string Benhnhan ::MasoBS2(string a)
{
    return this->_MasoBS = a;
}
string Benhnhan::HotenBN2(string a)
{
    return this->_HotenBN = a;
}
string Benhnhan ::MasoBN2(string a)
{
    return this->_MasoBN;
}
string Benhnhan ::Cmnd2(string a)
{
    return this->_Cmnd = a;
}
string Benhnhan::Gioitinh2(string a)
{
    return this->_Gioitinh = a;
}
int Benhnhan::Namsinh2(int a)
{
    return this->_Namsinh = a;
}
string Benhnhan::Diachi2(string a)
{
    return this->_Diachi = a;
}
string Benhnhan::SDT2(string a)
{
    return this->_SDT = a;
}
string Benhnhan ::Tenbenh2(string a)
{
    return this->_Tenbenh = a;
}
int Benhnhan ::ngayv()
{
    return this->_ngayv;
}
int Benhnhan ::thangv()
{
    return this->_thangv;
}
int Benhnhan ::namv()
{
    return this->_namv;
}
istream &operator>>(istream &in, Benhnhan &d)
{
    cout << "\nMa so bac si: ";
    getline(in >> ws, d._MasoBS);
    cout << "\nMa so benh nhan: ";
    getline(in >> ws, d._MasoBN);
    cout << "\nHo ten benh nhan: ";
    getline(in >> ws, d._HotenBN);
    cout << "\nSo giay CMND/Ho chieu: ";
    getline(in >> ws, d._Cmnd);
    cout << "\nGioi tinh: ";
    getline(in >> ws, d._Gioitinh);
    cout << "\nNam sinh: ";
    in >> d._Namsinh;
    cout << "\nDia chi: ";
    getline(in >> ws, d._Diachi);
    cout << "\nSo dien thoai: ";
    getline(in >> ws, d._SDT);
    cout << "\nTen benh: ";
    getline(in >> ws, d._Tenbenh);
    return in;
}
ostream &operator<<(ostream &out, const Benhnhan &d)
{
    out << setw(11) << d._MasoBS << setw(11) << left << d._MasoBN << setw(25) << left << d._HotenBN << setw(16) << left << d._Cmnd
        << setw(12) << left << d._Gioitinh << setw(12) << left << d._Namsinh << setw(35) << left << d._Diachi << setw(16)
        << left << d._SDT << setw(25) << left << d._Tenbenh << endl;
    return out;
}