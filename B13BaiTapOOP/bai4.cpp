#include <iostream>

using namespace std; 

class Animal{
     
    public: 
        Animal(string name, int age, double weight, double height);
        float calculateBMI();
        void compareAge(Animal A, Animal B);
        void CompareWeight(Animal A, Animal B);
    protected:
        string name; 
        int age; 
        double weight; 
        double height; 
      
}; 

Animal::Animal(string name, int age, double weight, double height){
    Animal::name = name; 
    Animal::age = age; 
    Animal::weight = weight; 
    Animal::height = height; 
}

float Animal::calculateBMI(){
    return weight/(height*height);
}

void Animal::compareAge(Animal A, Animal B){
    if (A.age > B.age){
        cout << " Dong Vat A lon tuoi hon Dong Vat B " << endl; 
    } else if (A.age == B.age){
        cout << "Hai dong vat bang tuoi nhau" << endl; 
    }
    else {
        cout << "Dong Vat B lon tuoi hon Dong Vat A" << endl; 
    } 
}
void Animal::CompareWeight(Animal A, Animal B){
    if (A.age > B.age){
        cout << " Dong Vat A nang hon Dong Vat B " << endl; 
    } else if (A.age == B.age){
        cout << "Hai dong vat nang bang nhau" << endl; 
    }
    else {
        cout << "Dong Vat B nang hon Dong Vat A" << endl; 
    } 
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
