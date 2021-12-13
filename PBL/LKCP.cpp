#include "LKCP.h"
#include <iomanip>
void LKCP ::Docfiletxt(ifstream &file1)
{
    string cpkhambenh, cpphongbenh, cpphauthuat, thuoc;
    getline(file1, this->_MasoBN, ',');
    getline(file1, this->_Phuonngphap, ',');
    getline(file1, this->_Ngaykham, ',');
    getline(file1, this->_Trangthai, ',');
    getline(file1, cpkhambenh, ',');
    this->_CPkhambenh = atoi(cpkhambenh.c_str());
    getline(file1, cpphongbenh, ',');
    this->_CPphongbenh = atoi(cpphongbenh.c_str());
    getline(file1, cpphauthuat, ',');
    this->_CPphauthuat = atoi(cpphauthuat.c_str());
    getline(file1, thuoc, '\n');
    this->_Thuoc = atoi(thuoc.c_str());
}
string LKCP ::MasoBN3()
{
    return this->_MasoBN;
}
string LKCP ::Phuongphap3()
{
    return this->_Phuonngphap;
}
string LKCP ::Ngaykham3()
{
    return this->_Ngaykham;
}
string LKCP ::Trangthai3()
{
    return this->_Trangthai;
}
long long LKCP ::CPkhambenh3()
{
    return this->_CPkhambenh;
}
long long LKCP ::CPphongbenh3()
{
    return this->_CPphongbenh;
}
long long LKCP ::CPphauthuat3()
{
    return this->_CPphauthuat;
}
long long LKCP ::Thuoc3()
{
    return this->_Thuoc;
}