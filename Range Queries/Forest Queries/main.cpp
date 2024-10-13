#include <iostream>

using namespace std;

const int NMAX = 1001;
int st[4 * NMAX][4 * NMAX], n, q, a[NMAX][NMAX];
char c;

void build(int srow = 1, int erow = n, int scol = 1, int ecol = n, int v1 = 1, int v2 = 1){
    if(srow > erow || scol > ecol) return;
    if(srow == erow && scol == ecol) { st[v1][v2] = a[srow][scol]; return; }
    int rmid = (srow + erow) / 2, cmid = (scol + ecol) / 2;
    build(srow, rmid, scol, cmid, v1 * 2, v2 * 2);
    build(rmid + 1, erow, scol, cmid, v1 * 2 + 1, v2 * 2);
    build(srow, rmid, cmid + 1, ecol, v1 * 2, v2 * 2 + 1);
    build(rmid + 1, erow, cmid + 1, ecol, v1 * 2 + 1, v2 * 2 + 1);
    st[v1][v2] = st[v1 * 2][v2 * 2] + st[v1 * 2 + 1][v2 * 2] + st[v1 * 2][v2 * 2 + 1] + st[v1 * 2 + 1][v2 * 2 + 1];
}

long long sum(int r1, int r2, int c1, int c2, int srow = 1, int erow = n, int scol = 1, int ecol = n, int v1 = 1, int v2 = 1){
    if(r1 > r2 || c1 > c2 || srow > erow || scol > ecol) return 0;
    if(r1 == srow && c1 == scol && r2 == erow && c2 == ecol) return st[v1][v2];
    int rmid = (srow + erow) / 2, cmid = (scol + ecol) / 2;
    return  sum(r1, min(rmid, r2), c1, min(cmid, c2), srow, rmid, scol, cmid, v1 * 2, v2 * 2) + 
            sum(max(r1, rmid + 1), r2, c1, min(cmid, c2), rmid + 1, erow, scol, cmid, v1 * 2 + 1, v2 * 2) + 
            sum(r1, min(rmid, r2), max(c1, cmid + 1), c2, srow, rmid, cmid + 1, ecol, v1 * 2, v2 * 2 + 1) + 
            sum(max(r1, rmid + 1), r2, max(c1, cmid + 1), c2, rmid + 1, erow, cmid + 1, ecol, v1 * 2 + 1, v2 * 2 + 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> c;
            if(c == '*') a[i][j] = 1;
        }
    build();
    for(int i = 1; i <= q; i++){
        int c1, c2, r1, r2;
        cin >> r1 >> c1 >> r2 >> c2;
        if(r1 > r2) swap(r1, r2);
        if(c1 > c2) swap(c1, c2);
        cout << sum(r1, r2, c1, c2) << '\n'; 
    }
    return 0;
}