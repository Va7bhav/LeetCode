#include<iostream>
#include<vector>

using namespace std;

class Solution {
    int f(int i, int j, vector<vector<int>>& triangle, int ROWS, int COLS) {
        if (i == ROWS - 1) {
            return triangle[ROWS - 1][j];
        }
        return triangle[i][j] + min(f(i + 1, j, triangle, ROWS, COLS), f(i + 1, j + 1, triangle, ROWS, COLS));
    }   
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ROWS = triangle.size();
        int COLS = triangle[0].size();
        return f(0, 0, triangle, ROWS, COLS);
    }
};

class Solution {
    int f(int i, int j, vector<vector<int>>& triangle, int n,vector<vector<int>> dp) {
        if (i == n - 1) {
            return triangle[n - 1][j];
        }
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = triangle[i][j] + min(f(i + 1, j, triangle, n, dp), f(i + 1, j + 1, triangle, n, dp));
    }   
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n));
        for (int j = 0; j < n; j++) dp[n - 1][j] = triangle[n - 1][j];
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};


int main() {
    
    return 0;
}