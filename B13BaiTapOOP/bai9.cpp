#include <iostream>

using namespace std; 

class Car {
    private: 
        string color; 
        string engineType; 
        int mileage; 
        
    public: 
        Car(string color, string engineType, int mileage);
        unsigned long serviceCost(Car A);
        void mileageCheck(Car A);
        void informationPrint(Car A);


};
Car::Car(string color, string engineType, int mileage){
    Car::color = color; 
    Car::engineType = engineType; 
    Car::mileage = mileage; 
}

unsigned long Car::serviceCost(Car A){
    const unsigned long costPerKm = 4000;
    return A.mileage*costPerKm; 
}

void Car::mileageCheck(Car A){
    cout << "So km da đi duoc la: " << A.mileage << endl; 
}

void Car::informationPrint(Car A){
    cout << "Mau xe : " << A.color << endl; 
    cout << "Loai dong co " << A.engineType << endl; 
    cout << "So km da đi duoc la: " << A.mileage << endl; 
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
