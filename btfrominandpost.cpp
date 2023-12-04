#include<iostream>
#include<vector>
#include<map>
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
    TreeNode* build(vector<int> inorder, int li, int ri, vector<int> postorder, int lp, int rp, map<int, int> hash) {
        if(li > ri || lp > rp) return NULL;
        TreeNode* newNode = new TreeNode(postorder[rp]);
        int index = hash[postorder[rp]];
        int leftInorderLen = index - li;
        int rightInorderLen = inorder.size() - index - 1;
        newNode->left = build(inorder, li, index - 1, postorder, lp, lp + leftInorderLen - 1, hash);
        newNode->right = build(inorder, index + 1, ri, postorder, lp + leftInorderLen, rp - 1, hash);
        return newNode;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        map<int, int> hash;
        for(int i = 0; i < inorder.size(); i++) hash[inorder[i]] = i;
        int i = postorder.size() - 1;
        TreeNode* root;
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, hash);
    }
};

int main() {
    
    return 0;
}