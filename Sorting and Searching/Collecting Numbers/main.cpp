#include <iostream>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
int n, m, index[NMAX], x;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x, index[x] = i;
    x = 0;
    for(int i = 2; i <= n; i++) if(index[i] < index[i - 1]) x++;
    cout << x + 1;
    return 0;
}