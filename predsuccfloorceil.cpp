#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	int key;
	struct Node *left, *right;
};


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    if(root == NULL) {
        return;
    }

    if(root->key <= key) {
        if(pre == NULL || pre->key < root->key) {
            pre = root;
        }
        return findPreSuc(root->right, pre, suc, key);
    }

    else if(root->key > key) {
        if(suc == NULL || suc->key > root->key) {
            suc = root;
        }
        return findPreSuc(root->left, pre, suc, key);
    }
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    pre = NULL, suc = NULL;
    Node* curr = root;
    while (curr) {
        if(curr->key <= key) {
            curr = curr->right;
        }
        else if(curr->key > key) {
            suc = curr;
            curr = curr->left;
        }
    }
    curr = root;
    while (curr) {
        if (curr->key < key) {
            pre = curr;
            curr = curr->right;
        }
        else if (curr->key >= key) {
            curr = curr->left;
        }
    }
}

int main() {
    
    return 0;
}