#include<iostream>
using namespace std;

class Solution {
private:
    bool valid(TreeNode* node, long left, long right) {
        if(node == NULL) return true;
        if  (!(node->val < right && node->val > left)) return false;
        return valid(node->left, left, node->val) && valid(node->right, node->val, right);
    }
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
}; 
int main() {
    
    return 0;
}