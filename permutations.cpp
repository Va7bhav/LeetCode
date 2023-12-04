#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
   void recurPermute(vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans, vector<int>& freq) {
        if(nums.size() == ds.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < 2; i++) {
            if(!freq[i]) { 
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(ds, nums, ans, freq); 
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> ds;
            vector<int> freq (nums.size(), 0);
            recurPermute(ds, nums, ans, freq);
            return ans;
        }
};

    void f(int i, vector<int> nums, vector<vector<int>>& res, vector<int> stack, vector<int> freq) {
        if(stack.size() == nums.size()) {
            res.push_back(stack);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(!freq[i]) {
                stack.push_back(nums[i]);
                freq[i] = 1;
                f(i + 1, nums, res, stack, freq);
                stack.pop_back();
                freq[i] = 0;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
           vector<vector<int>> res;
           vector<int> stack, freq;
           f(0, nums, res, stack, freq);
           return res;
        }

int main() {
    
    return 0;
}