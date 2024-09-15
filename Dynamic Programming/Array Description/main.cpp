#include <iostream>

using namespace std;

const int NMAX = 1e5 + 1, MMAX = 101, mod = 1e9 + 7;
int n, m, x[NMAX], sol, dp[NMAX][MMAX];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 1; i <= m; i++) if(x[0] == i || x[0] == 0) dp[1][i] = 1;
    for(int i = 2; i <= n; i++){
        for(int k = 1; k <= m; k++){
            if(x[i - 1] != 0 && x[i - 1] != k){
                dp[i][k] = 0;
                continue;
            }

            for(int prev = k - 1; prev <= k + 1; prev++) if(prev >= 1 && prev <= m) dp[i][k] = (dp[i][k] + dp[i - 1][prev]) % mod;
        }
    }
    for(int i = 1; i <= m; i++) sol = (sol + dp[n][i]) % mod;
    cout << sol;
    return 0;
}