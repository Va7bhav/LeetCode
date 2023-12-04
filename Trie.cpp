#include<iostream>
#include<map>
using namespace std;

class TrieNode {
    map<char, TrieNode*> children; 
    bool endOfWord = false;
    
    public:
    bool containsKey(char c) {
        if(children.find(c) != children.end()) return true;
        else return false;
    }
    void put(char c, TrieNode* node) {
        children[c] = node;
    }
    TrieNode* get(char c) {
        return children[c];
    }
    void setEnd() {
        endOfWord = true;   
    }
    bool getEnd() {
        return endOfWord;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();        
    }
    
    void insert(string word) {
        TrieNode* node = root; // always start with root yes..
        for (auto letter : word) {
            if(!node->containsKey(letter)) {
                node->put(letter, new TrieNode());
            }
            node = node->get(letter);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (auto letter : word) {
            if(!node->containsKey(letter)) {
                return false;
            } else {
                node = node->get(letter);
            }
        }
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (auto letter : prefix) {
            if(!node->containsKey(letter)) {
                return false;
            } else {
                node = node->get(letter);
            }
        }
        return true;
    }
};

int main() {
    
    return 0;
}