#include <iostream>
#include <algorithm>

using namespace std;

long long n, p[200001], res;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);
    for(int i = 0; i < n; i++) res += abs(p[n / 2] - p[i]);
    cout << res;
    return 0;
}