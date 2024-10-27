#include <iostream>

using namespace std;

const long long NMAX = 2 * 1e5 + 1;
long long a[NMAX], sum[4 * NMAX], prefix[4 * NMAX], suffix[4 * NMAX], st[4 * NMAX];
long long n, q;

void build(long long sl = 1, long long sr = n, long long v = 1){
    if(sl == sr) { 
        sum[v] = a[sl];
        prefix[v] = suffix[v] = max(0LL, a[sl]);
        st[v] = max(0LL, a[sl]);
        return;
    }
    long long mid = (sl + sr) / 2;
    build(sl, mid, 2 * v);
    build(mid + 1, sr, 2 * v + 1);
    sum[v] = sum[2 * v] + sum[2 * v + 1];
    prefix[v] = max(sum[2 * v] + prefix[2 * v + 1], prefix[2 * v]);
    suffix[v] = max(sum[2 * v + 1] + suffix[2 * v], suffix[2 * v + 1]);
    st[v] = max(st[2 * v + 1], max(st[2 * v], prefix[2 * v + 1] + suffix[2 * v]));
}

void update(long long pos, long long val, long long sl = 1, long long sr = n, long long v = 1){
    if(sl == sr) { 
        sum[v] = val;
        prefix[v] = suffix[v] = max(0LL, val);
        st[v] = max(0LL, val);
        return;
    }
    long long mid = (sl + sr) / 2;
    if(pos <= mid) update(pos, val, sl, mid, 2 * v);
    else update(pos, val, mid + 1, sr, 2 * v + 1);
    sum[v] = sum[2 * v] + sum[2 * v + 1];
    prefix[v] = max(sum[2 * v] + prefix[2 * v + 1], prefix[2 * v]);
    suffix[v] = max(sum[2 * v + 1] + suffix[2 * v], suffix[2 * v + 1]);
    st[v] = max(st[2 * v + 1], max(st[2 * v], prefix[2 * v + 1] + suffix[2 * v]));
}

int main(){
    cin >> n >> q;
    for(long long i = 1; i <= n; i++) cin >> a[i];
    build();
    for(long long i = 0; i < q; i++){
        long long k, x;
        cin >> k >> x;
        update(k, x);
        cout << st[1] << '\n';
    }
    return 0;
}