#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int x, y, w;
};

const long long NMAX = 2501, INF = 1e10;
int n, m, par[NMAX], ok = 1;
long long d[NMAX];
vector<Edge> g;
unordered_set<int> s;
vector<int> res;

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        g.push_back({x, y, w});
    }
    for(int i = 1; i <= n; i++) d[i] = -INF, par[i] = -1;
    d[1] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            int x = g[j].x, y = g[j].y, w = g[j].w;
            if(d[y] > d[x] + w){
                d[y] = d[x] + w;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            int x = g[j].x, y = g[j].y, w = g[j].w;
            if(d[y] > d[x] + w){
                d[y] = d[x] + w;
                par[y] = x;
                ok = 0;
            }
        }
    }
    if(!ok) { 
        cout << "YES\n";
        int x = 0;
        for(int i = 1; i <= n; i++)
            if(par[i] != -1) { x = i; break; }
        while (s.find(x) == s.end())
        {
            res.push_back(x);
            s.insert(x);
            x = par[x];
        }
        res.push_back(x);
        reverse(res.begin(), res.end());
        unordered_set<int> final;
        for (auto &i : res)
        {
            cout << i << " ";
            if (final.find(i) != final.end())
            {
                break;
            }
            final.insert(i);
        }
    }
    else cout << "NO";
    return 0;
}