#include <iostream>
#include <string> 
#include <vector> 


using namespace std; 

typedef enum{
    MALE, 
    FEMALE
}typeGender;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH, 
    YEU, 
}typeLevel; 


class SinhVien{
    protected: 
    int id; 
    string name; 
    int gender; 
    int age; 
    double mathScore; 
    double physicScore; 
    double chemicScore;  

    public: 
    SinhVien(){

    }
    SinhVien (string name, int gender, int age, double mathScore, double physicScore, double chemicScore){
        SinhVien::name = name; 
        SinhVien::gender = gender; 
        SinhVien::age = age; 
        SinhVien::mathScore = mathScore; 
        SinhVien::physicScore = physicScore; 
        SinhVien::chemicScore = chemicScore; 
    }
    int getID();
    float getAverage(); 
    void getThongTin();
    typeLevel getLevel();
    void setName(string name); 
    void setGender(int gender); 
    void setAge(int age);
    void setMathScore(double mathScore);
    void setPhysicScore(double physicScore); 
    void setChemicScore(double chemicScore);
    
};
int SinhVien::getID(){
    static int id = 100;
    SinhVien::id = id;
    id++;
    return SinhVien::id; 
}
void SinhVien::getThongTin(){
    cout << "ten : " << SinhVien::name << endl;
    cout << "gioi tinh " << SinhVien::gender << endl;
}
float SinhVien::getAverage(){
    return (this->mathScore + this->physicScore + this->chemicScore)/3; 
}
void SinhVien::setName(string name){
    SinhVien::name = name; 
}
void SinhVien::setAge(int age){
    SinhVien::age = age;
}
void SinhVien::setGender(int gender){
    SinhVien::gender = gender; 
}

typeLevel SinhVien::getLevel(){
    if(SinhVien::getAverage() > 8){
        return GIOI; 
    }else if (SinhVien::getAverage() > 6.5){
        return KHA; 
    }else if (SinhVien::getAverage() > 4.5){
        return TRUNG_BINH;
    } else {
        return YEU; 
    }
}

 
class Menu : public SinhVien {
    private:
   vector<SinhVien>dataBase;
    public:
    void studentAdd();
    void displayDataBase(); 
    void updateInfo();
    void deleteStudent();
    void searchStudent();

};

void Menu::studentAdd(){
        string name; 
        int gender; 
        int age; 
        double mathScore; 
        double physicScore; 
        double chemicScore;  
        cout << "Vui long nhap ten: " << endl; 
        cin >> name; 
        cout << "Vui long nhap gioi tinh: 1/Nam 2/Nu " << endl; 
        cin >> gender; 
        cout << "Vui long nhap tuoi: " << endl; 
        cin >> age; 
        cout << "Vui long nhap diem toan " << endl; 
        cin >> mathScore; 
        cout << "Nhap diem ly: " << endl; 
        cin >> physicScore; 
        cout << "Nhap diem hoa : " << endl;
        cin >> chemicScore; 

        SinhVien newStudent{name,gender,age,mathScore,physicScore,chemicScore}; 
        dataBase.push_back(newStudent); 
    }
    void Menu::displayDataBase(){
        for(auto item : dataBase){
            item.getThongTin();
            cout << "Diem trung binh cua ban : " << item.getAverage() << endl; 
            cout << "Hoc luc cua ban la: " << item.getLevel() << endl; 
        }
    }

    void Menu::updateInfo(){
        int id = 0; 
        cout << "Nhap vao id sinh vien can sua " << endl; 
        cin >> id; 
        
        for(int i = 0; i < dataBase.size(); i++)
            {
            if(dataBase[i].getID() == id){
               
                string name; 
                int gender; 
                int age; 
                double mathScore; 
                double physicScore; 
                double chemicScore;  
        cout << "Vui long nhap ten: " << endl; 
        cin >> name; 
        cout << "Vui long nhap gioi tinh: 1/Nam 2/Nu " << endl; 
        cin >> gender; 
        cout << "Vui long nhap tuoi: " << endl; 
        cin >> age; 
        cout << "Vui long nhap diem toan " << endl; 
        cin >> mathScore; 
        cout << "Nhap diem ly: " << endl; 
        cin >> physicScore; 
        cout << "Nhap diem hoa : " << endl;
        cin >> chemicScore; 
            dataBase[i].setName(name);
            dataBase[i].setAge(age);
            dataBase[i].setGender(gender); // dùng list thì không duyệt ntn được 
            cout << "da cap nhat thong tin " << endl;
            break;
            }
            else{
                cout << "Khong tim thay id sinh vien " << endl; 
            }
        }
    }
int main(int argc, char const *argv[])
{
    Menu menu1; 
    menu1.studentAdd();
    
    menu1.updateInfo();
   // menu1.studentAdd();

    menu1.displayDataBase();

    return 0;
}
