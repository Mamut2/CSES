#include <iostream>

using namespace std;

const int mod = 1e9 + 7;
int n;

long long power(long long a, long long b){
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
        long long a, b;
        cin >> a >> b;
        cout << power(a, b) << '\n';
    }
    return 0;
}