#include <iostream>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
int n, st[4 * NMAX], a[NMAX], q;

void build(int sl = 1, int sr = n, int v = 1){
    if(sl == sr) { st[v] = 1; return; } 
    int mid = (sl + sr) / 2;
    build(sl, mid, 2 * v);
    build(mid + 1, sr, 2 * v + 1);
    st[v] = st[2 * v] + st[2 * v + 1];
}

void update(int pos, int sl = 1, int sr = n, int v = 1){
    if(sl == sr) { st[v] = 0; return; } 
    int mid = (sl + sr) / 2;
    if(pos <= mid) update(pos, sl, mid, 2 * v);
    else update(pos, mid + 1, sr, 2  * v + 1);
    st[v] = st[2 * v] + st[2 * v + 1];
}

void getEl(int pos, int sl = 1, int sr = n, int v = 1){
    if(sl > sr) return;
    if(sl == sr && st[v]) { 
        update(sl); cout << a[sl] << ' '; 
        return; 
    }
    int mid = (sl + sr) / 2;
    if(st[2 * v] < pos) getEl(pos - st[2 * v], mid + 1, sr, 2 * v + 1);
    else getEl(pos, sl, mid, 2 * v);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build();
    for(int i = 1; i <= n; i++){
        cin >> q;
        getEl(q);
    }
    return 0;
}