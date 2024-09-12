#include <bits/stdc++.h>

using namespace std;

#define safe(x, y) (x > 0 && x <= n && y > 0 && y <= n && !v[x][y])
#define inBoundsButUsed(x, y) (x > 0 && x <= n && y > 0 && y <= n && v[x][y])
#define isValid(a) (a > 0 && a <= 7 ? 1 : 0)
#define right 0
#define left 1
#define down 2
#define up 3

int n = 7, di[] = {1, -1, 0, 0}, dj[] = {0, 0, -1, 1}, res, it;
bool v[8][8];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
string s;

void back(int k, int x, int y){
    if(k == 48 && x == n && y == 1) {res++; return;}
    if(x == n && y == 1) return;

    vector<bool> visited(4, -1);
    for (int k = 0; k < 4; k++)
        if (isValid(x + dx[k]) && isValid(y + dy[k]))
            visited[k] = v[x + dx[k]][y + dy[k]];

    if (!visited[down] && !visited[up] && visited[right]
        && visited[left])
        return;

    if (!visited[right] && !visited[left] && visited[down]
        && visited[up])
        return;

    if (isValid(x - 1) && isValid(y + 1)
        && v[x - 1][y + 1] == 1)
        if (!visited[right] && !visited[up])
            return;

    if (isValid(x + 1) && isValid(y + 1)
        && v[x + 1][y + 1] == 1)
        if (!visited[right] && !visited[down])
            return;

    if (isValid(x - 1) && isValid(y - 1)
        && v[x - 1][y - 1] == 1)
        if (!visited[left] && !visited[up])
            return;

    if (isValid(x + 1) && isValid(y - 1)
        && v[x + 1][y - 1] == 1)
        if (!visited[left] && !visited[down])
            return;
    
    v[x][y] = 1;
    if(s[k] == '?'){
        for(int i = 0; i < 4; i++){
            int xv = x + di[i], yv = y + dj[i];
            if(safe(xv, yv)) back(k + 1, xv, yv);
        }
    }
    else if(s[k] == 'U' && safe(x - 1, y)) back(k + 1, x - 1, y);
    else if(s[k] == 'D' && safe(x + 1, y)) back(k + 1, x + 1, y);
    else if(s[k] == 'R' && safe(x, y + 1)) back(k + 1, x, y + 1);
    else if(s[k] == 'L' && safe(x, y - 1)) back(k + 1, x, y - 1);
    v[x][y] = 0;
}

int main(){
    cin >> s;
    back(0, 1, 1);
    cout << res;
    return 0;
}