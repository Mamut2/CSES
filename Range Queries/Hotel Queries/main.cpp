#include <iostream>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
int n, m, st[4 * NMAX], h[NMAX];

void build(int sl = 1, int sr = n, int v = 1){
    if(sl == sr) { st[v] = h[sl]; return; }
    int mid = (sl + sr) / 2;
    build(sl, mid, v * 2);
    build(mid + 1, sr, v * 2 + 1);
    st[v] = max(st[2 * v], st[2 * v + 1]);
}

void update(int pos, int val, int sl = 1, int sr = n, int v = 1){
    if(sl == sr) { st[v] = val; return; }
    int mid = (sl + sr) / 2;
    if(pos <= mid) update(pos, val, sl, mid, v * 2);
    else update(pos, val, mid + 1, sr, v * 2 + 1);
    st[v] = max(st[2 * v], st[2 * v + 1]);
}

void getHotel(int x, int sl = 1, int sr = n, int v = 1){
    if(sl > sr) return;
    if(sl == sr){
        if(h[sl] - x >= 0) cout << sl << ' ', update(sl, h[sl] - x), h[sl] -= x;
        else cout << 0 << ' ';
        return;
    }
    int mid = (sl + sr) / 2;
    if(st[2 * v] >= x) getHotel(x, sl, mid, 2 * v);
    else getHotel(x, mid + 1, sr, 2 * v + 1);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> h[i];
    build();
    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        getHotel(x);
    }
    return 0;
}