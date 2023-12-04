#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        for (int i = goal; i > -1; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        if (goal == 0) return true; 
        else return false;
    }
};
int main() {
    Solution sally;
    vector<int> nums {3,2,1,0,4};
    bool ans = sally.canJump(nums);
    cout<<ans;
    return 0;
}