#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 1e9 + 7;
class Solution {

    int f(int n, int k, vector<vector<int>> dp) {
        if (k == 0) return 1;
        if (k < 0) return 0;
        if (dp[n][k] != -1) return dp[n][k];
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + f(n - 1, k - i, dp)) % MOD;
        }

        return dp[n][k] = res;
    }
public:
    int kInversePairs(int n, int k) {
        vector<int> prev(k + 1);
        vector<int> curr(k + 1);

        for (int N = 0; N <= n; N++) {
            curr[0] = 1;
            for (int K = 1; K <= k; K++) {
                int res = 0;
                for (int i = 0; i < N; i++) {
                    if (K - i >= 0) {
                        res = (res + prev[K - i]) % MOD;
                    }
                }
                curr[K] = res;
            }
            prev = curr;
        }
        return prev[k];      
    }
};

int main() {
  
  return 0;
}