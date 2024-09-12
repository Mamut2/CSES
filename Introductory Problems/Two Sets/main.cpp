#include <iostream> 
#include <vector> 

using namespace std;

const int MAX_N = 1e6 + 1;

int64_t n, sum, cnt, target;
bool f[MAX_N];

int main(){
    cin >> n;
    sum = (n * (n + 1)) / 2;
    if(sum & 1) cout << "NO";
    else{
        cout << "YES" << '\n';
        target = sum / 2;
        for(int i = n; i > 0 && target; i--) if(target - i >= 0) f[i] = 1, target -= i, cnt++;
        cout << cnt << '\n';
        for(int i = 1; i <= n; i++) if(f[i]) cout << i << ' ';
        cout << '\n' << n - cnt << '\n';
        for(int i = 1; i <= n; i++) if(!f[i]) cout << i << ' ';
    }
    return 0;
}