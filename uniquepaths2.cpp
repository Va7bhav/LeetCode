#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int f(int r, int c, vector<vector<int>>& obstacleGrid, vector<vector<int>> dp) {
        if (r < 0 || c < 0 || obstacleGrid[r][c] == 1) return 0;
        if (r == 0 && c == 0) return 1;
        if (dp[r][c] != -1) return dp[r][c];
        return f(r - 1, c, obstacleGrid, dp) + f(r, c - 1, obstacleGrid, dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROWS = obstacleGrid.size(), COLS = obstacleGrid[0].size();
        vector<vector<int>> dp(ROWS, vector<int> (COLS, -1));
        return f(ROWS - 1, COLS - 1, obstacleGrid, dp);
    }
};

class Solution {
    int f(int r, int c, vector<vector<int>>& obstacleGrid, vector<vector<int>> dp) {
        if (r == 0 || c == 0 || obstacleGrid[r - 1][c - 1] == 1) return 0;
        if (r == 1 && c == 1) return 1;
        if (dp[r][c] != -1) return dp[r][c];
        return dp[r][c] = f(r - 1, c, obstacleGrid, dp) + f(r, c - 1, obstacleGrid, dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROWS = obstacleGrid.size(), COLS = obstacleGrid[0].size();
        vector<vector<int>> dp(ROWS + 1, vector<int> (COLS + 1, -1));
        return f(ROWS, COLS, obstacleGrid, dp);
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROWS = obstacleGrid.size(), COLS = obstacleGrid[0].size();
        vector<vector<int>> dp(ROWS + 1, vector<int> (COLS + 1));
        dp[1][1] = 1;
        for (int r = 1; r <= ROWS; r++) {
            for (int c = 1; c <= COLS; c++) {
                if (obstacleGrid[r - 1][c - 1] == 1) dp[r][c] = 0;
                else {
                    if (r > 1 || c > 1) 
                        dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
                }
            }
        }
        return dp[ROWS][COLS];    
    }
};
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROWS = obstacleGrid.size(), COLS = obstacleGrid[0].size();
        vector<int> prev(COLS + 1);
        vector<int> curr(COLS + 1);
        prev[1] = 1;
        for (int r = 1; r <= ROWS; r++) {
            for (int c = 1; c <= COLS; c++) {
                if (obstacleGrid[r - 1][c - 1] == 1) curr[c] = 0;
                else {
                    if (r > 1 || c > 1) 
                        curr[c] = prev[c] + curr[c - 1];
                }
            }
            prev = curr;
        }
        return prev[COLS];    
    }
};
int main() {
    
    return 0;
}