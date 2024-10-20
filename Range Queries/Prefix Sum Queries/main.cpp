#include <iostream>

using namespace std;

const long long NMAX = 2 * 1e5 + 1;
long long a[NMAX], n, q, st[4 * NMAX], mst[4 * NMAX];

void build(int sl = 1, int sr = n, int v = 1){
    if(sl == sr) { st[v] = a[sl], mst[v] = max(0LL, a[sl]); return; }
    int mid = (sl + sr) / 2;
    build(sl, mid, 2 * v);
    build(mid + 1, sr, 2 * v + 1);
    st[v] = st[2 * v] + st[2 * v + 1];
    mst[v] = max(mst[2 * v], st[2 * v] + mst[2 * v + 1]);
}

void update(int pos, int val, int sl = 1, int sr = n, int v = 1){
    if(sl == sr) { st[v] = val, mst[v] = max(0, val); return; }
    int mid = (sl + sr) / 2;
    if(pos <= mid) update(pos, val, sl, mid, 2 * v);
    else update(pos, val, mid + 1, sr, 2 * v + 1);
    st[v] = st[2 * v] + st[2 * v + 1];
    mst[v] = max(mst[2 * v], st[2 * v] + mst[2 * v + 1]);
}

long long getSum(int l, int r, int sl = 1, int sr = n, int v = 1){
    if(l > r || sl > sr) return 0;
    if(l == sl && r == sr) return st[v];
    int mid = (sl + sr) / 2;
    return getSum(l, min(r, mid), sl, mid, 2 * v) + getSum(max(l, mid + 1), r, mid + 1, sr, 2 * v + 1);
}

long long getMax(int l, int r, int sl = 1, int sr = n, int v = 1){
    if(l > r || sl > sr) return 0;
    if(l == sl && r == sr) return mst[v];
    int mid = (sl + sr) / 2;
    return max(getMax(l, min(r, mid), sl, mid, 2 * v), getSum(l, min(r, mid), sl, mid, 2 * v) + getMax(max(l, mid + 1), r, mid + 1, sr, 2 * v + 1));
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build();
    for(int i = 1; i <= q; i++){
        int c, x, y;
        cin >> c >> x >> y;
        if(c == 1){
            update(x, y);
        }
        else {
            cout << getMax(x, y) << '\n';
        }
    }
    return 0;
}