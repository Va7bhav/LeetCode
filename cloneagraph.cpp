#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
    void clone(Node* node, map<Node*, Node*>& hash, vector<int>& visit) {
        Node* newNode = new Node(node->val);
        hash[node] = newNode;
        for(auto currNode : node->neighbors) {
            if(hash.find(currNode) == hash.end()) clone(currNode, hash, visit);    
            newNode->neighbors.push_back(currNode);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        map<Node*, Node*> hash; 
        vector<int> visit(10, 0);
        clone(node, hash, visit);
        return hash[node]; 
    }
};
int main() {
    
    return 0;
}