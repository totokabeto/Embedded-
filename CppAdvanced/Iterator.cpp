#include <iostream>
#include <list> 

using namespace std; 

int main(int argc, char const *argv[])
{
    list<int> database = {1,2,3,4,5,6,7,8}; 
    list<int>::iterator it; 
    for (it = database.begin(); it != database.end(); ++it ){
        cout << *it << endl; 
    }
    return 0;
}
