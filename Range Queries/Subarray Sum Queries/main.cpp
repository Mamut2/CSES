#include <iostream>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
long long a[NMAX], st[4 * NMAX];
int n, q;

void build(int sl = 1, int sr = n, int v = 1){
    if(sl == sr) { st[v] = a[sl]; return; }
    int mid = (sl + sr) / 2;
    build(sl, mid, 2 * v);
    build(mid + 1, sr, 2 * v + 1);
    st[v] = max(st[2 * v] + st[2 * v + 1], max(st[2 * v], st[2 * v + 1]));
}

void update(int pos, int val, int sl = 1, int sr = n, int v = 1){
    if(sl == sr) { st[v] = val; return; }
    int mid = (sl + sr) / 2;
    if(pos <= mid) update(pos, val, sl, mid, 2 * v);
    else update(pos, val, mid + 1, sr, 2 * v + 1);
    st[v] = max(st[2 * v] + st[2 * v + 1], st[2 * v]);
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build();
    for(int i = 0; i < q; i++){
        int k, x;
        cin >> k >> x;
        update(k, x);
        cout << st[1] << '\n';
    }
    return 0;
}