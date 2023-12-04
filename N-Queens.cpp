#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool isSafe(vector<string> board, int r, int c, int n) {
        int R = r, C = c;
        while(r >= 0 && c >= 0) {
            if(board[r][c] == 'Q') return false;                               // going north west
            r--, c--;
        }
        r = R, c = C;
        while(c >= 0) {
            if(board[r][c] == 'Q') return false;                               // going west
            c--;
        }
        r = R, c = C;
        while(r < n && c >= 0) {
            if(board[r][c] == 'Q') return false;               // going south west
            r++, c--;
        }
        return true;
    }
    void f(vector<vector<string>>& res, vector<string> board, int n, int c) {
        if(c == n) {
            res.emplace_back(board);
            return;
        }
            for(int r = 0; r < n; r++) {
                if(isSafe(board, r, c, n)) {
                    board[r][c] = 'Q';  
                    f(res, board, n, c + 1);
                    board[r][c] = '.';
                }
            }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');
        for(int r = 0; r < n; r++) {
            board[r] = s;
        }
        f(res, board, n, 0);
        return res;
    }
};

class Solution {
    void f(vector<vector<string>>& res, vector<string> board, vector<int> leftRow, vector<int> leftUpDiag, vector<int> leftDownDiag, int n, int c) {
        if(c == n) {
            res.emplace_back(board);
            return;
        }
        for(int r = 0; r < n; r++) {

            if(leftRow[c] == 0 && leftUpDiag[(n - 1) + (c - r)] == 0 && leftDownDiag[r + c] == 0) {
                board[r][c] = 'Q'; 
                leftRow[c] = 1, leftUpDiag[(n - 1) + (c - r)] = 1, leftDownDiag[r + c] = 1; 

                f(res, board, leftRow, leftUpDiag, leftDownDiag, n, c + 1);

                board[r][c] = '.';
                leftRow[c] = 0, leftUpDiag[(n - 1) + (c - r)] = 0, leftDownDiag[r + c] = 0;
                
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');
        for(int r = 0; r < n; r++) {
            board[r] = s;
        }
        vector<int> leftRow(n, 0);
        vector<int> leftUpDiag(2*n - 1, 0);
        vector<int> leftDownDiag(2*n - 1, 0);
        f(res, board, leftRow, leftUpDiag, leftDownDiag, n, 0);
        return res;
    }
};

int main() {
    
    return 0;
}