#include<vector>
#include<iostream>
using namespace std;
class Solution {
    bool wordSearch(vector<vector<char>>& board, string word, int r, int c, int i) {
        int ROWS = board.size();
        int COLS = board[0].size();
        if(i == word.length()) {
            return true;
        }
        if(r >= ROWS || c >= COLS || r < 0 || c < 0 || board[r][c] != word[i]) {
            return false;
        }
        wordSearch(board, word, r + 1, c, i + 1);
        wordSearch(board, word, r - 1, c, i + 1);
        wordSearch(board, word, r, c + 1, i + 1);
        wordSearch(board, word, r, c - 1, i + 1);
    }
    public:
        bool exist(vector<vector<char>>& board, string word) {
            int ROWS = board.size();
            int COLS = board[0].size();
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    wordSearch(board, word, 0, 0, i);
                }   
            }
            
        }   
};

int main() {
    
    return 0;
}