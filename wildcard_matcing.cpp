#include<iostream>
#include<vector>
using namespace std;

// recursion
class Solution {
    bool f(int i, int j, string p, string s) {
        if(i == -1 && j == -1) return true;

        if(i < 0 && j >= 0) return false;

        if(j < 0 && i >= 0) {
            for(int k = 0; k <= i; k ++) {
                if(p[k] != '*') return false; 
            }
            return true;
        }


        if(p[i] == '?' || p[i] == s[j]) return f(i - 1, j - 1, p, s);

        else if(p[i] == '*') { 
            return f(i - 1, j, p, s) || f(i, j - 1, p, s);
        }
        return false;
    }
public:
    bool isMatch(string p, string s) {
        return f(s.size() - 1, p.size() - 1, p, s);
    }
};

// memoisation n - 1 to -1
class Solution {
    bool f(int i, int j, string p, string s, vector<vector<int>> cache) {
        if(i == -1 && j == -1) return true;

        if(i < 0 && j >= 0) return false;

        if(j < 0 && i >= 0) {
            for(int k = 0; k <= i; k ++) {
                if(p[k] != '*') return false; 
            }
            return true;
        }
        
        if(cache[i][j] != -1) return cache[i][j];
    
        if(p[i] == '?' || p[i] == s[j]) return f(i - 1, j - 1, p, s, cache);

        else if(p[i] == '*') {
            return cache[i][j] = (f(i - 1, j, p, s, cache) || f(i, j - 1, p, s, cache));
        }
        
        return cache[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> cache(p.size(), vector<int> (s.size(), -1));
        return f(p.size() - 1, s.size() - 1, p, s, cache);
    }
};

// memoisation n to 0;
class Solution {
    bool f(int i, int j, string p, string s, vector<vector<int>> cache) {
        if(i == 0 && j == 0) return true;

        if(i == 0 && j > 0) return false;

        if(j == 0 && i > 0) {
            for(int k = 0; k < i; k++) {
                if(p[k] != '*') return false; 
            }
            return true;
        }
        
        if(cache[i][j] != -1) return cache[i][j];
    
        if(p[i - 1] == '?' || p[i - 1] == s[j - 1]) return f(i - 1, j - 1, p, s, cache);

        else if(p[i - 1] == '*') {
            return cache[i][j] = (f(i - 1, j, p, s, cache) || f(i, j - 1, p, s, cache));
        }
        
        return cache[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> cache(p.size() + 1, vector<int> (s.size() + 1, -1));
        return f(p.size(), s.size(), p, s, cache);
    }
};

// tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(p, s);
        vector<vector<int>> dp(p.size() + 1, vector<int> (s.size() + 1, false));
        dp[0][0] = true;

        for(int j = 1; j < s.size() + 1; j++) {
            dp[0][j] = false;
        }

        for(int i = 1; i < p.size() + 1; i++) {
            int flag = true;
            for(int k = 0; k < i; k++) {
                if(p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for(int i = 1; i < p.size() + 1; i++) {
            for(int j = 1; j < s.size() + 1; j++) {
                if(p[i - 1] == '?' || p[i - 1] == s[j - 1]) {
                    dp[i][j]  = dp[i - 1][j - 1];
                }
                else if(p[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else dp[i][j] = false;
            }
        }
        return dp[p.size()][s.size()];
    }
};

// space optimisation
class Solution {
public:
    bool isMatch(string s, string t) {
        vector<bool> curr(t.size() + 1, false);
        vector<bool> prev(t.size() + 1, false);

        prev[0] = true;
        for (int i = 1; i < t.size() + 1; i++) {
            if (t[i - 1] != '*')
                break;
            prev[i] = true;
        }

        for (int i = 1; i < s.size() + 1; i++) {
            curr[0] = false;
            for (int j = 1; j < t.size() + 1; j++) {
                if (s[i - 1] == t[j - 1] or t[j - 1] == '?')
                    curr[j] = prev[j - 1];
                else if (t[j - 1] == '*')
                    curr[j] = curr[j - 1] | prev[j];
                else
                    curr[j] = false;
            }
            prev = curr;
        }
        return prev[t.size()];
    }
};

int main() {
    
    return 0;
}