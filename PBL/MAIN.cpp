#include <windows.h>
#include <stdlib.h>
#include "Quanly.h"
#include "login.h"
#include <string>
#include <iostream>
using namespace std;
void Giaodien();
void nhapuser();
void admin();              // chọn thao tác quản lí với bác sĩ hay bệnh nhân
int thaotac();             // quyen dang nhap admin
int thaotacbacsi();       // quyen dang nhap admin
int thaotacbenhnhan();    // quyen dang nhap admin
void mucluc1();            // tuong ung voi user admin quản lí bác sĩ
void mucluc2();            // tuong ung voi user admin quản lí bệnh nhân
void thaotaccuabenhnhan(); // quyen dang nhap cua benh nhan
void mucluc3();            // tuong ung voi user của bênh nhân do bênh nhân quản lí
void setColor(int backgound_color, int text_color);
void cls();
int k = 1;
int main()
{
     login lg;
     int n = 0;
     Giaodien();
     cout << endl;
     cls();
     nhapuser();
     cout << endl
          << "Chon tai khoan:";
     int a;
     cin >> a;
     system("cls");
     if (a == 1)
     {
          cout << endl
               << "Ban dang dang nhap voi tu cach admin." << endl;
          lg.loginad();
          cls();
          k = thaotac();
          if (k == 0)
               return 0;
     }
     else if (a == 2)
     {
          thaotaccuabenhnhan();
          cls();
     }
}
//------------------------------------------------------------------------------------------------------------------//
int thaotac()
{
     admin();
     cout << endl
          << "\tBan chon:  ";
     int z;
     cin >> z;
     system("cls");
     if (z == 1)
     {
          thaotacbacsi();
     }
     else if (z == 2)
     {
          thaotacbenhnhan();
     }
     else
     {
          cout << "Da dang xuat";
          return 0;
     }
}
int thaotacbacsi()
{
     Quanly ql;
     char b;
     do
     {
          mucluc1();
          cout << endl
               << "Chon thao tac muon thuc hien: ";
          int k;
          cin >> k;
          setColor(0, 6);
          switch (k)
          {
          case 1: // Xem danh sach bac si
               ql.Menu1();
               break;
          case 2: // Tim kiem thong tin bac si
               ql.Search1();
               break;
          case 3: // Them thong tin bac si vao danh sach
               ql.Add1();
               break;
          case 4: // Cập nhạt thông tin bac si
               ql.Update1();
               break;
          case 5: // Xóa thông tin bác si
               ql.Delete1();
               break;
          case 6: // Xem thông tin chi tiết của 1 bác sĩ
               ql.Thongtinchitiet1();
               break;
          case 7: // Quay lai
              system("cls");
              k = thaotac();
              if (k == 0)
                  return 0;
          }
          setColor(0, 3);
          cout << endl
               << "Ban co muon tiep tuc? (y/n) ";
          cin >> b;
          system("cls");
     } while (b == 'y');
}
//--------------------------------------------------------------------------------------------------------------------//
int thaotacbenhnhan()
{
     char b;
     Quanly ql;
     do
     {
          mucluc2();
          cout << endl
               << "Chon thao tac muon thuc hien: ";
          int k;
          cin >> k;
          setColor(0, 6);
          switch (k)
          {
          case 1: // Xem danh sách bệnh nhân
               ql.Menu2();
               getchar();
               break;
          case 2: // Tìm kiếm thông tin bênh nhân
               ql.Search2();
               break;
          case 3: // Thêm thông tin benh nhan vao danh sach
               ql.Add2();
               break;
          case 4: // Cập nhật thông tin bệnh nhân
               ql.Update2();
               break;
          case 5: // Xóa thông tin bệnh nhân
               ql.Delete2();
               break;
          case 6: // Xem thông tin chi tiết của 1 bệnh nhân
               ql.Thongtinchitiet2();
               break;
          case 7: // Thống kê
               int c;
               cout << "\t1.Thong ke tuoi cua benh nhan.\n\t2.Thong ke so benh nhan vao.\n\t\tBan chon: ";
               cin >> c;
               if (c == 1)
                    ql.Tktuoi();
               if (c == 2)
                    ql.Tkngayvao();
               break;
          case 8: // Quay lai
              system("cls");
              k = thaotac();
              if (k == 0)
                  return 0;
          }
          setColor(0, 3);
          cout << endl
               << "Ban co muon tiep tuc? (y/n) " << endl;
          cin >> b;
          system("cls");
     } while (b == 'y');
}
//--------------------------------------------------------------------------------------------------------------------//
void thaotaccuabenhnhan()
{
     string m;
     Quanly ql;
     login lg;
     cout << endl
          << "Ban dang dang nhap voi tu benh nhan." << endl;
     m = lg.loginbn(); //đăng nhập
     char b;
     system("cls");
     do
     {
          mucluc3();
          cout << endl
               << "Chon thao tac muon thuc hien:";
          int k;
          cin >> k;
          setColor(0, 6);
          switch (k)
          {
          case 1: // Xem thông tin của bản thân
               ql.Thongtinbanthan(m);
               break;
          case 2: // Xem thông tin bac si chủ trị
               ql.Thongtinbacsi(m);
               break;
          case 3: // Xem lịch hẹn khám
               ql.LichKham(m);
               break;
          case 4: // Xem hóa đơn cần thanh toán
               ql.Hoadon(m);
               break;
          }
          setColor(0, 3);
          cout << endl
               << "Ban co muon tiep tuc? (y/n)";
          cin >> b;
          cls();

     } while (b == 'y');
}
//-------------------------------------------------------------------------------------------------------------------------------------//
void Giaodien()
{
     setColor(0, 3);
     cout << endl
          << "\t\t\t========================================================================================";
     cout << endl
          << "\t\t\t|...                       DAI HOC BACH KHOA-DAI HOC DA NANG                        ...|";
     cout << endl
          << "\t\t\tx-----------------------------PBL2:DU AN CO SO LAP TRINH-------------------------------x";
     cout << endl
          << "\t\t\t|.           +++ Quan Li benh nhan voi mot so doi tuong dac trung ++++                .|";
     cout << endl
          << "\t\t\t|  Phuong phap:Thuat Toan DIJKSTRA               GV huong dan: PGS.TS Vo Duc Hoang     |";
     cout << endl
          << "\t\t\t|  Nguoi thuc hien:                              Ma so sinh vien:                      |";
     cout << endl
          << "\t\t\t|  1.Nguyen Thi Thu Thuyen                       102200156                             |";
     cout << endl
          << "\t\t\t|. 2.Dang Quang Nhat Linh                        102200177                            .|";
     cout << endl
          << "\t\t\t|..                                                                                  ..|";
     cout << endl
          << "\t\t\t|...                                                                                ...|";
     cout << endl
          << "\t\t\t========================================================================================";
}
//--------------------------------------------------------------------------------------------------------------------//
void setColor(int backgound_color, int text_color)
{
     HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

     int color_code = backgound_color * 16 + text_color;
     SetConsoleTextAttribute(hStdout, color_code);
}
//--------------------------------------------------------------------------------------------------------------------//
void nhapuser()
{
     setColor(0, 2);
     cout << endl
          << "\t\t\tx----------------------------PBL2:DU AN CO SO LAP TRINH---------------------------------x";
     cout << endl
          << "\t\t\t|.           ++++ Quan Li benh nhan voi mot so doi tuong dac trung ++++                .|";
     cout << endl
          << "\t\t\t|.                        ++++++++++ MUC LUC ++++++++++                                .|";
     cout << endl
          << "\t\t\tx--------------------------                          -----------------------------------x";
     cout << endl
          << "\t\t\t|                                                                                       |";
     cout << endl
          << "\t\t\t| 1.Dang nhap voi tu cach admin                                                         |";
     cout << endl
          << "\t\t\t| 2.Dang nhap voi tu cach benh nhan.                                                    |";
     cout << endl
          << "\t\t\t|                                                                                       |";
     cout << endl
          << "\t\t\t|---------------------------------------------------------------------------------------|";
}
//--------------------------------------------------------------------------------------------------------------------//
void admin()
{
     setColor(0, 3);
     cout << endl
          << "\t\t\tx----------------------------PBL2:DU AN CO SO LAP TRINH---------------------------------x";
     cout << endl
          << "\t\t\t|.           ++++ Quan Li benh nhan voi mot so doi tuong dac trung ++++                .|";
     cout << endl
          << "\t\t\t|.                        ++++++++++ MUC LUC ++++++++++                                .|";
     cout << endl
          << "\t\t\tx--------------------------                          -----------------------------------x";
     cout << endl
          << "\t\t\t|                                                                                       |";
     cout << endl
          << "\t\t\t| 1. Thao tac quan ly bac si.                                                           |";
     cout << endl
          << "\t\t\t| 2. Thao tac quan ly benh nhan.                                                        |";
     cout << endl
          << "\t\t\t| 3. Thoat.                                                                             |";
     cout << endl
          << "\t\t\t|                                                                                       |";
     cout << endl
          << "\t\t\t|---------------------------------------------------------------------------------------|";
}
//--------------------------------------------------------------------------------------------------------------------//
void mucluc1()
{
     setColor(0, 3);
     cout << endl
          << "\t\t\tx-----------------------------PBL2:DU AN CO SO LAP TRINH---------- ---------------------x";
     cout << endl
          << "\t\t\t|.           ++++ Quan Li benh nhan voi mot so doi tuong dac trung ++++                .|";
     cout << endl
          << "\t\t\t|.                      ++++++++++ MUC LUC ++++++++++                                  .|";
     cout << endl
          << "\t\t\t|.x--------------------------                         -----------------------------------x";
     cout << endl
          << "\t\t\t|1. Xuat ra danh sach bac si.                                                           |";
     cout << endl
          << "\t\t\t|2. Tim kiem thong tin cua mot bac si.                                                  |";
     cout << endl
          << "\t\t\t|3. Them thong tin bac si moi.                                                          |";
     cout << endl
          << "\t\t\t|4. Sua thong tin bac si.                                                               |";
     cout << endl
          << "\t\t\t|5. Xoa thong tin bac si.                                                               |";
     cout << endl
          << "\t\t\t|6. Xem thong tin chi tiet cua mot bac si bat ky.                                       |";
     cout << endl
          << "\t\t\t|7. Quay lai.                                                                           |";
     cout << endl
          << "\t\t\t----------------------------------------------------------------------------------------|";
}
//--------------------------------------------------------------------------------------------------------------------//
void mucluc2()
{
     setColor(0, 3);
     cout << endl
          << "\t\t\tx-----------------------------PBL2:DU AN CO SO LAP TRINH---------- ---------------------x";
     cout << endl
          << "\t\t\t|.           ++++ Quan Li benh nhan voi mot so doi tuong dac trung ++++                .|";
     cout << endl
          << "\t\t\t|.                      ++++++++++ MUC LUC ++++++++++                                  .|";
     cout << endl
          << "\t\t\tx--------------------------                          -----------------------------------x";
     cout << endl
          << "\t\t\t1. Xuat ra danh sach benh nhan.                                                         |";
     cout << endl
          << "\t\t\t2. Tim kiem thong tin cua mot benh nhan.                                                |";
     cout << endl
          << "\t\t\t3. Them thong tin benh nhan moi.                                                        |";
     cout << endl
          << "\t\t\t4. Sua thong tin benh nhan.                                                             |";
     cout << endl
          << "\t\t\t5. Xoa thong tin benh nhan.                                                             |";
     cout << endl
          << "\t\t\t6. Xem thong tin chi tiet cua mot benh nhan bat ky.                                     |";
     cout << endl
          << "\t\t\t7. Thong ke                                                                             |";
     cout << endl
          << "\t\t\t8. Quay lai                                                                             |";
     cout << endl
          << "\t\t\t----------------------------------------------------------------------------------------|";
}
//--------------------------------------------------------------------------------------------------------------------//
void mucluc3()
{
     setColor(0, 3);
     cout << endl
          << "\t\t\tx----------------------------PBL2:DU AN CO SO LAP TRINH---------------------------------x";
     cout << endl
          << "\t\t\t|.           ++++ Quan Li benh nhan voi mot so doi tuong dac trung ++++                .|";
     cout << endl
          << "\t\t\t|.                      ++++++++++ MUC LUC ++++++++++                                  .|";
     cout << endl
          << "\t\t\tx--------------------------                          -----------------------------------x";
     cout << endl
          << "\t\t\t1. Xem thong tin cua ban than.                                                          |";
     cout << endl
          << "\t\t\t2. Xem thong tin bac si chu tri.                                                        |";
     cout << endl
          << "\t\t\t3. Xem lich hen kham.                                                                   |";
     cout << endl
          << "\t\t\t4. Xem hoa don can thanh toan.                                                          |";
     cout << endl
          << "\t\t\t----------------------------------------------------------------------------------------|";
}
//--------------------------------------------------------------------------------------------------------------------//
void cls()
{
     getchar();
     system("cls");
}
//--------------------------------------------------------------------------------------------------------------------//
