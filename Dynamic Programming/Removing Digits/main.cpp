#include <iostream>

using namespace std;

const int MAXN = 1e6 + 1, INF = 1e9;
int n, dp[MAXN];                          // merge si greedy (ii si mai rapid)

int main(){
    cin >> n;
    for(int i = 0; i <= n; i++) dp[i] = INF;
    dp[n] = 0;
    for(int i = n; i > 0; i--){
        int temp = i;
        while(temp){
            dp[i - temp % 10] = min(dp[i] + 1, dp[i - temp % 10]);
            temp /= 10;
        }
    }
    cout << dp[0];
    return 0; 
}