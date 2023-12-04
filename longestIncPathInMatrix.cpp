#include<iostream>
using namespace std;

class Solution {
    int dfs(int r, int c, int prevVal, vector<vector<int>>& matrix, int ROWS, int COLS, vector<vector<int>> cache) {
        if (r < 0 || c < 0 || r == ROWS || c == COLS || matrix[r][c] <= prevVal) {
            return 0;
        }
        if (cache[r][c] != -1) return cache[r][c];
        return cache[r][c] = 1 + max({dfs(r + 1, c, matrix[r][c], matrix, ROWS, COLS, cache), 
                        dfs(r - 1, c, matrix[r][c], matrix, ROWS, COLS, cache), 
                        dfs(r, c + 1, matrix[r][c], matrix, ROWS, COLS, cache), 
                        dfs(r, c - 1, matrix[r][c], matrix, ROWS, COLS, cache)});
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        int res = 0;
        vector<vector<int>> cache(ROWS, vector<int> (COLS, -1));
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                res = max(res, dfs(r, c, -1, matrix, ROWS, COLS, cache));
            }
        }
        return res;
    }
};

int main() {
    
    return 0;
}