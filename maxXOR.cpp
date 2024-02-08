#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;

struct Node {
    Node* links[2];
};

class Trie {
private:
    Node* root = new Node();

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (auto i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->links[bit] == NULL) {
                Node* temp = new Node();
                node->links[bit] = temp;
            }
            node = node->links[bit];
        }
    }

    int maxXor(int num) {
        Node* node = root;
        int res = 0;
        for (auto i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->links[!bit] != NULL) {
                res = res | (1 << i);
                node = node->links[!bit];
            } else {
                node = node->links[bit];
            }
        }
        return res;
    }
};


int main() {
	
	return 0;
}