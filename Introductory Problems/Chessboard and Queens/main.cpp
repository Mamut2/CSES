#include <iostream>
#include <cstring>

using namespace std;

int row[9], col[9], diag[20], diag2[20], res;
char board[9][9];

bool valid(int r, int c){
    if(row[r] || col[c] || diag[8 + r - c] || diag2[r + c] || board[r][c] == '*') return 0;
    return 1;
}

void back(int r){
    if(r == 8){
        res++;
        return;
    }
    for(int i = 0; i < 8; i++){
        if(valid(r, i)){
            row[r] = col[i] = diag[8 + r - i] = diag2[r + i] = 1;
            board[r][i] = 'D';
            back(r + 1);
            row[r] = col[i] = diag[8 + r - i] = diag2[r + i] = 0;
            board[r][i] = '.';
        }
    }
}

int main(){
    for(int i = 0; i < 8; i++) cin.getline(board[i], 9);
    back(0);
    cout << res;
    return 0;
}