#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> s;

        s.insert(wordList.begin(), wordList.end());
        q.push({beginWord, 1});

        while (!q.empty()) {
            string word = q.front().first;
            int count = q.front().second;
            q.pop();

            if (word == endWord) return count;
            
            for (int i = 0; i < beginWord.size(); i++) {
                string _word = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (s.find(word) != s.end()) {
                        s.erase(word);
                        q.push({word, count + 1});
                    }
                } 
                word = _word;
            }
        }
        
        return 0;
    }
};

int main() {
    
    return 0;
}