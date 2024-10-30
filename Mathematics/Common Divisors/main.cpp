#include <iostream>

using namespace std;

const int NMAX = 1e6 + 1;
int n, f[NMAX], maxD, a;

void div(int x){
    for(int i = 1; i * i <= x; i++) 
        if(x % i == 0) {
            if(f[i]) maxD = max(maxD, i);
            if(f[x / i]) maxD = max(maxD, x / i);
            f[x / i] = f[i] = 1;
        }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a, div(a);
    cout << maxD;
    return 0;
}