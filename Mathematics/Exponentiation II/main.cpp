#include <iostream>

using namespace std;

int n;

long long power(long long a, long long b, long long mod){
    long long res = 1;
    while (b)
    {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        cout << power(a, power(b, c, 1e9 + 6), 1e9 + 7) << '\n';
    }
    return 0;
}