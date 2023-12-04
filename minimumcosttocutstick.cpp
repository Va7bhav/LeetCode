#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
        int f(int i, int j, vector<int> cuts) {
            if (i > j) return 0;
            int mini = 1e9;
            for (int k = i; k <= j; k++) { // you traverse across the cuts array taking the cuts one by one
                int cost = (cuts[j + 1] - cuts[i - 1]) +
                            f(i, k - 1, cuts) + f(k + 1, j, cuts);
                mini = min(mini, cost);
            }
            return mini;
        }
    public:
        int minCost(int n, vector<int>& cuts) {
            cuts.push_back(n);
            cuts.insert(cuts.begin(), 0);
            
            sort(cuts.begin(), cuts.end());
            
            int c = cuts.size();
            return f(1, c, cuts);   
        }
};
// you traverse across the cuts array taking the cuts one by one
class Solution {
    int f(int i, int j, vector<int> cuts, vector<vector<int>> dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for (int k = i; k <= j; k++) { 
            int cost = (cuts[j + 1] - cuts[i - 1]) +
                        f(i, k - 1, cuts, dp) + f(k + 1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 1, vector<int> (c + 1, -1));
        return f(1, c, cuts, dp);
    }
};

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 2, vector<int> (c + 2));

        for (int i = c; i >= 1; i--) {
            for (int j = i; j <= c; j++) {
                // if (i > j) continue;
                int mini = 1e9;
                for (int k = i; k <= j; k++) { 
                    int cost = (cuts[j + 1] - cuts[i - 1]) +
                            dp[i][k - 1] + dp[k + 1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};


int main() {
    Solution sally;
    vector<int> vec {1, 3, 4, 5};
    cout << sally.minCost(7, vec);
    return 0;
}