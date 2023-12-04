#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for (int k = i; k <= j; k++) {
            int coins = (nums[i - 1] * nums[k] * nums[j + 1]) +
                         f(i, k - 1, nums, dp) + f(k + 1, j, nums, dp);
            maxi = max(maxi, coins);
        }
        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return f(1, n, nums, dp);
    }
};

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int> (n + 2));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j >= 1; j--) {
                if (i > j) continue;
                int maxi = INT_MIN;
                for (int k = i; k <= j; k++) {
                    int coins = (nums[i - 1] * nums[k] * nums[j + 1]) +
                                 dp[i][k - 1] + dp[k + 1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int> (n + 2));
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                int maxi = INT_MIN;
                for (int k = i; k <= j; k++) {
                    int coins = (nums[i - 1] * nums[k] * nums[j + 1]) +
                                 dp[i][k - 1] + dp[k + 1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};

int main() {
    
    return 0;
}