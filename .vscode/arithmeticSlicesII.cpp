#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;

long long big = pow(2, 32);
class Solution {
    unordered_map<string, int> dp;
    int f(int i, long long diff, vector<int> nums) {
        if (i == nums.size()) {
            return 0;
        }
        
        string key = to_string(i) + ":" + to_string(diff);
        if (dp.find(key) != dp.end()) return dp[key];
        int res = 0;

        // take
        for (int j = i + 1; j < nums.size(); j++) {
            if (diff == big) {
                res += f(j, (long)nums[j] - nums[i], nums);
            } else if ((long)nums[j] - nums[i] == diff) {
                res += (1 + f(j, diff, nums));
            }
        }
        return dp[key] = res;
    }

public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += f(i, big, nums);
        }

        return res;
    }
};

int main() {
    
    return 0;
}