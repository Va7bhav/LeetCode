#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    int f(int i, vector<int>& nums) {
        if (i < 0) return 0;

        int not_take = 0 + f(i - 1, nums);
        int currVal = nums[i];
        int before = currVal - 1;
        // I have taken one that means I have to take all values equal to that value in that array, so
        int take = 0;
        int j = i;
        while (j >= 0 && nums[j] == currVal) {
            take += nums[j];
            j -= 1;
        }
        // now as I am only travelling left hand side of the array, I have to skip the ones that has value currVal - 1
        while (i >= 0 && nums[j] == before) {
            j -= 1;
        }
        // now i have arrived at the index where I can choose now from
        take += f(j, nums);
        // at the end we have to return the maximum we got by take or not take

        return max(take, not_take);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(nums.size());
        sort(nums.begin(), nums.end());
        return f(nums.size() - 1, nums);
    }
};

class Solution {
    int f(int i, vector<int>& nums, vector<int>& dp) {
        if (i == 0) return 0;

        if (dp[i] != -1) return dp[i];

        int not_take = 0 + f(i - 1, nums, dp);
        int currVal = nums[i - 1];
        int before = currVal - 1;
        int take = 0;
        int j = i;
        while (j >= 1 && nums[j - 1] == currVal) {
            take += nums[j - 1];
            j -= 1;
        }
        while (j >= 1 && nums[j - 1] == before) {
            j -= 1;
        }
        take += f(j, nums, dp);
        return dp[i] = max(take, not_take);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        sort(nums.begin(), nums.end());
        return f(nums.size(), nums, dp);
    }
};

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size() + 1);
        dp[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            int not_take = 0 + dp[i - 1];
            int currVal = nums[i - 1];
            int before = currVal - 1;
            int take = 0;
            int j = i;
            while (j >= 1 && nums[j - 1] == currVal) {
                take += nums[j - 1];
                j -= 1;
            }
            while (j >= 1 && nums[j - 1] == before) {
                j -= 1;
            }
            take += dp[j];
            dp[i] = max(take, not_take);
        }   
        return dp[nums.size()];
    }
};

int main() {
    

    return 0;
}