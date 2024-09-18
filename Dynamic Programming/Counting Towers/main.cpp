#include <iostream>

using namespace std;

const long long mod = 1e9 + 7, NMAX = 1e6 + 1;
unsigned long long n, t, dp[NMAX][2];

int main(){
    cin >> t;

    dp[1][0] = 1, dp[1][1] = 1;

    for(int i = 1; i < NMAX - 1; i++){
        dp[i][0] %= mod;
        dp[i][1] %= mod;
        dp[i + 1][0] += 2 * dp[i][0];
        dp[i + 1][0] += dp[i][1];
        dp[i + 1][1] += dp[i][0];
        dp[i + 1][1] += 4 * dp[i][1];
    }

    for(int i = 0; i < t; i++){
        cin >> n;
        cout << (dp[n][1] + dp[n][0]) % mod << '\n';
    }
    return 0;
}