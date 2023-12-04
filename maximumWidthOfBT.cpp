#include<iostream>
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

// for loop was used to pop all the nodes int the row at the same time i.e. in the same iteration
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int max_width = 1;
        while(!q.empty()) {
            int min_index = q.front().second; // ye 1 nahi hoti hai hamesha
            int last, first;
            for(int i = 0; i < q.size(); i++) {
                TreeNode* currNode = q.front().first;
                int curr_index = q.front().second - min_index;
                q.pop();
                if(i == 0) first = curr_index;
                if(i == q.size() - 1) last = curr_index;
                if(currNode->left)
                    q.push({currNode->left, 2 * curr_index + 1});
                if(currNode->right)
                    q.push({currNode->right, 2 * curr_index + 2});
            }
            max_width = max(max_width, last - first + 1);
        }
        return max_width;
    }
};

int main() {
    
    return 0;
}