#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n, x, p[10000];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(v.empty()){ v.push_back(x); continue;}
        if(x > v.back()) /*p[x] = v.back(),*/ v.push_back(x);
        else{
            int index = lower_bound(v.begin(), v.end(), x) - v.begin();
            v[index] = x;
            //p[x] = v[index - 1];
        }
    }
    x = v.back();
    cout << v.size() << '\n';
    //for(int i = 0; i < v.size(); i++) cout << x << ' ', x = p[x];              reconstruct
    return 0;
}