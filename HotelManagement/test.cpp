#include <iostream> 
#include <vector> 

using namespace std; 

class SinhVien{
    private:
    vector <int> data; 
    public: 
    SinhVien(){

    }
    void addData(int a); 
    void showData(); 
};
void SinhVien::addData(int a){
    int temp; 
    cout << "Nhap a : " << endl; 
    cin >> temp;
    a = temp; 
    data.push_back(a);
    cout << "thanh cong " << endl;  
}
void SinhVien::showData(){
    for (auto &item : data){
        cout << item << endl; 
    }
}
int main(int argc, char const *argv[])
{
    int a; 
    SinhVien sv1;
    SinhVien sv2; 
    sv1.addData(a); 
    sv1.addData(a); 
    sv2.showData(); 



    return 0;
}
