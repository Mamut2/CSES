#include <iostream>

using namespace std;

const int mod = 1e9 + 7, NMAX = 1e6 + 1;
int dp[NMAX], n;

int main(){
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int k = 1; k <= 6; k++) 
            if(i - k >= 0) {
                dp[i] += dp[i - k];
                while(dp[i] >= mod) dp[i] -= mod;
            }
    }
    cout << dp[n];
    return 0;
}