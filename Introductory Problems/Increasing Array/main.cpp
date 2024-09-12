#include <iostream>

using namespace std;

const int MAX_N = 2 * 1e5;

uint64_t x[MAX_N], n, nr;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 1; i < n; i++) if(x[i] < x[i - 1]) nr += x[i - 1] - x[i], x[i] = x[i - 1];
    cout << nr; 
    return 0;
}