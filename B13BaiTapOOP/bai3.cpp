#include <iostream>

using namespace std; 

class Circle{
    private: 
    int radius; 
    public: 
    Circle(int radius);
    float getCircumference();
    float getArea();

};

Circle::Circle(int radius){
    Circle::radius = radius;
}
float Circle::getArea(){
    return radius*radius*3.14; 
}
float Circle::getCircumference(){
    return 2*3.14*radius;
}

int main(int argc, char const *argv[])
{
    Circle ht{4}; 

    cout << "chu vi hinh tròn la " << ht.getCircumference() << endl; 
    return 0;
}
