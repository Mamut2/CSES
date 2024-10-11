#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long NMAX = 1e5 + 1, INF = __LONG_LONG_MAX__;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
vector<pair<int, long long>> g[NMAX];
int n, m, a, b, w, ant[NMAX], vis[NMAX], discount, cnt;
long long d[NMAX][2];

void dijkstra(){
    pq.push({0, 1});
    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();
        if(vis[v] == 2) continue;
        vis[v]++;
        for(auto p : g[v]){
            int u = p.first, dis = p.second;
            if(d[u][1] > d[v][1] + dis){
                d[u][1] = d[v][1] + dis;
                pq.push({d[u][1], u});
            }
            if(d[u][0] > d[v][0] + dis){
                d[u][0] = d[v][0] + dis;
                pq.push({d[u][0], u});
            }
            if(d[u][1] > d[v][0] + dis / 2){
                d[u][1] = d[v][0] + dis / 2;
                pq.push({d[u][1], u});
            }
        }
    }    
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        g[a].push_back({b, w});
    }
    for(int i = 1; i <= n; i++) d[i][0] = d[i][1] = INF;
    d[1][0] = d[1][1] = 0;
    dijkstra();
    cout << d[n][1];
    return 0;
}