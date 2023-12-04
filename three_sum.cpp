class Solution {
    public:
    vector<vector<int>> threeSum (vector<int>& nums) {
        vector<int> stack;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            if(i == 0 || nums[i] != nums[i - 1]) {
                int l = i + 1, r = nums.size() - 1;
                int sum = nums[l] + nums[i]  + nums[r];
                while(l < r) {
                    if(sum < 0) {
                        l++;
                    } else if(sum > 0){
                    r--;
                    } else { 
                        vector<int> stack;
                        stack.push_back(nums[i]);
                        stack.push_back(nums[l]);
                        stack.push_back(nums[r]);
                        res.push_back(stack);
                        while(nums[l + 1] == nums[l] && l < r)
                            l++;
                        while(nums[r - 1] == nums[r] && l < r)
                            r--;
                        l++;
                        r--;
                    }   
                }
            }
        }
        return res;
    }
};