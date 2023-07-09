#include <iostream>
#include <list> 
using namespace std;


class Test {
 private: 
 bool trang_thai; 
list<Test> database; 
 public: 
list<Test> getdata(); 
 Test();
 Test(bool trangthai); 
 void setTT(); 
 bool getTT(); 
 void add();
 void show(list<Test> database);
};
Test::Test(){

}
list <Test> Test::getdata(){
   return this->database;
}
void Test::show(list<Test> database){
   for (auto item : database){
      item.setTT();
      cout << "trang thai moi cua item " << item.getTT() << endl; 
   }
}
void Test::add(){
   for (int i = 0; i < 3; i++)
   {
      Test newtest {false}; 
      database.push_back(newtest); 
   }
   
}

Test::Test(bool trangthai){
   this->trang_thai = trangthai; 
}
void Test::setTT(){
   this->trang_thai = true; 
}
 bool Test::getTT(){
   return this->trang_thai; 
 }
 int main(int argc, char const *argv[])
 {
   Test test1; 
   test1.add(); 
   test1.show(test1.getdata());
   return 0; 
 }
 