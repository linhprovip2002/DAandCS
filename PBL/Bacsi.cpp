#include "Bacsi.h"
#include <iomanip>
#include <string>
void Bacsi::Docfile1(ifstream &fileIn)
{
    string namsinh;
    getline(fileIn, this->_MasoBS, ',');
    getline(fileIn, this->_HotenBS, ',');
    getline(fileIn, this->_Gioitinh, ',');
    getline(fileIn, namsinh, ',');
    this->_Namsinh = atoi(namsinh.c_str());
    getline(fileIn, this->_SDT, ',');
    getline(fileIn, this->_Chuyenkhoa, '\n');
}
// xuất ra màn hình
void Bacsi ::Xuatmanhinh1()
{
    cout << "\t|    " << setw(8) << left << this->_MasoBS << "|   " << setw(25) << left << this->_HotenBS << "|    " << setw(9)
         << left << this->_Gioitinh << "|     " << setw(9) << left << this->_Namsinh << "|    " << setw(15)
         << left << this->_SDT << "|    " << setw(20) << left << this->_Chuyenkhoa << "|" << endl;
}
// xuất ra file
void Bacsi ::Xuatfile1(ofstream &fileOut)
{
    fileOut << "|    " << setw(8) << left << this->_MasoBS << "|   " << setw(25) << left << this->_HotenBS << "|    " << setw(9)
            << left << this->_Gioitinh << "|     " << setw(9) << left << this->_Namsinh << "|    " << setw(15)
            << left << this->_SDT << "|    " << setw(20) << left << this->_Chuyenkhoa << "|" << endl;
}
// Cập nhật lại file input
void Bacsi ::Inlaivaofile1(ofstream &fileIn)
{
    fileIn << this->_MasoBS << "," << this->_HotenBS << "," << this->_Gioitinh << ","
           << this->_Namsinh << "," << this->_SDT << "," << this->_Chuyenkhoa << endl;
}
istream &operator>>(istream &in, Bacsi &d)
{
    cout << "\n\tMa so bac si: ";
    getline(in >> ws, d._MasoBS);
    cout << "\n\tHo ten bac si: ";
    getline(in >> ws, d._HotenBS);
    cout << "\n\tGioi tinh: ";
    getline(in >> ws, d._Gioitinh);
    cout << "\n\tNam sinh: ";
    in >> d._Namsinh;
    cout << "\n\tSo dien thoai: ";
    getline(in >> ws, d._SDT);
    cout << "\n\tChuyen khoa: ";
    getline(in >> ws, d._Chuyenkhoa);
    return in;
}

ostream &operator<<(ostream &out, const Bacsi &d)
{
    out << d._MasoBS << "," << d._HotenBS << "," << d._Gioitinh << ","
        << d._Namsinh << "," << d._SDT << "," << d._Chuyenkhoa << endl;
    return out;
}
string Bacsi ::MasoBS1()
{
    return this->_MasoBS;
}
string Bacsi ::HotenBS1()
{
    return this->_HotenBS;
}
string Bacsi ::Gioitinh1()
{
    return this->_Gioitinh;
}
int Bacsi ::Namsinh1()
{
    return this->_Namsinh;
}
string Bacsi ::SDT1()
{
    return this->_SDT;
}
string Bacsi ::Chuyenkhoa1()
{
    return this->_Chuyenkhoa;
}
string Bacsi ::HotenBS1(string a)
{
    return this->_HotenBS = a;
}
string Bacsi::Gioitinh1(string a)
{
    return this->_Gioitinh = a;
}
int Bacsi::Namsinh1(int a)
{
    return this->_Namsinh = a;
}
string Bacsi::SDT1(string a)
{
    return this->_SDT = a;
}
string Bacsi::Chuyenkhoa1(string a)
{
    return this->_Chuyenkhoa = a;
}