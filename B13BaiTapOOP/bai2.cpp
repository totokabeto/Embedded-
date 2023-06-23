#include <iostream>
#include "math.h"

using namespace std; 

class Rectangle {
private: 
    double chieuDai; 
    double chieuRong; 
public: 
    Rectangle(int chieuDai, int chieuRong);
    double getCircumference();
    double getArea();
    double getDiagonal();
    bool checkSquare();
}; 

Rectangle::Rectangle(int chieuDai, int chieuRong){
    Rectangle::chieuDai = chieuDai; 
    Rectangle::chieuRong = chieuRong;
}
double Rectangle::getCircumference(){
    return (Rectangle::chieuDai+Rectangle::chieuRong)*2;
}
double Rectangle::getArea(){
    return Rectangle::chieuDai*Rectangle::chieuRong;
}
double Rectangle::getDiagonal(){
    return sqrt(pow(Rectangle::chieuDai,2)+pow(Rectangle::chieuRong,2));
}

bool Rectangle::checkSquare(){
    if (Rectangle::chieuDai == Rectangle::chieuRong){
        cout << "Day la hinh vuong" << endl; 
        return true; 
    } else {
        cout << "DAY KHONG PHAI HINH VUONG " << endl; 
        return false; 
    }
}



int main(int argc, char const *argv[])
{
    Rectangle hcn {3,3};
    
    cout << "Dien tich hcn la " << hcn.getArea() << endl; 
    cout << "Chu vi hcn la " << hcn.getCircumference() << endl; 
    cout << "Duong cheo hcn la " << hcn.getDiagonal() << endl; 
    hcn.checkSquare();
    return 0;
}
