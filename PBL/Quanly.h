#include"Bacsi.h"
#include"Benhnhan.h"
#include "LKCP.h"
using namespace std;
class Quanly
{
    private:
        Bacsi *bs;
        int _Length1;
        Benhnhan *bn;
        int _Length2;
        LKCP *lk;
        int _Length3;
    public:
        Quanly();
        ~Quanly();
        void Menu1();
        void Add1();
        void Search1();
        int search(const string, string);
        void Update1();
        void Delete1();
        void Thongtinchitiet1();
        void Menu2();
        void Add2();
        void Search2();
        void Update2();
        void Delete2();
        void Thongtinchitiet2();
        void Thongtinbanthan(string);
        void Thongtinbacsi(string);
        void LichKham(string);
        void Hoadon(string);
        int Tinhtuoi(int &);
        void Tktuoi();
        void Tkngayvao();
        
};