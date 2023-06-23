#include <iostream> 

using namespace std; 

class bankAccount{
    private: 
        string name; 
        string stk; 
        unsigned long deposit; 
    public: 
        bankAccount(string name, string stk, unsigned long deposit);
        void rutTien(int soTienCanRut);
        void napTien(int soTienCanNap);
        void kiemTraSoDu(bankAccount A);

}; 

bankAccount::bankAccount(string name, string stk, unsigned long deposit){
    bankAccount::name = name; 
    bankAccount::stk = stk; 
    bankAccount::deposit = deposit; 
}

void bankAccount::rutTien(int soTienCanRut){
    if (soTienCanRut > deposit){
        cout << "Ban khong du tien trong tai khoan de rut" << endl; 
    } else{
        deposit = deposit - soTienCanRut; 
    }
}
void bankAccount::napTien(int soTienCanNap){
    deposit += soTienCanNap;
    
}
void bankAccount::kiemTraSoDu(bankAccount A){
    cout << "So du cua ban trong tai khoan la " << A.deposit << endl; 
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
