#include "login.h"
#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
// user của admin
void login ::loginad()
{
    ifstream file;
    file.open("admin.txt");
    getline(file, this->user, ',');
    getline(file, this->pass, '\n');
    cout << " Enter username : ";
    cin >> this->username;
    if (this->username == this->user)
    {
        cout << " Enter your password: ";
        getpassword();
        while (password != this->pass)
        {
            cout << " Password incorrect!!!" << endl;
            cout << " Enter your password: ";
            getpassword();
        }
        cout << " Login sucessfully";
    }
    else
    {
        cout << " Username incorrect!!!" << endl;
        loginad();
    }
    file.close();
}
// user của bệnh nhân mỗi bệnh nhân có 1 tài khoản
// với username là mã số bệnh nhân
// password là họ tên bệnh nhân
string login ::loginbn()
{
    string temp;
    ifstream file, fileIn;
    file.open("user.txt", ios_base ::in);
    fileIn.open("Benhnhan.txt", ios_base ::in);
    getline(fileIn, temp, '\n');
    int length = atoi(temp.c_str());
    this->user1 = new string[length];
    this->pass1 = new string[length];
    for (int i = 0; i < length; i++)
    {
        getline(file, *(this->user1 + i), ',');
        getline(file, *(this->pass1 + i), '\n');
    }
    cout << " Enter username : ";
    cin >> this->username;
    for (int j = 0; j < length; j++)
    {
        if (this->username == *(this->user1 + j))
        {
            cout << " Enter your password: ";
            getpassword();
            while (this->password != *(this->pass1 + j))
            {
                cout << " Password incorrect!!!" << endl;
                cout << " Enter your password: ";
                getpassword();
            }
            cout << " Login sucessfully";
            return this->password;
        }
    }
    cout << " Username incorrect!!!" << endl;
    loginbn();
    file.close();
    fileIn.close();
}
string login ::getpassword()
{
    this->password = "";
    char ch;
    while ((ch = _getch()) != 13)
    {
        if (ch == 8)
        {
            if (this->password.length() > 0)
            {
                cout << "\b \b";
                this->password.resize(this->password.length() - 1);
            }
        }
        else
        {
            this->password += ch;
            cout << "*";
        }
    }
    cout << endl;
    return this->password;
}
