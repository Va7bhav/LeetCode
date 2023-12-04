#include<iostream>
#include<map>
#include<vector>
#include<set>

using namespace std;

class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isWord = false;
    
    void addWord(string s) {
        TrieNode* curr = this;
        for (char c : s) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = curr;
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }

    bool has(char c) {
        if (this->children.find(c) != this->children.end()) return true;
        else return false;
    }
    
};

class Solution {
    void dfs(vector<vector<char>>& board, TrieNode* node, int r, int c, set<string>& res, string word, vector<vector<int>> visit) {
        if (r < 0 || c < 0 || r == board.size() || c == board[0].size() || visit[r][c] || !node->has(board[r][c])) return;
        visit[r][c] = 1;
        node = node->children[board[r][c]];
        word += board[r][c];
        if (node->isWord) res.insert(word);

        dfs(board, node, r + 1, c, res, word, visit);
        dfs(board, node, r - 1, c, res, word, visit);
        dfs(board, node, r, c + 1, res, word, visit);
        dfs(board, node, r, c - 1, res, word, visit);
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string w : words) {
            root->addWord(w);
        }
        vector<vector<int>> visit;
        set<string> res; 
        string word;
        for(int r = 0; r < words.size(); r++) {
            for(int c = 0; c < words[0].size(); c++) {
                dfs(board, root, r, c, res, word, visit);
            }
        }
        vector<string> output(res.begin(), res.end());
        return output;
    }
};

int main() {
    
    return 0;
}