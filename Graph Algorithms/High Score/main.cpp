#include <iostream>
#include <vector>

using namespace std;

const long long NMAX = 2501, INF = 1e14;
long long n, m, a, b, w, d[NMAX], marked[NMAX], v[NMAX];
vector<int> g[NMAX];
bool ok = 1;

struct Edge
{
    long long a, b, w;
} edges[2 * NMAX];

void dfs(int k){
    v[k] = 1;
    if(marked[k]) ok = false;
    for(auto u : g[k]) if(!v[u]) dfs(u);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(long long i = 2; i <= n; i++) d[i] = -INF;
    d[1] = 0;
    for(long long i = 0; i < m; i++){
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
        g[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if(d[b] == d[a] && d[b] == -INF) continue;
            if(d[b] < d[a] + w) d[b] = d[a] + w;
        }
    }
    for(int j = 0; j < m; j++){
        a = edges[j].a, b = edges[j].b, w = edges[j].w;
        if(d[b] < d[a] + w) { 
            if(d[b] == d[a] && d[b] == -INF) continue;
            d[b] = d[a] + w;
            marked[b] = 1;
        }
    }
    dfs(n);
    if(ok) cout << d[n];
    else cout << -1;
    return 0;
}