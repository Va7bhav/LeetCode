#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void acc(vector<int>& arr) {accumulate(arr.begin(), arr.end(), 0);}
int MOD = 1e9 + 7;

int MOD = 1e9 + 7;
class Solution {
    int f(int curNums, int curSum, int n, int k, int target, vector<vector<int>> dp) {
        if (curNums == n && curSum == target) {
            return 1;
        }

        if (dp[curNums][curSum] != -1) return dp[curNums][curSum];
        int res = 0;
        for (int i = 1; i <= k; i++) {
            if (curSum + i <= target && curNums + 1 <= n) {
                res = (res + f(curNums + 1, curSum + i, n, k, target, dp)) % MOD;
            } 
        }

        return dp[curNums][curSum] = res;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n, vector<int> (target, -1));
        return f(0, 0, n, k, target, dp);
    }
};

int main() {
    
    return 0;
}