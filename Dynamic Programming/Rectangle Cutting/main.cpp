#include <iostream>

using namespace std;

const int INF = 1e9;
int dp[501][501], A, B;

int main(){
    cin >> A >> B;
    for(int a = 1; a <= A; a++)
        for(int b = 1; b <= B; b++)
            dp[a][b] = INF;
    for(int a = 1; a <= A; a++){
        for(int b = 1; b <= B; b++){
            if(a == b) dp[a][b] = 0;
            for(int i = 1; i <= a; i++) dp[a][b] = min(dp[a][b], dp[a - i][b] + dp[i][b] + 1);
            for(int i = 1; i <= b; i++) dp[a][b] = min(dp[a][b], dp[a][b - i] + dp[a][i] + 1);
        }
    }
    cout << dp[A][B];
    return 0;
}