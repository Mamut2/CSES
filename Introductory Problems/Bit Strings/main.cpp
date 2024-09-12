#include <iostream>

using namespace std;

const int mod = 1e9 + 7;
uint64_t n;

uint64_t power(uint64_t n, uint64_t x){
    uint64_t res = 1;
    while (x)
    {
        if(x & 1) res = res * n % mod;
        x >>= 1;
        n = n * n % mod;
    }
    return res;
}

int main(){
    cin >> n;
    cout << power(2, n);
    return 0;
}