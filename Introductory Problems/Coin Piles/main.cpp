#include <iostream>

using namespace std;

int t, a, b;

int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> a >> b;
        if((a + b) % 3 == 0 && (max(a, b) <= 2 * min(a, b))) cout << "YES" << '\n';
        else cout << "NO" << '\n'; 
    }
    return 0;
}