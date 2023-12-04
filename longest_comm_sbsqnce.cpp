#include<iostream>
#include<vector>
using namespace std;

// recursion -1 -> n - 1
class Solution {
    int f(int i1, int i2, string t1, string t2) {
        if(i1 == -1 || i2 == -1) return 0;

        if(t1[i1] == t2[i2]) {
            return (1 + f(i1 - 1, i2 - 1, t1, t2));
        }
        else if(t1[i1] != t2[i2]) {
            return (0 + max(f(i1 - 1, i2, t1, t2), f(i1, i2 - 1, t1, t2)));
        }
        return 69;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return f(text1.size() - 1, text2.size() - 1, text1, text2);
    }
};
// recursion 0 -> n
class Solution {
    int f(int i1, int i2, string t1, string t2) {
        if(i1 == 0 || i2 == 0) return 0;

        if(t1[i1 - 1] == t2[i2 - 1]) {
            return (1 + f(i1 - 1, i2 - 1, t1, t2));
        }
        else if(t1[i1 - 1] != t2[i2 - 1]) {
            return (0 + max(f(i1 - 1, i2, t1, t2), f(i1, i2 - 1, t1, t2)));
        }
        return 69;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return f(text1.size(), text2.size(), text1, text2);
    }
};

// memoisation -1 -> n - 1
class Solution {
    int f(int i1, int i2, string t1, string t2, vector<vector<int>> cache) {
        if(i1 == -1 || i2 == -1) return 0;

        if(cache[i1][i2] != -1) return cache[i1][i2];

        if(t1[i1] == t2[i2]) {
            cache[i1][i2] = (1 + f(i1 - 1, i2 - 1, t1, t2, cache));
        }
        else if(t1[i1] != t2[i2]) {
            cache[i1][i2] = (0 + max(f(i1 - 1, i2, t1, t2, cache), f(i1, i2 - 1, t1, t2, cache)));
        }
        return cache[i1][i2];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> cache(text1.size(), vector<int>(text2.size(), -1));
        return f(text1.size() - 1, text2.size() - 1, text1, text2, cache);
    }
};

// memoisation 0 -> n
class Solution {
    int f(int i1, int i2, string t1, string t2, vector<vector<int>> cache) {
        if(i1 == 0 || i2 == 0) return 0;

        if(cache[i1][i2] != -1) return cache[i1][i2];

        if(t1[i1 - 1] == t2[i2 - 1]) {
            cache[i1][i2] = (1 + f(i1 - 1, i2 - 1, t1, t2, cache));
        }
        else if(t1[i1 - 1] != t2[i2 - 1]) {
            cache[i1][i2] = (0 + max(f(i1 - 1, i2, t1, t2, cache), f(i1, i2 - 1, t1, t2, cache)));
        }
        return cache[i1][i2];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> cache(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return f(text1.size() , text2.size(), text1, text2, cache);
    }
};

// tabulation 0 -> n
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int i1 = 1; i1 < n + 1; i1++) {
            for (int i2 = 1; i2 < m + 1; i2++) {
                if(text1[i1 - 1] == text2[i2 - 1]) {
                    dp[i1][i2] = (1 + dp[i1 - 1][i2 - 1]);
                }
                else if(text1[i1 - 1] != text2[i2 - 1]) {
                    dp[i1][i2] = (0 + max(dp[i1 - 1][i2], dp[i1][i2 - 1]));
                }    
            }
        }
        return dp[n][m];
    }
};

// space optimisation 0 -> n
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m + 1), curr(m + 1);
    
        for (int i1 = 1; i1 < n + 1; i1++) {
            for (int i2 = 1; i2 < m + 1; i2++) {
                if(text1[i1 - 1] == text2[i2 - 1]) {
                    curr[i2] = (1 + prev[i2 - 1]);
                }
                else if(text1[i1 - 1] != text2[i2 - 1]) {
                    curr[i2] = (0 + max(prev[i2], curr[i2 - 1]));
                }    
            }
            prev = curr;
        }   
        return prev[m];
    }
};
int main() {

    return 0;
}