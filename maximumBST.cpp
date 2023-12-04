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
class Node {
    public:
    int max;
    int min;
    int total;
    Node (int _max, int _min, int _total) {
        max = _max;
        min = _min;
        total = _total;
    }
};

class Solution {
    Node f(TreeNode* root) {
        if (!root->left && !root->right) {
            return Node(root->val, root->val, root->val);
        }
        
        if ((root->val > f(root->left).max) && 
            (root->val < f(root->right).min)) {
            return Node(max(root->val, f(root->right).max), 
                        min(root->val, f(root->left).min), 
                        f(root->left).total + f(root->right).total + root->val)
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        return f(root).total;
    }
};


int main() {
    
    return 0;
}