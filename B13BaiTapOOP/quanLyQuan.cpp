#include <iostream>
#include <vector> 

using namespace std; 
class QuanLy {
    private: 
    static int id; 
    string tenMon; 
    int soBan;
    int price; 
    vector<QuanLy> listFood; 
    public: 
    QuanLy(string tenMon, int price); 
    QuanLy(); 
    void setTen(string tenMon); 
    void setGia(int price); 
    void themMon(); 
    void suaMon(int ID); 
    void xoaMon(); 
    void displayMon();
    void thietlapSoBan(int soBan); 
}; 

int QuanLy::id = 100; 
QuanLy::QuanLy(string tenMon, int price){
    QuanLy::tenMon = tenMon;
    QuanLy::price = price; 
}
QuanLy::QuanLy(){

}
void QuanLy::themMon(){
    string tenMon; 
    cout << "Nhap ten mon can them " << endl; 
    cin >> tenMon; 
    int price; 
    cout << "Nhap gia : " << endl; 
    cin >> price; 
    QuanLy newFood{tenMon,price}; 
    listFood.push_back(newFood);
    QuanLy::id++; 
}

void QuanLy::xoaMon(){
    string tenMon; 
    cout << "Nhap vao ten mon can xoa " << endl; 
    cin >> tenMon;
    for (int i = 0; i < listFood.size(); i++){
        if(listFood[i].tenMon == tenMon){
            listFood.erase(listFood.begin()+i); 
        } else {
            cout << "Khong co ten mon trung khop de xoa " << endl; 
        }
    }
}
void QuanLy::thietlapSoBan(int soBan){
QuanLy::soBan = soBan; 
}

void QuanLy::displayMon(){
    for (auto item : listFood){
        cout << "ID: " << item.id << endl; 
        cout << "Ten mon : " << item.tenMon << endl; 
        cout << "Gia " << item.price << endl; 
        cout << "So ban da thiet lap " << item.soBan << endl; 
    }
}
void QuanLy::setTen(string tenMon){
    QuanLy::tenMon = tenMon; 
}
void QuanLy::setGia(int price){
    QuanLy::price = price; 
}
void QuanLy::suaMon(int ID){
    for(int i = 0; i <listFood.size(); i++)
    {
        if(listFood[i].id == ID){
            listFood[i].displayMon(); 
            string name; 
            cout << "Nhap ten can sua " << endl; 
            cin  >> name; 
            int price; 
            cout << "Nhap gia can sua " << endl; 
            cin >> price; 
            listFood[i].setTen(name);
            listFood[i].setGia(price); 
        }
    }
}

class NhanVien: public QuanLy{
    private: 
    uint8_t soBan; 
    vector<QuanLy> ban1; 
    vector<QuanLy> ban2;  
    bool trangThai; 
    public:
    void themMon(); 
    void suaMon(); 
    void xoaMon(); 
    void thanhToan(); 
}; 
int main(int argc, char const *argv[])
{  /* uint8_t input; 
    cout << "Chuong trinh quan ly quan an " << endl; 
    cout << "1. Quan ly " << endl; 
    cout << "2. Nhan vien " << endl; 
    cout << "Nhap vao : " << endl; 
    cin >> input; */
    QuanLy mon1; 
    QuanLy mon2;
    mon1.themMon();
    mon1.displayMon(); 
    return 0;
}
