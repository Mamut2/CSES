#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;


const long long NMAX = 2501, INF = 1e14;
long long n, m, a, b, w, d[NMAX];
bool g[NMAX][NMAX];

struct Edge
{
    long long a, b, w;
} edges[2 * NMAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(long long i = 2; i <= n; i++) d[i] = -INF;
    d[1] = 0;
    for(long long i = 0; i < m; i++){
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
        g[a][b] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if(d[b] < d[a] + w) d[b] = d[a] + w;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if(d[b] < d[a] + w) { 
                d[b] = d[a] + w;
                if(g[b][n]) {cout << -1; return 0;} 
            }
        }
    }
    cout << d[n];
    return 0;
}