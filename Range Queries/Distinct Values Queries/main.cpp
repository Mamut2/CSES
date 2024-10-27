#include <iostream>
#include <set>

using namespace std;

const int NMAX = 2 * 1e3 + 1;
int n, q, a[NMAX], st[4 * NMAX];
set<int> s[4 * NMAX];

void build(int sl = 1, int sr = n, int v = 1){
    if(sl == sr) { 
        s[v].insert(a[sl]);
        st[v] = 1;
        return;
    }
    int mid = (sl + sr) / 2;
    build(sl, mid, 2 * v);
    build(mid + 1, sr, 2 * v + 1);
    s[v].insert(s[2 * v].begin(), s[2 * v].end());
    s[v].insert(s[2 * v + 1].begin(), s[2 * v + 1].end());
    st[v] = s[v].size();
}

int get_distinct(int l, int r, int sl = 1, int sr = n, int v = 1){
    if(l > r || sl > sr) return 0;
    if(l == sl && r == sr) return st[v];
    int mid = (sl + sr) / 2;
    return get_distinct(l, min(mid, r), sl, mid, 2 * v) + get_distinct(max(l, mid + 1), r, mid + 1, sr, 2 * v + 1);
}

int main(){ 
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build();
    for(int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;
        cout << get_distinct(a, b) << '\n';
    }
    return 0;
}