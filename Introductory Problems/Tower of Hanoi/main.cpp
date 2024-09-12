#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> moves;

void hanoi(int n, int s, int e){
    if(n == 1){
        moves.push_back({s, e});
        return;
    }
    int aux = 6 - s - e;
    hanoi(n - 1, s, aux);
    moves.push_back({s, e});
    hanoi(n - 1, aux, e);
}

int main(){
    int n;
    cin >> n;
    hanoi(n, 1, 3);
    cout << moves.size() << '\n';
    for(auto p : moves) cout << p.first << ' ' << p.second << '\n';
    return 0;
}