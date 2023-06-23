#include <iostream> 

using namespace std; 
class phanSo{
    private: 
    int tuSo; 
    int mauSo; 
    public: 
    phanSo(int tuSo, int mauSo);
    phanSo();
    void tong2Phanso(phanSo A, phanSo B);
    void hieu2Phanso(phanSo A, phanSo B);
    void tich2Phanso(phanSo A, phanSo B);
    void thuong2Phanso(phanSo A, phanSo B);
    void rutGon2PhanSo(phanSo A);
};
    phanSo::phanSo(){

    }
    phanSo::phanSo(int tuSo, int mauSo){
        phanSo::tuSo = tuSo; 
        phanSo::mauSo = mauSo; 
    }
void phanSo::tong2Phanso(phanSo A, phanSo B){
    phanSo C; 
    C.mauSo = A.mauSo*B.mauSo; 
    C.tuSo = A.tuSo*B.mauSo + B.tuSo*B.tuSo; 

    cout << "Tong 2 phan so la : " << C.tuSo << "/" << C.mauSo << endl; 
}

void phanSo::hieu2Phanso(phanSo A, phanSo B){
    phanSo C; 
    C.mauSo = A.mauSo*B.mauSo; 
    C.tuSo = A.tuSo*B.mauSo - B.tuSo*B.tuSo; 
}

void phanSo::tich2Phanso(phanSo A, phanSo B){
    phanSo C; 
    C.mauSo = A.mauSo*B.mauSo; 
    C.tuSo = A.tuSo*B.tuSo; 
}
void phanSo::thuong2Phanso(phanSo A, phanSo B){
    phanSo C; 
    C.mauSo = A.mauSo*B.tuSo; 
    C.tuSo = A.tuSo*B.mauSo; 
}
void phanSo::rutGon2PhanSo(phanSo A){

}

int main(int argc, char const *argv[])
{
    phanSo A{1,2}; 
    phanSo B{3,4};
    phanSo C;
    C.tong2Phanso(A,B);
    return 0;
}
