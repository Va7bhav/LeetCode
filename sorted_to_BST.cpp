#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    struct TreeNode{
        struct TreeNode* left;
        struct TreeNode* right;
        int val;
    };

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return  binarySearch(nums, 0, nums.size()-1); 
    }

    TreeNode* binarySearch(vector<int> nums, int left, int right) {
        if(left > right) return NULL;
        int middle = left + (right - left)/2;
        TreeNode* node = new TreeNode(nums[middle]);
        node->left = binarySearch(nums, left, middle-1);
        node->right = binarySearch(nums, middle+1, right);
        return node;
    }
};
int main() {
    
    return 0;
}