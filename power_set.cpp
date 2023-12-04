// https://youtu.be/eQCS_v3bw0Q 
#include<iostream>
#include<vector>
using namespace std;
// print all
class Solution {
public:
    void dfs(vector<int>& nums, int index, vector<vector<int>>& ans, vector<int> stack) {
        if(index >= nums.size()) {
            ans.push_back(stack);
            return;
        }

        stack.push_back(nums[index]);
        dfs(nums, index + 1, ans, stack);
        stack.pop_back();
        dfs(nums, index + 1, ans, stack);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0;
        vector<int> stack;
        vector<vector<int>> ans; 
        dfs(nums, index, ans, stack);
        return ans;
    }
};  

//----------------------------------------------------------------------------------------------------------------------
// print one
// bool dfs(int i, int sum, int k, vector<int> stack, vector<int> nums) {
//     if(i == nums.size()) {
//         if(sum == k) {
//         for(int i : stack) {
//             cout<<i;
//         }
//         cout<<endl;
//         return true;
//     }
//         return false;
//     }
//     sum += nums[i];
//     stack.push_back(nums[i]);
//     if(dfs(i + 1, sum, k, stack, nums)) return true;
//     sum -= nums[i];
//     stack.pop_back();
//     if(dfs(i + 1, sum, k, stack, nums)) return true;
//     return false;
// }

// void function_printOnlyOneResult(vector<int> nums, int k) {
//     vector<int> stack;
//     int sum = 0;
//     dfs(0, sum, k, stack, nums);
// }
// //-----------------------------------------------------------------------------------------------------------------------
// // print count
// int dfs(int i, int sum, int k, vector<int> nums) {
//     if(i == nums.size()) {
//         if(sum == k) {
//         return 1;
//     }
//         return 0;
//     }
//     sum += nums[i];
//     int a = dfs(i + 1, sum, k, nums);
//     sum -= nums[i];
//     int b = dfs(i + 1, sum, k, nums);
//     return a + b;
// }

// int function_printCount(vector<int> nums, int k) {
//     vector<int> stack;
//     int sum = 0;
//     return dfs(0, sum, k, nums);
// }

int main() {
    vector<int> nums {1, 2, 1};
    Solution sally;
    vector<vector<int>> res = sally.subsets(nums);
    
    return 0;
}