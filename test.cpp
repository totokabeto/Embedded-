#include <iostream>

using namespace std; 

char fisrtBack(string a,string b){
    if (a[0] < b[0]){
        cout << "dung nhu vay " << endl;  
    } else {
        cout << "khong dung " << endl;
    }
}
int main(int argc, char const *argv[])
{
    string a = {"Vy"};
    string b = {"Ngoc"}; 
    for (int i = 0; i < a.length(); i++)
    {
        cout << " " << a[i] << endl; 
    }
    fisrtBack(a,b);
    return 0;
}
