#include <iostream>
#include <vector> 

using namespace std; 

class Book{
    private: 
    string name; 
    string author; 
    int publishYear; 
    int number; 
    public: 
    Book(string name, string author, int publishYear, int number);
    void addBook(); 
    void informationPrint();
    void borrowBook();
    void returnBook();
}; 
Book::Book(string name, string author, int publishYear, int number){
    Book::name = name; 
    Book::author = author;
    Book::publishYear = publishYear; 
    Book::number = number; 
}

void Book::informationPrint(){
    cout << "Ten : " << name << endl; 
    cout << "Ten tach gia : " << author << endl; 
    cout << "Nam phat hanh : " << publishYear << endl; 
    cout << "So luong : " << number << endl; 
}
list<Book> dataBase; 
void Book::addBook(){
    string name; 
    string author; 
    int namPhatHanh; 
    int soLuong; 
    cout << "Nhap ten sach : " << endl; 
    cin >> name; 
    cout << "Nhap ten tach gia : " << endl; 
    cin >> author; 
    cout << "Nhap nam phat hanh : " << endl; 
    cin >> namPhatHanh; 
    cout << "Nhap so luong : " << endl; 
    cin >> soLuong; 

    Book newBook{name,author,namPhatHanh,soLuong}; 
    dataBase.push_back(newBook);
}
void Book::borrowBook(){
    string name; 
cout <<" Nhap ten sach can muon : " << endl; 
cin >> name; 
    for (auto item : dataBase){
        if(item.name == name){
            if (item.number != 0){
            item.number--; }
            else {
                cout << "Khong du so luong sach de muon " << endl;
            }
        } else {
            cout << "Khong co ten sach nhu tren " << endl; 
        }
    }
}
void Book::returnBook(){
    string name; 
    cout << "Nhap ten sach can tra " << endl; 
    cin >> name; 
    for (auto item: dataBase){
        if(item.name == name){
            item.number++; 
        } else {
            cout << "Khong co ten sach nhu tren " << endl; 
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
