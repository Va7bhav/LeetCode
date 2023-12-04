#include<iostream>
#include<queue>
#include<map>
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
    public:
        vector<int> bottomView(TreeNode* root) {
            map<int, int> hash;
            queue<pair<TreeNode*, int>> q;
            q.push({root, 0});
            while(!q.empty()) {
                TreeNode* currNode = q.front().first;
                int hl = q.front().second;
                hash[hl] = currNode->val;
                q.pop();
                if(currNode->left)
                    q.push({currNode->left, hl - 1});
                if(currNode->right)
                    q.push({currNode->right, hl + 1});
            }
            vector<int> res;
            for(auto pair : hash) {
                res.push_back(pair.second);
            }
            return res;
        }
};

int main() {
    
}