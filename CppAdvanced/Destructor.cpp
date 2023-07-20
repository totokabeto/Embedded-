#include <iostream>

using namespace std; 

class SinhVien
{
private:
    int ID;
    int *ptr; 
public:
    SinhVien(/* args */);
    ~SinhVien();
    int getID(){
        return this->ID; 
    }
};

SinhVien::SinhVien(/* args */)
{
    static int id = 100; 
    ID = id; 
    ptr = &id;
    id++; 
}

SinhVien::~SinhVien()
{
    *ptr = 100; 
}

void test1(){
    SinhVien sv1,sv2; 
    cout << sv1.getID() << endl; 
    cout << sv2.getID() << endl; 
}
void test2(){
    SinhVien sv1,sv2; 
    cout << sv1.getID() << endl; 
    cout << sv2.getID() << endl; 
}
int main(int argc, char const *argv[])
{
    test1();
    test2(); 
    return 0;
}
