#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int f(int i, int j, string word1, string word2, vector<vector<int>> dp) {

        if (i == 0 && j > 0) return j; // insert to empty string
        if (j == 0 && i > 0) return i;    
        if (i == 0 && j == 0) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        if (word1[i - 1] == word2[j - 1]) {
            return dp[i][j] = f(i - 1, j - 1, word1, word2, dp);
        }
        else { // (word1[i] != word2[j])
            return dp[i][j] = min({1 + f(i - 1, j, word1, word2, dp),      // delete      
                                   1 + f(i, j - 1, word1, word2, dp),      // insert      
                                   1 + f(i - 1, j - 1, word1, word2, dp)}); // replace
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return f(n, m, word1, word2, dp);
    }
};

int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));

        for (int j = 0; j <= m; j++) dp[0][j] = j;
        for (int i = 0; i <= n; i++) dp[i][0] = i;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else { // (word1[i] != word2[j])
                    dp[i][j] = min({1 + dp[i - 1][j],       // delete      
                                    1 + dp[i][j - 1],       // insert      
                                    1 + dp[i - 1][j - 1]}); // replace
                }
            }
        }
        return dp[n][m];
    }
    
int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<int> prev(m + 1);
    vector<int> curr(m + 1);

    for (int j = 0; j <= m; j++) prev[j] = j;
    // for (int i = 0; i <= n; i++) dp[i][0] = i;
    
    for (int i = 1; i <= n; i++) {
        curr[0] = i;
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                curr[j] = prev[j - 1];
            }
            else { // (word1[i] != word2[j])
                curr[j] = min({1 + prev[j],             // delete      
                                1 + curr[j - 1],        // insert      
                                1 + prev[j - 1]});      // replace
            }
        }
        prev = curr;
    }
    return curr[m];
}

int main() {
    
    return 0;
}