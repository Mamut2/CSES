#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int NMAX = 2 * 1e5 + 1;
int n, target, pos1 = -1, pos2 = -1, a[NMAX];
map<int, int> ap;

int main(){
    cin >> n >> target;
    for(int i = 0; i < n; i++) cin >> a[i], ap[a[i]]++;
    for(int i = 0; i < n; i++){
        if(ap[target - a[i]]){
            if(target - a[i] == a[i] && ap[a[i]] < 2) continue;
            pos1 = i;
            break;
        }
    }
    if(pos1 != - 1) for(int i = pos1 + 1; i < n; i++) if(a[i] == target - a[pos1]) { pos2 = i; break; }
    if(pos1 != -1 && pos2 != -1) cout << pos1 + 1 << ' ' << pos2 + 1;
    else cout << "IMPOSSIBLE";
    return 0;
}