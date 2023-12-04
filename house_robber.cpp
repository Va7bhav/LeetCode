#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int f(int i, vector<int>& nums) {
        if (i == 1) return nums[0];
        if (i == 0) return 0;

        return max(nums[i - 1] + f(i - 2, nums), f(i - 1, nums));
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
            dp[i] = max(nums[i - 1] + f(i - 2, nums), f(i - 1, nums));           
        }
        return f(nums.size(), nums);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1);
        int prePrev = 0;
        int prev = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
            int curr = max(nums[i - 1] + prePrev, prev);
            prePrev = prev;
            prev = curr;           
        }
        return prev;
    }
};

int main() {
    
    return 0;
}