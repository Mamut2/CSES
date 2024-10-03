#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
long long a, b, p, n, res;
set<pair<int, long long>> s;

struct Project{
    long long s, e, r;
} x[NMAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a >> b >> p, x[i] = {a, b, p};
    sort(x, x + n, [](Project p1, Project p2){ return p1.e < p2.e; });
    s.insert({0, 0});
    for(int i = 0; i < n; i++){
        auto k = s.lower_bound({x[i].s, -1});
        k--;
        res = max(res, k->second + x[i].r);
        s.insert({x[i].e, res});
    }
    cout << res;
    return 0;
}