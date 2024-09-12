#include <iostream>
#include <vector>

using namespace std;

string s;
int f[26];
char x[9];
vector<string> res;

void back(int k, int n){
    for(int i = 0; i < 26; i++){
        if(!f[i]) continue;
        x[k] = i + 'a';
        f[i]--;
        if(k == n - 1){
            string temp;
            for(int i = 0; i <= k; i++) temp.push_back(x[i]);
            res.push_back(temp);
        }
        else back(k + 1, s.size());
        f[i]++;
    }
}

int main(){
    cin >> s;
    for(auto c : s) f[c - 'a']++;
    back(0, s.size());
    cout << res.size() << '\n';
    for(auto k : res) cout << k << '\n';
    return 0;
}