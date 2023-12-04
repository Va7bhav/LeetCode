#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
};

void help(TreeNode* root, int level, vector<int>& res) {
    if(root == NULL) return;
    if(res.size() == level)
        res.push_back(root->val);
    help(root->right, level + 1, res);
    help(root->left, level + 1, res);
}
vector<int> leftView(TreeNode* root) {
    vector<int> res;
    int level = 0;
    help(root, level, res);
    return res;
}
int main() {
    
    return 0;
}