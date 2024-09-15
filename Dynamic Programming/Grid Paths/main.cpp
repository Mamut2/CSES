#include <iostream>

using namespace std;

const int mod = 1e9 + 7;
int n, dp[1001][1001];
char c;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> c;
            if(c == '*') dp[i][j] = -1;
            else dp[i][j] = 0;
        }
    if(dp[1][1] == -1) {cout << 0; return 0;}
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(dp[i][j] != -1){
                dp[i][j] += (dp[i][j - 1] != -1 ? dp[i][j - 1] : 0);
                dp[i][j] += (dp[i - 1][j] != -1 ? dp[i - 1][j] : 0);
                while(dp[i][j] >= mod) dp[i][j] -= mod;
            }
        }
    if(dp[n][n] == -1) cout << 0;
    else cout << dp[n][n];
    return 0;   
}