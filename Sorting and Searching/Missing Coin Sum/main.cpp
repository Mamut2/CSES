#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
long long n, a[NMAX], x = 1;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        if(a[i] > x) {cout << x; return 0;}
        x += a[i];
    }
    cout << x;
    return 0;
}