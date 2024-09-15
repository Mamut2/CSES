#include <iostream>

using namespace std;

const int NMAX = 1001, XMAX = 1e5 + 1;
int n, x, price[NMAX], pages[NMAX], dp[XMAX];

int main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> price[i];
    for(int i = 0; i < n; i++) cin >> pages[i];
    for(int k = 0; k < n; k++){
        for(int i = x; i > 0; i--){
            if(price[k] > i) continue;

            dp[i] = max(dp[i], pages[k] + dp[i - price[k]]);
        }
    }
    cout << dp[x];
    return 0;
}