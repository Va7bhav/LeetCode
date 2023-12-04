#include<iostream>
#include<vector>
#include<Set>
using namespace std;
// class Solution {
//     private:
//         bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
//             int ROWS = board.size();
//             int COLS = board[0].size();
//             set<vector<int>> path;

//             if(i == word.length()) {
//                 return true;
//             }

//             if(r < 0 || c < 0 || r >= ROWS || c >= COLS || word[i] != board[r][c] || path.find({r, c}) != path.end()) {
//                 return false;
//             }

//             path.insert({r, c}); 

//             bool res = dfs(board, word, r + 1, c, i + 1) || dfs(board, word, r - 1, c, i + 1) || dfs(board, word, r, c + 1, i + 1) || dfs(board, word, r, c - 1, i + 1);
//             // checking for the element done

//             path.erase({r, c}); 

//             return res;
//         }
//     public:
//         bool exist(vector<vector<char>>& board, string word) {
//             int ROWS = board.size();
//             int COLS = board[0].size();
//             int i = 0; // represents index of the word
//             for(int r = 0; r < ROWS; r++) {
//                 for(int c = 0; c < COLS; c++) {
//                     if(dfs(board, word, r, c, i)) return true;
//                 }
//             }
//             return false;
//         }   
// };
class Solution {
    private:
        bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
            int ROWS = board.size();
            int COLS = board[0].size();
    
            if(i == word.length()) {
                return true;
            }

            if(r < 0 || c < 0 || r >= ROWS || c >= COLS || word[i] != board[r][c]) {
                return false;
            }

            char temp = board[r][c];
            board[r][c] = ' ';

            bool res = dfs(board, word, r + 1, c, i + 1) || dfs(board, word, r - 1, c, i + 1) || dfs(board, word, r, c + 1, i + 1) || dfs(board, word, r, c - 1, i + 1);
            // checking for the element done

            board[r][c] = temp;

            return res;
        }
    public:
        bool exist(vector<vector<char>>& board, string word) {
            int ROWS = board.size();
            int COLS = board[0].size();
            int i = 0; // represents index of the word
            for(int r = 0; r < ROWS; r++) {
                for(int c = 0; c < COLS; c++) {
                    if(dfs(board, word, r, c, i)) return true;
                }
            }
            return false;
        }   
};
int main() {
    Solution sally;
    vector<vector<char>> pass = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    cout << sally.exist(pass, "ABCB");
}