#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
vector<int> g[NMAX];
deque<int> sol;
int n, m, a, b, v[NMAX];

void dfs(int k){
    v[NMAX] = 1;
    sol.push_back(k);
    for(auto u : g[k]) {
        if(!v[u]) dfs(u);
        
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    
    return 0;
}