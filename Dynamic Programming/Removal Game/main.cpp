#include <iostream>

using namespace std;

const int NMAX = 5001;
long long n, a[NMAX], sum, dp[NMAX][NMAX];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    for(int l = n - 1; l >= 0; l--){
        for(int r = l; r < n; r++){
            if(l == r) dp[l][r] = a[l];
            else{
                dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
            }
        }
    }
    cout << (sum + dp[0][n - 1]) / 2;
    return 0;
}