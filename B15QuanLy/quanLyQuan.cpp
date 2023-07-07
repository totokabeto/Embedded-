#include <iostream>
#include <vector> 

using namespace std; 
typedef enum{
    QUAN_LY = 1,
    NHAN_VIEN,
}typeSelection;
class QuanLy {
    protected: 
    int id; 
    string tenMon; 
    int soBan;
    int price; 
    public: 
    vector<QuanLy> listFood;
    QuanLy(int id, string tenMon, int price); 
    QuanLy(); 
    void themMon(); 
    void setTen(string tenMon); 
    void setGia(int price);
    string getTenMon(); 
    int getGiaMon(); 
    void suaTenMon(int ID); 
    void suaGiaMon(int ID);  
    void xoaMon(); 
    void displayMon();
    void thietlapSoBan(int soBan); 
    int getSoBan();
    int getID();
    void setID(QuanLy a);
}; 
string QuanLy::getTenMon(){
    return QuanLy::tenMon;
}
int QuanLy::getGiaMon(){
    return QuanLy::price; 
}
void QuanLy::setID(QuanLy a){
    static int id = 100;
    QuanLy::id = id;
    id++;
}
int QuanLy::getID(){
    return QuanLy::id; 
}
QuanLy::QuanLy(int id, string tenMon, int price){
    QuanLy::id = id; 
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

    QuanLy newFood{id,tenMon,price}; 
    newFood.setID(newFood);
    listFood.push_back(newFood);
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
int QuanLy::getSoBan(){
    return QuanLy::soBan; 
}

void QuanLy::displayMon(){
    for (auto item : listFood){
        cout << "ID: " << item.id << endl; 
        cout << "Ten mon : " << item.tenMon << endl; 
        cout << "Gia " << item.price << endl;  
    }
}
void QuanLy::setTen(string tenMon){
    QuanLy::tenMon = tenMon; 
}
void QuanLy::setGia(int price){
    QuanLy::price = price; 
}
void QuanLy::suaTenMon(int ID){
        for(int i = 0; i <listFood.size(); i++)
    {
        if(listFood[i].id == ID){
            listFood[i].displayMon(); 
            string name; 
            cout << "Nhap ten can sua " << endl; 
            cin  >> name;  
            listFood[i].setTen(name);
            cout << "Sua ten thanh cong " << endl;   
        }else {
            cout <<"ID khong ton tai " << endl; 
        }
    }
}
void QuanLy::suaGiaMon(int ID){
        for(int i = 0; i <listFood.size(); i++)
    {
        if(listFood[i].id == ID){
            listFood[i].displayMon(); 
            int price; 
            cout << "Nhap gia can sua " << endl; 
            cin >> price; 
            listFood[i].setGia(price); 
            cout << "Sua gia thanh cong " << endl; 
        }else {
            cout <<"ID khong ton tai " << endl; 
        }
    }
}

class Order: public QuanLy{
    protected: 
    int id; 
    int soluong; 
    int soBan; 
    bool trangThai; 
    public:
    vector<Order> orderList; 
    Order(int id, int soluong, int soBan, bool trangThai);
    Order(); 
    int getIDMonTaiBan(); 
    int getSoLuong(); 
    bool getTrangThai(int soBan); 
    void themMonTaiBan(int soBan); 
    void suaMonTaiBan(int soBan); 
    void xoaMonTaiBan(int soBan); 
    void thanhToan(int soBan); 
    void hienThiDanhSachMonTaiBan(int soBan); 
    void setID(int ID); 
    void setSoLuong(int soLuong); 
    void setTrangThai(int soBan); 
    int getSoBanDangGoiMon(); 
    void xoaMonSaiID(int id);
}; 
Order::Order(){

}
Order::Order(int id, int soLuong, int soBan,bool trangThai){
    Order::id = id; 
    Order::soluong = soLuong;
    Order::soBan = soBan;
    Order::trangThai = trangThai; 
}
int Order::getSoBanDangGoiMon(){
    return Order::soBan; 
}
int Order::getIDMonTaiBan(){
    return Order::id;
}
int Order::getSoLuong(){
    return Order::soluong; 
}
void Order::setTrangThai(int soBan){
    Order::trangThai = true; 
}
bool Order::getTrangThai(int soBan){
    for(auto item : orderList){
        if(item.getSoBanDangGoiMon() == soBan){
            return item.trangThai; 
        }
    } 
    return false; 
}
void Order::setSoLuong(int soLuong){
    Order::soluong = soLuong; 
}
void Order::setID(int ID){
    Order::id = ID; 
}
void Order::themMonTaiBan(int soBan){
    int id; 
    cout << "Nhap id mon: " << endl; 
    cin >> id;
    int soLuong; 
    cout << "Nhap so luong mon: " << endl; 
    cin >> soLuong; 
    bool trangThai2 = true; 
    Order newMonTaiBan{id,soLuong,soBan,trangThai2}; 
    orderList.push_back(newMonTaiBan); 
}
void Order::xoaMonSaiID(int id){
    for (int i = 0; i < orderList.size(); i++)
    {
        if(orderList[i].id == id){
            orderList.erase(orderList.begin() + i);
        }
    }
    
}
void Order::suaMonTaiBan(int soBan){
    int id; 
    int soLuong; 
    cout << "Nhap id can sua " << endl; 
    cin >> id; 
    cout << "Nhap so luong mon can sua " << endl; 
    cin >> soLuong; 
    for(auto item : orderList){
        if(item.soBan == soBan){
            item.setID(id); 
            item.setSoLuong(soLuong); 
        }
    }
}
void Order::xoaMonTaiBan(int soBan){
    int id; 
    cout << "Nhap vao id mon can xoa " << endl; 
    cin >> id; 
    for (int i = 0; i < orderList.size(); i++){
        if (orderList[i].getSoBanDangGoiMon() == soBan){
            if(orderList[i].id == id){
                orderList.erase(orderList.begin() + i); 
                cout << "Da xoa mon thanh cong " << endl; 
            } else {
                cout << "Khong co id da nhap tai ban " << endl; 
            }
        } else { 
            cout << "Khong co so ban nhu tren " << endl; 
        }
    }
}
void Order::hienThiDanhSachMonTaiBan(int soBan){
    for (int i = 0; i < orderList.size(); i++)
    {   
        cout << "id mon " << orderList[i].getIDMonTaiBan() << endl; 
        cout << "so luong " << orderList[i].getSoLuong() << endl;
    }
    
}
void Order::thanhToan(int soBan){

}
int main(int argc, char const *argv[])
{   int input;
    QuanLy ql1; 
    Order order1; 
    while(1){
    L:
    cout << "Chuong trinh quan ly quan an " << endl; 
    cout << "1. Quan ly " << endl; 
    cout << "2. Nhan vien " << endl; 
    cout << "Nhap vao : " << endl; 
    cin >> input;
    switch (input)
    {
    case QUAN_LY:
        H: 
        int input2; 
        cout << "1.Them mon " << endl; 
        cout << "2.Sua mon " << endl; 
        cout << "3.Xoa mon " << endl; 
        cout << "4.Danh sach mon " << endl; 
        cout << "5.Thiet lap so ban " << endl; 
        cout << "0.Quay lai " << endl;
        cout << "Ban chon : " << endl; 
        cin >> input2; 
        switch (input2)
        {
        case 1:
            T: 
            ql1.themMon();
            int inputTieptuc; 
            cout << "1.Tiep tuc them mon " << endl; 
            cout << "0.Quay lai " << endl; 
            cout << "Ban chon : " << endl; 
            cin >> inputTieptuc; 
            switch (inputTieptuc)
            {
            case 1:
                goto T;
                break;
            case 2: 
                goto H;
                break; 
            default:
                break;
            }
            break;
        case 2:
            int idInput;
            int selectionInput; 
            cout << "Nhap vao id mon can sua " << endl; 
            cin >> idInput;
            cout << "1.Sua ten " << endl; 
            cout << "2.Sua gia " << endl; 
            cout << "0.Quay lai " << endl; 
            cout << "Ban chon : " << endl; 
            cin >> selectionInput; 
            switch (selectionInput)
            {
            case 1:
                ql1.suaTenMon(idInput);
                break;
            case 2: 
                ql1.suaGiaMon(idInput);
                break; 
            case 0: 
                goto L;
                break; 
            default:
                break;
            }
            break; 
        case 3: 
            ql1.xoaMon();
            break; 
        case 4: 
            ql1.displayMon();
            break; 
        case 5: 
            int soBanInput; 
            cout << "Nhap vao so ban co dinh trong quan :  " << endl; 
            cin >> soBanInput;
            ql1.thietlapSoBan(soBanInput);
            break; 
        case 0:
            goto L;
        default:
            break;
        }
        break;
    case NHAN_VIEN: 
        if(ql1.getSoBan() == 0){
            cout << "Vui long nhap so ban co dinh truoc khi cho khach hang goi mon tai ban " << endl; 
            goto L; 
        } else if(ql1.listFood.size() == 0){
            cout << "Vui long bo sung danh sach mon an truoc khi cho khach hang goi mon tai ban " << endl; 
            goto L; 
        }
        int soBan; 
        cout << "------------------Thong tin quan an va trang thai ban-----------------------------" << endl; 
        cout << "So ban duoc thiet lap " << ql1.getSoBan() <<  endl; 
        for(int i = 0; i < ql1.getSoBan(); i++){
        cout << "trang thai cua ban " << i + 1 << " la : " << order1.getTrangThai(i+1) << endl;
        }
        cout << "Nhap vao so ban can dat mon : " << endl; 
        cout << "0.Quay lai" << endl;
        cout << "Nhap vao so ban : " << endl; 
        cin >> soBan; 
        switch (soBan)
        {
        case 1:
            K: 
            int inputTaiBan; 
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
            A:
                ql1.displayMon(); 
                order1.themMonTaiBan(soBan);
                for (int i = 0; i < order1.orderList.size(); i++) 
                { 
                    for (int j = 0; j < ql1.listFood.size(); j++){
                    if( ql1.listFood[j].getID() == order1.orderList[i].getIDMonTaiBan()){
                           cout << "id co ton tai duoc phep tiep tuc " << endl; 
                            goto B; 
                        } 
                }
                    cout << "id nhap vao khong ton tai vui long nhap lai id " << endl; 
                    order1.xoaMonSaiID(order1.orderList[i].getIDMonTaiBan());
                    cout << "Da xoa id mon nhap sai " << endl; 
                    goto A; 
                }
                B:
                int inputTaiBan; 
                cout << "1.Tiep tuc them mon " << endl; 
                cout << "0.Quay lai " << endl;
                cout << "Ban chon : " << endl; 
                cin >> inputTaiBan;     
                switch (inputTaiBan)
                {
                case 1:
                    goto A; 
                    break;
                case 0: 
                    goto K; 
                    break; 
                default:
                    break;
                }
                break;
            case 2: 
                order1.hienThiDanhSachMonTaiBan(soBan);
                order1.suaMonTaiBan(soBan);
                break; 
            case 3: 
                order1.hienThiDanhSachMonTaiBan(soBan);
                order1.xoaMonTaiBan(soBan);
                break; 
            case 4: 
                order1.hienThiDanhSachMonTaiBan(soBan);
                for (int i = 0; i < ql1.listFood.size(); i++){
                    if(ql1.listFood[i].getID() == order1.orderList[i].getIDMonTaiBan()){
                        cout << "Ten mon :" << ql1.listFood[i].getTenMon() << endl; 
                        cout << "Gia tien : " << ql1.listFood[i].getGiaMon() << endl; 
                        continue;
                    }
                }
                break; 
            case 5: 
                //order1.thanhToan(soBan);
                int tongTien; 
                for(int i = 0; i < order1.orderList.size(); i++){
                    for(int j = 0; j < ql1.listFood.size(); j++){
                        if(order1.orderList[i].getIDMonTaiBan() == ql1.listFood[i].getID()){
                         tongTien += order1.orderList[i].getSoLuong() * ql1.listFood[i].getGiaMon();
                        }
                    }
                }
                cout << "Tong so tien can phai thanh toan cua ban " << soBan << " la : " << tongTien << " $" << endl;
                break; 
            case 0: 
                goto K; 
                break; 
            default:
                break;
            }
            break;
        case 2: 
            break; 
        case 3: 
            break; 
        case 0: 
            goto L;
            break; 
        default:
            break;
        }
        break; 
    default:
        break;
    }
    }
    return 0;
}
