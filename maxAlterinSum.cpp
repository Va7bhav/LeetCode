#include<iostream>
#include<vector>
using namespace std;

class Solution {
    long long dfs(int i, bool isEven, vector<int>& nums, vector<vector<int>> dp) {
        if (i == nums.size()) {
            return 0;
        }
        if (dp[i][isEven] != -1) return dp[i][isEven];
        long long sum = 0;
        if (isEven) {
            sum = max(nums[i] + dfs(i + 1, false, nums, dp), dfs(i + 1, true, nums, dp)); 
        }
        else {
            sum = max(-nums[i] + dfs(i + 1, true, nums, dp), dfs(i + 1, false, nums, dp));
        }
        return dp[i][isEven] = sum;
    }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size() + 1, vector<int> (2, 0));

        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int isEven = 1; isEven >= 0; isEven--) {
                long long sum = 0;
                if (isEven) {
                    sum = max(nums[i] + dp[i + 1][false], dp[i + 1][true]); 
                }
                else {
                    sum = max(-nums[i] + dp[i + 1][true], dp[i + 1][false]);
                }
                dp[i][isEven] = sum;
            }
        }
        return dp[0][true];
    }
};
int main() {
    
    return 0;
}