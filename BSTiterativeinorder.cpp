#include<iostream>
#include<vector>
#include<stack>
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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        vector<int> inorder;
        while(!st.empty() || curr) {
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            inorder.push_back(curr->val);
            st.pop();
            curr = curr->right;
        }
        return inorder;
    }
};

int main() {
    
    return 0;
}