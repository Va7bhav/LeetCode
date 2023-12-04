#include<iostream>
#include<vector>
using namespace std;

bool f(int i, int k, vector<int>& nums, vector<vector<bool>> dp) {
    if (k == 0) return true;
    if (i == 0) return (nums[i] - k == 0);      
    if (dp[i][k] != -1) return dp[i][k];  
    bool not_take = f(i - 1, k, nums, dp);
    bool take = false;
    if (k >= nums[i]) take = f(i - 1, k - nums[i], nums, dp);
    return dp[i][k] = take | not_take;
}
bool subsetSumEqualsTarget(vector<int>& nums, int target) {
    vector<vector<bool>> dp(nums.size(), vector<bool> (target + 1));

    for (int i = 0; i < nums.size(); i++) dp[i][0] = true;
    for (int k = 0; k <= target; k++) {
        if (nums[0] - k == 0) dp[0][k] = true; 
    }
    for (int i = 0; i < nums.size(); i++) {
        for (int k = 0; k <= target; k++) {
            bool not_take = dp[i - 1][k];
            bool take = false;
            if (k >= nums[i]) take = dp[i - 1][k - nums[i]];
            dp[i][k] = take | not_take;
        }
    }
    return dp[nums.size() - 1][target];
}

bool subsetSumEqualsTarget(vector<int> &nums, int target) {
    vector<bool> prev(target + 1, false);
    vector<bool> curr(target + 1, false);

    for (int k = 0; k <= target; k++) {
        if (nums[0] - k == 0) prev[k] = true; 
    }

    for (int i = 1; i < nums.size(); i++) {
        prev[0] = true;
        for (int k = 1; k <= target; k++) {
            bool not_take = prev[k];
            bool take = false;
            if (k >= nums[i]) take = prev[k - nums[i]];
            curr[k] = take | not_take;
        }
        prev = curr;
    }
    return prev[target];
}

int main() {
    
    return 0;
}