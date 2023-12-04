#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>

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
    string dfs(TreeNode* node, map<string, vector<TreeNode*>> hash, vector<TreeNode*>& res) {
        if (node == NULL) {
            return "null";
        }
        string s = to_string(node->val) + "," + 
                   dfs(node->left, hash, res) + "," +
                   dfs(node->right, hash, res) + ",";


        if (hash[s].size() == 1) {
            res.push_back(node);
        }
        hash[s].push_back(node); 

        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, vector<TreeNode*>> hash;
        vector<TreeNode*> res;
        dfs(root, hash, res);
    }
};

int main() {
    vector<char> v1 {'a', 'b'};
    return 0;
}