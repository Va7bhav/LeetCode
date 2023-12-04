#include<iostream>
#include<map>
#include<queue>
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
    bool isCousins(TreeNode* root, int x, int y) {

        queue<pair<TreeNode*, int>> q;
        map<int, pair<TreeNode*, int>> hash;
        q.push({root, 0});
        while (!q.empty()) {
            TreeNode* node = q.front().first; q.pop();
            int level = q.front().second;
            if (node->left) {
                hash[node->right->val] = {node, level + 1};
                q.push({node->left, level + 1});
            }
            if (node->right) {
                hash[node->left->val] = {node, level + 1};
                q.push({node->right, level + 1});
            }
        }
        if (hash[x].second != hash[y].second) {
            return false;
        }
        if (hash[x].first != hash[y].first) {
            return false;
        }
        return true;
    }
};

int main() {
    
    return 0;
}