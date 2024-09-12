#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2 * 1e5 + 1;
long long n, m, k, a[MAX_N], b[MAX_N], res;
 
int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    for(int i = n - 1, j = m - 1; i >= 0 && j >= 0; ) {
        if(abs(a[i] - b[j]) <= k) res++, i--, j--;
        else if(a[i] > b[j]) i--;
        else j--;
    }
    cout << res;
    return 0;   
}