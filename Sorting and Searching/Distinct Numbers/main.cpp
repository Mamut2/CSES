#include <iostream>
#include <set>

using namespace std;

set<int> s;
int n, x;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x, s.insert(x);
    cout << s.size();
    return 0;
}