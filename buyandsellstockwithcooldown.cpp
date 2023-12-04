#include<iostream>
#include<vector>
using namespace std;


class Solution {
    int f(int i, bool canBuy, vector<int>& prices) {
        if (i == prices.size()) return 0;
        // buy
        int profit = 0;
        if (canBuy == true) {
            profit = max(-prices[i] + f(i + 1, false, prices),
                        0 + f(i + 1, true, prices));
        }
        // sell
        else {
            profit = max(+prices[i] + f(i + 2, true, prices), 
                        0 + f(i + 1, true, prices));
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        return f(0, true, prices);
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

int main() {
    
    return 0;
}