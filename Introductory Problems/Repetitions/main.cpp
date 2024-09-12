#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int maxSize = 0, sz = 1;
    getline(cin, s);
    for(int i = 1; i < s.size(); i++){
        if(s[i - 1] == s[i]) sz++;
        else maxSize = max(sz, maxSize), sz = 1;
    }
    maxSize = max(sz, maxSize);
    cout << maxSize;
    return 0;
}