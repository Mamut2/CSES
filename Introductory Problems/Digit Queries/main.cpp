#include <iostream>

using namespace std;

long long n, b, d, q, ind, res;

long long power(long long x, long long y){
    long long res = 1;
    while (y)
    {
        if(y & 1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

int main(){
    cin >> q;
    for(int i = 0; i < q; i++){
        b = 9, d = 1;
        cin >> n;
        while (n - b * d > 0)
        {
            n -= b * d;
            b *= 10, d++;
        }
        ind = n % d;
        res = power(10, d - 1) + (n - 1) / d;
        if(ind) res /= power(10, d - ind);
        cout << res % 10 << '\n';
    }
    return 0;
}