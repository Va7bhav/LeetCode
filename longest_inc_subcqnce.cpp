#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// memoisation
// class Solution {
//     int f(int i, int prev_index, vector<int>& nums, vector<vector<int>>& dp) {
//         if(i == nums.size()) return 0;
        
//         if(dp[i][prev_index + 1] != -1) return dp[i][prev_index + 1];
        
//         int len = f(i + 1, prev_index, nums, dp); // not take
        
//         if(prev_index == -1 || nums[prev_index] < nums[i]) {
//             len = max(len, 1 + f(i + 1, i, nums, dp)); // take
//         }
        
//         return dp[i][prev_index + 1] = len;
//     }
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//         return f(0 ,-1, nums, dp);
//     }
// };

// tabulation
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n + 1));

        for(int i = n - 1; i >= 0; i--) {
            for(int prev_index = i - 1; prev_index >= -1; prev_index--) {
                int len = dp[i + 1][prev_index + 1];
                if(prev_index == -1 || nums[prev_index] < nums[i]) {
                    len = max(len, 1 + dp[i + 1][i]);
                }
                dp[i][prev_index + 1] = len;
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution2 sally;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << sally.lengthOfLIS(nums);
    return 0;
}