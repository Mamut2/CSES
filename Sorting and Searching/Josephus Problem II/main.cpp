#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int NMAX = 1e5;
int n, root, k, row = 0, col = 0;
vector<vector<int>> m;
vector<int> v;

int main(){
    cin >> n >> k;
    root = sqrt(n);
    for(int i = 1; i <= n; i++){
        if(v.size() > root) m.push_back(v), v.clear();
        v.push_back(i);
    }
    if(!v.empty()) m.push_back(v), v.clear();
    
    for(int i = 0; i < n; i++){
        int el = k % (n - i);
        while(el){
            if(m[row].size() > el + col) col += el, el = 0;
            else{
                el -= (m[row].size() - col);
                col = 0;
                row++;
            }  
            if(row >= m.size()) row = 0;
        }
        while (m[row].size() <= col)
        {
            row++;
            col = 0;
            if(row >= m.size()) row = 0;
        }
        cout << m[row][col] << ' ';
        if(i != n - 1) {
            m[row].erase(m[row].begin() + col);
            while (m[row].size() <= col)
            {
                row++;
                col = 0;
                if(row >= m.size()) row = 0;
            }
        }
    }
    return 0;
}