#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int max_sum = INT_MIN;
        for(int element : nums) {
            sum += element;
            max_sum = max(max_sum, sum);
            if(sum < 0) sum = 0;
        }
        return max_sum;
    }
};
int main() {
    Solution sally;
    vector<int> nums {1};
    cout<<sally.maxSubArray(nums);
    return 0;
}