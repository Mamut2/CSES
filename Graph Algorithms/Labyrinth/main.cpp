#include <iostream>
#include <queue>

using namespace std;

int n, m, a[1001][1001], is, js, ie, je, di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
queue<pair<int, int>> q;

void bfs(int i, int j){
    q.push({i, j});
    a[is][js] = 1;
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int xv = x + di[k], yv = y + dj[k];
            if(xv > 0 && yv > 0 && xv <= n && yv <= m && !a[xv][yv]){
                a[xv][yv] = a[x][y] + 1;
                q.push({xv, yv});
            }
        }
    }
}

void path(int x, int y){
    if(a[x][y] == 1) return;
    for(int k = 0; k < 4; k++){
        int xv = x + di[k], yv = y + dj[k];
        if(xv > 0 && yv > 0 && xv <= n && yv <= m && a[xv][yv] == a[x][y] - 1){
            path(xv, yv);
            if(k == 0) cout << 'U'; 
            if(k == 1) cout << 'D';
            if(k == 2) cout << 'L';
            if(k == 3) cout << 'R';
            break;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if(c == '#') a[i][j] = -1;
            if(c == 'A') is = i, js = j;
            if(c == 'B') ie = i, je = j;
        };
    bfs(is, js);
    if(a[ie][je]){
        cout << "YES" << '\n' << a[ie][je] - 1 << '\n';
        path(ie, je);
    }
    else cout << "NO";
    return 0;
}