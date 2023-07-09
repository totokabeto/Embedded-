#include <iostream> 
#include <list> 

using namespace std; 
typedef enum{
    QUAN_LY = 1,
    NHAN_VIEN, 
}TypeSelection;

class MonAn{
    private: 
    uint8_t ID; 
    string TEN;
    double gia;
    public: 
    MonAn(string name, int gia); 
    MonAn(); 
    int getID(); 
    string getTen(); 
    double getGia(); 
    void getDanhSachMon();
    void setTen(string name); 
    void setGia(double price); 
}; 
MonAn::MonAn(){
}
void MonAn::getDanhSachMon(){
cout << "ID : " << (unsigned short)MonAn::ID << endl; 
cout << "Ten mon : " << MonAn::TEN << endl; 
cout << "Gia : "<< MonAn::gia << " $ " << endl; 
}
MonAn::MonAn(string name, int gia){
    static int id = 100; 
    this->ID = id; 
    id++; 
    this->TEN = name; 
    this->gia = gia; 
}
int MonAn::getID(){
    return this->ID;
}
string MonAn::getTen(){
    return MonAn::TEN; 
}
double MonAn::getGia(){
    return MonAn::gia; 
}
void MonAn::setTen(string name){
    MonAn::TEN = name; 
}
void MonAn::setGia(double gia){
    MonAn::gia = gia; 
}

