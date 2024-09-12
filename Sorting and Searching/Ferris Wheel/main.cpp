#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int N_MAX = 2 * 1e5 + 1;
int n, x, a[N_MAX], p, q, res;
 
int main()
{
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    p = n - 1, q = 0;
    while(p >= q){
        if(a[p] + a[q] > x) p--, res++;
        else q++, p--, res++;
    }
    cout << res;
    return 0;
}