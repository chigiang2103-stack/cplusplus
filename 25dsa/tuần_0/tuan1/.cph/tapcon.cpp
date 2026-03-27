#include <bits/stdc++.h>
using namespace std;



vector<vector<vector<bool>>>ans;

bool check_valid(int r , int c ,vector<vector<bool>>chessBoard ) {
    int n = chessBoard.size();
    for (int i = 0 ; i < n;i++) {
        if (chessBoard[r][i]) return false;
    }
     for (int j = 0 ; j < n;j++) {
        if (chessBoard[j][c]) return false;
    }
    for (int i = 0 ; r - i >= 0 && c + i < n ;i++) {
        if (chessBoard[r-i][c+i]) return false;
    }
     for (int i = 0 ; r - i >= 0 && c - i  >= 0;i++) {
        if (chessBoard[r-i][c-i]) return false;
    }
    return true;
}
void nQueen(vector<vector<bool>>chessBoard, int step ) {
    int n  = chessBoard.size();
    if (step==n) {
        ans.push_back(chessBoard);
        return;
    }

    for (int i = 0 ;i < n;i++) {
        if (check_valid(step,i,chessBoard)) {
            chessBoard[step][i] = true;
            nQueen(chessBoard,step+1);
            chessBoard[step][i] = false;
        }
    }

}

int main() {
    int n ;
    cin >> n;

    vector<vector<bool>>mat(n,vector<bool>(n,false));


    nQueen(mat,0);

    cout << ans.size() << endl;
    for (auto v : ans) {
        for (auto row : v) {
            for (auto col : row) {
                if (col) cout << "Q"; 
                else cout << ".";
            }
            cout << endl;
        }
        cout << endl;
    }





    

    return 0;
}