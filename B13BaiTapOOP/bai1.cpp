#include <iostream>

using namespace std; 

class Diem{
    private: 
        int8_t toaDoX;
        int8_t toaDoY;
    public: 
        Diem(int8_t x, int8_t y);
        Diem();
        void setToaDoX(int x);
        int8_t getToaDoX();
};
Diem::Diem(){

}
Diem::Diem(int8_t x , int8_t y){
    toaDoX = x; 
    toaDoY = y;
}
class PhepToanOXY{
    private: 
        Diem diemA;
        Diem diemB;
        Diem diemC;
        typedef enum{
            KHOANG_CACH,
            DIEN_TICH_TAM_GIAC
        }TypePhepToan; 

        TypePhepToan phepToan;
    public: 
            PhepToanOXY(Diem A, Diem B);
            PhepToanOXY(Diem A, Diem B, Diem C);
            float getKhoangCach();
            float getDienTich();
};

PhepToanOXY::PhepToanOXY(Diem A, Diem B){
    phepToan = KHOANG_CACH;
    diemA = A; 
    diemB = B; 
}

PhepToanOXY::PhepToanOXY(Diem A, Diem B, Diem C){
    phepToan = DIEN_TICH_TAM_GIAC; 
    diemA = A;
    diemB = B;
    diemC = C;
}

float PhepToanOXY::getKhoangCach(){
    if(phepToan == KHOANG_CACH){
        return 0;
    }else {
        cout << "Khong goi duoc ham tinh khoang cach";
    }
}





int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
