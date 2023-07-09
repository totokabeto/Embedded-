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
    string getName();
    char getFirstChar(); 
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

char SinhVien::getFirstChar(){
    return SinhVien::name[0];
}
int SinhVien::getID(){
    static int id = 100;
    SinhVien::id = id;
    id++;
    return SinhVien::id; 
}
void SinhVien::getThongTin(){
    cout << "id : " << SinhVien::id << endl;
    cout << "ten : " << SinhVien::name << endl;
    cout << "gioi tinh " << SinhVien::gender << endl;
    cout << "tuoi : " << SinhVien::age << endl; 
}
string SinhVien::getName(){
    return SinhVien::name; 
}
float SinhVien::getAverage(){
    return (this->mathScore + this->physicScore + this->chemicScore)/3; 
}
void SinhVien::setName(string name){
    SinhVien::name = name; 
}
void SinhVien::setAge(int age){
    if(age > 0 && age <= 100){
    SinhVien::age = age;}
}
void SinhVien::setGender(int gender){
    if(gender == 1 || gender == 0){
    SinhVien::gender = gender; }
    else {
        cout << "Gioi tinh nhap vao khong hop le " << endl; 
    }
}
void SinhVien::setMathScore(double mathScore){
    if(mathScore > 0 && mathScore < 10){
        SinhVien::mathScore = mathScore;
    } else {
        cout << "Diem toan nhap vao khong hop le " << endl;
    }
}
void SinhVien::setPhysicScore(double physicScore){
    if(physicScore > 0.0 && physicScore < 10.0){
        SinhVien::physicScore = physicScore; 
    } else {
        cout << "Diem ly nhap vao khong hop le "; 
    } 
}
void SinhVien::setChemicScore(double chemicScore){
    if(chemicScore > 0.0 && physicScore < 10.0){
        SinhVien::chemicScore = chemicScore; 
    } else { 
        cout << "Diem hoa nhap vao khong hop le " << endl; 
    }
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
     list<SinhVien>dataBase;
    public:
    void studentAdd();
    void displayDataBase(); 
    void updateInfo();
    void deleteStudent();
    void searchStudent();
    void sortByGPA(); 
    void sortByName(); 
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
        newStudent.getID(); 
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
void Menu::deleteStudent(){
        int id; 
        cout << "Nhap vao id sinh vien " << endl; 
        cin >> id; 
        for (int i = 0; i < dataBase.size(); i++)
        {
            if(dataBase[i].getID() == id){
                dataBase.erase(dataBase.begin()+i);
            } 
        }
    }
void Menu::searchStudent(){
    cout << "Nhap vao ten sinh vien" << endl; 
    string name; 
    cin >> name; 
    for (auto item : dataBase){
        if(item.getName() == name){
            item.getThongTin();
        } else {
            cout << "Khong tim duoc sinh vien co ten nhu tren " << endl; 
        }
    }

    }
void Menu::sortByGPA(){
    SinhVien array[dataBase.size()];
    int i = 0; 
    for (int i = 0; i < dataBase.size(); i++)
    {
        array[i] = dataBase[i]; 
    }
    
    for (int i = 0; i < dataBase.size() - 1; i++)
    {
        for (int j = i+1; j < dataBase.size(); j++){
        if(array[i].getAverage() < array[j].getAverage()){
            SinhVien temp; 
            temp = array[i]; 
            array[i] = array[j]; 
            array[j]= temp; 
        }
        }
    }
    for (auto item : array){
    item.getThongTin();
    }
}
void Menu::sortByName(){
    SinhVien array[dataBase.size()];
    int i = 0; 
     for (int i = 0; i < dataBase.size(); i++)
    {
        array[i] = dataBase[i]; 
    }
    for (int i = 0; i < dataBase.size() - 1 ; i++)
    {
        for (int j = i + 1 ; j < dataBase.size(); j++ ) {
        if (array[i].getFirstChar() > array[j].getFirstChar()){
        cout << "da sap xep " << endl; 
        
        SinhVien temp; 
        temp = array[i]; 
        array[i] = array[j]; 
        array[j]= temp; 
        }
        }
    }
   for (auto item : array){
    item.getThongTin();
    }
    
}

int main(int argc, char const *argv[])
{
    Menu menu0;
    int input; 
    while (1)
    {
    cout << "Chuong trinh quan ly sinh vien " << endl; 
    cout << "1. Them sinh vien " << endl; 
    cout << "2. Cap nhat thong tin sinh vien boi ID " << endl; 
    cout << "3. Xoa sinh vien boi ID " << endl; 
    cout << "4. Tim kiem sinh vien theo ten " << endl; 
    cout << "5. Sap xep sinh vien theo diem trung binh (GPA) " << endl; 
    cout << "6. Sap xep sinh vien theo ten " << endl; 
    cout << "7. Hien thi danh sach sinh vien " << endl; 
    cout << "0. Thoat " << endl; 
    cout << "Ban chon : " << endl; 
    cin >> input; 
    switch (input)
    {
    case 1:
        menu0.studentAdd();
        break;
    case 2: 
        menu0.updateInfo();
        break; 
    case 3: 
        menu0.deleteStudent();
        break;
    case 4: 
        menu0.searchStudent();
        break; 
    case 5: 
        menu0.sortByGPA();
        break; 
    case 6: 
        menu0.sortByName();
        break;
    case 7: 
        menu0.displayDataBase();
        break; 
    case 0: 
        return 0; 
    }
}
  /*
    SinhVien sv {"khanh",1,12,1,2,3}; 
    sv.getFirstChar();
    cout << " ky tu dau tien la = " <<  sv.getFirstChar() << endl; 
    */
}
