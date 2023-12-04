#include<iostream>
#include<vector>
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
    TreeNode* f(int ub, vector<int>& preorder, int& i) {
        if(i == preorder.size() || preorder[i] > ub) return NULL;   
        TreeNode* root = new TreeNode(preorder[i], NULL, NULL);
        i += 1;
        root->left = f(root->val, preorder, i);
        root->right = f(ub, preorder, i);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ub = INT_MAX;
        int i = 0;
        return f(ub, preorder, i);
    }
};

// this is not working
// class Solution {
//     TreeNode* f(int ub, vector<int>& preorder, int& i) {
//         if(i == preorder.size() || preorder[i] > ub) return NULL;   
//         TreeNode* root = new TreeNode(preorder[i], NULL, NULL);
//         root->left = f(root->val, preorder, i + 1);
//         root->right = f(ub, preorder, i + 1);
//         return root;
//     }
// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int ub = INT_MAX;
//         int i = 0;
//         return f(ub, preorder, i);
//     }
// };
int main() {
    
    return 0;
}