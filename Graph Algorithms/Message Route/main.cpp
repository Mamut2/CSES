#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int NMAX = 1e5 + 1;
int n, m, a, b, v[NMAX];
vector<int> g[NMAX];
queue<int> q;

void bfs(){
    q.push(1);
    v[1] = 1;
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for(auto u : g[k]) if(!v[u]) v[u] = v[k] + 1, q.push(u);
    }
}

void reconstruct(int node){
    for(auto k : g[node])
        if(v[k] == v[node] - 1){
            reconstruct(k);
            break;
        }
    cout << node << ' ';
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> a >> b, g[a].push_back(b), g[b].push_back(a);
    bfs();
    if(!v[n]) { cout << "IMPOSSIBLE"; return 0; }
    cout << v[n] << '\n';
    reconstruct(n);
    return 0;
}