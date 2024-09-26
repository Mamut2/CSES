#include <iostream>
#include <set>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
int n, m, ind[NMAX], x = 1, a, b, ar[NMAX];
set<pair<int, int>> swaped;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> ar[i], ind[ar[i]] = i;
    for(int i = 1; i <= n; i++) if(ind[i] < ind[i - 1]) x++;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(ar[a] + 1 <= n) swaped.insert({ar[a], ar[a] + 1});
        if(ar[a] - 1 > 0) swaped.insert({ar[a] - 1, ar[a]});
        if(ar[b] + 1 <= n) swaped.insert({ar[b], ar[b] + 1});
        if(ar[b] - 1 > 0) swaped.insert({ar[b] - 1, ar[b]});
        for(auto p : swaped) if(ind[p.first] > ind[p.second]) x--;
        swap(ar[a], ar[b]), ind[ar[a]] = a, ind[ar[b]] = b;
        for(auto p : swaped) if(ind[p.first] > ind[p.second]) x++;
        cout << x << '\n';
        swaped.clear();
    }
    return 0;
}