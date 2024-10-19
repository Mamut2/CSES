#include <iostream>
#include <map>

using namespace std;

const int SMAX = 1e6 + 1, NMAX = 2 * 1e5 + 1, BSIZE = 1e3;
long long st[4 * SMAX], a[NMAX];
int n, q, x, y;
char c;
map<int, long long> f;

void build(int sl = 1, int sr = SMAX, int v = 1){
    if(sl == sr) { 
        long long sum = 0;
        auto it = f.lower_bound(sl * BSIZE + 1);
        while (it != f.end() && it->first <= (sl + 1) * BSIZE) sum += it->second, it++;
        st[v] = sum; 
        return; 
    }
    int mid = (sl + sr) / 2;
    build(sl, mid, 2 * v);
    build(mid + 1, sr, 2 * v + 1);
    st[v] = st[2 * v] + st[2 * v + 1];
}

void update(int b, int diff, int sl = 1, int sr = SMAX, int v = 1){
    if(sl == sr) { st[v] += diff; return; }
    int mid = (sl + sr) / 2;
    if(b <= mid)update(b, diff, sl, mid, 2 * v);
    else update(b, diff, mid + 1, sr, 2 * v + 1);
    st[v] = st[2 * v] + st[2 * v + 1];
}

long long get_sum(int l, int r, int sl = 1, int sr = SMAX, int v = 1){
    if(l > r || sl > sr) return 0;
    if(l == sl && r == sr) return st[v];
    int mid = (sl + sr) / 2;
    return get_sum(l, min(r, mid), sl, mid, 2 * v) + get_sum(max(l, mid + 1), r, mid + 1, sr, 2 * v + 1);
}

inline int GetBucket(int _x){
    return (_x - 1) / BSIZE;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i], f[a[i]]++;
    build();
    for(int i = 0; i < q; i++){
        cin >> c >> x >> y;
        if(c == '!'){
            int b = GetBucket(a[x]);
            f[a[x]]--;
            update(b, -1);
            a[x] = y;
            f[y]++;
            b = GetBucket(y);
            update(b, 1);
        }
        else {
            long long b1 = GetBucket(x), b2 = GetBucket(y), res = 0;
            if(b1 == b2 || b1 + 1 == b2){
                auto it = f.lower_bound(x);
                while (it != f.end() && it->first <= y) res += it->second, it++;
            }
            else{
                int l = (b1 + 1) * BSIZE, r = b2 * BSIZE + 1;
                auto it = f.lower_bound(x);
                while (it != f.end() && it->first <= l) res += it->second, it++;
                it = f.lower_bound(r);
                while (it != f.end() && it->first <= y) res += it->second, it++;
                res += get_sum(b1 + 1, b2 - 1);
            }
            cout << res << '\n';
        }
    }
    return 0;
}