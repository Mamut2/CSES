#include <iostream>

using namespace std;

long long n, a[21], res;

long long solve(int k, long long sum1, long long sum2){
    if(k == n) return max(sum1, sum2) - min(sum1, sum2);
    return min(solve(k + 1, sum1 + a[k], sum2), solve(k + 1, sum1, sum2 + a[k]));
}

int main(){
    cin >> n;
    if(n < 2) { cin >> n; cout << n; return 0; }
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << solve(0, 0, 0);
    return 0;
}