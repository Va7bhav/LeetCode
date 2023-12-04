#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<vector<int>>& ans, vector<int> stack) {
        if(index >= nums.size()) {
            ans.push_back(stack);
            return;
        }

        stack.push_back(nums[index]);
        backtrack(nums, index + 1, ans, stack);
        stack.pop_back();
        backtrack(nums, index + 1, ans, stack);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0;
        vector<int> stack;
        vector<vector<int>> ans; 
        backtrack(nums, index, ans, stack);
        return ans;
    }
};

int main() {
    Solution sally;
    vector<int> vec {1, 2, 3};
    sally.subsets(vec);
    return 0;
}