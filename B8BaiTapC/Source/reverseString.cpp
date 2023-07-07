#include <iostream> 
#include <string> 

using namespace std; 

class Solution{
public: 
string reverserWord(string s){
    string result; 
    int i = 0; 
    int n = s.length();
    while (i < n) {
        while (i < n && s[i] == ' ') {i++;}
        if (i > n ) break;
        int j = i + 1; 
        while (j < n && s[j] != ' '){
        j++;}
        string sub = s.substr(i,j-i);
        if(result.length() == 0) result = sub; 
        else result = sub + ' ' + result; 
        i = j + 1; 
    }
    return result;
}
};

int main(int argc, char const *argv[])
{
    Solution sl1; 
    sl1.reverserWord("Thai exporters are halving the time it takes to deliver durian to China, from 8 days to four days, in order to better compete with Vietnam over the pungent fruit.");
    cout << " " <<  sl1.reverserWord("Thai exporters are halving the time it takes to deliver durian to China, from 8 days to four days, in order to better compete with Vietnam over the pungent fruit") << endl; 
    return 0;
}
