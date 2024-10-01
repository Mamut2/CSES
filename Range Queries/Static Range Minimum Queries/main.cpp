#include <iostream>

using namespace std;

const int NMAX = 2 * 1e5 + 1, INF = 1e9;
int n, q, a, b;
long long x[NMAX], st[4 * NMAX];

void build(int l, int r, int v){
    if(l == r) { st[v] = x[l]; return; }
    int mid = (l + r) / 2;
    build(l, mid, v * 2);
    build(mid + 1, r, v * 2 + 1);
    st[v] = min(st[v * 2], st[v * 2 + 1]);  
}

long long getMin(int l, int r, int sl, int sr, int v){
    if(l > r || sl > sr) return INF;
    if(sl == l && sr == r) return st[v];
    int mid = (sl + sr) / 2;
    return min(getMin(l, min(r, mid), sl, mid, v * 2), getMin(max(l, mid + 1), r, mid + 1, sr, v * 2 + 1));
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> x[i];
    build(1, n, 1);
    for(int i = 1; i <= q; i++){
        cin >> a >> b;
        cout << getMin(a, b, 1, n, 1) << '\n';
    }
    return 0;
}