#include <iostream>
#include <queue>

using namespace std;

int n, cnt, k, m[2 * (int)1e5];
queue<int> q;

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) q.push(i), m[i] = k % i;
    while (!q.empty())
    {
        int x = q.front();
        if(cnt == m[q.size()]) cout << x << ' ', cnt = -1, q.pop();
        else q.pop(), q.push(x);
        cnt++;
    }
    return 0;
}