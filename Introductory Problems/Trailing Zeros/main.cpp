#include <iostream>

using namespace std;

int n;

int trailing0(int n){
    if(n == 0) return 0;
    return n / 5 + trailing0(n / 5);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cin >> n;
    cout << trailing0(n);
    return 0;
}