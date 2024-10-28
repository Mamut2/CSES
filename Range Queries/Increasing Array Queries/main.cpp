#include <iostream>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
long long n, q, a[NMAX], st[4 * NMAX];
pair<int, long long> m[4 * NMAX];

void build(int sl = 1, int sr = n, int v = 1){
    if(sl == sr) { st[v] = a[sl], m[v].first = sl, m[v].second = a[sl]; return; }
    int mid = (sl + sr) / 2;
    build(sl, mid, 2 * v);
    build(mid + 1, sr, 2 * v + 1);
    st[v] = st[2 * v] + st[2 * v + 1];
    if(m[2 * v].second > m[2 * v + 1].second || m[2 * v].second == m[2 * v + 1].second) m[v].first = m[2 * v].first, m[v].second = m[2 * v].second;
    else m[v].first = m[2 * v + 1].first, m[v].second = m[2 * v + 1].second;
}

long long get_sum(int l, int r, int sl = 1, int sr = n, int v = 1){
    if(l > r || sl > sr) return 0;
    if(l == sl && r == sr) return st[v];
    int mid = (sl + sr) / 2;
    return get_sum(l, min(mid, r), sl, mid, 2 * v) + get_sum(max(l, mid + 1), r, mid + 1, sr, 2 * v + 1);
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build();
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
    }
    return 0;
}