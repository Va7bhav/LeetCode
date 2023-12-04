#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int f(int i, vector<int>& nums, int target, vector<vector<int>> dp) {
        if (i == 0) {
            if (target == 0 && nums[0] == 0) return 2;
            if (target == 0 || target == nums[0]) return 1;
            return 0;
        }
        if (dp[i][target] != -1) return dp[i][target];
        int not_take = f(i - 1, nums, target, dp);
        int take = 0;
        if (target - nums[i] >= 0) {
            take = f(i - 1, nums, target - nums[i], dp);
        }
        return dp[i][target] = take + not_take;
    } 
public:
    int findWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        dp[0][0] = 2;
        for (int i = 0; i < n; i++) {
            for (int sum = 0; sum <= target; sum++) {
                if (sum == 0 || sum == nums[0]) dp[0][sum] = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= target; sum++) {
                int not_take = dp[i - 1][target];
                int take = 0;
                if (target - nums[i] >= 0) {
                    take = dp[i - 1][target - nums[i]];
                }
                dp[i][target] = take + not_take;
            }
        }
        return dp[n - 1][target];
    }
};
int main()
{

    return 0;
}
