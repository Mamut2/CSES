#include <iostream>
#include <queue>

using namespace std;

int n;
queue<int> q;
bool ok = 0;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if(ok) cout << x << ' ';
        else q.push(x);
        ok = !ok;
    }
    return 0;
}