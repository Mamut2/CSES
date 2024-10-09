#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const long long NMAX = 1e5 + 1, INF = __LONG_LONG_MAX__;
long long n, m, a, b, w, d[NMAX], vs[NMAX];
vector<pair<long long, long long>> g[NMAX];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

void dijsktra(){
    pq.push({0, 1});
    while (!pq.empty())
    {
        long long v = pq.top().second;
        pq.pop();
        if(vs[v]) continue;
        vs[v] = 1;
        for(auto p : g[v]){
            long long u = p.second, wh = p.first;
            if(d[u] > d[v] + wh){
                d[u] = d[v] + wh;
                pq.push({d[u], u});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(long long i = 2; i <= n; i++) d[i] = INF;
    d[1] = 0;
    for(long long i = 0; i < m; i++){
        cin >> a >> b >> w;
        g[a].push_back({w, b});
    }
    dijsktra();
    for(long long i = 1; i <= n; i++) cout << d[i] << ' ';
    return 0;
}