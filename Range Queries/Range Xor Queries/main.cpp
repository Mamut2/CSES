#include <iostream>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
long long n, a, b, x[NMAX], st[4 * NMAX], q;

void build(int l = 1, int r = n, int v = 1){
    if(l == r) { st[v] = x[l]; return; }
    int mid = (l + r) / 2;
    build(l, mid, 2 * v);
    build(mid + 1, r, 2 * v + 1);
    st[v] = (st[v * 2] ^ st[v * 2 + 1]);
}

long long getXor(int l, int r, int sl = 1, int sr = n, int v = 1){
    if(l > r || sl > sr) return 0;
    if(l == sl && r == sr) return st[v];
    int mid = (sl + sr) / 2;
    return getXor(l, min(r, mid), sl, mid, v * 2) ^ getXor(max(l, mid + 1), r, mid + 1, sr, v * 2 + 1);
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> x[i];
    build();
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        cout << getXor(a, b) << '\n';
    }
    return 0;
}