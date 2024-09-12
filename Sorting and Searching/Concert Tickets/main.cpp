#include <bits/stdc++.h>

using namespace std;

int n, m, x;
multiset<int> s;
vector<int> a, b, res;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    a.resize(n), b.resize(m), res.resize(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    for(int i = 0; i < n; i++) s.insert(a[i]);
    for(int i = 0; i < m; i++) {
        x = b[i];
        multiset<int>::iterator it = s.upper_bound(x);
        if(it == s.begin() || s.empty()) { res[i] = -1; } 
        else{
            it--;
            res[i] = *it;
            s.erase(it);
        }
    }
    for(int i : res) cout << i << '\n';
    return 0;
}