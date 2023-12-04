#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
    int dfs(int i, int m, int p, int n, int minProfit, vector<int>& group, vector<int>& profit, map<pair<int, pair<int, int>>, int> dp) {
        if (i == group.size()) {
            if (p >= minProfit) {
                return 1;
            }
            else return 0;
        }
        if (dp.find({i, {m, p}}) != dp.end()) return dp[{i, {m, p}}];
        
        int ways = 0;
        ways += dfs(i + 1, m, p, n, minProfit, group, profit, dp);
        if (m + group[i] <= n) {
            ways += dfs(i + 1, m + group[i], p + profit[i], n, minProfit, group, profit, dp);
        }
        return dp[{i, {m, p}}] = ways;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {       
        int mod = pow(10, 9) + 7;
        map<pair<int, pair<int, int>>, int> dp;

        for (int m = 0; m <= n; m++) {
            dp[{group.size(), {m, minProfit}}] = 1;
        }
        for (int i = group.size() - 1; i >= 0; i--) {
            for (int m = n; m >= 0; m--) {
                for (int p = minProfit; p >= 0; p--) {
                    int ways = 0;
                    ways += dp[{i + 1, {m, p}}];
                    if (m + group[i] <= n) {// as now here we are taking the min of those two, see the base case, the base case is alse defined for the minProfit only, that's why we are doing it like this
                        ways += (dp[{i + 1, {m + group[i], min(minProfit, p + profit[i])}}]);
                    }
                    dp[{i, {m, p}}] = ways;
                }
            }
        }
        return dp[{0, {0, 0}}];
    }
};


int main()
{

    return 0;
}