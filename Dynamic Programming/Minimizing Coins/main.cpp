#include <iostream>

using namespace std;

const int MAX_SUM = 1e6 + 1, INF = 1e9;
int n, x, a[101], dp[MAX_SUM];

int main(){
    cin >> n >> x;
    for(int i = 0; i <= x; i++) dp[i] = INF;
    for(int i = 0; i < n; i++) cin >> a[i], dp[a[i]] = 1;
    for(int i = 1; i <= x; i++) for(int j = 0; j < n; j++) if(i - a[j] >= 0) dp[i] = min(dp[i], dp[i - a[j]] + 1);
    if(dp[x] != INF) cout << dp[x];
    else cout << -1;
    return 0;   
}