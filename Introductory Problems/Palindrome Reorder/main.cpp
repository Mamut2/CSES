#include <iostream>

using namespace std;

string s, sol;
int f[26], odd, ind;
char last = 0;

int main(){
    cin >> s;
    for(auto c : s) {
        ind = c - 'A';
        if(f[ind] & 1) odd--;
        f[ind]++;
        if(f[ind] & 1) odd++;
    }
    if(odd > 1) {cout << "NO SOLUTION"; return 0;}
    for(int i = 0; i < 26; i++) if(f[i] & 1) last = i + 'A';
    for(int i = 0; i < 26; i++) while(f[i] > 1) sol.push_back(i + 'A'), f[i] -= 2;
    if(odd) sol.push_back(last);
    cout << sol;
    if(odd) sol.pop_back();
    for(int i = sol.size() - 1; i >= 0; i--) cout << sol[i];
    return 0;
}