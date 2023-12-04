#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int ROWS = board.size();
        int COLS = board[0].size();
            if(r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != 'O') {
                return;
            }
            board[r][c] = 'T';
            dfs(board, r + 1, c);
            dfs(board, r - 1, c);
            dfs(board, r, c + 1);
            dfs(board, r, c - 1);
    } 
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();
        // checking borders
        // only zeroes emerging the borders will not be surroundedS
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if((board[i][j] == '0') && (i == 0 || i == ROWS-1) || (j == COLS-1 || j == 0))
                    dfs(board, i, j);
            }
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }       
            }
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if(board[i][j] == 'T') {
                    board[i][j] = 'O';
                }          
            }
        }
    }
};               

int main() {
    
    return 0;
}