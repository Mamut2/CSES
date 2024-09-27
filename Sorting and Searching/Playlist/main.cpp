#include <iostream>
#include <map>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
int n, a[NMAX], l, r, maxL = 1;
map<int, int> m;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    l = 0, r = 1;
    m[a[l]] = 1;
    while (l <= r && r < n)
    {
        m[a[r]]++;
        while (m[a[r]] > 1)
        {
            m[a[l]]--;
            l++;
        }
        maxL = max(maxL, r - l + 1);
        r++;
    }
    cout << maxL;
    return 0;
}