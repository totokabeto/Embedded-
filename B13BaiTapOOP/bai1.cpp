#include <iostream>
#include "math.h"

using namespace std; 

class Diem{
    private: 
        int8_t toaDoX;
        int8_t toaDoY;
    public: 
        Diem(int8_t x, int8_t y);
        Diem();
        void setToaDoX(int8_t x);
        void setToaDoY(int8_t y);
        int8_t getToaDoX();
        int8_t getToaDoY();
};
Diem::Diem(){

}
Diem::Diem(int8_t x , int8_t y){
    toaDoX = x; 
    toaDoY = y;
}
void Diem::setToaDoX(int8_t x){
    Diem::toaDoX = x; 
}
void Diem::setToaDoY(int8_t y){
    Diem::toaDoY = y; 
}
int8_t Diem::getToaDoX(){
    return Diem::toaDoX; 
}
int8_t Diem::getToaDoY(){
    return Diem::toaDoY; 
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
    float khoangCach; 
    if(phepToan == KHOANG_CACH){
     khoangCach = sqrt(pow(diemB.getToaDoX() - diemA.getToaDoX(),2) + pow(diemB.getToaDoY() - diemA.getToaDoY(),2));
     cout << "Khoảng cách giữa điểm A và điểm B là : " << khoangCach << endl; 
     return khoangCach;
    }else {
        cout << "Khong goi duoc ham tinh khoang cach" << endl; 
        return 0; 
    }
}
float PhepToanOXY::getDienTich(){
    float dienTich; 
    float nuaChuVi; 
    float khoangCachAB; 
    float khoangCachBC; 
    float khoangCachAC;
    if (phepToan == DIEN_TICH_TAM_GIAC){
    khoangCachAB = sqrt(pow(diemB.getToaDoX() - diemA.getToaDoX(),2) + pow(diemB.getToaDoY() - diemA.getToaDoY(),2));
    khoangCachAC = sqrt(pow(diemC.getToaDoX() - diemA.getToaDoX(),2) + pow(diemC.getToaDoY() - diemA.getToaDoY(),2));
    khoangCachBC = sqrt(pow(diemC.getToaDoX() - diemB.getToaDoX(),2) + pow(diemC.getToaDoY() - diemB.getToaDoY(),2));
    nuaChuVi = (khoangCachAB + khoangCachAC + khoangCachBC ) /2; 
    dienTich = sqrt(nuaChuVi * (nuaChuVi - khoangCachAB) * (nuaChuVi - khoangCachAC) * (nuaChuVi - khoangCachBC)); 

    cout << "Dien tich tam giac ABC la : " << dienTich << endl; 

    return dienTich; 

    } else {
        cout << "Khong gọi được hàm tính diện tích tam giác " << endl;
        return 0; 
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
