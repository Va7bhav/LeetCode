#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>


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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> hash;
        // horizontal - level : {vertical - level, {node -> val1, node->val2.....}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        // {root, {horizontal - level, vertical - level}}
        q.push({root, {0, 0}});
        while(!q.empty()) {
            TreeNode* currNode = q.front().first;
            int hl = q.front().second.first;
            int vl = q.front().second.second;
            hash[hl][vl].push_back(currNode->val);
            q.pop();
            if(currNode->left)
                q.push({currNode->left, {hl - 1, vl + 1}});
            if(currNode->right)    
                q.push({currNode->right, {hl + 1, vl + 1}});
        }
        vector<vector<int>> res;

        for(auto pair1 : hash) {
            vector<int> stack;
            for(auto pair2 : pair1.second) {
                stack.insert(stack.end(), pair2.second.begin(), pair2.second.end());
            }
            res.push_back(stack);
        }
    }
};

// my code
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<TreeNode*>>> hash;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            auto pop_element = q.front();
            q.pop();
            TreeNode* popNode = pop_element.first;
            int hl = pop_element.second.first;
            int vl = pop_element.second.second;
            hash[hl][vl].insert(popNode->val);
            if(popNode->left)
                q.push({popNode->left, {hl - 1, vl + 1}});
            if(popNode->right)
                q.push({popNode->right, {hl + 1, vl + 1}});
        }
        vector<vector<int>> res;
        for(auto pair1 : hash) {
            vector<int> stack;
            for(auto pair2 : pair1.second) {
                stack.insert(stack.end(), pair2.second.begin(), pair2.second.end());
            }
            res.push_back(stack);
        }
        return res;
    }
};


int main() {

    return 0;
}