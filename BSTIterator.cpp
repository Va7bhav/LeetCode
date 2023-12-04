#include<iostream>
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
 
class BSTIterator {
    stack<TreeNode*> st;
    TreeNode* curr;
public:
    int giveVal() {
        while(curr || !st.empty()) {
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            int nextVal = curr->val;
            st.pop();
            curr = curr->right;
            return nextVal;
        }
        return 69;
    }
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() {
        return giveVal();
    }
    
    bool hasNext() {
        if(curr || !st.empty()) return true;
        else return false;
    }
};

int main() {
    
    return 0;
}