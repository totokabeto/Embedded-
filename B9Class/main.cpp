#include <iostream>

using namespace std; 

class SinhVien
{ 
public: 
    //SinhVien(int lop, int tuoi); // constructor có input parameters 
    void themThongTin(int lop, int tuoi);
    void hienThi(); 
protected:
    static int bhyt; 
    int lop; 
    int tuoi; 
};
    int SinhVien::bhyt = 10; 
/*SinhVien::SinhVien(int lop, int tuoi){
    SinhVien::lop = lop; 
    SinhVien::tuoi = tuoi; 
}*/
void SinhVien::hienThi(){
cout << "Sinh vien nay thuoc lop " << SinhVien::lop << endl;
cout << "Tuoi : " << SinhVien::tuoi << endl; 
}
void SinhVien::themThongTin(int lop, int tuoi){
    SinhVien::lop = lop; 
    SinhVien::tuoi = tuoi; 
}

class DoiTuong: public SinhVien {
public: 
//nap chong phuong thuc 
    
    void themThongTin(int lop, int tuoi, int mssv, string ten); 
    void hienThi();
private: 
    int mssv; 
    string ten; 
};

void DoiTuong::themThongTin(int lop, int tuoi, int mssv, string ten){
SinhVien::lop = lop; 
SinhVien::tuoi = tuoi; 
DoiTuong::mssv = mssv; 
DoiTuong::ten = ten; 
}

void DoiTuong::hienThi(){
    cout << "Day la class doi tuong " << endl; 
    cout << "Sinh vien nay thuoc lop " << SinhVien::lop << endl;
    cout << "Tuoi : " << SinhVien::tuoi << endl;
    cout << "Mssv : " << DoiTuong::mssv<<endl; 
    cout << "ten : " << DoiTuong ::ten <<endl; 
}
int main(int argc, char const *argv[])
{
    
    DoiTuong hocSinh1;
    hocSinh1.themThongTin(7,14,1001,"Cu Chinh Lan");
    hocSinh1.hienThi();

    DoiTuong hocSinh2; 

    cout << "dia chi hoc sinh 1: " << &hocSinh1 << endl; 
    cout << "dia chi hoc sinh 2: " << &hocSinh2 << endl; 

    return 0;
}
