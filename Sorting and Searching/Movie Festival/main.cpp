#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct event
{
    int s, f;
};

vector<event> events;
event lastE = {-1, -1};
int n, a, b, nr;

bool cmp(event a, event b){
    if(a.f == b.f) return a.s < b.s;
    return a.f < b.f;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        events.push_back({a, b});
    }
    sort(events.begin(), events.end(), cmp);
    for(int i = 0; i < events.size(); i++){
        if(lastE.f <= events[i].s) nr++, lastE = events[i];
    }
    cout << nr;
    return 0;
}