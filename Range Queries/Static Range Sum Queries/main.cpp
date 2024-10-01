#include <iostream>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
long long ai[4 * NMAX], x[NMAX], n, q, p1, p2;

void construct(int st, int dr, int ind){
    if(st == dr) { ai[ind] = x[st]; return; }
    int mid = (st + dr) / 2;
    construct(st, mid, 2 * ind);
    construct(mid + 1, dr, 2 * ind + 1);

    ai[ind] = ai[2 * ind] + ai[2 * ind + 1];
}

long long sum(int a, int b, int st, int dr, int ind){
    if(a > b || st > dr) return 0;
    if(st == a && dr == b) return ai[ind];
    int mid = (st + dr) / 2;
    return sum(a, min(b, mid), st, mid, 2 * ind) + sum(max(a, mid + 1), b, mid + 1, dr, ind * 2 + 1);
}

int main(){
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> x[i];
    construct(0, n - 1, 1);
    for(int i = 0; i < q; i++){
        cin >> p1 >> p2;
        cout << sum(p1 - 1, p2 - 1, 0, n - 1, 1) << '\n';
    }
    return 0;
}