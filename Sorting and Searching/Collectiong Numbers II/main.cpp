#include <iostream>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
int n, m, index[NMAX], x, a, b, ar[NMAX];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> ar[i], index[ar[i]] = i;
    for(int i = 0; i < m; i++){
        x = 1;
        cin >> a >> b;
        swap(ar[a], ar[b]);
        swap(index[ar[a]], index[ar[b]]);
        for(int i = 2; i <= n; i++) if(index[i] < index[i - 1]) x++;
        cout << x << '\n';
    }
    return 0;
}