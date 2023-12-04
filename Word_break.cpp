#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    bool topDown(string s, vector<string>& wordDict, int i, vector<int>& dp) {
        if(i == s.size()) {
            return true;
        }
        for(auto word : wordDict) {
            int wordLen = word.size();
            if(s.substr(i, wordLen) == word && dp[i + wordLen] == 0) { 
                if(topDown(s, wordDict, i + wordLen, dp)) {
                    dp[i + wordLen] = 1;
                    return true;
                }
            } 
        }
        return false;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, 0);
        return topDown(s, wordDict, 0, dp);
    }
};

class Solution2 {
    public:
    bool dfs(int i, vector<bool> dp, string s, vector<string>& wordDict) {
        if(i == s.length()) {
            return true;
        }
        for(auto word : wordDict) {
            int wordLen = word.size();
            if(dp[i] == true) {
                if(s.substr(i, wordLen) == word) {
                    if(dfs(i + wordLen, dp, s, wordDict)) return true;
                }
            }
        }
        dp[i] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, true);
         return dfs(0, dp, s, wordDict);
    }
};


int main() {
    Solution sally;
    vector<string> wordDict {"neets", "leet", "code", "neetsmode"};
    cout << sally.wordBreak("neetsmode", wordDict);

    return 0;
}