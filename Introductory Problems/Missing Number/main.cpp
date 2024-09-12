#include <iostream>

using namespace std;

const int MAX_N = 2 * 1e5;

bool a[MAX_N];
int n, x;

int main(){
    cin >> n;
    for(int i = 0; i < n - 1; i++) cin >> x, a[x] = 1;
    for(int i = 1; i <= n; i++){
        if(!a[i]){
            x = i;
            break;
        }
    }
    cout << x;
    return 0;
}