#include <iostream>
#include <bitset>

using namespace std;

uint64_t x, n;

int main(){
    cin >> n;
    for(int i = 0; i < (1 << n); i++){;
        bitset<32> b;
        b = i;
        b ^= (b >> 1);
        for(int i = n - 1; i >= 0; i--) cout << b[i];
        cout << '\n';
    }
    return 0;   
}