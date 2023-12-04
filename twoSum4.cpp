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

class Solution {
    stack<TreeNode*> st;
    TreeNode* currN;
    TreeNode* currB;
    int next() {
        while(currN || !st.empty()) {
            while(currN) {
                st.push(currN);
                currN = currN->left;
            }
            currN = st.top();
            int nextVal = currN->val;
            st.pop();
            currN = currN->right;
            return nextVal;
        }
        return 69;
    }
    int before() {
        while(currB || !st.empty()) {
            while(currB) {
                st.push(currB);
                currB = currB->right;
            }
            currB = st.top();
            int nextVal = currB->val;
            st.pop();
            currB = currB->left;
            return nextVal;
        }
        return 69;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        currN = root;
        currB = root;
        int left = next();
        int right = before();
        cout << left << right;
        while(left <= right) {
            if(left + right == k) return true;
            else if(left + right < k) left = next();
            else if(left + right > k) right = before();
        }
        return false;
    }
};
int main() {
    
    return 0;
}