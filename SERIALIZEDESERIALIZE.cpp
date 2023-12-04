#include<iostream>
#include<queue>
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

// clasclass Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         string data = "";
//         if(root == NULL) return data; 
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()) {
//             TreeNode* popNode = q.front();
//             q.pop();
//             if(popNode == NULL) data.push_back('#');
//             else data.append(to_string(popNode->val));
//             if(popNode) {
//                 q.push(popNode->left);
//                 q.push(popNode->right);
//             }
//         }
//         return data;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         if(data.size() == NULL) return NULL;
//         queue<TreeNode*> q;
//         int i = 0;
//         TreeNode* root = new TreeNode(data[i] - '0');
//         i++;
//         q.push(root);
//         while(!q.empty()) {
//             TreeNode* popNode = q.front();
//             q.pop();

//             if(data[i] == '#') popNode->left = NULL;
//             else {
//                 popNode->left = new TreeNode(data[i] - '0');
//                 q.push(popNode->left);
//             }
//             i++;
//             if(data[i] == '#') popNode->right = NULL;
//             else {
//                 popNode->right = new TreeNode(data[i] - '0');
//                 q.push(popNode->right);
//             }
//             i++;
//         }
//         return root;
//     }
// };


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string data;
        q.push(root);
        while(!q.empty()) {
            TreeNode* popNode = q.front();
            q.pop();
            if(popNode == NULL) data.append("#,");
            else data.append(to_string(popNode->val) + ",");
            if(popNode) {
                q.push(popNode->left);
                q.push(popNode->right);
            }
        }
        cout << data;   
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode();
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {

            TreeNode* popNode = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#") popNode->left = NULL;
            else {
                popNode->left = new TreeNode(stoi(str));
                q.push(popNode->left);
            }

            getline(s, str, ',');
            if(str == "#") popNode->right = NULL;
            else {
                popNode->right = new TreeNode(stoi(str));
                q.push(popNode->right);
            } 
        }
        return root;
    }
};
int main() {
    
    return 0;
}