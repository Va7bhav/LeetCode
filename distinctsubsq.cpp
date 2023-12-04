#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int f(int i, int j, string s, string t, vector<vector<int>> dp) {
        if (j == 0) return 1;
        if (i == 0 && j > 0) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i - 1] == t[j - 1]) {
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
        }
        else { // (s[i] != t[j])
            return dp[i][j] = f(i - 1, j, s, t, dp);
        }
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int> (t.size() + 1, -1));
        return f(s.size(), t.size(), s, t, dp);
    }  
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n + 1, vector<double> (m + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        for (int j = 1; j <= m; j++) dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else { // (s[i] != t[j])
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> prev(m + 1, 0);
        vector<double> curr(m + 1, 0);
        for (int j = 1; j <= m; j++) prev[j] = 0;

        for (int i = 1; i <= n; i++) {
            prev[0] = 1;
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                }
                else { // (s[i] != t[j])
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return (int)prev[m];
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> prev(m + 1, 0);
        for (int j = 1; j <= m; j++) prev[j] = 0;

        for (int i = 1; i <= n; i++) {
            prev[0] = 1;
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    prev[j] = prev[j - 1] + prev[j];
                }
                else { // (s[i] != t[j])
                    prev[j] = prev[j];
                }
            }
            prev = prev;
        }
        return (int)prev[m];
    }
};


int main() {
    
    return 0;
}