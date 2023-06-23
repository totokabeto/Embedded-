#include <iostream>

using namespace std; 

class Human{
    private: 
    Human(string address, string name, int age);
    string address; 
    string name; 
    int age; 
    public: 
    void informationPrint(); 
    void ageDisplay();
};

Human::Human(string address, string name, int age){
    Human::address = address; 
    Human::name = name; 
    Human::age = age; 
}

void Human::informationPrint(){
    cout << "Ten : " << name << endl; 
    cout << "Dia chi : " << address << endl; 
    cout << "Tuoi : " << age << endl; 
}

void Human::ageDisplay(){
    cout << "Tuoi : " << endl; 
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
