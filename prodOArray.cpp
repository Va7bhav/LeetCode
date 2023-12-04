#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int prefix = 1;
        res[0] = prefix;
        for(int i = 1; i < nums.size(); i++) {
            res[i] = prefix *  nums[i - 1];
            prefix = prefix * nums[i - 1];
        } 
        int postfix = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            res[i] = res[i] * postfix;
            postfix = postfix * nums[i];
        }
        return res;
    }
};
int main() {
    
    return 0;
}