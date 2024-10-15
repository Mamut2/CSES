#include <iostream>

using namespace std;

const int NMAX = 1001;
int part[NMAX][NMAX], n, q;
char c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int s = 0;
        for(int j = 1; j <= n; j++){
            cin >> c;
            if(c == '*') s++;
            part[i][j] = part[i - 1][j] + s;
        }
    }
    for(int i = 0; i < q; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        cout << part[x2][y2] - part[x1 - 1][y2] - part[x2][y1 - 1] + part[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}