#include <iostream> 
#include <string> 
using namespace std; 
namespace conOngA{
    int A = 10;
class ToanHoc
{
private:
    int lop; 
    int tuoi; 
public:
    void tong(int a,int b);
    void tong(int a,int b, int c);
    int tong(int a, double b);
};
}
namespace conOngB{
    int A = 11; 
}
using namespace conOngA;

void ToanHoc::tong(int a, int b){
    cout << "Tong a va b la " << a + b << endl; 
}

void ToanHoc::tong(int a, int b, int c){
    cout << "Tong a va b va c la " << a + b + c << endl; 
}

int ToanHoc::tong(int a, double b){
    cout << "Tong a va b la " << a + (int)b << endl; 
    return a + (int)b;
}

template <typename var , typename varb> 


varb tong(var a, varb b){
    return (varb)a+b;
}
int main(int argc, char const *argv[])
{
    ToanHoc th; 
    th.tong(3,5.6);
    return 0;
}
