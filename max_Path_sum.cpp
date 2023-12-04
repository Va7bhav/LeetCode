#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int f(TreeNode* root, int& maxSum) {
        if(root == NULL) return 0; 
        int sumLeft = max(0, f(root->left, maxSum)); 
        int sumRight = max(0, f(root->right, maxSum)); 
        maxSum = max(maxSum, sumLeft + sumRight + root->val); // umbrella logic
        // if(sumLeft < 0 && sumRight < 0) return root->val;
        return root->val + max(sumLeft, sumRight);  // the function is returning max-path-sum, but we don't wanna consider negative path sum 
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        f(root, maxSum);
        return maxSum;
    }   
};
int main() {
    
    return 0;
}