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
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return isSymmetric(root->left,root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right){
        if(left->val != right->val) return false;
        if(left == NULL || right == NULL)  return left==right; 
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

int main() {
    
    
    return 0;
}