#include <iostream>

using namespace std;

const int NMAX = 101, XMAX = 100001;
int n, dp[NMAX][XMAX], a[NMAX], maxi, nr;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], maxi += a[i];
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int target = 0; target <= maxi; target++){
            dp[i][target] = dp[i - 1][target];
            if(target - a[i] >= 0 && dp[i - 1][target - a[i]]) dp[i][target] = 1;
        }
    }
    for(int i = 1; i <= maxi; i++) if(dp[n][i]) nr++;
    cout << nr << '\n';
    for(int i = 1; i <= maxi; i++) if(dp[n][i]) cout << i << ' ';
    return 0;
}