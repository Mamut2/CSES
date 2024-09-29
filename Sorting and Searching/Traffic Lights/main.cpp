#include <iostream>
#include <set>

using namespace std;

int n, x, a, st, en;
set<pair<int, int>> s;
multiset<long long> sz;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> n;
    s.insert({0, x});
    sz.insert(x);
    for(int i = 0; i < n; i++){
        cin >> a;
        auto k = s.upper_bound({a, 0});
        k--;
        st = (*k).first, en = (*k).second;
        s.erase(k);
        sz.erase(sz.find(en - st));
        s.insert({st, a}), s.insert({a, en});
        sz.insert(a - st), sz.insert((*k).second - a);
        cout << *(sz.rbegin()) << ' ';
    }
    return 0;
}