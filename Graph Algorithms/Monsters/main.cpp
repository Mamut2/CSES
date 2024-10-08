#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Entity
{
    bool isPlayer = false;
    int x, y;
};

const int NMAX = 2 * 1e3 + 1;
vector<int> g[NMAX];
string res;
int n, m, a[NMAX][NMAX], di[] = {1, -1, 0, 0}, dj[] = {0, 0, -1, 1}, xe = -1, ye = -1, xs, ys;
queue<Entity> q;

void bfs(){
    a[xs][ys] = 1;
    q.push({1, xs, ys});
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, isPlayer = q.front().isPlayer;
        q.pop();
        if((x == 1 || y == 1 || x == n || y == m) && xe == -1 && isPlayer) xe = x, ye = y;
        for(int k = 0; k < 4; k++){
            int xv = x + di[k], yv = y + dj[k];
            if(xv > 0 && xv <= n && yv > 0 && yv <= m && a[xv][yv] == 0){
                if(isPlayer) {
                    a[xv][yv] = a[x][y] + 1, q.push({1, xv, yv});
                    if((xv == 1 || yv == 1 || xv == n || yv == m) && xe == -1) xe = xv, ye = yv;
                }
                else a[xv][yv] = -1, q.push({0, xv, yv});
            }
        }
    }
}

void path(int x, int y){
    for(int k = 0; k < 4; k++){
        int xv = x + di[k], yv = y + dj[k];
        if(xv > 0 && xv <= n && yv > 0 && yv <= m && a[xv][yv] == a[x][y] - 1) { 
            path(xv, yv);
            if(k == 0) res.push_back('U');
            if(k == 1) res.push_back('D');
            if(k == 2) res.push_back('R');
            if(k == 3) res.push_back('L');;
            return;
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
            if(c == 'A') xs = i, ys = j;
            if(c == 'M') q.push({0, i, j}), a[i][j] = -1;
        }
    bfs();
    if(xe != -1) cout << "YES\n", path(xe, ye), cout << res.size() << '\n' << res;
    else cout << "NO";
    return 0;
}