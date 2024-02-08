int MOD = 1e9 + 7;
class Solution {
    int n;
    vector<vector<int>> map {{4, 6}, {8, 6}, {7, 9}, {4, 8}, {0, 3, 9}, {-1, -1}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

    int f(int digits, int num, vector<vector<int>> dp) {
        if (digits == n) return 1;

        if (dp[digits][num] != -1) return dp[digits][num];
        int res = 0;
        for (int ni: map[num]) {
            res += f(digits + 1, ni, dp);
        }

        return dp[digits][num] = res;
    }
public:
    int knightDialer(int n) {
        if (n == 1) return 10;
        this->n = n;
        int res = 0;
        vector<vector<int>> dp(n + 1, vector<int> (10));

        // base case
        for (int i = 0; i < 10; i++) {
            dp[n][i] = 1;
        }

        for (int digit = n - 1; digit >= 0; digit--) {
            for (int num = 0; num <= 9; num++) {
                if (num == 5) continue;
                int res = 0;
                for (int ni: map[num]) {
                    res = (res + dp[digit + 1][ni]) % MOD;
                }

                dp[digit][num] = res;
            }
        }
        
        for (int num = 0; num <= 9; num++) {
            if (num == 5) continue;
            res = (res + dp[1][num]) % MOD;
        }    

        return res;
    }
};
