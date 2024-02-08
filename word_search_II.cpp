#include<iostream>
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;

class TrieNode {
public:
    unordered_map<char, TrieNode*> hash;
    bool isEnd = false;

    bool has(char c) {
        return this->hash.find(c) != this->hash.end(); 
    }

    void addWord(string word) {
        TrieNode* curNode = this;
        for (char c : word) {
            if (!curNode->has(c)) {
                TrieNode* newNode = new TrieNode();
                curNode->hash[c] = newNode;
            }
            curNode = curNode->hash[c];
        }
        curNode->isEnd = true;
    }
};

class Solution {
    void dfs(int r, int c, TrieNode* node, string word, vector<vector<int>> visit, vector<vector<char>> board, unordered_set<string>& res) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || visit[r][c] || !node->has(board[r][c])) {
            return;
        }

        visit[r][c] = 1;
        word += board[r][c];
        node = node->hash[board[r][c]];
        if (node->isEnd) {
            res.insert(word);yar
        }
        dfs(r + 1, c, node, word, visit, board, res);
        dfs(r - 1, c, node, word, visit, board, res);
        dfs(r, c + 1, node, word, visit, board, res);
        dfs(r, c - 1, node, word, visit, board, res);
        visit[r][c] = 0;
    }    

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int ROWS = board.size();
        int COLS = board[0].size();
        TrieNode* root = new TrieNode();
        for (string word : words) {
            root->addWord(word);
        }
        unordered_set<string> res_set;
        vector<vector<int>> visit(ROWS, vector<int>(COLS));
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                dfs(r, c, root, "", visit, board, res_set);
            }
        }
        vector<string> res(res_set.begin(), res_set.end());
        return res;
    }
};


int main() {
	
	return 0;
}