#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 1e5 + 1;
int n, m, a, b, v[NMAX];
vector<int> g[NMAX], res;

void dfs(int k){
    v[k] = 1;
    for(auto j : g[k]) if(!v[j]) dfs(j);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> a >> b, g[a].push_back(b), g[b].push_back(a);
    for(int i = 1; i <= n; i++) if(!v[i]) dfs(i), res.push_back(i);
    cout << res.size() - 1 << '\n';
    if(res.size() > 1) for(int i = 1; i < res.size(); i++) cout << res[i] << ' ' << res[i - 1] << '\n';
    return 0;   
}