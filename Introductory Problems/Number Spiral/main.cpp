#include <iostream>

using namespace std;

uint64_t t, x, y;

int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> x >> y;
        if(x == y && x == 1) cout << 1 << '\n';
        else{
            if(x > y) cout << ((x & 1) ? x * x - 2 * x + y + 1 : x * x - y + 1);
            else if(x < y) cout << ((y & 1) ? y * y - x + 1 : y * y - 2 * y + x + 1);
            else cout << (x * x - x + 1);
            cout << '\n';
        }
    }
    return 0;
}