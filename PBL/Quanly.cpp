#include "Quanly.h"
#include <iomanip>
#include <time.h>
#include <string>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
Quanly ::Quanly()
{
    ifstream fileIn1, fileIn2, fileIn3;
    fileIn1.open("Bacsi.txt", ios_base ::in);
    fileIn2.open("Benhnhan.txt", ios_base ::in);
    fileIn3.open("LKCP.txt", ios_base ::in);
    string temp1, temp2, temp3;
    getline(fileIn1, temp1, '\n');
    this->_Length1 = atoi(temp1.c_str());
    getline(fileIn2, temp2, '\n');
    this->_Length2 = atoi(temp2.c_str());
    getline(fileIn3, temp3, '\n');
    this->_Length3 = atoi(temp3.c_str());
    this->bs = new Bacsi[this->_Length1];
    for (int i = 0; i < this->_Length1; i++)
    {
        (this->bs + i)->Docfile1(fileIn1);
    }
    this->bn = new Benhnhan[this->_Length2];
    for (int j = 0; j < this->_Length2; j++)
    {
        (this->bn + j)->Docfile2(fileIn2);
    }
    this->lk = new LKCP[this->_Length3];
    for (int k = 0; k < this->_Length3; k++)
    {
        (this->lk + k)->Docfiletxt(fileIn3);
    }
    fileIn1.close();
    fileIn2.close();
    fileIn3.close();
}
Quanly ::~Quanly()
{
}
void Quanly ::Menu1()
{
    ofstream fileOut;
    fileOut.open("ListBacsi.txt", ios_base ::out);
    cout << "\t---------------------------------------------------------------------------------------------------------------------" << endl;
    fileOut << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t|  Ma so BS  |      Ho ten bac si         |  Gioi tinh  |   Nam sinh   |   So dien thoai   |      Chuyen khoa       |" << endl;
    fileOut << "|  Ma so BS  |      Ho ten bac si         |  Gioi tinh  |   Nam sinh   |   So dien thoai   |      Chuyen khoa       |" << endl;
    cout << "\t---------------------------------------------------------------------------------------------------------------------" << endl;
    fileOut << "---------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < this->_Length1; i++)
    {
        (this->bs + i)->Xuatmanhinh1();
        (this->bs + i)->Xuatfile1(fileOut);
    }
    cout << "\t---------------------------------------------------------------------------------------------------------------------" << endl;
    fileOut << "---------------------------------------------------------------------------------------------------------------------" << endl;
    fileOut.close();
}
void Quanly::Add1()
{
    int n;
    ofstream fileIn;
    fileIn.open("Bacsi.txt", ios ::app);
    cout << "\tNhap thong tin bac si can them vao danh sach: ";
    Bacsi s;
    cin >> s;
    Bacsi *temp = new Bacsi[this->_Length1];
    for (int i = 0; i < this->_Length1; i++)
        *(temp + i) = *(this->bs + i);
    delete[] this->bs;
    this->bs = new Bacsi[this->_Length1 + 1];
    for (int i = 0; i < this->_Length1; i++)
        *(this->bs + i) = *(temp + i);
    delete[] temp;
    *(this->bs + this->_Length1) = s;
    this->_Length1++;
    fileIn << s;
    fileIn.close();
    fileIn.open("Bacsi.txt", ios ::out);
    fileIn << this->_Length1 << endl;
    for (int i = 0; i < this->_Length1; i++)
    {
        (this->bs + i)->Inlaivaofile1(fileIn);
    }
    fileIn.close();
}
// tìm họ tên khi chỉ cần nhập tên/ họ
void Quanly::Search1()
{
    string s2;
    cout << "Nhap ho ten bac si tim kiem: ";
    cin.ignore();
    getline(cin, s2);
    cout << "\t---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t|  Ma so BS  |      Ho ten bac si         |  Gioi tinh  |   Nam sinh   |   So dien thoai   |      Chuyen khoa       |" << endl;
    cout << "\t---------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < this->_Length1; i++)
    {
        string s1 = (this->bs + i)->HotenBS1();
        if (s1.find(s2) != string::npos)
        {
            (this->bs + i)->Xuatmanhinh1();
            cout << "\t---------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
}

// update thông tin bác sĩ có mã số nhập vào là n
void Quanly ::Update1()
{
    cout << "\t\tDanh sach ma so cac bac si : ";
    for (int i = 0; i < this->_Length1; i++)
    {
        cout << "\n\t\t\t" << (this->bs + i)->MasoBS1();
    }
    cout << endl;
    cout << "\t\tNhap ma so bac si can sua thong tin: ";
    string n;
    cin.ignore();
    getline(cin, n);
    int index = -1;
    for (int i = 0; i < this->_Length1; i++)
    {
        if ((this->bs + i)->MasoBS1() == n)
        {
            index = i;
            break;
        }
    }
    if (index >= 0)
    {
        int choice;
        cout << endl
             << "\t1. Cap nhat ho ten bac si" << endl
             << "\t2. Cap nhat gioi tinh" << endl
             << "\t3. Cap nhat nam sinh" << endl
             << "\t4. Cap nhat so dien thoai" << endl
             << "\t5. Cap nhat chuyen khoa" << endl
             << "\tBan muon cap nhat thong tin gi?";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string g;
            cout << "\tHo ten bac si se duoc cap nhat lai: ";
            cin.ignore();
            getline(cin, g);
            (this->bs + index)->HotenBS1(g);
            ofstream fileIn;
            fileIn.open("Bacsi.txt", ios ::out);
            fileIn << this->_Length1 << endl;
            for (int i = 0; i < this->_Length1; i++)
            {
                (this->bs + i)->Inlaivaofile1(fileIn);
            }
            fileIn.close();
            cout << "\t\tCap nhat thanh cong!!";
            break;
        }
        case 2:
        {
            string g;
            cout << "\tGioi tinh se duoc cap nhat lai: ";
            cin.ignore();
            getline(cin, g);
            (this->bs + index)->Gioitinh1(g);
            ofstream fileIn;
            fileIn.open("Bacsi.txt", ios ::out);
            fileIn << this->_Length1 << endl;
            for (int i = 0; i < this->_Length1; i++)
            {
                (this->bs + i)->Inlaivaofile1(fileIn);
            }
            fileIn.close();
            cout << "\t\tCap nhat thanh cong!!";
            break;
        }
        case 3:
        {
            int g;
            cout << "\tNam sinh se duoc cap nhat lai: ";
            cin >> g;
            (this->bs + index)->Namsinh1(g);
            ofstream fileIn;
            fileIn.open("Bacsi.txt", ios ::out);
            fileIn << this->_Length1 << endl;
            for (int i = 0; i < this->_Length1; i++)
            {
                (this->bs + i)->Inlaivaofile1(fileIn);
            }
            fileIn.close();
            cout << "\t\tCap nhat thanh cong!!";
            break;
        }
        case 4:
        {
            string g;
            cout << "\tSo dien thoai se duoc cap nhat lai: ";
            cin.ignore();
            getline(cin, g);
            (this->bs + index)->SDT1(g);
            ofstream fileIn;
            fileIn.open("Bacsi.txt", ios ::out);
            fileIn << this->_Length1 << endl;
            for (int i = 0; i < this->_Length1; i++)
            {
                (this->bs + i)->Inlaivaofile1(fileIn);
            }
            fileIn.close();
            cout << "\t\tCap nhat thanh cong!!";
            break;
        }
        case 5:
        {
            string g;
            cout << "\tChuyen khoa se duoc cap nhat lai: ";
            cin.ignore();
            getline(cin, g);
            (this->bs + index)->Chuyenkhoa1(g);
            ofstream fileIn;
            fileIn.open("Bacsi.txt", ios ::out);
            fileIn << this->_Length1 << endl;
            for (int i = 0; i < this->_Length1; i++)
            {
                (this->bs + i)->Inlaivaofile1(fileIn);
            }
            fileIn.close();
            cout << "\t\tCap nhat thanh cong!!";
            break;
        }
        default:
            break;
        }
    }
    else
        cout << "\tKhong co thong tin nao phu hop voi yeu cau cua ban";
}

