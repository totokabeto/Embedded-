#include <iostream> 
#include <vector> 
using namespace std; 
vector <int> modOfA; 
vector <int> modOfB;

int solution(int A,int B){
    int mod; 
    int mod_B;
    int size = 0; 
    while (A != 0){
        mod = A % 10; 
        modOfA.push_back(mod); 
        A /= 10;  
    }
    cout << " size of A : " << modOfA.size() << endl; 
    while (B != 0){
        mod_B = B % 10; 
        modOfB.push_back(mod_B); 
        B /= 10;  
    }
      cout << " size of B : " << modOfB.size() << endl; 
    if (modOfA.size() > modOfB.size()){
        size = modOfB.size();
    } else {
        size = modOfA.size(); 
    }
    cout << size << endl; 
    vector <int> c;  
    int i = size - 1;

    while (i != 0){
        c.push_back(modOfA[i]);
        c.push_back(modOfB[i]);
        i--;
    }
    
    cout <<"c ="<< c.size() << endl;

    for (int i = 0; i < c.size();i++){
      cout << c[i] << endl; 
    }
    
    
    return 0; 
}

int main(int argc, char const *argv[])
{
    unsigned int a = 0x01020304;
    unsigned char * p =  (unsigned char*) &a;
    printf("%d", *p);
    return 0;
}

