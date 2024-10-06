#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 1e5 + 1;
int n, m, a, b, v[NMAX], ok = 1;
vector<int> g[NMAX];

void dfs(int k, int color){
    v[k] = color;
    for(int u : g[k]){
        if(v[u] && v[u] != color % 2 + 1) {ok = 0; return; } 
        if(!v[u]) dfs(u, color % 2 + 1);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) if(!v[i]) dfs(i, 1);
    if(ok) for(int i = 1; i <= n; i++) cout << v[i] << ' ';
    else cout << "IMPOSSIBLE";
    return 0;
}