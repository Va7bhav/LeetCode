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
    TreeNode* dfs(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* leftTail = dfs(root->left);
        TreeNode* rightTail = dfs(root->right);
        if(root->left) {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        TreeNode* last;
        // last = rightTail or leftTail or root; according to priority
        if(rightTail) last = rightTail;
        else if(leftTail) last = leftTail;
        else if(root) last = root;
        return last;
    }
public:
    void flatten(TreeNode* root) {
        dfs(root);
    }
};
int main() {
    
    return 0;
}