#include <iostream>
#include <set>

using namespace std;

int n, x;
multiset<int> s;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(s.empty()) s.insert(x);
        else{
            bool inserted = false;
            auto ind = s.upper_bound(x);
            if(ind != s.end() && *ind > x) s.erase(ind), s.insert(x), inserted = true;
            if(!inserted) s.insert(x);
        }
    }
    cout << s.size();
    return 0;
}