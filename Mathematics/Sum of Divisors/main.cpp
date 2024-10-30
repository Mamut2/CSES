#include <iostream>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7, two_mod_inv = 500000004;

ll gauss(ll a, ll b){
    return ((((a + b) % mod) * ((b - a + 1) % mod)) % mod) * two_mod_inv % mod;
}

int main(){
    ll n, res = 0, i = 1;
    cin >> n;
    while(i <= n){
        ll q = n / i, next = n / q + 1;
        res = (res + gauss(i, next - 1) * q) % mod;
        i = next;
    }
    cout << res;
    return 0;
}