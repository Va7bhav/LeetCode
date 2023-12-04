#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int f(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>> dp) {
        if (j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size()) return -1e8;
        if (i == grid.size() - 1) {
            if (j1 == j2) return grid[i][j2];
            else return grid[i][j1] + grid[i][j2];
        }
        int res = -1e8;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int value = 0;
                if (j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += f(i, j1 + dj1, j2 + dj2, grid, dp);
                res = max(res, value);
            }
        }
        return res;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<vector<int>>> dp(ROWS, vector<vector<int>> (COLS, vector<int> (COLS, -1)));
        return f(0, 0, COLS  - 1, grid, dp);
    }
};

class Solution {
    int dfs(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if (j1 < 0 || j1 == m || j2 < 0 || j2 == m) return -1e9;
        if (i == n - 1) return j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2];
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int res = 0;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                if (j1 == j2) res = max(res, grid[i][j1] + dfs(i + 1, x, y, n, m, grid, dp));
                else res = max(res, grid[i][j1] + grid[i][j2] + dfs(i + 1, x, y, n, m, grid, dp));
            }
        }
        return dp[i][j1][j2] = res;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return dfs(0, 0, m - 1, n, m, grid, dp);
    }
    class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<vector<int>>> dp(ROWS, vector<vector<int>> (COLS, vector<int> (COLS)));
        for (int j1 = 0; j1 < COLS; j1++) {
            for (int j2 = 0; j2 < COLS; j2++) {
                if (j1 == j2) dp[ROWS - 1][j1][j2] = grid[ROWS - 1][j2];
                else dp[ROWS - 1][j1][j2] = grid[ROWS - 1][j1] + grid[ROWS - 1][j2];  
            }
        }
        for (int i = ROWS - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < COLS; j1++) {
                for (int j2 = 0; j2 < COLS; j2++) {
                    int res = -1e8;
                    for (int dj1 : {-1, 0, 1}) {
                        for (int dj2 : {-1, 0, 1}) {
                            int value = 0;
                            if (j1 == j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            if(j1 + dj1 >= 0 && j1 + dj1 < COLS && j2 + dj2 >= 0 && j2 + dj2 < COLS) {
                                value += dp[i + 1][j1 + dj1][j2 + dj2];
                            }
                            else value = -1e8;
                            res = max(res, value);
                        }
                    }
                    dp[i][j1][j2] = res;
                }
            }
        }
        return dp[0][0][COLS - 1];
    }
};

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<int>> prev(COLS, vector<int> (COLS));
        vector<vector<int>> curr(COLS, vector<int> (COLS));
        for (int j1 = 0; j1 < COLS; j1++) {
            for (int j2 = 0; j2 < COLS; j2++) {
                if (j1 == j2) prev[j1][j2] = grid[ROWS - 1][j2];
                else prev[j1][j2] = grid[ROWS - 1][j1] + grid[ROWS - 1][j2];  
            }
        }
        for (int i = ROWS - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < COLS; j1++) {
                for (int j2 = 0; j2 < COLS; j2++) {
                    int res = -1e8;
                    for (int dj1 : {-1, 0, 1}) {
                        for (int dj2 : {-1, 0, 1}) {
                            int value = 0;
                            if (j1 == j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            if(j1 + dj1 >= 0 && j1 + dj1 < COLS && j2 + dj2 >= 0 && j2 + dj2 < COLS) {
                                value += prev[j1 + dj1][j2 + dj2];
                            }
                            else value = -1e8;
                            res = max(res, value);
                        }
                    }
                    curr[j1][j2] = res;
                }
            }
            prev = curr;
        }
        return prev[0][COLS - 1];
    }
};
int main() {
    
    return 0;
}