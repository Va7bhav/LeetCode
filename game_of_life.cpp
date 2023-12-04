#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int countNeighbours(vector<vector<int>> board, int r, int c) {
        int ROWS = board.size();
        int COLS = board[0].size();
        int count_1 = 0;
        for(int i = -1; i <= 1 ; i++) {
            for(int j = -1; j <= 1; j++) {
                int R = r + i;
                int C = c + j;
                if(R < 0 || C < 0 || R >= ROWS || C >= COLS || (R == r && C == c)) {
                    continue;
                } 
                else {
                    if(board[R][C] == 1 || board[R][C] == 3) count_1++;
                }
            }
        } 
        return count_1;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();
        // Original | New  | State
        //     0    |  0   |   0
        //     1    |  0   |   1
        //     0    |  1   |   2
        //     1    |  1   |   3

        // modifying the board
        for(int r = 0; r < ROWS; r++) { 
            for(int c = 0; c < COLS; c++) {
                int count_1 = countNeighbours(board, r, c);

                if(board[r][c] == 0) {
                    board[r][c] = (count_1 == 3)? 2 : 0;
                }
                else {
                    board[r][c] = (count_1 == 2 || count_1 == 3)? 3 : 1;
                }
            }
        }
        // finalizing the board
        for(int r = 0; r < ROWS; r++) { 
            for(int c = 0; c < COLS; c++) {
                if(board[r][c] == 1) {
                    board[r][c] = 0;
                }
                if(board[r][c] == 2 || board[r][c] == 3) {
                    board[r][c] = 1;
                }
            }
        }
    }
};
int main() {
    
    return 0;
}