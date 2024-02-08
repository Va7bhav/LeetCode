#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


struct Node {
    public:
    bool isBST;
    int total;
    
    Node(bool is, int _total) {
        isBST = is;
        total = _total;
    }
};
class Solution {
    int res = -1e5;
    Node* f(TreeNode* root) {
        if (root == NULL) {
            return new Node(true, 0);
        }
        Node* leftNode = f(root->left);
        Node* rightNode = f(root->right);

        if (root->val < root->left->val || root->val < root->right->val) {
            return new Node(false, -1e5);
        }
        if (leftNode->isBST && rightNode->isBST) {
            res = max(res, root->val + leftNode->total + rightNode->total);
            return new Node(true, root->val + leftNode->total + rightNode->total);
        } else {
            return new Node(false, -1e5);
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        f(root);
        return res;
    }
};

int main() {
    
    return 0;
}