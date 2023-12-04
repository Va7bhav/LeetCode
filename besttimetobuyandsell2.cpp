#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int f(int i, int buy, vector<int> prices, vector<vector<int>> dp) {
        if (i == prices.size()) return 0;

        if (dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if (buy == 1) {
            profit = max((-prices[i] + f(i + 1, 0, prices, dp)), (0 + f(i + 1, buy, prices, dp)));
        }
        else {
            profit = max((prices[i] + f(i + 1, 1, prices, dp)), (0 + f(i + 1, buy, prices, dp)));
        }
        return dp[i][buy] = profit;

    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return f(0, 1, prices, dp);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2));
        dp[n][1] = dp[n][0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 1; buy >= 0; buy--) {
                int profit = 0;
                if (buy == 1) {
                    profit = max((-prices[i] + dp[i + 1][0]), (0 + dp[i + 1][buy]));
                }
                else {
                    profit = max((prices[i] + dp[i + 1][1]), (0 + dp[i + 1][buy]));
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2);
        vector<int> curr(2);
        prev[1] = prev[0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 1; buy >= 0; buy--) {
                int profit = 0;
                if (buy == 1) {
                    profit = max((-prices[i] + prev[0]), (0 + prev[buy]));
                }
                else {
                    profit = max((prices[i] + prev[1]), (0 + prev[buy]));
                }
                curr[buy] = profit;
            }
            prev = curr;
        }
        return prev[1];
    }
};

class Solution {
    int dfs(int i, int tran, bool canBuy, vector<int>& prices, int k) {
        if (tran == 2*k || i == prices.size()) {
            return 0;
        }
        int profit = 0;
        if (canBuy) {
            profit = max(-prices[i] + dfs(i + 1, tran + 1, false, prices, k), 
                        dfs(i + 1, tran, canBuy, prices, k));   
        }
        else {
            profit = max(prices[i] + dfs(i + 1, tran + 1, true, prices, k), 
                        dfs(i + 1, tran, canBuy, prices, k));
        }
        return profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return dfs(0, 0, true, prices, k);
    }
};

class Solution {
    int dfs(int i, int tran, bool canBuy, vector<int>& prices, int k) {
        if (tran == 2*k || i == prices.size()) {
            return 0;
        }
        int profit = 0;
        if (canBuy) {
            profit = max(-prices[i] + dfs(i + 1, tran + 1, false, prices, k), 
                        dfs(i + 1, tran, canBuy, prices, k));   
        }
        else {
            profit = max(prices[i] + dfs(i + 1, tran + 1, true, prices, k), 
                        dfs(i + 1, tran, canBuy, prices, k));
        }
        return profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return dfs(0, 0, true, prices, k);
    }
};

int main() {
    
    return 0;
}