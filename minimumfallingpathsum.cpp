#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> dp) {
        if (j < 0 || j >= matrix[0].size()) return 1e9;
        if (i == 0) return matrix[0][j];
        if (dp[i][j] != -1) return dp[i][j];
        int strafeLeft = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
        int commit = matrix[i][j] + f(i - 1, j, matrix, dp);
        int strafeRight = matrix[i][j] + f(i - 1, j + 1, matrix, dp);
        return dp[i][j] = min({strafeLeft, commit, strafeRight});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int res = 1e9;
        vector<vector<int>> dp(ROWS, vector<int> (COLS, -1));
        for (int j = 0; j < matrix[0].size(); j++) {
            res = min(res, f(ROWS - 1, j, matrix, dp));
        }
        return res;
    }
};

class Solution {
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> dp) {
        if (j < 0 || j >= matrix[0].size()) return 1e9;
        if (i == 0) return matrix[0][j];
        if (dp[i][j] != -1) return dp[i][j];
        int strafeLeft = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
        int commit = matrix[i][j] + f(i - 1, j, matrix, dp);
        int strafeRight = matrix[i][j] + f(i - 1, j + 1, matrix, dp);
        return dp[i][j] = min({strafeLeft, commit, strafeRight});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int res = 1e9;
        vector<vector<int>> dp(ROWS, vector<int> (COLS, -1));
        for (int j = 0; j < matrix[0].size(); j++) {
            res = min(res, f(ROWS - 1, j, matrix, dp));
        }
        return res;
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        vector<vector<int>> dp(ROWS, vector<int> (COLS, 0));
        for (int j = 0; j < COLS; j++) dp[0][j] = matrix[0][j];

            for (int i = 1; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                int strafeLeft = matrix[i][j];
                if (j >= 1) strafeLeft += dp[i - 1][j - 1];
                else strafeLeft += 1e8;

                int commit = matrix[i][j] + dp[i - 1][j];

                int strafeRight = matrix[i][j];
                if (j + 1 < COLS) strafeRight += dp[i - 1][j + 1];
                else strafeRight += 1e8;

                dp[i][j] = min({commit, strafeLeft, strafeRight});
            }
        }

        int res = 1e8;
        for(int j = 0; j < COLS; j++)
            res = min(res, dp[ROWS - 1][j]);
        return res;
    }
};
int main() {
    
    return 0;
}