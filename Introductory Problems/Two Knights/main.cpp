#include <iostream>

using namespace std;

const int MAX_N = 1e4 + 1;

uint64_t res, n;

int main(){
    cin >> n;
    for(uint64_t k = 1; k <= n; k++){
        res = k * k * (k * k - 1) / 2 - 4 * (k - 1) * (k - 2);
        cout << res << '\n';
    }
    return 0;
}