// #include <fstream>
#include <iostream>

using namespace std;

// ifstream fin("data.in");
// ofstream fout("data.out");

void f(uint64_t &n){
    cout << n << ' ';
    if(n == 1) return;
    if(n & 1) n = n * 3 + 1;
    else n /= 2;
    f(n);
}

int main(){
    uint64_t k;
    cin >> k;
    f(k);
    return 0;
}