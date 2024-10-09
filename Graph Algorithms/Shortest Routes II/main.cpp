#include <iostream>

using namespace std;

const long long NMAX = 501, INF = 1e14;
long long n, m, q, a, b, c;
long long cost[NMAX][NMAX];

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cost[i][j] = (i == j ? 0 : INF);
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        cost[a][b] = cost[b][a] = min(cost[a][b], c);
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(k == i || k == j) continue;
                cost[i][j] = min(cost[i][k] + cost[k][j], cost[i][j]);
            }
        }
    }
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        cout << (cost[a][b] == INF ? -1 : cost[a][b]) << '\n';
    }
    return 0;
}