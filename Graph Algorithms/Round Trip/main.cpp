#include <iostream>
#include <vector>
#include <deque>
 
using namespace std;
 
const int NMAX = 2 * 1e5 + 1;
vector<int> g[NMAX], res;
int n, m, a, b, ok = 0, v[NMAX];
 
void print_res(int k){
    vector<int> cyc = { k };
    for(int i = res.size() - 1; i >= 0; i--) {
        cyc.push_back(res[i]);
        if(res[i] == k) break;
    }
    cout << cyc.size() << '\n';
    for(auto u : cyc) cout << u << ' ';
}
 
void dfs(int k, int dad){
    if(ok) return;
    if(v[k] && res.size() > 2) { ok = 1, print_res(k); return; };
    if(v[k]) return;
    v[k] = 1;
    res.push_back(k);
    for(auto u : g[k]) if(u != dad) dfs(u, k);
    res.pop_back();
}
 
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) if(!v[i]) res.clear(), dfs(i, -1);
    if(!ok) cout << "IMPOSSIBLE";
    return 0;
}