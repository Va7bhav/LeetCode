#include<iostream>
#include<vector>
using namespace std;

class Solution {
    pair<bool, int> isHeightBalanced(TreeNode* root) {
        if (root == NULL) return {true, 0};
        pair<bool, int> left = isHeightBalanced(root->left);
        pair<bool, int> right = isHeightBalanced(root->right);
        if ((left.first && right.first) && abs(left.second - right.second) <= 1) {
            return {true, 1 + max(left.second, right.second)};
        }
        else return {false, 1 + max(left.second, right.second)};
    }
public:
    bool isBalanced(TreeNode* root) {
        return isHeightBalanced(root);
    }
};
int main() {
    
    return 0;
}