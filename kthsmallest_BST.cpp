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
    int kthSmallest(TreeNode* root, int k) {
        stack<int> tube;
        TreeNode* curr = root;
        while(curr != NULL && tube != NULL) {
            while(curr) {
                curr = curr->left;

            }

        }
    }
};
int main() {
    Solution sally;
    
    return 0;
}