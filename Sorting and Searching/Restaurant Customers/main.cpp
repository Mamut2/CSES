#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int NMAX = 4 * 1e5 + 1;

struct event
{
    int type, time;
};

bool cmp(event a, event b){
    return a.time < b.time;
}

vector<event> x;
int n, res, a, b, cur;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        x.push_back({0, a}), x.push_back({1, b});
    }
    sort(x.begin(), x.end(), cmp);
    for(int i = 0; i < x.size(); i++){
        if(x[i].type) cur--;
        else cur++;
        res = max(res, cur);
    }
    cout << res;
    return 0;
}