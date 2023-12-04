#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    bool f(int i, int SUM, vector<int> nums, int k) {
        if (i == nums.size() - 1) {
            return true;
        }


    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int SUM = accumulate(nums.begin(), nums.end(), 0);
        if (SUM % k == 0) return false;
        return f(0, SUM / k, nums, k);
    }
};

int main() {
    
    return 0;
}