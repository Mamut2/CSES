#include <iostream>

using namespace std;

const int MAX_SUM = 1e6 + 1, INF = 1e9, mod = 1e9 + 7;
int n, x, a[101], dp[MAX_SUM];

int main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> a[i], dp[a[i]] = 1;
    for(int i = 1; i <= x; i++) 
        for(int j = 0; j < n; j++) 
            if(i - a[j] >= 0){
                dp[i] += dp[i - a[j]];
                while(dp[i] >= mod) dp[i] -= mod;
            }
    cout << dp[x];
    return 0;   
}