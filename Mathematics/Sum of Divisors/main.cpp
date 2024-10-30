#include <iostream>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll DivSum(ll n){
    ll res = 0;
    for(ll i = 1; i * i <= n; i++) 
        res = res + i;
        while(res >= mod) res -= mod;
    }
    return res;
}

int main(){
    ll n, res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        res = (res + DivSum(i));
        while(res >= mod) res -= mod;
    }
    cout << res;
    return 0;
}