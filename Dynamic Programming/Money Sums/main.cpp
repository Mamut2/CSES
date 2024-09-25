#include <iostream>

using namespace std;

const int NMAX = 101;
int dp[1000001][101], n, a[NMAX], nr, maxi;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], maxi += a[i];
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int target = 0; target <= maxi; target++){
            dp[target][i] = dp[target][i - 1];
            int prev_sum = target - a[i];
            if(prev_sum >= 0 && dp[prev_sum][i - 1]) dp[target][i] = 1;
        }
    }
    for(int i = 1; i <= 100001; i++) if(dp[i][n] > 0) nr++;
    cout << nr << '\n';
    for(int i = 1; i <= 100001; i++) if(dp[i][n] > 0) cout << i << ' ';
    return 0;
}