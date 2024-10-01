#include <iostream>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
int n, q, a, b, k, u, t;
long long st[NMAX * 4], x[NMAX];

void build(int l, int r, int v){
    if(l == r) { st[v] = x[l]; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2 * v);
    build(mid + 1, r, 2 * v + 1);
    st[v] = st[v * 2] + st[v * 2 + 1];
}

long long sum(int l, int r, int sl, int sr, int v){
    if(l > r || sl > sr) return 0;
    if(l == sl && r == sr) return st[v];
    int mid = (sl + sr) / 2;
    return sum(l, min(r, mid), sl, mid, v * 2) + sum(max(l, mid + 1), r, mid + 1, sr, v * 2 + 1);
}

void update(int l, int r, int pos, int el, int v){
    if(l == r) { st[v] = el; return; }
    int mid = (l + r) / 2;
    if(pos <= mid) update(l, mid, pos, el, 2 * v);
    else update(mid + 1, r, pos, el, 2 * v + 1);
    st[v] = st[v * 2] + st[v * 2 + 1];
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> x[i];
    build(1, n, 1);
    for(int i = 1; i <= q; i++){
        cin >> t;
        if(t == 1) cin >> k >> u, update(1, n, k, u, 1);
        else cin >> a >> b, cout << sum(a, b, 1, n, 1) << '\n';
    }
    return 0;
}