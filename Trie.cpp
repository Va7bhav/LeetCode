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

struct Node {
	Node *links[26];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		//creating new obejct
		root = new Node();
	}

	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}
};

int main() {
    
    return 0;
}