#include <iostream>

using namespace std; 

class Book{
    private: 
    string name; 
    string author; 
    int publishYear; 
    int number; 
    public: 
    Book(string name, string author, int publishYear, int number);
    void informationPrint();
    void borrowBook(Book A);
    void returnBook(Book A);
}; 


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
