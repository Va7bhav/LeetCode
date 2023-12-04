#include<iostream>
#include<vector>

using namespace std;

class Solution {
    bool isPalindrome(int i, int j, string s) {
        while (i <= j)
            if(s[i++] != s[j--]) return false;
        return true;
    }
    int f(int i, string s, int n) {
        if (i == n) return 0;
        int mini = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                int count = 1 + f(j + 1, s, n);
                mini = min(mini, count);
            }
        }
        return mini;
    }
public:
    int minCut(string s) {
        int n = s.size();
        return f(0, s, n) - 1;
    }
};

class Solution {
    bool isPalindrome(int i, int j, string s) {
        while (i <= j)
            if(s[i++] != s[j--]) return false;
        return true;
    }
    int f(int i, string s, int n, vector<int> dp) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        int mini = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                int count = 1 + f(j + 1, s, n, dp);
                mini = min(mini, count);
            }
        }
        return dp[i] = mini;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, n, dp) - 1;
    }
};

class Solution {
    bool isPalindrome(int i, int j, string& s) {
        while (i <= j)
            if(s[i++] != s[j--]) return false;
        return true;
    }
public:
    int minCut(string& s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int mini = INT_MAX;
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s)) {
                    int count = 1 + dp[j + 1];
                    mini = min(mini, count);
                }
            }
            dp[i] = mini;
        }
        return dp[0] - 1;
    }
};

int main() {
    
    return 0;
}