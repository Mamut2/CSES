#include <iostream>

using namespace std;

int div(int n){
    int res = 0;
    for(int i = 1; i * i <= n; i++) if(n % i == 0) res += (i * i == n ? 1 : 2);
    return res;
}

int main(){
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        cout << div(x) << '\n';
    }
    return 0;
}