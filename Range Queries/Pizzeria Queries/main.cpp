#include <iostream>

using namespace std;

const long long NMAX = 2 * 1e5 + 1, INF = 1e10;
int n, lst[4 * NMAX], rst[4 * NMAX], p[NMAX], q;

void buildl(int sl = 1, int sr = n, int v = 1){
    if(sl == sr) { lst[v] = p[sl] - sl; return; }
    int mid = (sl + sr) / 2;
    buildl(sl, mid, 2 * v);
    buildl(mid + 1, sr, 2 * v + 1);
    lst[v] = min(lst[2 * v], lst[2 * v + 1]);
}

void buildr(int sl = 1, int sr = n, int v = 1){
    if(sl == sr) { rst[v] = p[sl] + sl; return; }
    int mid = (sl + sr) / 2;
    buildr(sl, mid, 2 * v);
    buildr(mid + 1, sr, 2 * v + 1);
    rst[v] = min(rst[2 * v], rst[2 * v + 1]);
}

void updater(int pos, int val, int sl = 1, int sr = n, int v = 1){
    if(sl == sr) { rst[v] = val + sl; return; }
    int mid = (sl + sr) / 2;
    if(pos <= mid) updater(pos, val, sl, mid, 2 * v);
    else updater(pos, val, mid + 1, sr, 2 * v + 1);
    rst[v] = min(rst[2 * v], rst[2 * v + 1]);
}

void updatel(int pos, int val, int sl = 1, int sr = n, int v = 1){
    if(sl == sr) { lst[v] = val - sl; return; }
    int mid = (sl + sr) / 2;
    if(pos <= mid) updatel(pos, val, sl, mid, 2 * v);
    else updatel(pos, val, mid + 1, sr, 2 * v + 1);
    lst[v] = min(lst[2 * v], lst[2 * v + 1]);
}

long long lget(int l, int r, int sl = 1, int sr = n, int v = 1){
    if(l > r || sl > sr) return INF;
    if(l == sl && r == sr) return lst[v];
    int mid = (sl + sr) / 2;
    return min(lget(l, min(mid, r), sl, mid, 2 * v), lget(max(l, mid + 1), r, mid + 1, sr, 2 * v + 1));
}

long long rget(int l, int r, int sl = 1, int sr = n, int v = 1){
    if(l > r || sl > sr) return INF;
    if(l == sl && r == sr) return rst[v];
    int mid = (sl + sr) / 2;
    return min(rget(l, min(mid, r), sl, mid, 2 * v), rget(max(l, mid + 1), r, mid + 1, sr, 2 * v + 1));
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> p[i];
    buildl(), buildr();
    for(int i = 0; i < q; i++){
        int c, k, x;
        cin >> c;
        if(c == 1){
            cin >> k >> x;
            updatel(k, x);
            updater(k, x);
        }
        else{
            cin >> k;
            cout << min(lget(1, k) + k, rget(k, n) - k) << '\n';
        }
    }
    return 0;
}