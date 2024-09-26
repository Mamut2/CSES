#include <iostream>

using namespace std;

int n, m, a[1001][1001], di[] = {1, -1, 0, 0}, dj[] = {0, 0, -1, 1}, nr;

void dfs(int x, int y){
    a[x][y] = 1;
    for(int k = 0; k < 4; k++)
        if(x + di[k] > 0 && x + di[k] <= n && y + dj[k] > 0 && y + dj[k] <= m && !a[x + di[k]][y + dj[k]])
            dfs(x + di[k], y + dj[k]);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) { char c; cin >> c; if(c == '#') a[i][j] = 1; }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(!a[i][j]) dfs(i, j), nr++;
        }
    cout << nr;
    return 0;
}