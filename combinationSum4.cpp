#include<iostream>
#include<vector>
#include<map>
using namespace std;


class Solution {
    int f(int target, vector<int>& nums, vector<int> dp) {
        if (target == 0) {
            return 1;
        }
        if (target < 0) {
            return 0;
        }
        if (dp[target] != -1) return dp[target];
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += f(target - nums[i], nums, dp);
        }
        return dp[target] = count;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        map<int, int> dp;
        dp[0] = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                count += dp[target - nums[j]];
            }
        }
        return dp[target];
    }
};

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        map<int, int> dp;
        dp[0] = 1;
        for (int sum = 1; sum <= target; sum++) {
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                count += dp[sum - nums[i]];
            }
            dp[sum] = count;
        }
        return dp[target];
    }
};

int main() {
    

    return 0;
}