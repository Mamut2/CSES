#include <iostream>

using namespace std;

const int mod = 1e9 + 7, MAX_SUM = 500 * 501 / 2;
long long n, sum, dp[MAX_SUM], l[MAX_SUM];

int main(){
    cin >> n;
    sum = (n * (n + 1)) / 2;
    if(sum & 1){ cout << 0; return 0; }
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        for(long long target = sum / 2; target > 0; target--)
            if(target - i >= 0) dp[target] = (dp[target] + dp[target - i]) % mod;
    }
    cout << dp[sum / 2];
    return 0;
}