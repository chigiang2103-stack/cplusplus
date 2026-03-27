#include <bits/stdc++.h>
using namespace std;



bool check(vector<vector<char>>& board , int r ,int c , char x) {
    for (int i = 0 ; i < 9 ; i++) {
        if (board[r][i]==x) return false;
    }
    for (int j = 0 ; j < 9 ; j++) {
        if (board[j][c]==x) return false;
    }
    for (int i = 0 ; i<3;i++) {
        for (int j = 0 ; j < 3; j++) {
            if (board[i + (r/3)*3][j + (c/3)*3]==x) return false;
        }
    }

    return true;
}

void sodoku(vector<vector<char>>& board , int r ,int c ) {

    if (c== 9) {
        c=0;
        r++;
    }
    if (r==9) {
        for (auto row : board) {
            for (auto col : row)  {
                cout << col ;
            }
            cout << endl;
        }
        exit(0);
    }

    if (board[r][c]!='.') {
        sodoku(board , r , c +1);
    }
    else {
        for (char i = '1' ; i <= '9';i++) {
            if (check(board,r,c,i)) {
                board[r][c]=i;
                sodoku(board,r,c+1) ;
                board[r][c]='.';
            }
        }


    }
}




int main () {
    vector<vector<char>> board(9,vector<char>(9));
    for (int i = 0 ; i<9;i++) {
        for (int j = 0 ;j <9 ; j++) {
            cin >> board[i][j];
        }
    }
    sodoku(board,0,0);






    return 0;
}