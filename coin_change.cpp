#include<iostream>
#include<vector>
using namespace std;

// memoisation
class Solution {
    int f(int n, vector<int>& coins, int a, vector<vector<int>> cache) {
        if(n == 0) {
            if(a % coins[n] == 0) return a / coins[n];
            else return 1e9;
        }

        if(cache[n][a] != -1) return cache[n][a];
        
        int not_take = 0 + f(n - 1, coins, a, cache);
        int take = INT_MAX;
        if(a >= coins[n]) {
            take = 1 + f(n, coins, a - coins[n], cache);  
        }
        cache[n][a] = min(take, not_take);
        return cache[n][a];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> cache(coins.size(), vector<int> (amount + 1, -1));
        int ans = f(coins.size() - 1, coins, amount, cache);
        if(ans >= 1e9) return -1; // a base case was generated where any a % coins[0] wasn't zero
        else return ans;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1));
        for(int a = 0; a <= amount; a++) {
            if(amount % coins[0] == 0) {
                dp[0][a] = a / coins[0];
            } else {
                dp[0][a] = 1e9;
            }
        }

        for(int n = 1; n < coins.size(); n++) {
            for(int a = 0; a <= amount; a++) {
                int not_take = 0 + dp[n - 1][a];
                int take = INT_MAX;
                if(a >= coins[n]) {
                    take = 1 + dp[n][a - coins[n]];
                }
                dp[n][a] = min(take, not_take);
            }
        }
        int ans = dp[coins.size() - 1][amount];
        if(ans >= 1e9) {
            return -1;
        }
        else return ans;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount + 1);
        vector<int> temp;
        for(int a = 0; a <= amount; a++) {
            if(amount % coins[0] == 0) {
                prev[a] = a / coins[0];
            } else {
                prev[a] = 1e9;
            }
        }

        for(int n = 1; n < coins.size(); n++) {
            for(int a = 0; a <= amount; a++) {
                int not_take = 0 + prev[a];
                int take = INT_MAX;
                if(a >= coins[n]) {
                    take = 1 + temp[a - coins[n]];
                }
                temp[a] = min(take, not_take);
            }
            prev = temp;
        }
        int ans = prev[amount];
        if(ans >= 1e9) {
            return -1;
        }
        return ans;
    }
};




// my code

// space optimsation
class Solution {
    public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> cache(coins.size(), vector<int> (amount + 1));
        for(int a = 0; a < amount; a++) {
            if(a % coins[0] == 0) 
                cache[0][a] = a / coins[0]; 
            else 
                cache[0][a] = 1e9;
        }
        for(int i = 1; i < coins.size(); i++) {
            for(int a = 0; a <= amount; a++) {
                int not_take = cache[i - 1][a]; 
                int take = INT_MAX;
                if(amount >= coins[i]) {
                    int take = 1 + cache[i][a - coins[i]];        
                }
                cache[i][a] = min(take, not_take);
            }
        }
        int res = cache[coins.size() - 1][amount];
        if(res >= 1e9) return -1;
        return res;
    }
};
int main() {
    Solution sally; 
    vector<int> coins {1, 2, 5};
    cout << sally.coinChange(coins, 11);
    return 0;
}