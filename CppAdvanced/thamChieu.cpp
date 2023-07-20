#include <iostream> 

using namespace std; 

void test(int a, int &b, int *c){
    a = 10; 
    b = 20; 
    *c = 30; 
}

int main(int argc, char const *argv[])
{
    int x = 1; 
    int y = 2; 
    int z = 3; 
    test(x,y,&z); 
    cout << x << endl; 
    cout << y << endl; 
    cout << z << endl; 
    return 0;
}
