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
    TreeNode* inorderPredecessor(TreeNode* node) {
        node = node->left;
        while (node->right != NULL) {
            node = node->right;
        }
        return node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            TreeNode* iPre = inorderPredecessor(root);
            root->val = iPre->val;
            root->left = deleteNode(root->left, iPre->val);
        }
        return root;
    }
};

class Solution {
    TreeNode* inorderSuccessor(TreeNode* root) {
        root = root->right;
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return root;
        }
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            TreeNode* iSucc = inorderSuccessor(root);
            root->val = iSucc->val;
            root->right = deleteNode(root->right, iSucc->val);
        }
        return root;
    }
};
int main() {
    
    return 0;
}