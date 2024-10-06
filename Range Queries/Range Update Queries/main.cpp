#include <iostream>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
int n, q, a, b, t, diff, pos;
long long x[NMAX], lazy[4 * NMAX];

void updateLazy(long long u, int l = 1, int r = n, int v = 1){
    if(l == r) { x[l] += u; return; }
    lazy[v] += u;
}

void update(int l, int r, long long u, int sl = 1, int sr = n, int v = 1){
    if(l > r || sl > sr) return;
    if(sl == l && sr == r) { updateLazy(u, l, r, v); return; }
    int mid = (sl + sr) / 2;
    update(l, min(r, mid), u, sl, mid, v * 2);
    update(max(l, mid + 1), r, u, mid + 1, sr, v * 2 + 1);
}

long long getVal(int k, int l = 1, int r = n, int v = 1){
    if(l == r) return x[l];
    if(lazy[v] != 0){
        int mid = (l + r) / 2;
        updateLazy(lazy[v], l, mid, v * 2);
        updateLazy(lazy[v], mid + 1, r, v * 2 + 1);
        lazy[v] = 0;
    }
    int mid = (l + r) / 2;
    if(mid < k) return getVal(k, mid + 1, r, v * 2 + 1);
    else return getVal(k, l, mid, v * 2);
}

int main(){
    cin >> n >> q;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 0; i < q; i++){
        cin >> t;
        if(t == 1){
            cin >> a >> b >> diff;
            update(a, b, diff);
        }
        else{
            cin >> pos;
            cout << getVal(pos) << '\n';
        }
    }
    return 0;
}