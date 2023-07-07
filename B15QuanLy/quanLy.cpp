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
  
    void setTen(); 
    void setGia(); 
    public: 
    MonAn(uint8_t id, string name, int gia); 
    int setID(); 
    int getID(); 
    string getTen(); 
    double getGia(); 
    void getDanhSachMon();
}; 
void MonAn::getDanhSachMon(){
cout << "ID : " << (unsigned short)MonAn::ID << endl; 
cout << "Ten mon : " << MonAn::TEN << endl; 
cout << "Gia : "<< MonAn::gia << " $ " << endl; 
}
MonAn::MonAn(uint8_t id, string name, int gia){
    this->ID = id;
    this->TEN = name; 
    this->gia = gia; 
}
int MonAn::setID(){
    static int id = 100; 
    this->ID = id; 
    id++; 
    return MonAn::ID;
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

class QuanLy{
private: 
int SOBAN;
void themMon();
void suaMon();
void xoaMon(); 
void nhapSoBan();
public:
list<MonAn>DATABASE;
QuanLy();
list<MonAn> getDatabase();
int getSoBan(); 
void managerMenu();
void hienThiDanhSachMon();
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
        cout << "id : " << (unsigned short)item.getID() << endl; 
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

    MonAn newMon(newMon.setID(),name,gia); 
    DATABASE.push_back(newMon);
    cout << "Them mon thanh cong ! " << endl;  
}
void QuanLy::suaMon(){

    cout << "1.Sua ten " << endl; 
    cout << "2.Sua gia " << endl; 
    cout << "0.Quay lai " << endl; 
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
   
}
void QuanLy::managerMenu(){
     while(1){
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
}
class thongTinBan{
private: 
    int SO_BAN;
    bool TRANG_THAI;
    typedef struct{
        MonAn MON_AN; 
        int SO_LUONG; 
    }TypeMon; 
    list<TypeMon> DATABASE_MON_AN;
public:
    thongTinBan(int SO_BAN, bool TRANG_THAI); 
    int getSoBan(); 
    bool getTrangThai(); 
    void setTrangThai();
    void getDanhSachMon();
    void themMon(list<MonAn> database , thongTinBan a);
    void suaMon(int id, int SO_LUONG);
    void xoaMon(int id);

}; 
thongTinBan::thongTinBan(int SO_BAN, bool TRANG_THAI){
    this->SO_BAN = SO_BAN;
    this->TRANG_THAI = TRANG_THAI;
}
int thongTinBan::getSoBan(){
    return thongTinBan::SO_BAN; 
}
void thongTinBan::setTrangThai(){
    thongTinBan::TRANG_THAI = true; 
}
bool thongTinBan::getTrangThai(){
    return thongTinBan::TRANG_THAI; 
}
void thongTinBan::getDanhSachMon(){
    for(auto item : DATABASE_MON_AN){
        cout << "Ten mon : " << item.MON_AN.getTen() << endl; 
        cout << "So luong : " << item.SO_LUONG << endl; 
    }
}
void thongTinBan::xoaMon(int id){
    cout << "Nhap vao id " << endl; 
    cin >> id; 
    auto position = DATABASE_MON_AN.begin(); 
    for (auto item : DATABASE_MON_AN){
        if (item.MON_AN.getID() == id){
             DATABASE_MON_AN.erase(position); 
        } else {
            cout << "ID khong ton tai " << endl; 
            return;
        }
        position++; 
    }
}
void thongTinBan::themMon(list<MonAn> database, thongTinBan a){
    int id; 
    int soLuong;
    cout << "Nhap vao id mon can them : " << endl; 
    cin >> id; 
    for (auto item : database){
        if(item.getID() == id){
            cout << "ID co ton tai, tiep tuc nhap so luong mon " << endl; 
            cout << "Nhap vao so luong mon : " << endl; 
            cin >> soLuong; 
            TypeMon newMon{item,soLuong};
            DATABASE_MON_AN.push_back(newMon);
            cout << "Them mon tai ban thanh cong ! " << endl;  
            if (a.getTrangThai() == false){
                a.setTrangThai();
        } else { 
            cout << "ID khong ton tai " << endl;
            return;
        }
    }
}
}
void thongTinBan::suaMon(int id, int soLuong){
    cout << "Nhap vao id mon can sua  : " << endl;
    cin >> id; 
    for (auto item : DATABASE_MON_AN){
        if(item.MON_AN.getID() == id){
            cout << "Nhap vao so luong mon can thay doi : " << endl; 
            cin >> soLuong; 
            item.SO_LUONG = soLuong;
            cout << "Thay doi so luong mon thanh cong " << endl; 
        } else {
        cout << "ID khong ton tai ! " <<endl; 
        }
    } 
   

}
class NhanVien{
    private: 
    list<MonAn> DATABASE_MON_AN;
    list<thongTinBan> DATABASE_BAN;
    void hienThiThongTinBan(); 

    public: 
    NhanVien(list<MonAn> DATABASE_MON_AN, int SO_BAN);
    
}; 
NhanVien::NhanVien(list<MonAn> database, int SO_BAN){
    if(SO_BAN == 0 && DATABASE_MON_AN.size() == 0){
        cout << "Ban chua nhap danh sach mon an va setup so ban " << endl; 
        return;
    } 
    else
    {
    DATABASE_MON_AN.assign(database.begin(),database.end());
    for (int i = 1; i <= SO_BAN; i++)
    {
        thongTinBan ban(i,false); 
        DATABASE_BAN.push_back(ban); 
    }
    for (auto item : DATABASE_BAN){
        cout << "So ban : " << item.getSoBan() << endl;
        cout << "Trang thai:  " << item.getTrangThai() << endl; 
    }
    int soBanGoiMon; 
    cout << "Nhap vao so ban muon goi mon " << endl; 
    cin >> soBanGoiMon; 
    for (auto item : DATABASE_BAN){
        if (soBanGoiMon == item.getSoBan()){
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
                item.themMon(database, item); 
                break;
            case 2: 
                for (auto item_Mon : database){
                    item_Mon.getDanhSachMon(); 
                } 
                break;
            case 3: 
                int id3; 
                item.xoaMon(id3);
                break;
            case 4: 
                item.getDanhSachMon(); 
                break; 
            case 5: 
                break; 
            case 0: 
                return; 
            default:
                break;
            }
        } else { 
            cout << "So ban ko hop le " << endl; 
            return; 
        }
    }
}
}
int main(int argc, char const *argv[])
{   QuanLy ql1;
    while(true){
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
        
        NhanVien nv1{ql1.getDatabase(),ql1.getSoBan()};

        break;
    }
    default: 
        break;
    }
    }
    return 0;
}

