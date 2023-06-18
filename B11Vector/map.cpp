#include <iostream>
#include <map>
#include <string>

using namespace std; 
int main(int argc, char const *argv[])
{
    map <string, int> Sinhvien; 

    Sinhvien["ID"] = 101;
    Sinhvien["Lop"] = 7; 
    Sinhvien["Tuoi"] = 13; 

    for (auto item : Sinhvien){
        cout << " Key : " << item.first.c_str() << " Value : " << item.second << endl; 
    }
    return 0;
}
