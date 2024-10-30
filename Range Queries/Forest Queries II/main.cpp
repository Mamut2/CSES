#include <iostream>
 
using namespace std;
 
const int NMAX = 1001;
int n, q, a[NMAX][NMAX], bit[NMAX][NMAX];
char c;

void update(int x, int y, int val){
    for(; x <= n; x += x & -x)
        for(int yy = y; yy <= n; yy += yy & -yy)
            bit[x][yy] += val;
}

int sum(int x, int y){
    int res = 0;
    for(; x > 0; x -= x & -x)
        for(int yy = y; yy > 0; yy -= yy & -yy)
            res += bit[x][yy];
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> c;
            if(c == '*') a[i][j] = 1, update(i, j, 1);
        }
    for(int i = 1; i <= q; i++){
        int c1, c2, r1, r2, c;
        cin >> c;
        if(c == 2){
            cin >> r1 >> c1 >> r2 >> c2;
            cout << sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) + sum(r1 - 1, c1 - 1) << '\n';
        }
        else {
            cin >> r1 >> c1;
            update(r1, c1, (a[r1][c1] ? -1 : 1));
            a[r1][c1] = !a[r1][c1];
        }
    }
    return 0;
}