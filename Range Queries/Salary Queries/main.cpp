#include <iostream>
#include <algorithm>

using namespace std;

const int SMAX = 1e7 + 1;
long long st[4 * SMAX], f[SMAX];
int n, q, maxV;

void build(int sl = 0, int sr = n, int v = 1){
    if(sl == sr) st[v] = f[sl];
    int mid = (sl + sr) / 2;
    build(sl, mid, 2 * v);
    build(mid + 1, sr, 2 * v + 1);
    st[v] = st[2 * v] + st[2 * v + 1];
}



int main(){
    
    return 0;
}