// xóa bác sĩ có mã số truyền vào
void Quanly ::Delete1()
{
    cout << "\t\tDanh sach ma so cac bac si : ";
    for (int i = 0; i < this->_Length1; i++)
    {
        cout << "\n\t\t\t" << (this->bs + i)->MasoBS1();
    }
    ofstream fileInn;
    fileInn.open("Bacsi.txt", ios_base::out);
    cout << "\n\tNhap ma so bac si can xoa khoi danh sach:  ";
    string n;
    cin.ignore();
    getline(cin, n);
    fileInn << this->_Length1 - 1 << endl;
    int index = -1;
    for (int i = 0; i < this->_Length1; i++)
    {
        if ((this->bs + i)->MasoBS1() == n)
        {
            index = i;
            break;
        }
    }
    if (index >= 0)
    {
        if (this->_Length1 == 1)
        {
            delete[] this->bs;
            this->bs = nullptr;
        }
        else
        {
            Bacsi *temp = new Bacsi[this->_Length1];
            for (int i = 0; i < this->_Length1; i++)
                *(temp + i) = *(this->bs + i);
            delete[] this->bs;
            this->bs = new Bacsi[this->_Length1];
            for (int i = 0; i < this->_Length1; i++)
            {
                if (index == i)
                {
                }
                else
                {
                    *(this->bs + i) = *(temp + i);
                    (this->bs + i)->Inlaivaofile1(fileInn);
                }
            }
        }
        cout << "\t\tXoa thanh cong!!!" << endl;
    }
    this->_Length1--;
    fileInn.close();
}
void Quanly ::Thongtinchitiet1()
{
    cout << "\t\tDanh sach ma so cac bac si : ";
    for (int i = 0; i < this->_Length1; i++)
    {
        cout << "\n\t\t\t" << (this->bs + i)->MasoBS1();
    }
    int check = 0;
    string m;
    cout << "\nNhap ma so bac si: ";
    cin.ignore();
    getline(cin, m);
    for (int i = 0; i < this->_Length1; i++)
    {
        if (m == (this->bs + i)->MasoBS1())
        {
            cout << "\t\t\t\t==================================================================" << endl;
            cout << "\t\t\t\t" << setw(18) << left << "| Ma so bac si: " << setw(47) << left << (this->bn + i)->MasoBN2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(23) << left << "| Ho va ten bac si : " << setw(42) << left << (this->bs + i)->HotenBS1() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(15) << left << "| Gioi tinh: " << setw(50) << left << (this->bs + i)->Gioitinh1() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(15) << left << "| Nam sinh: " << setw(50) << left << (this->bs + i)->Namsinh1() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(30) << left << "| So dien thoai lien lac: " << setw(35) << left << (this->bs + i)->SDT1() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(20) << left << "| Chuyen khoa: " << setw(45) << left << (this->bs + i)->Chuyenkhoa1() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(65) << left << "| Benh nhan dang phu trach: "
                 << "|" << endl;
            for (int j = 0; j < this->_Length2; j++)
            {
                if ((this->bn + j)->MasoBS2() == m)
                {
                    cout << "\t\t\t\t|                           + " << setw(35) << left << (this->bn + j)->HotenBN2() << "|" << endl;
                }
            }
            cout << "\t\t\t\t==================================================================" << endl;
            check = 1;
            break;
        }
    }
    if (check == 0)
        cout << "\t\tKhong co thong tin nao de hien thi";
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Quanly ::Menu2()
{
    ofstream fileOut;
    fileOut.open("ListBenhnhan.txt", ios_base ::out);
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    fileOut << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| Ma so BN |  Ho ten benh nhan    | CMND/Ho chieu | Gioi tinh | Nam sinh |      Dia chi           | So dien thoai  |   Ngay vao    |   Ten loai benh     |" << endl;
    fileOut << "| Ma so BN |  Ho ten benh nhan    | CMND/Ho chieu | Gioi tinh | Nam sinh |      Dia chi           | So dien thoai  |   Ngay vao    |   Ten loai benh     |" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    fileOut << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < this->_Length2; i++)
    {
        (this->bn + i)->Xuatmanhinh2();
        (this->bn + i)->Xuatfile2(fileOut);
    }
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    fileOut << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    fileOut.close();
}
void Quanly::Add2()
{
    int n;
    ofstream fileIn, fileO;
    fileIn.open("Benhnhan.txt", ios_base ::app);
    cout << " \tNhap thong tin benh nhan can them vao danh sach: ";
    Benhnhan s;
    cin >> s;
    Benhnhan *temp = new Benhnhan[this->_Length2];
    for (int i = 0; i < this->_Length2; i++)
        *(temp + i) = *(this->bn + i);
    delete[] this->bn;
    this->bn = new Benhnhan[this->_Length2 + 1];
    for (int i = 0; i < this->_Length2; i++)
        *(this->bn + i) = *(temp + i);
    delete[] temp;
    *(this->bn + this->_Length2) = s;
    this->_Length2++;
    // fileIn << s;
    fileIn.close();
    fileO.open("user.txt", ios_base ::app);
    fileIn.open("Benhnhan.txt", ios_base ::out);
    fileIn << this->_Length2 << endl;
    for (int i = 0; i < this->_Length2; i++)
    {
        (this->bn + i)->Inlaivaofile2(fileIn);
    }
    fileO << (this->bn + this->_Length2 - 1)->Cmnd2() << "," << (this->bn + this->_Length2 - 1)->MasoBN2() << endl;
    fileIn.close();
    fileO.close();
}
void Quanly::Search2()
{
    string s2;
    cout << "\tNhap ho ten benh nhan can tim kiem: ";
    cin.ignore();
    getline(cin, s2);
    int i;
    int check = 0;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| Ma so BN |  Ho ten benh nhan    | CMND/Ho chieu | Gioi tinh | Nam sinh |      Dia chi           | So dien thoai  |   Ngay vao    |   Ten loai benh     |" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (i = 0; i < this->_Length2; i++)
    {
        string s1 = (this->bn + i)->HotenBN2();
        if (s1.find(s2) != string::npos)
        {
            (this->bn + i)->Xuatmanhinh2();
            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
}
void Quanly ::Update2()
{
    cout << "\t\tDanh sach ma so cac benh nhan : ";
    for (int i = 0; i < this->_Length2; i++)
    {
        cout << "\n\t\t\t" << (this->bn + i)->MasoBN2();
    }
    cout << "\n\tNhap ma so benh nhan can sua thong tin: ";
    string n;
    cin.ignore();
    getline(cin, n);
    int index = -1;
    for (int i = 0; i < this->_Length2; i++)
    {
        if ((this->bn + i)->MasoBN2() == n)
        {
            index = i;
            break;
        }
    }
    if (index >= 0)
    {
        int choice;
        cout << endl
             << "\t1. Cap nhat ho ten benh nhan" << endl
             << "\t2. Cap nhat lai chung minh dan nhan" << endl
             << "\t3. Cap nhat gioi tinh" << endl
             << "\t4. Cap nhat nam sinh" << endl
             << "\t5. Cap nhat lai dia chi" << endl
             << "\t6. Cap nhat so dien thoai" << endl
             << "\t7. Cap nhat lai ten benh" << endl
             << "\t\tBan muon cap nhat thong tin gi?";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {

            string g;
            cout << "\tHo ten benh nhan se duoc cap nhat lai: ";
            cin.ignore();
            getline(cin, g);
            (this->bn + index)->HotenBN2(g);
            ofstream fileIn;
            fileIn.open("Benhnhan.txt", ios ::out);
            fileIn << this->_Length2 << endl;
            for (int i = 0; i < this->_Length2; i++)
            {
                (this->bn + i)->Inlaivaofile2(fileIn);
            }
            fileIn.close();
            cout << "\t\tCap nhat thanh cong!!";
            break;
        }
        case 2:
        {
            string g;
            cout << "\tChung minh nhan dan cap nhat lai:";
            cin.ignore();
            getline(cin, g);
            (this->bn + index)->Cmnd2(g);
            ofstream fileIn;
            fileIn.open("Benhnhan.txt", ios ::out);
            fileIn << this->_Length2 << endl;
            for (int i = 0; i < this->_Length2; i++)
            {
                (this->bn + i)->Inlaivaofile2(fileIn);
            }
            fileIn.close();
            cout << "\t\tCap nhat thanh cong!!";
            break;
        }
        case 3:
        {
            string g;
            cout << "\tGioi tinh se duoc cap nhat lai: ";
            cin.ignore();
            getline(cin, g);
            (this->bn + index)->Gioitinh2(g);
            ofstream fileIn;
            fileIn.open("Benhnhan.txt", ios ::out);
            fileIn << this->_Length2 << endl;
            for (int i = 0; i < this->_Length2; i++)
            {
                (this->bn + i)->Inlaivaofile2(fileIn);
            }
            fileIn.close();
            cout << "\t\tCap nhat thanh cong!!";
            break;
        }
        case 4:
        {
            int g;
            cout << "\tNam sinh se duoc cap nhat lai: ";
            cin >> g;
            (this->bn + index)->Namsinh2(g);
            ofstream fileIn;
            fileIn.open("Benhnhan.txt", ios ::out);
            fileIn << this->_Length2 << endl;
            for (int i = 0; i < this->_Length2; i++)
            {
                (this->bn + i)->Inlaivaofile2(fileIn);
            }
            fileIn.close();
            cout << "\t\tCap nhat thanh cong!!";
            break;
        }
        case 5:
        {
            string g;
            cout << "\tDia chi se cap nhat lai:";
            cin.ignore();
            getline(cin, g);
            (this->bn + index)->Diachi2(g);
            ofstream fileIn;
            fileIn.open("Benhnhan.txt", ios ::out);
            fileIn << this->_Length2 << endl;
            for (int i = 0; i < this->_Length2; i++)
            {
                (this->bn + i)->Inlaivaofile2(fileIn);
            }
            fileIn.close();
            cout << "\t\tCap nhat thanh cong!!";
            break;
        }
        case 6:
        {
            string g;
            cout << "\tSo dien thoai se duoc cap nhat lai: ";
            cin.ignore();
            getline(cin, g);
            // cin >> g;
            (this->bn + index)->SDT2(g);
            ofstream fileIn;
            fileIn.open("Benhnhan.txt", ios ::out);
            fileIn << this->_Length2 << endl;
            for (int i = 0; i < this->_Length2; i++)
            {
                (this->bn + i)->Inlaivaofile2(fileIn);
            }
            fileIn.close();
            cout << "\t\tCap nhat thanh cong!!";
            break;
        }
        case 7:
        {
            string g;
            cout << "\tTen benh se duoc cap nhat lai: ";
            cin.ignore();
            getline(cin, g);
            (this->bn + index)->Tenbenh2(g);
            ofstream fileIn;
            fileIn.open("Benhnhan.txt", ios ::out);
            fileIn << this->_Length2 << endl;
            for (int i = 0; i < this->_Length2; i++)
            {
                (this->bn + i)->Inlaivaofile2(fileIn);
            }
            fileIn.close();
            cout << "\t\tCap nhat thanh cong!!";
            break;
        }
        default:
            break;
        }
    }
    else
        cout << "\t\tKhong co thong tin nao phu hop voi yeu cau cua ban";
}
void Quanly ::Delete2()
{
    cout << "\t\tDanh sach ma so cac benh nhan : ";
    for (int i = 0; i < this->_Length2; i++)
    {
        cout << "\n\t\t\t" << (this->bn + i)->MasoBN2();
    }
    ofstream fileIn;
    fileIn.open("Benhnhan.txt", ios_base::out);
    cout << "\tNhap ma so benh nhan can xoa khoi danh sach:  ";
    string n;
    cin.ignore();
    getline(cin, n);
    fileIn << this->_Length2 - 1 << endl;
    int index = -1;
    for (int i = 0; i < this->_Length2; i++)
    {
        if ((this->bn + i)->MasoBN2() == n)
        {
            index = i;
            break;
        }
    }
    if (index >= 0)
    {
        if (this->_Length2 == 1)
        {
            delete[] this->bn;
            this->bn = nullptr;
        }
        else
        {
            Benhnhan *temp = new Benhnhan[this->_Length2];
            for (int i = 0; i < this->_Length2; i++)
                *(temp + i) = *(this->bn + i);
            delete[] this->bn;
            this->bn = new Benhnhan[this->_Length2];
            for (int i = 0; i < this->_Length2; i++)
            {
                if (index == i)
                {
                }
                else
                {
                    *(this->bn + i) = *(temp + i);
                    (this->bn + i)->Inlaivaofile2(fileIn);
                }
            }
        }
        cout << "\t\t\tXoa thanh cong!!!" << endl;
    }
    this->_Length2--;
    fileIn.close();
}
void Quanly ::Thongtinchitiet2()
{
    cout << "\t\tDanh sach ma so cac benh nhan : ";
    for (int i = 0; i < this->_Length2; i++)
    {
        cout << "\n\t\t\t" << (this->bn + i)->MasoBN2();
    }
    int temp = 0;
    string m;
    cout << "Nhap ma so benh nhan: ";
    cin.ignore();
    getline(cin, m);
    for (int i = 0; i < this->_Length2; i++)
    {
        if (m == (this->bn + i)->MasoBN2())
        {
            cout << "\t\t\t\t==================================================================" << endl;
            cout << "\t\t\t\t" << setw(20) << left << "| Ma so benh nhan: " << setw(45) << left << (this->bn + i)->MasoBN2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(20) << left << "| Ho ten benh nhan: " << setw(45) << left << (this->bn + i)->HotenBN2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(15) << left << "| Gioi tinh: " << setw(50) << left << (this->bn + i)->Gioitinh2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(15) << left << "| Nam sinh: " << setw(50) << left << (this->bn + i)->Namsinh2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(20) << left << "| So CMND/Ho chieu: " << setw(45) << left << (this->bn + i)->Cmnd2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(30) << left << "| So dien thoai lien lac: " << setw(35) << left << (this->bn + i)->SDT2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(20) << left << "| Dia chi lien he: " << setw(45) << left << (this->bn + i)->Diachi2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(15) << left << "| Ten benh: " << setw(50) << left << (this->bn + i)->Tenbenh2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(28) << left << "| Ho ten bac si chu tri: ";
            for (int j = 0; j < this->_Length2; j++)
            {
                if ((this->bs + j)->MasoBS1() == (this->bn + i)->MasoBS2())
                {
                    cout << setw(20) << left << (this->bs + j)->HotenBS1() << "(" << (this->bs + j)->MasoBS1() << setw(12) << left << ")"
                         << "|" << endl;
                }
            }
            cout << "\t\t\t\t==================================================================" << endl;
            temp = 1;
            break;
        }
    }
    if (temp == 0)
        cout << "\t\tKhong co benh nhan de hien thi";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// user bệnh nhân
// m là mã số bệnh nhân truyền vào, tương ứng với username
void Quanly ::Thongtinbanthan(string m)
{
    for (int i = 0; i < this->_Length2; i++)
    {
        if (m == (this->bn + i)->MasoBN2())
        {
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(12) << left << "| Ma so: " << setw(53) << left << (this->bn + i)->MasoBN2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(15) << left << "| Ho ten: " << setw(50) << left << (this->bn + i)->HotenBN2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(15) << left << "| Gioi tinh: " << setw(50) << left << (this->bn + i)->Gioitinh2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(15) << left << "| Nam sinh: " << setw(50) << left << (this->bn + i)->Namsinh2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(20) << left << "| So CMND/Ho chieu: " << setw(45) << left << (this->bn + i)->Cmnd2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(30) << left << "| So dien thoai lien lac: " << setw(35) << left << (this->bn + i)->SDT2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(20) << left << "| Dia chi lien he: " << setw(45) << left << (this->bn + i)->Diachi2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(15) << left << "| Ten benh: " << setw(50) << left << (this->bn + i)->Tenbenh2() << "|" << endl;
            cout << "\t\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t" << setw(27) << left << "| Ho ten bac si chu tri: ";
            for (int j = 0; j < this->_Length2; j++)
            {
                if ((this->bs + j)->MasoBS1() == (this->bn + i)->MasoBS2())
                {
                    cout << setw(20) << left << (this->bs + j)->HotenBS1() << " (" << setw(4) << left << (this->bs + j)->MasoBS1() << ")"
                         << setw(12) << right << "|";
                }
            }
            cout << "\n\t\t\t\t------------------------------------------------------------------" << endl;
            break;
        }
    }
}
void Quanly ::Thongtinbacsi(string m)
{
    for (int i = 0; i < this->_Length2; i++)
    {
        if (m == (this->bn + i)->MasoBN2())
        {
            for (int j = 0; j < this->_Length1; j++)
            {
                if ((this->bs + j)->MasoBS1() == (this->bn + i)->MasoBS2())
                {
                    cout << "\t\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t" << setw(20) << left << "| Ma so bac si : " << setw(45) << left << (this->bs + j)->MasoBS1() << "|" << endl;
                    cout << "\t\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t" << setw(25) << left << "| Ho va ten bac si : " << setw(40) << left << (this->bs + j)->HotenBS1() << "|" << endl;
                    cout << "\t\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t" << setw(15) << left << "| Gioi tinh: " << setw(50) << left << (this->bs + j)->Gioitinh1() << "|" << endl;
                    cout << "\t\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t" << setw(15) << left << "| Nam sinh: " << setw(50) << left << (this->bs + j)->Namsinh1() << "|" << endl;
                    cout << "\t\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t" << setw(20) << left << "| So dien thoai: " << setw(45) << left << (this->bs + j)->SDT1() << "|" << endl;
                    cout << "\t\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t" << setw(20) << left << "| Chuyen khoa: " << setw(45) << left << (this->bs + j)->Chuyenkhoa1() << "|" << endl;
                    cout << "\t\t\t\t------------------------------------------------------------------" << endl;
                    break;
                }
            }
            break;
        }
    }
}
void Quanly ::LichKham(string m)
{
    for (int i = 0; i < this->_Length2; i++)
    {
        if (m == (this->bn + i)->MasoBN2())
        {
            for (int j = 0; j < this->_Length3; j++)
            {
                if ((this->lk + j)->MasoBN3() == (this->bn + i)->MasoBN2())
                {
                    cout << "\t\t\t\t---------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t|          ++++++++++++ Lich hen kham ++++++++++++            | " << endl;
                    cout << "\t\t\t\t---------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t" << setw(10) << left << "|      -->" << setw(52) << left << (this->lk + j)->Phuongphap3() << "|" << endl;
                    cout << "\t\t\t\t" << setw(22) << left << "| Ngay kham benh: " << setw(40) << left << (this->lk + j)->Ngaykham3() << "|" << endl;
                    cout << "\t\t\t\t" << setw(18) << left << "| Trang thai: " << setw(44) << left << (this->lk + j)->Trangthai3() << "|" << endl;
                    cout << "\t\t\t\t---------------------------------------------------------------" << endl;
                }
            }
        }
    }
}
void Quanly ::Hoadon(string m)
{
    for (int i = 0; i < this->_Length2; i++)
    {
        if (m == (this->bn + i)->MasoBN2())
        {
            for (int j = 0; j < this->_Length3; j++)
            {
                if ((this->lk + j)->MasoBN3() == (this->bn + i)->MasoBN2())
                {
                    cout << "\t\t\t\t--------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t|              ++++++++++++ Chi phi ++++++++++++             | " << endl;
                    cout << "\t\t\t\t--------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t" << setw(18) << left << "| Kham benh : " << setw(42) << left << (this->lk + j)->CPkhambenh3() << " | " << endl;
                    cout << "\t\t\t\t" << setw(20) << left << "| Phau thuat : " << setw(40) << left << (this->lk + j)->CPphauthuat3() << " | " << endl;
                    cout << "\t\t\t\t" << setw(25) << left << "| Phong benh / ngay: " << setw(35) << left << (this->lk + j)->CPphongbenh3() << " | " << endl;
                    cout << "\t\t\t\t" << setw(13) << left << "| Thuoc: " << setw(47) << left << (this->lk + j)->Thuoc3() << " | " << endl;
                    // cout << "\t\t\t\t" << "Tong: " << (this->lk + j)->CPkhambenh3() + (this->lk + j)->CPphauthuat3() + (this->lk + j)->CPphongbenh3() + (this->lk + j)->Thuoc3() << endl;
                    cout << "\t\t\t\t--------------------------------------------------------------";
                }
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Quanly ::Tinhtuoi(int &m)
{
    int nCurYear(2021);
    time_t Time = time(0);
    struct tm Now;
    localtime_s(&Now, &Time);
    nCurYear = Now.tm_year + 1900;
    return (nCurYear - m);
}
void Quanly ::Tktuoi()
{
    int dem = 0;
    int t1, t2;
    cout << "\tBan muon thong ke tuoi tu bao nhieu den bao nhieu ?   ";
    cin >> t1 >> t2;
    cout << "\tDanh sach cac benh nhan co do tuoi tu " << t1 << " - " << t2 << ":" << endl;
    for (int i = 0; i < this->_Length2; i++)
    {
        int h = (this->bn + i)->Namsinh2();
        if (Tinhtuoi(h) >= t1 && Tinhtuoi(h) <= t2)
        {
            cout << "\t" << (this->bn + i)->HotenBN2() << endl;
            dem++;
        }
    }
    if (dem != 0)
        cout << "\t\tTong co " << dem << " benh nhan.";
    else
        cout << "\tKhong co benh nhan nao!!";
}
void Quanly ::Tkngayvao()
{
    int dem = 0;
    int th;
    cout << "\tBan muon thong ke benh nhan vao trong thang may?  ";
    cin >> th;
    for (int i = 0; i < this->_Length2; i++)
    {
        if ((this->bn + i)->thangv() == th)
        {
            cout << "\t\t+ " << (this->bn + i)->HotenBN2() << endl;
            dem++;
        }
    }
    cout << "\t\tTong co " << dem << " benh nhan.";
}
