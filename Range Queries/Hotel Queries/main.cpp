#include <iostream>
#include <set>

using namespace std;

multiset<pair<int, int>> h;
int n, m, x;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) { cin >> x; h.insert({x, i}); }
    for(int i = 0; i < m; i++) {
        cin >> x;
        auto it = h.lower_bound({x, -1});
        if(it == h.end()) cout << 0 << ' ';
        else { 
            cout << it->second << ' '; 
            cout << it->first << endl;
            if(it->first - x > 0) h.insert({it->first - x, it->second});
            h.erase(it);
        }
    }
    return 0;
}