#include <iostream> 

using namespace std; 

class SinhVien{
    public: 
        virtual char*test(){    // overload 
            return (char*)"Hello world\n";
        }
        void display(){
            printf("test: %s\n", test());
        }
};

class DoiTuong: public SinhVien{
    public: 
    char *test(){
        return (char *) "This is test \n"; // overide
    }
};

int main(int argc, char const *argv[])
{
    SinhVien sv; 
    sv.display();

    DoiTuong td; 
    td.display();
    return 0;
}
