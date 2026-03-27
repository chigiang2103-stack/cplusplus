#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool check_valid(vector<vector<char>>& board, string &word, vector<vector<bool>>&vis,int x, int y ,int start) {
        int n = board.size();
        int m = board[0].size();
        if (x < 0 || x >= n || y < 0 || y >=m) return false;
        if (vis[x][y]) return false;
        if (board[x][y]!=word[start]) return false;



        return true;
    }
    bool backtrack(vector<vector<char>>& board, string &word, vector<vector<bool>>&vis,int x, int y ,int start) {
        if (word.size() == start) {
            return true;
        }
        int n = board.size();
        int m = board[0].size();

        int dx[4]={0,0,-1,1};
        int dy[4] = {1,-1,0,0};

        for (int i = 0 ; i<4;i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (check_valid(board,word,vis,new_x,new_y,start+1)) {
                vis[new_x][new_y] = true;
                if (backtrack(board,word,vis,new_x,new_y,start+1)) return true;
                vis[new_x][new_y] = false;
            }

        }
        return false;


    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for (int i = 0 ;i < n ;i++) {
            for (int j = 0 ; j < m ; j++) {
                if (check_valid(board,word,vis,i,j,0)) {
                    vis[i][j] = true;
                    if (backtrack(board,word,vis,i,j,0)) return true;
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
};