class QuanLy{
private: 
int SOBAN;
void themMon();
void suaMon();
void xoaMon(); 
void nhapSoBan();
void hienThiDanhSachMon();
public:
QuanLy();
list<MonAn> DATABASE;
list<MonAn> getDatabase();
int getSoBan(); 
void managerMenu();
}; 
list<MonAn> QuanLy::getDatabase(){
    return this->DATABASE; 
}
void QuanLy::nhapSoBan(){
    int soBan; 
    cout << "Nhap vao so ban co dinh : " <<endl; 
    cin >> soBan;
    QuanLy::SOBAN = soBan;
}
int QuanLy::getSoBan(){
    return this->SOBAN; 
}
void QuanLy::hienThiDanhSachMon(){
    for(auto item : DATABASE){
        cout << "id : " << item.getID() << endl; 
        cout << "ten mon : " << item.getTen() << endl; 
        cout << "gia : " << item.getGia() << endl; 
    }
}
void QuanLy::themMon(){
    string name; 
    double gia; 
    cout << "Nhap vao ten mon an moi " << endl; 
    cin >> name; 
    cout << "Nhap gia mon an moi : " << endl; 
    cin >> gia; 
    MonAn newMon(name,gia); 
    DATABASE.push_back(newMon);
    cout << "Them mon thanh cong ! " << endl;
    int keyInput;   
    cout << "1. Tiep tuc them mon " << endl; 
    cout << "2. Quay lai " << endl; 
    cin >> keyInput;
    switch (keyInput)
    {
    case 1:
        themMon();
        break;
    case 2: 
        managerMenu();
        break; 
    default:
        break;
    }
}
void QuanLy::suaMon(){
    int id; 
    int keyInput; 
    string name; 
    double price;
    cout << "1.Sua ten " << endl; 
    cout << "2.Sua gia " << endl; 
    cout << "0.Quay lai " << endl; 
    cout << "Ban chon : " << endl; 
    cin >> keyInput; 
    switch (keyInput)
    {
    case 1:
        hienThiDanhSachMon(); 
        cout << "Nhap vao id mon can sua ten " << endl;
        cin >> id;
        for(auto &item : DATABASE){
            if(item.getID() == id){
                cout << "Nhap vao ten mon moi " << endl; 
                cin >> name; 
                item.setTen(name);
                cout << "da thay doi ten thanh cong " << endl; 
                managerMenu(); 
            } 
        }
        break;
    case 2: 
        hienThiDanhSachMon(); 
        cout << "Nhap vao id mon can sua ten " << endl;
        cin >> id;
        for(auto &item : DATABASE){
            if(item.getID() == id){
                cout << "Nhap vao gia moi " << endl; 
                cin >> price; 
                item.setGia(price);
                cout << "da thay doi gia thanh cong " << endl; 
                managerMenu(); 
            } 
        }
        cout << "Id nhap vao khong ton tai" << endl; 
        return; 
        break; 
    default:
        break;
    }
}
void QuanLy::xoaMon(){
    int id; 
    cout << "Nhap vao id mon can xoa " << endl; 
    cin >> id; 
    auto position = DATABASE.begin(); 
    for (auto item : DATABASE){
        if (item.getID() == id){
            DATABASE.erase(position); 
        }
        position++;
    }
}
QuanLy::QuanLy(){
   this->SOBAN = 0; 
}
void QuanLy::managerMenu(){
    int keyInput; 
        cout << "1.Them mon " << endl; 
        cout << "2.Sua mon " << endl; 
        cout << "3.Xoa mon " << endl; 
        cout << "4.Danh sach mon " << endl; 
        cout << "5.Thiet lap so ban " << endl; 
        cout << "0.Quay lai " << endl;
        cout << "Ban chon : " << endl; 
        cin >> keyInput;
    switch (keyInput)
    {
    case 1:
        themMon();
        break;
    case 2: 
        suaMon(); 
        break; 
    case 3: 
        xoaMon(); 
        break; 
    case 4: 
        hienThiDanhSachMon(); 
        break; 
    case 5: 
        nhapSoBan(); 
        break; 
    case 0: 
        return; 
    default:
        break;
    }
}
class thongTinBan{
private:  
    int SO_BAN;
    bool TRANG_THAI;
    MonAn MON_AN; 
    int SO_LUONG; 
public:
    thongTinBan(int SO_BAN, bool TRANG_THAI , MonAn Mon, int soLuong); 
    thongTinBan(int SO_BAN, bool TRANG_THAI);
    void setSoLuong(int soLuong);
    int getSoBan(); 
    bool getTrangThai();
    int getSoLuong();  
    void setTrangThai();
    int getIDMon();
    string getTenMon(); 
    double getGiaMon(); 
    int getSoLuongBan(); 

}; 
thongTinBan::thongTinBan(int SO_BAN, bool TRANG_THAI){
    this->SO_BAN = SO_BAN;
    this->TRANG_THAI = TRANG_THAI;
}
void thongTinBan::setSoLuong(int soLuong){
    thongTinBan::SO_LUONG = soLuong;
}
int thongTinBan::getSoLuong(){
    return thongTinBan::SO_LUONG;
}
int thongTinBan::getIDMon(){
    return MON_AN.getID();
}
string thongTinBan::getTenMon(){
    return MON_AN.getTen(); 
}
double thongTinBan::getGiaMon(){
    return MON_AN.getGia(); 
}
thongTinBan::thongTinBan(int SO_BAN, bool TRANG_THAI, MonAn Mon, int soLuong){
    thongTinBan::SO_BAN = SO_BAN;
    thongTinBan::TRANG_THAI = TRANG_THAI;
    thongTinBan::MON_AN = Mon; 
    thongTinBan::SO_LUONG = soLuong;
}
int thongTinBan::getSoBan(){
    return thongTinBan::SO_BAN; 
}
void thongTinBan::setTrangThai(){
    this->TRANG_THAI = !this->TRANG_THAI; 
}
bool thongTinBan::getTrangThai(){
    return thongTinBan::TRANG_THAI; 
}
class NhanVien{
    private: 
    list<MonAn> DATABASE_MON_AN;
    list<thongTinBan> DATABASE_MON_AN_TAI_BAN;
    list<thongTinBan> DATABASE_INFO; 
    void themMon(list<MonAn> database , thongTinBan &a);
    void suaMon();
    void xoaMon();
    void thanhToan(thongTinBan &a); 
    public: 
    NhanVien();
    NhanVien(list<MonAn> DATABASE_MON_AN, int SO_BAN);
    void nhanVienMenu(list<MonAn> DATABASE_MON_AN, int SO_BAN);
    void getDanhSachMon();
    void hienThiThongTinBan(thongTinBan &a);
 
}; 
NhanVien::NhanVien(){

}
void NhanVien::hienThiThongTinBan(thongTinBan &a){
    cout << "Thong tin ban so : " << a.getSoBan() << endl; 
    for (auto item : DATABASE_INFO){
        if (item.getSoBan() == a.getSoBan()){
                cout << " Ten mon da goi : " << item.getTenMon() << endl; 
                cout << " So luong : " << item.getSoLuong() << endl; 
        }
    }
}
void NhanVien::thanhToan(thongTinBan &a){
    cout << "Thanh toan ban so " << a.getSoBan() << endl; 
    double TongTien = 0; 
    for(auto item : DATABASE_INFO){
        if (item.getSoBan() == a.getSoBan()){
        TongTien += item.getSoLuong() * item.getGiaMon();
        }
    }
    cout << "Tong so tien cua ban nay la : " << TongTien << " $ " << endl; 
}
void NhanVien::getDanhSachMon(){
    if(DATABASE_INFO.size() == 0){
        cout << "Danh sach mon tai ban nay rong " <<endl; 
    } else{
    for(auto item : DATABASE_INFO){
        cout << "Ten mon : " << item.getTenMon() << endl; 
        cout << "So luong : " << item.getSoLuong() << endl; 
    }
    }
}
void NhanVien::xoaMon(){
    int id; 
    cout << "Nhap vao id " << endl; 
    cin >> id; 
    auto position = DATABASE_INFO.begin(); 
    for (auto &item : DATABASE_INFO){
        if (item.getIDMon() == id){
             DATABASE_INFO.erase(position); 
             cout << "da xoa mon an thanh cong " << endl; 
             return; 
        }
        position++; 
    }
    cout  << "Id ko ton tai " << endl; 
    return; 
}
void NhanVien::themMon(list<MonAn> database, thongTinBan &a){
    L: 
    int id; 
    int soLuong;
    cout << "Nhap vao id mon can them : " << endl; 
    cin >> id; 
    for (auto item : database){
        if(item.getID() == id){
            cout << "ID co ton tai, tiep tuc nhap so luong mon " << endl; 
            cout << "Nhap vao so luong mon : " << endl; 
            cin >> soLuong; 
            thongTinBan newMonTaiBAN(a.getSoBan(),true,item,soLuong);
            DATABASE_INFO.push_back(newMonTaiBAN);
            a.setTrangThai();
            cout << "Them mon tai ban thanh cong ! " << endl;
        //     for (auto &item : DATABASE_MON_AN_TAI_BAN){
        //     if (item.getSoBan() == a.getSoBan()){
        //         item.setTrangThai();
        //       }
        //  }
            int keyInput; 
            cout << "1.Tiep tuc them mon " << endl; 
            cout << "2.Quay lai " << endl; 
            cin >> keyInput; 
            switch (keyInput)
            {
            case 1:
                goto L; 
                break;
            case 2 : 
                nhanVienMenu(database,DATABASE_MON_AN_TAI_BAN.size()); 
                break; 
            default:
                break;
            }
        }
    }
            cout << "ID khong ton tai " << endl;
            return;
}
void NhanVien::suaMon(){
    int id; 
    int soLuong; 
    cout << "Nhap vao id mon can sua  : " << endl;
    cin >> id; 
    for (auto &item : DATABASE_INFO){
        if(item.getIDMon() == id){
            cout << "Nhap vao so luong mon can thay doi : " << endl; 
            cin >> soLuong; 
            item.setSoLuong(soLuong);// method set so luong; 
            cout << "Thay doi so luong mon thanh cong " << endl; 
            return; 
        } 
    } 
    cout << "ID khong ton tai ! " <<endl; 
    return; 
}
NhanVien::NhanVien(list<MonAn> database, int SO_BAN){

}
void NhanVien::nhanVienMenu(list<MonAn> database, int SO_BAN){
    if(SO_BAN != 0 && database.size() != 0) {
          if(DATABASE_MON_AN.size() == 0){
        for (int i = 1; i <= SO_BAN; i++){   
        cout << "da khoi tao so ban " << endl;
        thongTinBan ban{i,false}; 
        DATABASE_MON_AN_TAI_BAN.push_back(ban);
        }
        DATABASE_MON_AN.assign(database.begin(),database.end());
    } 
    for (auto item : DATABASE_MON_AN_TAI_BAN){
        cout << "data mon an tai ban " << endl; 
        cout << "So ban : " << item.getSoBan() << endl;
        cout << "Trang thai:  " << item.getTrangThai() << endl;
    }
    cout << "Tinh trang------------------------------" << endl; 
    for (auto item : DATABASE_INFO){
         cout << "So ban : " << item.getSoBan() << endl;
        cout << "Trang thai:  " << item.getTrangThai() << endl;
    }
    while(1)
    {
    int soBanGoiMon; 
    cout << "Nhap vao so ban muon goi mon " << endl; 
    cin >> soBanGoiMon; 
    for (auto &item : DATABASE_MON_AN_TAI_BAN){
        if (item.getSoBan() == soBanGoiMon){
            cout << "Nhap lua chon ban muon thuc hien voi ban : " << item.getSoBan() << endl;
            int inputTaiBan; 
            cout << "----------------------------------------Menu Nhan Vien ----------------------------------------" << endl; 
            cout << "1.Them mon tai ban " << endl; 
            cout << "2.Sua mon tai ban " <<endl; 
            cout << "3.Xoa mon tai ban " << endl; 
            cout << "4.Danh sach mon tai ban " << endl; 
            cout << "5.Thanh toan " << endl; 
            cout << "0.Quay lai " << endl;
            cout << "Ban chon : " << endl; 
            cin >> inputTaiBan; 
            switch (inputTaiBan)
            {
            case 1:
                for (auto item_Mon : database){
                    item_Mon.getDanhSachMon(); 
                }
                themMon(database, item); 
                break;
            case 2: 
                hienThiThongTinBan(item);
                suaMon();
                break;
            case 3: 
                hienThiThongTinBan(item);
                xoaMon();
                break;
            case 4: 
                hienThiThongTinBan(item); 
                break; 
            case 5: 
                thanhToan(item); 
                break; 
            case 0: 
                break; 
            default:
                break;
            }
        } 
    }
    cout << "So ban ko hop le " << endl; 
    return; 
}    
    }
    else {   
         cout << "Ban chua nhap danh sach mon an va setup so ban " << endl; 
        return; 
}
    }
void run(){
    QuanLy ql1;
    NhanVien nv1;
    while(1){
    int keyInput = 0;
    cout << "Chuong trinh quan ly quan an " << endl; 
    cout << "1. Quan ly " << endl; 
    cout << "2. Nhan vien " << endl; 
    cout << "Nhap vao : " << endl; 
    cin >> keyInput; 
    switch ((TypeSelection)keyInput)
    {
    case QUAN_LY:
    {
        ql1.managerMenu();
        break;
    } 
    case NHAN_VIEN:{
        nv1.nhanVienMenu(ql1.getDatabase(),ql1.getSoBan());
        break;
    }
    default: 
        break;
    }
    }
}
int main(int argc, char const *argv[])
{   run();
    return 0;
}
