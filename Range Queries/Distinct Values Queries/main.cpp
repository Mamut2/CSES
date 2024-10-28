#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
int n, q, a[NMAX], bit[NMAX];
vector<vector<pair<int, int>>> queries(NMAX);
vector<int> sol(NMAX);
map<int, int> last; 

void update(int pos, int val){
    for(; pos <= n; pos += pos & -pos) bit[pos] += val;
}

int get_val(int pos){
    int res = 0;
    for(; pos > 0; pos -= pos & -pos) res += bit[pos];
    return res;
}

int main(){ 
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;
        queries[a].push_back({b, i});
    }
    for(int i = n; i > 0; i--){
        
        if(last.count(a[i]) > 0) update(last[a[i]], -1);
        last[a[i]] = i;
        update(i, 1);

        for(auto &qr : queries[i]) sol[qr.second] = get_val(qr.first);
    }
    for(int i = 1; i <= q; i++) cout << sol[i] << '\n';
    return 0;
}