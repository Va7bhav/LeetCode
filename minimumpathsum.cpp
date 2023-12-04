#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>> dp) {
        if (i == 0 && j == 0) return grid[0][0];
        if (i < 0 || j < 0) return INT_MAX;
        if (dp[i][j] != -1) dp[i][j];
        return dp[i][j] =  grid[i][j] + min(f(i - 1, j, grid, dp), f(i, j - 1, grid, dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<int>> dp(ROWS, vector<int> (COLS, -1));
        return f(ROWS - 1, COLS - 1, grid, dp);
    }
};

class Solution {
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>> dp) {
        if (i == 1 && j == 1) return grid[0][0];
        if (i == 0 || j == 0) return INT_MAX;
        if (dp[i][j] != -1) dp[i][j];
        return dp[i][j] =  grid[i - 1][j - 1] + min(f(i - 1, j, grid, dp), f(i, j - 1, grid, dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<int>> dp(ROWS + 1, vector<int> (COLS + 1));
        dp[1][1] = grid[0][0];
        for (int i = 1; i <= ROWS; i++) dp[i][0] = INT_MAX;
        for (int j = 1; j <= COLS; j++) dp[0][j] = INT_MAX;
        
        for (int i = 1; i <= ROWS; i++) {
            for (int j = 1; j <= COLS; j++) {
                if (i > 1 || j > 1)
                    dp[i][j] = grid[i - 1][j - 1] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[ROWS][COLS];
    }
};


int main() {
    
    return 0;
}