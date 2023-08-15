#include <iostream> 
#include <vector> 
#include <math.h>
using namespace std; 
vector <string> temp; 
void removeDupWord(string str){
    string word = ""; 
    for (auto x : str){
        if (x == ' '){
           cout << word << endl; 
           temp.push_back(word);
            word = ""; 
        } else {
            word = word + x; 
            
        }
    }
         cout << word << endl; 
         temp.push_back(word);

}
int main(int argc, char const *argv[])
{   string str = "Geeks for Geeks"; 
    removeDupWord(str); 
    cout << temp.size() << endl; 
    return 0;
}

  