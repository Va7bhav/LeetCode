#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node {
    int data;
    Node* left, * right;
}; 

class Solution {
    bool isLeaf(Node* root) {
        if(!root->left && !root->right) return true;
        else return false;
    }
    
    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while(curr) {
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void addRightBoundary(Node* root, vector<int>& res) {
        vector<int> stack;
        Node* curr = root->right;
        while(curr) {
            if(!isLeaf(curr)) stack.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for(int i = stack.size() - 1; i >= 0; i--) {
            res.push_back(stack[i]);
        }
    
    }
    
    void addLeaves(Node* root, vector<int>& res) {
        // preorder traversal 
        if(isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if(root->left) addLeaves(root->left, res);
        if(root->right) addLeaves(root->right, res);
    }
    
    public:
    vector<int> boundary(Node* root) {
        vector<int> res;
        if(!root) return res;
        if(!isLeaf(root)) res.emplace_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};

int main() {
    
    return 0;
}