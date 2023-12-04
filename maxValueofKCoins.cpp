#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int f(int i, int j, int k, vector<vector<int>>& piles) {
        // base cases
        if (i == piles.size() || j == piles[i].size()) {
            return 0;
        }
        // general cases
        int not_take = max(f(i, j + 1, k, piles), f(i + 1, 0, k, piles));
        int take = INT_MIN;
        if (k > 0) {
            take = piles[i][j] + max(f(i, j + 1, k - 1, piles), 
                                     f(i + 1, 0, k - 1, piles));
        }
        return max(take, not_take);
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        

        return f(0, 0, k, piles);
    }
};


class Solution {
    int f(int i, int coins, vector<vector<int>>& piles, vector<vector<int>>& dp) {
        if (i == piles.size()) {
            return 0;
        }

        if (dp[i][coins] != -1) return dp[i][coins];
        int res = f(i + 1, coins, piles, dp);
        int curPile = 0;
        int pileSize = piles[i].size();
        int range = min(coins, pileSize);
        for (int j = 0; j < range; j++) {
            curPile += piles[i][j];
            
            // if exit:
            res = max(res, curPile + f(i + 1, coins - j - 1, piles, dp));
        }
        return dp[i][coins] = res;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size(), vector<int> (k + 1, -1));
    
        return f(0, k, piles, dp);
    }
};

class Solution {
    int f(int i, int coins, vector<vector<int>>& piles, vector<vector<int>>& dp) {
        if (i == piles.size()) {
            return 0;
        }

        if (dp[i][coins] != -1) return dp[i][coins];
        int res = f(i + 1, coins, piles, dp);
        int curPile = 0;
        int pileSize = piles[i].size();
        int range = min(coins, pileSize);
        for (int j = 0; j < range; j++) {
            curPile += piles[i][j];
            
            // if exit:
            res = max(res, curPile + f(i + 1, coins - j - 1, piles, dp));
        }
        return dp[i][coins] = res;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int> (k + 1));

        for (int i = n - 1; i >= 0; i--) {
            for (int coins = 0; coins <= k; coins++) {
                int res = dp[i + 1][coins];
                int curPile = 0;
                int pileSize = piles[i].size();
                int range = min(coins, pileSize);
                for (int j = 0; j < range; j++) {
                    curPile += piles[i][j];
                    
                    // if exit:
                    res = max(res, curPile + dp[i + 1][coins - j - 1]);
                }
                dp[i][coins] = res;
            }
        }
        return dp[0][k];
    }
};

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<int> prev(k + 1);
        vector<int> curr(k + 1);

        for (int i = n - 1; i >= 0; i--) {
            for (int coins = 0; coins <= k; coins++) {
                int res = prev[coins];
                int curPile = 0;
                int pileSize = piles[i].size();
                int range = min(coins, pileSize);
                for (int j = 0; j < range; j++) {
                    curPile += piles[i][j];
                    
                    // if exit:
                    res = max(res, curPile + prev[coins - j - 1]);
                }
                curr[coins] = res;
            }
            prev = curr;
        }
        return prev[k];
    }
};
int main() {
    
    return 0;
}