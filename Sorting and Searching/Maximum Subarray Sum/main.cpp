#include <iostream>

using namespace std;

const long long MAX_N = 2 * 1e5 + 1, INF = 1e11;
long long n, x, sum = 0, MaxSum = -INF;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(sum < 0) sum = x;
        else sum += x;
        MaxSum = max(sum, MaxSum);
    }
    cout << MaxSum;
    return 0;
}