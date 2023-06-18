#include <iostream> 
#include <vector>

using namespace std; 

int main(int argc, char const *argv[])
{
    vector<int> array; 
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);

    array.pop_back();
    array.insert(array.begin() + 2,7);
    for(auto item : array){
        cout<<"    " << item << endl; 
    }
    array.clear();
    return 0;
}
